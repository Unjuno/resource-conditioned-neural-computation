// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rtnn_c2_soc_42.h for the primary calling header

#include "Vtb_rtnn_c2_soc_42__pch.h"
#include "Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8.h"

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___eval_initial__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___eval_initial__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i\n"); );
    // Body
    vlSelf->__PVT__stall_alu = 0U;
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__1(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__1\n"); );
    // Body
    if (vlSelf->__PVT__instr_executing_spec) {
        vlSelf->mult_en_ex_o = vlSelf->__PVT__mult_en_dec;
        vlSelf->__PVT__jump_set_raw = 0U;
        if ((1U & (~ (IData)(vlSelf->__PVT__id_fsm_q)))) {
            if ((1U & (~ (IData)(vlSelf->__PVT__lsu_req_dec)))) {
                if ((1U & (~ (IData)(vlSelf->__PVT__multdiv_en_dec)))) {
                    if ((1U & (~ (IData)(vlSelf->__PVT__branch_in_dec)))) {
                        if (vlSelf->__PVT__jump_in_dec) {
                            vlSelf->__PVT__jump_set_raw 
                                = vlSelf->__PVT__jump_set_dec;
                        }
                    }
                }
            }
        }
    } else {
        vlSelf->mult_en_ex_o = 0U;
        vlSelf->__PVT__jump_set_raw = 0U;
    }
    vlSelf->__PVT__jump_set = ((~ (IData)(vlSelf->__PVT__branch_jump_set_done_q)) 
                               & (IData)(vlSelf->__PVT__jump_set_raw));
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__5(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__5\n"); );
    // Body
    vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_pending_d 
        = (((~ (IData)(vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_clear)) 
            & (IData)(vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_pending_q)) 
           | (IData)(vlSelf->__PVT__controller_i__DOT__g_intg_irq_int__DOT__mem_resp_intg_err_irq_set));
}
