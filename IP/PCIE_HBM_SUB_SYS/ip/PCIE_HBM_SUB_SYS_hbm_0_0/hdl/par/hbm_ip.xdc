
create_clock -period 10.00 [get_ports HBM_REF_CLK_0]
#create_clock -period 10.0 [get_ports APB_0_PCLK]
create_clock -period 10.00 [get_ports HBM_REF_CLK_1]
#create_clock -period 10.0 [get_ports APB_1_PCLK]

#set_false_path -from [get_pins {*/rst_cnt_reg[*]/C}] 
#set_false_path -from [get_pins {*/hbm_rst_n_r_reg/C}]


#set_false_path -from [get_clocks */APB_0_PCLK] -to [get_clocks */APB_1_PCLK]
#set_false_path -from [get_clocks */APB_1_PCLK] -to [get_clocks */APB_0_PCLK] 

 
 
 
 
 
 
 
 
 
 
