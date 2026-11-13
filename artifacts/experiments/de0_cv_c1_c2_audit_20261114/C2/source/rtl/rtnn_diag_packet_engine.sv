// Diagnostic transport only: serializes the unchanged 32-byte RTNQ frame
// and collects the unchanged 48-byte RTNR response. No expected predictions.
module rtnn_diag_packet_engine #(
  parameter integer CLOCK_HZ = 50_000_000,
  parameter integer BAUD = 115_200,
  parameter integer TIMEOUT_CYCLES = 100_000_000
)(
  input logic clk_i, rst_ni,
  input logic start_i,
  input logic [255:0] request_i,
  output logic busy_o, done_o,
  output logic [1:0] error_o, // 1 timeout, 2 UART framing error
  output logic [383:0] response_o,
  output wire request_serial_o,
  input logic response_serial_i
);
  typedef enum logic [1:0] {IDLE, SEND, WAIT_TX, RECEIVE} state_t;
  state_t state_q;
  logic [255:0] request_q;
  logic [4:0] tx_index_q;
  logic [5:0] rx_index_q;
  logic [$clog2(TIMEOUT_CYCLES+1)-1:0] timeout_q;
  wire tx_ready, rx_valid, rx_framing;
  wire [7:0] rx_byte;
  wire tx_start = busy_o && state_q == SEND && tx_ready;
  rtnn_uart_tx #(.CLOCK_HZ(CLOCK_HZ), .BAUD(BAUD)) u_request_tx (
    .clk_i(clk_i), .rst_ni(rst_ni), .start_i(tx_start),
    .data_i(request_q[tx_index_q*8 +: 8]),
    .tx_o(request_serial_o), .ready_o(tx_ready)
  );
  rtnn_uart_rx #(.CLOCK_HZ(CLOCK_HZ), .BAUD(BAUD)) u_response_rx (
    .clk_i(clk_i), .rst_ni(rst_ni), .rx_i(response_serial_i),
    .byte_o(rx_byte), .valid_o(rx_valid), .framing_error_o(rx_framing)
  );
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      state_q <= IDLE;
      request_q <= '0;
      tx_index_q <= '0;
      rx_index_q <= '0;
      timeout_q <= '0;
      response_o <= '0;
      busy_o <= 1'b0;
      done_o <= 1'b0;
      error_o <= 2'd0;
    end else if (start_i && !busy_o) begin
      request_q <= request_i;
      tx_index_q <= '0;
      rx_index_q <= '0;
      timeout_q <= '0;
      response_o <= '0;
      busy_o <= 1'b1;
      done_o <= 1'b0;
      error_o <= 2'd0;
      state_q <= SEND;
    end else if (busy_o) begin
      if (rx_framing || timeout_q == $bits(timeout_q)'(TIMEOUT_CYCLES-1)) begin
        error_o <= rx_framing ? 2'd2 : 2'd1;
        busy_o <= 1'b0;
        done_o <= 1'b1;
        state_q <= IDLE;
      end else begin
        timeout_q <= timeout_q + 1'b1;
        case (state_q)
          SEND: if (tx_ready) state_q <= WAIT_TX;
          WAIT_TX: if (tx_ready) begin
            if (tx_index_q == 5'd31) state_q <= RECEIVE;
            else begin
              tx_index_q <= tx_index_q + 1'b1;
              state_q <= SEND;
            end
          end
          default: ;
        endcase
        if (rx_valid) begin
          response_o[rx_index_q*8 +: 8] <= rx_byte;
          if (rx_index_q == 6'd47) begin
            busy_o <= 1'b0;
            done_o <= 1'b1;
            state_q <= IDLE;
          end else rx_index_q <= rx_index_q + 1'b1;
        end
      end
    end
  end
endmodule
