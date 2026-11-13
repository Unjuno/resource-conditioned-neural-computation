// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rtnn_c2_soc_42.h for the primary calling header

#include "Vtb_rtnn_c2_soc_42__pch.h"
#include "Vtb_rtnn_c2_soc_42__Syms.h"
#include "Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9.h"

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__0(Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__0\n"); );
    // Body
    vlSelf->__PVT__csr_we_int = ((IData)(vlSelf->__PVT__csr_wr) 
                                 & ((~ (IData)(vlSelf->illegal_csr_insn_o)) 
                                    & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_op_en_o)));
    vlSelf->dummy_instr_seed_en_o = ((IData)(vlSelf->__PVT__csr_we_int) 
                                     & (0x7c1U == (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                   >> 0x14U)));
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__0(Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__0\n"); );
    // Init
    IData/*31:0*/ __PVT__exception_pc;
    __PVT__exception_pc = 0;
    // Body
    vlSelf->__PVT__mstack_en = 0U;
    vlSelf->__PVT__mtval_d = vlSelf->__PVT__csr_wdata_int;
    vlSelf->__PVT__priv_lvl_d = vlSelf->__PVT__priv_lvl_q;
    __PVT__exception_pc = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.pc_id_o;
    vlSelf->__PVT__mepc_d = (0xfffffffeU & vlSelf->__PVT__csr_wdata_int);
    vlSelf->__PVT__depc_d = (0xfffffffeU & vlSelf->__PVT__csr_wdata_int);
    if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_save_cause_o) {
        if ((1U & (~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.debug_csr_save_o)))) {
            if ((1U & (~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__controller_i__DOT__debug_mode_q)))) {
                vlSelf->__PVT__mstack_en = 1U;
                vlSelf->__PVT__mtval_d = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_mtval_o;
            }
        }
        vlSelf->__PVT__priv_lvl_d = 3U;
        if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_save_if_o) {
            __PVT__exception_pc = (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q 
                                   << 1U);
        } else if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_save_id_o) {
            __PVT__exception_pc = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.pc_id_o;
        }
        if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.debug_csr_save_o) {
            vlSelf->__PVT__depc_d = __PVT__exception_pc;
        } else if ((1U & (~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__controller_i__DOT__debug_mode_q)))) {
            vlSelf->__PVT__mepc_d = __PVT__exception_pc;
        }
    } else {
        if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_restore_dret_id_o) {
            vlSelf->__PVT__priv_lvl_d = (3U & vlSelf->__PVT__u_dcsr_csr__DOT__rdata_q);
        } else if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_restore_mret_id_o) {
            vlSelf->__PVT__priv_lvl_d = (3U & ((IData)(vlSelf->__PVT__u_mstatus_csr__DOT__rdata_q) 
                                               >> 2U));
        }
        if ((1U & (~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_restore_dret_id_o)))) {
            if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_restore_mret_id_o) {
                if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__controller_i__DOT__nmi_mode_q) {
                    vlSelf->__PVT__mepc_d = vlSelf->__PVT__u_mstack_epc_csr__DOT__rdata_q;
                }
            }
        }
    }
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__1(Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__1\n"); );
    // Init
    CData/*0:0*/ double_fault_seen_o;
    double_fault_seen_o = 0;
    CData/*0:0*/ __PVT__mcountinhibit_we;
    __PVT__mcountinhibit_we = 0;
    IData/*31:0*/ __PVT__mhpmcounter_we;
    __PVT__mhpmcounter_we = 0;
    IData/*31:0*/ __PVT__mhpmcounterh_we;
    __PVT__mhpmcounterh_we = 0;
    IData/*31:0*/ __PVT__mhpmcounter_incr;
    __PVT__mhpmcounter_incr = 0;
    QData/*63:0*/ __PVT__mcycle_counter_i__DOT__counter_load;
    __PVT__mcycle_counter_i__DOT__counter_load = 0;
    CData/*0:0*/ __PVT__mcycle_counter_i__DOT__we;
    __PVT__mcycle_counter_i__DOT__we = 0;
    QData/*63:0*/ __PVT__minstret_counter_i__DOT__counter_load;
    __PVT__minstret_counter_i__DOT__counter_load = 0;
    CData/*0:0*/ __PVT__minstret_counter_i__DOT__we;
    __PVT__minstret_counter_i__DOT__we = 0;
    // Body
    vlSelf->__PVT__mstatus_en = 0U;
    vlSelf->__PVT__mstatus_d = vlSelf->__PVT__u_mstatus_csr__DOT__rdata_q;
    vlSelf->__PVT__mie_en = 0U;
    vlSelf->__PVT__mscratch_en = 0U;
    vlSelf->__PVT__mepc_en = 0U;
    vlSelf->__PVT__mcause_en = 0U;
    vlSelf->__PVT__mcause_d = (((3U == (vlSelf->__PVT__csr_wdata_int 
                                        >> 0x1eU)) 
                                << 6U) | (((2U == (vlSelf->__PVT__csr_wdata_int 
                                                   >> 0x1eU)) 
                                           << 5U) | 
                                          (0x1fU & vlSelf->__PVT__csr_wdata_int)));
    vlSelf->__PVT__mtval_en = 0U;
    vlSelf->__PVT__mtvec_en = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.csr_mtvec_init_o;
    vlSelf->__PVT__dcsr_en = 0U;
    vlSelf->__PVT__dcsr_d = vlSelf->__PVT__u_dcsr_csr__DOT__rdata_q;
    vlSelf->__PVT__depc_en = 0U;
    vlSelf->__PVT__dscratch0_en = 0U;
    vlSelf->__PVT__dscratch1_en = 0U;
    __PVT__mcountinhibit_we = 0U;
    vlSelf->__PVT__mcounteren_we = 0U;
    __PVT__mhpmcounter_we = 0U;
    __PVT__mhpmcounterh_we = 0U;
    vlSelf->__PVT__cpuctrlsts_part_we = 0U;
    vlSelf->__PVT__cpuctrlsts_part_d = vlSelf->__PVT__u_cpuctrlsts_part_csr__DOT__rdata_q;
    double_fault_seen_o = 0U;
    if (vlSelf->__PVT__csr_we_int) {
        if ((vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
             >> 0x1fU)) {
            if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                          >> 0x1eU)))) {
                if ((0x20000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    if ((0x10000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        if ((0x8000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                          >> 0x1aU)))) {
                                if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                              >> 0x19U)))) {
                                    if ((0x1000000U 
                                         & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                        __PVT__mhpmcounterh_we 
                                            = (__PVT__mhpmcounterh_we 
                                               | (0xffffffffULL 
                                                  & ((IData)(1U) 
                                                     << 
                                                     (0x1fU 
                                                      & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                         >> 0x14U)))));
                                    } else if ((0x800000U 
                                                & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                        __PVT__mhpmcounterh_we 
                                            = (__PVT__mhpmcounterh_we 
                                               | (0xffffffffULL 
                                                  & ((IData)(1U) 
                                                     << 
                                                     (0x1fU 
                                                      & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                         >> 0x14U)))));
                                    } else if ((0x400000U 
                                                & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                        __PVT__mhpmcounterh_we 
                                            = (__PVT__mhpmcounterh_we 
                                               | (0xffffffffULL 
                                                  & ((IData)(1U) 
                                                     << 
                                                     (0x1fU 
                                                      & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                         >> 0x14U)))));
                                    } else if ((0x200000U 
                                                & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                        __PVT__mhpmcounterh_we 
                                            = (__PVT__mhpmcounterh_we 
                                               | (0xffffffffULL 
                                                  & ((IData)(1U) 
                                                     << 
                                                     (0x1fU 
                                                      & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                         >> 0x14U)))));
                                    } else if ((1U 
                                                & (~ 
                                                   (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                    >> 0x14U)))) {
                                        __PVT__mhpmcounterh_we 
                                            = (__PVT__mhpmcounterh_we 
                                               | (0xffffffffULL 
                                                  & ((IData)(1U) 
                                                     << 
                                                     (0x1fU 
                                                      & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                         >> 0x14U)))));
                                    }
                                }
                            }
                        } else if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                             >> 0x1aU)))) {
                            if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                          >> 0x19U)))) {
                                if ((0x1000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                    __PVT__mhpmcounter_we 
                                        = (__PVT__mhpmcounter_we 
                                           | (0xffffffffULL 
                                              & ((IData)(1U) 
                                                 << 
                                                 (0x1fU 
                                                  & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                     >> 0x14U)))));
                                } else if ((0x800000U 
                                            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                    __PVT__mhpmcounter_we 
                                        = (__PVT__mhpmcounter_we 
                                           | (0xffffffffULL 
                                              & ((IData)(1U) 
                                                 << 
                                                 (0x1fU 
                                                  & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                     >> 0x14U)))));
                                } else if ((0x400000U 
                                            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                    __PVT__mhpmcounter_we 
                                        = (__PVT__mhpmcounter_we 
                                           | (0xffffffffULL 
                                              & ((IData)(1U) 
                                                 << 
                                                 (0x1fU 
                                                  & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                     >> 0x14U)))));
                                } else if ((0x200000U 
                                            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                    __PVT__mhpmcounter_we 
                                        = (__PVT__mhpmcounter_we 
                                           | (0xffffffffULL 
                                              & ((IData)(1U) 
                                                 << 
                                                 (0x1fU 
                                                  & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                     >> 0x14U)))));
                                } else if ((1U & (~ 
                                                  (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                   >> 0x14U)))) {
                                    __PVT__mhpmcounter_we 
                                        = (__PVT__mhpmcounter_we 
                                           | (0xffffffffULL 
                                              & ((IData)(1U) 
                                                 << 
                                                 (0x1fU 
                                                  & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                     >> 0x14U)))));
                                }
                            }
                        }
                    }
                }
            }
        } else if ((0x40000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
            if ((0x20000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                if ((0x10000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    if ((0x8000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        if ((0x4000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                          >> 0x19U)))) {
                                if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                              >> 0x18U)))) {
                                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                  >> 0x17U)))) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                    >> 0x16U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                     >> 0x15U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                         >> 0x14U)))) {
                                                    vlSelf->__PVT__cpuctrlsts_part_d 
                                                        = 
                                                        (0xfeU 
                                                         & vlSelf->__PVT__csr_wdata_int);
                                                    vlSelf->__PVT__cpuctrlsts_part_we = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((0x2000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            if ((0x1000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                              >> 0x17U)))) {
                                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                  >> 0x16U)))) {
                                        if ((0x200000U 
                                             & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                            if ((0x100000U 
                                                 & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                                vlSelf->__PVT__dscratch1_en = 1U;
                                            } else {
                                                vlSelf->__PVT__dscratch0_en = 1U;
                                            }
                                        } else if (
                                                   (0x100000U 
                                                    & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                            vlSelf->__PVT__depc_en = 1U;
                                        } else {
                                            vlSelf->__PVT__dcsr_d 
                                                = vlSelf->__PVT__csr_wdata_int;
                                            vlSelf->__PVT__dcsr_en = 1U;
                                            vlSelf->__PVT__dcsr_d 
                                                = (0x40000000U 
                                                   | (0xfffffffU 
                                                      & vlSelf->__PVT__dcsr_d));
                                            if (((3U 
                                                  != 
                                                  (3U 
                                                   & vlSelf->__PVT__dcsr_d)) 
                                                 & (0U 
                                                    != 
                                                    (3U 
                                                     & vlSelf->__PVT__dcsr_d)))) {
                                                vlSelf->__PVT__dcsr_d 
                                                    = 
                                                    (0xfffffffcU 
                                                     & vlSelf->__PVT__dcsr_d);
                                            }
                                            vlSelf->__PVT__dcsr_d 
                                                = (
                                                   (0xfffffe3fU 
                                                    & vlSelf->__PVT__dcsr_d) 
                                                   | (0x1c0U 
                                                      & vlSelf->__PVT__u_dcsr_csr__DOT__rdata_q));
                                            vlSelf->__PVT__dcsr_d 
                                                = (0xfffff7ffU 
                                                   & vlSelf->__PVT__dcsr_d);
                                            vlSelf->__PVT__dcsr_d 
                                                = (0xffffffe7U 
                                                   & vlSelf->__PVT__dcsr_d);
                                            vlSelf->__PVT__dcsr_d 
                                                = (0xfffff9ffU 
                                                   & vlSelf->__PVT__dcsr_d);
                                            vlSelf->__PVT__dcsr_d 
                                                = (0xffffffdfU 
                                                   & vlSelf->__PVT__dcsr_d);
                                            vlSelf->__PVT__dcsr_d 
                                                = (0xffffbfffU 
                                                   & vlSelf->__PVT__dcsr_d);
                                            vlSelf->__PVT__dcsr_d 
                                                = (0xf000ffffU 
                                                   & vlSelf->__PVT__dcsr_d);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if ((0x20000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
            if ((0x10000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                              >> 0x1bU)))) {
                    if ((0x4000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                      >> 0x19U)))) {
                            if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                          >> 0x18U)))) {
                                if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                              >> 0x17U)))) {
                                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                  >> 0x16U)))) {
                                        if ((0x200000U 
                                             & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                            if ((0x100000U 
                                                 & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                                vlSelf->__PVT__mtval_en = 1U;
                                            } else {
                                                vlSelf->__PVT__mcause_en = 1U;
                                            }
                                        } else if (
                                                   (0x100000U 
                                                    & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                            vlSelf->__PVT__mepc_en = 1U;
                                        } else {
                                            vlSelf->__PVT__mscratch_en = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((0x2000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                      >> 0x18U)))) {
                            if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                          >> 0x17U)))) {
                                if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                              >> 0x16U)))) {
                                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                  >> 0x15U)))) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                    >> 0x14U)))) {
                                            __PVT__mcountinhibit_we = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                         >> 0x18U)))) {
                        if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                      >> 0x17U)))) {
                            if ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                  >> 0x14U)))) {
                                        vlSelf->__PVT__mcounteren_we = 1U;
                                    }
                                } else if ((0x100000U 
                                            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                    vlSelf->__PVT__mtvec_en = 1U;
                                } else {
                                    vlSelf->__PVT__mie_en = 1U;
                                }
                            } else if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                 >> 0x15U)))) {
                                if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                              >> 0x14U)))) {
                                    vlSelf->__PVT__mstatus_en = 1U;
                                    vlSelf->__PVT__mstatus_d 
                                        = ((0x20U & 
                                            (vlSelf->__PVT__csr_wdata_int 
                                             << 2U)) 
                                           | ((0x10U 
                                               & (vlSelf->__PVT__csr_wdata_int 
                                                  >> 3U)) 
                                              | ((([&]() {
                                                            vlSelf->__Vfunc_sv2v_cast_2__0__inp 
                                                                = 
                                                                (3U 
                                                                 & (vlSelf->__PVT__csr_wdata_int 
                                                                    >> 0xbU));
                                                            vlSelf->__Vfunc_sv2v_cast_2__0__Vfuncout 
                                                                = vlSelf->__Vfunc_sv2v_cast_2__0__inp;
                                                        }(), (IData)(vlSelf->__Vfunc_sv2v_cast_2__0__Vfuncout)) 
                                                  << 2U) 
                                                 | ((2U 
                                                     & (vlSelf->__PVT__csr_wdata_int 
                                                        >> 0x10U)) 
                                                    | (1U 
                                                       & (vlSelf->__PVT__csr_wdata_int 
                                                          >> 0x15U))))));
                                    if (((3U != (3U 
                                                 & ((IData)(vlSelf->__PVT__mstatus_d) 
                                                    >> 2U))) 
                                         & (0U != (3U 
                                                   & ((IData)(vlSelf->__PVT__mstatus_d) 
                                                      >> 2U))))) {
                                        vlSelf->__PVT__mstatus_d 
                                            = (0x33U 
                                               & (IData)(vlSelf->__PVT__mstatus_d));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_save_cause_o) {
        if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.debug_csr_save_o) {
            vlSelf->__PVT__dcsr_d = ((0xfffffffcU & vlSelf->__PVT__dcsr_d) 
                                     | (IData)(vlSelf->__PVT__priv_lvl_q));
            vlSelf->__PVT__dcsr_en = 1U;
            vlSelf->__PVT__depc_en = 1U;
            vlSelf->__PVT__dcsr_d = ((0xfffffe3fU & vlSelf->__PVT__dcsr_d) 
                                     | ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__controller_i__DOT__debug_cause_q) 
                                        << 6U));
        } else if ((1U & (~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__controller_i__DOT__debug_mode_q)))) {
            vlSelf->__PVT__mcause_d = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.exc_cause_o;
            vlSelf->__PVT__mtval_en = 1U;
            vlSelf->__PVT__mstatus_en = 1U;
            vlSelf->__PVT__mstatus_d = ((3U & (IData)(vlSelf->__PVT__mstatus_d)) 
                                        | ((0x10U & 
                                            ((IData)(vlSelf->__PVT__u_mstatus_csr__DOT__rdata_q) 
                                             >> 1U)) 
                                           | ((IData)(vlSelf->__PVT__priv_lvl_q) 
                                              << 2U)));
            vlSelf->__PVT__mepc_en = 1U;
            vlSelf->__PVT__mcause_en = 1U;
            if ((1U & (~ (IData)((0U != (0x60U & (IData)(vlSelf->__PVT__mcause_d))))))) {
                vlSelf->__PVT__cpuctrlsts_part_we = 1U;
                vlSelf->__PVT__cpuctrlsts_part_d = 
                    (0x40U | (IData)(vlSelf->__PVT__cpuctrlsts_part_d));
                if ((0x40U & (IData)(vlSelf->__PVT__u_cpuctrlsts_part_csr__DOT__rdata_q))) {
                    double_fault_seen_o = 1U;
                    vlSelf->__PVT__cpuctrlsts_part_d 
                        = (0x80U | (IData)(vlSelf->__PVT__cpuctrlsts_part_d));
                }
            }
        }
    } else if ((1U & (~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_restore_dret_id_o)))) {
        if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_restore_mret_id_o) {
            vlSelf->__PVT__mstatus_en = 1U;
            vlSelf->__PVT__mstatus_d = ((0x1fU & (IData)(vlSelf->__PVT__mstatus_d)) 
                                        | (0x20U & 
                                           ((IData)(vlSelf->__PVT__u_mstatus_csr__DOT__rdata_q) 
                                            << 1U)));
            vlSelf->__PVT__cpuctrlsts_part_we = 1U;
            vlSelf->__PVT__cpuctrlsts_part_d = (0xbfU 
                                                & (IData)(vlSelf->__PVT__cpuctrlsts_part_d));
            if ((3U != (3U & ((IData)(vlSelf->__PVT__u_mstatus_csr__DOT__rdata_q) 
                              >> 2U)))) {
                vlSelf->__PVT__mstatus_d = (0x3dU & (IData)(vlSelf->__PVT__mstatus_d));
            }
            if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__controller_i__DOT__nmi_mode_q) {
                vlSelf->__PVT__mstatus_d = ((0x23U 
                                             & (IData)(vlSelf->__PVT__mstatus_d)) 
                                            | ((IData)(vlSelf->__PVT__u_mstack_csr__DOT__rdata_q) 
                                               << 2U));
                vlSelf->__PVT__mepc_en = 1U;
                vlSelf->__PVT__mcause_en = 1U;
                vlSelf->__PVT__mcause_d = vlSelf->__PVT__u_mstack_cause_csr__DOT__rdata_q;
            } else {
                vlSelf->__PVT__mstatus_d = (0x10U | 
                                            (0x23U 
                                             & (IData)(vlSelf->__PVT__mstatus_d)));
            }
        }
    }
    __PVT__mhpmcounter_incr = 0U;
    __PVT__mhpmcounter_incr = (1U | ((0xffffffe0U & __PVT__mhpmcounter_incr) 
                                     | ((((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__PVT__instr_valid_id_q)) 
                                          & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.id_in_ready_o)) 
                                         << 4U) | (
                                                   (((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__instr_executing_spec) 
                                                     & ((~ (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_resp_valid)) 
                                                        & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__lsu_req_dec))) 
                                                    << 3U) 
                                                   | ((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__perf_instr_ret_wb) 
                                                      << 2U)))));
    __PVT__mhpmcounter_incr = ((0xfffffe1fU & __PVT__mhpmcounter_incr) 
                               | (((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.perf_branch_o) 
                                   << 8U) | (((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.perf_jump_o) 
                                              << 7U) 
                                             | (((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__perf_store) 
                                                 << 6U) 
                                                | ((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__perf_load) 
                                                   << 5U)))));
    __PVT__mhpmcounter_incr = ((0xffffe1ffU & __PVT__mhpmcounter_incr) 
                               | ((((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__div_en_dec) 
                                    & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__stall_multdiv)) 
                                   << 0xcU) | ((((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__mult_en_dec) 
                                                 & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__stall_multdiv)) 
                                                << 0xbU) 
                                               | ((((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__perf_instr_ret_wb) 
                                                    & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_is_compressed_id_o)) 
                                                   << 0xaU) 
                                                  | ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.perf_tbranch_o) 
                                                     << 9U)))));
    if (__PVT__mcountinhibit_we) {
        vlSelf->__PVT__mcountinhibit_d = (7U & vlSelf->__PVT__csr_wdata_int);
        vlSelf->__PVT__mcountinhibit_d = (5U & (IData)(vlSelf->__PVT__mcountinhibit_d));
    } else {
        vlSelf->__PVT__mcountinhibit_d = vlSelf->__PVT__mcountinhibit_q;
    }
    if (vlSelf->__PVT__mcounteren_we) {
        vlSelf->__PVT__mcounteren_d = (7U & vlSelf->__PVT__csr_wdata_int);
        vlSelf->__PVT__mcounteren_d = (5U & (IData)(vlSelf->__PVT__mcounteren_d));
    } else {
        vlSelf->__PVT__mcounteren_d = vlSelf->__PVT__u_mcounteren_csr__DOT__rdata_q;
    }
    __PVT__mcycle_counter_i__DOT__we = (1U & (__PVT__mhpmcounter_we 
                                              | __PVT__mhpmcounterh_we));
    __PVT__mcycle_counter_i__DOT__counter_load = (((QData)((IData)(
                                                                   (vlSelf->__PVT__mcycle_counter_i__DOT__counter_q 
                                                                    >> 0x20U))) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(vlSelf->__PVT__csr_wdata_int)));
    if ((1U & __PVT__mhpmcounterh_we)) {
        __PVT__mcycle_counter_i__DOT__counter_load 
            = (((QData)((IData)(vlSelf->__PVT__csr_wdata_int)) 
                << 0x20U) | (QData)((IData)(vlSelf->__PVT__mcycle_counter_i__DOT__counter_q)));
    }
    vlSelf->__PVT__mcycle_counter_i__DOT__counter_d 
        = ((IData)(__PVT__mcycle_counter_i__DOT__we)
            ? __PVT__mcycle_counter_i__DOT__counter_load
            : ((1U & ((~ (IData)(vlSelf->__PVT__mcountinhibit_q)) 
                      & __PVT__mhpmcounter_incr)) ? 
               (1ULL + vlSelf->__PVT__mcycle_counter_i__DOT__counter_q)
                : vlSelf->__PVT__mcycle_counter_i__DOT__counter_q));
    __PVT__minstret_counter_i__DOT__we = (1U & ((__PVT__mhpmcounter_we 
                                                 | __PVT__mhpmcounterh_we) 
                                                >> 2U));
    __PVT__minstret_counter_i__DOT__counter_load = 
        (((QData)((IData)((vlSelf->__PVT__minstret_counter_i__DOT__counter_q 
                           >> 0x20U))) << 0x20U) | (QData)((IData)(vlSelf->__PVT__csr_wdata_int)));
    if ((4U & __PVT__mhpmcounterh_we)) {
        __PVT__minstret_counter_i__DOT__counter_load 
            = (((QData)((IData)(vlSelf->__PVT__csr_wdata_int)) 
                << 0x20U) | (QData)((IData)(vlSelf->__PVT__minstret_counter_i__DOT__counter_q)));
    }
    vlSelf->__PVT__minstret_counter_i__DOT__counter_d 
        = ((IData)(__PVT__minstret_counter_i__DOT__we)
            ? __PVT__minstret_counter_i__DOT__counter_load
            : ((1U & ((~ ((IData)(vlSelf->__PVT__mcountinhibit_q) 
                          >> 2U)) & (__PVT__mhpmcounter_incr 
                                     >> 2U))) ? (1ULL 
                                                 + vlSelf->__PVT__minstret_counter_i__DOT__counter_q)
                : vlSelf->__PVT__minstret_counter_i__DOT__counter_q));
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__0(Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__0\n"); );
    // Init
    CData/*0:0*/ __VdfgExtracted_he83216a4__0;
    __VdfgExtracted_he83216a4__0 = 0;
    // Body
    vlSelf->__PVT__dbg_csr = 0U;
    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                  >> 0x1fU)))) {
        if ((0x40000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
            if ((0x20000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                if ((0x10000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    if ((0x8000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                      >> 0x1aU)))) {
                            if ((0x2000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                if ((0x1000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                  >> 0x17U)))) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                    >> 0x16U)))) {
                                            vlSelf->__PVT__dbg_csr = 1U;
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
    __VdfgExtracted_he83216a4__0 = ((0x3a0U == (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                >> 0x14U)) 
                                    | ((0x3a1U == (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                   >> 0x14U)) 
                                       | ((0x3a2U == 
                                           (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                            >> 0x14U)) 
                                          | ((0x3a3U 
                                              == (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                  >> 0x14U)) 
                                             | ((0x3b0U 
                                                 == 
                                                 (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                  >> 0x14U)) 
                                                | ((0x3b1U 
                                                    == 
                                                    (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                     >> 0x14U)) 
                                                   | ((0x3b2U 
                                                       == 
                                                       (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                        >> 0x14U)) 
                                                      | ((0x3b3U 
                                                          == 
                                                          (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                           >> 0x14U)) 
                                                         | ((0x3b4U 
                                                             == 
                                                             (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                              >> 0x14U)) 
                                                            | ((0x3b5U 
                                                                == 
                                                                (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                 >> 0x14U)) 
                                                               | ((0x3b6U 
                                                                   == 
                                                                   (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                    >> 0x14U)) 
                                                                  | ((0x3b7U 
                                                                      == 
                                                                      (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                       >> 0x14U)) 
                                                                     | ((0x3b8U 
                                                                         == 
                                                                         (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                          >> 0x14U)) 
                                                                        | ((0x3b9U 
                                                                            == 
                                                                            (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                             >> 0x14U)) 
                                                                           | ((0x3baU 
                                                                               == 
                                                                               (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                                >> 0x14U)) 
                                                                              | ((0x3bbU 
                                                                                == 
                                                                                (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                                >> 0x14U)) 
                                                                                | ((0x3bcU 
                                                                                == 
                                                                                (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                                >> 0x14U)) 
                                                                                | ((0x3bdU 
                                                                                == 
                                                                                (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                                >> 0x14U)) 
                                                                                | ((0x3beU 
                                                                                == 
                                                                                (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                                >> 0x14U)) 
                                                                                | (0x3bfU 
                                                                                == 
                                                                                (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                                >> 0x14U)))))))))))))))))))));
    if (vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__rst_n) {
        vlSelf->__PVT__minstret_counter_i__DOT__counter_q 
            = vlSelf->__PVT__minstret_counter_i__DOT__counter_d;
        vlSelf->__PVT__mcycle_counter_i__DOT__counter_q 
            = vlSelf->__PVT__mcycle_counter_i__DOT__counter_d;
        vlSelf->__PVT__mcountinhibit_q = vlSelf->__PVT__mcountinhibit_d;
        if (vlSelf->__PVT__mtval_en) {
            vlSelf->__PVT__u_mtval_csr__DOT__rdata_q 
                = vlSelf->__PVT__mtval_d;
        }
        if (vlSelf->__PVT__depc_en) {
            vlSelf->__PVT__u_depc_csr__DOT__rdata_q 
                = vlSelf->__PVT__depc_d;
        }
        if (vlSelf->__PVT__dscratch1_en) {
            vlSelf->__PVT__u_dscratch1_csr__DOT__rdata_q 
                = vlSelf->__PVT__csr_wdata_int;
        }
        if (vlSelf->__PVT__dscratch0_en) {
            vlSelf->__PVT__u_dscratch0_csr__DOT__rdata_q 
                = vlSelf->__PVT__csr_wdata_int;
        }
        if (vlSelf->__PVT__mscratch_en) {
            vlSelf->__PVT__u_mscratch_csr__DOT__rdata_q 
                = vlSelf->__PVT__csr_wdata_int;
        }
        if (vlSelf->__PVT__mie_en) {
            vlSelf->__PVT__u_mie_csr__DOT__rdata_q 
                = ((0x20000U & (vlSelf->__PVT__csr_wdata_int 
                                << 0xeU)) | ((0x10000U 
                                              & (vlSelf->__PVT__csr_wdata_int 
                                                 << 9U)) 
                                             | ((0x8000U 
                                                 & (vlSelf->__PVT__csr_wdata_int 
                                                    << 4U)) 
                                                | (0x7fffU 
                                                   & (vlSelf->__PVT__csr_wdata_int 
                                                      >> 0x10U)))));
        }
        if (vlSelf->__PVT__mtvec_en) {
            vlSelf->__PVT__u_mtvec_csr__DOT__rdata_q 
                = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.csr_mtvec_init_o)
                    ? 0x100001U : (1U | (0xffffff00U 
                                         & vlSelf->__PVT__csr_wdata_int)));
        }
        if (vlSelf->__PVT__mstack_en) {
            vlSelf->__PVT__u_mstack_epc_csr__DOT__rdata_q 
                = vlSelf->__PVT__u_mepc_csr__DOT__rdata_q;
            vlSelf->__PVT__u_mstack_cause_csr__DOT__rdata_q 
                = vlSelf->__PVT__u_mcause_csr__DOT__rdata_q;
            vlSelf->__PVT__u_mstack_csr__DOT__rdata_q 
                = (7U & ((IData)(vlSelf->__PVT__u_mstatus_csr__DOT__rdata_q) 
                         >> 2U));
        }
        if (vlSelf->__PVT__mcounteren_we) {
            vlSelf->__PVT__u_mcounteren_csr__DOT__rdata_q 
                = vlSelf->__PVT__mcounteren_d;
        }
        if (vlSelf->__PVT__dcsr_en) {
            vlSelf->__PVT__u_dcsr_csr__DOT__rdata_q 
                = vlSelf->__PVT__dcsr_d;
        }
        vlSelf->__PVT__priv_lvl_q = vlSelf->__PVT__priv_lvl_d;
        if (vlSelf->__PVT__cpuctrlsts_part_we) {
            vlSelf->__PVT__u_cpuctrlsts_part_csr__DOT__rdata_q 
                = vlSelf->__PVT__cpuctrlsts_part_d;
        }
        if (vlSelf->__PVT__mepc_en) {
            vlSelf->__PVT__u_mepc_csr__DOT__rdata_q 
                = vlSelf->__PVT__mepc_d;
        }
        if (vlSelf->__PVT__mcause_en) {
            vlSelf->__PVT__u_mcause_csr__DOT__rdata_q 
                = vlSelf->__PVT__mcause_d;
        }
        if (vlSelf->__PVT__mstatus_en) {
            vlSelf->__PVT__u_mstatus_csr__DOT__rdata_q 
                = vlSelf->__PVT__mstatus_d;
        }
    } else {
        vlSelf->__PVT__minstret_counter_i__DOT__counter_q = 0ULL;
        vlSelf->__PVT__mcycle_counter_i__DOT__counter_q = 0ULL;
        vlSelf->__PVT__mcountinhibit_q = 0U;
        vlSelf->__PVT__u_mtval_csr__DOT__rdata_q = 0U;
        vlSelf->__PVT__u_depc_csr__DOT__rdata_q = 0U;
        vlSelf->__PVT__u_dscratch1_csr__DOT__rdata_q = 0U;
        vlSelf->__PVT__u_dscratch0_csr__DOT__rdata_q = 0U;
        vlSelf->__PVT__u_mscratch_csr__DOT__rdata_q = 0U;
        vlSelf->__PVT__u_mie_csr__DOT__rdata_q = 0U;
        vlSelf->__PVT__u_mtvec_csr__DOT__rdata_q = 1U;
        vlSelf->__PVT__u_mstack_epc_csr__DOT__rdata_q = 0U;
        vlSelf->__PVT__u_mstack_cause_csr__DOT__rdata_q = 0U;
        vlSelf->__PVT__u_mcounteren_csr__DOT__rdata_q = 0U;
        vlSelf->__PVT__u_mstack_csr__DOT__rdata_q = 4U;
        vlSelf->__PVT__u_dcsr_csr__DOT__rdata_q = 0x40000003U;
        vlSelf->__PVT__priv_lvl_q = 3U;
        vlSelf->__PVT__u_cpuctrlsts_part_csr__DOT__rdata_q = 0U;
        vlSelf->__PVT__u_mepc_csr__DOT__rdata_q = 0U;
        vlSelf->__PVT__u_mcause_csr__DOT__rdata_q = 0U;
        vlSelf->__PVT__u_mstatus_csr__DOT__rdata_q = 0x10U;
    }
    vlSelf->__PVT__mhpmcounter[2U] = vlSelf->__PVT__minstret_counter_i__DOT__counter_q;
    vlSelf->__PVT__mhpmcounter[0U] = vlSelf->__PVT__mcycle_counter_i__DOT__counter_q;
    vlSelf->__PVT__illegal_csr = 0U;
    if ((vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
         >> 0x1fU)) {
        if ((0x40000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
            if ((0x20000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                if ((0x10000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    if ((0x8000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        vlSelf->__PVT__illegal_csr = 1U;
                    } else if ((0x4000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        vlSelf->__PVT__illegal_csr = 1U;
                    } else if ((0x2000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        vlSelf->__PVT__illegal_csr = 1U;
                    } else if ((0x1000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        if ((0x800000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            vlSelf->__PVT__illegal_csr = 1U;
                        } else if ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                vlSelf->__PVT__illegal_csr = 1U;
                            }
                        } else if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                             >> 0x15U)))) {
                            if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                          >> 0x14U)))) {
                                vlSelf->__PVT__illegal_csr = 1U;
                            }
                        }
                    } else {
                        vlSelf->__PVT__illegal_csr = 1U;
                    }
                } else {
                    vlSelf->__PVT__illegal_csr = 1U;
                }
            } else {
                vlSelf->__PVT__illegal_csr = ((1U & 
                                               (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                >> 0x1cU)) 
                                              || ((0x8000000U 
                                                   & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                                   ? 
                                                  ((1U 
                                                    & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                       >> 0x1aU)) 
                                                   || ((1U 
                                                        & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                           >> 0x19U)) 
                                                       || ((0x1000000U 
                                                            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                                            ? 
                                                           ((0U 
                                                             == (IData)(vlSelf->__PVT__priv_lvl_q)) 
                                                            & (~ 
                                                               ((IData)(vlSelf->__PVT__u_mcounteren_csr__DOT__rdata_q) 
                                                                >> 
                                                                (0x1fU 
                                                                 & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                    >> 0x14U)))))
                                                            : 
                                                           ((0x800000U 
                                                             & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                                             ? 
                                                            ((0U 
                                                              == (IData)(vlSelf->__PVT__priv_lvl_q)) 
                                                             & (~ 
                                                                ((IData)(vlSelf->__PVT__u_mcounteren_csr__DOT__rdata_q) 
                                                                 >> 
                                                                 (0x1fU 
                                                                  & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                     >> 0x14U)))))
                                                             : 
                                                            ((0x400000U 
                                                              & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                                              ? 
                                                             ((0U 
                                                               == (IData)(vlSelf->__PVT__priv_lvl_q)) 
                                                              & (~ 
                                                                 ((IData)(vlSelf->__PVT__u_mcounteren_csr__DOT__rdata_q) 
                                                                  >> 
                                                                  (0x1fU 
                                                                   & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                      >> 0x14U)))))
                                                              : 
                                                             ((0x200000U 
                                                               & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                                               ? 
                                                              ((0U 
                                                                == (IData)(vlSelf->__PVT__priv_lvl_q)) 
                                                               & (~ 
                                                                  ((IData)(vlSelf->__PVT__u_mcounteren_csr__DOT__rdata_q) 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                       >> 0x14U)))))
                                                               : 
                                                              ((1U 
                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                   >> 0x14U)) 
                                                               || ((0U 
                                                                    == (IData)(vlSelf->__PVT__priv_lvl_q)) 
                                                                   & (~ 
                                                                      ((IData)(vlSelf->__PVT__u_mcounteren_csr__DOT__rdata_q) 
                                                                       >> 
                                                                       (0x1fU 
                                                                        & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                           >> 0x14U))))))))))))
                                                   : 
                                                  ((1U 
                                                    & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                       >> 0x1aU)) 
                                                   || ((1U 
                                                        & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                           >> 0x19U)) 
                                                       || ((0x1000000U 
                                                            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                                            ? 
                                                           ((0U 
                                                             == (IData)(vlSelf->__PVT__priv_lvl_q)) 
                                                            & (~ 
                                                               ((IData)(vlSelf->__PVT__u_mcounteren_csr__DOT__rdata_q) 
                                                                >> 
                                                                (0x1fU 
                                                                 & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                    >> 0x14U)))))
                                                            : 
                                                           ((0x800000U 
                                                             & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                                             ? 
                                                            ((0U 
                                                              == (IData)(vlSelf->__PVT__priv_lvl_q)) 
                                                             & (~ 
                                                                ((IData)(vlSelf->__PVT__u_mcounteren_csr__DOT__rdata_q) 
                                                                 >> 
                                                                 (0x1fU 
                                                                  & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                     >> 0x14U)))))
                                                             : 
                                                            ((0x400000U 
                                                              & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                                              ? 
                                                             ((0U 
                                                               == (IData)(vlSelf->__PVT__priv_lvl_q)) 
                                                              & (~ 
                                                                 ((IData)(vlSelf->__PVT__u_mcounteren_csr__DOT__rdata_q) 
                                                                  >> 
                                                                  (0x1fU 
                                                                   & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                      >> 0x14U)))))
                                                              : 
                                                             ((0x200000U 
                                                               & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                                               ? 
                                                              ((0U 
                                                                == (IData)(vlSelf->__PVT__priv_lvl_q)) 
                                                               & (~ 
                                                                  ((IData)(vlSelf->__PVT__u_mcounteren_csr__DOT__rdata_q) 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                       >> 0x14U)))))
                                                               : 
                                                              ((1U 
                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                   >> 0x14U)) 
                                                               || ((0U 
                                                                    == (IData)(vlSelf->__PVT__priv_lvl_q)) 
                                                                   & (~ 
                                                                      ((IData)(vlSelf->__PVT__u_mcounteren_csr__DOT__rdata_q) 
                                                                       >> 
                                                                       (0x1fU 
                                                                        & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                                           >> 0x14U))))))))))))));
            }
        } else if ((0x20000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
            if ((0x10000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                if ((0x8000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    if ((0x4000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        vlSelf->__PVT__illegal_csr = 1U;
                    } else if ((0x2000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        vlSelf->__PVT__illegal_csr = 1U;
                    } else if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                         >> 0x18U)))) {
                        if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                      >> 0x17U)))) {
                            if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                          >> 0x16U)))) {
                                if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                              >> 0x15U)))) {
                                    if ((0x100000U 
                                         & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                        vlSelf->__PVT__illegal_csr = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x4000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    vlSelf->__PVT__illegal_csr = 1U;
                } else if ((0x2000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    vlSelf->__PVT__illegal_csr = 1U;
                } else if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                     >> 0x18U)))) {
                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                  >> 0x17U)))) {
                        if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                      >> 0x16U)))) {
                            if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                          >> 0x15U)))) {
                                if ((0x100000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                    vlSelf->__PVT__illegal_csr = 1U;
                                }
                            }
                        }
                    }
                }
            } else {
                vlSelf->__PVT__illegal_csr = 1U;
            }
        } else {
            vlSelf->__PVT__illegal_csr = 1U;
        }
    } else if ((0x40000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
        if ((0x20000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
            if ((0x10000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                if ((0x8000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    if ((0x4000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        if ((0x2000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            vlSelf->__PVT__illegal_csr = 1U;
                        } else if ((0x1000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            vlSelf->__PVT__illegal_csr = 1U;
                        } else if ((0x800000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            vlSelf->__PVT__illegal_csr = 1U;
                        } else if ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            vlSelf->__PVT__illegal_csr = 1U;
                        } else if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            vlSelf->__PVT__illegal_csr = 1U;
                        }
                    } else if ((0x2000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        if ((0x1000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            if ((0x800000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                vlSelf->__PVT__illegal_csr = 1U;
                            } else if ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                vlSelf->__PVT__illegal_csr = 1U;
                            }
                        } else {
                            vlSelf->__PVT__illegal_csr = 1U;
                        }
                    } else {
                        vlSelf->__PVT__illegal_csr = 1U;
                    }
                } else {
                    vlSelf->__PVT__illegal_csr = 1U;
                }
            } else {
                vlSelf->__PVT__illegal_csr = 1U;
            }
        } else {
            vlSelf->__PVT__illegal_csr = 1U;
        }
    } else if ((0x20000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
        if ((0x10000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
            if ((0x8000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                if ((0x4000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    vlSelf->__PVT__illegal_csr = 1U;
                } else if ((0x2000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                  >> 0x18U)))) {
                        if ((0x800000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            vlSelf->__PVT__illegal_csr = 1U;
                        } else if ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            vlSelf->__PVT__illegal_csr = 1U;
                        }
                    }
                } else {
                    vlSelf->__PVT__illegal_csr = 1U;
                }
            } else if ((0x4000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                if ((0x2000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    vlSelf->__PVT__illegal_csr = 1U;
                } else if ((0x1000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    vlSelf->__PVT__illegal_csr = 1U;
                } else if ((0x800000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    vlSelf->__PVT__illegal_csr = 1U;
                } else if ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        vlSelf->__PVT__illegal_csr = 1U;
                    } else if ((0x100000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        vlSelf->__PVT__illegal_csr = 1U;
                    }
                }
            } else if ((0x2000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                              >> 0x18U)))) {
                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                  >> 0x17U)))) {
                        if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                      >> 0x16U)))) {
                            if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                              >> 0x14U)))) {
                                    vlSelf->__PVT__illegal_csr = 1U;
                                }
                            } else if ((0x100000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                vlSelf->__PVT__illegal_csr = 1U;
                            }
                        }
                    }
                }
            } else if ((0x1000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                if ((0x800000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    if ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        vlSelf->__PVT__illegal_csr = 1U;
                    } else if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        if ((0x100000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            vlSelf->__PVT__illegal_csr = 1U;
                        }
                    } else {
                        vlSelf->__PVT__illegal_csr = 1U;
                    }
                } else if ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    vlSelf->__PVT__illegal_csr = 1U;
                } else if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    vlSelf->__PVT__illegal_csr = 1U;
                } else if ((0x100000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    vlSelf->__PVT__illegal_csr = 1U;
                }
            } else if ((0x800000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                if ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    vlSelf->__PVT__illegal_csr = 1U;
                } else if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    if ((0x100000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        vlSelf->__PVT__illegal_csr = 1U;
                    }
                } else {
                    vlSelf->__PVT__illegal_csr = 1U;
                }
            } else if ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    if ((0x100000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        vlSelf->__PVT__illegal_csr = 1U;
                    }
                }
            } else if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                vlSelf->__PVT__illegal_csr = 1U;
            }
        } else {
            vlSelf->__PVT__illegal_csr = 1U;
        }
    } else {
        vlSelf->__PVT__illegal_csr = 1U;
    }
    if (__VdfgExtracted_he83216a4__0) {
        vlSelf->__PVT__illegal_csr = 1U;
    }
    vlSelf->__PVT__csr_rdata_int = 0U;
    if ((vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
         >> 0x1fU)) {
        if ((0x40000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
            if ((0x20000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                if ((0x10000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                  >> 0x1bU)))) {
                        if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                      >> 0x1aU)))) {
                            if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                          >> 0x19U)))) {
                                if ((0x1000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                  >> 0x17U)))) {
                                        if ((0x400000U 
                                             & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                     >> 0x15U)))) {
                                                vlSelf->__PVT__csr_rdata_int = 0U;
                                            }
                                        } else if (
                                                   (0x200000U 
                                                    & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                            vlSelf->__PVT__csr_rdata_int 
                                                = (
                                                   (0x100000U 
                                                    & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                                    ? 0U
                                                    : 0x16U);
                                        } else if (
                                                   (0x100000U 
                                                    & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                            vlSelf->__PVT__csr_rdata_int = 0U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } else if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                 >> 0x1cU)))) {
                if ((0x8000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                  >> 0x1aU)))) {
                        if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                      >> 0x19U)))) {
                            if ((0x1000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                vlSelf->__PVT__csr_rdata_int 
                                    = (IData)((vlSelf->__PVT__mhpmcounter
                                               [(0x1fU 
                                                 & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                    >> 0x14U))] 
                                               >> 0x20U));
                            } else if ((0x800000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                vlSelf->__PVT__csr_rdata_int 
                                    = (IData)((vlSelf->__PVT__mhpmcounter
                                               [(0x1fU 
                                                 & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                    >> 0x14U))] 
                                               >> 0x20U));
                            } else if ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                vlSelf->__PVT__csr_rdata_int 
                                    = (IData)((vlSelf->__PVT__mhpmcounter
                                               [(0x1fU 
                                                 & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                    >> 0x14U))] 
                                               >> 0x20U));
                            } else if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                vlSelf->__PVT__csr_rdata_int 
                                    = (IData)((vlSelf->__PVT__mhpmcounter
                                               [(0x1fU 
                                                 & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                    >> 0x14U))] 
                                               >> 0x20U));
                            } else if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                 >> 0x14U)))) {
                                vlSelf->__PVT__csr_rdata_int 
                                    = (IData)((vlSelf->__PVT__mhpmcounter
                                               [(0x1fU 
                                                 & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                    >> 0x14U))] 
                                               >> 0x20U));
                            }
                        }
                    }
                } else if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                     >> 0x1aU)))) {
                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                  >> 0x19U)))) {
                        if ((0x1000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            vlSelf->__PVT__csr_rdata_int 
                                = (IData)(vlSelf->__PVT__mhpmcounter
                                          [(0x1fU & 
                                            (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                             >> 0x14U))]);
                        } else if ((0x800000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            vlSelf->__PVT__csr_rdata_int 
                                = (IData)(vlSelf->__PVT__mhpmcounter
                                          [(0x1fU & 
                                            (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                             >> 0x14U))]);
                        } else if ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            vlSelf->__PVT__csr_rdata_int 
                                = (IData)(vlSelf->__PVT__mhpmcounter
                                          [(0x1fU & 
                                            (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                             >> 0x14U))]);
                        } else if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            vlSelf->__PVT__csr_rdata_int 
                                = (IData)(vlSelf->__PVT__mhpmcounter
                                          [(0x1fU & 
                                            (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                             >> 0x14U))]);
                        } else if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                             >> 0x14U)))) {
                            vlSelf->__PVT__csr_rdata_int 
                                = (IData)(vlSelf->__PVT__mhpmcounter
                                          [(0x1fU & 
                                            (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                             >> 0x14U))]);
                        }
                    }
                }
            }
        } else if ((0x20000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
            if ((0x10000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                if ((0x8000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                  >> 0x1aU)))) {
                        if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                      >> 0x19U)))) {
                            if ((0x1000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                vlSelf->__PVT__csr_rdata_int 
                                    = (IData)((vlSelf->__PVT__mhpmcounter
                                               [(0x1fU 
                                                 & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                    >> 0x14U))] 
                                               >> 0x20U));
                            } else if ((0x800000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                vlSelf->__PVT__csr_rdata_int 
                                    = (IData)((vlSelf->__PVT__mhpmcounter
                                               [(0x1fU 
                                                 & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                    >> 0x14U))] 
                                               >> 0x20U));
                            } else if ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                vlSelf->__PVT__csr_rdata_int 
                                    = (IData)((vlSelf->__PVT__mhpmcounter
                                               [(0x1fU 
                                                 & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                    >> 0x14U))] 
                                               >> 0x20U));
                            } else if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                vlSelf->__PVT__csr_rdata_int 
                                    = (IData)((vlSelf->__PVT__mhpmcounter
                                               [(0x1fU 
                                                 & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                    >> 0x14U))] 
                                               >> 0x20U));
                            } else if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                 >> 0x14U)))) {
                                vlSelf->__PVT__csr_rdata_int 
                                    = (IData)((vlSelf->__PVT__mhpmcounter
                                               [(0x1fU 
                                                 & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                    >> 0x14U))] 
                                               >> 0x20U));
                            }
                        }
                    }
                } else if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                     >> 0x1aU)))) {
                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                  >> 0x19U)))) {
                        if ((0x1000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            vlSelf->__PVT__csr_rdata_int 
                                = (IData)(vlSelf->__PVT__mhpmcounter
                                          [(0x1fU & 
                                            (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                             >> 0x14U))]);
                        } else if ((0x800000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            vlSelf->__PVT__csr_rdata_int 
                                = (IData)(vlSelf->__PVT__mhpmcounter
                                          [(0x1fU & 
                                            (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                             >> 0x14U))]);
                        } else if ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            vlSelf->__PVT__csr_rdata_int 
                                = (IData)(vlSelf->__PVT__mhpmcounter
                                          [(0x1fU & 
                                            (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                             >> 0x14U))]);
                        } else if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            vlSelf->__PVT__csr_rdata_int 
                                = (IData)(vlSelf->__PVT__mhpmcounter
                                          [(0x1fU & 
                                            (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                             >> 0x14U))]);
                        } else if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                             >> 0x14U)))) {
                            vlSelf->__PVT__csr_rdata_int 
                                = (IData)(vlSelf->__PVT__mhpmcounter
                                          [(0x1fU & 
                                            (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                             >> 0x14U))]);
                        }
                    }
                }
            }
        }
    } else if ((0x40000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
        if ((0x20000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
            if ((0x10000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                if ((0x8000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    if ((0x4000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                      >> 0x19U)))) {
                            if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                          >> 0x18U)))) {
                                if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                              >> 0x17U)))) {
                                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                  >> 0x16U)))) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                    >> 0x15U)))) {
                                            vlSelf->__PVT__csr_rdata_int 
                                                = (
                                                   (0x100000U 
                                                    & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                                    ? 0U
                                                    : (IData)(vlSelf->__PVT__u_cpuctrlsts_part_csr__DOT__rdata_q));
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((0x2000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        if ((0x1000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                          >> 0x17U)))) {
                                if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                              >> 0x16U)))) {
                                    vlSelf->__PVT__csr_rdata_int 
                                        = ((0x200000U 
                                            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                            ? ((0x100000U 
                                                & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                                ? vlSelf->__PVT__u_dscratch1_csr__DOT__rdata_q
                                                : vlSelf->__PVT__u_dscratch0_csr__DOT__rdata_q)
                                            : ((0x100000U 
                                                & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                                ? vlSelf->__PVT__u_depc_csr__DOT__rdata_q
                                                : vlSelf->__PVT__u_dcsr_csr__DOT__rdata_q));
                                }
                            }
                        } else if ((0x800000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                          >> 0x16U)))) {
                                if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                  >> 0x14U)))) {
                                        vlSelf->__PVT__csr_rdata_int = 0U;
                                    }
                                } else if ((1U & (~ 
                                                  (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                   >> 0x14U)))) {
                                    vlSelf->__PVT__csr_rdata_int = 0U;
                                }
                            }
                        } else if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                             >> 0x16U)))) {
                            vlSelf->__PVT__csr_rdata_int = 0U;
                        }
                    }
                }
            }
        } else if ((0x10000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
            if ((0x8000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                              >> 0x1aU)))) {
                    if ((0x2000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                      >> 0x18U)))) {
                            if ((0x800000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                              >> 0x16U)))) {
                                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                  >> 0x15U)))) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                    >> 0x14U)))) {
                                            vlSelf->__PVT__csr_rdata_int = 0U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else if ((0x20000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
        if ((0x10000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
            if ((0x8000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                              >> 0x1aU)))) {
                    if ((0x2000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        if ((0x1000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            vlSelf->__PVT__csr_rdata_int 
                                = ((0x800000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                    ? ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                        ? ((0x200000U 
                                            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                            ? ((0x100000U 
                                                & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                                ? vlSelf->__PVT__pmp_addr_rdata
                                               [0xfU]
                                                : vlSelf->__PVT__pmp_addr_rdata
                                               [0xeU])
                                            : ((0x100000U 
                                                & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                                ? vlSelf->__PVT__pmp_addr_rdata
                                               [0xdU]
                                                : vlSelf->__PVT__pmp_addr_rdata
                                               [0xcU]))
                                        : ((0x200000U 
                                            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                            ? ((0x100000U 
                                                & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                                ? vlSelf->__PVT__pmp_addr_rdata
                                               [0xbU]
                                                : vlSelf->__PVT__pmp_addr_rdata
                                               [0xaU])
                                            : ((0x100000U 
                                                & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                                ? vlSelf->__PVT__pmp_addr_rdata
                                               [9U]
                                                : vlSelf->__PVT__pmp_addr_rdata
                                               [8U])))
                                    : ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                        ? ((0x200000U 
                                            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                            ? ((0x100000U 
                                                & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                                ? vlSelf->__PVT__pmp_addr_rdata
                                               [7U]
                                                : vlSelf->__PVT__pmp_addr_rdata
                                               [6U])
                                            : ((0x100000U 
                                                & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                                ? vlSelf->__PVT__pmp_addr_rdata
                                               [5U]
                                                : vlSelf->__PVT__pmp_addr_rdata
                                               [4U]))
                                        : ((0x200000U 
                                            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                            ? ((0x100000U 
                                                & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                                ? vlSelf->__PVT__pmp_addr_rdata
                                               [3U]
                                                : vlSelf->__PVT__pmp_addr_rdata
                                               [2U])
                                            : ((0x100000U 
                                                & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                                ? vlSelf->__PVT__pmp_addr_rdata
                                               [1U]
                                                : vlSelf->__PVT__pmp_addr_rdata
                                               [0U]))));
                        } else if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                             >> 0x17U)))) {
                            if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                          >> 0x16U)))) {
                                vlSelf->__PVT__csr_rdata_int 
                                    = ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                        ? ((0x100000U 
                                            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                            ? ((vlSelf->__PVT__pmp_cfg_rdata
                                                [0xfU] 
                                                << 0x18U) 
                                               | ((vlSelf->__PVT__pmp_cfg_rdata
                                                   [0xeU] 
                                                   << 0x10U) 
                                                  | ((vlSelf->__PVT__pmp_cfg_rdata
                                                      [0xdU] 
                                                      << 8U) 
                                                     | vlSelf->__PVT__pmp_cfg_rdata
                                                     [0xcU])))
                                            : ((vlSelf->__PVT__pmp_cfg_rdata
                                                [0xbU] 
                                                << 0x18U) 
                                               | ((vlSelf->__PVT__pmp_cfg_rdata
                                                   [0xaU] 
                                                   << 0x10U) 
                                                  | ((vlSelf->__PVT__pmp_cfg_rdata
                                                      [9U] 
                                                      << 8U) 
                                                     | vlSelf->__PVT__pmp_cfg_rdata
                                                     [8U]))))
                                        : ((0x100000U 
                                            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                            ? ((vlSelf->__PVT__pmp_cfg_rdata
                                                [7U] 
                                                << 0x18U) 
                                               | ((vlSelf->__PVT__pmp_cfg_rdata
                                                   [6U] 
                                                   << 0x10U) 
                                                  | ((vlSelf->__PVT__pmp_cfg_rdata
                                                      [5U] 
                                                      << 8U) 
                                                     | vlSelf->__PVT__pmp_cfg_rdata
                                                     [4U])))
                                            : ((vlSelf->__PVT__pmp_cfg_rdata
                                                [3U] 
                                                << 0x18U) 
                                               | ((vlSelf->__PVT__pmp_cfg_rdata
                                                   [2U] 
                                                   << 0x10U) 
                                                  | ((vlSelf->__PVT__pmp_cfg_rdata
                                                      [1U] 
                                                      << 8U) 
                                                     | vlSelf->__PVT__pmp_cfg_rdata
                                                     [0U])))));
                            }
                        }
                    }
                }
            } else if ((0x4000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                              >> 0x19U)))) {
                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                  >> 0x18U)))) {
                        if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                      >> 0x17U)))) {
                            if ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                              >> 0x15U)))) {
                                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                  >> 0x14U)))) {
                                        vlSelf->__PVT__csr_rdata_int = 0U;
                                        vlSelf->__PVT__csr_rdata_int 
                                            = (0xfffffff7U 
                                               & vlSelf->__PVT__csr_rdata_int);
                                        vlSelf->__PVT__csr_rdata_int 
                                            = (0xffffff7fU 
                                               & vlSelf->__PVT__csr_rdata_int);
                                        vlSelf->__PVT__csr_rdata_int 
                                            = (0xfffff7ffU 
                                               & vlSelf->__PVT__csr_rdata_int);
                                        vlSelf->__PVT__csr_rdata_int 
                                            = (0x8000ffffU 
                                               & vlSelf->__PVT__csr_rdata_int);
                                    }
                                }
                            } else {
                                vlSelf->__PVT__csr_rdata_int 
                                    = ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                        ? ((0x100000U 
                                            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                            ? vlSelf->__PVT__u_mtval_csr__DOT__rdata_q
                                            : (((IData)(
                                                        (0U 
                                                         != 
                                                         (0x60U 
                                                          & (IData)(vlSelf->__PVT__u_mcause_csr__DOT__rdata_q)))) 
                                                << 0x1fU) 
                                               | ((((0x40U 
                                                     & (IData)(vlSelf->__PVT__u_mcause_csr__DOT__rdata_q))
                                                     ? 0x3ffffffU
                                                     : 0U) 
                                                   << 5U) 
                                                  | (0x1fU 
                                                     & (IData)(vlSelf->__PVT__u_mcause_csr__DOT__rdata_q)))))
                                        : ((0x100000U 
                                            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)
                                            ? vlSelf->__PVT__u_mepc_csr__DOT__rdata_q
                                            : vlSelf->__PVT__u_mscratch_csr__DOT__rdata_q));
                            }
                        }
                    }
                }
            } else if ((0x2000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                if ((0x1000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    vlSelf->__PVT__csr_rdata_int = 
                        vlSelf->__PVT__mhpmevent[(0x1fU 
                                                  & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                     >> 0x14U))];
                } else if ((0x800000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    vlSelf->__PVT__csr_rdata_int = 
                        vlSelf->__PVT__mhpmevent[(0x1fU 
                                                  & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                     >> 0x14U))];
                } else if ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    vlSelf->__PVT__csr_rdata_int = 
                        vlSelf->__PVT__mhpmevent[(0x1fU 
                                                  & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                     >> 0x14U))];
                } else if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    if ((0x100000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        vlSelf->__PVT__csr_rdata_int 
                            = vlSelf->__PVT__mhpmevent
                            [(0x1fU & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                       >> 0x14U))];
                    }
                } else if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                     >> 0x14U)))) {
                    vlSelf->__PVT__csr_rdata_int = vlSelf->__PVT__mcountinhibit_q;
                }
            } else if ((0x1000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                if ((0x800000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                  >> 0x16U)))) {
                        if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                          >> 0x14U)))) {
                                vlSelf->__PVT__csr_rdata_int = 0U;
                            }
                        }
                    }
                } else if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                     >> 0x16U)))) {
                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                  >> 0x15U)))) {
                        if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                      >> 0x14U)))) {
                            vlSelf->__PVT__csr_rdata_int = 0U;
                        }
                    }
                }
            } else if ((0x800000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                              >> 0x16U)))) {
                    if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                      >> 0x14U)))) {
                            vlSelf->__PVT__csr_rdata_int = 0U;
                        }
                    }
                }
            } else if ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                  >> 0x14U)))) {
                        vlSelf->__PVT__csr_rdata_int 
                            = vlSelf->__PVT__u_mcounteren_csr__DOT__rdata_q;
                    }
                } else if ((0x100000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    vlSelf->__PVT__csr_rdata_int = vlSelf->__PVT__u_mtvec_csr__DOT__rdata_q;
                } else {
                    vlSelf->__PVT__csr_rdata_int = 0U;
                    vlSelf->__PVT__csr_rdata_int = 
                        ((0xfffffff7U & vlSelf->__PVT__csr_rdata_int) 
                         | (8U & (vlSelf->__PVT__u_mie_csr__DOT__rdata_q 
                                  >> 0xeU)));
                    vlSelf->__PVT__csr_rdata_int = 
                        ((0xffffff7fU & vlSelf->__PVT__csr_rdata_int) 
                         | (0x80U & (vlSelf->__PVT__u_mie_csr__DOT__rdata_q 
                                     >> 9U)));
                    vlSelf->__PVT__csr_rdata_int = 
                        ((0xfffff7ffU & vlSelf->__PVT__csr_rdata_int) 
                         | (0x800U & (vlSelf->__PVT__u_mie_csr__DOT__rdata_q 
                                      >> 4U)));
                    vlSelf->__PVT__csr_rdata_int = 
                        ((0x8000ffffU & vlSelf->__PVT__csr_rdata_int) 
                         | (0x7fff0000U & (vlSelf->__PVT__u_mie_csr__DOT__rdata_q 
                                           << 0x10U)));
                }
            } else if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                 >> 0x15U)))) {
                if ((0x100000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    vlSelf->__PVT__csr_rdata_int = 0x40101104U;
                } else {
                    vlSelf->__PVT__csr_rdata_int = 0U;
                    vlSelf->__PVT__csr_rdata_int = 
                        ((0xfffffff7U & vlSelf->__PVT__csr_rdata_int) 
                         | (8U & ((IData)(vlSelf->__PVT__u_mstatus_csr__DOT__rdata_q) 
                                  >> 2U)));
                    vlSelf->__PVT__csr_rdata_int = 
                        ((0xffffff7fU & vlSelf->__PVT__csr_rdata_int) 
                         | (0x80U & ((IData)(vlSelf->__PVT__u_mstatus_csr__DOT__rdata_q) 
                                     << 3U)));
                    vlSelf->__PVT__csr_rdata_int = 
                        ((0xffffe7ffU & vlSelf->__PVT__csr_rdata_int) 
                         | (0x1800U & ((IData)(vlSelf->__PVT__u_mstatus_csr__DOT__rdata_q) 
                                       << 9U)));
                    vlSelf->__PVT__csr_rdata_int = 
                        ((0xfffdffffU & vlSelf->__PVT__csr_rdata_int) 
                         | (0x20000U & ((IData)(vlSelf->__PVT__u_mstatus_csr__DOT__rdata_q) 
                                        << 0x10U)));
                    vlSelf->__PVT__csr_rdata_int = 
                        ((0xffdfffffU & vlSelf->__PVT__csr_rdata_int) 
                         | (0x200000U & ((IData)(vlSelf->__PVT__u_mstatus_csr__DOT__rdata_q) 
                                         << 0x15U)));
                }
            }
        }
    }
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__1(Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__1\n"); );
    // Body
    vlSelf->__PVT__csr_wdata_int = ((2U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_op_o))
                                     ? ((1U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_op_o))
                                         ? ((~ vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a) 
                                            & vlSelf->__PVT__csr_rdata_int)
                                         : (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                            | vlSelf->__PVT__csr_rdata_int))
                                     : vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a);
    vlSelf->__PVT__csr_wr = ((1U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_op_o)) 
                             | ((2U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_op_o)) 
                                | (3U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_op_o))));
    vlSelf->illegal_csr_insn_o = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_access_o) 
                                  & ((IData)(vlSelf->__PVT__illegal_csr) 
                                     | (((3U == (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                 >> 0x1eU)) 
                                         & (IData)(vlSelf->__PVT__csr_wr)) 
                                        | (((3U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                   >> 0x1cU)) 
                                            > (IData)(vlSelf->__PVT__priv_lvl_q)) 
                                           | ((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__controller_i__DOT__debug_mode_q)) 
                                              & (IData)(vlSelf->__PVT__dbg_csr))))));
}
