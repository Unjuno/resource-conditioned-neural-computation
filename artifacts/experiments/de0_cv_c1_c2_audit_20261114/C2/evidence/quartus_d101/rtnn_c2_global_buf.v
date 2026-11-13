module rtnn_c2_global_buf(input wire clk_in, output wire clk_out);
  global u_global (.in(clk_in), .out(clk_out));
endmodule
