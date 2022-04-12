/* Sanjay Rai - Routine to access PCIe via  dev.mem mmap  */
#ifndef SRAI_ACCEL_UTILS_H_
#define SRAI_ACCEL_UTILS_H_

/* Address Ranges as defined in VIvado IPI Address map */
/* NOTE: Be aware on any PCIe-AXI Address translation setup on the xDMA/PCIEBridge*/ 
/*       These address translations affect the address shown . THese address are  */
/*       exactly waht is populated on the IPI Address tab                         */
/* AXI MM Register interfaces */
#define AXI_MM_DDR4_C0         0x8000000400000000ULL
#define AXI_MM_DDR4_results_C0 0x8000000480000000ULL
#define AXI_MM_DDR4_C1         0x8000000000000000ULL
#define AXI_MM_DDR4_results_C1 0x8000000080000000ULL
#define AXI_MM_DDR4_C2         0x8000000800000000ULL
#define AXI_MM_DDR4_results_C2 0x8000000880000000ULL
#define AXI_MM_DDR4_C3         0x8000000C00000000ULL
#define AXI_MM_DDR4_results_C3 0x8000000C80000000ULL


/* AXI LITE Register interfaces */
#define AXI_LITE_SCRATCH_PAD_BRAM        0x00000000UL
#define AXI_LITE_AXI_SYSMON_BASE         0x00020000UL
#define SYSMON_Temptature_register        AXI_LITE_AXI_SYSMON_BASE + 0x400UL 
#define SYSMON_MAX_Temptature_register    AXI_LITE_AXI_SYSMON_BASE + 0x1c80L 
#define SYSMON_MIN_Temptature_register    AXI_LITE_AXI_SYSMON_BASE + 0x1c90L 


typedef struct {
    double current_temp;
    double maximum_temp;
    double minimum_temp;
} SysMon_temp_struct;

typedef struct {
    uint32_t KERNEL_DATASET;
    uint32_t KERNEL_CLOCK_COUNT;
    double KERNEL_EXECUTION_TIME;
} kernel_execution_metric_struct;

int fpga_clean (fpga_xdma_dev_mem *my_fpga_ptr);
void fpga_test_AXIL_LITE_8KSCRATCHPAD_BRAM (fpga_xdma_dev_mem *fpga_AXI_Lite_ptr);
void fpga_read_temprature (fpga_xdma_dev_mem *fpga_AXI_Lite_ptr, SysMon_temp_struct *sys_temp, int average_num);
void SRAI_dbg_wait (string dbg_string);
#endif // SRAI_ACCEL_UTILS_H_
