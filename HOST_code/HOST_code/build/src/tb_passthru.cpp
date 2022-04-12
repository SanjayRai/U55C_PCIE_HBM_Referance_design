#include<stdio.h>
#include<math.h>
#include <errno.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/mman.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <cmath>
#include "pcie_memio.h" 
#include "srai_accel_utils.h" 
#define ZERO_f 1.0e-4
#define ITERATION_SZ 1
//#define ITERATION_SZ 4096
//#define ITERATION_SZ 8192
//#define ITERATION_SZ 16384
//#define ITERATION_SZ 32768
#define ONE_GIG (1024UL*1024UL*1024UL)

//#define TEST_DATA_SIZE 1024
#define TEST_DATA_SIZE ONE_GIG 

#define HW_Kernel_frequency 250000000.0

#define  HBM_CAPACITY_GB 16


using namespace std;


int check_buf(unsigned char* buf, unsigned int size)
{
    int i;
    int error_count = 0;
    for(i = 0; i < size; i++) {
        buf[i] = (char)0xA5;
    }
    for(i = 0; i < size; i++) {
        if (buf[i] != (char)0xA5) {
         error_count++;
        }
    }
    return error_count;
}


int main(int argc, char** argv) {

  int            fd;
  char  attr[1024];
  unsigned int   udma_buf_size;
  uint32_t   buf_size;
  uint32_t   result_buffer_offset;
  uint64_t phys_addr;
  uint64_t phys_addr_upper;
  unsigned long  debug_vma = 0;
  unsigned long  sync_mode = 2;
  uint32_t dbg_counter = 0;
  uint32_t test_data_byte_count = 0;

  unsigned long int itrn = 0;
  int compute_itn_count;
  uint32_t TCR0;
  volatile uint32_t TCSR0;
  uint32_t itn_count = 0;
  time_t t;
  srand((unsigned) time(&t));
  double high_res_elapsed_time = 0.0f;
  double high_res_elapsed_time_HW = 0.0f;
  double high_res_elapsed_time_SW = 0.0f;
  chrono::high_resolution_clock::time_point start_t;
  chrono::high_resolution_clock::time_point stop_t;
  chrono::duration<double> elapsed_hi_res;
  SysMon_temp_struct sys_temprature;
  bool RESULT_SUCESSFULL;
  kernel_execution_metric_struct kernel_execution_metric; 

  uint64_t cal_itn_count = 0;
  uint64_t HBM_startAddress = 0;

// Compile for SRAI custom HLS accelerator platform 
    uint32_t PCI_BAR_base_VF0;
    stringstream PCI_BAR_VF0_base_str;

    if (argc != 2) {
        printf("usage: %s fpga_bin_file \n", argv[0]);
        return -1;
    }

    PCI_BAR_VF0_base_str << hex <<  argv[1]; 

    PCI_BAR_VF0_base_str >> PCI_BAR_base_VF0;

    
    cout << "VF0 Base Addr = 0x"  << hex << PCI_BAR_base_VF0 << endl;

    cout << "Initializing FPGA\n";
    fpga_xdma_dev_mem *fpga_ptr_vf0 = new fpga_xdma_dev_mem;
    fpga_ptr_vf0->fpga_xdma_dev_mem_init((4*1024*1024), PCI_BAR_base_VF0);



    unsigned char *to_FPGA_data_buf = new unsigned char[TEST_DATA_SIZE];
    unsigned char *inter_FPGA_data_buf = new unsigned char[TEST_DATA_SIZE];
    unsigned char *from_FPGA_data_buf = new unsigned char[TEST_DATA_SIZE];
    for (int i= 0; i < TEST_DATA_SIZE; i ++) {
        to_FPGA_data_buf[i] = ((unsigned char)((rand() % 256)));
    }

    cout << dec << "Testing BRAM 8K Memory \n";
    fpga_test_AXIL_LITE_8KSCRATCHPAD_BRAM (fpga_ptr_vf0);



    cout << dec << "Reading FPGA Temprature struct via SysMON\n";
    fpga_read_temprature(fpga_ptr_vf0, &sys_temprature, 10);
    cout << "Current FPGA Die Temprature (deg C) =  " << sys_temprature.current_temp << endl;
    cout << "Current FPGA Max Die Temprature (deg C) =  " << sys_temprature.maximum_temp << endl;
    cout << "Current FPGA Min Die Temprature (deg C) =  " << sys_temprature.minimum_temp << endl;

    

        int xfer_count = 0;
        int ERR_count = 0;
        HBM_startAddress = 0x0000000000000000;
        for (int i = 0; i < HBM_CAPACITY_GB; i++ ) {
            cout << hex << "\n\nTesting HBM Memory Address : 0x" << HBM_startAddress << endl; 
            start_t = chrono::high_resolution_clock::now();
            xfer_count = fpga_ptr_vf0->fpga_xDMA_write64((HBM_startAddress), (char *)(to_FPGA_data_buf), TEST_DATA_SIZE);
            xfer_count = fpga_ptr_vf0->fpga_xDMA_read64((HBM_startAddress), (char *)(from_FPGA_data_buf), TEST_DATA_SIZE);
            stop_t = chrono::high_resolution_clock::now();
            elapsed_hi_res = stop_t - start_t ;
            high_res_elapsed_time = elapsed_hi_res.count();
            double xDMA_round_Trip_thruput = (TEST_DATA_SIZE/high_res_elapsed_time);
            cout << "xDMA Execution time =  " <<  high_res_elapsed_time << "s\n";
            cout << "xDMA THroughput =  " << xDMA_round_Trip_thruput  << " Bytes/s\n";
            for (int i= 0; i < TEST_DATA_SIZE; i++) {
                if(to_FPGA_data_buf[i] != from_FPGA_data_buf[i]) {
                    ERR_count++;
                }
            }

            cout << "xDMA xfer Err Count : " << dec << ERR_count << endl;
            HBM_startAddress += ONE_GIG;
        }

        for (int i= 0; i < TEST_DATA_SIZE; i ++) {
            to_FPGA_data_buf[i] = ((unsigned char)((rand() % 256)));
        }

        HBM_startAddress = 0x0000000000000000;
        cout << hex << "\n\nChain Testing HBM Memory Address : 0x" << HBM_startAddress << endl; 
        xfer_count = fpga_ptr_vf0->fpga_xDMA_write64((HBM_startAddress), (char *)(to_FPGA_data_buf), TEST_DATA_SIZE);

        for (int i = 0; i < (HBM_CAPACITY_GB-1); i++) {
            cout << hex << "\n\nChain Testing HBM Memory Address : 0x" << (HBM_startAddress+((i+1)*ONE_GIG)) << endl; 
            xfer_count = fpga_ptr_vf0->fpga_xDMA_read64((HBM_startAddress+(i*ONE_GIG)), (char *)(inter_FPGA_data_buf), TEST_DATA_SIZE);
            xfer_count = fpga_ptr_vf0->fpga_xDMA_write64((HBM_startAddress+((i+1)*ONE_GIG)), (char *)(inter_FPGA_data_buf), TEST_DATA_SIZE);
        }

        xfer_count = fpga_ptr_vf0->fpga_xDMA_read64((HBM_startAddress+((HBM_CAPACITY_GB-1)*ONE_GIG)), (char *)(from_FPGA_data_buf), TEST_DATA_SIZE);
        for (int i= 0; i < TEST_DATA_SIZE; i++) {
            if(to_FPGA_data_buf[i] != from_FPGA_data_buf[i]) {
                ERR_count++;
            }
        }

            cout << "xDMA xfer Err Count : " << dec << ERR_count << endl;


    fpga_clean(fpga_ptr_vf0);
    cout << "*************     Test finished ****************************************************************************\n"; 
    return 0;
}


