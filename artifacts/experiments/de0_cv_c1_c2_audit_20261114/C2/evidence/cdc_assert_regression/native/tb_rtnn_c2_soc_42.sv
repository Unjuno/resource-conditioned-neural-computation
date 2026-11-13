module tb_rtnn_c2_soc_42;
`ifndef RTNN_C2_BUILD_ID
`define RTNN_C2_BUILD_ID 32'h4332_4a31
`endif
  logic clk=0, tck=0, rst_n=0, trst_n=0;
  logic tdi=0, capture_dr=0, shift_dr=0, update_dr=0;
  logic [2:0] ir=0;
  logic tdo, request_valid, request_accept, response_commit, response_error;
  logic [799:0] request_data, requests [0:41];
  logic [383:0] response_data;
  logic [287:0] expected [0:41];
  logic halted, bus_fault;
  integer case_limit=42;
  integer i;

  // Simulation-only protocol checks for the asynchronous bundled-data paths.
  // They verify that payload storage stays unchanged until the receiving
  // domain has captured it; they do not replace STA delay bounds.
  logic req_toggle_guard=0, req_guard_active=0;
  logic [799:0] req_hold_guard=800'b0;
  logic rsp_sys_guard_active=0, rsp_tck_guard_active=0, rsp_pending_seen=0;
  logic [383:0] rsp_sys_guard=384'b0, rsp_tck_guard=384'b0;

  always #10 clk <= ~clk;   // simulated CLOCK_50, period 20 ns
  always #7 tck <= ~tck;

  rtnn_c2_vjtag_mailbox u_mailbox (
    .tck_i(tck), .tdi_i(tdi), .tdo_o(tdo), .ir_i(ir),
    .capture_dr_i(capture_dr), .shift_dr_i(shift_dr), .update_dr_i(update_dr),
    .trst_ni(trst_n), .clk_i(clk), .rst_ni(rst_n),
    .request_valid_o(request_valid), .request_data_o(request_data),
    .request_accept_i(request_accept), .response_commit_i(response_commit),
    .response_data_i(response_data), .response_error_i(response_error)
  );
  rtnn_de0_cv_soc_c2 u_soc (
    .clk_i(clk), .rst_ni(rst_n), .jtag_request_valid_i(request_valid),
    .jtag_request_data_i(request_data), .jtag_request_accept_o(request_accept),
    .jtag_response_commit_o(response_commit), .jtag_response_data_o(response_data),
    .jtag_response_error_o(response_error), .halted_o(halted), .bus_fault_o(bus_fault)
  );

  // TCK request data must remain stable from its publication toggle through
  // the synchronized acknowledgement from CLOCK_50.
  always @(posedge tck or negedge trst_n) begin
    if (!trst_n) begin
      req_toggle_guard <= 1'b0;
      req_guard_active <= 1'b0;
      req_hold_guard <= 800'b0;
    end else if (u_mailbox.req_toggle_tck_q != req_toggle_guard) begin
      req_toggle_guard <= u_mailbox.req_toggle_tck_q;
      req_hold_guard <= u_mailbox.req_hold_tck_q;
      req_guard_active <= 1'b1;
    end else if (req_guard_active) begin
      if (u_mailbox.req_hold_tck_q !== req_hold_guard)
        $fatal(1, "CDC request bundle changed before CLOCK_50 acknowledgement");
      if (u_mailbox.req_ack_sync2_tck_q == req_toggle_guard)
        req_guard_active <= 1'b0;
    end
  end

  // The SoC response snapshot must remain stable from COMMIT until the TCK
  // domain has captured it. The TCK-side check then covers the whole scan.
  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      rsp_sys_guard_active <= 1'b0;
      rsp_sys_guard <= 384'b0;
    end else if (response_commit) begin
      rsp_sys_guard <= response_data;
      rsp_sys_guard_active <= 1'b1;
    end else if (rsp_sys_guard_active) begin
      if (response_data !== rsp_sys_guard)
        $fatal(1, "CDC response bundle changed before TCK capture");
      if (u_mailbox.response_pending_tck_q)
        rsp_sys_guard_active <= 1'b0;
    end
  end

  always @(posedge tck or negedge trst_n) begin
    if (!trst_n) begin
      rsp_tck_guard_active <= 1'b0;
      rsp_pending_seen <= 1'b0;
      rsp_tck_guard <= 384'b0;
    end else if (u_mailbox.response_pending_tck_q && !rsp_pending_seen) begin
      rsp_tck_guard <= response_data;
      rsp_tck_guard_active <= 1'b1;
      rsp_pending_seen <= 1'b1;
    end else if (rsp_tck_guard_active) begin
      if (response_data !== rsp_tck_guard)
        $fatal(1, "CDC response bundle changed before JTAG response consumption");
      if (!u_mailbox.response_pending_tck_q) begin
        rsp_tck_guard_active <= 1'b0;
        rsp_pending_seen <= 1'b0;
      end
    end
  end

  // At the CLOCK_50 capture edge, the source request bundle must equal the
  // payload published by TCK. The source-side guard above proves it is held.
  always @(posedge clk) begin
    if (rst_n && (u_mailbox.req_sync2_sys_q != u_mailbox.req_seen_sys_q)) begin
      #1;
      if (request_data !== u_mailbox.req_hold_tck_q)
        $fatal(1, "CDC request bundle mismatch at CLOCK_50 capture");
    end
  end

  task automatic tick_tck;
    @(posedge tck); #1;
  endtask
  task automatic status_scan(output logic [7:0] value);
    value=0; ir=3'd3; capture_dr=1; tick_tck(); capture_dr=0;
    for (int b=0;b<8;b++) begin
      value[b]=tdo; shift_dr=1; tick_tck(); shift_dr=0;
    end
  endtask
  task automatic request_scan(input logic [799:0] payload);
    ir=3'd1; capture_dr=1; tick_tck(); capture_dr=0;
    for (int b=0;b<800;b++) begin
      tdi=payload[b]; shift_dr=1; tick_tck(); shift_dr=0;
    end
    update_dr=1; tick_tck(); update_dr=0;
  endtask
  task automatic response_scan_read(output logic [383:0] value);
    value=0; ir=3'd2; capture_dr=1; tick_tck(); capture_dr=0;
    for (int b=0;b<384;b++) begin
      value[b]=tdo; shift_dr=1; tick_tck(); shift_dr=0;
    end
    update_dr=1; tick_tck(); update_dr=0;
  endtask

  function automatic [31:0] crc32_44(input logic [351:0] prefix);
    logic [31:0] c;
    logic [7:0] by;
    c=32'hffff_ffff;
    for (int n=0;n<44;n++) begin
      by=prefix[n*8 +: 8]; c=c^{24'b0,by};
      for (int k=0;k<8;k++) c=(c[0] ? (c>>1)^32'hedb8_8320 : c>>1);
    end
    return ~c;
  endfunction

  function automatic [31:0] crc32_req_header(input logic [223:0] prefix);
    logic [31:0] c;
    logic [7:0] by;
    c=32'hffff_ffff;
    for (int n=0;n<28;n++) begin
      by=prefix[n*8 +: 8]; c=c^{24'b0,by};
      for (int k=0;k<8;k++) c=(c[0] ? (c>>1)^32'hedb8_8320 : c>>1);
    end
    return ~c;
  endfunction

  task automatic wait_for_ready;
    logic [7:0] s;
    bit ready;
    ready=0;
    for (int n=0;n<1000;n++) begin
      status_scan(s);
      if (s[3]) begin ready=1; break; end
    end
    if (!ready) $fatal(1,"JTAG mailbox READY/ERROR timeout status=%02x",s);
  endtask

  task automatic expect_error_request(input logic [799:0] payload,
                                      input logic [7:0] expected_status,
                                      input string tag);
    logic [7:0] s;
    logic [383:0] got;
    bit done;
    wait_for_ready();
    request_scan(payload);
    done=0;
    for (int n=0;n<100000;n++) begin
      status_scan(s);
      if (s[6]) begin done=1; break; end
    end
    if (!done) $fatal(1,"negative request completion timeout: %s status=%02x",tag,s);
    // Mailbox ERROR denotes scan/protocol faults. A well-formed SoC-level
    // rejection is carried by the response status byte and does not set it.
    response_scan_read(got);
    if (got[47:40] !== expected_status)
      $fatal(1,"negative response status %s got=%0d expected=%0d",tag,got[47:40],expected_status);
    if (got[223:192] !== 32'b0)
      $fatal(1,"negative request returned nonzero inference cycles: %s",tag);
    if (got[383:352] !== crc32_44(got[351:0]))
      $fatal(1,"negative response CRC mismatch: %s",tag);
    if (bus_fault || halted) $fatal(1,"negative request caused SoC fault/halt: %s",tag);
    $display("C2_SOC_NEGATIVE_PASS tag=%s response_status=%0d",tag,got[47:40]);
  endtask

  task automatic run_case(input integer index);
    logic [7:0] s;
    logic [383:0] got;
    logic done;
    logic [31:0] seq, mode, iid, admit, exec_exit, pred, label;
    logic [15:0] budget;
    logic [7:0] stop;
    seq=expected[index][0 +:32]; iid=expected[index][32 +:32];
    mode=expected[index][64 +:32]; admit=expected[index][96 +:32];
    exec_exit=expected[index][128 +:32]; pred=expected[index][160 +:32];
    label=expected[index][192 +:32]; budget=expected[index][224 +:16];
    stop=expected[index][256 +:8];
    wait_for_ready();
    request_scan(requests[index]);
    done=0;
    // Deep fixed/adaptive passes can exceed the admission/host polling cost.
    // This is a simulator safety timeout, not an expected inference cycle count.
    for (int n=0;n<1000000;n++) begin
      status_scan(s);
      if (s[7]) $fatal(1,"mailbox ERROR after case %0d status=%02x",index,s);
      if (s[6] && !s[5] && !s[4]) begin done=1; break; end
    end
    if (!done) $fatal(1,"SoC response timeout case=%0d status=%02x",index,s);
    response_scan_read(got);
    if (got[31:0] !== 32'h524e5452) $fatal(1,"RTNR magic case=%0d",index);
    if (got[39:32] !== 8'd1 || got[47:40] !== 8'd0) $fatal(1,"response version/status case=%0d",index);
    if (got[55:48] !== mode[7:0] || got[63:56] !== stop[7:0]) $fatal(1,"mode/stop mismatch case=%0d",index);
    if (got[95:64] !== seq || got[111:96] !== iid[15:0]) $fatal(1,"sequence/input mismatch case=%0d",index);
    if (got[127:112] !== budget[15:0]) $fatal(1,"budget mismatch case=%0d",index);
    if (got[167:160] !== admit[7:0] || got[175:168] !== exec_exit[7:0]) $fatal(1,"exit mismatch case=%0d",index);
    if (got[183:176] !== pred[7:0] || got[191:184] !== label[7:0]) $fatal(1,"prediction/label mismatch case=%0d",index);
    if (got[223:192] == 0) $fatal(1,"zero Q15 mcycle delta case=%0d",index);
    if (got[255:224] !== 32'h52544e4e || got[287:256] !== `RTNN_C2_BUILD_ID) $fatal(1,"model/build mismatch case=%0d",index);
    if (got[319:288] !== 32'b0 || got[351:320] !== 32'b0) $fatal(1,"unexpected binding/flags case=%0d",index);
    if (got[383:352] !== crc32_44(got[351:0])) $fatal(1,"response CRC mismatch case=%0d",index);
    if (exec_exit > admit) $fatal(1,"cap violation case=%0d",index);
    if (bus_fault || halted) $fatal(1,"SoC bus fault/halt case=%0d",index);
    $display("C2_SOC_CASE_PASS index=%0d seq=%0d input=%0d mode=%0d pred=%0d label=%0d admitted=%0d executed=%0d mcycle=%0d",
      index,seq,iid,mode,pred,label,admit,exec_exit,got[223:192]);
  endtask

  initial begin
    $readmemh("c2_requests.hex",requests);
    $readmemh("c2_expected.hex",expected);
    if ($value$plusargs("CASES=%d",case_limit)) begin end
    if (case_limit<1 || case_limit>42) $fatal(1,"CASES must be 1..42");
    repeat (5) @(negedge clk);
    rst_n=1; trst_n=1;
    repeat (5) @(negedge clk);
    for (i=0;i<case_limit;i++) run_case(i);
    // Reboot both clock domains, then repeat request 1 to prove state recovery.
    @(negedge clk); rst_n=0; trst_n=0;
    repeat (5) @(negedge clk);
    rst_n=1; trst_n=1;
    repeat (5) @(negedge clk);
    run_case(0);
    begin
      logic [799:0] bad_crc, bad_payload_crc, bad_input, bad_model, bad_build;
      bad_crc=requests[1];
      bad_crc[28*8] = ~bad_crc[28*8];
      expect_error_request(bad_crc,8'd2,"bad_frame_crc");
      expect_error_request(requests[0],8'd4,"duplicate_sequence");

      bad_payload_crc=requests[1];
      bad_payload_crc[8*8 +: 32]=32'd1000;
      bad_payload_crc[96*8]=~bad_payload_crc[96*8];
      bad_payload_crc[28*8 +: 32]=crc32_req_header(bad_payload_crc[223:0]);
      expect_error_request(bad_payload_crc,8'd4,"bad_payload_crc");

      bad_input=requests[1];
      bad_input[8*8 +: 32]=32'd1001;
      bad_input[12*8 +: 16]=16'hffff;
      bad_input[28*8 +: 32]=crc32_req_header(bad_input[223:0]);
      expect_error_request(bad_input,8'd4,"unknown_input_id");

      bad_model=requests[1];
      bad_model[8*8 +: 32]=32'd1002;
      bad_model[20*8 +: 32]=32'hdead_beef;
      bad_model[28*8 +: 32]=crc32_req_header(bad_model[223:0]);
      expect_error_request(bad_model,8'd3,"unknown_model_id");

      bad_build=requests[1];
      bad_build[8*8 +: 32]=32'd1003;
      bad_build[24*8 +: 32]=32'hdead_beef;
      bad_build[28*8 +: 32]=crc32_req_header(bad_build[223:0]);
      expect_error_request(bad_build,8'd3,"unknown_build_id");
    end
    // Reset while the CPU is busy on a long fixed-depth request. Reset both
    // clock domains together, then ensure READY and deterministic replay.
    wait_for_ready();
    request_scan(requests[41]);
    begin
      logic [7:0] s;
      bit observed_busy;
      observed_busy=0;
      for (int n=0;n<1000;n++) begin
        status_scan(s);
        if (s[5] || s[4]) begin observed_busy=1; break; end
      end
      if (!observed_busy) $fatal(1,"did not observe BUSY/PENDING before reset");
    end
    @(negedge clk); rst_n=0; trst_n=0;
    repeat (5) @(negedge clk);
    rst_n=1; trst_n=1;
    repeat (5) @(negedge clk);
    wait_for_ready();
    run_case(0);
    $display("C2_FIXED_IBEX_Q15_SOC_PASS cases=%0d reset_recovery=PASS negatives=bad_crc,duplicate,busy_reset,payload_crc,unknown_input,unknown_model,unknown_build",case_limit);
    $finish;
  end
endmodule
