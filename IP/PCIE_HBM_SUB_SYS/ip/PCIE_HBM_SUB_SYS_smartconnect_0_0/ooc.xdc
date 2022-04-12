# aclk {FREQ_HZ 250000000 CLK_DOMAIN PCIE_HBM_SUB_SYS_xdma_0_0_axi_aclk PHASE 0.0} aclk1 {FREQ_HZ 250000000 CLK_DOMAIN PCIE_HBM_SUB_SYS_xdma_0_0_axi_aclk PHASE 0.0}
# Clock Domain: PCIE_HBM_SUB_SYS_xdma_0_0_axi_aclk
create_clock -name aclk -period 4.000 [get_ports aclk]
# Generated clocks
create_generated_clock -name aclk1 -source [get_ports aclk] -divide_by 1 [get_ports aclk1]
