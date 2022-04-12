#ifndef IP_PCIE_HBM_SUB_SYS_HBM_0_0_H_
#define IP_PCIE_HBM_SUB_SYS_HBM_0_0_H_

// (c) Copyright 1995-2022 Xilinx, Inc. All rights reserved.
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


#ifndef XTLM
#include "xtlm.h"
#endif
#ifndef SYSTEMC_INCLUDED
#include <systemc>
#endif

#if defined(_MSC_VER)
#define DllExport __declspec(dllexport)
#elif defined(__GNUC__)
#define DllExport __attribute__ ((visibility("default")))
#else
#define DllExport
#endif

#include "PCIE_HBM_SUB_SYS_hbm_0_0_sc.h"




#ifdef XILINX_SIMULATOR
class DllExport PCIE_HBM_SUB_SYS_hbm_0_0 : public PCIE_HBM_SUB_SYS_hbm_0_0_sc
{
public:

  PCIE_HBM_SUB_SYS_hbm_0_0(const sc_core::sc_module_name& nm);
  virtual ~PCIE_HBM_SUB_SYS_hbm_0_0();

  // module pin-to-pin RTL interface

  sc_core::sc_in< bool > HBM_REF_CLK_0;
  sc_core::sc_in< bool > HBM_REF_CLK_1;
  sc_core::sc_in< bool > AXI_00_ACLK;
  sc_core::sc_in< bool > AXI_00_ARESET_N;
  sc_core::sc_in< sc_dt::sc_bv<34> > AXI_00_ARADDR;
  sc_core::sc_in< sc_dt::sc_bv<2> > AXI_00_ARBURST;
  sc_core::sc_in< sc_dt::sc_bv<6> > AXI_00_ARID;
  sc_core::sc_in< sc_dt::sc_bv<4> > AXI_00_ARLEN;
  sc_core::sc_in< sc_dt::sc_bv<3> > AXI_00_ARSIZE;
  sc_core::sc_in< bool > AXI_00_ARVALID;
  sc_core::sc_in< sc_dt::sc_bv<34> > AXI_00_AWADDR;
  sc_core::sc_in< sc_dt::sc_bv<2> > AXI_00_AWBURST;
  sc_core::sc_in< sc_dt::sc_bv<6> > AXI_00_AWID;
  sc_core::sc_in< sc_dt::sc_bv<4> > AXI_00_AWLEN;
  sc_core::sc_in< sc_dt::sc_bv<3> > AXI_00_AWSIZE;
  sc_core::sc_in< bool > AXI_00_AWVALID;
  sc_core::sc_in< bool > AXI_00_RREADY;
  sc_core::sc_in< bool > AXI_00_BREADY;
  sc_core::sc_in< sc_dt::sc_bv<256> > AXI_00_WDATA;
  sc_core::sc_in< bool > AXI_00_WLAST;
  sc_core::sc_in< sc_dt::sc_bv<32> > AXI_00_WSTRB;
  sc_core::sc_in< sc_dt::sc_bv<32> > AXI_00_WDATA_PARITY;
  sc_core::sc_in< bool > AXI_00_WVALID;
  sc_core::sc_in< bool > APB_0_PCLK;
  sc_core::sc_in< bool > APB_0_PRESET_N;
  sc_core::sc_in< bool > APB_1_PCLK;
  sc_core::sc_in< bool > APB_1_PRESET_N;
  sc_core::sc_out< bool > AXI_00_ARREADY;
  sc_core::sc_out< bool > AXI_00_AWREADY;
  sc_core::sc_out< sc_dt::sc_bv<32> > AXI_00_RDATA_PARITY;
  sc_core::sc_out< sc_dt::sc_bv<256> > AXI_00_RDATA;
  sc_core::sc_out< sc_dt::sc_bv<6> > AXI_00_RID;
  sc_core::sc_out< bool > AXI_00_RLAST;
  sc_core::sc_out< sc_dt::sc_bv<2> > AXI_00_RRESP;
  sc_core::sc_out< bool > AXI_00_RVALID;
  sc_core::sc_out< bool > AXI_00_WREADY;
  sc_core::sc_out< sc_dt::sc_bv<6> > AXI_00_BID;
  sc_core::sc_out< sc_dt::sc_bv<2> > AXI_00_BRESP;
  sc_core::sc_out< bool > AXI_00_BVALID;
  sc_core::sc_out< bool > apb_complete_0;
  sc_core::sc_out< bool > apb_complete_1;
  sc_core::sc_out< bool > DRAM_0_STAT_CATTRIP;
  sc_core::sc_out< sc_dt::sc_bv<7> > DRAM_0_STAT_TEMP;
  sc_core::sc_out< bool > DRAM_1_STAT_CATTRIP;
  sc_core::sc_out< sc_dt::sc_bv<7> > DRAM_1_STAT_TEMP;

  // Dummy Signals for IP Ports


protected:

  virtual void before_end_of_elaboration();

private:

  xtlm::xaximm_pin2xtlm_t<256,34,6,1,1,1,1,1>* mp_SAXI_00_8HI_transactor;
  xsc::common::vector2vector_converter<4,8>* mp_AXI_00_ARLEN_converter;
  sc_signal< sc_bv<8> > m_AXI_00_ARLEN_converter_signal;
  xsc::common::vector2vector_converter<4,8>* mp_AXI_00_AWLEN_converter;
  sc_signal< sc_bv<8> > m_AXI_00_AWLEN_converter_signal;
  sc_signal< bool > m_SAXI_00_8HI_transactor_rst_signal;

};
#endif // XILINX_SIMULATOR




#ifdef XM_SYSTEMC
class DllExport PCIE_HBM_SUB_SYS_hbm_0_0 : public PCIE_HBM_SUB_SYS_hbm_0_0_sc
{
public:

  PCIE_HBM_SUB_SYS_hbm_0_0(const sc_core::sc_module_name& nm);
  virtual ~PCIE_HBM_SUB_SYS_hbm_0_0();

  // module pin-to-pin RTL interface

  sc_core::sc_in< bool > HBM_REF_CLK_0;
  sc_core::sc_in< bool > HBM_REF_CLK_1;
  sc_core::sc_in< bool > AXI_00_ACLK;
  sc_core::sc_in< bool > AXI_00_ARESET_N;
  sc_core::sc_in< sc_dt::sc_bv<34> > AXI_00_ARADDR;
  sc_core::sc_in< sc_dt::sc_bv<2> > AXI_00_ARBURST;
  sc_core::sc_in< sc_dt::sc_bv<6> > AXI_00_ARID;
  sc_core::sc_in< sc_dt::sc_bv<4> > AXI_00_ARLEN;
  sc_core::sc_in< sc_dt::sc_bv<3> > AXI_00_ARSIZE;
  sc_core::sc_in< bool > AXI_00_ARVALID;
  sc_core::sc_in< sc_dt::sc_bv<34> > AXI_00_AWADDR;
  sc_core::sc_in< sc_dt::sc_bv<2> > AXI_00_AWBURST;
  sc_core::sc_in< sc_dt::sc_bv<6> > AXI_00_AWID;
  sc_core::sc_in< sc_dt::sc_bv<4> > AXI_00_AWLEN;
  sc_core::sc_in< sc_dt::sc_bv<3> > AXI_00_AWSIZE;
  sc_core::sc_in< bool > AXI_00_AWVALID;
  sc_core::sc_in< bool > AXI_00_RREADY;
  sc_core::sc_in< bool > AXI_00_BREADY;
  sc_core::sc_in< sc_dt::sc_bv<256> > AXI_00_WDATA;
  sc_core::sc_in< bool > AXI_00_WLAST;
  sc_core::sc_in< sc_dt::sc_bv<32> > AXI_00_WSTRB;
  sc_core::sc_in< sc_dt::sc_bv<32> > AXI_00_WDATA_PARITY;
  sc_core::sc_in< bool > AXI_00_WVALID;
  sc_core::sc_in< bool > APB_0_PCLK;
  sc_core::sc_in< bool > APB_0_PRESET_N;
  sc_core::sc_in< bool > APB_1_PCLK;
  sc_core::sc_in< bool > APB_1_PRESET_N;
  sc_core::sc_out< bool > AXI_00_ARREADY;
  sc_core::sc_out< bool > AXI_00_AWREADY;
  sc_core::sc_out< sc_dt::sc_bv<32> > AXI_00_RDATA_PARITY;
  sc_core::sc_out< sc_dt::sc_bv<256> > AXI_00_RDATA;
  sc_core::sc_out< sc_dt::sc_bv<6> > AXI_00_RID;
  sc_core::sc_out< bool > AXI_00_RLAST;
  sc_core::sc_out< sc_dt::sc_bv<2> > AXI_00_RRESP;
  sc_core::sc_out< bool > AXI_00_RVALID;
  sc_core::sc_out< bool > AXI_00_WREADY;
  sc_core::sc_out< sc_dt::sc_bv<6> > AXI_00_BID;
  sc_core::sc_out< sc_dt::sc_bv<2> > AXI_00_BRESP;
  sc_core::sc_out< bool > AXI_00_BVALID;
  sc_core::sc_out< bool > apb_complete_0;
  sc_core::sc_out< bool > apb_complete_1;
  sc_core::sc_out< bool > DRAM_0_STAT_CATTRIP;
  sc_core::sc_out< sc_dt::sc_bv<7> > DRAM_0_STAT_TEMP;
  sc_core::sc_out< bool > DRAM_1_STAT_CATTRIP;
  sc_core::sc_out< sc_dt::sc_bv<7> > DRAM_1_STAT_TEMP;

  // Dummy Signals for IP Ports


protected:

  virtual void before_end_of_elaboration();

private:

  xtlm::xaximm_pin2xtlm_t<256,34,6,1,1,1,1,1>* mp_SAXI_00_8HI_transactor;
  xsc::common::vector2vector_converter<4,8>* mp_AXI_00_ARLEN_converter;
  sc_signal< sc_bv<8> > m_AXI_00_ARLEN_converter_signal;
  xsc::common::vector2vector_converter<4,8>* mp_AXI_00_AWLEN_converter;
  sc_signal< sc_bv<8> > m_AXI_00_AWLEN_converter_signal;
  sc_signal< bool > m_SAXI_00_8HI_transactor_rst_signal;

};
#endif // XM_SYSTEMC




#ifdef RIVIERA
class DllExport PCIE_HBM_SUB_SYS_hbm_0_0 : public PCIE_HBM_SUB_SYS_hbm_0_0_sc
{
public:

  PCIE_HBM_SUB_SYS_hbm_0_0(const sc_core::sc_module_name& nm);
  virtual ~PCIE_HBM_SUB_SYS_hbm_0_0();

  // module pin-to-pin RTL interface

  sc_core::sc_in< bool > HBM_REF_CLK_0;
  sc_core::sc_in< bool > HBM_REF_CLK_1;
  sc_core::sc_in< bool > AXI_00_ACLK;
  sc_core::sc_in< bool > AXI_00_ARESET_N;
  sc_core::sc_in< sc_dt::sc_bv<34> > AXI_00_ARADDR;
  sc_core::sc_in< sc_dt::sc_bv<2> > AXI_00_ARBURST;
  sc_core::sc_in< sc_dt::sc_bv<6> > AXI_00_ARID;
  sc_core::sc_in< sc_dt::sc_bv<4> > AXI_00_ARLEN;
  sc_core::sc_in< sc_dt::sc_bv<3> > AXI_00_ARSIZE;
  sc_core::sc_in< bool > AXI_00_ARVALID;
  sc_core::sc_in< sc_dt::sc_bv<34> > AXI_00_AWADDR;
  sc_core::sc_in< sc_dt::sc_bv<2> > AXI_00_AWBURST;
  sc_core::sc_in< sc_dt::sc_bv<6> > AXI_00_AWID;
  sc_core::sc_in< sc_dt::sc_bv<4> > AXI_00_AWLEN;
  sc_core::sc_in< sc_dt::sc_bv<3> > AXI_00_AWSIZE;
  sc_core::sc_in< bool > AXI_00_AWVALID;
  sc_core::sc_in< bool > AXI_00_RREADY;
  sc_core::sc_in< bool > AXI_00_BREADY;
  sc_core::sc_in< sc_dt::sc_bv<256> > AXI_00_WDATA;
  sc_core::sc_in< bool > AXI_00_WLAST;
  sc_core::sc_in< sc_dt::sc_bv<32> > AXI_00_WSTRB;
  sc_core::sc_in< sc_dt::sc_bv<32> > AXI_00_WDATA_PARITY;
  sc_core::sc_in< bool > AXI_00_WVALID;
  sc_core::sc_in< bool > APB_0_PCLK;
  sc_core::sc_in< bool > APB_0_PRESET_N;
  sc_core::sc_in< bool > APB_1_PCLK;
  sc_core::sc_in< bool > APB_1_PRESET_N;
  sc_core::sc_out< bool > AXI_00_ARREADY;
  sc_core::sc_out< bool > AXI_00_AWREADY;
  sc_core::sc_out< sc_dt::sc_bv<32> > AXI_00_RDATA_PARITY;
  sc_core::sc_out< sc_dt::sc_bv<256> > AXI_00_RDATA;
  sc_core::sc_out< sc_dt::sc_bv<6> > AXI_00_RID;
  sc_core::sc_out< bool > AXI_00_RLAST;
  sc_core::sc_out< sc_dt::sc_bv<2> > AXI_00_RRESP;
  sc_core::sc_out< bool > AXI_00_RVALID;
  sc_core::sc_out< bool > AXI_00_WREADY;
  sc_core::sc_out< sc_dt::sc_bv<6> > AXI_00_BID;
  sc_core::sc_out< sc_dt::sc_bv<2> > AXI_00_BRESP;
  sc_core::sc_out< bool > AXI_00_BVALID;
  sc_core::sc_out< bool > apb_complete_0;
  sc_core::sc_out< bool > apb_complete_1;
  sc_core::sc_out< bool > DRAM_0_STAT_CATTRIP;
  sc_core::sc_out< sc_dt::sc_bv<7> > DRAM_0_STAT_TEMP;
  sc_core::sc_out< bool > DRAM_1_STAT_CATTRIP;
  sc_core::sc_out< sc_dt::sc_bv<7> > DRAM_1_STAT_TEMP;

  // Dummy Signals for IP Ports


protected:

  virtual void before_end_of_elaboration();

private:

  xtlm::xaximm_pin2xtlm_t<256,34,6,1,1,1,1,1>* mp_SAXI_00_8HI_transactor;
  xsc::common::vector2vector_converter<4,8>* mp_AXI_00_ARLEN_converter;
  sc_signal< sc_bv<8> > m_AXI_00_ARLEN_converter_signal;
  xsc::common::vector2vector_converter<4,8>* mp_AXI_00_AWLEN_converter;
  sc_signal< sc_bv<8> > m_AXI_00_AWLEN_converter_signal;
  sc_signal< bool > m_SAXI_00_8HI_transactor_rst_signal;

};
#endif // RIVIERA




#ifdef VCSSYSTEMC
#include "utils/xtlm_aximm_target_stub.h"

class DllExport PCIE_HBM_SUB_SYS_hbm_0_0 : public PCIE_HBM_SUB_SYS_hbm_0_0_sc
{
public:

  PCIE_HBM_SUB_SYS_hbm_0_0(const sc_core::sc_module_name& nm);
  virtual ~PCIE_HBM_SUB_SYS_hbm_0_0();

  // module pin-to-pin RTL interface

  sc_core::sc_in< bool > HBM_REF_CLK_0;
  sc_core::sc_in< bool > HBM_REF_CLK_1;
  sc_core::sc_in< bool > AXI_00_ACLK;
  sc_core::sc_in< bool > AXI_00_ARESET_N;
  sc_core::sc_in< sc_dt::sc_bv<34> > AXI_00_ARADDR;
  sc_core::sc_in< sc_dt::sc_bv<2> > AXI_00_ARBURST;
  sc_core::sc_in< sc_dt::sc_bv<6> > AXI_00_ARID;
  sc_core::sc_in< sc_dt::sc_bv<4> > AXI_00_ARLEN;
  sc_core::sc_in< sc_dt::sc_bv<3> > AXI_00_ARSIZE;
  sc_core::sc_in< bool > AXI_00_ARVALID;
  sc_core::sc_in< sc_dt::sc_bv<34> > AXI_00_AWADDR;
  sc_core::sc_in< sc_dt::sc_bv<2> > AXI_00_AWBURST;
  sc_core::sc_in< sc_dt::sc_bv<6> > AXI_00_AWID;
  sc_core::sc_in< sc_dt::sc_bv<4> > AXI_00_AWLEN;
  sc_core::sc_in< sc_dt::sc_bv<3> > AXI_00_AWSIZE;
  sc_core::sc_in< bool > AXI_00_AWVALID;
  sc_core::sc_in< bool > AXI_00_RREADY;
  sc_core::sc_in< bool > AXI_00_BREADY;
  sc_core::sc_in< sc_dt::sc_bv<256> > AXI_00_WDATA;
  sc_core::sc_in< bool > AXI_00_WLAST;
  sc_core::sc_in< sc_dt::sc_bv<32> > AXI_00_WSTRB;
  sc_core::sc_in< sc_dt::sc_bv<32> > AXI_00_WDATA_PARITY;
  sc_core::sc_in< bool > AXI_00_WVALID;
  sc_core::sc_in< bool > APB_0_PCLK;
  sc_core::sc_in< bool > APB_0_PRESET_N;
  sc_core::sc_in< bool > APB_1_PCLK;
  sc_core::sc_in< bool > APB_1_PRESET_N;
  sc_core::sc_out< bool > AXI_00_ARREADY;
  sc_core::sc_out< bool > AXI_00_AWREADY;
  sc_core::sc_out< sc_dt::sc_bv<32> > AXI_00_RDATA_PARITY;
  sc_core::sc_out< sc_dt::sc_bv<256> > AXI_00_RDATA;
  sc_core::sc_out< sc_dt::sc_bv<6> > AXI_00_RID;
  sc_core::sc_out< bool > AXI_00_RLAST;
  sc_core::sc_out< sc_dt::sc_bv<2> > AXI_00_RRESP;
  sc_core::sc_out< bool > AXI_00_RVALID;
  sc_core::sc_out< bool > AXI_00_WREADY;
  sc_core::sc_out< sc_dt::sc_bv<6> > AXI_00_BID;
  sc_core::sc_out< sc_dt::sc_bv<2> > AXI_00_BRESP;
  sc_core::sc_out< bool > AXI_00_BVALID;
  sc_core::sc_out< bool > apb_complete_0;
  sc_core::sc_out< bool > apb_complete_1;
  sc_core::sc_out< bool > DRAM_0_STAT_CATTRIP;
  sc_core::sc_out< sc_dt::sc_bv<7> > DRAM_0_STAT_TEMP;
  sc_core::sc_out< bool > DRAM_1_STAT_CATTRIP;
  sc_core::sc_out< sc_dt::sc_bv<7> > DRAM_1_STAT_TEMP;

  // Dummy Signals for IP Ports


protected:

  virtual void before_end_of_elaboration();

private:

  xtlm::xaximm_pin2xtlm_t<256,34,6,1,1,1,1,1>* mp_SAXI_00_8HI_transactor;
  xsc::common::vector2vector_converter<4,8>* mp_AXI_00_ARLEN_converter;
  sc_signal< sc_bv<8> > m_AXI_00_ARLEN_converter_signal;
  xsc::common::vector2vector_converter<4,8>* mp_AXI_00_AWLEN_converter;
  sc_signal< sc_bv<8> > m_AXI_00_AWLEN_converter_signal;
  sc_signal< bool > m_SAXI_00_8HI_transactor_rst_signal;

  // Transactor stubs
  xtlm::xtlm_aximm_target_stub * SAXI_00_8HI_transactor_target_rd_socket_stub;
  xtlm::xtlm_aximm_target_stub * SAXI_00_8HI_transactor_target_wr_socket_stub;

  // Socket stubs

};
#endif // VCSSYSTEMC




#ifdef MTI_SYSTEMC
#include "utils/xtlm_aximm_target_stub.h"

class DllExport PCIE_HBM_SUB_SYS_hbm_0_0 : public PCIE_HBM_SUB_SYS_hbm_0_0_sc
{
public:

  PCIE_HBM_SUB_SYS_hbm_0_0(const sc_core::sc_module_name& nm);
  virtual ~PCIE_HBM_SUB_SYS_hbm_0_0();

  // module pin-to-pin RTL interface

  sc_core::sc_in< bool > HBM_REF_CLK_0;
  sc_core::sc_in< bool > HBM_REF_CLK_1;
  sc_core::sc_in< bool > AXI_00_ACLK;
  sc_core::sc_in< bool > AXI_00_ARESET_N;
  sc_core::sc_in< sc_dt::sc_bv<34> > AXI_00_ARADDR;
  sc_core::sc_in< sc_dt::sc_bv<2> > AXI_00_ARBURST;
  sc_core::sc_in< sc_dt::sc_bv<6> > AXI_00_ARID;
  sc_core::sc_in< sc_dt::sc_bv<4> > AXI_00_ARLEN;
  sc_core::sc_in< sc_dt::sc_bv<3> > AXI_00_ARSIZE;
  sc_core::sc_in< bool > AXI_00_ARVALID;
  sc_core::sc_in< sc_dt::sc_bv<34> > AXI_00_AWADDR;
  sc_core::sc_in< sc_dt::sc_bv<2> > AXI_00_AWBURST;
  sc_core::sc_in< sc_dt::sc_bv<6> > AXI_00_AWID;
  sc_core::sc_in< sc_dt::sc_bv<4> > AXI_00_AWLEN;
  sc_core::sc_in< sc_dt::sc_bv<3> > AXI_00_AWSIZE;
  sc_core::sc_in< bool > AXI_00_AWVALID;
  sc_core::sc_in< bool > AXI_00_RREADY;
  sc_core::sc_in< bool > AXI_00_BREADY;
  sc_core::sc_in< sc_dt::sc_bv<256> > AXI_00_WDATA;
  sc_core::sc_in< bool > AXI_00_WLAST;
  sc_core::sc_in< sc_dt::sc_bv<32> > AXI_00_WSTRB;
  sc_core::sc_in< sc_dt::sc_bv<32> > AXI_00_WDATA_PARITY;
  sc_core::sc_in< bool > AXI_00_WVALID;
  sc_core::sc_in< bool > APB_0_PCLK;
  sc_core::sc_in< bool > APB_0_PRESET_N;
  sc_core::sc_in< bool > APB_1_PCLK;
  sc_core::sc_in< bool > APB_1_PRESET_N;
  sc_core::sc_out< bool > AXI_00_ARREADY;
  sc_core::sc_out< bool > AXI_00_AWREADY;
  sc_core::sc_out< sc_dt::sc_bv<32> > AXI_00_RDATA_PARITY;
  sc_core::sc_out< sc_dt::sc_bv<256> > AXI_00_RDATA;
  sc_core::sc_out< sc_dt::sc_bv<6> > AXI_00_RID;
  sc_core::sc_out< bool > AXI_00_RLAST;
  sc_core::sc_out< sc_dt::sc_bv<2> > AXI_00_RRESP;
  sc_core::sc_out< bool > AXI_00_RVALID;
  sc_core::sc_out< bool > AXI_00_WREADY;
  sc_core::sc_out< sc_dt::sc_bv<6> > AXI_00_BID;
  sc_core::sc_out< sc_dt::sc_bv<2> > AXI_00_BRESP;
  sc_core::sc_out< bool > AXI_00_BVALID;
  sc_core::sc_out< bool > apb_complete_0;
  sc_core::sc_out< bool > apb_complete_1;
  sc_core::sc_out< bool > DRAM_0_STAT_CATTRIP;
  sc_core::sc_out< sc_dt::sc_bv<7> > DRAM_0_STAT_TEMP;
  sc_core::sc_out< bool > DRAM_1_STAT_CATTRIP;
  sc_core::sc_out< sc_dt::sc_bv<7> > DRAM_1_STAT_TEMP;

  // Dummy Signals for IP Ports


protected:

  virtual void before_end_of_elaboration();

private:

  xtlm::xaximm_pin2xtlm_t<256,34,6,1,1,1,1,1>* mp_SAXI_00_8HI_transactor;
  xsc::common::vector2vector_converter<4,8>* mp_AXI_00_ARLEN_converter;
  sc_signal< sc_bv<8> > m_AXI_00_ARLEN_converter_signal;
  xsc::common::vector2vector_converter<4,8>* mp_AXI_00_AWLEN_converter;
  sc_signal< sc_bv<8> > m_AXI_00_AWLEN_converter_signal;
  sc_signal< bool > m_SAXI_00_8HI_transactor_rst_signal;

  // Transactor stubs
  xtlm::xtlm_aximm_target_stub * SAXI_00_8HI_transactor_target_rd_socket_stub;
  xtlm::xtlm_aximm_target_stub * SAXI_00_8HI_transactor_target_wr_socket_stub;

  // Socket stubs

};
#endif // MTI_SYSTEMC
#endif // IP_PCIE_HBM_SUB_SYS_HBM_0_0_H_
