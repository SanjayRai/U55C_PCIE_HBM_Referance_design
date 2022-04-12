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


//------------------------------------------------------------------------------------
// Filename:    PCIE_HBM_SUB_SYS_hbm_0_0_stub.sv
// Description: This HDL file is intended to be used with following simulators only:
//
//   Vivado Simulator (XSim)
//   Cadence Xcelium Simulator
//   Aldec Riviera-PRO Simulator
//
//------------------------------------------------------------------------------------
`timescale 1ps/1ps

`ifdef XILINX_SIMULATOR

`ifndef XILINX_SIMULATOR_BITASBOOL
`define XILINX_SIMULATOR_BITASBOOL
typedef bit bit_as_bool;
`endif

(* SC_MODULE_EXPORT *)
module PCIE_HBM_SUB_SYS_hbm_0_0 (
  input bit_as_bool HBM_REF_CLK_0,
  input bit_as_bool HBM_REF_CLK_1,
  input bit_as_bool AXI_00_ACLK,
  input bit_as_bool AXI_00_ARESET_N,
  input bit [33 : 0] AXI_00_ARADDR,
  input bit [1 : 0] AXI_00_ARBURST,
  input bit [5 : 0] AXI_00_ARID,
  input bit [3 : 0] AXI_00_ARLEN,
  input bit [2 : 0] AXI_00_ARSIZE,
  input bit_as_bool AXI_00_ARVALID,
  input bit [33 : 0] AXI_00_AWADDR,
  input bit [1 : 0] AXI_00_AWBURST,
  input bit [5 : 0] AXI_00_AWID,
  input bit [3 : 0] AXI_00_AWLEN,
  input bit [2 : 0] AXI_00_AWSIZE,
  input bit_as_bool AXI_00_AWVALID,
  input bit_as_bool AXI_00_RREADY,
  input bit_as_bool AXI_00_BREADY,
  input bit [255 : 0] AXI_00_WDATA,
  input bit_as_bool AXI_00_WLAST,
  input bit [31 : 0] AXI_00_WSTRB,
  input bit [31 : 0] AXI_00_WDATA_PARITY,
  input bit_as_bool AXI_00_WVALID,
  input bit_as_bool APB_0_PCLK,
  input bit_as_bool APB_0_PRESET_N,
  input bit_as_bool APB_1_PCLK,
  input bit_as_bool APB_1_PRESET_N,
  output bit_as_bool AXI_00_ARREADY,
  output bit_as_bool AXI_00_AWREADY,
  output bit [31 : 0] AXI_00_RDATA_PARITY,
  output bit [255 : 0] AXI_00_RDATA,
  output bit [5 : 0] AXI_00_RID,
  output bit_as_bool AXI_00_RLAST,
  output bit [1 : 0] AXI_00_RRESP,
  output bit_as_bool AXI_00_RVALID,
  output bit_as_bool AXI_00_WREADY,
  output bit [5 : 0] AXI_00_BID,
  output bit [1 : 0] AXI_00_BRESP,
  output bit_as_bool AXI_00_BVALID,
  output bit_as_bool apb_complete_0,
  output bit_as_bool apb_complete_1,
  output bit_as_bool DRAM_0_STAT_CATTRIP,
  output bit [6 : 0] DRAM_0_STAT_TEMP,
  output bit_as_bool DRAM_1_STAT_CATTRIP,
  output bit [6 : 0] DRAM_1_STAT_TEMP
);
endmodule
`endif

`ifdef XCELIUM
(* XMSC_MODULE_EXPORT *)
module PCIE_HBM_SUB_SYS_hbm_0_0 (HBM_REF_CLK_0,HBM_REF_CLK_1,AXI_00_ACLK,AXI_00_ARESET_N,AXI_00_ARADDR,AXI_00_ARBURST,AXI_00_ARID,AXI_00_ARLEN,AXI_00_ARSIZE,AXI_00_ARVALID,AXI_00_AWADDR,AXI_00_AWBURST,AXI_00_AWID,AXI_00_AWLEN,AXI_00_AWSIZE,AXI_00_AWVALID,AXI_00_RREADY,AXI_00_BREADY,AXI_00_WDATA,AXI_00_WLAST,AXI_00_WSTRB,AXI_00_WDATA_PARITY,AXI_00_WVALID,APB_0_PCLK,APB_0_PRESET_N,APB_1_PCLK,APB_1_PRESET_N,AXI_00_ARREADY,AXI_00_AWREADY,AXI_00_RDATA_PARITY,AXI_00_RDATA,AXI_00_RID,AXI_00_RLAST,AXI_00_RRESP,AXI_00_RVALID,AXI_00_WREADY,AXI_00_BID,AXI_00_BRESP,AXI_00_BVALID,apb_complete_0,apb_complete_1,DRAM_0_STAT_CATTRIP,DRAM_0_STAT_TEMP,DRAM_1_STAT_CATTRIP,DRAM_1_STAT_TEMP)
(* integer foreign = "SystemC";
*);
  input bit HBM_REF_CLK_0;
  input bit HBM_REF_CLK_1;
  input bit AXI_00_ACLK;
  input bit AXI_00_ARESET_N;
  input bit [33 : 0] AXI_00_ARADDR;
  input bit [1 : 0] AXI_00_ARBURST;
  input bit [5 : 0] AXI_00_ARID;
  input bit [3 : 0] AXI_00_ARLEN;
  input bit [2 : 0] AXI_00_ARSIZE;
  input bit AXI_00_ARVALID;
  input bit [33 : 0] AXI_00_AWADDR;
  input bit [1 : 0] AXI_00_AWBURST;
  input bit [5 : 0] AXI_00_AWID;
  input bit [3 : 0] AXI_00_AWLEN;
  input bit [2 : 0] AXI_00_AWSIZE;
  input bit AXI_00_AWVALID;
  input bit AXI_00_RREADY;
  input bit AXI_00_BREADY;
  input bit [255 : 0] AXI_00_WDATA;
  input bit AXI_00_WLAST;
  input bit [31 : 0] AXI_00_WSTRB;
  input bit [31 : 0] AXI_00_WDATA_PARITY;
  input bit AXI_00_WVALID;
  input bit APB_0_PCLK;
  input bit APB_0_PRESET_N;
  input bit APB_1_PCLK;
  input bit APB_1_PRESET_N;
  output wire AXI_00_ARREADY;
  output wire AXI_00_AWREADY;
  output wire [31 : 0] AXI_00_RDATA_PARITY;
  output wire [255 : 0] AXI_00_RDATA;
  output wire [5 : 0] AXI_00_RID;
  output wire AXI_00_RLAST;
  output wire [1 : 0] AXI_00_RRESP;
  output wire AXI_00_RVALID;
  output wire AXI_00_WREADY;
  output wire [5 : 0] AXI_00_BID;
  output wire [1 : 0] AXI_00_BRESP;
  output wire AXI_00_BVALID;
  output wire apb_complete_0;
  output wire apb_complete_1;
  output wire DRAM_0_STAT_CATTRIP;
  output wire [6 : 0] DRAM_0_STAT_TEMP;
  output wire DRAM_1_STAT_CATTRIP;
  output wire [6 : 0] DRAM_1_STAT_TEMP;
endmodule
`endif

`ifdef RIVIERA
(* SC_MODULE_EXPORT *)
module PCIE_HBM_SUB_SYS_hbm_0_0 (HBM_REF_CLK_0,HBM_REF_CLK_1,AXI_00_ACLK,AXI_00_ARESET_N,AXI_00_ARADDR,AXI_00_ARBURST,AXI_00_ARID,AXI_00_ARLEN,AXI_00_ARSIZE,AXI_00_ARVALID,AXI_00_AWADDR,AXI_00_AWBURST,AXI_00_AWID,AXI_00_AWLEN,AXI_00_AWSIZE,AXI_00_AWVALID,AXI_00_RREADY,AXI_00_BREADY,AXI_00_WDATA,AXI_00_WLAST,AXI_00_WSTRB,AXI_00_WDATA_PARITY,AXI_00_WVALID,APB_0_PCLK,APB_0_PRESET_N,APB_1_PCLK,APB_1_PRESET_N,AXI_00_ARREADY,AXI_00_AWREADY,AXI_00_RDATA_PARITY,AXI_00_RDATA,AXI_00_RID,AXI_00_RLAST,AXI_00_RRESP,AXI_00_RVALID,AXI_00_WREADY,AXI_00_BID,AXI_00_BRESP,AXI_00_BVALID,apb_complete_0,apb_complete_1,DRAM_0_STAT_CATTRIP,DRAM_0_STAT_TEMP,DRAM_1_STAT_CATTRIP,DRAM_1_STAT_TEMP)
  input bit HBM_REF_CLK_0;
  input bit HBM_REF_CLK_1;
  input bit AXI_00_ACLK;
  input bit AXI_00_ARESET_N;
  input bit [33 : 0] AXI_00_ARADDR;
  input bit [1 : 0] AXI_00_ARBURST;
  input bit [5 : 0] AXI_00_ARID;
  input bit [3 : 0] AXI_00_ARLEN;
  input bit [2 : 0] AXI_00_ARSIZE;
  input bit AXI_00_ARVALID;
  input bit [33 : 0] AXI_00_AWADDR;
  input bit [1 : 0] AXI_00_AWBURST;
  input bit [5 : 0] AXI_00_AWID;
  input bit [3 : 0] AXI_00_AWLEN;
  input bit [2 : 0] AXI_00_AWSIZE;
  input bit AXI_00_AWVALID;
  input bit AXI_00_RREADY;
  input bit AXI_00_BREADY;
  input bit [255 : 0] AXI_00_WDATA;
  input bit AXI_00_WLAST;
  input bit [31 : 0] AXI_00_WSTRB;
  input bit [31 : 0] AXI_00_WDATA_PARITY;
  input bit AXI_00_WVALID;
  input bit APB_0_PCLK;
  input bit APB_0_PRESET_N;
  input bit APB_1_PCLK;
  input bit APB_1_PRESET_N;
  output wire AXI_00_ARREADY;
  output wire AXI_00_AWREADY;
  output wire [31 : 0] AXI_00_RDATA_PARITY;
  output wire [255 : 0] AXI_00_RDATA;
  output wire [5 : 0] AXI_00_RID;
  output wire AXI_00_RLAST;
  output wire [1 : 0] AXI_00_RRESP;
  output wire AXI_00_RVALID;
  output wire AXI_00_WREADY;
  output wire [5 : 0] AXI_00_BID;
  output wire [1 : 0] AXI_00_BRESP;
  output wire AXI_00_BVALID;
  output wire apb_complete_0;
  output wire apb_complete_1;
  output wire DRAM_0_STAT_CATTRIP;
  output wire [6 : 0] DRAM_0_STAT_TEMP;
  output wire DRAM_1_STAT_CATTRIP;
  output wire [6 : 0] DRAM_1_STAT_TEMP;
endmodule
`endif
