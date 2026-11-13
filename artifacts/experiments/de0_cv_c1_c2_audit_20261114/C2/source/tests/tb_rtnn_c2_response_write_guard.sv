module tb_rtnn_c2_response_write_guard;
  logic clk=0, rst_n=0;
  logic request_valid=0;
  logic [799:0] request_data='0;
  logic request_accept, response_commit, response_error, halted, bus_fault;
  logic [383:0] response_data;
  localparam logic [31:0] REQUEST_SEQ=32'h1234_5678;

  always #10 clk <= ~clk;

  rtnn_de0_cv_soc_c2 dut (
    .clk_i(clk), .rst_ni(rst_n), .jtag_request_valid_i(request_valid),
    .jtag_request_data_i(request_data), .jtag_request_accept_o(request_accept),
    .jtag_response_commit_o(response_commit), .jtag_response_data_o(response_data),
    .jtag_response_error_o(response_error), .halted_o(halted), .bus_fault_o(bus_fault)
  );

  task automatic bus_write(input logic [31:0] addr,
                           input logic [3:0] be,
                           input logic [31:0] value);
    @(negedge clk);
    force dut.data_addr=addr;
    force dut.data_be=be;
    force dut.data_wdata=value;
    force dut.accepted=1'b1;
    force dut.mmio_write_valid=1'b1;
    force dut.response_word_index=addr[5:2]-4'd3;
    @(posedge clk); #1;
  endtask

  initial begin
    request_data[64 +: 32]=REQUEST_SEQ;
    repeat (5) @(negedge clk);
    rst_n=1;
    repeat (3) @(negedge clk);

    // Replace only the CPU's bus pins to inject a partial-word MMIO write;
    // all response assembly and commit logic remains the production SoC RTL.
    force dut.data_req=1'b1;
    force dut.data_we=1'b1;

    for (int word_index=0;word_index<12;word_index++) begin
      if (word_index==0)
        bus_write(32'h0002_008c + 4*word_index,4'b0011,32'h1122_3344);
      else if (word_index==2)
        bus_write(32'h0002_008c + 4*word_index,4'b1111,REQUEST_SEQ);
      else
        bus_write(32'h0002_008c + 4*word_index,4'b1111,32'hca00_0000+word_index);
    end

    bus_write(32'h0002_00bc,4'b1111,REQUEST_SEQ);
    if (response_commit) $fatal(1,"partial byte lanes were accepted as a complete response");
    if (!bus_fault) $fatal(1,"incomplete response commit did not set bus_fault");

    // Completing the missing two lanes makes the same response commit valid.
    bus_write(32'h0002_008c,4'b1100,32'haabb_0000);
    bus_write(32'h0002_00bc,4'b1111,REQUEST_SEQ);
    if (!response_commit) $fatal(1,"complete 48-byte response was not committed");

    // A second commit without rewriting any response byte must fail.
    bus_write(32'h0002_00bc,4'b1111,REQUEST_SEQ);
    if (response_commit) $fatal(1,"response byte-write mask was not cleared on commit");
    $display("C2_RESPONSE_WRITE_GUARD_PASS partial_rejected=1 full_commit=1 empty_recommit_rejected=1");
    $finish;
  end
endmodule
