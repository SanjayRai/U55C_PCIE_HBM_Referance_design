//Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2021.2 (lin64) Build 3367213 Tue Oct 19 02:47:39 MDT 2021
//Date        : Fri Apr  1 07:06:33 2022
//Host        : xsjgd1 running 64-bit Red Hat Enterprise Linux Workstation release 7.5 (Maipo)
//Command     : generate_target PCIE_HBM_SUB_SYS_wrapper.bd
//Design      : PCIE_HBM_SUB_SYS_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module PCIE_HBM_SUB_SYS_wrapper
   (HBM_REF_CLK,
    pcie_rxn,
    pcie_rxp,
    pcie_txn,
    pcie_txp,
    prst_n,
    sys_clk,
    sys_clk_gt);
  input HBM_REF_CLK;
  input [7:0]pcie_rxn;
  input [7:0]pcie_rxp;
  output [7:0]pcie_txn;
  output [7:0]pcie_txp;
  input prst_n;
  input sys_clk;
  input sys_clk_gt;

  wire HBM_REF_CLK;
  wire [7:0]pcie_rxn;
  wire [7:0]pcie_rxp;
  wire [7:0]pcie_txn;
  wire [7:0]pcie_txp;
  wire prst_n;
  wire sys_clk;
  wire sys_clk_gt;

  PCIE_HBM_SUB_SYS PCIE_HBM_SUB_SYS_i
       (.HBM_REF_CLK(HBM_REF_CLK),
        .pcie_rxn(pcie_rxn),
        .pcie_rxp(pcie_rxp),
        .pcie_txn(pcie_txn),
        .pcie_txp(pcie_txp),
        .prst_n(prst_n),
        .sys_clk(sys_clk),
        .sys_clk_gt(sys_clk_gt));
endmodule
