// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rtnn_c2_soc_42.h for the primary calling header

#include "Vtb_rtnn_c2_soc_42__pch.h"
#include "Vtb_rtnn_c2_soc_42__Syms.h"
#include "Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9.h"

VL_ATTR_COLD void Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___stl_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__0(Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___stl_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__0\n"); );
    // Init
    CData/*0:0*/ __VdfgExtracted_he83216a4__0;
    __VdfgExtracted_he83216a4__0 = 0;
    // Body
    vlSelf->__PVT__mhpmcounter[0U] = vlSelf->__PVT__mcycle_counter_i__DOT__counter_q;
    vlSelf->__PVT__mhpmcounter[2U] = vlSelf->__PVT__minstret_counter_i__DOT__counter_q;
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
    vlSelf->__PVT__csr_rdata_int = 0U;
    vlSelf->__PVT__illegal_csr = 0U;
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
                if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                              >> 0x1cU)))) {
                    if ((0x8000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                      >> 0x1aU)))) {
                            if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                          >> 0x19U)))) {
                                if ((0x1000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                    vlSelf->__PVT__csr_rdata_int 
                                        = (IData)((
                                                   vlSelf->__PVT__mhpmcounter
                                                   [
                                                   (0x1fU 
                                                    & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                       >> 0x14U))] 
                                                   >> 0x20U));
                                } else if ((0x800000U 
                                            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                    vlSelf->__PVT__csr_rdata_int 
                                        = (IData)((
                                                   vlSelf->__PVT__mhpmcounter
                                                   [
                                                   (0x1fU 
                                                    & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                       >> 0x14U))] 
                                                   >> 0x20U));
                                } else if ((0x400000U 
                                            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                    vlSelf->__PVT__csr_rdata_int 
                                        = (IData)((
                                                   vlSelf->__PVT__mhpmcounter
                                                   [
                                                   (0x1fU 
                                                    & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                       >> 0x14U))] 
                                                   >> 0x20U));
                                } else if ((0x200000U 
                                            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                    vlSelf->__PVT__csr_rdata_int 
                                        = (IData)((
                                                   vlSelf->__PVT__mhpmcounter
                                                   [
                                                   (0x1fU 
                                                    & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                       >> 0x14U))] 
                                                   >> 0x20U));
                                } else if ((1U & (~ 
                                                  (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                   >> 0x14U)))) {
                                    vlSelf->__PVT__csr_rdata_int 
                                        = (IData)((
                                                   vlSelf->__PVT__mhpmcounter
                                                   [
                                                   (0x1fU 
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
                                              [(0x1fU 
                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                   >> 0x14U))]);
                            } else if ((0x800000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                vlSelf->__PVT__csr_rdata_int 
                                    = (IData)(vlSelf->__PVT__mhpmcounter
                                              [(0x1fU 
                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                   >> 0x14U))]);
                            } else if ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                vlSelf->__PVT__csr_rdata_int 
                                    = (IData)(vlSelf->__PVT__mhpmcounter
                                              [(0x1fU 
                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                   >> 0x14U))]);
                            } else if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                vlSelf->__PVT__csr_rdata_int 
                                    = (IData)(vlSelf->__PVT__mhpmcounter
                                              [(0x1fU 
                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                   >> 0x14U))]);
                            } else if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                 >> 0x14U)))) {
                                vlSelf->__PVT__csr_rdata_int 
                                    = (IData)(vlSelf->__PVT__mhpmcounter
                                              [(0x1fU 
                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                   >> 0x14U))]);
                            }
                        }
                    }
                }
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
                } else {
                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                  >> 0x1aU)))) {
                        if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                      >> 0x19U)))) {
                            if ((0x1000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                vlSelf->__PVT__csr_rdata_int 
                                    = (IData)(vlSelf->__PVT__mhpmcounter
                                              [(0x1fU 
                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                   >> 0x14U))]);
                            } else if ((0x800000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                vlSelf->__PVT__csr_rdata_int 
                                    = (IData)(vlSelf->__PVT__mhpmcounter
                                              [(0x1fU 
                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                   >> 0x14U))]);
                            } else if ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                vlSelf->__PVT__csr_rdata_int 
                                    = (IData)(vlSelf->__PVT__mhpmcounter
                                              [(0x1fU 
                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                   >> 0x14U))]);
                            } else if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                vlSelf->__PVT__csr_rdata_int 
                                    = (IData)(vlSelf->__PVT__mhpmcounter
                                              [(0x1fU 
                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                   >> 0x14U))]);
                            } else if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                 >> 0x14U)))) {
                                vlSelf->__PVT__csr_rdata_int 
                                    = (IData)(vlSelf->__PVT__mhpmcounter
                                              [(0x1fU 
                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                   >> 0x14U))]);
                            }
                        }
                    }
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
                            if ((0x800000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                vlSelf->__PVT__illegal_csr = 1U;
                            } else if ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                vlSelf->__PVT__illegal_csr = 1U;
                            }
                        } else {
                            if ((0x800000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                              >> 0x16U)))) {
                                    if ((0x200000U 
                                         & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                    >> 0x14U)))) {
                                            vlSelf->__PVT__csr_rdata_int = 0U;
                                        }
                                    } else if ((1U 
                                                & (~ 
                                                   (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                    >> 0x14U)))) {
                                        vlSelf->__PVT__csr_rdata_int = 0U;
                                    }
                                }
                            } else if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                 >> 0x16U)))) {
                                vlSelf->__PVT__csr_rdata_int = 0U;
                            }
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
            if ((0x10000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                if ((0x8000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                  >> 0x1aU)))) {
                        if ((0x2000000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                          >> 0x18U)))) {
                                if ((0x800000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                  >> 0x16U)))) {
                                        if ((1U & (~ 
                                                   (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                    >> 0x15U)))) {
                                            if ((1U 
                                                 & (~ 
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
            vlSelf->__PVT__illegal_csr = 1U;
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
                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                  >> 0x16U)))) {
                        if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                          >> 0x14U)))) {
                                vlSelf->__PVT__csr_rdata_int = 0U;
                            }
                        }
                    }
                    if ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        vlSelf->__PVT__illegal_csr = 1U;
                    } else if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        if ((0x100000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                            vlSelf->__PVT__illegal_csr = 1U;
                        }
                    } else {
                        vlSelf->__PVT__illegal_csr = 1U;
                    }
                } else {
                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                  >> 0x16U)))) {
                        if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                      >> 0x15U)))) {
                            if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                          >> 0x14U)))) {
                                vlSelf->__PVT__csr_rdata_int = 0U;
                            }
                        }
                    }
                    if ((0x400000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        vlSelf->__PVT__illegal_csr = 1U;
                    } else if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        vlSelf->__PVT__illegal_csr = 1U;
                    } else if ((0x100000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        vlSelf->__PVT__illegal_csr = 1U;
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
                    if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                  >> 0x14U)))) {
                        vlSelf->__PVT__csr_rdata_int 
                            = vlSelf->__PVT__u_mcounteren_csr__DOT__rdata_q;
                    }
                    if ((0x100000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        vlSelf->__PVT__illegal_csr = 1U;
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
            } else {
                if ((1U & (~ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                              >> 0x15U)))) {
                    if ((0x100000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                        vlSelf->__PVT__csr_rdata_int = 0x40101104U;
                    } else {
                        vlSelf->__PVT__csr_rdata_int = 0U;
                        vlSelf->__PVT__csr_rdata_int 
                            = ((0xfffffff7U & vlSelf->__PVT__csr_rdata_int) 
                               | (8U & ((IData)(vlSelf->__PVT__u_mstatus_csr__DOT__rdata_q) 
                                        >> 2U)));
                        vlSelf->__PVT__csr_rdata_int 
                            = ((0xffffff7fU & vlSelf->__PVT__csr_rdata_int) 
                               | (0x80U & ((IData)(vlSelf->__PVT__u_mstatus_csr__DOT__rdata_q) 
                                           << 3U)));
                        vlSelf->__PVT__csr_rdata_int 
                            = ((0xffffe7ffU & vlSelf->__PVT__csr_rdata_int) 
                               | (0x1800U & ((IData)(vlSelf->__PVT__u_mstatus_csr__DOT__rdata_q) 
                                             << 9U)));
                        vlSelf->__PVT__csr_rdata_int 
                            = ((0xfffdffffU & vlSelf->__PVT__csr_rdata_int) 
                               | (0x20000U & ((IData)(vlSelf->__PVT__u_mstatus_csr__DOT__rdata_q) 
                                              << 0x10U)));
                        vlSelf->__PVT__csr_rdata_int 
                            = ((0xffdfffffU & vlSelf->__PVT__csr_rdata_int) 
                               | (0x200000U & ((IData)(vlSelf->__PVT__u_mstatus_csr__DOT__rdata_q) 
                                               << 0x15U)));
                    }
                }
                if ((0x200000U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) {
                    vlSelf->__PVT__illegal_csr = 1U;
                }
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
}

VL_ATTR_COLD void Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___stl_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__1(Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___stl_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__1\n"); );
    // Body
    vlSelf->__PVT__csr_wr = ((1U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_op_o)) 
                             | ((2U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_op_o)) 
                                | (3U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_op_o))));
    vlSelf->__PVT__csr_wdata_int = ((2U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_op_o))
                                     ? ((1U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_op_o))
                                         ? ((~ vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a) 
                                            & vlSelf->__PVT__csr_rdata_int)
                                         : (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                            | vlSelf->__PVT__csr_rdata_int))
                                     : vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a);
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
