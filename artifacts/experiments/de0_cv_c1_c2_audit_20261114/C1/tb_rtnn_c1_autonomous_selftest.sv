module tb_rtnn_c1_autonomous_selftest;
  logic clk=0,key_n=0;
  wire [3:0] ledr;
  always #10 clk=~clk;
  rtnn_de0_cv_selftest dut(.CLOCK_50(clk),.KEY(key_n),.LEDR(ledr));
  initial begin
    #60; key_n=1;
    wait(ledr[2] || ledr[3]); #10;
    if(ledr!==4'b1000) $fatal(1,"first selftest failed LED=%b cases=%0d",ledr,dut.case_q);
    if(dut.case_q!==5'd20 || dut.fail_q!==1'b0) $fatal(1,"first selftest incomplete cases=%0d LED=%b",dut.case_q,ledr);
    $display("C1_AUTONOMOUS_SELFTEST_PASS run=1 cases=%0d LEDR=%b",dut.case_q,ledr);
    @(negedge clk); key_n=0;
    repeat(8) @(negedge clk);
    #1;
    if(ledr!==4'b0000 || dut.case_q!==0 || dut.pass_q || dut.fail_q) $fatal(1,"reset did not clear state LED=%b cases=%0d",ledr,dut.case_q);
    key_n=1;
    wait(ledr[2] || ledr[3]); #10;
    if(ledr!==4'b1000) $fatal(1,"reset recovery selftest failed LED=%b cases=%0d",ledr,dut.case_q);
    if(dut.case_q!==5'd20 || dut.fail_q!==1'b0) $fatal(1,"reset recovery incomplete cases=%0d LED=%b",dut.case_q,ledr);
    $display("C1_AUTONOMOUS_SELFTEST_ALL_PASS runs=2 cases_per_run=20 reset_recovery=PASS LEDR=%b",ledr);
    $finish;
  end
  initial begin
    #(64'd20000000000);
    $fatal(1,"selftest watchdog LED=%b cases=%0d",ledr,dut.case_q);
  end
endmodule
