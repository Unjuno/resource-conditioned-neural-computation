// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_rtnn_c2_soc_42.h for the primary calling header

#ifndef VERILATED_VTB_RTNN_C2_SOC_42_IBEX_ID_STAGE__PI8_H_
#define VERILATED_VTB_RTNN_C2_SOC_42_IBEX_ID_STAGE__PI8_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_rtnn_c2_soc_42__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk_i,0,0);
        VL_IN8(rst_ni,0,0);
        VL_OUT8(ctrl_busy_o,0,0);
        VL_OUT8(illegal_insn_o,0,0);
        VL_IN8(instr_valid_i,0,0);
        VL_IN8(instr_is_compressed_i,0,0);
        VL_IN8(instr_gets_expanded_i,1,0);
        VL_IN8(instr_bp_taken_i,0,0);
        VL_OUT8(instr_req_o,0,0);
        VL_OUT8(instr_first_cycle_id_o,0,0);
        VL_OUT8(instr_valid_clear_o,0,0);
        VL_OUT8(id_in_ready_o,0,0);
        VL_IN8(instr_exec_i,0,0);
        VL_OUT8(icache_inval_o,0,0);
        VL_IN8(branch_decision_i,0,0);
        VL_OUT8(pc_set_o,0,0);
        VL_OUT8(pc_mux_o,2,0);
        VL_OUT8(nt_branch_mispredict_o,0,0);
        VL_OUT8(exc_pc_mux_o,1,0);
        VL_OUT8(exc_cause_o,6,0);
        VL_IN8(illegal_c_insn_i,0,0);
        VL_IN8(instr_fetch_err_i,0,0);
        VL_IN8(instr_fetch_err_plus2_i,0,0);
        VL_IN8(ex_valid_i,0,0);
        VL_IN8(lsu_resp_valid_i,0,0);
        VL_OUT8(alu_operator_ex_o,6,0);
        VL_IN8(imd_val_we_ex_i,1,0);
        VL_OUT8(mult_en_ex_o,0,0);
        VL_OUT8(div_en_ex_o,0,0);
        VL_OUT8(mult_sel_ex_o,0,0);
        VL_OUT8(div_sel_ex_o,0,0);
        VL_OUT8(multdiv_operator_ex_o,1,0);
        VL_OUT8(multdiv_signed_mode_ex_o,1,0);
        VL_OUT8(multdiv_ready_id_o,0,0);
        VL_OUT8(csr_access_o,0,0);
        VL_OUT8(csr_op_o,1,0);
        VL_OUT8(csr_op_en_o,0,0);
        VL_OUT8(csr_save_if_o,0,0);
        VL_OUT8(csr_save_id_o,0,0);
        VL_OUT8(csr_save_wb_o,0,0);
        VL_OUT8(csr_restore_mret_id_o,0,0);
        VL_OUT8(csr_restore_dret_id_o,0,0);
        VL_OUT8(csr_save_cause_o,0,0);
        VL_IN8(priv_mode_i,1,0);
        VL_IN8(csr_mstatus_tw_i,0,0);
        VL_IN8(illegal_csr_insn_i,0,0);
        VL_IN8(data_ind_timing_i,0,0);
        VL_OUT8(lsu_req_o,0,0);
        VL_OUT8(lsu_we_o,0,0);
        VL_OUT8(lsu_type_o,1,0);
        VL_OUT8(lsu_sign_ext_o,0,0);
        VL_IN8(lsu_req_done_i,0,0);
        VL_IN8(lsu_addr_incr_req_i,0,0);
        VL_IN8(csr_mstatus_mie_i,0,0);
        VL_IN8(irq_pending_i,0,0);
        VL_IN8(irq_nm_i,0,0);
        VL_OUT8(nmi_mode_o,0,0);
        VL_IN8(lsu_load_err_i,0,0);
        VL_IN8(lsu_load_resp_intg_err_i,0,0);
        VL_IN8(lsu_store_err_i,0,0);
        VL_IN8(lsu_store_resp_intg_err_i,0,0);
        VL_OUT8(expecting_load_resp_o,0,0);
        VL_OUT8(expecting_store_resp_o,0,0);
        VL_OUT8(debug_mode_o,0,0);
    };
    struct {
        VL_OUT8(debug_mode_entering_o,0,0);
        VL_OUT8(debug_cause_o,2,0);
        VL_OUT8(debug_csr_save_o,0,0);
        VL_IN8(debug_req_i,0,0);
        VL_IN8(debug_single_step_i,0,0);
        VL_IN8(debug_ebreakm_i,0,0);
        VL_IN8(debug_ebreaku_i,0,0);
        VL_IN8(trigger_match_i,0,0);
        VL_OUT8(rf_raddr_a_o,4,0);
        VL_OUT8(rf_raddr_b_o,4,0);
        VL_OUT8(rf_ren_a_o,0,0);
        VL_OUT8(rf_ren_b_o,0,0);
        VL_OUT8(rf_waddr_id_o,4,0);
        VL_OUT8(rf_we_id_o,0,0);
        VL_OUT8(__PVT__rf_rd_a_wb_match_o,0,0);
        VL_OUT8(__PVT__rf_rd_b_wb_match_o,0,0);
        VL_IN8(rf_waddr_wb_i,4,0);
        VL_IN8(rf_write_wb_i,0,0);
        VL_OUT8(en_wb_o,0,0);
        VL_OUT8(__PVT__instr_type_wb_o,1,0);
        VL_OUT8(instr_perf_count_id_o,0,0);
        VL_IN8(ready_wb_i,0,0);
        VL_IN8(outstanding_load_wb_i,0,0);
        VL_IN8(outstanding_store_wb_i,0,0);
        VL_OUT8(perf_jump_o,0,0);
        VL_OUT8(perf_branch_o,0,0);
        VL_OUT8(perf_tbranch_o,0,0);
        VL_OUT8(perf_dside_wait_o,0,0);
        VL_OUT8(perf_mul_wait_o,0,0);
        VL_OUT8(perf_div_wait_o,0,0);
        VL_OUT8(instr_id_done_o,0,0);
        CData/*0:0*/ __PVT__ebrk_insn;
        CData/*0:0*/ __PVT__mret_insn_dec;
        CData/*0:0*/ __PVT__dret_insn_dec;
        CData/*0:0*/ __PVT__ecall_insn_dec;
        CData/*0:0*/ __PVT__wfi_insn_dec;
        CData/*0:0*/ __PVT__branch_in_dec;
        CData/*0:0*/ __PVT__branch_set;
        CData/*0:0*/ __PVT__branch_set_raw_d;
        CData/*0:0*/ __PVT__branch_jump_set_done_q;
        CData/*0:0*/ __PVT__branch_jump_set_done_d;
        CData/*0:0*/ __PVT__jump_in_dec;
        CData/*0:0*/ __PVT__jump_set_dec;
        CData/*0:0*/ __PVT__jump_set;
        CData/*0:0*/ __PVT__jump_set_raw;
        CData/*0:0*/ __PVT__instr_executing_spec;
        CData/*0:0*/ __PVT__stall_multdiv;
        CData/*0:0*/ __PVT__stall_id;
        CData/*0:0*/ __PVT__multicycle_done;
        CData/*0:0*/ __PVT__rf_wdata_sel;
        CData/*6:0*/ __PVT__alu_operator;
        CData/*1:0*/ __PVT__alu_op_a_mux_sel;
        CData/*0:0*/ __PVT__alu_op_b_mux_sel_dec;
        CData/*0:0*/ __PVT__stall_alu;
        CData/*0:0*/ __PVT__imm_a_mux_sel;
        CData/*0:0*/ __PVT__mult_en_dec;
        CData/*0:0*/ __PVT__div_en_dec;
        CData/*0:0*/ __PVT__multdiv_en_dec;
        CData/*1:0*/ __PVT__multdiv_operator;
        CData/*1:0*/ __PVT__multdiv_signed_mode;
        CData/*0:0*/ __PVT__lsu_we;
        CData/*1:0*/ __PVT__lsu_type;
        CData/*0:0*/ __PVT__lsu_sign_ext;
        CData/*0:0*/ __PVT__lsu_req_dec;
    };
    struct {
        CData/*0:0*/ __PVT__id_fsm_q;
        CData/*0:0*/ __PVT__id_fsm_d;
        CData/*0:0*/ __PVT__g_branch_set_flop__DOT__branch_set_raw_q;
        CData/*0:0*/ __PVT__g_sec_branch_taken__DOT__branch_taken_q;
        CData/*0:0*/ __VdfgTmp_h50e2f79d__0;
        CData/*0:0*/ __VdfgTmp_hc09de8e0__0;
        CData/*0:0*/ __PVT__decoder_i__DOT__illegal_insn;
        CData/*0:0*/ __PVT__decoder_i__DOT__rf_we;
        CData/*3:0*/ __PVT__controller_i__DOT__ctrl_fsm_cs;
        CData/*3:0*/ __PVT__controller_i__DOT__ctrl_fsm_ns;
        CData/*0:0*/ __PVT__controller_i__DOT__nmi_mode_q;
        CData/*0:0*/ __PVT__controller_i__DOT__nmi_mode_d;
        CData/*0:0*/ __PVT__controller_i__DOT__debug_mode_q;
        CData/*0:0*/ __PVT__controller_i__DOT__debug_mode_d;
        CData/*2:0*/ __PVT__controller_i__DOT__debug_cause_q;
        CData/*0:0*/ __PVT__controller_i__DOT__load_err_q;
        CData/*0:0*/ __PVT__controller_i__DOT__store_err_q;
        CData/*0:0*/ __PVT__controller_i__DOT__exc_req_q;
        CData/*0:0*/ __PVT__controller_i__DOT__exc_req_d;
        CData/*0:0*/ __PVT__controller_i__DOT__illegal_insn_q;
        CData/*0:0*/ __PVT__controller_i__DOT__illegal_insn_d;
        CData/*0:0*/ __PVT__controller_i__DOT__instr_fetch_err_prio;
        CData/*0:0*/ __PVT__controller_i__DOT__illegal_insn_prio;
        CData/*0:0*/ __PVT__controller_i__DOT__ecall_insn_prio;
        CData/*0:0*/ __PVT__controller_i__DOT__ebrk_insn_prio;
        CData/*0:0*/ __PVT__controller_i__DOT__store_err_prio;
        CData/*0:0*/ __PVT__controller_i__DOT__load_err_prio;
        CData/*0:0*/ __PVT__controller_i__DOT__special_req;
        CData/*0:0*/ __PVT__controller_i__DOT__do_single_step_d;
        CData/*0:0*/ __PVT__controller_i__DOT__do_single_step_q;
        CData/*0:0*/ __PVT__controller_i__DOT__enter_debug_mode_prio_d;
        CData/*0:0*/ __PVT__controller_i__DOT__enter_debug_mode_prio_q;
        CData/*0:0*/ __PVT__controller_i__DOT__ebreak_into_debug;
        CData/*0:0*/ __PVT__controller_i__DOT__handle_irq;
        CData/*0:0*/ __PVT__controller_i__DOT__ecall_insn;
        CData/*0:0*/ __PVT__controller_i__DOT__mret_insn;
        CData/*0:0*/ __PVT__controller_i__DOT__dret_insn;
        CData/*0:0*/ __PVT__controller_i__DOT__wfi_insn;
        CData/*0:0*/ __PVT__controller_i__DOT__ebrk_insn;
        CData/*0:0*/ __PVT__controller_i__DOT__instr_fetch_err;
        CData/*0:0*/ __PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_pending_q;
        CData/*0:0*/ __PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_pending_d;
        CData/*0:0*/ __PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_set;
        CData/*0:0*/ __PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_clear;
        CData/*0:0*/ __VdfgTmp_h20a3cc49__0;
        VL_IN16(instr_rdata_c_i,15,0);
        VL_OUT16(csr_addr_o,11,0);
        VL_IN(instr_rdata_i,31,0);
        VL_IN(instr_rdata_alu_i,31,0);
        VL_OUT(__PVT__nt_branch_addr_o,31,0);
        VL_IN(pc_id_i,31,0);
        VL_OUT(alu_operand_a_ex_o,31,0);
        VL_OUT(alu_operand_b_ex_o,31,0);
        VL_INW(imd_val_d_ex_i,67,0,3);
        VL_OUTW(imd_val_q_ex_o,67,0,3);
        VL_OUT(__PVT__bt_a_operand_o,31,0);
        VL_OUT(__PVT__bt_b_operand_o,31,0);
        VL_OUT(multdiv_operand_a_ex_o,31,0);
        VL_OUT(multdiv_operand_b_ex_o,31,0);
        VL_OUT(csr_mtval_o,31,0);
        VL_OUT(lsu_wdata_o,31,0);
        VL_IN(lsu_addr_last_i,31,0);
        VL_IN(irqs_i,17,0);
        VL_IN(result_ex_i,31,0);
    };
    struct {
        VL_IN(csr_rdata_i,31,0);
        VL_IN(rf_rdata_a_i,31,0);
        VL_IN(rf_rdata_b_i,31,0);
        VL_OUT(rf_wdata_id_o,31,0);
        VL_IN(rf_wdata_fwd_wb_i,31,0);
        IData/*31:0*/ __PVT__imm_b;
        VlWide<3>/*67:0*/ __PVT__imd_val_q;
        IData/*31:0*/ __PVT__alu_operand_a;
        IData/*31:0*/ __PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_addr_q;
        IData/*31:0*/ __PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_addr_d;
    };

    // INTERNAL VARIABLES
    Vtb_rtnn_c2_soc_42__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8(Vtb_rtnn_c2_soc_42__Syms* symsp, const char* v__name);
    ~Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8();
    VL_UNCOPYABLE(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
