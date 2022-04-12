create_project project_X ./project_X -part xcu55c-fsvh2892-2L-e

add_files -norecurse ../IP/PCIE_HBM_SUB_SYS/PCIE_HBM_SUB_SYS.bd
add_files -norecurse ../rtl/u55c_top.sv
update_compile_order -fileset sources_1
add_files -fileset constrs_1 -norecurse ../xdc/u55c_top.xdc
launch_runs impl_1 -to_step write_bitstream -jobs 8
wait_on_run impl_1
