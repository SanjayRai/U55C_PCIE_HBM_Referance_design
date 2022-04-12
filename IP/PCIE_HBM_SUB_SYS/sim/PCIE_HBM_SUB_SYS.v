//Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2021.2 (lin64) Build 3367213 Tue Oct 19 02:47:39 MDT 2021
//Date        : Fri Apr  1 07:06:33 2022
//Host        : xsjgd1 running 64-bit Red Hat Enterprise Linux Workstation release 7.5 (Maipo)
//Command     : generate_target PCIE_HBM_SUB_SYS.bd
//Design      : PCIE_HBM_SUB_SYS
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "PCIE_HBM_SUB_SYS,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=PCIE_HBM_SUB_SYS,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=12,numReposBlks=12,numNonXlnxBlks=0,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=0,numHdlrefBlks=0,numPkgbdBlks=0,bdsource=USER,da_axi4_cnt=1,da_board_cnt=2,da_bram_cntlr_cnt=4,da_clkrst_cnt=5,synth_mode=Global}" *) (* HW_HANDOFF = "PCIE_HBM_SUB_SYS.hwdef" *) 
module PCIE_HBM_SUB_SYS
   (HBM_REF_CLK,
    pcie_rxn,
    pcie_rxp,
    pcie_txn,
    pcie_txp,
    prst_n,
    sys_clk,
    sys_clk_gt);
  (* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.HBM_REF_CLK CLK" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.HBM_REF_CLK, CLK_DOMAIN PCIE_HBM_SUB_SYS_HBM_REF_CLK_0_0, FREQ_HZ 100000000, FREQ_TOLERANCE_HZ 0, INSERT_VIP 0, PHASE 0.0" *) input HBM_REF_CLK;
  (* X_INTERFACE_INFO = "xilinx.com:interface:pcie_7x_mgt:1.0 pcie rxn" *) input [7:0]pcie_rxn;
  (* X_INTERFACE_INFO = "xilinx.com:interface:pcie_7x_mgt:1.0 pcie rxp" *) input [7:0]pcie_rxp;
  (* X_INTERFACE_INFO = "xilinx.com:interface:pcie_7x_mgt:1.0 pcie txn" *) output [7:0]pcie_txn;
  (* X_INTERFACE_INFO = "xilinx.com:interface:pcie_7x_mgt:1.0 pcie txp" *) output [7:0]pcie_txp;
  (* X_INTERFACE_INFO = "xilinx.com:signal:reset:1.0 RST.PRST_N RST" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME RST.PRST_N, INSERT_VIP 0, POLARITY ACTIVE_LOW" *) input prst_n;
  (* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.SYS_CLK CLK" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.SYS_CLK, CLK_DOMAIN PCIE_HBM_SUB_SYS_sys_clk_0, FREQ_HZ 100000000, FREQ_TOLERANCE_HZ 0, INSERT_VIP 0, PHASE 0.0" *) input sys_clk;
  (* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.SYS_CLK_GT CLK" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.SYS_CLK_GT, CLK_DOMAIN PCIE_HBM_SUB_SYS_sys_clk_gt_0, FREQ_HZ 100000000, FREQ_TOLERANCE_HZ 0, INSERT_VIP 0, PHASE 0.0" *) input sys_clk_gt;

  wire HBM_REF_CLK_0_0_1;
  wire [14:0]axi_bram_ctrl_1_BRAM_PORTA_ADDR;
  wire axi_bram_ctrl_1_BRAM_PORTA_CLK;
  wire [511:0]axi_bram_ctrl_1_BRAM_PORTA_DIN;
  wire [511:0]axi_bram_ctrl_1_BRAM_PORTA_DOUT;
  wire axi_bram_ctrl_1_BRAM_PORTA_EN;
  wire axi_bram_ctrl_1_BRAM_PORTA_RST;
  wire [63:0]axi_bram_ctrl_1_BRAM_PORTA_WE;
  wire [14:0]axi_bram_ctrl_1_BRAM_PORTB_ADDR;
  wire axi_bram_ctrl_1_BRAM_PORTB_CLK;
  wire [511:0]axi_bram_ctrl_1_BRAM_PORTB_DIN;
  wire [511:0]axi_bram_ctrl_1_BRAM_PORTB_DOUT;
  wire axi_bram_ctrl_1_BRAM_PORTB_EN;
  wire axi_bram_ctrl_1_BRAM_PORTB_RST;
  wire [63:0]axi_bram_ctrl_1_BRAM_PORTB_WE;
  wire clk_wiz_0_clk_out100m;
  wire [0:0]proc_sys_reset_0_peripheral_aresetn;
  wire reset_rtl_0_1;
  wire [14:0]smartconnect_0_M00_AXI_ARADDR;
  wire [1:0]smartconnect_0_M00_AXI_ARBURST;
  wire [3:0]smartconnect_0_M00_AXI_ARCACHE;
  wire [7:0]smartconnect_0_M00_AXI_ARLEN;
  wire [0:0]smartconnect_0_M00_AXI_ARLOCK;
  wire [2:0]smartconnect_0_M00_AXI_ARPROT;
  wire smartconnect_0_M00_AXI_ARREADY;
  wire [2:0]smartconnect_0_M00_AXI_ARSIZE;
  wire smartconnect_0_M00_AXI_ARVALID;
  wire [14:0]smartconnect_0_M00_AXI_AWADDR;
  wire [1:0]smartconnect_0_M00_AXI_AWBURST;
  wire [3:0]smartconnect_0_M00_AXI_AWCACHE;
  wire [7:0]smartconnect_0_M00_AXI_AWLEN;
  wire [0:0]smartconnect_0_M00_AXI_AWLOCK;
  wire [2:0]smartconnect_0_M00_AXI_AWPROT;
  wire smartconnect_0_M00_AXI_AWREADY;
  wire [2:0]smartconnect_0_M00_AXI_AWSIZE;
  wire smartconnect_0_M00_AXI_AWVALID;
  wire smartconnect_0_M00_AXI_BREADY;
  wire [1:0]smartconnect_0_M00_AXI_BRESP;
  wire smartconnect_0_M00_AXI_BVALID;
  wire [511:0]smartconnect_0_M00_AXI_RDATA;
  wire smartconnect_0_M00_AXI_RLAST;
  wire smartconnect_0_M00_AXI_RREADY;
  wire [1:0]smartconnect_0_M00_AXI_RRESP;
  wire smartconnect_0_M00_AXI_RVALID;
  wire [511:0]smartconnect_0_M00_AXI_WDATA;
  wire smartconnect_0_M00_AXI_WLAST;
  wire smartconnect_0_M00_AXI_WREADY;
  wire [63:0]smartconnect_0_M00_AXI_WSTRB;
  wire smartconnect_0_M00_AXI_WVALID;
  wire [12:0]smartconnect_0_M01_AXI_ARADDR;
  wire smartconnect_0_M01_AXI_ARREADY;
  wire smartconnect_0_M01_AXI_ARVALID;
  wire [12:0]smartconnect_0_M01_AXI_AWADDR;
  wire smartconnect_0_M01_AXI_AWREADY;
  wire smartconnect_0_M01_AXI_AWVALID;
  wire smartconnect_0_M01_AXI_BREADY;
  wire [1:0]smartconnect_0_M01_AXI_BRESP;
  wire smartconnect_0_M01_AXI_BVALID;
  wire [31:0]smartconnect_0_M01_AXI_RDATA;
  wire smartconnect_0_M01_AXI_RREADY;
  wire [1:0]smartconnect_0_M01_AXI_RRESP;
  wire smartconnect_0_M01_AXI_RVALID;
  wire [31:0]smartconnect_0_M01_AXI_WDATA;
  wire smartconnect_0_M01_AXI_WREADY;
  wire [3:0]smartconnect_0_M01_AXI_WSTRB;
  wire smartconnect_0_M01_AXI_WVALID;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 ARADDR" *) (* DONT_TOUCH *) wire [33:0]smartconnect_1_M00_AXI_ARADDR;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 ARBURST" *) (* DONT_TOUCH *) wire [1:0]smartconnect_1_M00_AXI_ARBURST;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 ARCACHE" *) (* DONT_TOUCH *) wire [3:0]smartconnect_1_M00_AXI_ARCACHE;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 ARLEN" *) (* DONT_TOUCH *) wire [3:0]smartconnect_1_M00_AXI_ARLEN;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 ARLOCK" *) (* DONT_TOUCH *) wire [1:0]smartconnect_1_M00_AXI_ARLOCK;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 ARPROT" *) (* DONT_TOUCH *) wire [2:0]smartconnect_1_M00_AXI_ARPROT;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 ARQOS" *) (* DONT_TOUCH *) wire [3:0]smartconnect_1_M00_AXI_ARQOS;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 ARREADY" *) (* DONT_TOUCH *) wire smartconnect_1_M00_AXI_ARREADY;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 ARSIZE" *) (* DONT_TOUCH *) wire [2:0]smartconnect_1_M00_AXI_ARSIZE;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 ARVALID" *) (* DONT_TOUCH *) wire smartconnect_1_M00_AXI_ARVALID;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 AWADDR" *) (* DONT_TOUCH *) wire [33:0]smartconnect_1_M00_AXI_AWADDR;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 AWBURST" *) (* DONT_TOUCH *) wire [1:0]smartconnect_1_M00_AXI_AWBURST;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 AWCACHE" *) (* DONT_TOUCH *) wire [3:0]smartconnect_1_M00_AXI_AWCACHE;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 AWLEN" *) (* DONT_TOUCH *) wire [3:0]smartconnect_1_M00_AXI_AWLEN;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 AWLOCK" *) (* DONT_TOUCH *) wire [1:0]smartconnect_1_M00_AXI_AWLOCK;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 AWPROT" *) (* DONT_TOUCH *) wire [2:0]smartconnect_1_M00_AXI_AWPROT;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 AWQOS" *) (* DONT_TOUCH *) wire [3:0]smartconnect_1_M00_AXI_AWQOS;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 AWREADY" *) (* DONT_TOUCH *) wire smartconnect_1_M00_AXI_AWREADY;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 AWSIZE" *) (* DONT_TOUCH *) wire [2:0]smartconnect_1_M00_AXI_AWSIZE;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 AWVALID" *) (* DONT_TOUCH *) wire smartconnect_1_M00_AXI_AWVALID;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 BREADY" *) (* DONT_TOUCH *) wire smartconnect_1_M00_AXI_BREADY;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 BRESP" *) (* DONT_TOUCH *) wire [1:0]smartconnect_1_M00_AXI_BRESP;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 BVALID" *) (* DONT_TOUCH *) wire smartconnect_1_M00_AXI_BVALID;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 RDATA" *) (* DONT_TOUCH *) wire [255:0]smartconnect_1_M00_AXI_RDATA;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 RLAST" *) (* DONT_TOUCH *) wire smartconnect_1_M00_AXI_RLAST;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 RREADY" *) (* DONT_TOUCH *) wire smartconnect_1_M00_AXI_RREADY;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 RRESP" *) (* DONT_TOUCH *) wire [1:0]smartconnect_1_M00_AXI_RRESP;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 RVALID" *) (* DONT_TOUCH *) wire smartconnect_1_M00_AXI_RVALID;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 WDATA" *) (* DONT_TOUCH *) wire [255:0]smartconnect_1_M00_AXI_WDATA;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 WLAST" *) (* DONT_TOUCH *) wire smartconnect_1_M00_AXI_WLAST;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 WREADY" *) (* DONT_TOUCH *) wire smartconnect_1_M00_AXI_WREADY;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 WSTRB" *) (* DONT_TOUCH *) wire [31:0]smartconnect_1_M00_AXI_WSTRB;
  (* CONN_BUS_INFO = "smartconnect_1_M00_AXI xilinx.com:interface:aximm:1.0 AXI3 WVALID" *) (* DONT_TOUCH *) wire smartconnect_1_M00_AXI_WVALID;
  wire sys_clk_1;
  wire sys_clk_gt_0_1;
  wire [63:0]xdma_0_M_AXI_ARADDR;
  wire [1:0]xdma_0_M_AXI_ARBURST;
  wire [3:0]xdma_0_M_AXI_ARCACHE;
  wire [3:0]xdma_0_M_AXI_ARID;
  wire [7:0]xdma_0_M_AXI_ARLEN;
  wire xdma_0_M_AXI_ARLOCK;
  wire [2:0]xdma_0_M_AXI_ARPROT;
  wire xdma_0_M_AXI_ARREADY;
  wire [2:0]xdma_0_M_AXI_ARSIZE;
  wire xdma_0_M_AXI_ARVALID;
  wire [63:0]xdma_0_M_AXI_AWADDR;
  wire [1:0]xdma_0_M_AXI_AWBURST;
  wire [3:0]xdma_0_M_AXI_AWCACHE;
  wire [3:0]xdma_0_M_AXI_AWID;
  wire [7:0]xdma_0_M_AXI_AWLEN;
  wire xdma_0_M_AXI_AWLOCK;
  wire [2:0]xdma_0_M_AXI_AWPROT;
  wire xdma_0_M_AXI_AWREADY;
  wire [2:0]xdma_0_M_AXI_AWSIZE;
  wire xdma_0_M_AXI_AWVALID;
  wire [3:0]xdma_0_M_AXI_BID;
  wire xdma_0_M_AXI_BREADY;
  wire [1:0]xdma_0_M_AXI_BRESP;
  wire xdma_0_M_AXI_BVALID;
  (* CONN_BUS_INFO = "xdma_0_M_AXI_LITE xilinx.com:interface:aximm:1.0 AXI4LITE ARADDR" *) (* DONT_TOUCH *) wire [31:0]xdma_0_M_AXI_LITE_ARADDR;
  (* CONN_BUS_INFO = "xdma_0_M_AXI_LITE xilinx.com:interface:aximm:1.0 AXI4LITE ARPROT" *) (* DONT_TOUCH *) wire [2:0]xdma_0_M_AXI_LITE_ARPROT;
  (* CONN_BUS_INFO = "xdma_0_M_AXI_LITE xilinx.com:interface:aximm:1.0 AXI4LITE ARREADY" *) (* DONT_TOUCH *) wire xdma_0_M_AXI_LITE_ARREADY;
  (* CONN_BUS_INFO = "xdma_0_M_AXI_LITE xilinx.com:interface:aximm:1.0 AXI4LITE ARVALID" *) (* DONT_TOUCH *) wire xdma_0_M_AXI_LITE_ARVALID;
  (* CONN_BUS_INFO = "xdma_0_M_AXI_LITE xilinx.com:interface:aximm:1.0 AXI4LITE AWADDR" *) (* DONT_TOUCH *) wire [31:0]xdma_0_M_AXI_LITE_AWADDR;
  (* CONN_BUS_INFO = "xdma_0_M_AXI_LITE xilinx.com:interface:aximm:1.0 AXI4LITE AWPROT" *) (* DONT_TOUCH *) wire [2:0]xdma_0_M_AXI_LITE_AWPROT;
  (* CONN_BUS_INFO = "xdma_0_M_AXI_LITE xilinx.com:interface:aximm:1.0 AXI4LITE AWREADY" *) (* DONT_TOUCH *) wire xdma_0_M_AXI_LITE_AWREADY;
  (* CONN_BUS_INFO = "xdma_0_M_AXI_LITE xilinx.com:interface:aximm:1.0 AXI4LITE AWVALID" *) (* DONT_TOUCH *) wire xdma_0_M_AXI_LITE_AWVALID;
  (* CONN_BUS_INFO = "xdma_0_M_AXI_LITE xilinx.com:interface:aximm:1.0 AXI4LITE BREADY" *) (* DONT_TOUCH *) wire xdma_0_M_AXI_LITE_BREADY;
  (* CONN_BUS_INFO = "xdma_0_M_AXI_LITE xilinx.com:interface:aximm:1.0 AXI4LITE BRESP" *) (* DONT_TOUCH *) wire [1:0]xdma_0_M_AXI_LITE_BRESP;
  (* CONN_BUS_INFO = "xdma_0_M_AXI_LITE xilinx.com:interface:aximm:1.0 AXI4LITE BVALID" *) (* DONT_TOUCH *) wire xdma_0_M_AXI_LITE_BVALID;
  (* CONN_BUS_INFO = "xdma_0_M_AXI_LITE xilinx.com:interface:aximm:1.0 AXI4LITE RDATA" *) (* DONT_TOUCH *) wire [31:0]xdma_0_M_AXI_LITE_RDATA;
  (* CONN_BUS_INFO = "xdma_0_M_AXI_LITE xilinx.com:interface:aximm:1.0 AXI4LITE RREADY" *) (* DONT_TOUCH *) wire xdma_0_M_AXI_LITE_RREADY;
  (* CONN_BUS_INFO = "xdma_0_M_AXI_LITE xilinx.com:interface:aximm:1.0 AXI4LITE RRESP" *) (* DONT_TOUCH *) wire [1:0]xdma_0_M_AXI_LITE_RRESP;
  (* CONN_BUS_INFO = "xdma_0_M_AXI_LITE xilinx.com:interface:aximm:1.0 AXI4LITE RVALID" *) (* DONT_TOUCH *) wire xdma_0_M_AXI_LITE_RVALID;
  (* CONN_BUS_INFO = "xdma_0_M_AXI_LITE xilinx.com:interface:aximm:1.0 AXI4LITE WDATA" *) (* DONT_TOUCH *) wire [31:0]xdma_0_M_AXI_LITE_WDATA;
  (* CONN_BUS_INFO = "xdma_0_M_AXI_LITE xilinx.com:interface:aximm:1.0 AXI4LITE WREADY" *) (* DONT_TOUCH *) wire xdma_0_M_AXI_LITE_WREADY;
  (* CONN_BUS_INFO = "xdma_0_M_AXI_LITE xilinx.com:interface:aximm:1.0 AXI4LITE WSTRB" *) (* DONT_TOUCH *) wire [3:0]xdma_0_M_AXI_LITE_WSTRB;
  (* CONN_BUS_INFO = "xdma_0_M_AXI_LITE xilinx.com:interface:aximm:1.0 AXI4LITE WVALID" *) (* DONT_TOUCH *) wire xdma_0_M_AXI_LITE_WVALID;
  wire [511:0]xdma_0_M_AXI_RDATA;
  wire [3:0]xdma_0_M_AXI_RID;
  wire xdma_0_M_AXI_RLAST;
  wire xdma_0_M_AXI_RREADY;
  wire [1:0]xdma_0_M_AXI_RRESP;
  wire xdma_0_M_AXI_RVALID;
  wire [511:0]xdma_0_M_AXI_WDATA;
  wire xdma_0_M_AXI_WLAST;
  wire xdma_0_M_AXI_WREADY;
  wire [63:0]xdma_0_M_AXI_WSTRB;
  wire xdma_0_M_AXI_WVALID;
  wire xdma_0_axi_aclk;
  wire xdma_0_axi_aresetn;
  wire [7:0]xdma_0_pcie_mgt_rxn;
  wire [7:0]xdma_0_pcie_mgt_rxp;
  wire [7:0]xdma_0_pcie_mgt_txn;
  wire [7:0]xdma_0_pcie_mgt_txp;
  wire [0:0]xlconstant_0_dout;

  assign HBM_REF_CLK_0_0_1 = HBM_REF_CLK;
  assign pcie_txn[7:0] = xdma_0_pcie_mgt_txn;
  assign pcie_txp[7:0] = xdma_0_pcie_mgt_txp;
  assign reset_rtl_0_1 = prst_n;
  assign sys_clk_1 = sys_clk;
  assign sys_clk_gt_0_1 = sys_clk_gt;
  assign xdma_0_pcie_mgt_rxn = pcie_rxn[7:0];
  assign xdma_0_pcie_mgt_rxp = pcie_rxp[7:0];
  PCIE_HBM_SUB_SYS_axi_bram_ctrl_1_0 axi_bram_ctrl_1
       (.bram_addr_a(axi_bram_ctrl_1_BRAM_PORTA_ADDR),
        .bram_addr_b(axi_bram_ctrl_1_BRAM_PORTB_ADDR),
        .bram_clk_a(axi_bram_ctrl_1_BRAM_PORTA_CLK),
        .bram_clk_b(axi_bram_ctrl_1_BRAM_PORTB_CLK),
        .bram_en_a(axi_bram_ctrl_1_BRAM_PORTA_EN),
        .bram_en_b(axi_bram_ctrl_1_BRAM_PORTB_EN),
        .bram_rddata_a(axi_bram_ctrl_1_BRAM_PORTA_DOUT),
        .bram_rddata_b(axi_bram_ctrl_1_BRAM_PORTB_DOUT),
        .bram_rst_a(axi_bram_ctrl_1_BRAM_PORTA_RST),
        .bram_rst_b(axi_bram_ctrl_1_BRAM_PORTB_RST),
        .bram_we_a(axi_bram_ctrl_1_BRAM_PORTA_WE),
        .bram_we_b(axi_bram_ctrl_1_BRAM_PORTB_WE),
        .bram_wrdata_a(axi_bram_ctrl_1_BRAM_PORTA_DIN),
        .bram_wrdata_b(axi_bram_ctrl_1_BRAM_PORTB_DIN),
        .s_axi_aclk(xdma_0_axi_aclk),
        .s_axi_araddr(smartconnect_0_M00_AXI_ARADDR),
        .s_axi_arburst(smartconnect_0_M00_AXI_ARBURST),
        .s_axi_arcache(smartconnect_0_M00_AXI_ARCACHE),
        .s_axi_aresetn(xdma_0_axi_aresetn),
        .s_axi_arlen(smartconnect_0_M00_AXI_ARLEN),
        .s_axi_arlock(smartconnect_0_M00_AXI_ARLOCK),
        .s_axi_arprot(smartconnect_0_M00_AXI_ARPROT),
        .s_axi_arready(smartconnect_0_M00_AXI_ARREADY),
        .s_axi_arsize(smartconnect_0_M00_AXI_ARSIZE),
        .s_axi_arvalid(smartconnect_0_M00_AXI_ARVALID),
        .s_axi_awaddr(smartconnect_0_M00_AXI_AWADDR),
        .s_axi_awburst(smartconnect_0_M00_AXI_AWBURST),
        .s_axi_awcache(smartconnect_0_M00_AXI_AWCACHE),
        .s_axi_awlen(smartconnect_0_M00_AXI_AWLEN),
        .s_axi_awlock(smartconnect_0_M00_AXI_AWLOCK),
        .s_axi_awprot(smartconnect_0_M00_AXI_AWPROT),
        .s_axi_awready(smartconnect_0_M00_AXI_AWREADY),
        .s_axi_awsize(smartconnect_0_M00_AXI_AWSIZE),
        .s_axi_awvalid(smartconnect_0_M00_AXI_AWVALID),
        .s_axi_bready(smartconnect_0_M00_AXI_BREADY),
        .s_axi_bresp(smartconnect_0_M00_AXI_BRESP),
        .s_axi_bvalid(smartconnect_0_M00_AXI_BVALID),
        .s_axi_rdata(smartconnect_0_M00_AXI_RDATA),
        .s_axi_rlast(smartconnect_0_M00_AXI_RLAST),
        .s_axi_rready(smartconnect_0_M00_AXI_RREADY),
        .s_axi_rresp(smartconnect_0_M00_AXI_RRESP),
        .s_axi_rvalid(smartconnect_0_M00_AXI_RVALID),
        .s_axi_wdata(smartconnect_0_M00_AXI_WDATA),
        .s_axi_wlast(smartconnect_0_M00_AXI_WLAST),
        .s_axi_wready(smartconnect_0_M00_AXI_WREADY),
        .s_axi_wstrb(smartconnect_0_M00_AXI_WSTRB),
        .s_axi_wvalid(smartconnect_0_M00_AXI_WVALID));
  PCIE_HBM_SUB_SYS_axi_bram_ctrl_1_bram_0 axi_bram_ctrl_1_bram
       (.addra({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,axi_bram_ctrl_1_BRAM_PORTA_ADDR}),
        .addrb({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,axi_bram_ctrl_1_BRAM_PORTB_ADDR}),
        .clka(axi_bram_ctrl_1_BRAM_PORTA_CLK),
        .clkb(axi_bram_ctrl_1_BRAM_PORTB_CLK),
        .dina(axi_bram_ctrl_1_BRAM_PORTA_DIN),
        .dinb(axi_bram_ctrl_1_BRAM_PORTB_DIN),
        .douta(axi_bram_ctrl_1_BRAM_PORTA_DOUT),
        .doutb(axi_bram_ctrl_1_BRAM_PORTB_DOUT),
        .ena(axi_bram_ctrl_1_BRAM_PORTA_EN),
        .enb(axi_bram_ctrl_1_BRAM_PORTB_EN),
        .rsta(axi_bram_ctrl_1_BRAM_PORTA_RST),
        .rstb(axi_bram_ctrl_1_BRAM_PORTB_RST),
        .wea(axi_bram_ctrl_1_BRAM_PORTA_WE),
        .web(axi_bram_ctrl_1_BRAM_PORTB_WE));
  PCIE_HBM_SUB_SYS_clk_wiz_0_0 clk_wiz_0
       (.clk_in1(xdma_0_axi_aclk),
        .clk_out100m(clk_wiz_0_clk_out100m));
  PCIE_HBM_SUB_SYS_hbm_0_0 hbm_0
       (.APB_0_PCLK(clk_wiz_0_clk_out100m),
        .APB_0_PRESET_N(proc_sys_reset_0_peripheral_aresetn),
        .APB_1_PCLK(clk_wiz_0_clk_out100m),
        .APB_1_PRESET_N(proc_sys_reset_0_peripheral_aresetn),
        .AXI_00_ACLK(xdma_0_axi_aclk),
        .AXI_00_ARADDR(smartconnect_1_M00_AXI_ARADDR),
        .AXI_00_ARBURST(smartconnect_1_M00_AXI_ARBURST),
        .AXI_00_ARESET_N(xdma_0_axi_aresetn),
        .AXI_00_ARID({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .AXI_00_ARLEN(smartconnect_1_M00_AXI_ARLEN),
        .AXI_00_ARREADY(smartconnect_1_M00_AXI_ARREADY),
        .AXI_00_ARSIZE(smartconnect_1_M00_AXI_ARSIZE),
        .AXI_00_ARVALID(smartconnect_1_M00_AXI_ARVALID),
        .AXI_00_AWADDR(smartconnect_1_M00_AXI_AWADDR),
        .AXI_00_AWBURST(smartconnect_1_M00_AXI_AWBURST),
        .AXI_00_AWID({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .AXI_00_AWLEN(smartconnect_1_M00_AXI_AWLEN),
        .AXI_00_AWREADY(smartconnect_1_M00_AXI_AWREADY),
        .AXI_00_AWSIZE(smartconnect_1_M00_AXI_AWSIZE),
        .AXI_00_AWVALID(smartconnect_1_M00_AXI_AWVALID),
        .AXI_00_BREADY(smartconnect_1_M00_AXI_BREADY),
        .AXI_00_BRESP(smartconnect_1_M00_AXI_BRESP),
        .AXI_00_BVALID(smartconnect_1_M00_AXI_BVALID),
        .AXI_00_RDATA(smartconnect_1_M00_AXI_RDATA),
        .AXI_00_RLAST(smartconnect_1_M00_AXI_RLAST),
        .AXI_00_RREADY(smartconnect_1_M00_AXI_RREADY),
        .AXI_00_RRESP(smartconnect_1_M00_AXI_RRESP),
        .AXI_00_RVALID(smartconnect_1_M00_AXI_RVALID),
        .AXI_00_WDATA(smartconnect_1_M00_AXI_WDATA),
        .AXI_00_WDATA_PARITY({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .AXI_00_WLAST(smartconnect_1_M00_AXI_WLAST),
        .AXI_00_WREADY(smartconnect_1_M00_AXI_WREADY),
        .AXI_00_WSTRB(smartconnect_1_M00_AXI_WSTRB),
        .AXI_00_WVALID(smartconnect_1_M00_AXI_WVALID),
        .HBM_REF_CLK_0(HBM_REF_CLK_0_0_1),
        .HBM_REF_CLK_1(HBM_REF_CLK_0_0_1));
  PCIE_HBM_SUB_SYS_proc_sys_reset_0_0 proc_sys_reset_0
       (.aux_reset_in(1'b1),
        .dcm_locked(1'b1),
        .ext_reset_in(xdma_0_axi_aresetn),
        .mb_debug_sys_rst(1'b0),
        .peripheral_aresetn(proc_sys_reset_0_peripheral_aresetn),
        .slowest_sync_clk(clk_wiz_0_clk_out100m));
  PCIE_HBM_SUB_SYS_smartconnect_0_0 smartconnect_0
       (.M00_AXI_araddr(smartconnect_0_M00_AXI_ARADDR),
        .M00_AXI_arburst(smartconnect_0_M00_AXI_ARBURST),
        .M00_AXI_arcache(smartconnect_0_M00_AXI_ARCACHE),
        .M00_AXI_arlen(smartconnect_0_M00_AXI_ARLEN),
        .M00_AXI_arlock(smartconnect_0_M00_AXI_ARLOCK),
        .M00_AXI_arprot(smartconnect_0_M00_AXI_ARPROT),
        .M00_AXI_arready(smartconnect_0_M00_AXI_ARREADY),
        .M00_AXI_arsize(smartconnect_0_M00_AXI_ARSIZE),
        .M00_AXI_arvalid(smartconnect_0_M00_AXI_ARVALID),
        .M00_AXI_awaddr(smartconnect_0_M00_AXI_AWADDR),
        .M00_AXI_awburst(smartconnect_0_M00_AXI_AWBURST),
        .M00_AXI_awcache(smartconnect_0_M00_AXI_AWCACHE),
        .M00_AXI_awlen(smartconnect_0_M00_AXI_AWLEN),
        .M00_AXI_awlock(smartconnect_0_M00_AXI_AWLOCK),
        .M00_AXI_awprot(smartconnect_0_M00_AXI_AWPROT),
        .M00_AXI_awready(smartconnect_0_M00_AXI_AWREADY),
        .M00_AXI_awsize(smartconnect_0_M00_AXI_AWSIZE),
        .M00_AXI_awvalid(smartconnect_0_M00_AXI_AWVALID),
        .M00_AXI_bready(smartconnect_0_M00_AXI_BREADY),
        .M00_AXI_bresp(smartconnect_0_M00_AXI_BRESP),
        .M00_AXI_bvalid(smartconnect_0_M00_AXI_BVALID),
        .M00_AXI_rdata(smartconnect_0_M00_AXI_RDATA),
        .M00_AXI_rlast(smartconnect_0_M00_AXI_RLAST),
        .M00_AXI_rready(smartconnect_0_M00_AXI_RREADY),
        .M00_AXI_rresp(smartconnect_0_M00_AXI_RRESP),
        .M00_AXI_rvalid(smartconnect_0_M00_AXI_RVALID),
        .M00_AXI_wdata(smartconnect_0_M00_AXI_WDATA),
        .M00_AXI_wlast(smartconnect_0_M00_AXI_WLAST),
        .M00_AXI_wready(smartconnect_0_M00_AXI_WREADY),
        .M00_AXI_wstrb(smartconnect_0_M00_AXI_WSTRB),
        .M00_AXI_wvalid(smartconnect_0_M00_AXI_WVALID),
        .M01_AXI_araddr(smartconnect_0_M01_AXI_ARADDR),
        .M01_AXI_arready(smartconnect_0_M01_AXI_ARREADY),
        .M01_AXI_arvalid(smartconnect_0_M01_AXI_ARVALID),
        .M01_AXI_awaddr(smartconnect_0_M01_AXI_AWADDR),
        .M01_AXI_awready(smartconnect_0_M01_AXI_AWREADY),
        .M01_AXI_awvalid(smartconnect_0_M01_AXI_AWVALID),
        .M01_AXI_bready(smartconnect_0_M01_AXI_BREADY),
        .M01_AXI_bresp(smartconnect_0_M01_AXI_BRESP),
        .M01_AXI_bvalid(smartconnect_0_M01_AXI_BVALID),
        .M01_AXI_rdata(smartconnect_0_M01_AXI_RDATA),
        .M01_AXI_rready(smartconnect_0_M01_AXI_RREADY),
        .M01_AXI_rresp(smartconnect_0_M01_AXI_RRESP),
        .M01_AXI_rvalid(smartconnect_0_M01_AXI_RVALID),
        .M01_AXI_wdata(smartconnect_0_M01_AXI_WDATA),
        .M01_AXI_wready(smartconnect_0_M01_AXI_WREADY),
        .M01_AXI_wstrb(smartconnect_0_M01_AXI_WSTRB),
        .M01_AXI_wvalid(smartconnect_0_M01_AXI_WVALID),
        .S00_AXI_araddr(xdma_0_M_AXI_LITE_ARADDR),
        .S00_AXI_arprot(xdma_0_M_AXI_LITE_ARPROT),
        .S00_AXI_arready(xdma_0_M_AXI_LITE_ARREADY),
        .S00_AXI_arvalid(xdma_0_M_AXI_LITE_ARVALID),
        .S00_AXI_awaddr(xdma_0_M_AXI_LITE_AWADDR),
        .S00_AXI_awprot(xdma_0_M_AXI_LITE_AWPROT),
        .S00_AXI_awready(xdma_0_M_AXI_LITE_AWREADY),
        .S00_AXI_awvalid(xdma_0_M_AXI_LITE_AWVALID),
        .S00_AXI_bready(xdma_0_M_AXI_LITE_BREADY),
        .S00_AXI_bresp(xdma_0_M_AXI_LITE_BRESP),
        .S00_AXI_bvalid(xdma_0_M_AXI_LITE_BVALID),
        .S00_AXI_rdata(xdma_0_M_AXI_LITE_RDATA),
        .S00_AXI_rready(xdma_0_M_AXI_LITE_RREADY),
        .S00_AXI_rresp(xdma_0_M_AXI_LITE_RRESP),
        .S00_AXI_rvalid(xdma_0_M_AXI_LITE_RVALID),
        .S00_AXI_wdata(xdma_0_M_AXI_LITE_WDATA),
        .S00_AXI_wready(xdma_0_M_AXI_LITE_WREADY),
        .S00_AXI_wstrb(xdma_0_M_AXI_LITE_WSTRB),
        .S00_AXI_wvalid(xdma_0_M_AXI_LITE_WVALID),
        .aclk(xdma_0_axi_aclk),
        .aclk1(xdma_0_axi_aclk),
        .aresetn(xdma_0_axi_aresetn));
  PCIE_HBM_SUB_SYS_smartconnect_1_0 smartconnect_1
       (.M00_AXI_araddr(smartconnect_1_M00_AXI_ARADDR),
        .M00_AXI_arburst(smartconnect_1_M00_AXI_ARBURST),
        .M00_AXI_arcache(smartconnect_1_M00_AXI_ARCACHE),
        .M00_AXI_arlen(smartconnect_1_M00_AXI_ARLEN),
        .M00_AXI_arlock(smartconnect_1_M00_AXI_ARLOCK),
        .M00_AXI_arprot(smartconnect_1_M00_AXI_ARPROT),
        .M00_AXI_arqos(smartconnect_1_M00_AXI_ARQOS),
        .M00_AXI_arready(smartconnect_1_M00_AXI_ARREADY),
        .M00_AXI_arsize(smartconnect_1_M00_AXI_ARSIZE),
        .M00_AXI_arvalid(smartconnect_1_M00_AXI_ARVALID),
        .M00_AXI_awaddr(smartconnect_1_M00_AXI_AWADDR),
        .M00_AXI_awburst(smartconnect_1_M00_AXI_AWBURST),
        .M00_AXI_awcache(smartconnect_1_M00_AXI_AWCACHE),
        .M00_AXI_awlen(smartconnect_1_M00_AXI_AWLEN),
        .M00_AXI_awlock(smartconnect_1_M00_AXI_AWLOCK),
        .M00_AXI_awprot(smartconnect_1_M00_AXI_AWPROT),
        .M00_AXI_awqos(smartconnect_1_M00_AXI_AWQOS),
        .M00_AXI_awready(smartconnect_1_M00_AXI_AWREADY),
        .M00_AXI_awsize(smartconnect_1_M00_AXI_AWSIZE),
        .M00_AXI_awvalid(smartconnect_1_M00_AXI_AWVALID),
        .M00_AXI_bready(smartconnect_1_M00_AXI_BREADY),
        .M00_AXI_bresp(smartconnect_1_M00_AXI_BRESP),
        .M00_AXI_bvalid(smartconnect_1_M00_AXI_BVALID),
        .M00_AXI_rdata(smartconnect_1_M00_AXI_RDATA),
        .M00_AXI_rlast(smartconnect_1_M00_AXI_RLAST),
        .M00_AXI_rready(smartconnect_1_M00_AXI_RREADY),
        .M00_AXI_rresp(smartconnect_1_M00_AXI_RRESP),
        .M00_AXI_rvalid(smartconnect_1_M00_AXI_RVALID),
        .M00_AXI_wdata(smartconnect_1_M00_AXI_WDATA),
        .M00_AXI_wlast(smartconnect_1_M00_AXI_WLAST),
        .M00_AXI_wready(smartconnect_1_M00_AXI_WREADY),
        .M00_AXI_wstrb(smartconnect_1_M00_AXI_WSTRB),
        .M00_AXI_wvalid(smartconnect_1_M00_AXI_WVALID),
        .S00_AXI_araddr(xdma_0_M_AXI_ARADDR),
        .S00_AXI_arburst(xdma_0_M_AXI_ARBURST),
        .S00_AXI_arcache(xdma_0_M_AXI_ARCACHE),
        .S00_AXI_arid(xdma_0_M_AXI_ARID),
        .S00_AXI_arlen(xdma_0_M_AXI_ARLEN),
        .S00_AXI_arlock(xdma_0_M_AXI_ARLOCK),
        .S00_AXI_arprot(xdma_0_M_AXI_ARPROT),
        .S00_AXI_arqos({1'b0,1'b0,1'b0,1'b0}),
        .S00_AXI_arready(xdma_0_M_AXI_ARREADY),
        .S00_AXI_arsize(xdma_0_M_AXI_ARSIZE),
        .S00_AXI_arvalid(xdma_0_M_AXI_ARVALID),
        .S00_AXI_awaddr(xdma_0_M_AXI_AWADDR),
        .S00_AXI_awburst(xdma_0_M_AXI_AWBURST),
        .S00_AXI_awcache(xdma_0_M_AXI_AWCACHE),
        .S00_AXI_awid(xdma_0_M_AXI_AWID),
        .S00_AXI_awlen(xdma_0_M_AXI_AWLEN),
        .S00_AXI_awlock(xdma_0_M_AXI_AWLOCK),
        .S00_AXI_awprot(xdma_0_M_AXI_AWPROT),
        .S00_AXI_awqos({1'b0,1'b0,1'b0,1'b0}),
        .S00_AXI_awready(xdma_0_M_AXI_AWREADY),
        .S00_AXI_awsize(xdma_0_M_AXI_AWSIZE),
        .S00_AXI_awvalid(xdma_0_M_AXI_AWVALID),
        .S00_AXI_bid(xdma_0_M_AXI_BID),
        .S00_AXI_bready(xdma_0_M_AXI_BREADY),
        .S00_AXI_bresp(xdma_0_M_AXI_BRESP),
        .S00_AXI_bvalid(xdma_0_M_AXI_BVALID),
        .S00_AXI_rdata(xdma_0_M_AXI_RDATA),
        .S00_AXI_rid(xdma_0_M_AXI_RID),
        .S00_AXI_rlast(xdma_0_M_AXI_RLAST),
        .S00_AXI_rready(xdma_0_M_AXI_RREADY),
        .S00_AXI_rresp(xdma_0_M_AXI_RRESP),
        .S00_AXI_rvalid(xdma_0_M_AXI_RVALID),
        .S00_AXI_wdata(xdma_0_M_AXI_WDATA),
        .S00_AXI_wlast(xdma_0_M_AXI_WLAST),
        .S00_AXI_wready(xdma_0_M_AXI_WREADY),
        .S00_AXI_wstrb(xdma_0_M_AXI_WSTRB),
        .S00_AXI_wvalid(xdma_0_M_AXI_WVALID),
        .aclk(xdma_0_axi_aclk),
        .aresetn(xdma_0_axi_aresetn));
  PCIE_HBM_SUB_SYS_system_ila_0_0 system_ila_AXILITE
       (.SLOT_0_AXI_araddr(xdma_0_M_AXI_LITE_ARADDR),
        .SLOT_0_AXI_arprot(xdma_0_M_AXI_LITE_ARPROT),
        .SLOT_0_AXI_arready(xdma_0_M_AXI_LITE_ARREADY),
        .SLOT_0_AXI_arvalid(xdma_0_M_AXI_LITE_ARVALID),
        .SLOT_0_AXI_awaddr(xdma_0_M_AXI_LITE_AWADDR),
        .SLOT_0_AXI_awprot(xdma_0_M_AXI_LITE_AWPROT),
        .SLOT_0_AXI_awready(xdma_0_M_AXI_LITE_AWREADY),
        .SLOT_0_AXI_awvalid(xdma_0_M_AXI_LITE_AWVALID),
        .SLOT_0_AXI_bready(xdma_0_M_AXI_LITE_BREADY),
        .SLOT_0_AXI_bresp(xdma_0_M_AXI_LITE_BRESP),
        .SLOT_0_AXI_bvalid(xdma_0_M_AXI_LITE_BVALID),
        .SLOT_0_AXI_rdata(xdma_0_M_AXI_LITE_RDATA),
        .SLOT_0_AXI_rready(xdma_0_M_AXI_LITE_RREADY),
        .SLOT_0_AXI_rresp(xdma_0_M_AXI_LITE_RRESP),
        .SLOT_0_AXI_rvalid(xdma_0_M_AXI_LITE_RVALID),
        .SLOT_0_AXI_wdata(xdma_0_M_AXI_LITE_WDATA),
        .SLOT_0_AXI_wready(xdma_0_M_AXI_LITE_WREADY),
        .SLOT_0_AXI_wstrb(xdma_0_M_AXI_LITE_WSTRB),
        .SLOT_0_AXI_wvalid(xdma_0_M_AXI_LITE_WVALID),
        .clk(xdma_0_axi_aclk),
        .resetn(xdma_0_axi_aresetn));
  PCIE_HBM_SUB_SYS_system_ila_AXILITE_0 system_ila_AXIMM
       (.SLOT_0_AXI_araddr(smartconnect_1_M00_AXI_ARADDR),
        .SLOT_0_AXI_arburst(smartconnect_1_M00_AXI_ARBURST),
        .SLOT_0_AXI_arcache(smartconnect_1_M00_AXI_ARCACHE),
        .SLOT_0_AXI_arlen(smartconnect_1_M00_AXI_ARLEN),
        .SLOT_0_AXI_arlock(smartconnect_1_M00_AXI_ARLOCK),
        .SLOT_0_AXI_arprot(smartconnect_1_M00_AXI_ARPROT),
        .SLOT_0_AXI_arqos(smartconnect_1_M00_AXI_ARQOS),
        .SLOT_0_AXI_arready(smartconnect_1_M00_AXI_ARREADY),
        .SLOT_0_AXI_arsize(smartconnect_1_M00_AXI_ARSIZE),
        .SLOT_0_AXI_arvalid(smartconnect_1_M00_AXI_ARVALID),
        .SLOT_0_AXI_awaddr(smartconnect_1_M00_AXI_AWADDR),
        .SLOT_0_AXI_awburst(smartconnect_1_M00_AXI_AWBURST),
        .SLOT_0_AXI_awcache(smartconnect_1_M00_AXI_AWCACHE),
        .SLOT_0_AXI_awlen(smartconnect_1_M00_AXI_AWLEN),
        .SLOT_0_AXI_awlock(smartconnect_1_M00_AXI_AWLOCK),
        .SLOT_0_AXI_awprot(smartconnect_1_M00_AXI_AWPROT),
        .SLOT_0_AXI_awqos(smartconnect_1_M00_AXI_AWQOS),
        .SLOT_0_AXI_awready(smartconnect_1_M00_AXI_AWREADY),
        .SLOT_0_AXI_awsize(smartconnect_1_M00_AXI_AWSIZE),
        .SLOT_0_AXI_awvalid(smartconnect_1_M00_AXI_AWVALID),
        .SLOT_0_AXI_bready(smartconnect_1_M00_AXI_BREADY),
        .SLOT_0_AXI_bresp(smartconnect_1_M00_AXI_BRESP),
        .SLOT_0_AXI_bvalid(smartconnect_1_M00_AXI_BVALID),
        .SLOT_0_AXI_rdata(smartconnect_1_M00_AXI_RDATA),
        .SLOT_0_AXI_rlast(smartconnect_1_M00_AXI_RLAST),
        .SLOT_0_AXI_rready(smartconnect_1_M00_AXI_RREADY),
        .SLOT_0_AXI_rresp(smartconnect_1_M00_AXI_RRESP),
        .SLOT_0_AXI_rvalid(smartconnect_1_M00_AXI_RVALID),
        .SLOT_0_AXI_wdata(smartconnect_1_M00_AXI_WDATA),
        .SLOT_0_AXI_wlast(smartconnect_1_M00_AXI_WLAST),
        .SLOT_0_AXI_wready(smartconnect_1_M00_AXI_WREADY),
        .SLOT_0_AXI_wstrb(smartconnect_1_M00_AXI_WSTRB),
        .SLOT_0_AXI_wvalid(smartconnect_1_M00_AXI_WVALID),
        .clk(xdma_0_axi_aclk),
        .resetn(xdma_0_axi_aresetn));
  PCIE_HBM_SUB_SYS_system_management_wiz_0_0 system_management_wiz_0
       (.s_axi_aclk(xdma_0_axi_aclk),
        .s_axi_araddr(smartconnect_0_M01_AXI_ARADDR),
        .s_axi_aresetn(xdma_0_axi_aresetn),
        .s_axi_arready(smartconnect_0_M01_AXI_ARREADY),
        .s_axi_arvalid(smartconnect_0_M01_AXI_ARVALID),
        .s_axi_awaddr(smartconnect_0_M01_AXI_AWADDR),
        .s_axi_awready(smartconnect_0_M01_AXI_AWREADY),
        .s_axi_awvalid(smartconnect_0_M01_AXI_AWVALID),
        .s_axi_bready(smartconnect_0_M01_AXI_BREADY),
        .s_axi_bresp(smartconnect_0_M01_AXI_BRESP),
        .s_axi_bvalid(smartconnect_0_M01_AXI_BVALID),
        .s_axi_rdata(smartconnect_0_M01_AXI_RDATA),
        .s_axi_rready(smartconnect_0_M01_AXI_RREADY),
        .s_axi_rresp(smartconnect_0_M01_AXI_RRESP),
        .s_axi_rvalid(smartconnect_0_M01_AXI_RVALID),
        .s_axi_wdata(smartconnect_0_M01_AXI_WDATA),
        .s_axi_wready(smartconnect_0_M01_AXI_WREADY),
        .s_axi_wstrb(smartconnect_0_M01_AXI_WSTRB),
        .s_axi_wvalid(smartconnect_0_M01_AXI_WVALID),
        .vn(1'b0),
        .vp(1'b0));
  PCIE_HBM_SUB_SYS_xdma_0_0 xdma_0
       (.axi_aclk(xdma_0_axi_aclk),
        .axi_aresetn(xdma_0_axi_aresetn),
        .m_axi_araddr(xdma_0_M_AXI_ARADDR),
        .m_axi_arburst(xdma_0_M_AXI_ARBURST),
        .m_axi_arcache(xdma_0_M_AXI_ARCACHE),
        .m_axi_arid(xdma_0_M_AXI_ARID),
        .m_axi_arlen(xdma_0_M_AXI_ARLEN),
        .m_axi_arlock(xdma_0_M_AXI_ARLOCK),
        .m_axi_arprot(xdma_0_M_AXI_ARPROT),
        .m_axi_arready(xdma_0_M_AXI_ARREADY),
        .m_axi_arsize(xdma_0_M_AXI_ARSIZE),
        .m_axi_arvalid(xdma_0_M_AXI_ARVALID),
        .m_axi_awaddr(xdma_0_M_AXI_AWADDR),
        .m_axi_awburst(xdma_0_M_AXI_AWBURST),
        .m_axi_awcache(xdma_0_M_AXI_AWCACHE),
        .m_axi_awid(xdma_0_M_AXI_AWID),
        .m_axi_awlen(xdma_0_M_AXI_AWLEN),
        .m_axi_awlock(xdma_0_M_AXI_AWLOCK),
        .m_axi_awprot(xdma_0_M_AXI_AWPROT),
        .m_axi_awready(xdma_0_M_AXI_AWREADY),
        .m_axi_awsize(xdma_0_M_AXI_AWSIZE),
        .m_axi_awvalid(xdma_0_M_AXI_AWVALID),
        .m_axi_bid(xdma_0_M_AXI_BID),
        .m_axi_bready(xdma_0_M_AXI_BREADY),
        .m_axi_bresp(xdma_0_M_AXI_BRESP),
        .m_axi_bvalid(xdma_0_M_AXI_BVALID),
        .m_axi_rdata(xdma_0_M_AXI_RDATA),
        .m_axi_rid(xdma_0_M_AXI_RID),
        .m_axi_rlast(xdma_0_M_AXI_RLAST),
        .m_axi_rready(xdma_0_M_AXI_RREADY),
        .m_axi_rresp(xdma_0_M_AXI_RRESP),
        .m_axi_rvalid(xdma_0_M_AXI_RVALID),
        .m_axi_wdata(xdma_0_M_AXI_WDATA),
        .m_axi_wlast(xdma_0_M_AXI_WLAST),
        .m_axi_wready(xdma_0_M_AXI_WREADY),
        .m_axi_wstrb(xdma_0_M_AXI_WSTRB),
        .m_axi_wvalid(xdma_0_M_AXI_WVALID),
        .m_axil_araddr(xdma_0_M_AXI_LITE_ARADDR),
        .m_axil_arprot(xdma_0_M_AXI_LITE_ARPROT),
        .m_axil_arready(xdma_0_M_AXI_LITE_ARREADY),
        .m_axil_arvalid(xdma_0_M_AXI_LITE_ARVALID),
        .m_axil_awaddr(xdma_0_M_AXI_LITE_AWADDR),
        .m_axil_awprot(xdma_0_M_AXI_LITE_AWPROT),
        .m_axil_awready(xdma_0_M_AXI_LITE_AWREADY),
        .m_axil_awvalid(xdma_0_M_AXI_LITE_AWVALID),
        .m_axil_bready(xdma_0_M_AXI_LITE_BREADY),
        .m_axil_bresp(xdma_0_M_AXI_LITE_BRESP),
        .m_axil_bvalid(xdma_0_M_AXI_LITE_BVALID),
        .m_axil_rdata(xdma_0_M_AXI_LITE_RDATA),
        .m_axil_rready(xdma_0_M_AXI_LITE_RREADY),
        .m_axil_rresp(xdma_0_M_AXI_LITE_RRESP),
        .m_axil_rvalid(xdma_0_M_AXI_LITE_RVALID),
        .m_axil_wdata(xdma_0_M_AXI_LITE_WDATA),
        .m_axil_wready(xdma_0_M_AXI_LITE_WREADY),
        .m_axil_wstrb(xdma_0_M_AXI_LITE_WSTRB),
        .m_axil_wvalid(xdma_0_M_AXI_LITE_WVALID),
        .pci_exp_rxn(xdma_0_pcie_mgt_rxn),
        .pci_exp_rxp(xdma_0_pcie_mgt_rxp),
        .pci_exp_txn(xdma_0_pcie_mgt_txn),
        .pci_exp_txp(xdma_0_pcie_mgt_txp),
        .sys_clk(sys_clk_1),
        .sys_clk_gt(sys_clk_gt_0_1),
        .sys_rst_n(reset_rtl_0_1),
        .usr_irq_req(xlconstant_0_dout));
  PCIE_HBM_SUB_SYS_xlconstant_0_0 xlconstant_0
       (.dout(xlconstant_0_dout));
endmodule
