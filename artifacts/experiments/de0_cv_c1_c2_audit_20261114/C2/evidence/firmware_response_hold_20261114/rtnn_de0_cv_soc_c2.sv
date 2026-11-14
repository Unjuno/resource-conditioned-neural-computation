// C2 SoC: pinned C1 Ibex + frozen image RAM + UART-free JTAG MMIO mailbox.
module rtnn_de0_cv_soc_c2 (
  input  logic         clk_i,
  input  logic         rst_ni,
  input  logic         jtag_request_valid_i,
  input  logic [799:0] jtag_request_data_i,
  output logic         jtag_request_accept_o,
  output logic         jtag_response_commit_o,
  output logic [383:0] jtag_response_data_o,
  output logic         jtag_response_error_o,
  output logic         halted_o,
  output logic         bus_fault_o
);
  logic instr_req, instr_gnt, instr_rvalid, instr_hit;
  logic [31:0] instr_addr, instr_rdata;
  logic [6:0] instr_rdata_intg;
  logic instr_err_q;
  logic data_req, data_gnt, data_rvalid, data_we;
  logic [3:0] data_be;
  logic [31:0] data_addr, data_wdata, data_rdata;
  logic [6:0] data_rdata_intg;
  logic data_err_q;
  logic ram_data_hit, ram_data_rvalid, ram_instr_rvalid;
  logic [31:0] ram_data_rdata;
  logic data_access_err, mmio_hit, mmio_read_valid, mmio_write_valid;
  logic accepted, ram_dreq, response_ram_q, response_valid_q;
  logic [31:0] mmio_read_data_q;
  logic [4:0] request_word_index;
  logic [3:0] response_word_index;
  logic [31:0] response_words_q [0:11];
  logic [47:0] response_byte_written_q;
  logic [31:0] response_commit_seq;
  logic [31:0] response_expected_seq;
  logic response_commit_match;
  prim_ram_1p_pkg::ram_1p_cfg_req_t [ibex_pkg::IC_NUM_WAYS-1:0] icache_tag_cfg;
  prim_ram_1p_pkg::ram_1p_cfg_req_t [ibex_pkg::IC_NUM_WAYS-1:0] icache_data_cfg;

  assign instr_gnt = instr_req;
  assign accepted = data_req && data_gnt;
  assign data_gnt = 1'b1;
  assign mmio_hit = ((data_addr & 32'hfffffc00) == 32'h00020000);
  assign mmio_read_valid = mmio_hit &&
       (data_addr[9:0] == 10'h020 ||
        (data_addr[9:0] >= 10'h024 && data_addr[9:0] <= 10'h084 && data_addr[1:0] == 0));
  assign mmio_write_valid = mmio_hit &&
       (data_addr[9:0] == 10'h088 ||
        (data_addr[9:0] >= 10'h08c && data_addr[9:0] <= 10'h0b8 && data_addr[1:0] == 0) ||
        data_addr[9:0] == 10'h0bc);
  assign data_access_err = !(ram_data_hit || mmio_read_valid || mmio_write_valid);
  assign ram_dreq = accepted && ram_data_hit;
  assign instr_rvalid = ram_instr_rvalid;
  assign request_word_index = data_addr[6:2] - 5'd9;
  assign response_word_index = data_addr[5:2] - 4'd3;
  assign response_commit_seq = response_words_q[2];
  assign response_expected_seq = jtag_request_data_i[64 +: 32];
  assign response_commit_match = (&response_byte_written_q) &&
                                 (data_wdata == response_expected_seq) &&
                                 (response_commit_seq == response_expected_seq);
  assign jtag_response_error_o = response_words_q[1][15:8] != 8'd0;
  // The diagnostic status output has no Ibex debug-halt source in this fixed
  // configuration. Keep it deterministic; do not infer a storage latch.
  assign halted_o = 1'b0;

  for (genvar r = 0; r < 12; r++) begin : gen_response_words
    assign jtag_response_data_o[r*32 +: 32] = response_words_q[r];
  end

  rtnn_de0_cv_ram u_ram (
    .clk_i(clk_i), .rst_ni(rst_ni),
    .data_req_i(ram_dreq), .data_we_i(data_we), .data_be_i(data_be),
    .data_addr_i(data_addr), .data_wdata_i(data_wdata),
    // Retain the explicit RAM valid wire: sv2v v0.0.13 fails on this module
    // when the output is left as an empty named connection.
    .data_hit_o(ram_data_hit), .data_rvalid_o(ram_data_rvalid), .data_rdata_o(ram_data_rdata),
    .instr_req_i(instr_req), .instr_addr_i(instr_addr), .instr_hit_o(instr_hit),
    .instr_rvalid_o(ram_instr_rvalid), .instr_rdata_o(instr_rdata)
  );

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) instr_err_q <= 1'b0;
    else instr_err_q <= instr_req && !instr_hit;
  end

  // The processor sees a one-cycle MMIO response. Every result word is staged
  // privately; only all 48 written byte lanes plus matching sequence can COMMIT.
  always_ff @(posedge clk_i or negedge rst_ni) begin : p_mailbox_mmio
    integer i;
    if (!rst_ni) begin
      response_ram_q <= 1'b0;
      response_valid_q <= 1'b0;
      data_err_q <= 1'b0;
      mmio_read_data_q <= 32'b0;
      response_byte_written_q <= 48'b0;
      jtag_request_accept_o <= 1'b0;
      jtag_response_commit_o <= 1'b0;
      bus_fault_o <= 1'b0;
      for (i=0;i<12;i=i+1) response_words_q[i] <= 32'b0;
    end else begin
      response_valid_q <= accepted;
      jtag_request_accept_o <= 1'b0;
      jtag_response_commit_o <= 1'b0;
      if (accepted) begin
        response_ram_q <= ram_data_hit;
        data_err_q <= data_access_err;
        if (data_access_err) bus_fault_o <= 1'b1;
        if (mmio_read_valid && !data_we) begin
          if (data_addr[9:0] == 10'h020)
            mmio_read_data_q <= {31'b0,jtag_request_valid_i};
          else begin
            mmio_read_data_q <= jtag_request_data_i[request_word_index*32 +: 32];
          end
        end else mmio_read_data_q <= 32'b0;

        if (mmio_write_valid && data_we) begin
          if (data_addr[9:0] == 10'h088 && data_be[0])
            jtag_request_accept_o <= 1'b1;
          else if (data_addr[9:0] >= 10'h08c && data_addr[9:0] <= 10'h0b8) begin
            for (integer b=0;b<4;b=b+1) begin
              if (data_be[b]) begin
                response_words_q[response_word_index][b*8 +: 8] <= data_wdata[b*8 +: 8];
                response_byte_written_q[response_word_index*4+b] <= 1'b1;
              end
            end
          end else if (data_addr[9:0] == 10'h0bc) begin
            if (response_commit_match) begin
              jtag_response_commit_o <= 1'b1;
              response_byte_written_q <= 48'b0;
            end else bus_fault_o <= 1'b1;
          end
        end
      end
      if (instr_req && !instr_hit) bus_fault_o <= 1'b1;
    end
  end
  assign data_rvalid = response_valid_q;
  assign data_rdata = response_ram_q ? ram_data_rdata : mmio_read_data_q;

  for (genvar cfg_way=0;cfg_way<ibex_pkg::IC_NUM_WAYS;cfg_way++) begin : gen_icache_cfg
    assign icache_tag_cfg[cfg_way]=prim_ram_1p_pkg::RAM_1P_CFG_REQ_DEFAULT;
    assign icache_data_cfg[cfg_way]=prim_ram_1p_pkg::RAM_1P_CFG_REQ_DEFAULT;
  end
  logic [31:0] unused_data_ecc, unused_instr_ecc;
  prim_secded_inv_39_32_enc u_data_secded (.data_i(data_rdata), .data_o({data_rdata_intg,unused_data_ecc}));
  prim_secded_inv_39_32_enc u_instr_secded (.data_i(instr_rdata), .data_o({instr_rdata_intg,unused_instr_ecc}));

  // Fixed C1 Ibex parameterization and canonical flat RTL; no CPU configuration changes.
  ibex_top #(
    .SecureIbex(1'b1), .RV32M(ibex_pkg::RV32MSingleCycle), .RV32B(ibex_pkg::RV32BNone),
    .RegFile(ibex_pkg::RegFileFF), .BranchTargetALU(1'b0), .WritebackStage(1'b0),
    .ICache(1'b0), .ICacheECC(1'b0), .BranchPredictor(1'b0),
    .PMPEnable(1'b0), .DbgTriggerEn(1'b0), .DmBaseAddr(32'h00100000),
    .DmAddrMask(32'h00000003), .DmHaltAddr(32'h00100000), .DmExceptionAddr(32'h00100000)
  ) u_ibex (
    .clk_i(clk_i), .rst_ni(rst_ni), .test_en_i(1'b0), .scan_rst_ni(1'b1),
    .ram_cfg_icache_tag_i(icache_tag_cfg), .ram_cfg_icache_tag_o(),
    .ram_cfg_icache_data_i(icache_data_cfg), .ram_cfg_icache_data_o(),
    .hart_id_i(32'b0), .boot_addr_i(32'h00100000), .trvk_heap_base_addr_i(32'b0),
    .instr_req_o(instr_req), .instr_gnt_i(instr_gnt), .instr_rvalid_i(instr_rvalid),
    .instr_addr_o(instr_addr), .instr_rdata_i(instr_rdata), .instr_rdata_intg_i(instr_rdata_intg), .instr_err_i(instr_err_q),
    .data_req_o(data_req), .data_gnt_i(data_gnt), .data_rvalid_i(data_rvalid),
    .data_we_o(data_we), .data_be_o(data_be), .data_addr_o(data_addr), .data_wdata_o(data_wdata),
    .data_wdata_intg_o(), .data_tag_o(), .data_rdata_i(data_rdata), .data_rdata_intg_i(data_rdata_intg),
    .data_tag_i(1'b0), .data_err_i(data_err_q), .trvk_revbm_req_o(), .trvk_revbm_gnt_i(1'b0),
    .trvk_revbm_rvalid_i(1'b0), .trvk_revbm_addr_o(), .trvk_revbm_rdata_i('0),
    .trvk_revbm_rdata_intg_i('0), .trvk_revbm_err_i(1'b0), .irq_software_i(1'b0),
    .irq_timer_i(1'b0), .irq_external_i(1'b0), .irq_fast_i(15'b0), .irq_nm_i(1'b0),
    .scramble_key_valid_i('0), .scramble_key_i('0), .scramble_nonce_i('0), .scramble_req_o(),
    .debug_req_i(1'b0), .crash_dump_o(), .double_fault_seen_o(), .fetch_enable_i(ibex_pkg::IbexMuBiOn),
    .mcounteren_writable_i(ibex_pkg::IbexMuBiOn), .alert_minor_o(), .alert_major_internal_o(),
    .alert_major_bus_o(), .core_sleep_o(), .lockstep_cmp_en_o(), .data_req_shadow_o(),
    .data_we_shadow_o(), .data_be_shadow_o(), .data_addr_shadow_o(), .data_wdata_shadow_o(),
    .data_wdata_intg_shadow_o(), .instr_req_shadow_o(), .instr_addr_shadow_o()
  );
endmodule
