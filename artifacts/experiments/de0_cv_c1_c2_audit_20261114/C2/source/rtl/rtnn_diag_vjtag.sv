// Virtual JTAG endpoint plus a bundled-data toggle mailbox into CLOCK_50.
// IR 1: shift 256-bit RTNQ frame (LSB first), UpdateDR submits it.
// IR 2: shift 384-bit RTNR frame (LSB first), CaptureDR snapshots response.
// IR 3: 8-bit status: {error[1:0], valid, busy, 4'b0}.
module rtnn_diag_vjtag_endpoint #(
  parameter integer PACKET_TIMEOUT_CYCLES = 100_000_000
) (
  input logic tck_i, tdi_i,
  output logic tdo_o,
  input logic [2:0] ir_i,
  input logic capture_dr_i, shift_dr_i, update_dr_i,
  input logic clk_i, rst_sys_ni, rst_tck_async_ni,
  output logic request_serial_o,
  input logic response_serial_i,
  output wire diag_uart_loopback_o
);
  logic [255:0] command_shift_q, command_mailbox_q;
  logic [383:0] response_shift_q, response_mailbox_sys_q, response_mailbox_tck_q;
  logic [7:0] status_shift_q;
  logic [31:0] build_id_shift_q;
  logic request_toggle_tck_q, request_sync1_q, request_sync2_q;
  logic request_ack_sys_q;
  logic response_toggle_sys_q, response_sync1_q, response_sync2_q, response_seen_tck_q;
  logic busy_sync1_q, busy_sync2_q;
  logic valid_tck_q;
  logic [1:0] error_sys_q, error_sync1_q, error_sync2_q;
  logic [1:0] rst_tck_pipe_q;
  wire rst_tck_ni = rst_tck_pipe_q[1];
  logic packet_start_q, packet_busy, packet_done;
  logic packet_done_seen_q;
  logic [1:0] packet_error;
  logic [383:0] packet_response;
  logic [255:0] packet_request_q;

  rtnn_diag_packet_engine #(.TIMEOUT_CYCLES(PACKET_TIMEOUT_CYCLES)) u_packet (
    .clk_i(clk_i), .rst_ni(rst_sys_ni), .start_i(packet_start_q), .request_i(packet_request_q),
    .busy_o(packet_busy), .done_o(packet_done), .error_o(packet_error),
    .response_o(packet_response), .request_serial_o(request_serial_o),
    .response_serial_i(response_serial_i)
  );
  assign diag_uart_loopback_o = packet_busy || (request_sync2_q != request_ack_sys_q);

  // JTAG hosts sample TDO on the active TCK edge. Drive the current LSB
  // before that edge; registering TDO on posedge tck_i makes hardware reads
  // one bit late even though a post-edge RTL testbench can hide the phase error.
  always_comb begin
    case (ir_i)
      2'd1: tdo_o = command_shift_q[0];
      2'd2: tdo_o = response_shift_q[0];
      2'd3: tdo_o = status_shift_q[0];
      3'd4: tdo_o = build_id_shift_q[0];
      default: tdo_o = 1'b0;
    endcase
  end

  // TCK domain: scan registers and request/response toggle synchronizers.
  always_ff @(posedge tck_i or negedge rst_tck_async_ni) begin
    if (!rst_tck_async_ni) rst_tck_pipe_q <= 2'b00;
    else rst_tck_pipe_q <= {rst_tck_pipe_q[0], 1'b1};
  end

  always_ff @(posedge tck_i or negedge rst_tck_ni) begin
    if (!rst_tck_ni) begin
      command_shift_q <= '0;
      command_mailbox_q <= '0;
      response_shift_q <= '0;
      response_mailbox_tck_q <= '0;
      status_shift_q <= '0;
      build_id_shift_q <= '0;
      request_toggle_tck_q <= 1'b0;
      response_sync1_q <= 1'b0;
      response_sync2_q <= 1'b0;
      response_seen_tck_q <= 1'b0;
      busy_sync1_q <= 1'b0;
      busy_sync2_q <= 1'b0;
      error_sync1_q <= '0;
      error_sync2_q <= '0;
      valid_tck_q <= 1'b0;
    end else begin
      response_sync1_q <= response_toggle_sys_q;
      response_sync2_q <= response_sync1_q;
      busy_sync1_q <= packet_busy;
      busy_sync2_q <= busy_sync1_q;
      error_sync1_q <= error_sys_q;
      error_sync2_q <= error_sync1_q;
      if (response_sync2_q != response_seen_tck_q) begin
        // response_mailbox_sys_q remains stable until a later transaction completes.
        response_mailbox_tck_q <= response_mailbox_sys_q;
        response_seen_tck_q <= response_sync2_q;
        valid_tck_q <= 1'b1;
      end

      if (capture_dr_i) begin
        case (ir_i)
          2'd1: command_shift_q <= '0;
          2'd2: response_shift_q <= response_mailbox_tck_q;
          2'd3: status_shift_q <= {error_sync2_q, valid_tck_q, busy_sync2_q, 4'b0};
          3'd4: build_id_shift_q <= 32'h4332_4a31; // ASCII "C2J1", bytes LSB-first.
          default: status_shift_q <= '0;
        endcase
      end else if (shift_dr_i) begin
        case (ir_i)
          2'd1: command_shift_q <= {tdi_i, command_shift_q[255:1]};
          2'd2: response_shift_q <= {tdi_i, response_shift_q[383:1]};
          2'd3: status_shift_q <= {tdi_i, status_shift_q[7:1]};
          3'd4: build_id_shift_q <= {tdi_i, build_id_shift_q[31:1]};
          default: ;
        endcase
      end

      if (update_dr_i && ir_i == 2'd1 && !busy_sync2_q) begin
        command_mailbox_q <= command_shift_q;
        request_toggle_tck_q <= ~request_toggle_tck_q;
        valid_tck_q <= 1'b0;
      end
    end
  end

  // CLOCK_50 domain: synchronize request toggle, capture its stable payload,
  // execute the unchanged UART packet protocol, then publish a stable response.
  always_ff @(posedge clk_i or negedge rst_sys_ni) begin
    if (!rst_sys_ni) begin
      request_sync1_q <= 1'b0;
      request_sync2_q <= 1'b0;
      request_ack_sys_q <= 1'b0;
      packet_start_q <= 1'b0;
      packet_done_seen_q <= 1'b0;
      packet_request_q <= '0;
      response_mailbox_sys_q <= '0;
      response_toggle_sys_q <= 1'b0;
      error_sys_q <= '0;
    end else begin
      request_sync1_q <= request_toggle_tck_q;
      request_sync2_q <= request_sync1_q;
      packet_start_q <= 1'b0;
      if (request_sync2_q != request_ack_sys_q && !packet_busy) begin
        packet_request_q <= command_mailbox_q;
        request_ack_sys_q <= request_sync2_q;
        packet_start_q <= 1'b1;
        // The engine's done_o is sticky until it samples this new start.
        // Mask that old completion while the start crosses one local cycle.
        packet_done_seen_q <= 1'b1;
        error_sys_q <= '0;
      end
      if (!packet_done) packet_done_seen_q <= 1'b0;
      if (packet_done && !packet_done_seen_q) begin
        response_mailbox_sys_q <= packet_response;
        response_toggle_sys_q <= ~response_toggle_sys_q;
        error_sys_q <= packet_error;
        packet_done_seen_q <= 1'b1;
      end
    end
  end
endmodule

module rtnn_diag_vjtag_soc (
  input wire CLOCK_50,
  input wire [0:0] KEY,
  output wire [3:0] LEDR,
  output wire GPIO_0_D0,
  input wire GPIO_0_D1
);
  wire tck, tdi, tdo, capture_dr, shift_dr, update_dr;
  wire [2:0] instruction;
  wire [21:0] unused_state;
  wire request_serial, response_serial, diag_uart_loopback, uart_idle, halted, bus_fault;
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

  rtnn_diag_vjtag_endpoint u_endpoint (
    .tck_i(tck), .tdi_i(tdi), .tdo_o(tdo), .ir_i(instruction),
    .capture_dr_i(capture_dr), .shift_dr_i(shift_dr), .update_dr_i(update_dr),
    .clk_i(CLOCK_50), .rst_sys_ni(sys_rst_n), .rst_tck_async_ni(KEY[0]),
    .request_serial_o(request_serial),
    .response_serial_i(response_serial), .diag_uart_loopback_o(diag_uart_loopback)
  );

  rtnn_de0_cv_soc u_soc (
    .clk_i(CLOCK_50), .rst_ni(sys_rst_n), .uart_tx_o(response_serial),
    .uart_rx_i(diag_uart_loopback ? request_serial : GPIO_0_D1), .uart_idle_o(uart_idle),
    .halted_o(halted), .bus_fault_o(bus_fault)
  );
  assign GPIO_0_D0 = response_serial;
  assign LEDR = {bus_fault, halted, !uart_idle, heartbeat_q[25]};
endmodule
