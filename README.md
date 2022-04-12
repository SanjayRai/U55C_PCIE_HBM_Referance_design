# U55C_PCIE_HBM_Referance_design
Referance XDMA HBM design for U55C

Requirements:
1. U55C card
2. x86 Linux desktop (OS requirement the same as xDMA driver OS requirement)
3. vivado 2021.2 (https://www.xilinx.com/support/download.html)



Build XDMA driver:
 Get the sources from https://github.com/Xilinx/dma_ip_drivers  and build the driver per instructions.


Building  bit file:

1. cd vivado 
2. vivado -source vivado_project.tcl

* The bifile (u55c_top.bit) and ltx (u55c_top.ltx) will be in the project_X/project_X.runs/impl_1 directory
* The bitfile and ltx file can be loaded to the U55C card via JTAG/USB Cable from Vivado Hardware Manager.

Modifying the  IPI design
1. cd IP
2. vivado -source vivado_project.tcl


Reboot server after  loading the bitfile. lspci command should now show the  enumerated card.
* lspci -vvv -s <BDF>
* The above command should also report xdma driver as the kernel module driver in use for the U55C card.
* Note the  BAR0 address. This is the address used  for MMIO reads and writes to the card


Building x86 linux host code

1. cd  HOST_code/build/build_dir
2. make
This builds the passthru.hw  executable
3. passthru.hw <BAR0 Address>

* THe above comman runs the executable which performaes the following:
a. Peek and Pokes to Block RAM as a proxy for Register reads and writes.
b. Uses System Monitor to read the die temprature
c. Uses xDMA driver to transfer 16GB of data between x86 host memory and U55C card HBM memory.

