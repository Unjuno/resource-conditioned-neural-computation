`timescale 1ns/1ps
module tb_rtnn_c2_vjtag_mailbox_async;
  logic tck=0, clk=0, rst_n=0, trst_n=0;
  logic tdi=0, tdo, capture_dr=0, shift_dr=0, update_dr=0;
  logic [2:0] ir=0;
  logic request_valid, request_accept=0, response_commit=0, response_error=0;
  logic [799:0] request_data;
  logic [479:0] response_data=480'b0;
  logic [799:0] current_payload=800'b0;
  logic [479:0] expected_response;
  integer sys_half_ps=10000, tck_half_ps=15000, tck_phase_ps=0;
  integer transaction_count=32;

  rtnn_c2_vjtag_mailbox dut (
    .tck_i(tck), .tdi_i(tdi), .tdo_o(tdo), .ir_i(ir),
    .capture_dr_i(capture_dr), .shift_dr_i(shift_dr), .update_dr_i(update_dr),
    .trst_ni(trst_n), .clk_i(clk), .rst_ni(rst_n),
    .request_valid_o(request_valid), .request_data_o(request_data),
    .request_accept_i(request_accept), .response_commit_i(response_commit),
    .response_data_i(response_data), .response_error_i(response_error)
  );

  function automatic logic [799:0] make_payload(input integer seed);
    logic [799:0] p;
    for (int b=0; b<800; b++)
      p[b] = (((b * (seed + 3)) ^ (b >> 2) ^ (seed * 19)) % 17) < 8;
    return p;
  endfunction

  function automatic logic [479:0] make_response(input logic [799:0] p);
    logic [479:0] r;
    r = {p[399:0], p[799:720]};
    r[0] = r[0] ^ (^p[719:400]);
    return r;
  endfunction

  task automatic scan_cycle(input logic [2:0] instruction,
                            input logic cap, input logic shift,
                            input logic update, input logic data_bit);
    @(negedge tck);
    ir=instruction; capture_dr=cap; shift_dr=shift; update_dr=update; tdi=data_bit;
    @(negedge tck);
    capture_dr=0; shift_dr=0; update_dr=0;
  endtask

  task automatic submit_request(input logic [799:0] payload);
    scan_cycle(3'd1, 1, 0, 0, 0);
    for (int b=0; b<800; b++) scan_cycle(3'd1, 0, 1, 0, payload[b]);
    scan_cycle(3'd1, 0, 0, 1, 0);
  endtask

  task automatic consume_response(output logic [479:0] scanned);
    scan_cycle(3'd2, 1, 0, 0, 0);
    scanned='0;
    for (int b=0; b<480; b++) begin
      @(negedge tck);
      ir=3'd2; shift_dr=1; capture_dr=0; update_dr=0;
      scanned[b]=tdo;
      @(negedge tck);
      shift_dr=0;
    end
    scan_cycle(3'd2, 0, 0, 1, 0);
  endtask

  // Model only the mailbox client interface. This test does not model Ibex
  // execution and is not an SoC, analog-metastability, or STA proof.
  initial begin : system_side_client
    forever begin
      wait (rst_n && request_valid);
      #1;
      if (request_data !== current_payload)
        $fatal(1, "request CDC payload mismatch");
      response_data = make_response(request_data);
      @(negedge clk); request_accept=1;
      @(negedge clk); request_accept=0;
      repeat (2) @(negedge clk);
      response_commit=1;
      @(negedge clk); response_commit=0;
    end
  end

  initial begin : clocks_and_stimulus
    if (!$value$plusargs("sys_half_ps=%d", sys_half_ps) ||
        !$value$plusargs("tck_half_ps=%d", tck_half_ps) ||
        !$value$plusargs("tck_phase_ps=%d", tck_phase_ps))
      $fatal(1, "required plusargs: sys_half_ps, tck_half_ps, tck_phase_ps");
    if (sys_half_ps < 1 || tck_half_ps < 1 || tck_phase_ps < 0)
      $fatal(1, "invalid clock parameters");
    fork
      forever #(sys_half_ps * 1ps) clk = ~clk;
      begin
        #(tck_phase_ps * 1ps);
        forever #(tck_half_ps * 1ps) tck = ~tck;
      end
    join_none

    repeat (4) @(negedge clk); rst_n=1;
    repeat (4) @(negedge tck); trst_n=1;
    repeat (4) @(negedge tck);
    if (!dut.tck_reset_released) $fatal(1, "TCK reset release did not complete");

    for (int n=0; n<transaction_count; n++) begin
      logic [479:0] scanned_response;
      current_payload = make_payload(n+1);
      expected_response = make_response(current_payload);
      submit_request(current_payload);
      begin : wait_response
        bit seen;
        seen=0;
        for (int k=0; k<2000; k++) begin
          @(negedge tck);
          if (dut.response_pending_tck_q) begin seen=1; break; end
        end
        if (!seen) $fatal(1, "response CDC timeout transaction=%0d", n);
      end
      #1;
      if (dut.rsp_hold_tck_q !== expected_response)
        $fatal(1, "response CDC payload mismatch transaction=%0d", n);
      consume_response(scanned_response);
      if (scanned_response !== expected_response)
        $fatal(1, "JTAG response scan mismatch transaction=%0d", n);
      begin : wait_idle
        bit idle;
        idle=0;
        for (int k=0; k<2000; k++) begin
          @(negedge tck);
          if (!dut.response_pending_tck_q &&
              dut.req_ack_sync2_tck_q == dut.req_toggle_tck_q &&
              !dut.busy_sync2_tck_q && !dut.done_sync2_tck_q &&
              !dut.error_sync2_tck_q && !dut.protocol_error_tck_q) begin
            idle=1; break;
          end
        end
        if (!idle) $fatal(1, "mailbox did not return idle transaction=%0d", n);
      end
    end
    $display("PASS_CDC_MAILBOX_PHASE_STRESS transactions=%0d sys_period_ps=%0d tck_period_ps=%0d phase_ps=%0d",
      transaction_count, 2*sys_half_ps, 2*tck_half_ps, tck_phase_ps);
    $finish;
  end
endmodule
