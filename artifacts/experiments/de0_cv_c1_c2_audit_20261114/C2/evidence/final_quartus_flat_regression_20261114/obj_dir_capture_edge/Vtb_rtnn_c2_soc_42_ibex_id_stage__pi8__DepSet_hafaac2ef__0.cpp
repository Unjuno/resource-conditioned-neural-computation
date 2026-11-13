// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rtnn_c2_soc_42.h for the primary calling header

#include "Vtb_rtnn_c2_soc_42__pch.h"
#include "Vtb_rtnn_c2_soc_42__Syms.h"
#include "Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8.h"

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__0(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__0\n"); );
    // Body
    vlSelf->csr_op_en_o = ((IData)(vlSelf->csr_access_o) 
                           & ((IData)(vlSelf->__PVT__instr_executing_spec) 
                              & (IData)(vlSelf->en_wb_o)));
    vlSelf->__PVT__controller_i__DOT__special_req = 
        ((IData)(vlSelf->__PVT__controller_i__DOT__mret_insn) 
         | ((IData)(vlSelf->__PVT__controller_i__DOT__dret_insn) 
            | ((IData)(vlSelf->__PVT__controller_i__DOT__exc_req_d) 
               | ((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_load_err) 
                  | ((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_store_err) 
                     | ((IData)(vlSelf->__PVT__controller_i__DOT__wfi_insn) 
                        | (((IData)(vlSelf->csr_op_en_o) 
                            & ((~ ((0x340U == (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                               >> 0x14U)) 
                                   | (0x341U == (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                 >> 0x14U)))) 
                               & (IData)(vlSelf->__VdfgTmp_hc09de8e0__0))) 
                           & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__PVT__instr_valid_id_q))))))));
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__2(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__2\n"); );
    // Init
    CData/*0:0*/ __PVT__stall_branch;
    __PVT__stall_branch = 0;
    CData/*0:0*/ __PVT__stall_jump;
    __PVT__stall_jump = 0;
    // Body
    vlSelf->__PVT__multicycle_done = ((IData)(vlSelf->__PVT__lsu_req_dec)
                                       ? (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_resp_valid)
                                       : (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_valid));
    __PVT__stall_jump = 0U;
    __PVT__stall_branch = 0U;
    vlSelf->__PVT__stall_multdiv = 0U;
    if (vlSelf->__PVT__instr_executing_spec) {
        if (vlSelf->__PVT__id_fsm_q) {
            if (vlSelf->__PVT__id_fsm_q) {
                if ((1U & (~ (IData)(vlSelf->__PVT__multicycle_done)))) {
                    __PVT__stall_jump = vlSelf->__PVT__jump_in_dec;
                    __PVT__stall_branch = vlSelf->__PVT__branch_in_dec;
                    vlSelf->__PVT__stall_multdiv = vlSelf->__PVT__multdiv_en_dec;
                }
            }
        } else if ((1U & (~ (IData)(vlSelf->__PVT__lsu_req_dec)))) {
            if ((1U & (~ (IData)(vlSelf->__PVT__multdiv_en_dec)))) {
                if ((1U & (~ (IData)(vlSelf->__PVT__branch_in_dec)))) {
                    if (vlSelf->__PVT__jump_in_dec) {
                        __PVT__stall_jump = 1U;
                    }
                }
                if (vlSelf->__PVT__branch_in_dec) {
                    __PVT__stall_branch = (1U & ((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result) 
                                                 | ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
                                                    >> 1U)));
                }
            }
            if (vlSelf->__PVT__multdiv_en_dec) {
                if ((1U & (~ (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_valid)))) {
                    vlSelf->__PVT__stall_multdiv = 1U;
                }
            }
        }
    }
    vlSelf->__PVT__stall_id = (((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__PVT__instr_valid_id_q) 
                                & ((IData)(vlSelf->__PVT__lsu_req_dec) 
                                   & ((~ (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_resp_valid)) 
                                      | (IData)(vlSelf->instr_first_cycle_id_o)))) 
                               | ((IData)(vlSelf->__PVT__stall_multdiv) 
                                  | ((IData)(__PVT__stall_jump) 
                                     | ((IData)(vlSelf->__PVT__stall_alu) 
                                        | (IData)(__PVT__stall_branch)))));
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__0(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__0\n"); );
    // Init
    CData/*0:0*/ ctrl_busy_o;
    ctrl_busy_o = 0;
    CData/*0:0*/ debug_mode_entering_o;
    debug_mode_entering_o = 0;
    CData/*0:0*/ __PVT__controller_run;
    __PVT__controller_run = 0;
    CData/*0:0*/ __PVT__rf_we_raw;
    __PVT__rf_we_raw = 0;
    CData/*0:0*/ __PVT__controller_i__DOT__halt_if;
    __PVT__controller_i__DOT__halt_if = 0;
    CData/*0:0*/ __PVT__controller_i__DOT__retain_id;
    __PVT__controller_i__DOT__retain_id = 0;
    CData/*0:0*/ __PVT__controller_i__DOT__flush_id;
    __PVT__controller_i__DOT__flush_id = 0;
    // Body
    vlSelf->instr_req_o = 1U;
    vlSelf->csr_save_if_o = 0U;
    vlSelf->csr_save_id_o = 0U;
    vlSelf->csr_restore_mret_id_o = 0U;
    vlSelf->csr_restore_dret_id_o = 0U;
    vlSelf->csr_save_cause_o = 0U;
    vlSelf->csr_mtval_o = 0U;
    vlSelf->pc_mux_o = 0U;
    vlSelf->pc_set_o = 0U;
    vlSelf->exc_pc_mux_o = 1U;
    vlSelf->exc_cause_o = 0U;
    vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs;
    ctrl_busy_o = 1U;
    __PVT__controller_i__DOT__halt_if = 0U;
    __PVT__controller_i__DOT__retain_id = 0U;
    __PVT__controller_i__DOT__flush_id = 0U;
    vlSelf->debug_csr_save_o = 0U;
    vlSelf->__PVT__controller_i__DOT__debug_mode_d 
        = vlSelf->__PVT__controller_i__DOT__debug_mode_q;
    debug_mode_entering_o = 0U;
    vlSelf->__PVT__controller_i__DOT__nmi_mode_d = vlSelf->__PVT__controller_i__DOT__nmi_mode_q;
    vlSelf->perf_tbranch_o = 0U;
    vlSelf->perf_jump_o = 0U;
    __PVT__controller_run = 0U;
    if ((8U & (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs))) {
        if ((4U & (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs))) {
            vlSelf->instr_req_o = 0U;
            vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 0U;
        } else if ((2U & (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs))) {
            vlSelf->instr_req_o = 0U;
            vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 0U;
        } else if ((1U & (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs))) {
            __PVT__controller_i__DOT__flush_id = 1U;
            vlSelf->pc_mux_o = 2U;
            vlSelf->pc_set_o = 1U;
            vlSelf->exc_pc_mux_o = 2U;
            if (((IData)(vlSelf->__PVT__controller_i__DOT__ebreak_into_debug) 
                 & (~ (IData)(vlSelf->__PVT__controller_i__DOT__debug_mode_q)))) {
                vlSelf->csr_save_cause_o = 1U;
                vlSelf->csr_save_id_o = 1U;
                vlSelf->debug_csr_save_o = 1U;
            }
            vlSelf->__PVT__controller_i__DOT__debug_mode_d = 1U;
            debug_mode_entering_o = 1U;
            vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 5U;
        } else {
            vlSelf->pc_mux_o = 2U;
            vlSelf->exc_pc_mux_o = 2U;
            __PVT__controller_i__DOT__flush_id = 1U;
            vlSelf->pc_set_o = 1U;
            vlSelf->csr_save_if_o = 1U;
            vlSelf->debug_csr_save_o = 1U;
            vlSelf->csr_save_cause_o = 1U;
            vlSelf->__PVT__controller_i__DOT__debug_mode_d = 1U;
            debug_mode_entering_o = 1U;
            vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 5U;
        }
    } else if ((4U & (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs))) {
        if ((2U & (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs))) {
            if ((1U & (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs))) {
                vlSelf->pc_mux_o = 2U;
                vlSelf->exc_pc_mux_o = 1U;
                if (vlSelf->__PVT__controller_i__DOT__handle_irq) {
                    vlSelf->pc_set_o = 1U;
                    vlSelf->csr_save_if_o = 1U;
                    vlSelf->csr_save_cause_o = 1U;
                    if (((IData)(vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_pending_q) 
                         & (~ (IData)(vlSelf->__PVT__controller_i__DOT__nmi_mode_q)))) {
                        vlSelf->exc_cause_o = 0x40U;
                        if (vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_pending_q) {
                            vlSelf->csr_mtval_o = vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_addr_q;
                        }
                        vlSelf->__PVT__controller_i__DOT__nmi_mode_d = 1U;
                    } else {
                        vlSelf->exc_cause_o = 0x27U;
                    }
                }
                vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 5U;
            } else {
                __PVT__controller_i__DOT__halt_if = 1U;
                __PVT__controller_i__DOT__flush_id = 1U;
                vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 5U;
                if ((((IData)(vlSelf->__PVT__controller_i__DOT__exc_req_q) 
                      | (IData)(vlSelf->__PVT__controller_i__DOT__store_err_q)) 
                     | (IData)(vlSelf->__PVT__controller_i__DOT__load_err_q))) {
                    vlSelf->pc_set_o = 1U;
                    vlSelf->pc_mux_o = 2U;
                    vlSelf->exc_pc_mux_o = ((IData)(vlSelf->__PVT__controller_i__DOT__debug_mode_q)
                                             ? 3U : 0U);
                    vlSelf->csr_save_id_o = 0U;
                    vlSelf->csr_save_cause_o = 1U;
                    if (vlSelf->__PVT__controller_i__DOT__instr_fetch_err_prio) {
                        vlSelf->exc_cause_o = 1U;
                        vlSelf->csr_mtval_o = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_fetch_err_plus2_o)
                                                ? ((IData)(2U) 
                                                   + vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.pc_id_o)
                                                : vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.pc_id_o);
                    } else if (vlSelf->__PVT__controller_i__DOT__illegal_insn_prio) {
                        vlSelf->exc_cause_o = 2U;
                        vlSelf->csr_mtval_o = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_is_compressed_id_o)
                                                ? (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_c_id_o)
                                                : vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o);
                    } else if (vlSelf->__PVT__controller_i__DOT__ecall_insn_prio) {
                        vlSelf->exc_cause_o = ((3U 
                                                == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__priv_lvl_q))
                                                ? 0xbU
                                                : 8U);
                    } else if (vlSelf->__PVT__controller_i__DOT__ebrk_insn_prio) {
                        if (((IData)(vlSelf->__PVT__controller_i__DOT__debug_mode_q) 
                             | (IData)(vlSelf->__PVT__controller_i__DOT__ebreak_into_debug))) {
                            vlSelf->pc_set_o = 0U;
                            vlSelf->csr_save_id_o = 0U;
                            vlSelf->csr_save_cause_o = 0U;
                            vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 9U;
                            __PVT__controller_i__DOT__flush_id = 0U;
                        } else {
                            vlSelf->exc_cause_o = 3U;
                        }
                    } else if (vlSelf->__PVT__controller_i__DOT__store_err_prio) {
                        vlSelf->exc_cause_o = 7U;
                        vlSelf->csr_mtval_o = vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_last_q;
                    } else if (vlSelf->__PVT__controller_i__DOT__load_err_prio) {
                        vlSelf->exc_cause_o = 5U;
                        vlSelf->csr_mtval_o = vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_last_q;
                    }
                } else if (vlSelf->__PVT__controller_i__DOT__mret_insn) {
                    vlSelf->pc_mux_o = 3U;
                    vlSelf->pc_set_o = 1U;
                    vlSelf->csr_restore_mret_id_o = 1U;
                    if (vlSelf->__PVT__controller_i__DOT__nmi_mode_q) {
                        vlSelf->__PVT__controller_i__DOT__nmi_mode_d = 0U;
                    }
                } else if (vlSelf->__PVT__controller_i__DOT__dret_insn) {
                    vlSelf->pc_mux_o = 4U;
                    vlSelf->pc_set_o = 1U;
                    vlSelf->__PVT__controller_i__DOT__debug_mode_d = 0U;
                    vlSelf->csr_restore_dret_id_o = 1U;
                } else if (vlSelf->__PVT__controller_i__DOT__wfi_insn) {
                    vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 2U;
                }
                if (((IData)(vlSelf->__PVT__controller_i__DOT__enter_debug_mode_prio_q) 
                     & (~ ((IData)(vlSelf->__PVT__controller_i__DOT__ebrk_insn_prio) 
                           & (IData)(vlSelf->__PVT__controller_i__DOT__ebreak_into_debug))))) {
                    vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 8U;
                }
            }
        } else if ((1U & (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs))) {
            __PVT__controller_run = 1U;
            vlSelf->pc_mux_o = 1U;
            if (vlSelf->__PVT__controller_i__DOT__special_req) {
                __PVT__controller_i__DOT__retain_id = 1U;
                vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 6U;
            }
            if (((IData)(vlSelf->__PVT__branch_set) 
                 | (IData)(vlSelf->__PVT__jump_set))) {
                vlSelf->pc_set_o = 1U;
                vlSelf->perf_tbranch_o = vlSelf->__PVT__branch_set;
                vlSelf->perf_jump_o = vlSelf->__PVT__jump_set;
            }
            if ((((IData)(vlSelf->__PVT__controller_i__DOT__enter_debug_mode_prio_d) 
                  | (IData)(vlSelf->__PVT__controller_i__DOT__handle_irq)) 
                 & ((IData)(vlSelf->__PVT__stall_id) 
                    | (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__PVT__instr_valid_id_q)))) {
                __PVT__controller_i__DOT__halt_if = 1U;
            }
            if ((1U & ((~ (IData)(vlSelf->__PVT__stall_id)) 
                       & (~ ((IData)(vlSelf->__PVT__controller_i__DOT__special_req) 
                             | (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__PVT__instr_valid_id_q)))))) {
                if (vlSelf->__PVT__controller_i__DOT__enter_debug_mode_prio_d) {
                    vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 8U;
                    __PVT__controller_i__DOT__halt_if = 1U;
                } else if (vlSelf->__PVT__controller_i__DOT__handle_irq) {
                    vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 7U;
                    __PVT__controller_i__DOT__halt_if = 1U;
                }
            }
        } else {
            if (vlSelf->id_in_ready_o) {
                vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 5U;
            }
            if (vlSelf->__PVT__controller_i__DOT__handle_irq) {
                vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 7U;
                __PVT__controller_i__DOT__halt_if = 1U;
            }
            if (vlSelf->__PVT__controller_i__DOT__enter_debug_mode_prio_d) {
                vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 8U;
                __PVT__controller_i__DOT__halt_if = 1U;
            }
        }
    } else if ((2U & (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs))) {
        if ((1U & (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs))) {
            vlSelf->instr_req_o = 0U;
            __PVT__controller_i__DOT__halt_if = 1U;
            __PVT__controller_i__DOT__flush_id = 1U;
            if ((1U & (((IData)(vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_pending_q) 
                        | (IData)(vlSelf->__PVT__controller_i__DOT__debug_mode_q)) 
                       | (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_dcsr_csr__DOT__rdata_q 
                          >> 2U)))) {
                vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 4U;
            } else {
                ctrl_busy_o = 0U;
            }
        } else {
            ctrl_busy_o = 0U;
            vlSelf->instr_req_o = 0U;
            __PVT__controller_i__DOT__halt_if = 1U;
            __PVT__controller_i__DOT__flush_id = 1U;
            vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 3U;
        }
    } else if ((1U & (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs))) {
        vlSelf->instr_req_o = 1U;
        vlSelf->pc_mux_o = 0U;
        vlSelf->pc_set_o = 1U;
        vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 4U;
    } else {
        vlSelf->instr_req_o = 0U;
        vlSelf->pc_mux_o = 0U;
        vlSelf->pc_set_o = 1U;
        vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 1U;
    }
    vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_clear = 0U;
    if (vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_pending_q) {
        if (((~ (IData)(vlSelf->__PVT__controller_i__DOT__nmi_mode_q)) 
             & (IData)(vlSelf->__PVT__controller_i__DOT__nmi_mode_d))) {
            vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_clear = 1U;
        }
    }
    vlSelf->en_wb_o = ((~ (IData)(vlSelf->__PVT__stall_id)) 
                       & ((~ (IData)(__PVT__controller_i__DOT__flush_id)) 
                          & (IData)(vlSelf->__PVT__instr_executing_spec)));
    vlSelf->__PVT__instr_executing_spec = (((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_fetch_err_o)) 
                                            & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__PVT__instr_valid_id_q)) 
                                           & (IData)(__PVT__controller_run));
    vlSelf->instr_valid_clear_o = (1U & ((~ ((IData)(vlSelf->__PVT__stall_id) 
                                             | (IData)(__PVT__controller_i__DOT__retain_id))) 
                                         | (IData)(__PVT__controller_i__DOT__flush_id)));
    vlSelf->id_in_ready_o = (1U & ((~ (IData)(vlSelf->__PVT__stall_id)) 
                                   & (~ ((IData)(__PVT__controller_i__DOT__halt_if) 
                                         | (IData)(__PVT__controller_i__DOT__retain_id)))));
    vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_pending_d 
        = (((~ (IData)(vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_clear)) 
            & (IData)(vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_pending_q)) 
           | (IData)(vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_set));
    vlSelf->__PVT__branch_set_raw_d = 0U;
    vlSelf->__PVT__id_fsm_d = vlSelf->__PVT__id_fsm_q;
    __PVT__rf_we_raw = vlSelf->__PVT__decoder_i__DOT__rf_we;
    vlSelf->perf_branch_o = 0U;
    if (vlSelf->__PVT__instr_executing_spec) {
        if ((1U & (~ (IData)(vlSelf->__PVT__id_fsm_q)))) {
            if ((1U & (~ (IData)(vlSelf->__PVT__lsu_req_dec)))) {
                if ((1U & (~ (IData)(vlSelf->__PVT__multdiv_en_dec)))) {
                    if (vlSelf->__PVT__branch_in_dec) {
                        vlSelf->__PVT__branch_set_raw_d 
                            = (1U & ((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result) 
                                     | ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
                                        >> 1U)));
                        vlSelf->perf_branch_o = 1U;
                    }
                }
            }
        }
        if (vlSelf->__PVT__id_fsm_q) {
            if (vlSelf->__PVT__id_fsm_q) {
                if (vlSelf->__PVT__multicycle_done) {
                    vlSelf->__PVT__id_fsm_d = 0U;
                }
                if (vlSelf->__PVT__multdiv_en_dec) {
                    __PVT__rf_we_raw = ((IData)(vlSelf->__PVT__decoder_i__DOT__rf_we) 
                                        & (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_valid));
                }
            } else {
                vlSelf->__PVT__id_fsm_d = 0U;
            }
        } else {
            if (vlSelf->__PVT__lsu_req_dec) {
                vlSelf->__PVT__id_fsm_d = 1U;
            } else if (vlSelf->__PVT__multdiv_en_dec) {
                if ((1U & (~ (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_valid)))) {
                    vlSelf->__PVT__id_fsm_d = 1U;
                }
            } else {
                vlSelf->__PVT__id_fsm_d = (1U & ((IData)(vlSelf->__PVT__branch_in_dec)
                                                  ? 
                                                 (((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
                                                   >> 1U) 
                                                  | (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result))
                                                  : (IData)(vlSelf->__PVT__jump_in_dec)));
            }
            if ((1U & (~ (IData)(vlSelf->__PVT__lsu_req_dec)))) {
                if (vlSelf->__PVT__multdiv_en_dec) {
                    if ((1U & (~ (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_valid)))) {
                        __PVT__rf_we_raw = 0U;
                    }
                }
            }
        }
        vlSelf->lsu_req_o = ((IData)(vlSelf->instr_first_cycle_id_o) 
                             & (IData)(vlSelf->__PVT__lsu_req_dec));
    } else {
        vlSelf->lsu_req_o = 0U;
    }
    vlSelf->__PVT__branch_jump_set_done_d = ((~ (IData)(vlSelf->instr_valid_clear_o)) 
                                             & ((IData)(vlSelf->__PVT__g_branch_set_flop__DOT__branch_set_raw_q) 
                                                | ((IData)(vlSelf->__PVT__branch_jump_set_done_q) 
                                                   | (IData)(vlSelf->__PVT__jump_set_raw))));
    vlSelf->rf_we_id_o = ((IData)(__PVT__rf_we_raw) 
                          & ((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.illegal_csr_insn_o)) 
                             & (IData)(vlSelf->__PVT__instr_executing_spec)));
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__0(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__0\n"); );
    // Init
    CData/*1:0*/ __PVT__alu_op_a_mux_sel_dec;
    __PVT__alu_op_a_mux_sel_dec = 0;
    CData/*2:0*/ __PVT__imm_b_mux_sel;
    __PVT__imm_b_mux_sel = 0;
    CData/*2:0*/ __PVT__imm_b_mux_sel_dec;
    __PVT__imm_b_mux_sel_dec = 0;
    CData/*6:0*/ __PVT__decoder_i__DOT__opcode_alu;
    __PVT__decoder_i__DOT__opcode_alu = 0;
    // Body
    vlSelf->__VdfgTmp_h20a3cc49__0 = ((1U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_gets_expanded_id_o)) 
                                      | (2U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_gets_expanded_id_o)));
    vlSelf->__PVT__controller_i__DOT__instr_fetch_err 
        = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_fetch_err_o) 
           & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__PVT__instr_valid_id_q));
    if (vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__rst_n) {
        vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_addr_q 
            = vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_addr_d;
        vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs 
            = vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns;
        if ((1U & (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_we_ex))) {
            vlSelf->__PVT__imd_val_q[1U] = ((3U & vlSelf->__PVT__imd_val_q[1U]) 
                                            | ((IData)(
                                                       (0x3ffffffffULL 
                                                        & (((QData)((IData)(
                                                                            vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_d_ex[2U])) 
                                                            << 0x1eU) 
                                                           | ((QData)((IData)(
                                                                              vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_d_ex[1U])) 
                                                              >> 2U)))) 
                                               << 2U));
            vlSelf->__PVT__imd_val_q[2U] = (0xfU & 
                                            (((IData)(
                                                      (0x3ffffffffULL 
                                                       & (((QData)((IData)(
                                                                           vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_d_ex[2U])) 
                                                           << 0x1eU) 
                                                          | ((QData)((IData)(
                                                                             vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_d_ex[1U])) 
                                                             >> 2U)))) 
                                              >> 0x1eU) 
                                             | ((IData)(
                                                        ((0x3ffffffffULL 
                                                          & (((QData)((IData)(
                                                                              vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_d_ex[2U])) 
                                                              << 0x1eU) 
                                                             | ((QData)((IData)(
                                                                                vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_d_ex[1U])) 
                                                                >> 2U))) 
                                                         >> 0x20U)) 
                                                << 2U)));
        }
        if ((2U & (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_we_ex))) {
            vlSelf->__PVT__imd_val_q[0U] = (IData)(
                                                   (0x3ffffffffULL 
                                                    & (((QData)((IData)(
                                                                        vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_d_ex[1U])) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(
                                                                         vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_d_ex[0U])))));
            vlSelf->__PVT__imd_val_q[1U] = ((0xfffffffcU 
                                             & vlSelf->__PVT__imd_val_q[1U]) 
                                            | (IData)(
                                                      ((0x3ffffffffULL 
                                                        & (((QData)((IData)(
                                                                            vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_d_ex[1U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_d_ex[0U])))) 
                                                       >> 0x20U)));
        }
        vlSelf->__PVT__controller_i__DOT__debug_cause_q 
            = (((IData)(vlSelf->__PVT__controller_i__DOT__ebrk_insn_prio) 
                & (IData)(vlSelf->__PVT__controller_i__DOT__ebreak_into_debug))
                ? 1U : ((IData)(vlSelf->__PVT__controller_i__DOT__do_single_step_d)
                         ? 4U : 0U));
        if (vlSelf->__PVT__instr_executing_spec) {
            vlSelf->__PVT__id_fsm_q = vlSelf->__PVT__id_fsm_d;
        }
        vlSelf->__PVT__g_branch_set_flop__DOT__branch_set_raw_q 
            = vlSelf->__PVT__branch_set_raw_d;
    } else {
        vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_addr_q = 0U;
        vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs = 0U;
        vlSelf->__PVT__imd_val_q[1U] = (3U & vlSelf->__PVT__imd_val_q[1U]);
        vlSelf->__PVT__imd_val_q[2U] = 0U;
        vlSelf->__PVT__imd_val_q[0U] = 0U;
        vlSelf->__PVT__imd_val_q[1U] = (0xfffffffcU 
                                        & vlSelf->__PVT__imd_val_q[1U]);
        vlSelf->__PVT__controller_i__DOT__debug_cause_q = 0U;
        vlSelf->__PVT__id_fsm_q = 0U;
        vlSelf->__PVT__g_branch_set_flop__DOT__branch_set_raw_q = 0U;
    }
    vlSelf->__PVT__controller_i__DOT__enter_debug_mode_prio_q 
        = ((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__rst_n) 
           && (IData)(vlSelf->__PVT__controller_i__DOT__enter_debug_mode_prio_d));
    vlSelf->__PVT__controller_i__DOT__exc_req_q = ((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__rst_n) 
                                                   && (IData)(vlSelf->__PVT__controller_i__DOT__exc_req_d));
    vlSelf->__PVT__controller_i__DOT__do_single_step_q 
        = ((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__rst_n) 
           && (IData)(vlSelf->__PVT__controller_i__DOT__do_single_step_d));
    vlSelf->__PVT__branch_jump_set_done_q = ((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__rst_n) 
                                             & (IData)(vlSelf->__PVT__branch_jump_set_done_d));
    vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_pending_q 
        = ((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__rst_n) 
           && (IData)(vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_pending_d));
    vlSelf->__PVT__controller_i__DOT__nmi_mode_q = 
        ((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__rst_n) 
         && (IData)(vlSelf->__PVT__controller_i__DOT__nmi_mode_d));
    vlSelf->__PVT__controller_i__DOT__illegal_insn_q 
        = ((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__rst_n) 
           && (IData)(vlSelf->__PVT__controller_i__DOT__illegal_insn_d));
    vlSelf->__PVT__controller_i__DOT__debug_mode_q 
        = ((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__rst_n) 
           && (IData)(vlSelf->__PVT__controller_i__DOT__debug_mode_d));
    vlSelf->__PVT__controller_i__DOT__load_err_q = 
        ((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__rst_n) 
         && (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_load_err));
    vlSelf->__PVT__controller_i__DOT__store_err_q = 
        ((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__rst_n) 
         && (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_store_err));
    vlSelf->__PVT__g_sec_branch_taken__DOT__branch_taken_q 
        = ((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__rst_n) 
           & (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result));
    vlSelf->__PVT__controller_i__DOT__ebreak_into_debug 
        = (1U & ((3U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__priv_lvl_q))
                  ? (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_dcsr_csr__DOT__rdata_q 
                     >> 0xfU) : ((0U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__priv_lvl_q)) 
                                 & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_dcsr_csr__DOT__rdata_q 
                                    >> 0xcU))));
    vlSelf->__PVT__branch_set = ((~ (IData)(vlSelf->__PVT__branch_jump_set_done_q)) 
                                 & (IData)(vlSelf->__PVT__g_branch_set_flop__DOT__branch_set_raw_q));
    vlSelf->__PVT__controller_i__DOT__handle_irq = 
        ((~ (IData)(vlSelf->__PVT__controller_i__DOT__debug_mode_q)) 
         & ((~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_dcsr_csr__DOT__rdata_q 
                >> 2U)) & ((~ (IData)(vlSelf->__PVT__controller_i__DOT__nmi_mode_q)) 
                           & ((IData)(vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_pending_q) 
                              & (2U != (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_gets_expanded_id_o))))));
    if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__PVT__instr_valid_id_q) {
        vlSelf->__PVT__controller_i__DOT__do_single_step_d 
            = (1U & ((~ (IData)(vlSelf->__PVT__controller_i__DOT__debug_mode_q)) 
                     & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_dcsr_csr__DOT__rdata_q 
                        >> 2U)));
        vlSelf->instr_first_cycle_id_o = (1U & (~ (IData)(vlSelf->__PVT__id_fsm_q)));
    } else {
        vlSelf->__PVT__controller_i__DOT__do_single_step_d 
            = (1U & (IData)(vlSelf->__PVT__controller_i__DOT__do_single_step_q));
        vlSelf->instr_first_cycle_id_o = 0U;
    }
    vlSelf->__PVT__controller_i__DOT__enter_debug_mode_prio_d 
        = ((IData)(vlSelf->__PVT__controller_i__DOT__do_single_step_d) 
           & ((~ (IData)(vlSelf->__PVT__controller_i__DOT__debug_mode_q)) 
              & (~ (IData)(vlSelf->__VdfgTmp_h20a3cc49__0))));
    vlSelf->__PVT__alu_operator = 0x2cU;
    __PVT__alu_op_a_mux_sel_dec = 3U;
    vlSelf->__PVT__alu_op_b_mux_sel_dec = 1U;
    vlSelf->__PVT__imm_a_mux_sel = 1U;
    __PVT__imm_b_mux_sel_dec = 0U;
    __PVT__decoder_i__DOT__opcode_alu = (0x7fU & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o);
    vlSelf->mult_sel_ex_o = 0U;
    vlSelf->div_sel_ex_o = 0U;
    if ((0x40U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
        if ((0x20U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
            if ((0x10U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                if ((1U & (~ ((IData)(__PVT__decoder_i__DOT__opcode_alu) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(__PVT__decoder_i__DOT__opcode_alu) 
                                  >> 2U)))) {
                        if ((2U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                            if ((1U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                                if ((0U == (7U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o 
                                                  >> 0xcU)))) {
                                    __PVT__alu_op_a_mux_sel_dec = 0U;
                                    vlSelf->__PVT__alu_op_b_mux_sel_dec = 1U;
                                } else {
                                    vlSelf->__PVT__imm_a_mux_sel = 0U;
                                    __PVT__alu_op_a_mux_sel_dec 
                                        = ((0x4000U 
                                            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)
                                            ? 3U : 0U);
                                }
                            }
                        }
                    }
                }
            } else if ((8U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                if ((4U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                    if ((2U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                        if ((1U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                            if (vlSelf->instr_first_cycle_id_o) {
                                __PVT__alu_op_a_mux_sel_dec = 2U;
                                vlSelf->__PVT__alu_op_b_mux_sel_dec = 1U;
                                __PVT__imm_b_mux_sel_dec = 4U;
                                vlSelf->__PVT__alu_operator = 0U;
                            } else {
                                __PVT__alu_op_a_mux_sel_dec = 2U;
                                vlSelf->__PVT__alu_op_b_mux_sel_dec = 1U;
                                __PVT__imm_b_mux_sel_dec = 5U;
                                vlSelf->__PVT__alu_operator = 0U;
                            }
                        }
                    }
                }
            } else if ((4U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                if ((2U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                    if ((1U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                        if (vlSelf->instr_first_cycle_id_o) {
                            __PVT__alu_op_a_mux_sel_dec = 0U;
                            vlSelf->__PVT__alu_op_b_mux_sel_dec = 1U;
                            __PVT__imm_b_mux_sel_dec = 0U;
                            vlSelf->__PVT__alu_operator = 0U;
                        } else {
                            __PVT__alu_op_a_mux_sel_dec = 2U;
                            vlSelf->__PVT__alu_op_b_mux_sel_dec = 1U;
                            __PVT__imm_b_mux_sel_dec = 5U;
                            vlSelf->__PVT__alu_operator = 0U;
                        }
                    }
                }
            } else if ((2U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                if ((1U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                    if ((0x4000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)) {
                        vlSelf->__PVT__alu_operator 
                            = ((0x2000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)
                                ? ((0x1000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)
                                    ? 0x1cU : 0x1aU)
                                : ((0x1000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)
                                    ? 0x1bU : 0x19U));
                    } else if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o 
                                         >> 0xdU)))) {
                        vlSelf->__PVT__alu_operator 
                            = ((0x1000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)
                                ? 0x1eU : 0x1dU);
                    }
                    if (vlSelf->instr_first_cycle_id_o) {
                        __PVT__alu_op_a_mux_sel_dec = 0U;
                        vlSelf->__PVT__alu_op_b_mux_sel_dec = 0U;
                    } else {
                        __PVT__alu_op_a_mux_sel_dec = 2U;
                        vlSelf->__PVT__alu_op_b_mux_sel_dec = 1U;
                        __PVT__imm_b_mux_sel_dec = 
                            ((1U & ((~ ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
                                        >> 1U)) | (IData)(vlSelf->__PVT__g_sec_branch_taken__DOT__branch_taken_q)))
                              ? 2U : 5U);
                        vlSelf->__PVT__alu_operator = 0U;
                    }
                }
            }
        }
    } else if ((0x20U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
        if ((0x10U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
            if ((1U & (~ ((IData)(__PVT__decoder_i__DOT__opcode_alu) 
                          >> 3U)))) {
                if ((4U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                    if ((2U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                        if ((1U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                            __PVT__alu_op_a_mux_sel_dec = 3U;
                            vlSelf->__PVT__alu_op_b_mux_sel_dec = 1U;
                            vlSelf->__PVT__imm_a_mux_sel = 1U;
                            __PVT__imm_b_mux_sel_dec = 3U;
                            vlSelf->__PVT__alu_operator = 0U;
                        }
                    }
                } else if ((2U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                    if ((1U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                        __PVT__alu_op_a_mux_sel_dec = 0U;
                        vlSelf->__PVT__alu_op_b_mux_sel_dec = 0U;
                        if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o 
                                      >> 0x1aU)))) {
                            if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o 
                                          >> 0x1fU)))) {
                                if ((0x40000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)) {
                                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o 
                                                  >> 0x1dU)))) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o 
                                                    >> 0x1cU)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o 
                                                     >> 0x1bU)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o 
                                                         >> 0x1aU)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o 
                                                             >> 0x19U)))) {
                                                        if (
                                                            (0x4000U 
                                                             & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o 
                                                                     >> 0xdU)))) {
                                                                if (
                                                                    (0x1000U 
                                                                     & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)) {
                                                                    vlSelf->__PVT__alu_operator = 8U;
                                                                }
                                                            }
                                                        } else if (
                                                                   (1U 
                                                                    & (~ 
                                                                       (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o 
                                                                        >> 0xdU)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o 
                                                                     >> 0xcU)))) {
                                                                vlSelf->__PVT__alu_operator = 1U;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else if ((1U & (~ 
                                                  (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o 
                                                   >> 0x1dU)))) {
                                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o 
                                                  >> 0x1cU)))) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o 
                                                    >> 0x1bU)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o 
                                                     >> 0x1aU)))) {
                                                if (
                                                    (0x2000000U 
                                                     & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)) {
                                                    if (
                                                        (0x4000U 
                                                         & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)) {
                                                        if (
                                                            (0x2000U 
                                                             & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)) {
                                                            if (
                                                                (0x1000U 
                                                                 & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)) {
                                                                vlSelf->__PVT__alu_operator = 0U;
                                                                vlSelf->div_sel_ex_o = 1U;
                                                            } else {
                                                                vlSelf->__PVT__alu_operator = 0U;
                                                                vlSelf->div_sel_ex_o = 1U;
                                                            }
                                                        } else if (
                                                                   (0x1000U 
                                                                    & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)) {
                                                            vlSelf->__PVT__alu_operator = 0U;
                                                            vlSelf->div_sel_ex_o = 1U;
                                                        } else {
                                                            vlSelf->__PVT__alu_operator = 0U;
                                                            vlSelf->div_sel_ex_o = 1U;
                                                        }
                                                    } else if (
                                                               (0x2000U 
                                                                & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)) {
                                                        if (
                                                            (0x1000U 
                                                             & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)) {
                                                            vlSelf->__PVT__alu_operator = 0U;
                                                            vlSelf->mult_sel_ex_o = 1U;
                                                        } else {
                                                            vlSelf->__PVT__alu_operator = 0U;
                                                            vlSelf->mult_sel_ex_o = 1U;
                                                        }
                                                    } else if (
                                                               (0x1000U 
                                                                & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)) {
                                                        vlSelf->__PVT__alu_operator = 0U;
                                                        vlSelf->mult_sel_ex_o = 1U;
                                                    } else {
                                                        vlSelf->__PVT__alu_operator = 0U;
                                                        vlSelf->mult_sel_ex_o = 1U;
                                                    }
                                                } else {
                                                    vlSelf->__PVT__alu_operator 
                                                        = 
                                                        ((0x4000U 
                                                          & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)
                                                          ? 
                                                         ((0x2000U 
                                                           & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)
                                                           ? 
                                                          ((0x1000U 
                                                            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)
                                                            ? 4U
                                                            : 3U)
                                                           : 
                                                          ((0x1000U 
                                                            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)
                                                            ? 9U
                                                            : 2U))
                                                          : 
                                                         ((0x2000U 
                                                           & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)
                                                           ? 
                                                          ((0x1000U 
                                                            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)
                                                            ? 0x2cU
                                                            : 0x2bU)
                                                           : 
                                                          ((0x1000U 
                                                            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)
                                                            ? 0xaU
                                                            : 0U)));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if ((1U & (~ ((IData)(__PVT__decoder_i__DOT__opcode_alu) 
                             >> 3U)))) {
            if ((1U & (~ ((IData)(__PVT__decoder_i__DOT__opcode_alu) 
                          >> 2U)))) {
                if ((2U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                    if ((1U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                        __PVT__alu_op_a_mux_sel_dec = 0U;
                        vlSelf->__PVT__alu_op_b_mux_sel_dec = 0U;
                        vlSelf->__PVT__alu_operator = 0U;
                        if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o 
                                      >> 0xeU)))) {
                            __PVT__imm_b_mux_sel_dec = 1U;
                            vlSelf->__PVT__alu_op_b_mux_sel_dec = 1U;
                        }
                    }
                }
            }
        }
    } else if ((0x10U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
        if ((1U & (~ ((IData)(__PVT__decoder_i__DOT__opcode_alu) 
                      >> 3U)))) {
            if ((4U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                if ((2U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                    if ((1U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                        __PVT__alu_op_a_mux_sel_dec = 2U;
                        vlSelf->__PVT__alu_op_b_mux_sel_dec = 1U;
                        __PVT__imm_b_mux_sel_dec = 3U;
                        vlSelf->__PVT__alu_operator = 0U;
                    }
                }
            } else if ((2U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                if ((1U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                    __PVT__alu_op_a_mux_sel_dec = 0U;
                    vlSelf->__PVT__alu_op_b_mux_sel_dec = 1U;
                    __PVT__imm_b_mux_sel_dec = 0U;
                    if ((0x4000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)) {
                        if ((0x2000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)) {
                            vlSelf->__PVT__alu_operator 
                                = ((0x1000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)
                                    ? 4U : 3U);
                        } else if ((0x1000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)) {
                            if ((0U == (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o 
                                        >> 0x1bU))) {
                                vlSelf->__PVT__alu_operator = 9U;
                            } else if ((8U == (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o 
                                               >> 0x1bU))) {
                                vlSelf->__PVT__alu_operator = 8U;
                            }
                        } else {
                            vlSelf->__PVT__alu_operator = 2U;
                        }
                    } else {
                        vlSelf->__PVT__alu_operator 
                            = ((0x2000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)
                                ? ((0x1000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)
                                    ? 0x2cU : 0x2bU)
                                : ((0x1000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o)
                                    ? 0xaU : 0U));
                    }
                }
            }
        }
    } else if ((8U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
        if ((4U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
            if ((2U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                if ((1U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                    if ((0U == (7U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o 
                                      >> 0xcU)))) {
                        vlSelf->__PVT__alu_operator = 0U;
                        __PVT__alu_op_a_mux_sel_dec = 0U;
                        vlSelf->__PVT__alu_op_b_mux_sel_dec = 1U;
                    } else if ((1U == (7U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_alu_id_o 
                                             >> 0xcU)))) {
                        __PVT__alu_op_a_mux_sel_dec = 2U;
                        vlSelf->__PVT__alu_op_b_mux_sel_dec = 1U;
                        __PVT__imm_b_mux_sel_dec = 5U;
                        vlSelf->__PVT__alu_operator = 0U;
                    }
                }
            }
        }
    } else if ((1U & (~ ((IData)(__PVT__decoder_i__DOT__opcode_alu) 
                         >> 2U)))) {
        if ((2U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
            if ((1U & (IData)(__PVT__decoder_i__DOT__opcode_alu))) {
                __PVT__alu_op_a_mux_sel_dec = 0U;
                vlSelf->__PVT__alu_operator = 0U;
                vlSelf->__PVT__alu_op_b_mux_sel_dec = 1U;
                __PVT__imm_b_mux_sel_dec = 0U;
            }
        }
    }
    if (vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_addr_incr_req) {
        __PVT__imm_b_mux_sel = 6U;
        vlSelf->__PVT__alu_op_a_mux_sel = 1U;
    } else {
        __PVT__imm_b_mux_sel = __PVT__imm_b_mux_sel_dec;
        vlSelf->__PVT__alu_op_a_mux_sel = __PVT__alu_op_a_mux_sel_dec;
    }
    vlSelf->__PVT__imm_b = ((4U & (IData)(__PVT__imm_b_mux_sel))
                             ? ((2U & (IData)(__PVT__imm_b_mux_sel))
                                 ? 4U : ((1U & (IData)(__PVT__imm_b_mux_sel))
                                          ? ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_is_compressed_id_o)
                                              ? 2U : 4U)
                                          : (((- (IData)(
                                                         (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                          >> 0x1fU))) 
                                              << 0x14U) 
                                             | ((0xff000U 
                                                 & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o) 
                                                | ((0x800U 
                                                    & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                       >> 9U)) 
                                                   | (0x7feU 
                                                      & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                         >> 0x14U)))))))
                             : ((2U & (IData)(__PVT__imm_b_mux_sel))
                                 ? ((1U & (IData)(__PVT__imm_b_mux_sel))
                                     ? (0xfffff000U 
                                        & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                     : (((- (IData)(
                                                    (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                     >> 0x1fU))) 
                                         << 0xdU) | 
                                        ((0x1000U & 
                                          (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                           >> 0x13U)) 
                                         | ((0x800U 
                                             & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                << 4U)) 
                                            | ((0x7e0U 
                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                   >> 0x14U)) 
                                               | (0x1eU 
                                                  & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                     >> 7U)))))))
                                 : ((1U & (IData)(__PVT__imm_b_mux_sel))
                                     ? (((- (IData)(
                                                    (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                     >> 0x1fU))) 
                                         << 0xcU) | 
                                        ((0xfe0U & 
                                          (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                           >> 0x14U)) 
                                         | (0x1fU & 
                                            (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                             >> 7U))))
                                     : (((- (IData)(
                                                    (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                     >> 0x1fU))) 
                                         << 0xcU) | 
                                        (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                         >> 0x14U)))));
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__1(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__1\n"); );
    // Body
    vlSelf->alu_operand_b_ex_o = (((IData)(vlSelf->__PVT__alu_op_b_mux_sel_dec) 
                                   | (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_addr_incr_req))
                                   ? vlSelf->__PVT__imm_b
                                   : vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b);
    vlSelf->__PVT__alu_operand_a = ((2U & (IData)(vlSelf->__PVT__alu_op_a_mux_sel))
                                     ? ((1U & (IData)(vlSelf->__PVT__alu_op_a_mux_sel))
                                         ? ((IData)(vlSelf->__PVT__imm_a_mux_sel)
                                             ? 0U : 
                                            (0x1fU 
                                             & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                >> 0xfU)))
                                         : vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.pc_id_o)
                                     : ((1U & (IData)(vlSelf->__PVT__alu_op_a_mux_sel))
                                         ? vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_last_q
                                         : vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_a));
}

extern const VlUnpacked<CData/*0:0*/, 64> Vtb_rtnn_c2_soc_42__ConstPool__TABLE_h6451e8c0_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vtb_rtnn_c2_soc_42__ConstPool__TABLE_h2aabc56c_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vtb_rtnn_c2_soc_42__ConstPool__TABLE_hf64aebe0_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vtb_rtnn_c2_soc_42__ConstPool__TABLE_h323b7bc3_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vtb_rtnn_c2_soc_42__ConstPool__TABLE_h6d182578_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vtb_rtnn_c2_soc_42__ConstPool__TABLE_hbf9cbdd6_0;

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__2(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__2\n"); );
    // Init
    CData/*0:0*/ icache_inval_o;
    icache_inval_o = 0;
    CData/*0:0*/ __PVT__decoder_i__DOT__csr_illegal;
    __PVT__decoder_i__DOT__csr_illegal = 0;
    CData/*1:0*/ __PVT__decoder_i__DOT__csr_op;
    __PVT__decoder_i__DOT__csr_op = 0;
    CData/*6:0*/ __PVT__decoder_i__DOT__opcode;
    __PVT__decoder_i__DOT__opcode = 0;
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->__PVT__jump_in_dec = 0U;
    vlSelf->__PVT__jump_set_dec = 0U;
    vlSelf->__PVT__branch_in_dec = 0U;
    icache_inval_o = 0U;
    vlSelf->__PVT__multdiv_operator = 0U;
    vlSelf->__PVT__multdiv_signed_mode = 0U;
    vlSelf->__PVT__rf_wdata_sel = 0U;
    vlSelf->__PVT__decoder_i__DOT__rf_we = 0U;
    vlSelf->csr_access_o = 0U;
    __PVT__decoder_i__DOT__csr_illegal = 0U;
    __PVT__decoder_i__DOT__csr_op = 0U;
    vlSelf->__PVT__lsu_we = 0U;
    vlSelf->__PVT__lsu_type = 0U;
    vlSelf->__PVT__lsu_sign_ext = 0U;
    vlSelf->__PVT__lsu_req_dec = 0U;
    vlSelf->__PVT__decoder_i__DOT__illegal_insn = 0U;
    vlSelf->__PVT__ebrk_insn = 0U;
    vlSelf->__PVT__mret_insn_dec = 0U;
    vlSelf->__PVT__dret_insn_dec = 0U;
    vlSelf->__PVT__ecall_insn_dec = 0U;
    vlSelf->__PVT__wfi_insn_dec = 0U;
    __PVT__decoder_i__DOT__opcode = (0x7fU & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o);
    if ((0x40U & (IData)(__PVT__decoder_i__DOT__opcode))) {
        if ((0x20U & (IData)(__PVT__decoder_i__DOT__opcode))) {
            if ((0x10U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                if ((8U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                    vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                } else if ((4U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                    vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                } else if ((2U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                    if ((1U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                        if ((0U == (7U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                          >> 0xcU)))) {
                            if ((0U == (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                        >> 0x14U))) {
                                vlSelf->__PVT__ecall_insn_dec = 1U;
                            } else if ((1U == (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                               >> 0x14U))) {
                                vlSelf->__PVT__ebrk_insn = 1U;
                            } else if ((0x302U == (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                   >> 0x14U))) {
                                vlSelf->__PVT__mret_insn_dec = 1U;
                            } else if ((0x7b2U == (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                   >> 0x14U))) {
                                vlSelf->__PVT__dret_insn_dec = 1U;
                            } else if ((0x105U == (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                   >> 0x14U))) {
                                vlSelf->__PVT__wfi_insn_dec = 1U;
                            } else {
                                vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                            }
                            if ((IData)((0U != (0xf8f80U 
                                                & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)))) {
                                vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                            }
                        } else {
                            vlSelf->csr_access_o = 1U;
                            vlSelf->__PVT__rf_wdata_sel = 1U;
                            vlSelf->__PVT__decoder_i__DOT__rf_we = 1U;
                            if ((1U == (3U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                              >> 0xcU)))) {
                                __PVT__decoder_i__DOT__csr_op = 1U;
                            } else if ((2U == (3U & 
                                               (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                >> 0xcU)))) {
                                __PVT__decoder_i__DOT__csr_op = 2U;
                            } else if ((3U == (3U & 
                                               (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                >> 0xcU)))) {
                                __PVT__decoder_i__DOT__csr_op = 3U;
                            } else {
                                __PVT__decoder_i__DOT__csr_illegal = 1U;
                            }
                            vlSelf->__PVT__decoder_i__DOT__illegal_insn 
                                = __PVT__decoder_i__DOT__csr_illegal;
                        }
                    } else {
                        vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                    }
                } else {
                    vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                }
            } else if ((8U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                if ((4U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                    if ((2U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                        if ((1U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                            vlSelf->__PVT__jump_in_dec = 1U;
                            if (vlSelf->instr_first_cycle_id_o) {
                                vlSelf->__PVT__decoder_i__DOT__rf_we = 0U;
                                vlSelf->__PVT__jump_set_dec = 1U;
                            } else {
                                vlSelf->__PVT__decoder_i__DOT__rf_we = 1U;
                            }
                        } else {
                            vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                        }
                    } else {
                        vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                    }
                } else {
                    vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                }
            } else if ((4U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                if ((2U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                    if ((1U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                        vlSelf->__PVT__jump_in_dec = 1U;
                        if (vlSelf->instr_first_cycle_id_o) {
                            vlSelf->__PVT__decoder_i__DOT__rf_we = 0U;
                            vlSelf->__PVT__jump_set_dec = 1U;
                        } else {
                            vlSelf->__PVT__decoder_i__DOT__rf_we = 1U;
                        }
                        if ((0U != (7U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                          >> 0xcU)))) {
                            vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                        }
                    } else {
                        vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                    }
                } else {
                    vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                }
            } else if ((2U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                if ((1U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                    vlSelf->__PVT__branch_in_dec = 1U;
                    vlSelf->__PVT__decoder_i__DOT__illegal_insn 
                        = ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                     >> 0xeU))) && 
                           (1U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                  >> 0xdU)));
                } else {
                    vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                }
            } else {
                vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
            }
        } else {
            vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
        }
    } else if ((0x20U & (IData)(__PVT__decoder_i__DOT__opcode))) {
        if ((0x10U & (IData)(__PVT__decoder_i__DOT__opcode))) {
            if ((8U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
            } else if ((4U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                if ((2U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                    if ((1U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                        vlSelf->__PVT__decoder_i__DOT__rf_we = 1U;
                    } else {
                        vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                    }
                } else {
                    vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                }
            } else if ((2U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                if ((1U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                    vlSelf->__PVT__decoder_i__DOT__rf_we = 1U;
                    if ((5U == ((4U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                       >> 0x18U)) | 
                                (3U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                       >> 0xcU))))) {
                        vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                    } else if ((vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                >> 0x1fU)) {
                        vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                    } else if ((0x40000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        vlSelf->__PVT__decoder_i__DOT__illegal_insn 
                            = ((1U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                      >> 0x1dU)) || 
                               ((1U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                       >> 0x1cU)) || 
                                ((1U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                        >> 0x1bU)) 
                                 || ((1U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                            >> 0x1aU)) 
                                     || ((1U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                >> 0x19U)) 
                                         || ((0x4000U 
                                              & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                              ? ((1U 
                                                  & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                     >> 0xdU)) 
                                                 || (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                         >> 0xcU))))
                                              : ((1U 
                                                  & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                     >> 0xdU)) 
                                                 || (1U 
                                                     & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                        >> 0xcU)))))))));
                    } else if ((0x20000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                    } else if ((0x10000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                    } else if ((0x8000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                    } else if ((0x4000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                    } else if ((0x2000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        if ((0x4000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            if ((0x2000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                if ((0x1000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                    vlSelf->__PVT__multdiv_operator = 3U;
                                    vlSelf->__PVT__multdiv_signed_mode = 0U;
                                    vlSelf->__PVT__decoder_i__DOT__illegal_insn = 0U;
                                } else {
                                    vlSelf->__PVT__multdiv_operator = 3U;
                                    vlSelf->__PVT__multdiv_signed_mode = 3U;
                                    vlSelf->__PVT__decoder_i__DOT__illegal_insn = 0U;
                                }
                            } else if ((0x1000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                vlSelf->__PVT__multdiv_operator = 2U;
                                vlSelf->__PVT__multdiv_signed_mode = 0U;
                                vlSelf->__PVT__decoder_i__DOT__illegal_insn = 0U;
                            } else {
                                vlSelf->__PVT__multdiv_operator = 2U;
                                vlSelf->__PVT__multdiv_signed_mode = 3U;
                                vlSelf->__PVT__decoder_i__DOT__illegal_insn = 0U;
                            }
                        } else if ((0x2000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            if ((0x1000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                vlSelf->__PVT__multdiv_operator = 1U;
                                vlSelf->__PVT__multdiv_signed_mode = 0U;
                                vlSelf->__PVT__decoder_i__DOT__illegal_insn = 0U;
                            } else {
                                vlSelf->__PVT__multdiv_operator = 1U;
                                vlSelf->__PVT__multdiv_signed_mode = 1U;
                                vlSelf->__PVT__decoder_i__DOT__illegal_insn = 0U;
                            }
                        } else if ((0x1000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            vlSelf->__PVT__multdiv_operator = 1U;
                            vlSelf->__PVT__multdiv_signed_mode = 3U;
                            vlSelf->__PVT__decoder_i__DOT__illegal_insn = 0U;
                        } else {
                            vlSelf->__PVT__multdiv_operator = 0U;
                            vlSelf->__PVT__multdiv_signed_mode = 0U;
                            vlSelf->__PVT__decoder_i__DOT__illegal_insn = 0U;
                        }
                    } else {
                        vlSelf->__PVT__decoder_i__DOT__illegal_insn = 0U;
                    }
                } else {
                    vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                }
            } else {
                vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
            }
        } else if ((8U & (IData)(__PVT__decoder_i__DOT__opcode))) {
            vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
        } else if ((4U & (IData)(__PVT__decoder_i__DOT__opcode))) {
            vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
        } else if ((2U & (IData)(__PVT__decoder_i__DOT__opcode))) {
            if ((1U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                vlSelf->__PVT__lsu_req_dec = 1U;
                vlSelf->__PVT__lsu_we = 1U;
                if ((0x4000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                }
                if ((0U == (3U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                  >> 0xcU)))) {
                    vlSelf->__PVT__lsu_type = 2U;
                } else if ((1U == (3U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                         >> 0xcU)))) {
                    vlSelf->__PVT__lsu_type = 1U;
                } else if ((2U == (3U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                         >> 0xcU)))) {
                    vlSelf->__PVT__lsu_type = 0U;
                } else {
                    vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                }
            } else {
                vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
            }
        } else {
            vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
        }
    } else if ((0x10U & (IData)(__PVT__decoder_i__DOT__opcode))) {
        if ((8U & (IData)(__PVT__decoder_i__DOT__opcode))) {
            vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
        } else if ((4U & (IData)(__PVT__decoder_i__DOT__opcode))) {
            if ((2U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                if ((1U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                    vlSelf->__PVT__decoder_i__DOT__rf_we = 1U;
                } else {
                    vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                }
            } else {
                vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
            }
        } else if ((2U & (IData)(__PVT__decoder_i__DOT__opcode))) {
            if ((1U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                vlSelf->__PVT__decoder_i__DOT__rf_we = 1U;
                vlSelf->__PVT__decoder_i__DOT__illegal_insn 
                    = ((0x4000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                        ? ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                     >> 0xdU))) && 
                           ((1U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                   >> 0xcU)) && ((1U 
                                                  & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                     >> 0x1aU)) 
                                                 || ((vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                      >> 0x1fU) 
                                                     || ((0x40000000U 
                                                          & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                                          ? 
                                                         ((1U 
                                                           & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                              >> 0x1dU)) 
                                                          || ((1U 
                                                               & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                  >> 0x1cU)) 
                                                              || ((1U 
                                                                   & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                      >> 0x1bU)) 
                                                                  || (0U 
                                                                      != 
                                                                      (3U 
                                                                       & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                          >> 0x19U))))))
                                                          : 
                                                         ((1U 
                                                           & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                              >> 0x1dU)) 
                                                          || ((1U 
                                                               & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                  >> 0x1cU)) 
                                                              || ((1U 
                                                                   & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                      >> 0x1bU)) 
                                                                  || (0U 
                                                                      != 
                                                                      (3U 
                                                                       & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                          >> 0x19U)))))))))))
                        : ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                     >> 0xdU))) && 
                           ((1U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                   >> 0xcU)) && ((vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                  >> 0x1fU) 
                                                 || ((1U 
                                                      & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                         >> 0x1eU)) 
                                                     || ((1U 
                                                          & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                             >> 0x1dU)) 
                                                         || ((1U 
                                                              & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                 >> 0x1cU)) 
                                                             || ((1U 
                                                                  & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                     >> 0x1bU)) 
                                                                 || (0U 
                                                                     != 
                                                                     (3U 
                                                                      & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                         >> 0x19U)))))))))));
            } else {
                vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
            }
        } else {
            vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
        }
    } else if ((8U & (IData)(__PVT__decoder_i__DOT__opcode))) {
        if ((4U & (IData)(__PVT__decoder_i__DOT__opcode))) {
            if ((2U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                if ((1U & (IData)(__PVT__decoder_i__DOT__opcode))) {
                    if ((0U == (7U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                      >> 0xcU)))) {
                        vlSelf->__PVT__decoder_i__DOT__rf_we = 0U;
                    } else if ((1U == (7U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                             >> 0xcU)))) {
                        vlSelf->__PVT__jump_in_dec = 1U;
                        vlSelf->__PVT__decoder_i__DOT__rf_we = 0U;
                        if (vlSelf->instr_first_cycle_id_o) {
                            vlSelf->__PVT__jump_set_dec = 1U;
                            icache_inval_o = 1U;
                        }
                    } else {
                        vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                    }
                } else {
                    vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                }
            } else {
                vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
            }
        } else {
            vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
        }
    } else if ((4U & (IData)(__PVT__decoder_i__DOT__opcode))) {
        vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
    } else if ((2U & (IData)(__PVT__decoder_i__DOT__opcode))) {
        if ((1U & (IData)(__PVT__decoder_i__DOT__opcode))) {
            vlSelf->__PVT__lsu_req_dec = 1U;
            vlSelf->__PVT__lsu_type = 0U;
            vlSelf->__PVT__lsu_sign_ext = (1U & (~ 
                                                 (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                  >> 0xeU)));
            if ((0U == (3U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                              >> 0xcU)))) {
                vlSelf->__PVT__lsu_type = 2U;
            } else if ((1U == (3U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                     >> 0xcU)))) {
                vlSelf->__PVT__lsu_type = 1U;
            } else if ((2U == (3U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                     >> 0xcU)))) {
                vlSelf->__PVT__lsu_type = 0U;
                if ((0x4000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
                }
            } else {
                vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
            }
        } else {
            vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
        }
    } else {
        vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
    }
    if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.illegal_c_insn_id_o) {
        vlSelf->__PVT__decoder_i__DOT__illegal_insn = 1U;
    }
    if (vlSelf->__PVT__decoder_i__DOT__illegal_insn) {
        vlSelf->__PVT__decoder_i__DOT__rf_we = 0U;
        vlSelf->__PVT__lsu_req_dec = 0U;
        vlSelf->__PVT__lsu_we = 0U;
        vlSelf->__PVT__jump_in_dec = 0U;
        vlSelf->__PVT__jump_set_dec = 0U;
        vlSelf->__PVT__branch_in_dec = 0U;
        vlSelf->csr_access_o = 0U;
    }
    vlSelf->csr_op_o = __PVT__decoder_i__DOT__csr_op;
    if ((IData)(((0U == (0xf8000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                 & ((2U == (IData)(__PVT__decoder_i__DOT__csr_op)) 
                    | (3U == (IData)(__PVT__decoder_i__DOT__csr_op)))))) {
        vlSelf->csr_op_o = 0U;
    }
    vlSelf->__PVT__controller_i__DOT__mret_insn = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__PVT__instr_valid_id_q) 
                                                   & (IData)(vlSelf->__PVT__mret_insn_dec));
    vlSelf->__PVT__controller_i__DOT__dret_insn = ((IData)(vlSelf->__PVT__dret_insn_dec) 
                                                   & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__PVT__instr_valid_id_q));
    vlSelf->__PVT__controller_i__DOT__wfi_insn = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__PVT__instr_valid_id_q) 
                                                  & (IData)(vlSelf->__PVT__wfi_insn_dec));
    vlSelf->__PVT__controller_i__DOT__ebrk_insn = ((IData)(vlSelf->__PVT__ebrk_insn) 
                                                   & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__PVT__instr_valid_id_q));
    vlSelf->__PVT__controller_i__DOT__ecall_insn = 
        ((IData)(vlSelf->__PVT__ecall_insn_dec) & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__PVT__instr_valid_id_q));
    vlSelf->__VdfgTmp_h50e2f79d__0 = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__PVT__instr_valid_id_q) 
                                      & ((~ (IData)(vlSelf->instr_first_cycle_id_o)) 
                                         & (IData)(vlSelf->__PVT__lsu_req_dec)));
    vlSelf->__PVT__div_en_dec = ((~ (IData)(vlSelf->__PVT__decoder_i__DOT__illegal_insn)) 
                                 & (IData)(vlSelf->div_sel_ex_o));
    vlSelf->__PVT__mult_en_dec = ((~ (IData)(vlSelf->__PVT__decoder_i__DOT__illegal_insn)) 
                                  & (IData)(vlSelf->mult_sel_ex_o));
    vlSelf->__VdfgTmp_hc09de8e0__0 = ((1U == (IData)(vlSelf->csr_op_o)) 
                                      | ((2U == (IData)(vlSelf->csr_op_o)) 
                                         | (3U == (IData)(vlSelf->csr_op_o))));
    __Vtableidx1 = (((IData)(vlSelf->__PVT__controller_i__DOT__load_err_q) 
                     << 5U) | (((IData)(vlSelf->__PVT__controller_i__DOT__store_err_q) 
                                << 4U) | (((IData)(vlSelf->__PVT__controller_i__DOT__ebrk_insn) 
                                           << 3U) | 
                                          (((IData)(vlSelf->__PVT__controller_i__DOT__ecall_insn) 
                                            << 2U) 
                                           | (((IData)(vlSelf->__PVT__controller_i__DOT__illegal_insn_q) 
                                               << 1U) 
                                              | (IData)(vlSelf->__PVT__controller_i__DOT__instr_fetch_err))))));
    vlSelf->__PVT__controller_i__DOT__instr_fetch_err_prio 
        = Vtb_rtnn_c2_soc_42__ConstPool__TABLE_h6451e8c0_0
        [__Vtableidx1];
    vlSelf->__PVT__controller_i__DOT__illegal_insn_prio 
        = Vtb_rtnn_c2_soc_42__ConstPool__TABLE_h2aabc56c_0
        [__Vtableidx1];
    vlSelf->__PVT__controller_i__DOT__ecall_insn_prio 
        = Vtb_rtnn_c2_soc_42__ConstPool__TABLE_hf64aebe0_0
        [__Vtableidx1];
    vlSelf->__PVT__controller_i__DOT__ebrk_insn_prio 
        = Vtb_rtnn_c2_soc_42__ConstPool__TABLE_h323b7bc3_0
        [__Vtableidx1];
    vlSelf->__PVT__controller_i__DOT__store_err_prio 
        = Vtb_rtnn_c2_soc_42__ConstPool__TABLE_h6d182578_0
        [__Vtableidx1];
    vlSelf->__PVT__controller_i__DOT__load_err_prio 
        = Vtb_rtnn_c2_soc_42__ConstPool__TABLE_hbf9cbdd6_0
        [__Vtableidx1];
    vlSelf->expecting_load_resp_o = ((~ (IData)(vlSelf->__PVT__lsu_we)) 
                                     & (IData)(vlSelf->__VdfgTmp_h50e2f79d__0));
    vlSelf->__PVT__multdiv_en_dec = ((IData)(vlSelf->__PVT__div_en_dec) 
                                     | (IData)(vlSelf->__PVT__mult_en_dec));
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__3(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__3\n"); );
    // Init
    CData/*0:0*/ illegal_insn_o;
    illegal_insn_o = 0;
    // Body
    vlSelf->rf_wdata_id_o = ((IData)(vlSelf->__PVT__rf_wdata_sel)
                              ? ((IData)(vlSelf->__PVT__rf_wdata_sel)
                                  ? vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__csr_rdata_int
                                  : ((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
                                      ? ((IData)(vlSelf->div_sel_ex_o)
                                          ? ((vlSelf->__PVT__imd_val_q[2U] 
                                              << 0x1eU) 
                                             | (vlSelf->__PVT__imd_val_q[1U] 
                                                >> 2U))
                                          : (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d))
                                      : vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_result))
                              : ((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
                                  ? ((IData)(vlSelf->div_sel_ex_o)
                                      ? ((vlSelf->__PVT__imd_val_q[2U] 
                                          << 0x1eU) 
                                         | (vlSelf->__PVT__imd_val_q[1U] 
                                            >> 2U))
                                      : (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d))
                                  : vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_result));
    illegal_insn_o = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__PVT__instr_valid_id_q) 
                      & ((IData)(vlSelf->__PVT__decoder_i__DOT__illegal_insn) 
                         | ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.illegal_csr_insn_o) 
                            | (((~ (IData)(vlSelf->__PVT__controller_i__DOT__debug_mode_q)) 
                                & (IData)(vlSelf->__PVT__dret_insn_dec)) 
                               | ((3U != (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__priv_lvl_q)) 
                                  & ((IData)(vlSelf->__PVT__mret_insn_dec) 
                                     | ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_mstatus_csr__DOT__rdata_q) 
                                        & (IData)(vlSelf->__PVT__wfi_insn_dec))))))));
    vlSelf->__PVT__controller_i__DOT__illegal_insn_d 
        = ((IData)(illegal_insn_o) & (6U != (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs)));
    vlSelf->__PVT__controller_i__DOT__exc_req_d = (
                                                   ((IData)(vlSelf->__PVT__controller_i__DOT__ecall_insn) 
                                                    | ((IData)(vlSelf->__PVT__controller_i__DOT__ebrk_insn) 
                                                       | ((IData)(vlSelf->__PVT__controller_i__DOT__illegal_insn_d) 
                                                          | (IData)(vlSelf->__PVT__controller_i__DOT__instr_fetch_err)))) 
                                                   & (6U 
                                                      != (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs)));
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__0(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__0\n"); );
    // Init
    CData/*0:0*/ __PVT__mem_resp_intg_err;
    __PVT__mem_resp_intg_err = 0;
    // Body
    __PVT__mem_resp_intg_err = (((~ (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q)) 
                                 & (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT____VdfgTmp_h3fd48639__0)) 
                                | ((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT____VdfgTmp_h3fd48639__0) 
                                   & (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q)));
    vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_addr_d 
        = vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_addr_q;
    vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_set = 0U;
    if ((1U & (~ (IData)(vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_pending_q)))) {
        if (__PVT__mem_resp_intg_err) {
            vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_addr_d 
                = vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_last_q;
            vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_set = 1U;
        }
    }
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__4(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__4\n"); );
    // Init
    CData/*0:0*/ ctrl_busy_o;
    ctrl_busy_o = 0;
    CData/*0:0*/ debug_mode_entering_o;
    debug_mode_entering_o = 0;
    CData/*0:0*/ __PVT__controller_run;
    __PVT__controller_run = 0;
    CData/*0:0*/ __PVT__rf_we_raw;
    __PVT__rf_we_raw = 0;
    CData/*0:0*/ __PVT__controller_i__DOT__halt_if;
    __PVT__controller_i__DOT__halt_if = 0;
    CData/*0:0*/ __PVT__controller_i__DOT__retain_id;
    __PVT__controller_i__DOT__retain_id = 0;
    CData/*0:0*/ __PVT__controller_i__DOT__flush_id;
    __PVT__controller_i__DOT__flush_id = 0;
    // Body
    vlSelf->instr_req_o = 1U;
    vlSelf->csr_save_if_o = 0U;
    vlSelf->csr_save_id_o = 0U;
    vlSelf->csr_restore_mret_id_o = 0U;
    vlSelf->csr_restore_dret_id_o = 0U;
    vlSelf->csr_save_cause_o = 0U;
    vlSelf->csr_mtval_o = 0U;
    vlSelf->pc_mux_o = 0U;
    vlSelf->pc_set_o = 0U;
    vlSelf->exc_pc_mux_o = 1U;
    vlSelf->exc_cause_o = 0U;
    vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs;
    ctrl_busy_o = 1U;
    __PVT__controller_i__DOT__halt_if = 0U;
    __PVT__controller_i__DOT__retain_id = 0U;
    __PVT__controller_i__DOT__flush_id = 0U;
    vlSelf->debug_csr_save_o = 0U;
    vlSelf->__PVT__controller_i__DOT__debug_mode_d 
        = vlSelf->__PVT__controller_i__DOT__debug_mode_q;
    debug_mode_entering_o = 0U;
    vlSelf->__PVT__controller_i__DOT__nmi_mode_d = vlSelf->__PVT__controller_i__DOT__nmi_mode_q;
    vlSelf->perf_tbranch_o = 0U;
    vlSelf->perf_jump_o = 0U;
    __PVT__controller_run = 0U;
    if ((8U & (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs))) {
        if ((4U & (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs))) {
            vlSelf->instr_req_o = 0U;
            vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 0U;
        } else if ((2U & (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs))) {
            vlSelf->instr_req_o = 0U;
            vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 0U;
        } else if ((1U & (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs))) {
            __PVT__controller_i__DOT__flush_id = 1U;
            vlSelf->pc_mux_o = 2U;
            vlSelf->pc_set_o = 1U;
            vlSelf->exc_pc_mux_o = 2U;
            if (((IData)(vlSelf->__PVT__controller_i__DOT__ebreak_into_debug) 
                 & (~ (IData)(vlSelf->__PVT__controller_i__DOT__debug_mode_q)))) {
                vlSelf->csr_save_cause_o = 1U;
                vlSelf->csr_save_id_o = 1U;
                vlSelf->debug_csr_save_o = 1U;
            }
            vlSelf->__PVT__controller_i__DOT__debug_mode_d = 1U;
            debug_mode_entering_o = 1U;
            vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 5U;
        } else {
            vlSelf->pc_mux_o = 2U;
            vlSelf->exc_pc_mux_o = 2U;
            __PVT__controller_i__DOT__flush_id = 1U;
            vlSelf->pc_set_o = 1U;
            vlSelf->csr_save_if_o = 1U;
            vlSelf->debug_csr_save_o = 1U;
            vlSelf->csr_save_cause_o = 1U;
            vlSelf->__PVT__controller_i__DOT__debug_mode_d = 1U;
            debug_mode_entering_o = 1U;
            vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 5U;
        }
    } else if ((4U & (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs))) {
        if ((2U & (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs))) {
            if ((1U & (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs))) {
                vlSelf->pc_mux_o = 2U;
                vlSelf->exc_pc_mux_o = 1U;
                if (vlSelf->__PVT__controller_i__DOT__handle_irq) {
                    vlSelf->pc_set_o = 1U;
                    vlSelf->csr_save_if_o = 1U;
                    vlSelf->csr_save_cause_o = 1U;
                    if (((IData)(vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_pending_q) 
                         & (~ (IData)(vlSelf->__PVT__controller_i__DOT__nmi_mode_q)))) {
                        vlSelf->exc_cause_o = 0x40U;
                        if (vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_pending_q) {
                            vlSelf->csr_mtval_o = vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_addr_q;
                        }
                        vlSelf->__PVT__controller_i__DOT__nmi_mode_d = 1U;
                    } else {
                        vlSelf->exc_cause_o = 0x27U;
                    }
                }
                vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 5U;
            } else {
                __PVT__controller_i__DOT__halt_if = 1U;
                __PVT__controller_i__DOT__flush_id = 1U;
                vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 5U;
                if ((((IData)(vlSelf->__PVT__controller_i__DOT__exc_req_q) 
                      | (IData)(vlSelf->__PVT__controller_i__DOT__store_err_q)) 
                     | (IData)(vlSelf->__PVT__controller_i__DOT__load_err_q))) {
                    vlSelf->pc_set_o = 1U;
                    vlSelf->pc_mux_o = 2U;
                    vlSelf->exc_pc_mux_o = ((IData)(vlSelf->__PVT__controller_i__DOT__debug_mode_q)
                                             ? 3U : 0U);
                    vlSelf->csr_save_id_o = 0U;
                    vlSelf->csr_save_cause_o = 1U;
                    if (vlSelf->__PVT__controller_i__DOT__instr_fetch_err_prio) {
                        vlSelf->exc_cause_o = 1U;
                        vlSelf->csr_mtval_o = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_fetch_err_plus2_o)
                                                ? ((IData)(2U) 
                                                   + vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.pc_id_o)
                                                : vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.pc_id_o);
                    } else if (vlSelf->__PVT__controller_i__DOT__illegal_insn_prio) {
                        vlSelf->exc_cause_o = 2U;
                        vlSelf->csr_mtval_o = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_is_compressed_id_o)
                                                ? (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_c_id_o)
                                                : vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o);
                    } else if (vlSelf->__PVT__controller_i__DOT__ecall_insn_prio) {
                        vlSelf->exc_cause_o = ((3U 
                                                == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__priv_lvl_q))
                                                ? 0xbU
                                                : 8U);
                    } else if (vlSelf->__PVT__controller_i__DOT__ebrk_insn_prio) {
                        if (((IData)(vlSelf->__PVT__controller_i__DOT__debug_mode_q) 
                             | (IData)(vlSelf->__PVT__controller_i__DOT__ebreak_into_debug))) {
                            vlSelf->pc_set_o = 0U;
                            vlSelf->csr_save_id_o = 0U;
                            vlSelf->csr_save_cause_o = 0U;
                            vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 9U;
                            __PVT__controller_i__DOT__flush_id = 0U;
                        } else {
                            vlSelf->exc_cause_o = 3U;
                        }
                    } else if (vlSelf->__PVT__controller_i__DOT__store_err_prio) {
                        vlSelf->exc_cause_o = 7U;
                        vlSelf->csr_mtval_o = vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_last_q;
                    } else if (vlSelf->__PVT__controller_i__DOT__load_err_prio) {
                        vlSelf->exc_cause_o = 5U;
                        vlSelf->csr_mtval_o = vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_last_q;
                    }
                } else if (vlSelf->__PVT__controller_i__DOT__mret_insn) {
                    vlSelf->pc_mux_o = 3U;
                    vlSelf->pc_set_o = 1U;
                    vlSelf->csr_restore_mret_id_o = 1U;
                    if (vlSelf->__PVT__controller_i__DOT__nmi_mode_q) {
                        vlSelf->__PVT__controller_i__DOT__nmi_mode_d = 0U;
                    }
                } else if (vlSelf->__PVT__controller_i__DOT__dret_insn) {
                    vlSelf->pc_mux_o = 4U;
                    vlSelf->pc_set_o = 1U;
                    vlSelf->__PVT__controller_i__DOT__debug_mode_d = 0U;
                    vlSelf->csr_restore_dret_id_o = 1U;
                } else if (vlSelf->__PVT__controller_i__DOT__wfi_insn) {
                    vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 2U;
                }
                if (((IData)(vlSelf->__PVT__controller_i__DOT__enter_debug_mode_prio_q) 
                     & (~ ((IData)(vlSelf->__PVT__controller_i__DOT__ebrk_insn_prio) 
                           & (IData)(vlSelf->__PVT__controller_i__DOT__ebreak_into_debug))))) {
                    vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 8U;
                }
            }
        } else if ((1U & (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs))) {
            __PVT__controller_run = 1U;
            vlSelf->pc_mux_o = 1U;
            if (vlSelf->__PVT__controller_i__DOT__special_req) {
                __PVT__controller_i__DOT__retain_id = 1U;
                vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 6U;
            }
            if (((IData)(vlSelf->__PVT__branch_set) 
                 | (IData)(vlSelf->__PVT__jump_set))) {
                vlSelf->pc_set_o = 1U;
                vlSelf->perf_tbranch_o = vlSelf->__PVT__branch_set;
                vlSelf->perf_jump_o = vlSelf->__PVT__jump_set;
            }
            if ((((IData)(vlSelf->__PVT__controller_i__DOT__enter_debug_mode_prio_d) 
                  | (IData)(vlSelf->__PVT__controller_i__DOT__handle_irq)) 
                 & ((IData)(vlSelf->__PVT__stall_id) 
                    | (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__PVT__instr_valid_id_q)))) {
                __PVT__controller_i__DOT__halt_if = 1U;
            }
            if ((1U & ((~ (IData)(vlSelf->__PVT__stall_id)) 
                       & (~ ((IData)(vlSelf->__PVT__controller_i__DOT__special_req) 
                             | (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__PVT__instr_valid_id_q)))))) {
                if (vlSelf->__PVT__controller_i__DOT__enter_debug_mode_prio_d) {
                    vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 8U;
                    __PVT__controller_i__DOT__halt_if = 1U;
                } else if (vlSelf->__PVT__controller_i__DOT__handle_irq) {
                    vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 7U;
                    __PVT__controller_i__DOT__halt_if = 1U;
                }
            }
        } else {
            if (vlSelf->id_in_ready_o) {
                vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 5U;
            }
            if (vlSelf->__PVT__controller_i__DOT__handle_irq) {
                vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 7U;
                __PVT__controller_i__DOT__halt_if = 1U;
            }
            if (vlSelf->__PVT__controller_i__DOT__enter_debug_mode_prio_d) {
                vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 8U;
                __PVT__controller_i__DOT__halt_if = 1U;
            }
        }
    } else if ((2U & (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs))) {
        if ((1U & (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs))) {
            vlSelf->instr_req_o = 0U;
            __PVT__controller_i__DOT__halt_if = 1U;
            __PVT__controller_i__DOT__flush_id = 1U;
            if ((1U & (((IData)(vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_pending_q) 
                        | (IData)(vlSelf->__PVT__controller_i__DOT__debug_mode_q)) 
                       | (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_dcsr_csr__DOT__rdata_q 
                          >> 2U)))) {
                vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 4U;
            } else {
                ctrl_busy_o = 0U;
            }
        } else {
            ctrl_busy_o = 0U;
            vlSelf->instr_req_o = 0U;
            __PVT__controller_i__DOT__halt_if = 1U;
            __PVT__controller_i__DOT__flush_id = 1U;
            vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 3U;
        }
    } else if ((1U & (IData)(vlSelf->__PVT__controller_i__DOT__ctrl_fsm_cs))) {
        vlSelf->instr_req_o = 1U;
        vlSelf->pc_mux_o = 0U;
        vlSelf->pc_set_o = 1U;
        vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 4U;
    } else {
        vlSelf->instr_req_o = 0U;
        vlSelf->pc_mux_o = 0U;
        vlSelf->pc_set_o = 1U;
        vlSelf->__PVT__controller_i__DOT__ctrl_fsm_ns = 1U;
    }
    vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_clear = 0U;
    if (vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_pending_q) {
        if (((~ (IData)(vlSelf->__PVT__controller_i__DOT__nmi_mode_q)) 
             & (IData)(vlSelf->__PVT__controller_i__DOT__nmi_mode_d))) {
            vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_clear = 1U;
        }
    }
    vlSelf->en_wb_o = ((~ (IData)(vlSelf->__PVT__stall_id)) 
                       & ((~ (IData)(__PVT__controller_i__DOT__flush_id)) 
                          & (IData)(vlSelf->__PVT__instr_executing_spec)));
    vlSelf->__PVT__instr_executing_spec = (((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_fetch_err_o)) 
                                            & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__PVT__instr_valid_id_q)) 
                                           & (IData)(__PVT__controller_run));
    vlSelf->instr_valid_clear_o = (1U & ((~ ((IData)(vlSelf->__PVT__stall_id) 
                                             | (IData)(__PVT__controller_i__DOT__retain_id))) 
                                         | (IData)(__PVT__controller_i__DOT__flush_id)));
    vlSelf->id_in_ready_o = (1U & ((~ (IData)(vlSelf->__PVT__stall_id)) 
                                   & (~ ((IData)(__PVT__controller_i__DOT__halt_if) 
                                         | (IData)(__PVT__controller_i__DOT__retain_id)))));
    vlSelf->__PVT__branch_set_raw_d = 0U;
    vlSelf->__PVT__id_fsm_d = vlSelf->__PVT__id_fsm_q;
    __PVT__rf_we_raw = vlSelf->__PVT__decoder_i__DOT__rf_we;
    vlSelf->perf_branch_o = 0U;
    if (vlSelf->__PVT__instr_executing_spec) {
        if ((1U & (~ (IData)(vlSelf->__PVT__id_fsm_q)))) {
            if ((1U & (~ (IData)(vlSelf->__PVT__lsu_req_dec)))) {
                if ((1U & (~ (IData)(vlSelf->__PVT__multdiv_en_dec)))) {
                    if (vlSelf->__PVT__branch_in_dec) {
                        vlSelf->__PVT__branch_set_raw_d 
                            = (1U & ((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result) 
                                     | ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
                                        >> 1U)));
                        vlSelf->perf_branch_o = 1U;
                    }
                }
            }
        }
        if (vlSelf->__PVT__id_fsm_q) {
            if (vlSelf->__PVT__id_fsm_q) {
                if (vlSelf->__PVT__multicycle_done) {
                    vlSelf->__PVT__id_fsm_d = 0U;
                }
                if (vlSelf->__PVT__multdiv_en_dec) {
                    __PVT__rf_we_raw = ((IData)(vlSelf->__PVT__decoder_i__DOT__rf_we) 
                                        & (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_valid));
                }
            } else {
                vlSelf->__PVT__id_fsm_d = 0U;
            }
        } else {
            if (vlSelf->__PVT__lsu_req_dec) {
                vlSelf->__PVT__id_fsm_d = 1U;
            } else if (vlSelf->__PVT__multdiv_en_dec) {
                if ((1U & (~ (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_valid)))) {
                    vlSelf->__PVT__id_fsm_d = 1U;
                }
            } else {
                vlSelf->__PVT__id_fsm_d = (1U & ((IData)(vlSelf->__PVT__branch_in_dec)
                                                  ? 
                                                 (((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
                                                   >> 1U) 
                                                  | (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result))
                                                  : (IData)(vlSelf->__PVT__jump_in_dec)));
            }
            if ((1U & (~ (IData)(vlSelf->__PVT__lsu_req_dec)))) {
                if (vlSelf->__PVT__multdiv_en_dec) {
                    if ((1U & (~ (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_valid)))) {
                        __PVT__rf_we_raw = 0U;
                    }
                }
            }
        }
        vlSelf->lsu_req_o = ((IData)(vlSelf->instr_first_cycle_id_o) 
                             & (IData)(vlSelf->__PVT__lsu_req_dec));
    } else {
        vlSelf->lsu_req_o = 0U;
    }
    vlSelf->__PVT__branch_jump_set_done_d = ((~ (IData)(vlSelf->instr_valid_clear_o)) 
                                             & ((IData)(vlSelf->__PVT__g_branch_set_flop__DOT__branch_set_raw_q) 
                                                | ((IData)(vlSelf->__PVT__branch_jump_set_done_q) 
                                                   | (IData)(vlSelf->__PVT__jump_set_raw))));
    vlSelf->rf_we_id_o = ((IData)(__PVT__rf_we_raw) 
                          & ((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.illegal_csr_insn_o)) 
                             & (IData)(vlSelf->__PVT__instr_executing_spec)));
}
