module rtnn_c2_vjtag_mailbox (
	tck_i,
	tdi_i,
	tdo_o,
	ir_i,
	capture_dr_i,
	shift_dr_i,
	update_dr_i,
	trst_ni,
	clk_i,
	rst_ni,
	request_valid_o,
	request_data_o,
	request_accept_i,
	response_commit_i,
	response_data_i,
	response_error_i
);
	reg _sv2v_0;
	input wire tck_i;
	input wire tdi_i;
	output reg tdo_o;
	input wire [2:0] ir_i;
	input wire capture_dr_i;
	input wire shift_dr_i;
	input wire update_dr_i;
	input wire trst_ni;
	input wire clk_i;
	input wire rst_ni;
	output reg request_valid_o;
	output reg [799:0] request_data_o;
	input wire request_accept_i;
	input wire response_commit_i;
	input wire [383:0] response_data_i;
	input wire response_error_i;
	localparam [2:0] IR_REQUEST = 3'd1;
	localparam [2:0] IR_RESPONSE = 3'd2;
	localparam [2:0] IR_STATUS = 3'd3;
	localparam [2:0] IR_BUILD_ID = 3'd4;
	localparam [31:0] BUILD_ID = 32'h43324a31;
	reg [799:0] req_shift_tck_q;
	reg [799:0] req_hold_tck_q;
	reg [383:0] rsp_shift_tck_q;
	reg [383:0] rsp_hold_tck_q;
	reg [31:0] build_shift_tck_q;
	reg [7:0] status_shift_tck_q;
	reg [10:0] req_shift_count_tck_q;
	reg [1:0] tck_reset_release_q;
	wire tck_reset_released;
	reg req_toggle_tck_q;
	reg req_sync1_sys_q;
	reg req_sync2_sys_q;
	reg req_seen_sys_q;
	reg req_ack_toggle_sys_q;
	reg req_ack_sync1_tck_q;
	reg req_ack_sync2_tck_q;
	reg rsp_toggle_sys_q;
	reg rsp_sync1_tck_q;
	reg rsp_sync2_tck_q;
	reg rsp_seen_tck_q;
	reg rsp_consume_toggle_tck_q;
	reg rsp_consume_sync1_sys_q;
	reg rsp_consume_sync2_sys_q;
	reg busy_sys_q;
	reg error_sys_q;
	reg done_sys_q;
	reg busy_sync1_tck_q;
	reg busy_sync2_tck_q;
	reg error_sync1_tck_q;
	reg error_sync2_tck_q;
	reg done_sync1_tck_q;
	reg done_sync2_tck_q;
	reg pending_tck_q;
	reg response_pending_tck_q;
	reg protocol_error_tck_q;
	reg [10:0] rsp_shift_count_tck_q;
	always @(posedge tck_i or negedge trst_ni)
		if (!trst_ni)
			tck_reset_release_q <= 2'b00;
		else
			tck_reset_release_q <= {tck_reset_release_q[0], 1'b1};
	assign tck_reset_released = tck_reset_release_q[1];
	always @(*) begin
		if (_sv2v_0)
			;
		(* full_case, parallel_case *)
		case (ir_i)
			IR_REQUEST: tdo_o = req_shift_tck_q[0];
			IR_RESPONSE: tdo_o = rsp_shift_tck_q[0];
			IR_STATUS: tdo_o = status_shift_tck_q[0];
			IR_BUILD_ID: tdo_o = build_shift_tck_q[0];
			default: tdo_o = 1'b0;
		endcase
	end
	always @(posedge tck_i or negedge trst_ni)
		if (!trst_ni) begin
			req_shift_tck_q <= 800'b0;
			req_hold_tck_q <= 800'b0;
			rsp_shift_tck_q <= 384'b0;
			rsp_hold_tck_q <= 384'b0;
			build_shift_tck_q <= 32'b00000000000000000000000000000000;
			status_shift_tck_q <= 8'b00000000;
			req_shift_count_tck_q <= 11'b00000000000;
			rsp_shift_count_tck_q <= 11'b00000000000;
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
		end
		else if (!tck_reset_released) begin
			req_shift_tck_q <= 800'b0;
			req_hold_tck_q <= 800'b0;
			rsp_shift_tck_q <= 384'b0;
			rsp_hold_tck_q <= 384'b0;
			build_shift_tck_q <= 32'b00000000000000000000000000000000;
			status_shift_tck_q <= 8'b00000000;
			req_shift_count_tck_q <= 11'b00000000000;
			rsp_shift_count_tck_q <= 11'b00000000000;
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
		end
		else begin
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
			if (rsp_sync2_tck_q != rsp_seen_tck_q) begin
				rsp_hold_tck_q <= response_data_i;
				rsp_seen_tck_q <= rsp_sync2_tck_q;
				response_pending_tck_q <= 1'b1;
			end
			if (capture_dr_i)
				(* full_case, parallel_case *)
				case (ir_i)
					IR_REQUEST: begin
						req_shift_tck_q <= 800'b0;
						req_shift_count_tck_q <= 11'b00000000000;
					end
					IR_RESPONSE: begin
						rsp_shift_tck_q <= rsp_hold_tck_q;
						rsp_shift_count_tck_q <= 11'b00000000000;
					end
					IR_STATUS: status_shift_tck_q <= {error_sync2_tck_q | protocol_error_tck_q, done_sync2_tck_q, busy_sync2_tck_q, pending_tck_q, !(((((pending_tck_q || response_pending_tck_q) || busy_sync2_tck_q) || done_sync2_tck_q) || error_sync2_tck_q) || protocol_error_tck_q), 3'b000};
					IR_BUILD_ID: build_shift_tck_q <= BUILD_ID;
					default:
						;
				endcase
			if (shift_dr_i)
				(* full_case, parallel_case *)
				case (ir_i)
					IR_REQUEST: begin
						req_shift_tck_q <= {tdi_i, req_shift_tck_q[799:1]};
						if (req_shift_count_tck_q < 11'd801)
							req_shift_count_tck_q <= req_shift_count_tck_q + 1'b1;
					end
					IR_RESPONSE: begin
						rsp_shift_tck_q <= {1'b0, rsp_shift_tck_q[383:1]};
						if (rsp_shift_count_tck_q < 11'd385)
							rsp_shift_count_tck_q <= rsp_shift_count_tck_q + 1'b1;
					end
					IR_STATUS: status_shift_tck_q <= {1'b0, status_shift_tck_q[7:1]};
					IR_BUILD_ID: build_shift_tck_q <= {1'b0, build_shift_tck_q[31:1]};
					default:
						;
				endcase
			if (update_dr_i) begin
				if (ir_i == IR_REQUEST) begin
					if (((((((req_shift_count_tck_q == 11'd800) && !pending_tck_q) && !response_pending_tck_q) && !busy_sync2_tck_q) && !done_sync2_tck_q) && !error_sync2_tck_q) && !protocol_error_tck_q) begin
						req_hold_tck_q <= req_shift_tck_q;
						req_toggle_tck_q <= ~req_toggle_tck_q;
						pending_tck_q <= 1'b1;
					end
					else
						protocol_error_tck_q <= 1'b1;
					req_shift_count_tck_q <= 11'b00000000000;
				end
				else if (((ir_i == IR_RESPONSE) && (rsp_shift_count_tck_q == 11'd384)) && response_pending_tck_q) begin
					rsp_consume_toggle_tck_q <= ~rsp_consume_toggle_tck_q;
					response_pending_tck_q <= 1'b0;
				end
			end
		end
	always @(posedge clk_i or negedge rst_ni)
		if (!rst_ni) begin
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
		end
		else begin
			req_sync1_sys_q <= req_toggle_tck_q;
			req_sync2_sys_q <= req_sync1_sys_q;
			rsp_consume_sync1_sys_q <= rsp_consume_toggle_tck_q;
			rsp_consume_sync2_sys_q <= rsp_consume_sync1_sys_q;
			if (req_sync2_sys_q != req_seen_sys_q) begin
				request_data_o <= req_hold_tck_q;
				request_valid_o <= 1'b1;
				req_seen_sys_q <= req_sync2_sys_q;
				busy_sys_q <= 1'b1;
				done_sys_q <= 1'b0;
			end
			if (request_valid_o && request_accept_i) begin
				request_valid_o <= 1'b0;
				req_ack_toggle_sys_q <= req_seen_sys_q;
			end
			if (response_commit_i && busy_sys_q) begin
				rsp_toggle_sys_q <= ~rsp_toggle_sys_q;
				busy_sys_q <= 1'b0;
				done_sys_q <= 1'b1;
				error_sys_q <= response_error_i;
			end
			if ((rsp_consume_sync2_sys_q == rsp_toggle_sys_q) && done_sys_q) begin
				done_sys_q <= 1'b0;
				error_sys_q <= 1'b0;
			end
		end
	initial _sv2v_0 = 0;
endmodule
