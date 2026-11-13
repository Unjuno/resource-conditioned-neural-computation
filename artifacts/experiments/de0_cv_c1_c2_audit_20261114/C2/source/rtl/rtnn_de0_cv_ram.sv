// DE0-CV on-chip memory: 256 KiB, two synchronous read ports and one byte-write port.
// The frozen B image is split into four 8-bit M10K lanes to preserve Cyclone V
// True Dual Port inference. Same-port store response is new-data; Ibex LSU does
// not consume store response data. Mixed-port collisions are unspecified by M10K.
module rtnn_de0_cv_ram (
  input logic clk_i, rst_ni,
  input logic data_req_i, data_we_i,
  input logic [3:0] data_be_i,
  input logic [31:0] data_addr_i, data_wdata_i,
  output logic data_hit_o, data_rvalid_o,
  output wire [31:0] data_rdata_o,
  input logic instr_req_i,
  input logic [31:0] instr_addr_i,
  output logic instr_hit_o, instr_rvalid_o,
  output wire [31:0] instr_rdata_o
);
  // 0x00100000..0x0013ffff direct map; preserve frozen ELF stack alias.
  function automatic logic is_direct(input logic [31:0] a);
    is_direct = ((a & 32'hfffc0000) == 32'h00100000);
  endfunction
  function automatic logic is_stack_alias(input logic [31:0] a);
    is_stack_alias = ((a & 32'hffff8000) == 32'h001f8000);
  endfunction
  function automatic logic [15:0] word_index(input logic [31:0] a);
    if (is_stack_alias(a)) word_index = {3'b111, a[14:2]};
    else word_index = a[17:2];
  endfunction

  assign data_hit_o = is_direct(data_addr_i) || is_stack_alias(data_addr_i);
  assign instr_hit_o = is_direct(instr_addr_i);

  (* ramstyle = "M10K" *) logic [7:0] mem0 [0:65535];
  (* ramstyle = "M10K" *) logic [7:0] mem1 [0:65535];
  (* ramstyle = "M10K" *) logic [7:0] mem2 [0:65535];
  (* ramstyle = "M10K" *) logic [7:0] mem3 [0:65535];
  initial begin
    $readmemh("rtnn_ram_lane0.hex", mem0);
    $readmemh("rtnn_ram_lane1.hex", mem1);
    $readmemh("rtnn_ram_lane2.hex", mem2);
    $readmemh("rtnn_ram_lane3.hex", mem3);
  end

  wire [15:0] data_idx = word_index(data_addr_i);
  wire [15:0] instr_idx = word_index(instr_addr_i);
  logic [31:0] data_ram_q, instr_ram_q;
  logic data_hit_q, instr_hit_q;
  assign data_rdata_o = data_hit_q ? data_ram_q : 32'b0;
  assign instr_rdata_o = instr_hit_q ? instr_ram_q : 32'b0;

  // Canonical synchronous two-port style used by Quartus to infer one TDP per lane.
  always @(posedge clk_i) begin
    if (data_req_i && data_hit_o && data_we_i) begin
      if (data_be_i[0]) mem0[data_idx] = data_wdata_i[7:0];
      if (data_be_i[1]) mem1[data_idx] = data_wdata_i[15:8];
      if (data_be_i[2]) mem2[data_idx] = data_wdata_i[23:16];
      if (data_be_i[3]) mem3[data_idx] = data_wdata_i[31:24];
    end
    data_ram_q <= {mem3[data_idx],mem2[data_idx],mem1[data_idx],mem0[data_idx]};
    if (data_req_i) data_hit_q <= data_hit_o;
  end
  always @(posedge clk_i) begin
    instr_ram_q <= {mem3[instr_idx],mem2[instr_idx],mem1[instr_idx],mem0[instr_idx]};
    if (instr_req_i) instr_hit_q <= instr_hit_o;
  end
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      data_rvalid_o <= 1'b0;
      instr_rvalid_o <= 1'b0;
    end else begin
      data_rvalid_o <= data_req_i;
      instr_rvalid_o <= instr_req_i;
    end
  end
endmodule
