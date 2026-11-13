// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rtnn_c2_soc_42.h for the primary calling header

#include "Vtb_rtnn_c2_soc_42__pch.h"
#include "Vtb_rtnn_c2_soc_42___024root.h"

VlCoroutine Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__0__0(Vtb_rtnn_c2_soc_42___024root* vlSelf);
VlCoroutine Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__0__1(Vtb_rtnn_c2_soc_42___024root* vlSelf);
VlCoroutine Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__0__2(Vtb_rtnn_c2_soc_42___024root* vlSelf);
VlCoroutine Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__0__3(Vtb_rtnn_c2_soc_42___024root* vlSelf);
VlCoroutine Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__0__4(Vtb_rtnn_c2_soc_42___024root* vlSelf);

VL_INLINE_OPT VlCoroutine Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__0(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    co_await Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__0__0(vlSelf);
    co_await Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__0__1(vlSelf);
    co_await Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__0__2(vlSelf);
    co_await Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__0__3(vlSelf);
    co_await Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__0__4(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__1(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(7ULL, nullptr, 
                                           "tb_rtnn_c2_soc_42.sv", 
                                           25);
        vlSelf->__Vdlyvval__tb_rtnn_c2_soc_42__DOT__tck__v0 
            = (1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tck)));
        vlSelf->__Vdlyvset__tb_rtnn_c2_soc_42__DOT__tck__v0 = 1U;
    }
}

VL_INLINE_OPT VlCoroutine Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__2(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0xaULL, 
                                           nullptr, 
                                           "tb_rtnn_c2_soc_42.sv", 
                                           24);
        vlSelf->__Vdlyvval__tb_rtnn_c2_soc_42__DOT__clk__v0 
            = (1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__clk)));
        vlSelf->__Vdlyvset__tb_rtnn_c2_soc_42__DOT__clk__v0 = 1U;
    }
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42___024root___act_comb__TOP__0(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___act_comb__TOP__0\n"); );
    // Body
    vlSelf->tb_rtnn_c2_soc_42__DOT__tdo = (1U & ((4U 
                                                  & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir))
                                                  ? 
                                                 ((1U 
                                                   & (~ 
                                                      ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir) 
                                                       >> 1U))) 
                                                  && ((1U 
                                                       & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir))) 
                                                      && (1U 
                                                          & vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__build_shift_tck_q)))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir))
                                                    ? (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__status_shift_tck_q)
                                                    : 
                                                   vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0U])
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir)) 
                                                   && (1U 
                                                       & vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0U])))));
}

extern const VlWide<25>/*799:0*/ Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0;
extern const VlWide<12>/*383:0*/ Vtb_rtnn_c2_soc_42__ConstPool__CONST_h9ba48564_0;
extern const VlWide<25>/*799:0*/ Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0;
extern const VlWide<12>/*383:0*/ Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0;

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__1(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__1\n"); );
    // Init
    VlWide<12>/*383:0*/ __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q;
    VL_ZERO_W(384, __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q);
    IData/*31:0*/ __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__build_shift_tck_q;
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__build_shift_tck_q = 0;
    CData/*0:0*/ __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__pending_tck_q;
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__pending_tck_q = 0;
    CData/*7:0*/ __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__status_shift_tck_q;
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__status_shift_tck_q = 0;
    SData/*10:0*/ __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_count_tck_q;
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_count_tck_q = 0;
    VlWide<25>/*799:0*/ __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q;
    VL_ZERO_W(800, __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q);
    SData/*10:0*/ __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_count_tck_q;
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_count_tck_q = 0;
    // Body
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__build_shift_tck_q 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__build_shift_tck_q;
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_consume_toggle_tck_q 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_consume_toggle_tck_q;
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0U];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[1U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[1U];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[2U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[2U];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[3U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[3U];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[4U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[4U];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[5U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[5U];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[6U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[6U];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[7U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[7U];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[8U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[8U];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[9U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[9U];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xaU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xaU];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xbU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xbU];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xcU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xcU];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xdU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xdU];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xeU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xeU];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xfU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xfU];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x10U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x10U];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x11U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x11U];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x12U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x12U];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x13U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x13U];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x14U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x14U];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x15U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x15U];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x16U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x16U];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x17U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x17U];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x18U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x18U];
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_toggle_tck_q 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_toggle_tck_q;
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_count_tck_q 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_count_tck_q;
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_count_tck_q 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_count_tck_q;
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__response_pending_tck_q 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__response_pending_tck_q;
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__pending_tck_q 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__pending_tck_q;
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[1U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[1U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[2U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[2U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[3U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[3U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[4U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[4U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[5U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[5U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[6U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[6U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[7U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[7U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[8U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[8U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[9U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[9U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xaU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xaU];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xbU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xbU];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xcU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xcU];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xdU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xdU];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xeU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xeU];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xfU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xfU];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x10U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x10U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x11U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x11U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x12U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x12U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x13U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x13U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x14U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x14U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x15U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x15U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x16U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x16U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x17U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x17U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x18U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x18U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__status_shift_tck_q 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__status_shift_tck_q;
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[1U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[1U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[2U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[2U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[3U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[3U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[4U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[4U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[5U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[5U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[6U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[6U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[7U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[7U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[8U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[8U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[9U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[9U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0xaU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0xaU];
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0xbU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0xbU];
    if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_released) {
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr) {
            if ((4U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir))) {
                if ((1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir)))) {
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__build_shift_tck_q = 0x43324a32U;
                    }
                }
            }
            if ((1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir))) {
                    if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir)))) {
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0U] 
                            = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[0U];
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[1U] 
                            = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[1U];
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[2U] 
                            = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[2U];
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[3U] 
                            = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[3U];
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[4U] 
                            = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[4U];
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[5U] 
                            = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[5U];
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[6U] 
                            = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[6U];
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[7U] 
                            = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[7U];
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[8U] 
                            = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[8U];
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[9U] 
                            = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[9U];
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0xaU] 
                            = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[0xaU];
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0xbU] 
                            = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[0xbU];
                    }
                    if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir))) {
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__status_shift_tck_q 
                            = ((((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__error_sync2_tck_q) 
                                 | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__protocol_error_tck_q)) 
                                << 7U) | (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sync2_tck_q) 
                                           << 6U) | 
                                          (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__busy_sync2_tck_q) 
                                            << 5U) 
                                           | (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__pending_tck_q) 
                                               << 4U) 
                                              | (8U 
                                                 & ((~ 
                                                     ((((((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__pending_tck_q) 
                                                          | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__response_pending_tck_q)) 
                                                         | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__busy_sync2_tck_q)) 
                                                        | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sync2_tck_q)) 
                                                       | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__error_sync2_tck_q)) 
                                                      | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__protocol_error_tck_q))) 
                                                    << 3U))))));
                    } else {
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_count_tck_q = 0U;
                    }
                } else if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir))) {
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0U] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0U];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[1U] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[1U];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[2U] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[2U];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[3U] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[3U];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[4U] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[4U];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[5U] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[5U];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[6U] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[6U];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[7U] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[7U];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[8U] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[8U];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[9U] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[9U];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xaU] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xaU];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xbU] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xbU];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xcU] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xcU];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xdU] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xdU];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xeU] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xeU];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xfU] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xfU];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x10U] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x10U];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x11U] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x11U];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x12U] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x12U];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x13U] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x13U];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x14U] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x14U];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x15U] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x15U];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x16U] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x16U];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x17U] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x17U];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x18U] 
                        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x18U];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_count_tck_q = 0U;
                }
            }
        }
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr) {
            if ((4U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir))) {
                if ((1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir)))) {
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__build_shift_tck_q 
                            = (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__build_shift_tck_q 
                               >> 1U);
                    }
                }
            }
            if ((1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir))) {
                    if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir)))) {
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0U] 
                            = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_h9ba48564_0[0U] 
                               & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[1U] 
                                   << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0U] 
                                                >> 1U)));
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[1U] 
                            = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_h9ba48564_0[1U] 
                               & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[2U] 
                                   << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[1U] 
                                                >> 1U)));
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[2U] 
                            = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_h9ba48564_0[2U] 
                               & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[3U] 
                                   << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[2U] 
                                                >> 1U)));
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[3U] 
                            = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_h9ba48564_0[3U] 
                               & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[4U] 
                                   << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[3U] 
                                                >> 1U)));
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[4U] 
                            = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_h9ba48564_0[4U] 
                               & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[5U] 
                                   << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[4U] 
                                                >> 1U)));
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[5U] 
                            = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_h9ba48564_0[5U] 
                               & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[6U] 
                                   << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[5U] 
                                                >> 1U)));
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[6U] 
                            = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_h9ba48564_0[6U] 
                               & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[7U] 
                                   << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[6U] 
                                                >> 1U)));
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[7U] 
                            = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_h9ba48564_0[7U] 
                               & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[8U] 
                                   << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[7U] 
                                                >> 1U)));
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[8U] 
                            = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_h9ba48564_0[8U] 
                               & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[9U] 
                                   << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[8U] 
                                                >> 1U)));
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[9U] 
                            = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_h9ba48564_0[9U] 
                               & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0xaU] 
                                   << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[9U] 
                                                >> 1U)));
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0xaU] 
                            = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_h9ba48564_0[0xaU] 
                               & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0xbU] 
                                   << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0xaU] 
                                                >> 1U)));
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0xbU] 
                            = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_h9ba48564_0[0xbU] 
                               & (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0xbU] 
                                  >> 1U));
                    }
                    if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir))) {
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__status_shift_tck_q 
                            = (0x7fU & ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__status_shift_tck_q) 
                                        >> 1U));
                    } else if ((0x181U > (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_count_tck_q))) {
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_count_tck_q 
                            = (0x7ffU & ((IData)(1U) 
                                         + (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_count_tck_q)));
                    }
                } else if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir))) {
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0U] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[0U] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[1U] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0U] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[1U] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[1U] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[2U] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[1U] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[2U] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[2U] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[3U] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[2U] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[3U] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[3U] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[4U] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[3U] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[4U] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[4U] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[5U] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[4U] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[5U] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[5U] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[6U] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[5U] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[6U] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[6U] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[7U] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[6U] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[7U] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[7U] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[8U] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[7U] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[8U] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[8U] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[9U] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[8U] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[9U] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[9U] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xaU] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[9U] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xaU] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[0xaU] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xbU] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xaU] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xbU] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[0xbU] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xcU] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xbU] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xcU] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[0xcU] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xdU] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xcU] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xdU] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[0xdU] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xeU] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xdU] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xeU] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[0xeU] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xfU] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xeU] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xfU] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[0xfU] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x10U] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xfU] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x10U] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[0x10U] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x11U] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x10U] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x11U] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[0x11U] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x12U] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x11U] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x12U] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[0x12U] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x13U] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x12U] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x13U] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[0x13U] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x14U] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x13U] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x14U] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[0x14U] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x15U] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x14U] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x15U] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[0x15U] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x16U] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x15U] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x16U] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[0x16U] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x17U] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x16U] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x17U] 
                        = (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[0x17U] 
                           & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x18U] 
                               << 0x1fU) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x17U] 
                                            >> 1U)));
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x18U] 
                        = (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdi) 
                            << 0x1fU) | (Vtb_rtnn_c2_soc_42__ConstPool__CONST_hfdfba27a_0[0x18U] 
                                         & (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x18U] 
                                            >> 1U)));
                    if ((0x321U > (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_count_tck_q))) {
                        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_count_tck_q 
                            = (0x7ffU & ((IData)(1U) 
                                         + (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_count_tck_q)));
                    }
                }
            }
        }
        if (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_ack_sync2_tck_q) 
             == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_toggle_tck_q))) {
            __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__pending_tck_q = 0U;
        }
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_capture_pending_tck_q) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[0U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[1U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[1U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[2U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[2U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[3U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[3U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[4U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[4U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[5U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[5U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[6U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[6U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[7U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[7U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[8U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[8U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[9U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[9U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[0xaU] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0xaU];
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[0xbU] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0xbU];
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_capture_pending_tck_q = 0U;
            vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__response_pending_tck_q = 1U;
        }
        if (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_sync2_tck_q) 
             != (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_seen_tck_q))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_seen_tck_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_sync2_tck_q;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_capture_pending_tck_q = 1U;
        }
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__update_dr) {
            if ((1U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir))) {
                if ((((((((0x320U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_count_tck_q)) 
                          & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__pending_tck_q))) 
                         & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__response_pending_tck_q))) 
                        & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__busy_sync2_tck_q))) 
                       & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sync2_tck_q))) 
                      & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__error_sync2_tck_q))) 
                     & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__protocol_error_tck_q)))) {
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_toggle_tck_q 
                        = (1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_toggle_tck_q)));
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0U] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0U];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[1U] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[1U];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[2U] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[2U];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[3U] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[3U];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[4U] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[4U];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[5U] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[5U];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[6U] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[6U];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[7U] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[7U];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[8U] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[8U];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[9U] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[9U];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xaU] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xaU];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xbU] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xbU];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xcU] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xcU];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xdU] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xdU];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xeU] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xeU];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xfU] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xfU];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x10U] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x10U];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x11U] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x11U];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x12U] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x12U];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x13U] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x13U];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x14U] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x14U];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x15U] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x15U];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x16U] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x16U];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x17U] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x17U];
                    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x18U] 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x18U];
                    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__pending_tck_q = 1U;
                } else {
                    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__protocol_error_tck_q = 1U;
                }
                __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_count_tck_q = 0U;
            } else if ((((2U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir)) 
                         & (0x180U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_count_tck_q))) 
                        & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__response_pending_tck_q))) {
                vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_consume_toggle_tck_q 
                    = (1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_consume_toggle_tck_q)));
                vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__response_pending_tck_q = 0U;
            }
        }
    } else {
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__build_shift_tck_q = 0U;
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[1U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[1U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[2U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[2U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[3U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[3U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[4U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[4U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[5U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[5U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[6U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[6U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[7U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[7U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[8U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[8U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[9U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[9U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0xaU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0xaU];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0xbU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0xbU];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__status_shift_tck_q = 0U;
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_toggle_tck_q = 0U;
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_consume_toggle_tck_q = 0U;
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[1U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[1U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[2U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[2U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[3U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[3U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[4U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[4U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[5U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[5U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[6U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[6U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[7U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[7U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[8U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[8U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[9U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[9U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xaU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xaU];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xbU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xbU];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xcU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xcU];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xdU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xdU];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xeU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xeU];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xfU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xfU];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x10U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x10U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x11U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x11U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x12U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x12U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x13U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x13U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x14U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x14U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x15U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x15U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x16U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x16U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x17U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x17U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x18U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x18U];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0U];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[1U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[1U];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[2U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[2U];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[3U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[3U];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[4U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[4U];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[5U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[5U];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[6U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[6U];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[7U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[7U];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[8U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[8U];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[9U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[9U];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xaU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xaU];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xbU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xbU];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xcU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xcU];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xdU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xdU];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xeU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xeU];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xfU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xfU];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x10U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x10U];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x11U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x11U];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x12U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x12U];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x13U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x13U];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x14U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x14U];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x15U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x15U];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x16U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x16U];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x17U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x17U];
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x18U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x18U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[0U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[1U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[1U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[2U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[2U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[3U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[3U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[4U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[4U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[5U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[5U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[6U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[6U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[7U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[7U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[8U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[8U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[9U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[9U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[0xaU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0xaU];
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[0xbU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0xbU];
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_count_tck_q = 0U;
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_count_tck_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_capture_pending_tck_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_seen_tck_q = 0U;
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__pending_tck_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__protocol_error_tck_q = 0U;
        vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__response_pending_tck_q = 0U;
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__build_shift_tck_q 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__build_shift_tck_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[1U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[1U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[2U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[2U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[3U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[3U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[4U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[4U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[5U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[5U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[6U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[6U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[7U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[7U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[8U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[8U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[9U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[9U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0xaU] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0xaU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0xbU] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0xbU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__pending_tck_q 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__pending_tck_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_count_tck_q 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_count_tck_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_count_tck_q 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_count_tck_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__status_shift_tck_q 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__status_shift_tck_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[1U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[1U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[2U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[2U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[3U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[3U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[4U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[4U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[5U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[5U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[6U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[6U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[7U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[7U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[8U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[8U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[9U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[9U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xaU] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xaU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xbU] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xbU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xcU] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xcU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xdU] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xdU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xeU] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xeU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xfU] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0xfU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x10U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x10U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x11U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x11U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x12U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x12U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x13U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x13U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x14U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x14U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x15U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x15U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x16U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x16U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x17U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x17U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x18U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0x18U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_sync2_tck_q 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_released) 
           && (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_sync1_tck_q));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sync2_tck_q 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_released) 
           && (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sync1_tck_q));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__busy_sync2_tck_q 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_released) 
           && (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__busy_sync1_tck_q));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__error_sync2_tck_q 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_released) 
           && (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__error_sync1_tck_q));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_ack_sync2_tck_q 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_released) 
           && (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_ack_sync1_tck_q));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_sync1_tck_q 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_released) 
           && (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_toggle_sys_q));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sync1_tck_q 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_released) 
           && (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sys_q));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__busy_sync1_tck_q 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_released) 
           && (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__busy_sys_q));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__error_sync1_tck_q 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_released) 
           && (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__error_sys_q));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_ack_sync1_tck_q 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_released) 
           && (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_ack_toggle_sys_q));
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__5(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__5\n"); );
    // Body
    if (vlSelf->__Vdlyvset__tb_rtnn_c2_soc_42__DOT__tck__v0) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__tck = vlSelf->__Vdlyvval__tb_rtnn_c2_soc_42__DOT__tck__v0;
        vlSelf->__Vdlyvset__tb_rtnn_c2_soc_42__DOT__tck__v0 = 0U;
    }
    if (vlSelf->__Vdlyvset__tb_rtnn_c2_soc_42__DOT__clk__v0) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__clk = vlSelf->__Vdlyvval__tb_rtnn_c2_soc_42__DOT__clk__v0;
        vlSelf->__Vdlyvset__tb_rtnn_c2_soc_42__DOT__clk__v0 = 0U;
    }
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__7(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__7\n"); );
    // Body
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_released 
        = (1U & ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_release_q) 
                 >> 1U));
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__8(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__8\n"); );
    // Body
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__response_pending_tck_q 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__response_pending_tck_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0U] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[1U] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[1U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[2U] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[2U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[3U] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[3U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[4U] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[4U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[5U] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[5U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[6U] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[6U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[7U] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[7U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[8U] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[8U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[9U] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[9U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xaU] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xaU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xbU] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xbU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xcU] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xcU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xdU] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xdU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xeU] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xeU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xfU] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xfU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x10U] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x10U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x11U] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x11U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x12U] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x12U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x13U] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x13U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x14U] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x14U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x15U] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x15U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x16U] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x16U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x17U] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x17U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x18U] 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x18U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_consume_toggle_tck_q 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_consume_toggle_tck_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_toggle_tck_q 
        = vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_toggle_tck_q;
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__9(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__9\n"); );
    // Init
    SData/*15:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__175__Vfuncout;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__175__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__175__a;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__175__a = 0;
    QData/*38:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_wdata_ecc__DOT__u_data_gen__DOT__sv2v_cast_39__185__Vfuncout;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_wdata_ecc__DOT__u_data_gen__DOT__sv2v_cast_39__185__Vfuncout = 0;
    QData/*38:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_wdata_ecc__DOT__u_data_gen__DOT__sv2v_cast_39__185__inp;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_wdata_ecc__DOT__u_data_gen__DOT__sv2v_cast_39__185__inp = 0;
    // Body
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__175__a 
        = ((IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                    >> 3U)) << 2U);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__175__Vfuncout 
        = (0xffffU & (([&]() {
                    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__176__a 
                        = __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__175__a;
                    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__176__Vfuncout 
                        = (0x1f8000U == (0xffff8000U 
                                         & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__176__a));
                }(), (IData)(vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__176__Vfuncout))
                       ? (0xe000U | (0x1fffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__175__a 
                                                >> 2U)))
                       : (__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__175__a 
                          >> 2U)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__data_idx 
        = __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__175__Vfuncout;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_wdata_ecc__DOT__u_data_gen__DOT__sv2v_cast_39__185__inp 
        = (QData)((IData)(((1U & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                          >> 2U))) ? 
                           ((1U & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                           >> 1U)))
                             ? ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b 
                                 << 0x18U) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b 
                                              >> 8U))
                             : ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b 
                                 << 0x10U) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b 
                                              >> 0x10U)))
                            : ((1U & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                              >> 1U)))
                                ? ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b 
                                    << 8U) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b 
                                              >> 0x18U))
                                : vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b))));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_wdata_ecc__DOT__u_data_gen__DOT__sv2v_cast_39__185__Vfuncout 
        = __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_wdata_ecc__DOT__u_data_gen__DOT__sv2v_cast_39__185__inp;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
        = __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_wdata_ecc__DOT__u_data_gen__DOT__sv2v_cast_39__185__Vfuncout;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
        = ((0x7effffffffULL & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x2606bd25ULL 
                                                  & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core))))) 
              << 0x20U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
        = ((0x7dffffffffULL & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0xdeba8050ULL 
                                                  & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core))))) 
              << 0x21U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
        = ((0x7bffffffffULL & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x413d89aaULL 
                                                  & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core))))) 
              << 0x22U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
        = ((0x77ffffffffULL & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x31234ed1ULL 
                                                  & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core))))) 
              << 0x23U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
        = ((0x6fffffffffULL & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0xc2c1323bULL 
                                                  & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core))))) 
              << 0x24U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
        = ((0x5fffffffffULL & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x2dcc624cULL 
                                                  & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core))))) 
              << 0x25U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
        = ((0x3fffffffffULL & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x98505586ULL 
                                                  & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core))))) 
              << 0x26U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
        = (0x2a00000000ULL ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__ram_data_hit 
        = (([&]() {
                vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__172__a 
                    = ((IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                >> 3U)) << 2U);
                vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__172__Vfuncout 
                    = (0x100000U == (0xfffc0000U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__172__a));
            }(), (IData)(vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__172__Vfuncout)) 
           | ([&]() {
                vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__173__a 
                    = ((IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                >> 3U)) << 2U);
                vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__173__Vfuncout 
                    = (0x1f8000U == (0xffff8000U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__173__a));
            }(), (IData)(vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__173__Vfuncout)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_commit_match 
        = ((0xffffffffffffULL == vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_byte_written_q) 
           & (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core) 
               == vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[2U]) 
              & (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
                 [2U] == vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[2U])));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_access_err 
        = (1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__ram_data_hit) 
                    | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__mmio_read_valid) 
                       | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__mmio_write_valid)))));
}

void Vtb_rtnn_c2_soc_42___024root___timing_resume(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___timing_resume\n"); );
    // Body
    if ((0x100ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h23c93641__0.resume("@(negedge tb_rtnn_c2_soc_42.clk)");
    }
    if ((0x200ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h6e9b7ca3__0.resume("@(posedge tb_rtnn_c2_soc_42.tck)");
    }
    if ((0x20ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h23c93590__0.resume("@(posedge tb_rtnn_c2_soc_42.clk)");
    }
    if ((0x80ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_rtnn_c2_soc_42___024root___timing_commit(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___timing_commit\n"); );
    // Body
    if ((! (0x100ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h23c93641__0.commit("@(negedge tb_rtnn_c2_soc_42.clk)");
    }
    if ((! (0x200ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h6e9b7ca3__0.commit("@(posedge tb_rtnn_c2_soc_42.tck)");
    }
    if ((! (0x20ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h23c93590__0.commit("@(posedge tb_rtnn_c2_soc_42.clk)");
    }
}

void Vtb_rtnn_c2_soc_42___024root___eval_triggers__act(Vtb_rtnn_c2_soc_42___024root* vlSelf);
void Vtb_rtnn_c2_soc_42___024root___eval_act(Vtb_rtnn_c2_soc_42___024root* vlSelf);

bool Vtb_rtnn_c2_soc_42___024root___eval_phase__act(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<10> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_rtnn_c2_soc_42___024root___eval_triggers__act(vlSelf);
    Vtb_rtnn_c2_soc_42___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_rtnn_c2_soc_42___024root___timing_resume(vlSelf);
        Vtb_rtnn_c2_soc_42___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vtb_rtnn_c2_soc_42___024root___eval_nba(Vtb_rtnn_c2_soc_42___024root* vlSelf);

bool Vtb_rtnn_c2_soc_42___024root___eval_phase__nba(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_rtnn_c2_soc_42___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rtnn_c2_soc_42___024root___dump_triggers__nba(Vtb_rtnn_c2_soc_42___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rtnn_c2_soc_42___024root___dump_triggers__act(Vtb_rtnn_c2_soc_42___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_rtnn_c2_soc_42___024root___eval(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_rtnn_c2_soc_42___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb_rtnn_c2_soc_42.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_rtnn_c2_soc_42___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb_rtnn_c2_soc_42.sv", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_rtnn_c2_soc_42___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_rtnn_c2_soc_42___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_rtnn_c2_soc_42___024root___eval_debug_assertions(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
