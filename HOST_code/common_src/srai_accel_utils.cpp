/* Sanjay Rai - Test routing to access PCIe via  dev.mem mmap  */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <time.h>
#include <inttypes.h>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <cmath>
#include "pcie_memio.h" 
//#include "pcie_memio_winx.h" 
#include "srai_accel_utils.h" 

using namespace std;

void fpga_test_AXIL_LITE_8KSCRATCHPAD_BRAM (fpga_xdma_dev_mem *fpga_AXI_Lite_ptr) {

    cout << "Testing Axi_Lite ScratchPad BRAM\n";
    uint32_t tmp_dbg_val[2048];
    uint32_t count_v = 0;
    for (int idx = 0; idx < 2048; idx+=4) {
        //tmp_dbg_val[idx]  = (uint32_t)(rand() % 0xffffffff); 
        tmp_dbg_val[idx]  = (uint32_t)(count_v); 
        count_v++;
        fpga_AXI_Lite_ptr->fpga_poke((AXI_LITE_SCRATCH_PAD_BRAM + idx), tmp_dbg_val[idx]);
    }
    uint32_t tmp_dbg;
    for (int idx = 0; idx < 2048; idx+=4) {
        tmp_dbg= fpga_AXI_Lite_ptr->fpga_peek(AXI_LITE_SCRATCH_PAD_BRAM + idx);
        if (tmp_dbg != tmp_dbg_val[idx]) {
            printf("Error !!! Axi_lite Test failed @ Index = %d :: Expected %x but got %x\n", idx, tmp_dbg_val[idx], tmp_dbg);
        }
    }

    cout << "Done Testing Axi_Lite ScratchPad BRAM\n";

}

void fpga_read_temprature (fpga_xdma_dev_mem *fpga_AXI_Lite_ptr, SysMon_temp_struct *sys_temp, int average_num) {
        double temprature_v = 0.0;
        for (int i = 0 ; i < average_num; i++) {
            temprature_v += ((double)(fpga_AXI_Lite_ptr->fpga_peek(SYSMON_Temptature_register))*509.3140064/(65536.0))-280.23087870;
        }
        sys_temp->current_temp = (temprature_v/(double)average_num); 
        sys_temp->maximum_temp = ((double)(fpga_AXI_Lite_ptr->fpga_peek(SYSMON_MAX_Temptature_register))*509.3140064/(65536.0))-280.23087870;
        sys_temp->minimum_temp = ((double)(fpga_AXI_Lite_ptr->fpga_peek(SYSMON_MIN_Temptature_register))*509.3140064/(65536.0))-280.23087870;
}


// ------------ Clean -----------------------
int fpga_clean (fpga_xdma_dev_mem *my_fpga_ptr) {
        my_fpga_ptr->fpga_xdma_dev_mem_clean();

        return 0;
}


void SRAI_dbg_wait (string dbg_string) {
    string Srai_dbg_wait;
    cout << "Dbg Pause : " << dbg_string << " : Enter any character (followed by Enter key) to proceed : ";
    cin >> Srai_dbg_wait;
}

