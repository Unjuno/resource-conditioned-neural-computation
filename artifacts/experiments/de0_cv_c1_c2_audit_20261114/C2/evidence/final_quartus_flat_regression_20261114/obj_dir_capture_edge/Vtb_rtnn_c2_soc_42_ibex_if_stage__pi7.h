// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_rtnn_c2_soc_42.h for the primary calling header

#ifndef VERILATED_VTB_RTNN_C2_SOC_42_IBEX_IF_STAGE__PI7_H_
#define VERILATED_VTB_RTNN_C2_SOC_42_IBEX_IF_STAGE__PI7_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_rtnn_c2_soc_42__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk_i,0,0);
        VL_IN8(rst_ni,0,0);
        VL_IN8(req_i,0,0);
        VL_OUT8(instr_req_o,0,0);
        VL_IN8(instr_gnt_i,0,0);
        VL_IN8(instr_rvalid_i,0,0);
        VL_IN8(instr_bus_err_i,0,0);
        VL_OUT8(instr_intg_err_o,0,0);
        VL_OUT8(__PVT__ic_tag_req_o,1,0);
        VL_OUT8(__PVT__ic_tag_write_o,0,0);
        VL_OUT8(__PVT__ic_tag_addr_o,7,0);
        VL_OUT8(__PVT__ic_data_req_o,1,0);
        VL_OUT8(__PVT__ic_data_write_o,0,0);
        VL_OUT8(__PVT__ic_data_addr_o,7,0);
        VL_IN8(ic_scr_key_valid_i,0,0);
        VL_OUT8(__PVT__ic_scr_key_req_o,0,0);
        VL_OUT8(instr_valid_id_o,0,0);
        VL_OUT8(instr_new_id_o,0,0);
        VL_OUT8(instr_is_compressed_id_o,0,0);
        VL_OUT8(instr_gets_expanded_id_o,1,0);
        VL_OUT8(__PVT__instr_bp_taken_o,0,0);
        VL_OUT8(instr_fetch_err_o,0,0);
        VL_OUT8(instr_fetch_err_plus2_o,0,0);
        VL_OUT8(illegal_c_insn_id_o,0,0);
        VL_OUT8(dummy_instr_id_o,0,0);
        VL_IN8(pmp_err_if_i,0,0);
        VL_IN8(pmp_err_if_plus2_i,0,0);
        VL_IN8(instr_valid_clear_i,0,0);
        VL_IN8(pc_set_i,0,0);
        VL_IN8(pc_mux_i,2,0);
        VL_IN8(nt_branch_mispredict_i,0,0);
        VL_IN8(exc_pc_mux_i,1,0);
        VL_IN8(exc_cause,6,0);
        VL_IN8(dummy_instr_en_i,0,0);
        VL_IN8(dummy_instr_mask_i,2,0);
        VL_IN8(dummy_instr_seed_en_i,0,0);
        VL_IN8(icache_enable_i,0,0);
        VL_IN8(icache_inval_i,0,0);
        VL_OUT8(__PVT__icache_ecc_error_o,0,0);
        VL_OUT8(csr_mtvec_init_o,0,0);
        VL_IN8(id_in_ready_i,0,0);
        VL_OUT8(pc_mismatch_alert_o,0,0);
        VL_OUT8(if_busy_o,0,0);
        CData/*0:0*/ __PVT__instr_valid_id_d;
        CData/*0:0*/ __PVT__instr_valid_id_q;
        CData/*0:0*/ __PVT__instr_new_id_d;
        CData/*0:0*/ __PVT__instr_err;
        CData/*0:0*/ __PVT__fetch_valid_raw;
        CData/*0:0*/ __PVT__fetch_err;
        CData/*0:0*/ __PVT__illegal_c_insn;
        CData/*1:0*/ __PVT__instr_gets_expanded;
        CData/*0:0*/ __Vcellinp__compressed_decoder_i__id_in_ready_i;
        CData/*0:0*/ __Vcellinp__compressed_decoder_i__valid_i;
        CData/*1:0*/ __PVT__g_mem_ecc__DOT__ecc_err;
        CData/*0:0*/ __PVT__gen_dummy_instr__DOT__insert_dummy_instr;
        CData/*4:0*/ __PVT__compressed_decoder_i__DOT__cm_rlist_d;
        CData/*4:0*/ __PVT__compressed_decoder_i__DOT__cm_rlist_q;
        CData/*4:0*/ __PVT__compressed_decoder_i__DOT__cm_sp_offset_d;
        CData/*4:0*/ __PVT__compressed_decoder_i__DOT__cm_sp_offset_q;
        CData/*2:0*/ __PVT__compressed_decoder_i__DOT__cm_state_d;
        CData/*2:0*/ __PVT__compressed_decoder_i__DOT__cm_state_q;
        CData/*6:0*/ __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o;
        CData/*0:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_req_q;
        CData/*0:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__discard_req_d;
    };
    struct {
        CData/*0:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__discard_req_q;
        CData/*1:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_n;
        CData/*1:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q;
        CData/*1:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_n;
        CData/*1:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_q;
        CData/*0:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid;
        CData/*0:0*/ gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_hfddf9e70__0;
        CData/*2:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_d;
        CData/*2:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q;
        CData/*2:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_d;
        CData/*2:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q;
        CData/*2:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__entry_en;
        CData/*0:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid;
        CData/*0:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__aligned_is_compressed;
        CData/*0:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two;
        CData/*0:0*/ gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_hd659ff45__0;
        CData/*0:0*/ gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h87841355__0;
        CData/*0:0*/ gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h46facb3b__0;
        CData/*0:0*/ gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h18c9f2e2__0;
        CData/*0:0*/ gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_haf2cbd5f__0;
        CData/*0:0*/ gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h0d767fd8__0;
        CData/*4:0*/ __PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_cnt_d;
        CData/*4:0*/ __PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_cnt_q;
        CData/*6:0*/ __PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_set;
        CData/*2:0*/ __PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_opcode;
        CData/*3:0*/ __Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__rlist;
        CData/*1:0*/ __Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__spimm;
        CData/*6:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj__4__Vfuncout;
        CData/*3:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj__4__rlist;
        CData/*1:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj__4__spimm;
        CData/*6:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__5__Vfuncout;
        CData/*3:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__5__rlist;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__rlist;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__sp_offset;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__Vfuncout;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_rlist_init__8__Vfuncout;
        CData/*3:0*/ __Vfunc_compressed_decoder_i__DOT__cm_rlist_init__8__instr_rlist;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_rlist_init__8__rlist;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__9__Vfuncout;
        CData/*3:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__9__rlist;
        CData/*1:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__9__spimm;
        CData/*6:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__9__tmp;
        CData/*6:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj__10__Vfuncout;
        CData/*3:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj__10__rlist;
        CData/*1:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj__10__spimm;
        CData/*6:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__11__Vfuncout;
        CData/*3:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__11__rlist;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__rlist;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__sp_offset;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__Vfuncout;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist;
        CData/*3:0*/ __Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__rlist;
        CData/*1:0*/ __Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__spimm;
        CData/*6:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj__18__Vfuncout;
        CData/*3:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj__18__rlist;
        CData/*1:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj__18__spimm;
        CData/*6:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__19__Vfuncout;
        CData/*3:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__19__rlist;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__rlist;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__sp_offset;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__Vfuncout;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_rlist_init__22__Vfuncout;
    };
    struct {
        CData/*3:0*/ __Vfunc_compressed_decoder_i__DOT__cm_rlist_init__22__instr_rlist;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_rlist_init__22__rlist;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__23__Vfuncout;
        CData/*3:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__23__rlist;
        CData/*1:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__23__spimm;
        CData/*6:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__23__tmp;
        CData/*6:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj__24__Vfuncout;
        CData/*3:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj__24__rlist;
        CData/*1:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj__24__spimm;
        CData/*6:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__25__Vfuncout;
        CData/*3:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__25__rlist;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__rlist;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__sp_offset;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__Vfuncout;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_rlist_init__28__Vfuncout;
        CData/*3:0*/ __Vfunc_compressed_decoder_i__DOT__cm_rlist_init__28__instr_rlist;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_rlist_init__28__rlist;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__29__rlist;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__Vfuncout;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__rlist;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__sp_offset;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__Vfuncout;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist;
        CData/*3:0*/ __Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__rlist;
        CData/*1:0*/ __Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__spimm;
        CData/*6:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj__34__Vfuncout;
        CData/*3:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj__34__rlist;
        CData/*1:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj__34__spimm;
        CData/*6:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__35__Vfuncout;
        CData/*3:0*/ __Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__35__rlist;
        CData/*2:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mvsa01__36__rs;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mvsa01__36__dst;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mv_reg__37__dst;
        CData/*2:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mvsa01__38__rs;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mvsa01__38__dst;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mv_reg__39__dst;
        CData/*2:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mva01s__40__rs;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mva01s__40__src;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mv_reg__41__src;
        CData/*2:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mva01s__42__rs;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mva01s__42__src;
        CData/*4:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mv_reg__43__src;
        VL_OUT16(instr_rdata_c_id_o,15,0);
        VL_OUT16(instr_expanded_id_o,15,0);
        SData/*11:0*/ __Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__imm;
        SData/*11:0*/ __Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__imm_signed;
        SData/*11:0*/ __Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__imm;
        SData/*11:0*/ __Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__imm_signed;
        SData/*11:0*/ __Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__neg_offset;
        SData/*11:0*/ __Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__neg_offset_signed;
        SData/*11:0*/ __Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__imm;
        SData/*11:0*/ __Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__imm_signed;
        VL_IN(boot_addr_i,31,0);
        VL_OUT(instr_addr_o,31,0);
        VL_OUT(__PVT__ic_tag_wdata_o,21,0);
        VL_INW(ic_data_rdata_i,127,0,4);
        VL_OUT(instr_rdata_id_o,31,0);
        VL_OUT(instr_rdata_alu_id_o,31,0);
        VL_OUT(pc_if_o,31,0);
        VL_OUT(pc_id_o,31,0);
        VL_IN(nt_branch_addr_i,31,0);
        VL_IN(dummy_instr_seed_i,31,0);
    };
    struct {
        VL_IN(branch_target_ex_i,31,0);
        VL_IN(csr_mepc_i,31,0);
        VL_IN(csr_depc_i,31,0);
        VL_IN(csr_mtvec_i,31,0);
        IData/*31:0*/ __PVT__prefetch_addr;
        IData/*31:0*/ __PVT__fetch_rdata;
        IData/*31:0*/ __PVT__instr_out;
        IData/*31:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_d;
        IData/*31:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_q;
        IData/*31:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fetch_addr_d;
        IData/*31:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fetch_addr_q;
        VlWide<3>/*95:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_d;
        VlWide<3>/*95:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q;
        IData/*30:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_d;
        IData/*30:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q;
        IData/*16:0*/ __PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_data;
        IData/*31:0*/ __PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_instr_seed_q;
        IData/*31:0*/ __PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_instr_seed_d;
        IData/*31:0*/ __PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_d;
        IData/*31:0*/ __PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__Vfuncout;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__instr;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__Vfuncout;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__instr;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__Vfuncout;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__instr;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__Vfuncout;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__instr;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__Vfuncout;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__instr;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__Vfuncout;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__instr;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__29__Vfuncout;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__29__instr;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__Vfuncout;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__instr;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__Vfuncout;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__instr;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mvsa01__36__Vfuncout;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mv_reg__37__Vfuncout;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mv_reg__37__instr;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mvsa01__38__Vfuncout;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mv_reg__39__Vfuncout;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mv_reg__39__instr;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mva01s__40__Vfuncout;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mv_reg__41__Vfuncout;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mv_reg__41__instr;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mva01s__42__Vfuncout;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mv_reg__43__Vfuncout;
        IData/*31:0*/ __Vfunc_compressed_decoder_i__DOT__cm_mv_reg__43__instr;
        VL_IN64(instr_rdata_i,38,0);
        VL_IN64(ic_tag_rdata_i,43,0);
        VL_OUT64(__PVT__ic_data_wdata_o,63,0);
    };

    // INTERNAL VARIABLES
    Vtb_rtnn_c2_soc_42__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7(Vtb_rtnn_c2_soc_42__Syms* symsp, const char* v__name);
    ~Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7();
    VL_UNCOPYABLE(Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
