module tb_rtnn_mailbox_commit_guard;
  logic clk=0,tck=0,rst_n=0,trst_n=0,tdi=0,capture_dr=0,shift_dr=0,update_dr=0;
  logic [2:0] ir=0;
  logic tdo,request_valid,request_accept=0,response_commit=0,response_error=0;
  logic [799:0] request_data;
  logic [479:0] response_data=480'b0,response_bits;
  logic [7:0] status_bits;
  logic [479:0] final_response=480'h123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef;
  always #10 clk=~clk;
  always #7 tck=~tck;
  rtnn_c2_vjtag_mailbox dut(.tck_i(tck),.tdi_i(tdi),.tdo_o(tdo),.ir_i(ir),
    .capture_dr_i(capture_dr),.shift_dr_i(shift_dr),.update_dr_i(update_dr),.trst_ni(trst_n),
    .clk_i(clk),.rst_ni(rst_n),.request_valid_o(request_valid),.request_data_o(request_data),
    .request_accept_i(request_accept),.response_commit_i(response_commit),
    .response_data_i(response_data),.response_error_i(response_error));
  task automatic tick_tck; @(posedge tck); #1; endtask
  task automatic read_status(output logic[7:0] s);
    s=0; ir=3; capture_dr=1; tick_tck(); capture_dr=0;
    for(int i=0;i<8;i++) begin s[i]=tdo; shift_dr=1; tick_tck(); shift_dr=0; end
  endtask
  task automatic send_req(input integer bits_to_shift);
    ir=1; capture_dr=1; tick_tck(); capture_dr=0;
    for(int i=0;i<bits_to_shift;i++) begin tdi=(i%3)==0; shift_dr=1; tick_tck(); shift_dr=0; end
    update_dr=1; tick_tck(); update_dr=0;
  endtask
  task automatic read_response(output logic[479:0] q, input bit do_update);
    q=0; ir=2; capture_dr=1; tick_tck(); capture_dr=0;
    for(int i=0;i<480;i++) begin q[i]=tdo; shift_dr=1; tick_tck(); shift_dr=0; end
    if(do_update) begin update_dr=1; tick_tck(); update_dr=0; end
  endtask
  initial begin
    repeat(5) @(negedge clk); rst_n=1; trst_n=1; repeat(5) @(negedge clk);
    send_req(800);
    for(int n=0;n<100;n++) begin @(negedge clk); if(request_valid) break; end
    if(!request_valid) $fatal(1,"request did not cross to system domain");
    @(negedge clk); request_accept=1; @(negedge clk); request_accept=0;
    repeat(8) @(negedge clk);

    // Simulate response words being written over time; without commit they
    // must not become a JTAG-visible response or set DONE.
    response_data[239:0]=240'h1234;
    repeat(8) @(negedge clk);
    response_data[479:240]=240'habcd;
    repeat(20) @(negedge clk);
    read_status(status_bits);
    if(status_bits[6] || !status_bits[5]) $fatal(1,"DONE asserted before response commit: %02x",status_bits);
    read_response(response_bits,0);
    if(response_bits!==480'b0) $fatal(1,"partial response leaked before commit");

    response_data=final_response;
    repeat(3) @(negedge clk);
    response_commit=1; @(negedge clk); response_commit=0;
    begin bit done; done=0;
      for(int n=0;n<10000;n++) begin read_status(status_bits); if(status_bits[6]) begin done=1;break;end end
      if(!done) $fatal(1,"response commit did not publish DONE");
    end
    read_response(response_bits,1);
    if(response_bits!==final_response) $fatal(1,"committed response mismatch");
    $display("MAILBOX_COMMIT_GUARD_PASS partial_data_hidden_until_commit");

    rst_n=0; trst_n=0; repeat(5) @(negedge clk); rst_n=1; trst_n=1; repeat(5) @(negedge clk);
    send_req(799);
    read_status(status_bits);
    if(!status_bits[7] || request_valid || status_bits[6]) $fatal(1,"short request was not rejected: %02x",status_bits);
    $display("MAILBOX_NEGATIVE_PASS short_request_length");
    $finish;
  end
endmodule
