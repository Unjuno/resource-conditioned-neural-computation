module rtnn_c1_selftest_checker (
  input  logic         done_i,
  input  logic [1:0]   transport_error_i,
  input  logic         uart_idle_i,
  input  logic         halted_i,
  input  logic         bus_fault_i,
  input  logic         reject_expected_i,
  input  logic [31:0]  seq_expected_i,
  input  logic [15:0]  input_id_expected_i,
  input  logic [15:0]  budget_expected_i,
  input  logic [31:0]  deadline_expected_i,
  input  logic [7:0]   status_expected_i,
  input  logic [7:0]   admitted_expected_i,
  input  logic [7:0]   executed_expected_i,
  input  logic [7:0]   prediction_expected_i,
  input  logic [7:0]   label_expected_i,
  input  logic [7:0]   stop_expected_i,
  input logic [31:0]  flags_expected_i,
  input  logic [383:0] response_i,
  output logic         valid_o
);
  function automatic logic [31:0] crc32_44(input logic [351:0] data);
    logic [31:0] crc, mask;
    begin
      crc = 32'hffff_ffff;
      for (int n = 0; n < 44; n++) begin
        crc = crc ^ {24'b0, data[n*8 +: 8]};
        for (int k = 0; k < 8; k++) begin
          mask = 32'h0 - (crc & 1);
          crc = (crc >> 1) ^ (32'hedb8_8320 & mask);
        end
      end
      crc32_44 = ~crc;
    end
  endfunction

  always_comb begin
    valid_o = 1'b0;
    if (done_i && (transport_error_i == 2'b00) && uart_idle_i &&
        !halted_i && !bus_fault_i &&
        (response_i[31:0] == 32'h524e_5452) &&
        (response_i[39:32] == 8'd1) &&
        (response_i[47:40] == status_expected_i) &&
        (response_i[55:48] == 8'd4) &&
        (response_i[63:56] == stop_expected_i) &&
        (response_i[95:64] == seq_expected_i) &&
        (response_i[111:96] == input_id_expected_i) &&
        (response_i[127:112] == budget_expected_i) &&
        (response_i[159:128] == deadline_expected_i) &&
        (response_i[167:160] == admitted_expected_i) &&
        (response_i[175:168] == executed_expected_i) &&
        (response_i[183:176] == prediction_expected_i) &&
        (response_i[191:184] == label_expected_i) &&
        (response_i[255:224] == 32'h5254_4e4e) &&
        (response_i[287:256] == 32'h4450_4331) &&
        (response_i[319:288] == 32'h79e4_aef3) &&
        (response_i[351:320] == flags_expected_i) &&
        (response_i[383:352] == crc32_44(response_i[351:0]))) begin
      if (reject_expected_i) begin
        valid_o = (response_i[223:192] == 32'd0);
      end else begin
        valid_o = (response_i[223:192] != 32'd0) &&
                  (response_i[223:192] <= deadline_expected_i);
      end
    end
  end
endmodule
