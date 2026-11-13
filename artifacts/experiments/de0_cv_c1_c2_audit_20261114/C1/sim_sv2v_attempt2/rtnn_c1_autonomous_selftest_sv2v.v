module rtnn_diag_packet_engine (
	clk_i,
	rst_ni,
	start_i,
	request_i,
	busy_o,
	done_o,
	error_o,
	response_o,
	request_serial_o,
	request_tx_active_o,
	response_serial_i
);
	parameter integer CLOCK_HZ = 50000000;
	parameter integer BAUD = 115200;
	parameter integer TIMEOUT_CYCLES = 100000000;
	input wire clk_i;
	input wire rst_ni;
	input wire start_i;
	input wire [255:0] request_i;
	output reg busy_o;
	output reg done_o;
	output reg [1:0] error_o;
	output reg [383:0] response_o;
	output wire request_serial_o;
	output wire request_tx_active_o;
	input wire response_serial_i;
	reg [1:0] state_q;
	assign request_tx_active_o = (state_q == 2'd1) || (state_q == 2'd2);
	reg [255:0] request_q;
	reg [4:0] tx_index_q;
	reg [5:0] rx_index_q;
	reg [$clog2(TIMEOUT_CYCLES + 1) - 1:0] timeout_q;
	wire tx_ready;
	wire rx_valid;
	wire rx_framing;
	wire [7:0] rx_byte;
	wire tx_start = (busy_o && (state_q == 2'd1)) && tx_ready;
	rtnn_uart_tx #(
		.CLOCK_HZ(CLOCK_HZ),
		.BAUD(BAUD)
	) u_request_tx(
		.clk_i(clk_i),
		.rst_ni(rst_ni),
		.start_i(tx_start),
		.data_i(request_q[tx_index_q * 8+:8]),
		.tx_o(request_serial_o),
		.ready_o(tx_ready)
	);
	rtnn_uart_rx #(
		.CLOCK_HZ(CLOCK_HZ),
		.BAUD(BAUD)
	) u_response_rx(
		.clk_i(clk_i),
		.rst_ni(rst_ni),
		.rx_i(response_serial_i),
		.byte_o(rx_byte),
		.valid_o(rx_valid),
		.framing_error_o(rx_framing)
	);
	function automatic signed [$clog2(TIMEOUT_CYCLES + 1) - 1:0] sv2v_cast_590F0_signed;
		input reg signed [$clog2(TIMEOUT_CYCLES + 1) - 1:0] inp;
		sv2v_cast_590F0_signed = inp;
	endfunction
	always @(posedge clk_i or negedge rst_ni)
		if (!rst_ni) begin
			state_q <= 2'd0;
			request_q <= 1'sb0;
			tx_index_q <= 1'sb0;
			rx_index_q <= 1'sb0;
			timeout_q <= 1'sb0;
			response_o <= 1'sb0;
			busy_o <= 1'b0;
			done_o <= 1'b0;
			error_o <= 2'd0;
		end
		else if (start_i && !busy_o) begin
			request_q <= request_i;
			tx_index_q <= 1'sb0;
			rx_index_q <= 1'sb0;
			timeout_q <= 1'sb0;
			response_o <= 1'sb0;
			busy_o <= 1'b1;
			done_o <= 1'b0;
			error_o <= 2'd0;
			state_q <= 2'd1;
		end
		else if (busy_o) begin
			if (((state_q == 2'd3) && rx_framing) || (timeout_q == sv2v_cast_590F0_signed(TIMEOUT_CYCLES - 1))) begin
				error_o <= ((state_q == 2'd3) && rx_framing ? 2'd2 : 2'd1);
				busy_o <= 1'b0;
				done_o <= 1'b1;
				state_q <= 2'd0;
			end
			else begin
				timeout_q <= timeout_q + 1'b1;
				case (state_q)
					2'd1:
						if (tx_ready)
							state_q <= 2'd2;
					2'd2:
						if (tx_ready) begin
							if (tx_index_q == 5'd31)
								state_q <= 2'd3;
							else begin
								tx_index_q <= tx_index_q + 1'b1;
								state_q <= 2'd1;
							end
						end
					default:
						;
				endcase
				if ((state_q == 2'd3) && rx_valid) begin
					response_o[rx_index_q * 8+:8] <= rx_byte;
					if (rx_index_q == 6'd47) begin
						busy_o <= 1'b0;
						done_o <= 1'b1;
						state_q <= 2'd0;
					end
					else
						rx_index_q <= rx_index_q + 1'b1;
				end
			end
		end
endmodule
module rtnn_c1_selftest_checker (
	done_i,
	transport_error_i,
	uart_idle_i,
	halted_i,
	bus_fault_i,
	reject_expected_i,
	seq_expected_i,
	input_id_expected_i,
	budget_expected_i,
	deadline_expected_i,
	status_expected_i,
	admitted_expected_i,
	executed_expected_i,
	prediction_expected_i,
	label_expected_i,
	stop_expected_i,
	flags_expected_i,
	response_i,
	valid_o
);
	reg _sv2v_0;
	input wire done_i;
	input wire [1:0] transport_error_i;
	input wire uart_idle_i;
	input wire halted_i;
	input wire bus_fault_i;
	input wire reject_expected_i;
	input wire [31:0] seq_expected_i;
	input wire [15:0] input_id_expected_i;
	input wire [15:0] budget_expected_i;
	input wire [31:0] deadline_expected_i;
	input wire [7:0] status_expected_i;
	input wire [7:0] admitted_expected_i;
	input wire [7:0] executed_expected_i;
	input wire [7:0] prediction_expected_i;
	input wire [7:0] label_expected_i;
	input wire [7:0] stop_expected_i;
	input wire [31:0] flags_expected_i;
	input wire [383:0] response_i;
	output reg valid_o;
	function automatic [31:0] crc32_44;
		input reg [351:0] data;
		reg [31:0] crc;
		reg [31:0] mask;
		begin
			crc = 32'hffffffff;
			begin : sv2v_autoblock_1
				reg signed [31:0] n;
				for (n = 0; n < 44; n = n + 1)
					begin
						crc = crc ^ {24'b000000000000000000000000, data[n * 8+:8]};
						begin : sv2v_autoblock_2
							reg signed [31:0] k;
							for (k = 0; k < 8; k = k + 1)
								begin
									mask = 32'h00000000 - (crc & 1);
									crc = (crc >> 1) ^ (32'hedb88320 & mask);
								end
						end
					end
			end
			crc32_44 = ~crc;
		end
	endfunction
	always @(*) begin
		if (_sv2v_0)
			;
		valid_o = 1'b0;
		if ((((((((((((((((((((((done_i && (transport_error_i == 2'b00)) && uart_idle_i) && !halted_i) && !bus_fault_i) && (response_i[31:0] == 32'h524e5452)) && (response_i[39:32] == 8'd1)) && (response_i[47:40] == status_expected_i)) && (response_i[55:48] == 8'd4)) && (response_i[63:56] == stop_expected_i)) && (response_i[95:64] == seq_expected_i)) && (response_i[111:96] == input_id_expected_i)) && (response_i[127:112] == budget_expected_i)) && (response_i[159:128] == deadline_expected_i)) && (response_i[167:160] == admitted_expected_i)) && (response_i[175:168] == executed_expected_i)) && (response_i[183:176] == prediction_expected_i)) && (response_i[191:184] == label_expected_i)) && (response_i[255:224] == 32'h52544e4e)) && (response_i[287:256] == 32'h44504331)) && (response_i[319:288] == 32'h79e4aef3)) && (response_i[351:320] == flags_expected_i)) && (response_i[383:352] == crc32_44(response_i[351:0]))) begin
			if (reject_expected_i)
				valid_o = response_i[223:192] == 32'd0;
			else
				valid_o = (response_i[223:192] != 32'd0) && (response_i[223:192] <= deadline_expected_i);
		end
	end
	initial _sv2v_0 = 0;
endmodule
module rtnn_de0_cv_selftest (
	CLOCK_50,
	KEY,
	LEDR
);
	input wire CLOCK_50;
	input wire [0:0] KEY;
	output wire [3:0] LEDR;
	localparam [223:0] DEADLINE = 224'h000061a80009a0d80012e3f0001c270800256638002ea950002ead38;
	localparam [31:0] BUILD_ID = 32'h44504331;
	reg [2:0] rst_pipe_q;
	wire sys_rst_n = rst_pipe_q[2];
	reg [4:0] case_q;
	reg [13:0] drain_count_q;
	reg [2:0] state_q;
	reg start_q;
	reg [255:0] request_q;
	reg [7:0] expected_status_q;
	reg [7:0] expected_admitted_q;
	reg [7:0] expected_executed_q;
	reg [7:0] expected_prediction_q;
	reg [7:0] expected_label_q;
	reg [7:0] expected_stop_q;
	reg [31:0] expected_seq_q;
	reg [31:0] expected_deadline_q;
	reg [15:0] expected_input_q;
	reg [15:0] expected_budget_q;
	reg reject_expected_q;
	reg pass_q;
	reg fail_q;
	wire soc_tx;
	wire uart_idle;
	wire halted;
	wire bus_fault;
	wire packet_busy;
	wire packet_done;
	wire [1:0] packet_error;
	wire [383:0] packet_response;
	wire checker_valid;
	localparam [2:0] ST_START = 3'd0;
	localparam [2:0] ST_CLEAR = 3'd1;
	localparam [2:0] ST_WAIT = 3'd2;
	localparam [2:0] ST_DRAIN = 3'd3;
	localparam [2:0] ST_CHECK = 3'd4;
	localparam [2:0] ST_DONE = 3'd5;
	localparam [2:0] ST_FAIL = 3'd6;
	always @(posedge CLOCK_50 or negedge KEY[0])
		if (!KEY[0])
			rst_pipe_q <= 3'b000;
		else
			rst_pipe_q <= {rst_pipe_q[1:0], 1'b1};
	function automatic [31:0] crc32_28;
		input reg [223:0] data;
		reg [31:0] c;
		reg [31:0] mask;
		begin
			c = 32'hffffffff;
			begin : sv2v_autoblock_1
				reg signed [31:0] n;
				for (n = 0; n < 28; n = n + 1)
					begin
						c = c ^ {24'b000000000000000000000000, data[n * 8+:8]};
						begin : sv2v_autoblock_2
							reg signed [31:0] k;
							for (k = 0; k < 8; k = k + 1)
								begin
									mask = 32'h00000000 - (c & 1);
									c = (c >> 1) ^ (32'hedb88320 & mask);
								end
						end
					end
			end
			crc32_28 = ~c;
		end
	endfunction
	function automatic [15:0] budget_for_cap;
		input reg [2:0] cap;
		case (cap)
			3'd0: budget_for_cap = 16'd0;
			3'd1: budget_for_cap = 16'd10923;
			3'd2: budget_for_cap = 16'd21845;
			3'd3: budget_for_cap = 16'd32768;
			3'd4: budget_for_cap = 16'd43690;
			3'd5: budget_for_cap = 16'd54613;
			default: budget_for_cap = 16'd65535;
		endcase
	endfunction
	task automatic build_case;
		input reg [4:0] index;
		reg [15:0] iid;
		reg [15:0] budget;
		reg [31:0] deadline;
		reg [31:0] seqno;
		reg [7:0] admitted;
		reg [7:0] executed;
		reg [7:0] prediction;
		reg [7:0] label_value;
		reg [7:0] stop_reason;
		reg [7:0] status;
		reg [2:0] cap;
		reg [2:0] allowed;
		reg [2:0] effective;
		reg reject_case;
		reg [255:0] req;
		begin
			iid = 16'd57;
			budget = 16'hffff;
			deadline = DEADLINE[(6 - (index <= 6 ? index : 6)) * 32+:32];
			seqno = {27'd0, index} + 32'd1;
			admitted = {3'd0, index};
			status = 0;
			reject_case = 0;
			cap = 3'd6;
			allowed = (index < 5'd6 ? index[2:0] : 3'd6);
			effective = (allowed < 3'd5 ? allowed : 3'd5);
			executed = (effective < 3'd5 ? {5'd0, effective} : 8'd5);
			prediction = (executed < 8'd2 ? 8'd1 : 8'd8);
			label_value = 8'd2;
			stop_reason = (executed < {5'd0, effective} ? 8'd1 : ((allowed < cap) && (effective == allowed) ? 8'd3 : 8'd2));
			if ((index >= 5'd7) && (index <= 5'd13)) begin
				cap = index[2:0] - 3'd7;
				budget = budget_for_cap(cap);
				deadline = DEADLINE[0+:32];
				admitted = 8'd6;
				allowed = (admitted < {5'd0, cap} ? admitted[2:0] : cap);
				effective = (allowed < 3'd5 ? allowed : 3'd5);
				executed = (effective < 3'd5 ? {5'd0, effective} : 8'd5);
				prediction = (executed < 8'd2 ? 8'd1 : 8'd8);
				stop_reason = (executed < {5'd0, effective} ? 8'd1 : ((allowed < cap) && (effective == allowed) ? 8'd3 : 8'd2));
			end
			if ((index == 5'd14) || (index == 5'd15)) begin
				iid = 16'd0;
				deadline = (index == 5'd14 ? 32'd0 : 32'd24999);
				admitted = 8'hff;
				executed = 8'hff;
				prediction = 8'hff;
				label_value = 8'hff;
				stop_reason = 0;
				status = 1;
				reject_case = 1;
			end
			if (index == 5'd16) begin
				iid = 16'd0;
				deadline = DEADLINE[0+:32];
				admitted = 8'd6;
				executed = 8'd1;
				prediction = 8'd3;
				label_value = 8'd3;
				stop_reason = 8'd1;
			end
			if ((index >= 5'd17) && (index <= 5'd19)) begin
				iid = 16'd57;
				budget = 16'hffff;
				deadline = (index == 5'd17 ? 32'd630999 : (index == 5'd18 ? 32'd631000 : 32'd631001));
				admitted = (index == 5'd17 ? 8'd0 : 8'd1);
				allowed = admitted[2:0];
				effective = allowed;
				executed = {5'd0, effective};
				prediction = (executed < 8'd2 ? 8'd1 : 8'd8);
				label_value = 8'd2;
				stop_reason = (executed < {5'd0, effective} ? 8'd1 : ((allowed < cap) && (effective == allowed) ? 8'd3 : 8'd2));
			end
			req = 1'sb0;
			req[31:0] = 32'h514e5452;
			req[39:32] = 8'd1;
			req[47:40] = 8'd4;
			req[95:64] = seqno;
			req[111:96] = iid;
			req[127:112] = budget;
			req[159:128] = deadline;
			req[191:160] = 32'h52544e4e;
			req[223:192] = BUILD_ID;
			req[255:224] = crc32_28(req[223:0]);
			request_q <= req;
			expected_seq_q <= seqno;
			expected_input_q <= iid;
			expected_budget_q <= budget;
			expected_deadline_q <= deadline;
			expected_status_q <= status;
			expected_admitted_q <= admitted;
			expected_executed_q <= executed;
			expected_prediction_q <= prediction;
			expected_label_q <= label_value;
			expected_stop_q <= stop_reason;
			reject_expected_q <= reject_case;
		end
	endtask
	wire req_active;
	wire req_tx;
	rtnn_diag_packet_engine #(
		.CLOCK_HZ(50000000),
		.BAUD(115200),
		.TIMEOUT_CYCLES(100000000)
	) u_packet(
		.clk_i(CLOCK_50),
		.rst_ni(sys_rst_n),
		.start_i(start_q),
		.request_i(request_q),
		.busy_o(packet_busy),
		.done_o(packet_done),
		.error_o(packet_error),
		.response_o(packet_response),
		.request_serial_o(req_tx),
		.request_tx_active_o(req_active),
		.response_serial_i(soc_tx)
	);
	rtnn_de0_cv_soc u_soc(
		.clk_i(CLOCK_50),
		.rst_ni(sys_rst_n),
		.uart_tx_o(soc_tx),
		.uart_rx_i(req_tx),
		.uart_idle_o(uart_idle),
		.halted_o(halted),
		.bus_fault_o(bus_fault)
	);
	rtnn_c1_selftest_checker u_checker(
		.done_i(packet_done),
		.transport_error_i(packet_error),
		.uart_idle_i(uart_idle),
		.halted_i(halted),
		.bus_fault_i(bus_fault),
		.reject_expected_i(reject_expected_q),
		.seq_expected_i(expected_seq_q),
		.input_id_expected_i(expected_input_q),
		.budget_expected_i(expected_budget_q),
		.deadline_expected_i(expected_deadline_q),
		.status_expected_i(expected_status_q),
		.admitted_expected_i(expected_admitted_q),
		.executed_expected_i(expected_executed_q),
		.prediction_expected_i(expected_prediction_q),
		.label_expected_i(expected_label_q),
		.stop_expected_i(expected_stop_q),
		.flags_expected_i(32'd0),
		.response_i(packet_response),
		.valid_o(checker_valid)
	);
	always @(posedge CLOCK_50 or negedge sys_rst_n)
		if (!sys_rst_n) begin
			state_q <= ST_START;
			case_q <= 0;
			drain_count_q <= 0;
			start_q <= 0;
			pass_q <= 0;
			fail_q <= 0;
			request_q <= 0;
			expected_seq_q <= 0;
			expected_input_q <= 0;
			expected_budget_q <= 0;
			expected_deadline_q <= 0;
			expected_status_q <= 0;
			expected_admitted_q <= 0;
			expected_executed_q <= 0;
			expected_prediction_q <= 0;
			expected_label_q <= 0;
			expected_stop_q <= 0;
			reject_expected_q <= 0;
		end
		else begin
			start_q <= 0;
			if (halted || bus_fault) begin
				pass_q <= 0;
				fail_q <= 1;
				state_q <= ST_FAIL;
			end
			else
				case (state_q)
					ST_START:
						if (case_q == 20) begin
							pass_q <= 1;
							state_q <= ST_DONE;
						end
						else begin
							build_case(case_q);
							start_q <= 1;
							state_q <= ST_CLEAR;
						end
					ST_CLEAR:
						if (!packet_done)
							state_q <= ST_WAIT;
					ST_WAIT:
						if (packet_done) begin
							drain_count_q <= 0;
							state_q <= ST_DRAIN;
						end
					ST_DRAIN:
						if (uart_idle)
							state_q <= ST_CHECK;
						else if (drain_count_q == 14'd9999) begin
							pass_q <= 0;
							fail_q <= 1;
							state_q <= ST_FAIL;
						end
						else
							drain_count_q <= drain_count_q + 1'b1;
					ST_CHECK:
						if ((checker_valid && uart_idle) && !packet_busy) begin
							case_q <= case_q + 1'b1;
							state_q <= ST_START;
						end
						else begin
							$display("SELFTEST_REJECT case=%0d err=%0d idle=%b halted=%b bus_fault=%b response=%h expected status=%0d admit=%0d exec=%0d pred=%0d label=%0d stop=%0d", case_q, packet_error, uart_idle, halted, bus_fault, packet_response, expected_status_q, expected_admitted_q, expected_executed_q, expected_prediction_q, expected_label_q, expected_stop_q);
							pass_q <= 0;
							fail_q <= 1;
							state_q <= ST_FAIL;
						end
					ST_DONE:
						;
					ST_FAIL:
						;
					default: begin
						pass_q <= 0;
						fail_q <= 1;
						state_q <= ST_FAIL;
					end
				endcase
		end
	assign LEDR = {pass_q, fail_q, case_q[1:0]};
endmodule
module tb_rtnn_c1_autonomous_selftest;
	reg clk = 0;
	reg key_n = 0;
	wire [3:0] ledr;
	always #(10) clk = ~clk;
	rtnn_de0_cv_selftest dut(
		.CLOCK_50(clk),
		.KEY(key_n),
		.LEDR(ledr)
	);
	initial begin
		#(60)
			;
		key_n = 1;
		wait (ledr[2] || ledr[3])
			;
		#(10)
			;
		if (ledr !== 4'b1000) begin
			$display("Fatal [%0t] tb_rtnn_c1_autonomous_selftest.sv:9:24 - tb_rtnn_c1_autonomous_selftest.<unnamed_block>.<unnamed_block>\n msg: ", $time, "first selftest failed LED=%b cases=%0d", ledr, dut.case_q);
			$finish(1);
		end
		if ((dut.case_q !== 5'd20) || (dut.fail_q !== 1'b0)) begin
			$display("Fatal [%0t] tb_rtnn_c1_autonomous_selftest.sv:10:49 - tb_rtnn_c1_autonomous_selftest.<unnamed_block>.<unnamed_block>\n msg: ", $time, "first selftest incomplete cases=%0d LED=%b", dut.case_q, ledr);
			$finish(1);
		end
		$display("C1_AUTONOMOUS_SELFTEST_PASS run=1 cases=%0d LEDR=%b", dut.case_q, ledr);
		@(negedge clk)
			;
		key_n = 0;
		repeat (8) @(negedge clk)
			;
		#(1)
			;
		if ((((ledr !== 4'b0000) || (dut.case_q !== 0)) || dut.pass_q) || dut.fail_q) begin
			$display("Fatal [%0t] tb_rtnn_c1_autonomous_selftest.sv:15:70 - tb_rtnn_c1_autonomous_selftest.<unnamed_block>.<unnamed_block>\n msg: ", $time, "reset did not clear state LED=%b cases=%0d", ledr, dut.case_q);
			$finish(1);
		end
		key_n = 1;
		wait (ledr[2] || ledr[3])
			;
		#(10)
			;
		if (ledr !== 4'b1000) begin
			$display("Fatal [%0t] tb_rtnn_c1_autonomous_selftest.sv:18:24 - tb_rtnn_c1_autonomous_selftest.<unnamed_block>.<unnamed_block>\n msg: ", $time, "reset recovery selftest failed LED=%b cases=%0d", ledr, dut.case_q);
			$finish(1);
		end
		if ((dut.case_q !== 5'd20) || (dut.fail_q !== 1'b0)) begin
			$display("Fatal [%0t] tb_rtnn_c1_autonomous_selftest.sv:19:49 - tb_rtnn_c1_autonomous_selftest.<unnamed_block>.<unnamed_block>\n msg: ", $time, "reset recovery incomplete cases=%0d LED=%b", dut.case_q, ledr);
			$finish(1);
		end
		$display("C1_AUTONOMOUS_SELFTEST_ALL_PASS runs=2 cases_per_run=20 reset_recovery=PASS LEDR=%b", ledr);
		$finish;
	end
	initial begin
		#(64'd20000000000)
			;
		$display("Fatal [%0t] tb_rtnn_c1_autonomous_selftest.sv:25:5 - tb_rtnn_c1_autonomous_selftest.<unnamed_block>.<unnamed_block>\n msg: ", $time, "selftest watchdog LED=%b cases=%0d", ledr, dut.case_q);
		$finish(1);
	end
endmodule
