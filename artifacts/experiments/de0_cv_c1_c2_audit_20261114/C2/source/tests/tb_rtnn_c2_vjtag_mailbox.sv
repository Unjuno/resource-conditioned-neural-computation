module tb_rtnn_c2_vjtag_mailbox;
  logic tck=0, tck_enable=1, clk=0, trst_n=0, rst_n=0, tdi=0;
  logic [2:0] ir=0;
  logic capture_dr=0, shift_dr=0, update_dr=0;
  logic tdo, request_valid, request_accept=0, response_commit=0, response_error=0;
  logic [799:0] request_data;
  logic [383:0] response_data='0;
  logic [799:0] request_payload;
  logic [383:0] response_payload;
  logic [383:0] observed_response;
  logic [7:0] status_payload;
  int unsigned i;

  always #5 clk <= ~clk;
  always #7 begin
    if (tck_enable) tck <= ~tck;
    else tck <= 1'b0;
  end

  rtnn_c2_vjtag_mailbox dut (
    .tck_i(tck), .tdi_i(tdi), .tdo_o(tdo), .ir_i(ir),
    .capture_dr_i(capture_dr), .shift_dr_i(shift_dr), .update_dr_i(update_dr),
    .trst_ni(trst_n), .clk_i(clk), .rst_ni(rst_n),
    .request_valid_o(request_valid), .request_data_o(request_data),
    .request_accept_i(request_accept), .response_commit_i(response_commit),
    .response_data_i(response_data), .response_error_i(response_error)
  );

  task automatic tck_tick;
    @(posedge tck); #1;
  endtask
  task automatic scan_request(input logic [799:0] payload, input int nbits);
    ir=3'd1; capture_dr=1; tck_tick(); capture_dr=0;
    for (int k=0;k<nbits;k++) begin
      tdi=payload[k]; shift_dr=1; tck_tick(); shift_dr=0;
    end
    update_dr=1; tck_tick(); update_dr=0;
  endtask
  task automatic scan_status(output logic [7:0] value);
    value='0; ir=3'd3; capture_dr=1; tck_tick(); capture_dr=0;
    for (int k=0;k<8;k++) begin
      value[k]=tdo; shift_dr=1; tck_tick(); shift_dr=0;
    end
  endtask
  task automatic scan_response(output logic [383:0] value);
    value='0; ir=3'd2; capture_dr=1; tck_tick(); capture_dr=0;
    for (int k=0;k<384;k++) begin
      value[k]=tdo; shift_dr=1; tck_tick(); shift_dr=0;
    end
    update_dr=1; tck_tick(); update_dr=0;
  endtask

  initial begin
    request_payload='0;
    for (i=0;i<800;i++) request_payload[i] = ((i*17+3)%11)<5;
    response_payload='0;
    for (i=0;i<384;i++) response_payload[i] = ((i*13+7)%17)<8;
    repeat (4) @(negedge clk);
    rst_n=1;
    if (dut.tck_reset_release_q !== 2'b00)
      $fatal(1,"TCK reset synchronizer did not remain asserted before release");
    trst_n=1;
    tck_tick();
    if (dut.tck_reset_release_q !== 2'b01)
      $fatal(1,"TCK reset released before the first synchronizer stage");
    tck_tick();
    if (dut.tck_reset_release_q !== 2'b11)
      $fatal(1,"TCK reset did not shift through two stages");
    tck_tick();
    repeat (2) @(negedge clk);
    scan_status(status_payload);
    if (!status_payload[3] || status_payload[7:4] !== 4'b0)
      $fatal(1,"mailbox did not report READY after reset");

    // An empty response scan must not pre-consume the first future response.
    scan_response(observed_response);
    if (observed_response !== 384'b0) $fatal(1,"empty response scan returned nonzero data");
    scan_status(status_payload);
    if (!status_payload[3] || status_payload[7:4] !== 4'b0)
      $fatal(1,"empty response scan changed mailbox state");

    // Exact-length request crosses TCK->CLOCK_50 and is held until accepted.
    scan_request(request_payload,800);
    wait(request_valid===1'b1);
    if (request_data !== request_payload) $fatal(1,"request CDC/data ordering mismatch");
    @(negedge clk); request_accept=1; @(negedge clk); request_accept=0;
    repeat (3) @(negedge clk);

    // Commit a complete response only after the mailbox has accepted a request.
    response_data=response_payload;
    response_commit=1; @(negedge clk); response_commit=0;
    repeat (4) @(negedge tck);
    scan_status(status_payload);
    if (!status_payload[6] || status_payload[7])
      $fatal(1,"early empty response scan consumed or corrupted the next DONE response");
    scan_response(observed_response);
    if (observed_response !== response_payload) $fatal(1,"response bit ordering/data mismatch");
    repeat (5) @(negedge clk);

    // A 799-bit scan must set sticky protocol ERROR and never reach CPU.
    scan_request(request_payload,799);
    scan_status(status_payload);
    if (!status_payload[7]) $fatal(1,"malformed request length did not set ERROR");
    if (status_payload[6:0] !== 7'b0) $fatal(1,"unexpected mailbox state after malformed request");
    if (request_valid) $fatal(1,"malformed request reached CPU mailbox");

    // Sticky ERROR must fail-stop the mailbox until reset; a later valid-size
    // frame cannot be forwarded merely because the bus is otherwise idle.
    scan_request(request_payload,800);
    repeat (5) @(negedge clk);
    if (request_valid) $fatal(1,"request was accepted while sticky ERROR was active");
    scan_status(status_payload);
    if (!status_payload[7] || status_payload[3])
      $fatal(1,"ERROR state did not remain fail-stopped");

    // Reset the interface while TCK is stopped. Release must remain asserted
    // until two TCK edges have passed, then the mailbox must return to READY.
    tck_enable=0;
    #1; trst_n=0; rst_n=0; #1;
    if (dut.tck_reset_release_q !== 2'b00 || dut.tck_reset_released !== 1'b0)
      $fatal(1,"asynchronous TCK reset assertion failed");
    trst_n=1;
    repeat (4) @(negedge clk);
    rst_n=1;
    repeat (4) @(negedge clk);
    if (dut.tck_reset_release_q !== 2'b00 || dut.tck_reset_released !== 1'b0)
      $fatal(1,"TCK reset released while the TCK clock was stopped");
    tck_enable=1;
    tck_tick();
    if (dut.tck_reset_release_q !== 2'b01 || dut.tck_reset_released !== 1'b0)
      $fatal(1,"TCK reset released after only one TCK edge");
    tck_tick();
    if (dut.tck_reset_release_q !== 2'b11 || dut.tck_reset_released !== 1'b1)
      $fatal(1,"TCK reset did not release after two synchronizer edges");
    tck_tick();
    scan_status(status_payload);
    if (!status_payload[3] || status_payload[7:4] !== 4'b0)
      $fatal(1,"mailbox did not return to READY after stopped-clock reset");

    $display("C2_VJTAG_MAILBOX_PASS empty_response_noop=1 exact_request=800 response=384 malformed=ERROR error_fail_stop=1 stopped_tck_reset=1");
    $finish;
  end
endmodule
