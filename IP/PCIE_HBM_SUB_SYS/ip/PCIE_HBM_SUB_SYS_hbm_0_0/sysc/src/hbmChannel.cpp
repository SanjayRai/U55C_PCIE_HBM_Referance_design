// (c) Copyright 1995-2021 Xilinx, Inc. All rights reserved.
// 
// This file contains confidential and proprietary information
// of Xilinx, Inc. and is protected under U.S. and
// international copyright and other intellectual property
// laws.
// 
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// Xilinx, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) Xilinx shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or Xilinx had been advised of the
// possibility of the same.
// 
// CRITICAL APPLICATIONS
// Xilinx products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of Xilinx products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
// 
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.
// 
// DO NOT MODIFY THIS FILE.

#include "hbmChannel.h"
#include "extensions/P2P_XTLM_extension.h"
#include <algorithm>
#include <regex>

using namespace sc_core;


  hbmChannel::hbmChannel(sc_core::sc_module_name nm, uint64_t memStartAddr, uint32_t memSize, std::string addrMap, unsigned hbmClk, xsc::common_cpp::report_handler* reportHandler, xsc::memory* mem): sc_module(nm), xtlm_aximm_target_base("target_base")
    ,wr_skt("wrSkt", 256)
    ,rd_skt("rdSkt", 256)
    //,d("dram0", sc_time(1, SC_NS))
    ,wrUtil("wrSktUtil", xtlm::aximm::TRANSACTION, 256)
    ,rdUtil("rdSktUtil", xtlm::aximm::TRANSACTION, 256)
    ,cmdQueue(-1)
    ,bankGrpAddrBits(0)
    ,bankAddrBits(0)
    ,rowAddrBits(0)
    ,colAddrBits(0)
    ,state(dramState::IDLE)
    ,memStartAddr(memStartAddr)
    ,memSize(memSize)
    ,Ck(sc_time(double(1000)/hbmClk, SC_NS))
  {
    this->rH = reportHandler;
    this->hbmMem = mem;
    REPORT_DEBUG(rH, this->name() << "_construtor", "Creating channel with addrMap = " << addrMap)
    parseAddrMapString(addrMap);

    wr_skt.bind(wrUtil.wr_socket);
    rd_skt.bind(rdUtil.rd_socket);

    sc_core::sc_spawn_options optW;
    optW.dont_initialize();
    optW.set_sensitivity(&(wrUtil.transaction_available));
    sc_spawn(sc_bind(&hbmChannel::threadWr, this), "methodMCWrite", &optW);

    sc_core::sc_spawn_options optR;
    optR.dont_initialize();
    optR.set_sensitivity(&(rdUtil.transaction_available));
    sc_spawn(sc_bind(&hbmChannel::threadRd, this), "methodMCRead", &optR);

    wrUtil.cb_transport_dbg = std::bind(&hbmChannel::transport_dbg, this, std::placeholders::_1);
    rdUtil.cb_transport_dbg = std::bind(&hbmChannel::transport_dbg, this, std::placeholders::_1);

    if (getenv("SDX_USE_SHARED_MEMORY")) {
      m_mem_handler = new hbm_fmodel_shared_memory(this->name(), rH, this->memSize);
    } else {
      m_mem_handler = nullptr;
    }

    const char *envHwEmuLatencyDis = std::getenv("HW_EM_DISABLE_LATENCY");
    bool latDisabled = (envHwEmuLatencyDis != nullptr) && ((strcmp(envHwEmuLatencyDis, "true") == 0) ||
                                                           (strcmp(envHwEmuLatencyDis, "TRUE") == 0) ||
                                                           (strcmp(envHwEmuLatencyDis, "1") == 0));
    if (latDisabled) {
      latencyEnabled = false;
    } else {
      latencyEnabled = true;
    }

    speedBin = 0;  //#rsbtbd  1 = 2.4Gbps, 0 = 2Gbps
    dbiOnOff = 0;  //#rsbtbd 0=off,1=On

    tActivate = 2 * Ck;
    tRrdL = tRrdS = std::max(2*Ck, sc_time(4,SC_NS));
    tRp = std::max(3 * Ck, sc_time(14,SC_NS));
    tRas = 3 * Ck;
    tRcdrd = tRcdwr = std::max(3*Ck, sc_time(14,SC_NS));
    tRc = 6 * Ck;
    tRl = (dbiOnOff?(speedBin?26:22):(speedBin?25:21)) * Ck;
    tWl = (speedBin?8:7) * Ck;
    tCcdL = 4 * Ck;
    tCcdR = 2 * Ck;
    tCcdS = 3 * Ck;
    tFaw = 8 * Ck;
    tBl = 4 * Ck;
    tWr = std::max(3*Ck,sc_time(15,SC_NS)) + Ck;
    tWrtl = std::max(4 * Ck, sc_time(7.5, SC_NS)) + Ck;
    tWrts = std::max(2 * Ck, sc_time(2.5, SC_NS)) + Ck;

    tRefi = sc_time(3.9,SC_US);
    tRfc = sc_time(260,SC_NS);

    SC_THREAD(threadSpendTxnDelay);
    SC_THREAD(threadRefreshKeeper);

    //cout<< "BGitem :";
    //for(auto& pr: bankGrpAddrBits){
    //  cout<< pr.first<<"|"<<pr.second<<", ";
    //}
    //cout<<endl<<"BAitem :";
    //for(auto& pr: bankAddrBits){
    //  cout<<pr.first<<"|"<<pr.second<<", ";
    //}
    //cout<<endl<<"RAitem:";
    //for(auto& pr: rowAddrBits){
    //  cout<<pr.first<<"|"<<pr.second<<", ";
    //}
    //cout<<endl<<"CAitem:";
    //for(auto& pr: colAddrBits){
    //  cout<<pr.first<<"|"<<pr.second<<", ";
    //}
    //cout<<endl;

  }

  hbmChannel::~hbmChannel() {
    for (auto &pg : mem) {
      delete pg.second;
    }
    delete m_mem_handler;
  }


unsigned int hbmChannel::transport_dbg(xtlm::aximm_payload &trans) {     //only INCR burst supported
  uint64_t startAddress = trans.get_address() % memSize;
  unsigned dataLen = trans.get_data_length();
  uint64_t endAddress = startAddress + dataLen - 1;
  unsigned id = trans.get_axi_id();
  uint8_t *data = trans.get_data_ptr();
  uint8_t *byt = trans.get_byte_enable_ptr();
  unsigned byteLen = trans.get_byte_enable_length();

  hbmMem->transport_dbg(trans);

  //if (m_mem_handler) {  //SHARED MEMORY
  //  if (trans.get_command() == xtlm::XTLM_WRITE_COMMAND) {
  //    writeToSharedMem(&trans);
  //  } else if (trans.get_command() == xtlm::XTLM_READ_COMMAND) {
  //    m_mem_handler->readDevMem(startAddress, data, dataLen);
  //  }
  //}

  //else {  //SELF ALLOCATED MEMORY
  //  unsigned numPages = dataLen / 4096 + ((dataLen % 4096) ? 1 : 0);
  //  unsigned dbyte = 0;
  //  for (unsigned page = 0; page < numPages; page++) {
  //    uint64_t aligned4kBoundL = (startAddress / 4096) * 4096;
  //    uint64_t aligned4kBoundH = aligned4kBoundL + 4095;

  //    uint64_t memKey = aligned4kBoundL >> 12;
  //    unsigned sIdx = startAddress & 0xFFF;
  //    unsigned eIdx = ((endAddress < aligned4kBoundH) ? endAddress : aligned4kBoundH) & 0xFFF;
  //    unsigned nByts = (eIdx - sIdx) + 1;
  //    pg4KB *pg = mem[memKey];

  //    if (trans.get_command() == xtlm::XTLM_WRITE_COMMAND) {
  //      if (pg == nullptr) mem[memKey] = pg = new pg4KB(4096);

  //      if (byt) {
  //        for (unsigned w = sIdx; w <= eIdx; w++) {
  //          if (byt[dbyte % byteLen] == TLM_BYTE_ENABLED) {
  //            pg->operator[](w) = data[dbyte];
  //          }
  //          dbyte++;
  //        }
  //      } else {
  //        memcpy(&pg->operator[](sIdx), data + dbyte, nByts);
  //        dbyte += nByts;
  //      }
  //    }else if (trans.get_command() == xtlm::XTLM_READ_COMMAND) {
  //      std::vector<uint8_t> tD(nByts);
  //      if (pg == nullptr) {
  //        std::generate(tD.begin(), tD.end(), [] { return 0; });
  //      } else {
  //        std::copy(pg->begin() + sIdx, pg->begin() + sIdx + nByts, tD.begin());
  //      }
  //      memcpy(data + dbyte, &tD[0], nByts);
  //      dbyte += nByts;
  //    }
  //    startAddress = aligned4kBoundH+1;
  //  }
  //}
  //trans.set_response_status(xtlm::XTLM_OK_RESPONSE);
  //std::string pt;
}

void hbmChannel::parseAddrMapString(std::string s){
  std::regex word_regex("([A-Z]+)(\\d+)(,?)");                               //#tbd - SID is not handled in USER PARAMS still, handle when introduced
  auto words_begin = std::sregex_iterator(s.begin(), s.end(), word_regex);
  auto words_end = std::sregex_iterator();

  // std::cout << "Found "
  //          << std::distance(words_begin, words_end)
  //          << " words\n";
  unsigned idx = std::distance(words_begin, words_end)-1;

  while(words_begin!=words_end){
  //for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
    std::smatch match(*words_begin);
    std::string sIdent = match[1].str();
    int lIndex = stoi(match[2].str());
    //cout<< " ADDR="<<sIdent<<" bits="<<lIndex;
    std::vector<std::pair<uint32_t, uint32_t> > *vAddrBits;
    if(sIdent == "BG"){
      vAddrBits = &bankGrpAddrBits;
    }else if(sIdent == "BA"){
      vAddrBits = &bankAddrBits;
    }else if(sIdent == "RA"){
      vAddrBits = &rowAddrBits;
    }else if(sIdent == "CA"){
      vAddrBits = &colAddrBits;
    }
    if(vAddrBits->empty()){
      vAddrBits->push_back(std::make_pair(idx--, 1));
    }else{
      unsigned size = 1;
      auto prv = vAddrBits->front();
      if(prv.first == idx+1){
        size += prv.second;
        vAddrBits->erase(vAddrBits->begin());
      }
      vAddrBits->emplace(vAddrBits->begin(), std::make_pair(idx--,size));
    }
    ++words_begin;
  } 
}

void hbmChannel::threadWr(){
  while (1) {
    xtlm::aximm_payload *trans = wrUtil.peek_transaction();
    processTrans(trans, false);
    sc_time lat = SC_ZERO_TIME;
    wrUtil.send_resp(*trans, lat);
    trans = wrUtil.get_transaction();
    if(wrUtil.is_trans_available()==false) wait();
  }
}

void hbmChannel::threadRd(){
  while (1) {
    xtlm::aximm_payload *trans = rdUtil.peek_transaction();
    processTrans(trans, false);
    sc_time lat = SC_ZERO_TIME;
    rdUtil.send_data(*trans, lat);
    trans = rdUtil.get_transaction();
    if (rdUtil.is_trans_available() == false) wait();
  }
}

void hbmChannel::threadRefreshKeeper() {
  while (1) {
    wait(9 * tRefi);
    state = dramState::REFRESH;
    wait(tRfc);  //Refresh command period, Tk b/w REF and VALID
    state = dramState::IDLE;
    dramIdle.notify();
  }
}

void hbmChannel::processTrans(xtlm::aximm_payload* trans, bool dbg){
  uint64_t startAddress = trans->get_address() % memSize;
  //uint64_t maxAddress = memStartAddr + memSize;
  //if (startAddress >  memSize) {
    //REPORT_DEBUG(rH, this->name() << "_processTrans", "Tx startAddr :0x" <<std::hex<< startAddress << ", totalMemorySize =0x"<<memSize ) 
    //XSC_REPORT_INFO((*this->rH), "hbmChannel", "Switching ERROR: address received out of channel accessible MEMORY, normalising with bounds");
    //startAddress = startAddress % memSize;
  //}
  unsigned bSize = trans->get_burst_size();
  if (bSize != 32) {
    REPORT_MEDIUM(rH, this->name()<<".processTrans", "SPECIFICATION DEVIANCE: HBM IP only supports burst size as 32 Bytes(AxSize=3'b101) but Tx received has burst size as " << dec << bSize);
  }
  unsigned bSizeBytes = bSize;
  //unsigned bSizeBytes = 32;
  unsigned bLen = trans->get_burst_length();
  unsigned bType = trans->get_burst_type();
  unsigned dataLen = trans->get_data_length();
  unsigned id = trans->get_axi_id();
  uint8_t *data = trans->get_data_ptr();
  uint8_t *byt = trans->get_byte_enable_ptr();
  unsigned byteLen = trans->get_byte_enable_length();

  Fx f, sync;
  sc_event *doneEv;
  if (trans->get_command() == xtlm::XTLM_WRITE_COMMAND) {
    f = WRITE;
    sync = wrSync;
    doneEv = &wrTxDone;
  } else if (trans->get_command() == xtlm::XTLM_READ_COMMAND) {
    f = READ;
    sync = rdSync;
    doneEv = &rdTxDone;
  }

  std::vector<uint64_t> listColAddress;
  uint64_t alignedstartAddress = (startAddress / bSizeBytes) * bSizeBytes;
  uint64_t lastAddress = startAddress;
  unsigned totalBytes = bSizeBytes * bLen;
  unsigned totalColumns = (totalBytes/32)+1;
  unsigned wrapByteIndex = 0; //byte index at which address wraps
  switch (bType)
  {
  case 0: //FIXED BURST - not supported
    cout << " ERROR : FIXED burst not supported" << endl;
    //trans->set_response_status(xtlm::XTLM_COMMAND_ERROR_RESPONSE);
    //return tlm::TLM_COMPLETED;
    break;
  case 1: {  //INCR BURST
    lastAddress = alignedstartAddress + (bSizeBytes * bLen);
    unsigned cA = alignedstartAddress;
    while (lastAddress > cA) {
      uint64_t boundaryAddr = cA/32;
      listColAddress.push_back(boundaryAddr);
      cA = (boundaryAddr+1)*32;
    }
  } break;
  case 2: {
    uint64_t wrapBound = (startAddress / totalBytes) * totalBytes;  //wrapBoundary AXI4
    lastAddress = wrapBound + totalBytes;
    uint64_t tbla = lastAddress - alignedstartAddress;
    //cout << "Value of wrapBoundary is" << hex << wrapBound << endl;
    //cout << "total Bytes =" << dec << totalBytes << " till tbla" << tbla << ", remaining" << totalBytes - tbla << endl;
    //cout << "total column access till last address = " <<dec<< (tbla / 32) + ((tbla % 32) ? 1 : 0) << "remaining =" << (totalBytes - tbla) / 32 + ((totalBytes - tbla) % 32 ? 1 : 0) << endl;
    uint64_t cA = alignedstartAddress;
    while (lastAddress > cA) {
      uint64_t boundaryAddr = cA/32;
      listColAddress.push_back(boundaryAddr);
      cA = (boundaryAddr+1)*32;
    }
    cA = wrapBound;
    uint64_t remBytes = totalBytes - tbla;
    while (wrapBound+remBytes > cA){
      uint64_t boundaryAddr = cA/32;
      listColAddress.push_back(boundaryAddr);
      cA = (boundaryAddr+1)*32;
    }
    wrapByteIndex = lastAddress - startAddress;
  } break;
  default:
    cout << "ERROR: unknown burst type" << endl;
    break;
  }
  //cout << " AXI trans with "<<hex<<
  //  "Addr =0x" << startAddress<<
  //  ", aligned start=0x" << alignedstartAddress<<
  //  ", burst ="<<bType<<
  //  ", lastAddress =0x"<< lastAddress<<
  //  ", dataLen =0x"<< dataLen<<
  //  ", totalBytes ='d"<<dec<< bSizeBytes<<"("<<bSize<<")"<<"*"<<bLen<<"="<<totalBytes<<
  //  ", wrapByteIndex ='d"<< wrapByteIndex<<endl;
  //pass delay

  if (!dbg && latencyEnabled) {
    for (auto sA : listColAddress) {
      REPORT_DEBUG(rH, this->name()<<".processTrans", "Putting column addr 0x"<<std::hex<<sA<< "on command queue")
      cmdQueue.put(std::make_pair(sA, f));
    }
    cmdQueue.put(std::make_pair(id, sync));
    //if(wrTxDone.find(id) == wrTxDone.end()) {
    //  wrTxDone.insert(std::make_pair(id, new sc_event()));
    //}
    REPORT_DEBUG(rH, this->name()<<".processTrans", "Waiting on done Event @"<<sc_time_stamp())
    wait(*doneEv);
  }

  //unsigned totalBytBefWrap = lastAddress - startAddress;
  //unsigned totalBytAftWrap = totalBytes - totalBytBefWrap;

  //uint64_t memKey = startAddress >> 12;
  //unsigned pos = startAddress & 0xFFF;
  //unsigned lpos = lastAddress & 0xFFF;
  //unsigned apos = alignedstartAddress & 0xFFF;
  //pg4KB *pg = mem[memKey];

  //if (trans->get_command() == xtlm::XTLM_WRITE_COMMAND) {
  //  if (m_mem_handler) {
  //    xtlm::xtlm_extension<xsc::extension::P2P_XTLM_extension> *bExt;
  //    trans->get_extension(bExt);
  //    xsc::extension::P2P_XTLM_extension *ext = dynamic_cast<xsc::extension::P2P_XTLM_extension *>(bExt);
  //    if (ext != nullptr) {
  //      std::string filename;
  //      bool ret = true;
  //      if (ext->getType() == xsc::extension::TYPE::ALLOC_BO)
  //        ret = m_mem_handler->createMMappedBuffer(
  //            startAddress, ext->getSize(), filename);
  //      else if (ext->getType() == xsc::extension::TYPE::FREE_BO)
  //        ret = m_mem_handler->freePage(startAddress);
  //      else if (ext->getType() == xsc::extension::TYPE::IMPORT_BO) {
  //        ret = m_mem_handler->importBO(startAddress,
  //                                      ext->getFileName(), ext->getSize());
  //      } else if (ext->getType() == xsc::extension::TYPE::COPY_BO) {
  //        ret = m_mem_handler->copyBO(startAddress,
  //                                    ext->getFileName(), ext->getSize(),
  //                                    ext->getSrcOffset(), ext->getDstOffset());
  //      }
  //      ext->setResponse(ret);
  //      ext->setFileName(filename);
  //    }else if (!byt) {
  //      unsigned cpySz = std::min(dataLen, totalBytBefWrap);
  //      m_mem_handler->writeDevMem(startAddress, data, cpySz);
  //      if(dataLen > totalBytBefWrap){
  //        m_mem_handler->writeDevMem(alignedstartAddress, data+totalBytBefWrap, dataLen-totalBytBefWrap);
  //      }
  //      //if(totalBytAftWrap!=0) m_mem_handler->writeDevMem(alignedstartAddress, data+wrapByteIndex, totalBytAftWrap);
  //      //m_mem_handler->writeDevMem(alignedstartAddress+totalBytAftWrap, data, totalBytBefWrap);
  //    } else {
  //        for (unsigned i = 0, w = startAddress; i < dataLen; i++) {
  //        if (byt[i % byteLen] == TLM_BYTE_ENABLED) {
  //          m_mem_handler->writeDevMem(w, data + i, 1);
  //        }
  //        w++;
  //        if (w == lastAddress) w = alignedstartAddress;
  //      }
  //    }
  //  } else {
  //    if (pg == nullptr) {
  //      mem[memKey] = pg = new pg4KB(4096);
  //    }
  //    if (byt) {
  //      for (unsigned i = 0, w = pos; i < dataLen; i++) {
  //        if (byt[i % byteLen] == TLM_BYTE_ENABLED) {
  //          pg->operator[](w) = data[i];
  //        }
  //        w++;
  //        if (w == lpos) w = apos;
  //      }
  //    } else {
  //      unsigned cpySz = std::min(dataLen, totalBytBefWrap);
  //      memcpy(&pg->operator[](pos), data, cpySz);
  //      if(dataLen > totalBytBefWrap){
  //        memcpy(&pg->operator[](apos), data + totalBytBefWrap, dataLen-totalBytBefWrap);
  //      }
  //    }
  //    if(rH->get_verbosity_level() ==  xsc::common_cpp::VERBOSITY::DEBUG){
  //      std::stringstream ss;
  //      ss << "Data Written to mem @0x"<<hex<<alignedstartAddress <<" (" <<dec<<totalBytes << "Bytes)-> |";
  //      for (auto it = pg->begin() + apos; it < pg->begin() + apos + totalBytes; it++) {
  //        ss <<"0x"<<std::hex<<(unsigned)(*it) << "|";
  //      }
  //      XSC_REPORT_INFO((*rH), "hbm.processTrans", ss.str().c_str());
  //    }
  //    //if (wrapByteIndex != totalBytes) memcpy(&tD[0], data + wrapByteIndex, totalBytAftWrap);
  //    //memcpy(&tD[0] + totalBytAftWrap, data, totalBytBefWrap);
  //    //writeMem(startAddress, tD);
  //  }
  //} else if (trans->get_command() == xtlm::XTLM_READ_COMMAND) {
  //  if(m_mem_handler){
  //    //if(totalBytAftWrap!=0) m_mem_handler->readDevMem(alignedstartAddress, data+wrapByteIndex, totalBytAftWrap);
  //    //m_mem_handler->readDevMem(alignedstartAddress+totalBytAftWrap, data, totalBytBefWrap);
  //    unsigned cpySz = std::min(dataLen, totalBytBefWrap);
  //    m_mem_handler->readDevMem(startAddress, data, cpySz);
  //    if(dataLen > totalBytBefWrap){
  //      m_mem_handler->readDevMem(alignedstartAddress, data+totalBytBefWrap, dataLen-totalBytBefWrap);
  //    }
  //  } else {
  //    std::vector<uint8_t> tD(totalBytes);
  //    if (pg == nullptr) {
  //      std::generate(tD.begin(), tD.end(), [] { return 0; });
  //    } else {
  //      std::copy(pg->begin() + apos, pg->begin() + apos + totalBytes, tD.begin());
  //    }
  //    if(rH->get_verbosity_level() ==  xsc::common_cpp::VERBOSITY::DEBUG){
  //      std::stringstream ss;
  //      ss << "Data Read from mem @0x"<<hex<<alignedstartAddress <<" (" <<dec<<totalBytes << "Bytes)-> |";
  //      for (auto it = tD.begin(); it < tD.end(); it++) {
  //        ss <<"0x"<<std::hex<<(unsigned)(*it) << "|";
  //      }
  //      XSC_REPORT_INFO((*rH), "hbm.processTrans", ss.str().c_str());
  //    }
  //    //commented as byteEnables are to be ignored for read commands
  //    //if(byt){
  //    //  for(unsigned i=0, w=wrapByteIndex; i<totalBytes; i++){
  //    //    if(byt[w%byteLen] == 0xFF){data[w] = tD[i]; }
  //    //    w++;
  //    //    if(w==totalBytes) w=0;
  //    //  }
  //    //}else {
  //    unsigned cpySz = std::min(dataLen, totalBytBefWrap);
  //    memcpy(data, &tD[totalBytAftWrap], cpySz);
  //    if(dataLen > totalBytBefWrap){
  //      memcpy(data + totalBytBefWrap, &tD[0], dataLen-totalBytBefWrap);
  //    }
  //  //}
  //  }
  //}
  sc_core::sc_time zeroDel = sc_core::SC_ZERO_TIME;
  hbmMem->b_transport(*trans, zeroDel);
  //trans->set_response_status(xtlm::XTLM_OK_RESPONSE);
}

void hbmChannel::writeToSharedMem(xtlm::aximm_payload *trans) {
  uint64_t startAddress = trans->get_address() % memSize;
  unsigned dataLen = trans->get_data_length();
  uint8_t *data = trans->get_data_ptr();
  uint8_t *byt = trans->get_byte_enable_ptr();
  unsigned byteLen = trans->get_byte_enable_length();

  xtlm::xtlm_extension<xsc::extension::P2P_XTLM_extension> *bExt;
  trans->get_extension(bExt);
  xsc::extension::P2P_XTLM_extension *ext = dynamic_cast<xsc::extension::P2P_XTLM_extension *>(bExt);
  if (ext != nullptr) {
    std::string filename;
    bool ret = true;
    if (ext->getType() == xsc::extension::TYPE::ALLOC_BO)
      ret = m_mem_handler->createMMappedBuffer(
          startAddress, ext->getSize(), filename);
    else if (ext->getType() == xsc::extension::TYPE::FREE_BO)
      ret = m_mem_handler->freePage(startAddress);
    else if (ext->getType() == xsc::extension::TYPE::IMPORT_BO) {
      ret = m_mem_handler->importBO(startAddress,
                                    ext->getFileName(), ext->getSize());
    } else if (ext->getType() == xsc::extension::TYPE::COPY_BO) {
      ret = m_mem_handler->copyBO(startAddress,
                                  ext->getFileName(), ext->getSize(),
                                  ext->getSrcOffset(), ext->getDstOffset());
    }
    ext->setResponse(ret);
    ext->setFileName(filename);
  } else if (!byt) {
    m_mem_handler->writeDevMem(startAddress, data, dataLen);
  } else {
    for (unsigned i = 0, w = startAddress; i < dataLen; i++) {
      if (byt[i % byteLen] == TLM_BYTE_ENABLED) {
        m_mem_handler->writeDevMem(w, data + i, 1);
      }
      w++;
    }
  }
}

void hbmChannel::writeMem(uint64_t addr, std::vector<uint8_t>& data){
  uint64_t bankA = addr >> 12;
  uint16_t byteA = addr & 0xFFF;
  pg4KB *pg = mem[bankA];
  if (pg == nullptr) {
    mem[bankA] = pg = new pg4KB(4096);
  }
  std::copy(data.begin(), data.end(), pg->begin()+byteA);
}

void hbmChannel::readMem(uint64_t addr, std::vector<uint8_t>& data){
  uint64_t bankA = addr >> 12;
  uint16_t byteA = addr & 0xFFF;
  pg4KB *pg = mem[bankA];
  if (pg == nullptr) {
    std::generate(data.begin(), data.end(), [] { return 0; });
  } else{
    std::copy(pg->begin() + byteA, pg->begin() + byteA + data.size(), data.begin());
  }
}


void hbmChannel::threadSpendTxnDelay(){
  uint32_t prvBankGrp = -1;
  uint32_t prvBank = -1;
  uint32_t prvPage = -1;
  Fx prvFx=NONE;
  bool FirstTx = true;
  sc_time lat(0, SC_NS);
  uint32_t activeBanks = 0;
  sc_time tFawStartTime(0, SC_PS);
  sc_time prvActivateCmdTime = sc_time(0, SC_PS);  //taken 1 PS and not 0 so that tRact check at index 0 fails,
                                                   //negative of small number makes a big unsigned number
  sc_time prvColCmdTime=sc_time(0, SC_PS);
  while(1){
    if (state != dramState::IDLE) wait(dramIdle);
    auto cmd = cmdQueue.get();
    switch (cmd.second) {
      case READ:
      case WRITE: {
        Fx fx = cmd.second;
        uint32_t bankGrp = getBankGrpAddr(cmd.first);
        uint32_t bank = getBankAddr(cmd.first);
        uint32_t page = getRowAddr(cmd.first);
        uint32_t col = getColAddr(cmd.first);
        //cout << " for Addr=0x" << std::hex << cmd.first << " ,in bankGrp=0x" << bankGrp << " ,in bank=0x" << bank << ",page=0x" << page << ",col=0x" << col << std::dec << endl;
        if (prvBankGrp != bankGrp || prvBank != bank || prvPage != page) {
          if (FirstTx) {
            wait(Ck);  // wait 1 cycle to execute 1st bank activate
            tFawStartTime = sc_time_stamp();
            FirstTx = false;
          } else {
            //precharge previous opened page, maintain tRas timing requirements
            sc_time tPre = getRemainingTime(tRas, prvActivateCmdTime);
            //timing requirement tRtp must be met is precharging after previous read command
            if (prvBankGrp == bankGrp && bank == prvBankGrp && page != prvPage && prvFx == READ) {
              switch (prvFx) {
                case READ:
                  tPre = std::max(tPre, getRemainingTime(tRtpL, prvColCmdTime));
                  break;
                case WRITE:
                  sc_time tPreAfterWr = tWl + tBl / 2 + tWr;
                  tPre = std::max(tPre, getRemainingTime(tPreAfterWr, prvColCmdTime));
                  break;
              }
            }
            wait(tPre);  //wait for maximum of tRas or tRtp(if prv cmd is READ) or tWl+BL/2+tWr(if prv cmd is WRITE)
            //#DFI//auto cmdR = std::make_shared<cmdRow>(prvBankGrp, prvBank, prvPage, PRE);
            //#DFI//d.rowCmdPipe.put(cmdR);
            wait(tRp);  //wait for precharge period

            //meet timing requirements between 2 consequtive activate commands
            sc_time tRact = (prvBankGrp != bankGrp) ? tRrdS : ((prvBank != bank) ? tRrdL : tRc);
            waitForRemainingTime(tRact, prvActivateCmdTime);
          }
          //send activate command to dram
          //#DFI//auto cmdR = std::make_shared<cmdRow>(bankGrp, bank, page, ACT);
          //#DFI//d.rowCmdPipe.put(cmdR);
          prvActivateCmdTime = sc_time_stamp();  //update last Page activate time current time
          activeBanks += 1;                      //increase Num activeBanks in current tFaw

          wait((fx == WRITE) ? tRcdwr : tRcdrd);  //wait time tRcd(tRcdwr) before sending write command
          //***********tRcd takes care of tCcd requirments below, #tbd correct if found otherwise
          //take care of tCcd time before sending Column command
          //sc_time tBeforeColCommand = ((sc_time_stamp() - prvColCmdTime) > tCcd) ? SC_ZERO_TIME : (tCcd - (sc_time_stamp() - prvColCmdTime));
          //if (tBeforeColCommand != SC_ZERO_TIME) wait(tBeforeColCommand);
          //*******************************************************************************/
          //#DFI//auto cmdC = std::make_shared<cmdCol>(bankGrp, bank, col, WR);
          //#DFI//d.colCmdPipe.put(cmdC);
          prvColCmdTime = sc_time_stamp();
          wait((fx == WRITE) ? tWl : tRl);  //wait for Write latency, added only for first as subsequent access will be seamless, #tbd check cases for non seamless support
        } else {
          sc_time tCcd = tCcdL;  //assumed that bankgroups are always enabled

          //READ after WRITE command requires (total write + bus turn) timing  requirements to be met
          if (prvFx == WRITE && fx == READ) {
            sc_time tReadafterWr = tWl + tBl / 2 + tWrtl;
            tCcd = std::max(tCcd, tReadafterWr);
          }

          //remaining tCcd b/w 2 consequtive column commmands
          waitForRemainingTime(tCcd, prvColCmdTime);
          prvColCmdTime = sc_time_stamp();
          //#DFI//auto cmdC = std::make_shared<cmdCol>(bankGrp, bank, col, WR);
          //#DFI//d.colCmdPipe.put(cmdC);
        }

        if (activeBanks >= 4) {
          //cout << "4 activattion within tFaw, waiting for remaining tFaw to avoid violation" << endl;
          //4 activattion within tFaw, waiting for remaining tFaw to avoid violation
          waitForRemainingTime(tFaw, tFawStartTime);
          activeBanks = 0;  //reset Num activeBanks to 0 after tFaw
          tFawStartTime = sc_time_stamp();
        }
        //cout << "time spent = " << sc_time_stamp() << endl;
        prvBankGrp = bankGrp;
        prvBankGrp = bank;
        prvPage = page;
        prvFx = cmd.second;
      } break;

      case wrSync:
        //cout << sc_time_stamp() << "pending wr Tx with id " << cmd.first << " done" << endl;
        //wrTxDone[cmd.first].notify(SC_ZERO_TIME);
        wrTxDone.notify(SC_ZERO_TIME);
        break;
      case rdSync:
        //cout << "pending rd Tx with id " << cmd.first << " done" << endl;
        //rdTxDone[cmd.first].notify(SC_ZERO_TIME);
        rdTxDone.notify(SC_ZERO_TIME);
        break;
      default:
        break;
    }
  }
}


uint32_t hbmChannel::extractAddr(uint64_t addr, std::vector<std::pair<uint32_t, uint32_t> >& vect){
  uint32_t extAddr=0;
  for(auto v: vect){
    unsigned lsb = v.first;
    unsigned mask = (1<<v.second)-1;
    extAddr |= (addr>>lsb) & mask;
  }
  return extAddr;
}

uint32_t hbmChannel::getBankGrpAddr(uint64_t addr){
  return extractAddr(addr, bankGrpAddrBits);
}
uint32_t hbmChannel::getBankAddr(uint64_t addr){
  return extractAddr(addr, bankAddrBits);
}
uint32_t hbmChannel::getRowAddr(uint64_t addr){
  return extractAddr(addr, rowAddrBits);
}
uint32_t hbmChannel::getColAddr(uint64_t addr){
  return extractAddr(addr, colAddrBits);
}

inline sc_time hbmChannel::getRemainingTime(sc_time tBound, sc_time tLast){
  return (((sc_time_stamp() - tLast) > tBound) ? SC_ZERO_TIME : (tBound - (sc_time_stamp() - tLast)));
}
inline void hbmChannel::waitForRemainingTime(sc_time tBound, sc_time tLast){
  sc_time tRem = getRemainingTime(tBound, tLast);
  if (tRem != SC_ZERO_TIME) wait(tRem);
}
