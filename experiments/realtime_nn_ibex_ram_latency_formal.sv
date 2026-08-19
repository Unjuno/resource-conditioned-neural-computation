/*
 * Formal wrapper for the pinned Ibex ram_2p data-port response timing.
 * The workflow compiles this together with the exact upstream ram_2p.sv.
 * prim_ram_2p is stubbed only for DATA values; response-valid timing remains
 * the actual ram_2p control RTL under proof.
 */

module prim_ram_2p #(
  parameter integer Width = 32,
  parameter integer Depth = 128,
  parameter integer DataBitsPerMask = 8,
  parameter MemInitFile = ""
) (
  input  wire clk_a_i,
  input  wire clk_b_i,
  input  wire a_req_i,
  input  wire a_write_i,
  input  wire [$clog2(Depth)-1:0] a_addr_i,
  input  wire [Width-1:0] a_wdata_i,
  input  wire [Width-1:0] a_wmask_i,
  output wire [Width-1:0] a_rdata_o,
  input  wire b_req_i,
  input  wire b_write_i,
  input  wire [$clog2(Depth)-1:0] b_addr_i,
  input  wire [Width-1:0] b_wdata_i,
  input  wire [Width-1:0] b_wmask_i,
  output wire [Width-1:0] b_rdata_o,
  input  wire cfg_i,
  output wire cfg_o
);
  assign a_rdata_o = {Width{1'b0}};
  assign b_rdata_o = {Width{1'b0}};
  assign cfg_o = 1'b0;
endmodule

module rtnn_ram_latency_formal(input wire clk);
  (* anyseq *) reg a_req;
  (* anyseq *) reg [31:0] a_addr0;
  (* anyseq *) reg [31:0] a_addr1;
  reg rst_n = 1'b0;
  reg past_valid = 1'b0;

  wire a_rvalid0, a_rvalid1;
  wire [31:0] a_rdata0, a_rdata1;
  wire b_rvalid0, b_rvalid1;
  wire [31:0] b_rdata0, b_rdata1;

  /* Reset only initializes the real ram_2p response register; after the first
     clock both copies see the same request but arbitrary independent addresses. */
  always @(posedge clk) begin
    rst_n <= 1'b1;
    past_valid <= 1'b1;
    if (past_valid) begin
      assert(a_rvalid0 == $past(a_req));
      assert(a_rvalid1 == $past(a_req));
      assert(a_rvalid0 == a_rvalid1);
    end
  end

  ram_2p #(.Depth(262144), .BExtraDelay(0)) dut0 (
    .clk_i(clk), .rst_ni(rst_n),
    .a_req_i(a_req), .a_we_i(1'b0), .a_be_i(4'hf), .a_addr_i(a_addr0),
    .a_wdata_i(32'b0), .a_rvalid_o(a_rvalid0), .a_rdata_o(a_rdata0),
    .b_req_i(1'b0), .b_we_i(1'b0), .b_be_i(4'b0), .b_addr_i(32'b0),
    .b_wdata_i(32'b0), .b_rvalid_o(b_rvalid0), .b_rdata_o(b_rdata0)
  );

  ram_2p #(.Depth(262144), .BExtraDelay(0)) dut1 (
    .clk_i(clk), .rst_ni(rst_n),
    .a_req_i(a_req), .a_we_i(1'b0), .a_be_i(4'hf), .a_addr_i(a_addr1),
    .a_wdata_i(32'b0), .a_rvalid_o(a_rvalid1), .a_rdata_o(a_rdata1),
    .b_req_i(1'b0), .b_we_i(1'b0), .b_be_i(4'b0), .b_addr_i(32'b0),
    .b_wdata_i(32'b0), .b_rvalid_o(b_rvalid1), .b_rdata_o(b_rdata1)
  );
endmodule
