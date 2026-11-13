// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rtnn_c2_soc_42.h for the primary calling header

#include "Vtb_rtnn_c2_soc_42__pch.h"
#include "Vtb_rtnn_c2_soc_42__Syms.h"
#include "Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7.h"

VL_ATTR_COLD void Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___stl_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__0(Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___stl_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__0\n"); );
    // Init
    IData/*31:0*/ __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o;
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o = 0;
    IData/*31:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata;
    __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata = 0;
    CData/*0:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err;
    __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err = 0;
    CData/*0:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unaligned_is_compressed;
    __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unaligned_is_compressed = 0;
    IData/*16:0*/ __Vfunc_gen_dummy_instr__DOT__dummy_instr_i__DOT__sv2v_cast_92F3A__44__Vfuncout;
    __Vfunc_gen_dummy_instr__DOT__dummy_instr_i__DOT__sv2v_cast_92F3A__44__Vfuncout = 0;
    IData/*16:0*/ __Vfunc_gen_dummy_instr__DOT__dummy_instr_i__DOT__sv2v_cast_92F3A__44__inp;
    __Vfunc_gen_dummy_instr__DOT__dummy_instr_i__DOT__sv2v_cast_92F3A__44__inp = 0;
    // Body
    __Vfunc_gen_dummy_instr__DOT__dummy_instr_i__DOT__sv2v_cast_92F3A__44__inp 
        = ((0x10000U & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                        >> 5U)) | ((0x8000U & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                               >> 1U)) 
                                   | ((0x4000U & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                  << 9U)) 
                                      | ((0x2000U & 
                                          (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                           << 4U)) 
                                         | ((0x1000U 
                                             & vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q) 
                                            | ((0x800U 
                                                & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                   << 0xbU)) 
                                               | ((0x400U 
                                                   & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                      >> 9U)) 
                                                  | ((0x200U 
                                                      & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                         >> 0x14U)) 
                                                     | ((0x100U 
                                                         & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                            << 4U)) 
                                                        | ((0x80U 
                                                            & vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q) 
                                                           | ((0x40U 
                                                               & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                                  << 5U)) 
                                                              | ((0x20U 
                                                                  & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                                     >> 0x17U)) 
                                                                 | ((0x10U 
                                                                     & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                                        >> 6U)) 
                                                                    | ((8U 
                                                                        & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                                           >> 0xeU)) 
                                                                       | ((4U 
                                                                           & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                                              >> 0x14U)) 
                                                                          | ((2U 
                                                                              & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                                                >> 0x16U)) 
                                                                             | (1U 
                                                                                & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                                                >> 0xdU))))))))))))))))));
    __Vfunc_gen_dummy_instr__DOT__dummy_instr_i__DOT__sv2v_cast_92F3A__44__Vfuncout 
        = __Vfunc_gen_dummy_instr__DOT__dummy_instr_i__DOT__sv2v_cast_92F3A__44__inp;
    vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_data 
        = __Vfunc_gen_dummy_instr__DOT__dummy_instr_i__DOT__sv2v_cast_92F3A__44__Vfuncout;
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid 
        = ((~ (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_q)) 
           & (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__ram_instr_rvalid));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_d[0U] 
        = ((2U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))
            ? vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q[1U]
            : (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_d[1U] 
        = (IData)((((QData)((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core)) 
                    << 0x20U) | (QData)((IData)(((4U 
                                                  & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))
                                                  ? 
                                                 vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q[2U]
                                                  : (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core))))));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_d[2U] 
        = (IData)(((((QData)((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core)) 
                     << 0x20U) | (QData)((IData)(((4U 
                                                   & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))
                                                   ? 
                                                  vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q[2U]
                                                   : (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core))))) 
                   >> 0x20U));
    vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o 
        = ((0x7eU & (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
           | (1U & VL_REDXOR_64((0x12606bd25ULL & (0x2a00000000ULL 
                                                   ^ vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core)))));
    vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o 
        = ((0x7dU & (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
           | (2U & (VL_REDXOR_64((0x2deba8050ULL & 
                                  (0x2a00000000ULL 
                                   ^ vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core))) 
                    << 1U)));
    vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o 
        = ((0x7bU & (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
           | (4U & (VL_REDXOR_64((0x4413d89aaULL & 
                                  (0x2a00000000ULL 
                                   ^ vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core))) 
                    << 2U)));
    vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o 
        = ((0x77U & (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
           | (8U & (VL_REDXOR_64((0x831234ed1ULL & 
                                  (0x2a00000000ULL 
                                   ^ vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core))) 
                    << 3U)));
    vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o 
        = ((0x6fU & (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
           | (0x10U & (VL_REDXOR_64((0x10c2c1323bULL 
                                     & (0x2a00000000ULL 
                                        ^ vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core))) 
                       << 4U)));
    vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o 
        = ((0x5fU & (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
           | (0x20U & (VL_REDXOR_64((0x202dcc624cULL 
                                     & (0x2a00000000ULL 
                                        ^ vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core))) 
                       << 5U)));
    vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o 
        = ((0x3fU & (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
           | (0x40U & (VL_REDXOR_64((0x4098505586ULL 
                                     & (0x2a00000000ULL 
                                        ^ vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core))) 
                       << 6U)));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xfffffffcU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((2U & (((0x54U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                      ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                 >> 1U))) << 1U)) | 
              (1U & ((0x19U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                     ^ (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core)))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xfffffff3U & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((8U & (((0x34U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                      ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                 >> 3U))) << 3U)) | 
              (4U & (((0x61U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                      ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                 >> 2U))) << 2U))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xffffffcfU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x20U & (((0x15U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                         ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                    >> 5U))) << 5U)) 
              | (0x10U & (((0x1aU == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                           ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                      >> 4U))) << 4U))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xffffff3fU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x80U & (((0x4cU == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                         ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                    >> 7U))) << 7U)) 
              | (0x40U & (((0x2aU == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                           ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                      >> 6U))) << 6U))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xfffffcffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x200U & (((0x38U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                          ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                     >> 9U))) << 9U)) 
              | (0x100U & (((0x45U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                            ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                       >> 8U))) << 8U))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xfffff3ffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x800U & (((0xdU == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                          ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                     >> 0xbU))) << 0xbU)) 
              | (0x400U & (((0x49U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                            ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                       >> 0xaU))) << 0xaU))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xffffcfffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x2000U & (((0x31U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                           ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                      >> 0xdU))) << 0xdU)) 
              | (0x1000U & (((0x51U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                             ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                        >> 0xcU))) 
                            << 0xcU))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xffff3fffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x8000U & (((7U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                           ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                      >> 0xfU))) << 0xfU)) 
              | (0x4000U & (((0x68U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                             ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                        >> 0xeU))) 
                            << 0xeU))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xfffcffffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x20000U & (((0xbU == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                            ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                       >> 0x11U))) 
                           << 0x11U)) | (0x10000U & 
                                         (((0x1cU == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                                           ^ (IData)(
                                                     (vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                                      >> 0x10U))) 
                                          << 0x10U))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xfff3ffffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x80000U & (((0x26U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                            ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                       >> 0x13U))) 
                           << 0x13U)) | (0x40000U & 
                                         (((0x25U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                                           ^ (IData)(
                                                     (vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                                      >> 0x12U))) 
                                          << 0x12U))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xffcfffffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x200000U & (((0xeU == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                             ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                        >> 0x15U))) 
                            << 0x15U)) | (0x100000U 
                                          & (((0x46U 
                                               == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                                              ^ (IData)(
                                                        (vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                                         >> 0x14U))) 
                                             << 0x14U))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xff3fffffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x800000U & (((0x32U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                             ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                        >> 0x17U))) 
                            << 0x17U)) | (0x400000U 
                                          & (((0x70U 
                                               == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                                              ^ (IData)(
                                                        (vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                                         >> 0x16U))) 
                                             << 0x16U))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xfcffffffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x2000000U & (((0x13U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                              ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                         >> 0x19U))) 
                             << 0x19U)) | (0x1000000U 
                                           & (((0x2cU 
                                                == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                                               ^ (IData)(
                                                         (vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                                          >> 0x18U))) 
                                              << 0x18U))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xf3ffffffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x8000000U & (((0x62U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                              ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                         >> 0x1bU))) 
                             << 0x1bU)) | (0x4000000U 
                                           & (((0x23U 
                                                == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                                               ^ (IData)(
                                                         (vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                                          >> 0x1aU))) 
                                              << 0x1aU))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xcfffffffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x20000000U & (((0x29U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                               ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                          >> 0x1dU))) 
                              << 0x1dU)) | (0x10000000U 
                                            & (((0x4aU 
                                                 == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                                                ^ (IData)(
                                                          (vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                                           >> 0x1cU))) 
                                               << 0x1cU))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0x3fffffffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((((0x52U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                           >> 0x1fU))) << 0x1fU) | 
              (0x40000000U & (((0x16U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                               ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                          >> 0x1eU))) 
                              << 0x1eU))));
    vlSelf->__PVT__g_mem_ecc__DOT__ecc_err = ((2U & (IData)(vlSelf->__PVT__g_mem_ecc__DOT__ecc_err)) 
                                              | (1U 
                                                 & VL_REDXOR_8(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)));
    vlSelf->__PVT__g_mem_ecc__DOT__ecc_err = ((1U & (IData)(vlSelf->__PVT__g_mem_ecc__DOT__ecc_err)) 
                                              | (((~ (IData)(vlSelf->__PVT__g_mem_ecc__DOT__ecc_err)) 
                                                  & (0U 
                                                     != (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o))) 
                                                 << 1U));
    if ((0x10000U & vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_data)) {
        if ((0x8000U & vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_data)) {
            vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_set = 0U;
            vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_opcode = 7U;
        } else {
            vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_set = 1U;
            vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_opcode = 4U;
        }
    } else {
        vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_set 
            = ((0x8000U & vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_data)
                ? 1U : 0U);
        vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_opcode = 0U;
    }
    vlSelf->__PVT__gen_dummy_instr__DOT__insert_dummy_instr 
        = (((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
            >> 2U) & ((IData)(vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_cnt_q) 
                      == (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_data 
                          & (3U | (0x1cU & ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
                                            >> 1U))))));
    vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h0d767fd8__0 
        = ((~ (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q)) 
           & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid));
    vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h87841355__0 
        = ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid) 
           & (IData)((2U == (6U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q)))));
    vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h18c9f2e2__0 
        = ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid) 
           & (IData)((1U == (3U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q)))));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid 
        = (1U & ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                 | (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid)));
    __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata 
        = ((1U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))
            ? vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q[0U]
            : (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core));
    vlSelf->__PVT__instr_err = ((0U != (IData)(vlSelf->__PVT__g_mem_ecc__DOT__ecc_err)) 
                                | (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__instr_err_q));
    __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err 
        = (1U & ((1U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))
                  ? (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q)
                  : (IData)(vlSelf->__PVT__instr_err)));
    vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_cnt_d 
        = ((IData)(vlSelf->__PVT__gen_dummy_instr__DOT__insert_dummy_instr)
            ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_cnt_q))));
    vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h46facb3b__0 
        = (IData)((((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                    >> 2U) | (IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h87841355__0)));
    vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_haf2cbd5f__0 
        = (1U & ((IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h18c9f2e2__0) 
                 | ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                    >> 1U)));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_d 
        = (((IData)(vlSelf->__PVT__instr_err) << 2U) 
           | ((2U & (((4U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))
                       ? ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q) 
                          >> 2U) : (IData)(vlSelf->__PVT__instr_err)) 
                     << 1U)) | (1U & ((2U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))
                                       ? ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q) 
                                          >> 1U) : (IData)(vlSelf->__PVT__instr_err)))));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__aligned_is_compressed 
        = ((~ (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err)) 
           & (3U != (3U & __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata)));
    __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unaligned_is_compressed 
        = ((~ (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err)) 
           & (3U != (3U & (__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata 
                           >> 0x10U))));
    if ((1U & vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q)) {
        if ((2U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))) {
            vlSelf->__PVT__fetch_rdata = ((vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q[1U] 
                                           << 0x10U) 
                                          | (__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata 
                                             >> 0x10U));
            vlSelf->__PVT__fetch_err = (1U & (((~ (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unaligned_is_compressed)) 
                                               & ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q) 
                                                  >> 1U)) 
                                              | (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q)));
        } else {
            vlSelf->__PVT__fetch_rdata = (((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core) 
                                           << 0x10U) 
                                          | (__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata 
                                             >> 0x10U));
            vlSelf->__PVT__fetch_err = (1U & (((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                                               & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q)) 
                                              | ((IData)(vlSelf->__PVT__instr_err) 
                                                 & ((~ (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q)) 
                                                    | (~ (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unaligned_is_compressed))))));
        }
        if (__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unaligned_is_compressed) {
            vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two = 1U;
            vlSelf->__PVT__fetch_valid_raw = (1U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid));
        } else {
            vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two = 0U;
            vlSelf->__PVT__fetch_valid_raw = (1U & 
                                              (((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                                                >> 1U) 
                                               | ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                                                  & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid))));
        }
    } else {
        vlSelf->__PVT__fetch_rdata = __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata;
        vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two 
            = vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__aligned_is_compressed;
        vlSelf->__PVT__fetch_err = (1U & (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err));
        vlSelf->__PVT__fetch_valid_raw = (1U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid));
    }
    vlSelf->__Vcellinp__compressed_decoder_i__valid_i 
        = ((~ (IData)(vlSelf->__PVT__fetch_err)) & (IData)(vlSelf->__PVT__fetch_valid_raw));
}
