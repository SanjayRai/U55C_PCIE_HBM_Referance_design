`timescale 1 ps / 1 ps

module u55c_top (
  input [7:0]pcie_rxn,
  input [7:0]pcie_rxp,
  output [7:0]pcie_txn,
  output [7:0]pcie_txp,
  input prst_n,
  input sys_clk_p,
  input sys_clk_n,
  input HBM_ref_clk_p,
  input HBM_ref_clk_n);

  wire sys_rst_n_c;
  wire sys_clk;
  wire sys_clk_gt;
  wire HBM_REF_CLK_ibuf;
  wire HBM_REF_CLK;


  IBUF   sys_reset_n_ibuf (.O(sys_rst_n_c), .I(prst_n));
  IBUFDS_GTE4 refclk_ibuf (.O(sys_clk_gt), .ODIV2(sys_clk), .I(sys_clk_p), .CEB(1'b0), .IB(sys_clk_n));
  IBUFDS hbm_ref_clk (.O(HBM_REF_CLK_ibuf), .I(HBM_ref_clk_p), .IB(HBM_ref_clk_n));
  BUFG hbm_ref_clk_bufg (.I(HBM_REF_CLK_ibuf), .O(HBM_REF_CLK));



  PCIE_HBM_SUB_SYS PCIE_HBM_SUB_SYS_i(
        .HBM_REF_CLK(HBM_REF_CLK),
        .pcie_rxn(pcie_rxn),
        .pcie_rxp(pcie_rxp),
        .pcie_txn(pcie_txn),
        .pcie_txp(pcie_txp),
        .prst_n(sys_rst_n_c),
        .sys_clk(sys_clk),
        .sys_clk_gt(sys_clk_gt));

endmodule
