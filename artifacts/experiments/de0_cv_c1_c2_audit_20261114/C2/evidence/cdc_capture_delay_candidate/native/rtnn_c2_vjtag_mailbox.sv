// UART-free Virtual-JTAG scan mailbox. The vendor Virtual-JTAG primitive
// supplies these DR control signals; this module owns the TCK/CLOCK_50 CDC.
// IR 1: 800-bit request (32-byte RTNQ + 64 pixels + 4-byte pixel CRC),
// IR 2: 384-bit committed RTNR response, IR 3: status (ERROR/DONE/BUSY/
// REQUEST_PENDING/READY), IR 4: build ID.
module rtnn_c2_vjtag_mailbox (
  input  logic         tck_i,
  input  logic         tdi_i,
  output logic         tdo_o,
  input  logic [2:0]   ir_i,
  input  logic         capture_dr_i,
  input  logic         shift_dr_i,
  input  logic         update_dr_i,
  input  logic         trst_ni,

  input  logic         clk_i,
  input  logic         rst_ni,

  output logic         request_valid_o,
  output logic [799:0] request_data_o,
  input  logic         request_accept_i,
  input  logic         response_commit_i,
  input  logic [383:0] response_data_i,
  input  logic         response_error_i
);
  localparam logic [2:0] IR_REQUEST = 3'd1;
  localparam logic [2:0] IR_RESPONSE = 3'd2;
  localparam logic [2:0] IR_STATUS = 3'd3;
  localparam logic [2:0] IR_BUILD_ID = 3'd4;
`ifndef RTNN_C2_BUILD_ID
`define RTNN_C2_BUILD_ID 32'h4332_4a31
`endif
  localparam logic [31:0] BUILD_ID = `RTNN_C2_BUILD_ID;

  logic [799:0] req_shift_tck_q, req_hold_tck_q;
  logic [383:0] rsp_shift_tck_q, rsp_hold_tck_q;
  logic [799:0] req_bus_sync1_sys_q, req_bus_sync2_sys_q;
  logic [383:0] rsp_bus_sync1_tck_q, rsp_bus_sync2_tck_q;
  logic req_capture_pending_sys_q, rsp_capture_pending_tck_q;
  logic [31:0] build_shift_tck_q;
  logic [7:0] status_shift_tck_q;
  logic [10:0] req_shift_count_tck_q;
  logic [1:0] tck_reset_release_q;
  logic tck_reset_released;
  logic req_toggle_tck_q, req_sync1_sys_q, req_sync2_sys_q, req_seen_sys_q;
  logic req_ack_toggle_sys_q, req_ack_sync1_tck_q, req_ack_sync2_tck_q;
  logic rsp_toggle_sys_q, rsp_sync1_tck_q, rsp_sync2_tck_q, rsp_seen_tck_q;
  logic rsp_consume_toggle_tck_q, rsp_consume_sync1_sys_q, rsp_consume_sync2_sys_q;
  logic busy_sys_q, error_sys_q, done_sys_q;
  logic busy_sync1_tck_q, busy_sync2_tck_q, error_sync1_tck_q, error_sync2_tck_q;
  logic done_sync1_tck_q, done_sync2_tck_q;
  logic pending_tck_q;
  logic response_pending_tck_q;
  logic protocol_error_tck_q;
  logic [10:0] rsp_shift_count_tck_q;

  // Assert the TCK-domain reset asynchronously, but release it only after two
  // TCK edges. TCK may be stopped while KEY[0] is released; the synchronizer
  // then keeps the mailbox reset until the host starts a scan.
  always_ff @(posedge tck_i or negedge trst_ni) begin
    if (!trst_ni) tck_reset_release_q <= 2'b00;
    else tck_reset_release_q <= {tck_reset_release_q[0], 1'b1};
  end
  assign tck_reset_released = tck_reset_release_q[1];

  // Current LSB is available before the host's sampling edge.
  always_comb begin
    unique case (ir_i)
      IR_REQUEST:  tdo_o = req_shift_tck_q[0];
      IR_RESPONSE: tdo_o = rsp_shift_tck_q[0];
      IR_STATUS:   tdo_o = status_shift_tck_q[0];
      IR_BUILD_ID: tdo_o = build_shift_tck_q[0];
      default:     tdo_o = 1'b0;
    endcase
  end

  // TCK domain. A local pending lock is set at UpdateDR, before the BUSY
  // synchronizer round-trip, preventing a second request in that latency.
  always_ff @(posedge tck_i or negedge tck_reset_released) begin
    if (!tck_reset_released) begin
      req_shift_tck_q <= 800'b0;
      req_hold_tck_q <= 800'b0;
      rsp_bus_sync1_tck_q <= 384'b0;
      rsp_bus_sync2_tck_q <= 384'b0;
      rsp_shift_tck_q <= 384'b0;
      rsp_hold_tck_q <= 384'b0;
      build_shift_tck_q <= 32'b0;
      status_shift_tck_q <= 8'b0;
      req_shift_count_tck_q <= 11'b0;
      rsp_shift_count_tck_q <= 11'b0;
      rsp_capture_pending_tck_q <= 1'b0;
      req_toggle_tck_q <= 1'b0;
      req_ack_sync1_tck_q <= 1'b0;
      req_ack_sync2_tck_q <= 1'b0;
      rsp_sync1_tck_q <= 1'b0;
      rsp_sync2_tck_q <= 1'b0;
      rsp_seen_tck_q <= 1'b0;
      rsp_consume_toggle_tck_q <= 1'b0;
      busy_sync1_tck_q <= 1'b0;
      busy_sync2_tck_q <= 1'b0;
      error_sync1_tck_q <= 1'b0;
      error_sync2_tck_q <= 1'b0;
      done_sync1_tck_q <= 1'b0;
      done_sync2_tck_q <= 1'b0;
      pending_tck_q <= 1'b0;
      protocol_error_tck_q <= 1'b0;
      response_pending_tck_q <= 1'b0;
    end else begin
      rsp_bus_sync1_tck_q <= response_data_i;
      rsp_bus_sync2_tck_q <= rsp_bus_sync1_tck_q;
      req_ack_sync1_tck_q <= req_ack_toggle_sys_q;
      req_ack_sync2_tck_q <= req_ack_sync1_tck_q;
      rsp_sync1_tck_q <= rsp_toggle_sys_q;
      rsp_sync2_tck_q <= rsp_sync1_tck_q;
      busy_sync1_tck_q <= busy_sys_q;
      busy_sync2_tck_q <= busy_sync1_tck_q;
      error_sync1_tck_q <= error_sys_q;
      error_sync2_tck_q <= error_sync1_tck_q;
      done_sync1_tck_q <= done_sys_q;
      done_sync2_tck_q <= done_sync1_tck_q;

      if (req_ack_sync2_tck_q == req_toggle_tck_q)
        pending_tck_q <= 1'b0;
      if (rsp_capture_pending_tck_q) begin
        rsp_hold_tck_q <= rsp_bus_sync2_tck_q;
        rsp_capture_pending_tck_q <= 1'b0;
        response_pending_tck_q <= 1'b1;
      end
      if (rsp_sync2_tck_q != rsp_seen_tck_q) begin
        rsp_seen_tck_q <= rsp_sync2_tck_q;
        rsp_capture_pending_tck_q <= 1'b1;
      end

      if (capture_dr_i) begin
        unique case (ir_i)
          IR_REQUEST: begin req_shift_tck_q <= 800'b0; req_shift_count_tck_q <= 11'b0; end
          IR_RESPONSE: begin rsp_shift_tck_q <= rsp_hold_tck_q; rsp_shift_count_tck_q <= 11'b0; end
          IR_STATUS: status_shift_tck_q <= {(error_sync2_tck_q | protocol_error_tck_q),
                                             done_sync2_tck_q, busy_sync2_tck_q,
                                             pending_tck_q,
                                             !(pending_tck_q || response_pending_tck_q ||
                                               busy_sync2_tck_q || done_sync2_tck_q ||
                                               error_sync2_tck_q || protocol_error_tck_q),
                                             3'b0};
          IR_BUILD_ID: build_shift_tck_q <= BUILD_ID;
          default: begin end
        endcase
      end
      if (shift_dr_i) begin
        unique case (ir_i)
          IR_REQUEST: begin
            req_shift_tck_q <= {tdi_i, req_shift_tck_q[799:1]};
            if (req_shift_count_tck_q < 11'd801) req_shift_count_tck_q <= req_shift_count_tck_q + 1'b1;
          end
          IR_RESPONSE: begin
            rsp_shift_tck_q <= {1'b0, rsp_shift_tck_q[383:1]};
            if (rsp_shift_count_tck_q < 11'd385) rsp_shift_count_tck_q <= rsp_shift_count_tck_q + 1'b1;
          end
          IR_STATUS: status_shift_tck_q <= {1'b0, status_shift_tck_q[7:1]};
          IR_BUILD_ID: build_shift_tck_q <= {1'b0, build_shift_tck_q[31:1]};
          default: begin end
        endcase
      end
      if (update_dr_i) begin
        if (ir_i == IR_REQUEST) begin
          if (req_shift_count_tck_q == 11'd800 && !pending_tck_q &&
              !response_pending_tck_q && !busy_sync2_tck_q && !done_sync2_tck_q &&
              !error_sync2_tck_q && !protocol_error_tck_q) begin
            req_hold_tck_q <= req_shift_tck_q;
            req_toggle_tck_q <= ~req_toggle_tck_q;
            pending_tck_q <= 1'b1;
          end else begin
            // Malformed length or overlapping submission is visible as ERROR.
            protocol_error_tck_q <= 1'b1;
          end
          req_shift_count_tck_q <= 11'b0;
        end else if (ir_i == IR_RESPONSE && rsp_shift_count_tck_q == 11'd384 &&
                     response_pending_tck_q) begin
          // An empty/stale response read is a no-op. Toggling consume without
          // a published response could match the next response toggle and
          // clear its DONE before the host has read it.
          rsp_consume_toggle_tck_q <= ~rsp_consume_toggle_tck_q;
          response_pending_tck_q <= 1'b0;
        end
      end
    end
  end

  // CLOCK_50 domain. Multi-bit request/response buses are bundled data: their
  // source registers remain stable until the opposite-domain toggle handshake.
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      req_bus_sync1_sys_q <= 800'b0;
      req_bus_sync2_sys_q <= 800'b0;
      req_capture_pending_sys_q <= 1'b0;
      req_sync1_sys_q <= 1'b0;
      req_sync2_sys_q <= 1'b0;
      req_seen_sys_q <= 1'b0;
      req_ack_toggle_sys_q <= 1'b0;
      rsp_toggle_sys_q <= 1'b0;
      rsp_consume_sync1_sys_q <= 1'b0;
      rsp_consume_sync2_sys_q <= 1'b0;
      request_valid_o <= 1'b0;
      request_data_o <= 800'b0;
      busy_sys_q <= 1'b0;
      error_sys_q <= 1'b0;
      done_sys_q <= 1'b0;
    end else begin
      req_bus_sync1_sys_q <= req_hold_tck_q;
      req_bus_sync2_sys_q <= req_bus_sync1_sys_q;
      req_sync1_sys_q <= req_toggle_tck_q;
      req_sync2_sys_q <= req_sync1_sys_q;
      rsp_consume_sync1_sys_q <= rsp_consume_toggle_tck_q;
      rsp_consume_sync2_sys_q <= rsp_consume_sync1_sys_q;
      if (req_capture_pending_sys_q) begin
        request_data_o <= req_bus_sync2_sys_q;
        request_valid_o <= 1'b1;
        req_capture_pending_sys_q <= 1'b0;
      end
      if (req_sync2_sys_q != req_seen_sys_q) begin
        req_seen_sys_q <= req_sync2_sys_q;
        req_capture_pending_sys_q <= 1'b1;
        busy_sys_q <= 1'b1;
        done_sys_q <= 1'b0;
      end
      if (request_valid_o && request_accept_i) begin
        request_valid_o <= 1'b0;
        req_ack_toggle_sys_q <= req_seen_sys_q;
      end
      if (response_commit_i && busy_sys_q) begin
        // Payload must already be stable before this toggle; host may only scan
        // after the two-stage synchronized completion and resulting snapshot.
        rsp_toggle_sys_q <= ~rsp_toggle_sys_q;
        busy_sys_q <= 1'b0;
        done_sys_q <= 1'b1;
        error_sys_q <= response_error_i;
      end
      if (rsp_consume_sync2_sys_q == rsp_toggle_sys_q && done_sys_q) begin
        done_sys_q <= 1'b0;
        error_sys_q <= 1'b0;
      end
    end
  end
endmodule
