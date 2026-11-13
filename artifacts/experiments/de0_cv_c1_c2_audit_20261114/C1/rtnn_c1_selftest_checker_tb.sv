module rtnn_c1_selftest_checker_tb;
  logic done, uart_idle, halted, bus_fault, reject_expected;
  logic [1:0] transport_error;
  logic [31:0] seq_expected, deadline_expected;
  logic [15:0] input_id_expected, budget_expected;
  logic [7:0] status_expected, admitted_expected, executed_expected;
  logic [7:0] prediction_expected, label_expected, stop_expected;
  logic [31:0] flags_expected;
  logic [383:0] response;
  logic valid;
  rtnn_c1_selftest_checker dut (
    .done_i(done), .transport_error_i(transport_error), .uart_idle_i(uart_idle),
    .halted_i(halted), .bus_fault_i(bus_fault), .reject_expected_i(reject_expected),
    .seq_expected_i(seq_expected), .input_id_expected_i(input_id_expected),
    .budget_expected_i(budget_expected), .deadline_expected_i(deadline_expected),
    .status_expected_i(status_expected), .admitted_expected_i(admitted_expected),
    .executed_expected_i(executed_expected), .prediction_expected_i(prediction_expected),
    .label_expected_i(label_expected), .stop_expected_i(stop_expected),
    .flags_expected_i(flags_expected),
    .response_i(response), .valid_o(valid)
  );

  function automatic [31:0] crc32(input logic [351:0] data);
    logic [31:0] c, mask;
    begin
      c = 32'hffff_ffff;
      for (int n=0;n<44;n++) begin
        c ^= {24'b0,data[n*8 +: 8]};
        for(int k=0;k<8;k++) begin mask=32'h0-(c&1); c=(c>>1)^(32'hedb8_8320&mask); end
      end
      return ~c;
    end
  endfunction

  task automatic refresh_crc; response[383:352]=crc32(response[351:0]); endtask
  task automatic expect_invalid(input string name);
    #1; if(valid) $fatal(1,"negative checker case accepted: %s",name);
    $display("CHECKER_REJECT_PASS %s",name);
  endtask

  initial begin
    done=1; uart_idle=1; halted=0; bus_fault=0; transport_error=0; reject_expected=0;
    seq_expected=32'd18; input_id_expected=16'd57; budget_expected=16'hffff;
    deadline_expected=32'd631000; status_expected=0; admitted_expected=1;
    executed_expected=1; prediction_expected=8'd1; label_expected=8'd2; stop_expected=8'd3;
    flags_expected=0;
    response='0; response[31:0]=32'h524e_5452; response[39:32]=1;
    response[47:40]=0; response[55:48]=4; response[63:56]=3;
    response[95:64]=18; response[111:96]=57; response[127:112]=16'hffff;
    response[159:128]=631000; response[167:160]=1; response[175:168]=1;
    response[183:176]=1; response[191:184]=2; response[223:192]=1000;
    response[255:224]=32'h5254_4e4e; response[287:256]=32'h4450_4331;
    response[319:288]=32'h79e4_aef3; refresh_crc();
    #1; if(!valid) $fatal(1,"valid normal frame rejected");
    $display("CHECKER_POSITIVE_PASS normal");
    response[352] ^= 1; expect_invalid("bad_crc"); response[352] ^= 1;
    response[183:176]=8'd9; refresh_crc(); expect_invalid("wrong_prediction"); response[183:176]=1;
    response[175:168]=8'd0; refresh_crc(); expect_invalid("wrong_executed"); response[175:168]=1;
    response[95:64]=19; refresh_crc(); expect_invalid("stale_sequence"); response[95:64]=18;
    response[287:256]=32'h0000_0000; refresh_crc(); expect_invalid("wrong_build_identity"); response[287:256]=32'h4450_4331;
    response[223:192]=631001; refresh_crc(); expect_invalid("over_deadline"); response[223:192]=1000; refresh_crc();
    transport_error=1; expect_invalid("transport_timeout"); transport_error=0;
    bus_fault=1; expect_invalid("bus_fault"); bus_fault=0;
    halted=1; expect_invalid("cpu_halted"); halted=0;
    uart_idle=0; expect_invalid("uart_not_idle"); uart_idle=1;
    done=0; expect_invalid("not_done"); done=1;
    reject_expected=1; status_expected=1; admitted_expected=8'hff; executed_expected=8'hff;
    prediction_expected=8'hff; label_expected=8'hff; stop_expected=0;
    response[47:40]=1; response[63:56]=0; response[167:160]=8'hff;
    response[175:168]=8'hff; response[183:176]=8'hff; response[191:184]=8'hff;
    response[223:192]=0; refresh_crc(); #1;
    if(!valid) $fatal(1,"valid reject frame rejected");
    $display("CHECKER_POSITIVE_PASS reject");
    response[223:192]=1; refresh_crc(); expect_invalid("reject_nonzero_cycles");
    $display("CHECKER_ALL_PASS"); $finish;
  end
endmodule
