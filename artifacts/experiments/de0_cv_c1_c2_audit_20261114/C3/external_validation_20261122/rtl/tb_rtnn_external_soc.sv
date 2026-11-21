module tb_rtnn_external_soc;
`ifndef RTNN_C2_BUILD_ID
`define RTNN_C2_BUILD_ID 32'h4558_5631
`endif
  localparam integer NCASE=20;
  logic clk=0,tck=0,rst_n=0,trst_n=0,tdi=0,capture_dr=0,shift_dr=0,update_dr=0;
  logic [2:0] ir=0;
  logic tdo,request_valid,request_accept,response_commit,response_error,halted,bus_fault;
  logic [799:0] request_data,requests[0:NCASE-1];
  logic [479:0] response_data,got;
  logic [303:0] expected[0:NCASE-1];
  integer i;
  always #10 clk=~clk;
  always #7 tck=~tck;

  rtnn_c2_vjtag_mailbox u_mailbox(.tck_i(tck),.tdi_i(tdi),.tdo_o(tdo),.ir_i(ir),
    .capture_dr_i(capture_dr),.shift_dr_i(shift_dr),.update_dr_i(update_dr),.trst_ni(trst_n),
    .clk_i(clk),.rst_ni(rst_n),.request_valid_o(request_valid),.request_data_o(request_data),
    .request_accept_i(request_accept),.response_commit_i(response_commit),
    .response_data_i(response_data),.response_error_i(response_error));
  rtnn_de0_cv_soc_c2 u_soc(.clk_i(clk),.rst_ni(rst_n),.jtag_request_valid_i(request_valid),
    .jtag_request_data_i(request_data),.jtag_request_accept_o(request_accept),
    .jtag_response_commit_o(response_commit),.jtag_response_data_o(response_data),
    .jtag_response_error_o(response_error),.halted_o(halted),.bus_fault_o(bus_fault));

  task automatic tick_tck; @(posedge tck); #1; endtask
  task automatic scan_status(output logic[7:0] s);
    s=0; ir=3; capture_dr=1; tick_tck(); capture_dr=0;
    for(int b=0;b<8;b++) begin s[b]=tdo; shift_dr=1; tick_tck(); shift_dr=0; end
  endtask
  task automatic scan_request(input logic[799:0] q);
    ir=1; capture_dr=1; tick_tck(); capture_dr=0;
    for(int b=0;b<800;b++) begin tdi=q[b]; shift_dr=1; tick_tck(); shift_dr=0; end
    update_dr=1; tick_tck(); update_dr=0;
  endtask
  task automatic scan_response(output logic[479:0] q);
    q=0; ir=2; capture_dr=1; tick_tck(); capture_dr=0;
    for(int b=0;b<480;b++) begin q[b]=tdo; shift_dr=1; tick_tck(); shift_dr=0; end
    update_dr=1; tick_tck(); update_dr=0;
  endtask
  function automatic [31:0] crc32_56(input logic[447:0] bytes56);
    logic[31:0] c; logic[7:0] b;
    c=32'hffff_ffff;
    for(int n=0;n<56;n++) begin b=bytes56[n*8+:8]; c=c^{24'b0,b};
      for(int k=0;k<8;k++) c=c[0]?(c>>1)^32'hedb8_8320:c>>1;
    end return ~c;
  endfunction
  function automatic [31:0] crc32_28(input logic[223:0] bytes28);
    logic[31:0] c; logic[7:0] b;
    c=32'hffff_ffff;
    for(int n=0;n<28;n++) begin b=bytes28[n*8+:8]; c=c^{24'b0,b};
      for(int k=0;k<8;k++) c=c[0]?(c>>1)^32'hedb8_8320:c>>1;
    end return ~c;
  endfunction
  function automatic [31:0] crc32_64(input logic[511:0] bytes64);
    logic[31:0] c; logic[7:0] b;
    c=32'hffff_ffff;
    for(int n=0;n<64;n++) begin b=bytes64[n*8+:8]; c=c^{24'b0,b};
      for(int k=0;k<8;k++) c=c[0]?(c>>1)^32'hedb8_8320:c>>1;
    end return ~c;
  endfunction
  task automatic wait_done;
    logic[7:0] s; bit done; done=0;
    for(int n=0;n<1000000;n++) begin scan_status(s); if(s[7]) $fatal(1,"mailbox error status=%02x",s); if(s[6]&&!s[5]&&!s[4]) begin done=1;break;end end
    if(!done) $fatal(1,"response timeout status=%02x",s);
  endtask
  task automatic wait_done_allow_error;
    logic[7:0] s; bit done; done=0;
    for(int n=0;n<1000000;n++) begin
      scan_status(s);
      // Firmware-level rejection is returned in the response and also marks
      // the mailbox status ERROR. Negative tests must still collect that frame.
      if(s[6]&&!s[5]&&!s[4]) begin done=1;break;end
    end
    if(!done) $fatal(1,"negative response timeout status=%02x",s);
  endtask
  task automatic run_case(input integer n);
    logic[7:0] s; logic[31:0] seq,iid,mode,admit,executed,pred,label,crc,stop;
    logic[15:0] budget;
    seq=expected[n][0+:32]; iid=expected[n][32+:32]; mode=expected[n][64+:32];
    admit=expected[n][96+:32]; executed=expected[n][128+:32]; pred=expected[n][160+:32];
    label=expected[n][192+:32]; budget=expected[n][224+:16]; stop=expected[n][240+:8]; crc=expected[n][272+:32];
    scan_request(requests[n]); wait_done(); scan_response(got);
    if(got[31:0]!==32'h524e5452 || got[39:32]!==8'd3 || got[47:40]!==0) $fatal(1,"response magic/version/status case=%0d",n);
    if(got[55:48]!==mode[7:0] || got[63:56]!==stop[7:0] || got[95:64]!==seq || got[111:96]!==iid[15:0]) $fatal(1,"identity/mode case=%0d",n);
    if(got[127:112]!==budget || got[159:128]!==crc || got[167:160]!==admit[7:0] || got[175:168]!==executed[7:0]) $fatal(1,"payload/exit case=%0d",n);
    if(got[183:176]!==pred[7:0] || got[191:184]!==label[7:0] || got[191:184]!==8'hff) $fatal(1,"prediction/teacher-label isolation case=%0d",n);
    if(got[319:256]<=got[255:192] || got[351:320]!==32'h52544e4e || got[383:352]!==`RTNN_C2_BUILD_ID) $fatal(1,"counter/model/build case=%0d",n);
    if(got[415:384]!==32'h45585632 || got[447:416]!==32'd1 || got[479:448]!==crc32_56(got[447:0])) $fatal(1,"binding/flags/response CRC case=%0d",n);
    if(executed>admit || bus_fault || halted) $fatal(1,"cap/SoC fault case=%0d",n);
    $display("EXT_IMAGE_CASE_PASS index=%0d seq=%0d input=%0d mode=%0d prediction=%0d exit=%0d cycles=%0d",n,seq,iid,mode,pred,executed,got[319:256]-got[255:192]);
  endtask
  task automatic expect_error(input logic[799:0] q,input logic[7:0] stat,input string tag);
    scan_request(q); wait_done_allow_error(); scan_response(got);
    if(got[39:32]!==3 || got[47:40]!==stat || got[223:192]!==64'b0 || got[191:184]!==8'hff || got[479:448]!==crc32_56(got[447:0])) $fatal(1,"negative response %s",tag);
    if(bus_fault||halted) $fatal(1,"negative caused SoC fault %s",tag);
    $display("EXT_NEGATIVE_PASS %s",tag);
  endtask
  initial begin
    $readmemh("external_requests.hex",requests); $readmemh("external_expected.hex",expected);
    repeat(5) @(negedge clk); rst_n=1; trst_n=1; repeat(5) @(negedge clk);
    for(i=0;i<NCASE;i++) run_case(i);
    // Reset replay uses the same dynamic payload, and is separate from a power cycle.
    @(negedge clk); rst_n=0; trst_n=0; repeat(5) @(negedge clk); rst_n=1; trst_n=1; repeat(5) @(negedge clk); run_case(0);
    begin
      logic[799:0] q;
      q=requests[0]; q[28*8]=~q[28*8]; expect_error(q,8'd2,"bad_header_crc");
      q=requests[0]; q[8*8+:32]=32'd21; q[96*8]=~q[96*8]; q[28*8+:32]=crc32_28(q[223:0]); expect_error(q,8'd7,"bad_payload_crc");
      q=requests[0]; q[8*8+:32]=32'd22; q[32*8+:8]=8'd17; q[96*8+:32]=crc32_64(q[767:256]); q[28*8+:32]=crc32_28(q[223:0]); expect_error(q,8'd7,"pixel_range");
      q=requests[0]; q[8*8+:32]=32'd23; q[12*8+:16]=16'hffff; q[28*8+:32]=crc32_28(q[223:0]); expect_error(q,8'd4,"invalid_input_id");
      q=requests[0]; q[8*8+:32]=32'd24; q[20*8+:32]=32'hdead_beef; q[28*8+:32]=crc32_28(q[223:0]); expect_error(q,8'd3,"wrong_model_id");
      q=requests[0]; q[8*8+:32]=32'd25; q[24*8+:32]=32'hdead_beef; q[28*8+:32]=crc32_28(q[223:0]); expect_error(q,8'd3,"wrong_build_id");
      q=requests[0]; q[8*8+:32]=32'd22; q[28*8+:32]=crc32_28(q[223:0]); expect_error(q,8'd4,"duplicate_sequence");
      q=requests[0]; q[5*8+:8]=8'd1; q[6*8+:8]=8'd2; q[8*8+:32]=32'd26; q[28*8+:32]=crc32_28(q[223:0]);
      scan_request(q); repeat(100) @(negedge clk); @(negedge clk); rst_n=0; trst_n=0; repeat(5) @(negedge clk); rst_n=1; trst_n=1; repeat(5) @(negedge clk); run_case(0);
    end
    begin logic[7:0] s;
      ir=1; capture_dr=1; tick_tck(); capture_dr=0;
      for(int b=0;b<799;b++) begin tdi=1'b0; shift_dr=1; tick_tck(); shift_dr=0; end
      update_dr=1; tick_tck(); update_dr=0; scan_status(s);
      if(!s[7] || s[6]) $fatal(1,"short request was not rejected status=%02x",s);
      $display("EXT_NEGATIVE_PASS short_request_length");
    end
    $display("RTNN_EXTERNAL_DYNAMIC_INPUT_SOC_PASS cases=%0d reset_replay=PASS negatives=crc,pixel-range,input-id,model-id,build-id,duplicate-sequence,short-request,reset-interrupt",NCASE);
    $finish;
  end
endmodule
