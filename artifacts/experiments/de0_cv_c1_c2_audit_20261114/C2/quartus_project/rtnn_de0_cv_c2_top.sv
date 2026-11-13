// Physical DE0-CV wrapper. This is the only design top exposing Virtual JTAG.
module rtnn_de0_cv_c2_top (
  input wire CLOCK_50,
  input wire [0:0] KEY,
  output wire [3:0] LEDR
);
  wire tck, tdi, tdo, capture_dr, shift_dr, update_dr;
  wire [2:0] instruction;
  wire [21:0] unused_state;
  wire request_valid;
  wire [799:0] request_data;
  wire request_accept;
  wire response_commit;
  wire [383:0] response_data;
  wire response_error;
  wire halted, bus_fault;
  reg [2:0] rst_pipe_q;
  reg [25:0] heartbeat_q;
  wire sys_rst_n = rst_pipe_q[2];

  always @(posedge CLOCK_50 or negedge KEY[0])
    if (!KEY[0]) rst_pipe_q <= 3'b000;
    else rst_pipe_q <= {rst_pipe_q[1:0],1'b1};
  always @(posedge CLOCK_50 or negedge sys_rst_n)
    if (!sys_rst_n) heartbeat_q <= 26'd0;
    else heartbeat_q <= heartbeat_q + 26'd1;

  sld_virtual_jtag #(
    .sld_auto_instance_index("NO"), .sld_instance_index(0), .sld_ir_width(3)
  ) u_vjtag (
    .tck(tck), .tdi(tdi), .tdo(tdo), .ir_in(instruction), .ir_out(3'b000),
    .virtual_state_cdr(capture_dr), .virtual_state_sdr(shift_dr),
    .virtual_state_udr(update_dr), .virtual_state_cir(unused_state[0]),
    .virtual_state_uir(unused_state[1]), .virtual_state_e1dr(unused_state[2]),
    .virtual_state_pdr(unused_state[3]), .virtual_state_e2dr(unused_state[4]),
    .tms(unused_state[5]), .jtag_state_tlr(unused_state[6]),
    .jtag_state_rti(unused_state[7]), .jtag_state_sdrs(unused_state[8]),
    .jtag_state_cdr(unused_state[9]), .jtag_state_sdr(unused_state[10]),
    .jtag_state_e1dr(unused_state[11]), .jtag_state_pdr(unused_state[12]),
    .jtag_state_e2dr(unused_state[13]), .jtag_state_udr(unused_state[14]),
    .jtag_state_sirs(unused_state[15]), .jtag_state_cir(unused_state[16]),
    .jtag_state_sir(unused_state[17]), .jtag_state_e1ir(unused_state[18]),
    .jtag_state_pir(unused_state[19]), .jtag_state_e2ir(unused_state[20]),
    .jtag_state_uir(unused_state[21])
  );

  rtnn_c2_vjtag_mailbox u_mailbox (
    .tck_i(tck), .tdi_i(tdi), .tdo_o(tdo), .ir_i(instruction),
    .capture_dr_i(capture_dr), .shift_dr_i(shift_dr), .update_dr_i(update_dr),
    .trst_ni(KEY[0]), .clk_i(CLOCK_50), .rst_ni(sys_rst_n),
    .request_valid_o(request_valid), .request_data_o(request_data),
    .request_accept_i(request_accept), .response_commit_i(response_commit),
    .response_data_i(response_data), .response_error_i(response_error)
  );
  rtnn_de0_cv_soc_c2 u_soc (
    .clk_i(CLOCK_50), .rst_ni(sys_rst_n),
    .jtag_request_valid_i(request_valid), .jtag_request_data_i(request_data),
    .jtag_request_accept_o(request_accept), .jtag_response_commit_o(response_commit),
    .jtag_response_data_o(response_data), .jtag_response_error_o(response_error),
    .halted_o(halted), .bus_fault_o(bus_fault)
  );
  assign LEDR = {bus_fault, halted, response_commit, heartbeat_q[25]};
endmodule
