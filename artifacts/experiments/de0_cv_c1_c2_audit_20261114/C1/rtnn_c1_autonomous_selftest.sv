module rtnn_de0_cv_selftest (
  input  wire       CLOCK_50,
  input  wire [0:0] KEY,
  output wire [3:0] LEDR
);
  localparam logic [31:0] DEADLINE [0:6] =
    '{32'd25000,32'd631000,32'd1238000,32'd1845000,32'd2451000,32'd3058000,32'd3059000};
  localparam logic [31:0] BUILD_ID = 32'h44504331;

  logic [2:0] rst_pipe_q;
  wire sys_rst_n = rst_pipe_q[2];
  logic [4:0] case_q;
  logic [13:0] drain_count_q;
  logic [2:0] state_q;
  logic start_q;
  logic [255:0] request_q;
  logic [7:0] expected_status_q, expected_admitted_q, expected_executed_q;
  logic [7:0] expected_prediction_q, expected_label_q, expected_stop_q;
  logic [31:0] expected_seq_q, expected_deadline_q;
  logic [15:0] expected_input_q, expected_budget_q;
  logic reject_expected_q;
  logic pass_q, fail_q;
  wire soc_tx, uart_idle, halted, bus_fault;
  wire packet_busy, packet_done;
  wire [1:0] packet_error;
  wire [383:0] packet_response;
  wire checker_valid;

  localparam logic [2:0] ST_START=3'd0, ST_CLEAR=3'd1, ST_WAIT=3'd2, ST_DRAIN=3'd3, ST_CHECK=3'd4, ST_DONE=3'd5, ST_FAIL=3'd6;

  always @(posedge CLOCK_50 or negedge KEY[0])
    if (!KEY[0]) rst_pipe_q <= 3'b000;
    else rst_pipe_q <= {rst_pipe_q[1:0],1'b1};

  function automatic [31:0] crc32_28(input logic [223:0] data);
    logic [31:0] c, mask;
    begin
      c=32'hffff_ffff;
      for(int n=0;n<28;n++) begin
        c=c^{24'b0,data[n*8+:8]};
        for(int k=0;k<8;k++) begin mask=32'h0-(c&1);c=(c>>1)^(32'hedb8_8320&mask);end
      end
      return ~c;
    end
  endfunction

  function automatic [15:0] budget_for_cap(input logic [2:0] cap);
    begin
      case (cap)
        3'd0: budget_for_cap=16'd0;
        3'd1: budget_for_cap=16'd10923;
        3'd2: budget_for_cap=16'd21845;
        3'd3: budget_for_cap=16'd32768;
        3'd4: budget_for_cap=16'd43690;
        3'd5: budget_for_cap=16'd54613;
        default: budget_for_cap=16'd65535;
      endcase
    end
  endfunction

  task automatic build_case(input logic [4:0] index);
    logic [15:0] iid,budget;
    logic [31:0] deadline,seqno;
    logic [7:0] admitted,executed,prediction,label_value,stop_reason,status;
    logic [2:0] cap,allowed,effective;
    logic reject_case;
    logic [255:0] req;
    begin
      iid=16'd57; budget=16'hffff; deadline=DEADLINE[(index<=6)?index:6]; seqno={27'd0,index}+32'd1;
      admitted={3'd0,index}; status=0; reject_case=0;
      cap=3'd6; allowed=(index<5'd6)?index[2:0]:3'd6;
      effective=(allowed<3'd5)?allowed:3'd5;
      executed=(effective<3'd5)?{5'd0,effective}:8'd5;
      prediction=(executed<8'd2)?8'd1:8'd8; label_value=8'd2;
      stop_reason=(executed<{5'd0,effective})?8'd1:((allowed<cap && effective==allowed)?8'd3:8'd2);
      if(index>=5'd7 && index<=5'd13) begin
        cap=index[2:0]-3'd7; budget=budget_for_cap(cap); deadline=DEADLINE[6]; admitted=8'd6;
        allowed=(admitted<{5'd0,cap})?admitted[2:0]:cap;
        effective=(allowed<3'd5)?allowed:3'd5;
        executed=(effective<3'd5)?{5'd0,effective}:8'd5;
        prediction=(executed<8'd2)?8'd1:8'd8;
        stop_reason=(executed<{5'd0,effective})?8'd1:((allowed<cap && effective==allowed)?8'd3:8'd2);
      end
      if(index==5'd14 || index==5'd15) begin
        iid=16'd0; deadline=(index==5'd14)?32'd0:32'd24999; admitted=8'hff; executed=8'hff;
        prediction=8'hff; label_value=8'hff; stop_reason=0; status=1; reject_case=1;
      end
      if(index==5'd16) begin
        iid=16'd0; deadline=DEADLINE[6]; admitted=8'd6; executed=8'd1;
        prediction=8'd3; label_value=8'd3; stop_reason=8'd1;
      end
      if(index>=5'd17 && index<=5'd19) begin
        iid=16'd57; budget=16'hffff;
        deadline=(index==5'd17)?32'd630999:(index==5'd18)?32'd631000:32'd631001;
        admitted=(index==5'd17)?8'd0:8'd1;
        allowed=admitted[2:0]; effective=allowed; executed={5'd0,effective};
        prediction=(executed<8'd2)?8'd1:8'd8; label_value=8'd2;
        stop_reason=(executed<{5'd0,effective})?8'd1:((allowed<cap && effective==allowed)?8'd3:8'd2);
      end
      req='0; req[31:0]=32'h514e_5452; req[39:32]=8'd1; req[47:40]=8'd4;
      req[95:64]=seqno; req[111:96]=iid; req[127:112]=budget; req[159:128]=deadline;
      req[191:160]=32'h5254_4e4e; req[223:192]=BUILD_ID;
      req[255:224]=crc32_28(req[223:0]);
      request_q<=req; expected_seq_q<=seqno; expected_input_q<=iid;
      expected_budget_q<=budget; expected_deadline_q<=deadline; expected_status_q<=status;
      expected_admitted_q<=admitted; expected_executed_q<=executed;
      expected_prediction_q<=prediction; expected_label_q<=label_value;
      expected_stop_q<=stop_reason; reject_expected_q<=reject_case;
    end
  endtask

  rtnn_diag_packet_engine #(.CLOCK_HZ(50_000_000),.BAUD(115_200),.TIMEOUT_CYCLES(100_000_000)) u_packet (
    .clk_i(CLOCK_50),.rst_ni(sys_rst_n),.start_i(start_q),.request_i(request_q),
    .busy_o(packet_busy),.done_o(packet_done),.error_o(packet_error),.response_o(packet_response),
    .request_serial_o(req_tx),.request_tx_active_o(req_active),.response_serial_i(soc_tx)
  );
  wire req_tx,req_active;
  rtnn_de0_cv_soc u_soc (
    .clk_i(CLOCK_50),.rst_ni(sys_rst_n),.uart_tx_o(soc_tx),
    .uart_rx_i(req_tx),.uart_idle_o(uart_idle),.halted_o(halted),.bus_fault_o(bus_fault)
  );
  rtnn_c1_selftest_checker u_checker (
    .done_i(packet_done),.transport_error_i(packet_error),.uart_idle_i(uart_idle),
    .halted_i(halted),.bus_fault_i(bus_fault),.reject_expected_i(reject_expected_q),
    .seq_expected_i(expected_seq_q),.input_id_expected_i(expected_input_q),
    .budget_expected_i(expected_budget_q),.deadline_expected_i(expected_deadline_q),
    .status_expected_i(expected_status_q),.admitted_expected_i(expected_admitted_q),
    .executed_expected_i(expected_executed_q),.prediction_expected_i(expected_prediction_q),
    .label_expected_i(expected_label_q),.stop_expected_i(expected_stop_q),
    .flags_expected_i(32'd0),.response_i(packet_response),.valid_o(checker_valid)
  );

  always @(posedge CLOCK_50 or negedge sys_rst_n) begin
    if(!sys_rst_n) begin
      state_q<=ST_START;case_q<=0;drain_count_q<=0;start_q<=0;pass_q<=0;fail_q<=0;
      request_q<=0;expected_seq_q<=0;expected_input_q<=0;expected_budget_q<=0;expected_deadline_q<=0;
      expected_status_q<=0;expected_admitted_q<=0;expected_executed_q<=0;
      expected_prediction_q<=0;expected_label_q<=0;expected_stop_q<=0;reject_expected_q<=0;
    end else begin
      start_q<=0;
      if(halted||bus_fault) begin pass_q<=0;fail_q<=1;state_q<=ST_FAIL;end
      else case(state_q)
        ST_START: begin
          if(case_q==20) begin pass_q<=1;state_q<=ST_DONE;end
          else begin build_case(case_q); start_q<=1; state_q<=ST_CLEAR; end
        end
        ST_CLEAR: if(!packet_done) state_q<=ST_WAIT;
        ST_WAIT: if(packet_done) begin drain_count_q<=0;state_q<=ST_DRAIN;end
        ST_DRAIN: if(uart_idle) state_q<=ST_CHECK;
                  else if(drain_count_q==14'd9999) begin pass_q<=0;fail_q<=1;state_q<=ST_FAIL;end
                  else drain_count_q<=drain_count_q+1'b1;
        ST_CHECK: begin
          if(checker_valid && uart_idle && !packet_busy) begin
            case_q<=case_q+1'b1;state_q<=ST_START;
          end else begin
            $display("SELFTEST_REJECT case=%0d err=%0d idle=%b halted=%b bus_fault=%b response=%h expected status=%0d admit=%0d exec=%0d pred=%0d label=%0d stop=%0d",case_q,packet_error,uart_idle,halted,bus_fault,packet_response,expected_status_q,expected_admitted_q,expected_executed_q,expected_prediction_q,expected_label_q,expected_stop_q);
            pass_q<=0;fail_q<=1;state_q<=ST_FAIL;
          end
        end
        ST_DONE: ;
        ST_FAIL: ;
        default: begin pass_q<=0;fail_q<=1;state_q<=ST_FAIL;end
      endcase
    end
  end
  assign LEDR={pass_q,fail_q,case_q[1:0]};
endmodule

