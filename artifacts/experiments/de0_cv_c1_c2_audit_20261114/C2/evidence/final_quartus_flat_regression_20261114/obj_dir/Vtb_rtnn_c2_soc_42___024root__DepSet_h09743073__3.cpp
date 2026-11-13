// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rtnn_c2_soc_42.h for the primary calling header

#include "Vtb_rtnn_c2_soc_42__pch.h"
#include "Vtb_rtnn_c2_soc_42__Syms.h"
#include "Vtb_rtnn_c2_soc_42___024root.h"

extern const VlWide<12>/*383:0*/ Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0;

VlCoroutine Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__0__4(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__0__4\n"); );
    // Init
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__s;
    __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__s = 0;
    VlWide<12>/*383:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got;
    VL_ZERO_W(384, __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got);
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__164__value;
    __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__164__value = 0;
    VlWide<12>/*383:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value;
    VL_ZERO_W(384, __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value);
    IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__unnamedblk3__DOT__b;
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__unnamedblk3__DOT__b = 0;
    IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__Vfuncout;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__Vfuncout = 0;
    VlWide<11>/*351:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix;
    VL_ZERO_W(352, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix);
    IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c = 0;
    CData/*7:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by = 0;
    // Body
    {
        while (VL_GTS_III(32, 0xf4240U, vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__unnamedblk10__DOT__n)) {
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__164__value = 0U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__ir = 3U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__164__value 
                = ((0xfeU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__164__value)) 
                   | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__164__value 
                = ((0xfdU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__164__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 1U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__164__value 
                = ((0xfbU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__164__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 2U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__164__value 
                = ((0xf7U & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__164__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 3U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__164__value 
                = ((0xefU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__164__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 4U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__164__value 
                = ((0xdfU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__164__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 5U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__164__value 
                = ((0xbfU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__164__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 6U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__164__value 
                = ((0x7fU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__164__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 7U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__s 
                = __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__164__value;
            if (VL_UNLIKELY((0x80U & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__s)))) {
                VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:220: Assertion failed in %Ntb_rtnn_c2_soc_42.run_case.unnamedblk10: mailbox ERROR after case %0d status=%02x\n",
                          64,VL_TIME_UNITED_Q(1),-12,
                          vlSymsp->name(),32,vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index,
                          8,(IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__s));
                VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 220, "");
            }
            if ((IData)((0x40U == (0x70U & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__s))))) {
                vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__done = 1U;
                goto __Vlabel21;
            }
            vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__unnamedblk10__DOT__n 
                = ((IData)(1U) + vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__unnamedblk10__DOT__n);
        }
        __Vlabel21: ;
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__done))))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:223: Assertion failed in %Ntb_rtnn_c2_soc_42.run_case: SoC response timeout case=%0d status=%02x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index,
                  8,(IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__s));
        VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 223, "");
    }
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[0U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[1U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[1U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[2U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[2U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[3U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[3U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[4U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[4U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[5U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[5U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[6U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[6U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[7U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[7U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[8U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[8U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[9U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[9U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[0xaU] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0xaU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[0xbU] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0xbU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__ir = 2U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 1U;
    co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                       "tb_rtnn_c2_soc_42.sv", 
                                                       118);
    co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                       "tb_rtnn_c2_soc_42.sv", 
                                       118);
    vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 0U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__unnamedblk3__DOT__b = 0U;
    while (VL_GTS_III(32, 0x180U, __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__unnamedblk3__DOT__b)) {
        vlSelf->tb_rtnn_c2_soc_42__DOT____Vlvbound_hbf14d360__0 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__tdo;
        if (VL_LIKELY((0x17fU >= (0x1ffU & __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__unnamedblk3__DOT__b)))) {
            __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[(0xfU 
                                                                            & (__Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__unnamedblk3__DOT__b 
                                                                               >> 5U))] 
                = (((~ ((IData)(1U) << (0x1fU & __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__unnamedblk3__DOT__b))) 
                    & __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[
                    (0xfU & (__Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__unnamedblk3__DOT__b 
                             >> 5U))]) | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT____Vlvbound_hbf14d360__0) 
                                          << (0x1fU 
                                              & __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__unnamedblk3__DOT__b)));
        }
        vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
        co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                           "tb_rtnn_c2_soc_42.sv", 
                                                           118);
        co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                           "tb_rtnn_c2_soc_42.sv", 
                                           118);
        vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
        __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__unnamedblk3__DOT__b 
            = ((IData)(1U) + __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__unnamedblk3__DOT__b);
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__update_dr = 1U;
    co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                       "tb_rtnn_c2_soc_42.sv", 
                                                       118);
    co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                       "tb_rtnn_c2_soc_42.sv", 
                                       118);
    vlSelf->tb_rtnn_c2_soc_42__DOT__update_dr = 0U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[0U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[0U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[1U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[1U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[2U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[2U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[3U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[3U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[4U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[4U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[5U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[5U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[6U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[6U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[7U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[7U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[8U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[8U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[9U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[9U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[0xaU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[0xaU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[0xbU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__167__value[0xbU];
    if (VL_UNLIKELY((0x524e5452U != __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[0U]))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:225: Assertion failed in %Ntb_rtnn_c2_soc_42.run_case: RTNR magic case=%0d\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index);
        VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 225, "");
    }
    if (VL_UNLIKELY((IData)((1U != (0xffffU & __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[1U]))))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:226: Assertion failed in %Ntb_rtnn_c2_soc_42.run_case: response version/status case=%0d\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index);
        VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 226, "");
    }
    if (VL_UNLIKELY((((0xffU & (__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[1U] 
                                >> 0x10U)) != (0xffU 
                                               & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__mode)) 
                     | ((__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[1U] 
                         >> 0x18U) != (IData)(vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__stop))))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:227: Assertion failed in %Ntb_rtnn_c2_soc_42.run_case: mode/stop mismatch case=%0d\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index);
        VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 227, "");
    }
    if (VL_UNLIKELY(((__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[2U] 
                      != vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__seq) 
                     | ((0xffffU & __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[3U]) 
                        != (0xffffU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__iid))))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:228: Assertion failed in %Ntb_rtnn_c2_soc_42.run_case: sequence/input mismatch case=%0d\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index);
        VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 228, "");
    }
    if (VL_UNLIKELY(((__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[3U] 
                      >> 0x10U) != (IData)(vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__budget)))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:229: Assertion failed in %Ntb_rtnn_c2_soc_42.run_case: budget mismatch case=%0d\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index);
        VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 229, "");
    }
    if (VL_UNLIKELY((((0xffU & __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[5U]) 
                      != (0xffU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__admit)) 
                     | ((0xffU & (__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[5U] 
                                  >> 8U)) != (0xffU 
                                              & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__exec_exit))))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:230: Assertion failed in %Ntb_rtnn_c2_soc_42.run_case: exit mismatch case=%0d\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index);
        VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 230, "");
    }
    if (VL_UNLIKELY((((0xffU & (__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[5U] 
                                >> 0x10U)) != (0xffU 
                                               & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__pred)) 
                     | ((__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[5U] 
                         >> 0x18U) != (0xffU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__label))))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:231: Assertion failed in %Ntb_rtnn_c2_soc_42.run_case: prediction/label mismatch case=%0d\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index);
        VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 231, "");
    }
    if (VL_UNLIKELY((0U == __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[6U]))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:232: Assertion failed in %Ntb_rtnn_c2_soc_42.run_case: zero Q15 mcycle delta case=%0d\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index);
        VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 232, "");
    }
    if (VL_UNLIKELY(((0x52544e4eU != __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[7U]) 
                     | (0x43324a32U != __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[8U])))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:233: Assertion failed in %Ntb_rtnn_c2_soc_42.run_case: model/build mismatch case=%0d\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index);
        VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 233, "");
    }
    if (VL_UNLIKELY(((0U != __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[9U]) 
                     | (0U != __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[0xaU])))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:234: Assertion failed in %Ntb_rtnn_c2_soc_42.run_case: unexpected binding/flags case=%0d\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index);
        VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 234, "");
    }
    if (VL_UNLIKELY((__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[0xbU] 
                     != ([&]() {
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[0U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[0U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[1U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[1U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[2U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[2U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[3U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[3U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[4U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[4U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[5U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[5U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[6U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[6U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[7U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[7U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[8U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[8U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[9U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[9U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[0xaU] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[0xaU];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c = 0xffffffffU;
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[0U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[0U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[0U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[0U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[1U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[1U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[1U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[1U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[2U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[2U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[2U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[2U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[3U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[3U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[3U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[3U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[4U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[4U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[4U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[4U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[5U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[5U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[5U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[5U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[6U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[6U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[6U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[6U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[7U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[7U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[7U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[7U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[8U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[8U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[8U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[8U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[9U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[9U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[9U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[9U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[0xaU]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[0xaU] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[0xaU] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__prefix[0xaU] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__Vfuncout 
                            = (~ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__c);
                    }(), __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__171__Vfuncout)))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:235: Assertion failed in %Ntb_rtnn_c2_soc_42.run_case: response CRC mismatch case=%0d\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index);
        VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 235, "");
    }
    if (VL_UNLIKELY((vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__exec_exit 
                     > vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__admit))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:236: Assertion failed in %Ntb_rtnn_c2_soc_42.run_case: cap violation case=%0d\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index);
        VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 236, "");
    }
    if (VL_UNLIKELY(vlSelf->tb_rtnn_c2_soc_42__DOT__bus_fault)) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:237: Assertion failed in %Ntb_rtnn_c2_soc_42.run_case: SoC bus fault/halt case=%0d\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index);
        VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 237, "");
    }
    VL_WRITEF("C2_SOC_CASE_PASS index=%0d seq=%0# input=%0# mode=%0# pred=%0# label=%0# admitted=%0# executed=%0# mcycle=%0#\nC2_FIXED_IBEX_Q15_SOC_PASS cases=%0d reset_recovery=PASS negatives=bad_crc,duplicate,busy_reset,payload_crc,unknown_input,unknown_model,unknown_build\n",
              32,vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index,
              32,vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__seq,
              32,vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__iid,
              32,vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__mode,
              32,vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__pred,
              32,vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__label,
              32,vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__admit,
              32,vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__exec_exit,
              32,__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__got[6U],
              32,vlSelf->tb_rtnn_c2_soc_42__DOT__case_limit);
    VL_FINISH_MT("tb_rtnn_c2_soc_42.sv", 309, "");
}

VL_INLINE_OPT VlCoroutine Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__3(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__3\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                           "tb_rtnn_c2_soc_42.sv", 
                                                           99);
        if (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__trst_n) 
             & ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_sync2_tck_q) 
                != (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_seen_tck_q)))) {
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42.sv", 
                                               101);
            if (VL_UNLIKELY((0U != ((((((((((((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[0U] 
                                               ^ vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0U]) 
                                              | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[1U] 
                                                 ^ 
                                                 vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[1U])) 
                                             | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[2U] 
                                                ^ vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[2U])) 
                                            | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[3U] 
                                               ^ vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[3U])) 
                                           | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[4U] 
                                              ^ vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[4U])) 
                                          | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[5U] 
                                             ^ vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[5U])) 
                                         | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[6U] 
                                            ^ vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[6U])) 
                                        | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[7U] 
                                           ^ vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[7U])) 
                                       | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[8U] 
                                          ^ vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[8U])) 
                                      | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[9U] 
                                         ^ vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[9U])) 
                                     | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[0xaU] 
                                        ^ vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0xaU])) 
                                    | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q[0xbU] 
                                       ^ vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0xbU]))))) {
                VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:103: Assertion failed in %Ntb_rtnn_c2_soc_42: CDC response bundle mismatch at TCK capture\n",
                          64,VL_TIME_UNITED_Q(1),-12,
                          vlSymsp->name());
                VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 103, "");
            }
        }
    }
}

VL_INLINE_OPT VlCoroutine Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__4(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__4\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VtrigSched_h23c93590__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_rtnn_c2_soc_42.clk)", 
                                                           "tb_rtnn_c2_soc_42.sv", 
                                                           109);
        if (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__rst_n) 
             & ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_sync2_sys_q) 
                != (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_seen_sys_q)))) {
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42.sv", 
                                               111);
            if (VL_UNLIKELY((0U != ((((((((((((((((
                                                   (((((((((vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0U] 
                                                            ^ 
                                                            vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0U]) 
                                                           | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[1U] 
                                                              ^ 
                                                              vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[1U])) 
                                                          | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[2U] 
                                                             ^ 
                                                             vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[2U])) 
                                                         | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[3U] 
                                                            ^ 
                                                            vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[3U])) 
                                                        | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[4U] 
                                                           ^ 
                                                           vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[4U])) 
                                                       | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[5U] 
                                                          ^ 
                                                          vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[5U])) 
                                                      | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[6U] 
                                                         ^ 
                                                         vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[6U])) 
                                                     | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[7U] 
                                                        ^ 
                                                        vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[7U])) 
                                                    | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[8U] 
                                                       ^ 
                                                       vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[8U])) 
                                                   | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[9U] 
                                                      ^ 
                                                      vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[9U])) 
                                                  | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0xaU] 
                                                     ^ 
                                                     vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xaU])) 
                                                 | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0xbU] 
                                                    ^ 
                                                    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xbU])) 
                                                | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0xcU] 
                                                   ^ 
                                                   vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xcU])) 
                                               | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0xdU] 
                                                  ^ 
                                                  vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xdU])) 
                                              | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0xeU] 
                                                 ^ 
                                                 vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xeU])) 
                                             | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0xfU] 
                                                ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xfU])) 
                                            | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x10U] 
                                               ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x10U])) 
                                           | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x11U] 
                                              ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x11U])) 
                                          | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x12U] 
                                             ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x12U])) 
                                         | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x13U] 
                                            ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x13U])) 
                                        | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x14U] 
                                           ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x14U])) 
                                       | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x15U] 
                                          ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x15U])) 
                                      | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x16U] 
                                         ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x16U])) 
                                     | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x17U] 
                                        ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x17U])) 
                                    | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x18U] 
                                       ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x18U]))))) {
                VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:113: Assertion failed in %Ntb_rtnn_c2_soc_42: CDC request bundle mismatch at CLOCK_50 capture\n",
                          64,VL_TIME_UNITED_Q(1),-12,
                          vlSymsp->name());
                VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 113, "");
            }
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rtnn_c2_soc_42___024root___dump_triggers__act(Vtb_rtnn_c2_soc_42___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_rtnn_c2_soc_42___024root___eval_triggers__act(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.en_wb_o) 
                                      != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__en_wb_o__1)) 
                                     | ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__instr_executing_spec) 
                                        != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i____PVT__instr_executing_spec__1))));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__instr_executing_spec) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i____PVT__instr_executing_spec__1)));
    vlSelf->__VactTriggered.set(2U, ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.id_in_ready_o) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__id_in_ready_o__1)));
    vlSelf->__VactTriggered.set(3U, (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tck) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__tck__0))) 
                                     | ((~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__trst_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__trst_n__0))));
    vlSelf->__VactTriggered.set(4U, (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__clk__0))) 
                                     | ((~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__rst_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__rst_n__0))));
    vlSelf->__VactTriggered.set(5U, ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__clk__0))));
    vlSelf->__VactTriggered.set(6U, (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tck) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__tck__0))) 
                                     | ((~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_released)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_released__0))));
    vlSelf->__VactTriggered.set(7U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__VactTriggered.set(8U, ((~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__clk)) 
                                     & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__clk__0)));
    vlSelf->__VactTriggered.set(9U, ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tck) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__tck__0))));
    vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__en_wb_o__1 
        = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.en_wb_o;
    vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i____PVT__instr_executing_spec__1 
        = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__instr_executing_spec;
    vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__id_in_ready_o__1 
        = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.id_in_ready_o;
    vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__tck__0 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__tck;
    vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__trst_n__0 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__trst_n;
    vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__clk__0 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__rst_n__0 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rst_n;
    vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_released__0 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_released;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.set(0U, 1U);
        vlSelf->__VactTriggered.set(1U, 1U);
        vlSelf->__VactTriggered.set(2U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_rtnn_c2_soc_42___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42___024root___act_sequent__TOP__0(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___act_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_valid;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_valid = 0;
    // Body
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_en_internal 
        = ((~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_hold)) 
           & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.mult_en_ex_o));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_valid 
        = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.mult_en_ex_o;
    if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q) {
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q) {
            tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_valid = 1U;
        }
    } else if ((0U != (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_operator))) {
        tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_valid = 0U;
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_valid 
        = (1U & ((~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)) 
                 | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_valid) 
                    | (IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_valid))));
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42___024root___act_comb__TOP__1(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___act_comb__TOP__1\n"); );
    // Init
    CData/*0:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__174__Vfuncout;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__174__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__174__a;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__174__a = 0;
    SData/*15:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__177__Vfuncout;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__177__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__177__a;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__177__a = 0;
    // Body
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__perf_instr_ret_wb 
        = (((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__ebrk_insn)) 
            & ((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__ecall_insn_dec)) 
               & ((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__decoder_i__DOT__illegal_insn)) 
                  & ((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.illegal_csr_insn_o)) 
                     & ((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_fetch_err_o)) 
                        & (~ (((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_access_o) 
                               & ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__VdfgTmp_hc09de8e0__0) 
                                  & ((0xb02U == (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                 >> 0x14U)) 
                                     | (0xb82U == (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                   >> 0x14U))))) 
                              | (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__VdfgTmp_h20a3cc49__0)))))))) 
           & ((~ (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_load_err) 
                   | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_store_err)) 
                  & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_resp_valid))) 
              & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.en_wb_o)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal 
        = ((~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_hold)) 
           & ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__instr_executing_spec) 
              & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__div_en_dec)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ctrl_update = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_d 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__data_req_out = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_d 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_q;
    if ((4U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
        if ((1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)))) {
                if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_valid_q) {
                    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d = 0U;
                    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update 
                        = (1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_err_q)));
                    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_d 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_err_q;
                }
            }
        }
        if ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = 0U;
        } else if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = 0U;
        } else if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_valid_q) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = 0U;
        }
    } else if ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
        if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)))) {
            if (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_valid_q) 
                 | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q))) {
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d = 0U;
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_d 
                    = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_err_q) 
                       | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q));
            }
        }
        if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = 0U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update 
                = (1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_q)));
        } else if (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_valid_q) 
                    | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = 0U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update 
                = (1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_err_q) 
                            | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q))));
        } else {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = 4U;
        }
    } else {
        if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d = 0U;
            if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.lsu_req_o) {
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d = 0U;
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_d = 0U;
            }
        }
        if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = 2U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update = 1U;
        } else if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.lsu_req_o) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns 
                = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__split_misaligned_access)
                    ? 2U : 0U);
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update = 1U;
        }
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__perf_store = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__perf_load = 0U;
    if ((1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs) 
                  >> 2U)))) {
        if ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
            if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ctrl_update = 1U;
            }
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_d = 0U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__data_req_out = 1U;
        } else if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ctrl_update = 1U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_d = 1U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__data_req_out = 1U;
        } else if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.lsu_req_o) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ctrl_update = 1U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_d 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__split_misaligned_access;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__data_req_out = 1U;
        }
        if ((1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)))) {
                if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.lsu_req_o) {
                    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__perf_store 
                        = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__lsu_we;
                    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__perf_load 
                        = (1U & (~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__lsu_we)));
                }
            }
        }
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb 
        = (((- (IData)((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.rf_we_id_o))) 
            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.rf_wdata_id_o) 
           | ((- (IData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_lsu))) 
              & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_rdata_ext));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_lsu) 
           | (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.rf_we_id_o));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__174__a 
        = (0xfffffffcU & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_d);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__174__Vfuncout 
        = (0x100000U == (0xfffc0000U & __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__174__a));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__instr_hit 
        = __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__174__Vfuncout;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__177__a 
        = (0xfffffffcU & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_d);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__177__Vfuncout 
        = (0xffffU & (([&]() {
                    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__178__a 
                        = __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__177__a;
                    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__178__Vfuncout 
                        = (0x1f8000U == (0xffff8000U 
                                         & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__178__a));
                }(), (IData)(vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__178__Vfuncout))
                       ? (0xe000U | (0x1fffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__177__a 
                                                >> 2U)))
                       : (__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__177__a 
                          >> 2U)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__instr_idx 
        = __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__177__Vfuncout;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_we_ex 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
            ? (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal) 
                << 1U) | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_en_internal) 
                          | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal)))
            : 0U);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__ram_dreq 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__data_req_out) 
           & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__ram_data_hit));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffffffeU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | (IData)(((0U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                      & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffffffdU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x80U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 1U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffffffbU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x100U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 2U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffffff7U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x180U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 3U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffffffefU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x200U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 4U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffffffdfU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x280U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 5U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffffffbfU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x300U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 6U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffffff7fU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x380U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 7U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffffeffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x400U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 8U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffffdffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x480U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 9U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffffbffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x500U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0xaU));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffff7ffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x580U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0xbU));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffffefffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x600U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0xcU));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffffdfffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x680U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0xdU));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffffbfffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x700U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0xeU));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffff7fffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x780U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0xfU));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffeffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x800U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x10U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffdffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x880U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x11U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffbffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x900U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x12U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfff7ffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x980U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x13U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffefffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xa00U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x14U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffdfffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xa80U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x15U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffbfffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xb00U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x16U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xff7fffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xb80U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x17U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfeffffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xc00U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x18U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfdffffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xc80U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x19U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfbffffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xd00U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x1aU));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xf7ffffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xd80U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x1bU));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xefffffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xe00U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x1cU));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xdfffffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xe80U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x1dU));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xbfffffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xf00U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x1eU));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0x7fffffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xf80U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x1fU));
}

void Vtb_rtnn_c2_soc_42___024root___act_comb__TOP__0(Vtb_rtnn_c2_soc_42___024root* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__0(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__0(Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__1(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__2(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__0(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__0(Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__0(Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__1(Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9* vlSelf);

void Vtb_rtnn_c2_soc_42___024root___eval_act(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___eval_act\n"); );
    // Body
    if ((0x380ULL & vlSelf->__VactTriggered.word(0U))) {
        Vtb_rtnn_c2_soc_42___024root___act_comb__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__0((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i));
        Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__0((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i));
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__1((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i));
        Vtb_rtnn_c2_soc_42___024root___act_sequent__TOP__0(vlSelf);
        Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__2((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i));
    }
    if ((7ULL & vlSelf->__VactTriggered.word(0U))) {
        Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__0((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i));
        Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__0((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i));
        Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__0((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i));
        Vtb_rtnn_c2_soc_42___024root___act_comb__TOP__1(vlSelf);
        Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__1((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i));
    }
}

extern const VlWide<25>/*799:0*/ Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0;

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__0(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdly__tb_rtnn_c2_soc_42__DOT__req_toggle_guard;
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_toggle_guard = 0;
    VlWide<25>/*799:0*/ __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard;
    VL_ZERO_W(800, __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard);
    CData/*0:0*/ __Vdly__tb_rtnn_c2_soc_42__DOT__req_guard_active;
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_guard_active = 0;
    VlWide<12>/*383:0*/ __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard;
    VL_ZERO_W(384, __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard);
    CData/*0:0*/ __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard_active;
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard_active = 0;
    // Body
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard_active 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard_active;
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[1U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[1U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[2U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[2U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[3U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[3U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[4U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[4U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[5U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[5U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[6U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[6U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[7U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[7U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[8U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[8U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[9U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[9U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0xaU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0xaU];
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0xbU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0xbU];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_guard_active 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_guard_active;
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[1U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[1U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[2U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[2U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[3U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[3U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[4U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[4U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[5U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[5U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[6U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[6U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[7U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[7U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[8U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[8U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[9U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[9U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xaU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xaU];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xbU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xbU];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xcU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xcU];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xdU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xdU];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xeU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xeU];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xfU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xfU];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x10U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x10U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x11U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x11U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x12U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x12U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x13U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x13U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x14U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x14U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x15U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x15U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x16U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x16U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x17U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x17U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x18U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x18U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__req_toggle_guard 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__req_toggle_guard;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_release_q 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__trst_n)
            ? (1U | (2U & ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_release_q) 
                           << 1U))) : 0U);
    if (vlSelf->tb_rtnn_c2_soc_42__DOT__trst_n) {
        if (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__response_pending_tck_q) 
             & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_pending_seen)))) {
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[1U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[1U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[2U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[2U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[3U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[3U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[4U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[4U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[5U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[5U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[6U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[6U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[7U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[7U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[8U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[8U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[9U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[9U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0xaU] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0xaU];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0xbU] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0xbU];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard_active = 1U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_pending_seen = 1U;
        } else if (vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard_active) {
            if (VL_UNLIKELY((0U != ((((((((((((vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0U] 
                                               ^ vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0U]) 
                                              | (vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[1U] 
                                                 ^ 
                                                 vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[1U])) 
                                             | (vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[2U] 
                                                ^ vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[2U])) 
                                            | (vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[3U] 
                                               ^ vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[3U])) 
                                           | (vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[4U] 
                                              ^ vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[4U])) 
                                          | (vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[5U] 
                                             ^ vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[5U])) 
                                         | (vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[6U] 
                                            ^ vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[6U])) 
                                        | (vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[7U] 
                                           ^ vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[7U])) 
                                       | (vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[8U] 
                                          ^ vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[8U])) 
                                      | (vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[9U] 
                                         ^ vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[9U])) 
                                     | (vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0xaU] 
                                        ^ vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0xaU])) 
                                    | (vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0xbU] 
                                       ^ vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0xbU]))))) {
                VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:89: Assertion failed in %Ntb_rtnn_c2_soc_42: CDC response bundle changed before JTAG response consumption\n",
                          64,VL_TIME_UNITED_Q(1),-12,
                          vlSymsp->name());
                VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 89, "");
            }
            if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__response_pending_tck_q)))) {
                __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard_active = 0U;
                vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_pending_seen = 0U;
            }
        }
    } else {
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard_active = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_pending_seen = 0U;
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[1U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[1U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[2U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[2U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[3U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[3U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[4U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[4U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[5U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[5U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[6U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[6U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[7U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[7U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[8U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[8U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[9U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[9U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0xaU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0xaU];
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0xbU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0xbU];
    }
    if (vlSelf->tb_rtnn_c2_soc_42__DOT__trst_n) {
        if (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_toggle_tck_q) 
             != (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__req_toggle_guard))) {
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_toggle_guard 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_toggle_tck_q;
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[1U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[1U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[2U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[2U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[3U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[3U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[4U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[4U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[5U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[5U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[6U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[6U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[7U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[7U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[8U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[8U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[9U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[9U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xaU] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xaU];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xbU] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xbU];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xcU] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xcU];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xdU] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xdU];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xeU] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xeU];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xfU] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xfU];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x10U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x10U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x11U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x11U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x12U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x12U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x13U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x13U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x14U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x14U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x15U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x15U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x16U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x16U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x17U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x17U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x18U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x18U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__req_guard_active = 1U;
        } else if (vlSelf->tb_rtnn_c2_soc_42__DOT__req_guard_active) {
            if (VL_UNLIKELY((0U != ((((((((((((((((
                                                   (((((((((vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0U] 
                                                            ^ 
                                                            vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0U]) 
                                                           | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[1U] 
                                                              ^ 
                                                              vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[1U])) 
                                                          | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[2U] 
                                                             ^ 
                                                             vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[2U])) 
                                                         | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[3U] 
                                                            ^ 
                                                            vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[3U])) 
                                                        | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[4U] 
                                                           ^ 
                                                           vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[4U])) 
                                                       | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[5U] 
                                                          ^ 
                                                          vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[5U])) 
                                                      | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[6U] 
                                                         ^ 
                                                         vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[6U])) 
                                                     | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[7U] 
                                                        ^ 
                                                        vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[7U])) 
                                                    | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[8U] 
                                                       ^ 
                                                       vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[8U])) 
                                                   | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[9U] 
                                                      ^ 
                                                      vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[9U])) 
                                                  | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xaU] 
                                                     ^ 
                                                     vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xaU])) 
                                                 | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xbU] 
                                                    ^ 
                                                    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xbU])) 
                                                | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xcU] 
                                                   ^ 
                                                   vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xcU])) 
                                               | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xdU] 
                                                  ^ 
                                                  vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xdU])) 
                                              | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xeU] 
                                                 ^ 
                                                 vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xeU])) 
                                             | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xfU] 
                                                ^ vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xfU])) 
                                            | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x10U] 
                                               ^ vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x10U])) 
                                           | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x11U] 
                                              ^ vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x11U])) 
                                          | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x12U] 
                                             ^ vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x12U])) 
                                         | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x13U] 
                                            ^ vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x13U])) 
                                        | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x14U] 
                                           ^ vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x14U])) 
                                       | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x15U] 
                                          ^ vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x15U])) 
                                      | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x16U] 
                                         ^ vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x16U])) 
                                     | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x17U] 
                                        ^ vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x17U])) 
                                    | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x18U] 
                                       ^ vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x18U]))))) {
                VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:55: Assertion failed in %Ntb_rtnn_c2_soc_42: CDC request bundle changed before CLOCK_50 acknowledgement\n",
                          64,VL_TIME_UNITED_Q(1),-12,
                          vlSymsp->name());
                VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 55, "");
            }
            if (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_ack_sync2_tck_q) 
                 == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__req_toggle_guard))) {
                __Vdly__tb_rtnn_c2_soc_42__DOT__req_guard_active = 0U;
            }
        }
    } else {
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_toggle_guard = 0U;
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_guard_active = 0U;
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[1U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[1U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[2U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[2U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[3U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[3U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[4U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[4U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[5U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[5U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[6U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[6U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[7U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[7U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[8U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[8U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[9U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[9U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xaU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xaU];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xbU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xbU];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xcU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xcU];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xdU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xdU];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xeU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xeU];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xfU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xfU];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x10U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x10U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x11U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x11U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x12U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x12U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x13U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x13U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x14U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x14U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x15U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x15U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x16U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x16U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x17U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x17U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x18U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x18U];
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[1U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[1U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[2U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[2U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[3U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[3U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[4U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[4U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[5U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[5U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[6U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[6U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[7U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[7U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[8U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[8U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[9U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[9U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0xaU] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0xaU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0xbU] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0xbU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard_active 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_tck_guard_active;
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_toggle_guard 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_toggle_guard;
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[1U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[1U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[2U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[2U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[3U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[3U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[4U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[4U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[5U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[5U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[6U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[6U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[7U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[7U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[8U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[8U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[9U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[9U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xaU] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xaU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xbU] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xbU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xcU] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xcU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xdU] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xdU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xeU] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xeU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xfU] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xfU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x10U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x10U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x11U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x11U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x12U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x12U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x13U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x13U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x14U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x14U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x15U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x15U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x16U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x16U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x17U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x17U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x18U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x18U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_guard_active 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__req_guard_active;
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__2(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__2\n"); );
    // Init
    CData/*3:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__rst_shadow_set_q;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__rst_shadow_set_q = 0;
    VlWide<12>/*383:0*/ __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard;
    VL_ZERO_W(384, __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard);
    CData/*0:0*/ __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard_active;
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard_active = 0;
    CData/*0:0*/ __Vdly__tb_rtnn_c2_soc_42__DOT__request_valid;
    __Vdly__tb_rtnn_c2_soc_42__DOT__request_valid = 0;
    CData/*0:0*/ __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_seen_sys_q;
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_seen_sys_q = 0;
    CData/*0:0*/ __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__busy_sys_q;
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__busy_sys_q = 0;
    CData/*0:0*/ __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sys_q;
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sys_q = 0;
    CData/*0:0*/ __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_toggle_sys_q;
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_toggle_sys_q = 0;
    CData/*3:0*/ __Vdlyvdim0__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v0;
    __Vdlyvdim0__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v0 = 0;
    CData/*4:0*/ __Vdlyvlsb__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v0;
    __Vdlyvlsb__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v0 = 0;
    CData/*7:0*/ __Vdlyvval__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v0;
    __Vdlyvval__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v0;
    __Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v0 = 0;
    CData/*3:0*/ __Vdlyvdim0__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v1;
    __Vdlyvdim0__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v1 = 0;
    CData/*4:0*/ __Vdlyvlsb__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v1;
    __Vdlyvlsb__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v1 = 0;
    CData/*7:0*/ __Vdlyvval__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v1;
    __Vdlyvval__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v1 = 0;
    CData/*0:0*/ __Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v1;
    __Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v1 = 0;
    CData/*3:0*/ __Vdlyvdim0__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v2;
    __Vdlyvdim0__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v2 = 0;
    CData/*4:0*/ __Vdlyvlsb__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v2;
    __Vdlyvlsb__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v2 = 0;
    CData/*7:0*/ __Vdlyvval__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v2;
    __Vdlyvval__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v2 = 0;
    CData/*0:0*/ __Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v2;
    __Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v2 = 0;
    CData/*3:0*/ __Vdlyvdim0__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v3;
    __Vdlyvdim0__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v3 = 0;
    CData/*4:0*/ __Vdlyvlsb__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v3;
    __Vdlyvlsb__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v3 = 0;
    CData/*7:0*/ __Vdlyvval__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v3;
    __Vdlyvval__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v3 = 0;
    CData/*0:0*/ __Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v3;
    __Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v3 = 0;
    CData/*0:0*/ __Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v4;
    __Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v4 = 0;
    // Body
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard_active 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard_active;
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[1U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[1U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[2U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[2U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[3U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[3U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[4U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[4U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[5U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[5U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[6U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[6U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[7U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[7U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[8U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[8U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[9U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[9U];
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0xaU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0xaU];
    __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0xbU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0xbU];
    __Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v0 = 0U;
    __Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v1 = 0U;
    __Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v2 = 0U;
    __Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v3 = 0U;
    __Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v4 = 0U;
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_toggle_sys_q 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_toggle_sys_q;
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sys_q 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sys_q;
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__busy_sys_q 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__busy_sys_q;
    __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_seen_sys_q 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_seen_sys_q;
    __Vdly__tb_rtnn_c2_soc_42__DOT__request_valid = vlSelf->tb_rtnn_c2_soc_42__DOT__request_valid;
    if (vlSelf->tb_rtnn_c2_soc_42__DOT__rst_n) {
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__response_commit) {
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[1U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[1U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[2U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[2U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[3U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[3U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[4U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[4U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[5U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[5U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[6U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[6U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[7U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[7U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[8U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[8U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[9U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[9U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0xaU] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0xaU];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0xbU] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0xbU];
            __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard_active = 1U;
        } else if (vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard_active) {
            if (VL_UNLIKELY((0U != ((((((((((((vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0U] 
                                               ^ vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0U]) 
                                              | (vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[1U] 
                                                 ^ 
                                                 vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[1U])) 
                                             | (vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[2U] 
                                                ^ vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[2U])) 
                                            | (vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[3U] 
                                               ^ vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[3U])) 
                                           | (vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[4U] 
                                              ^ vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[4U])) 
                                          | (vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[5U] 
                                             ^ vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[5U])) 
                                         | (vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[6U] 
                                            ^ vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[6U])) 
                                        | (vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[7U] 
                                           ^ vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[7U])) 
                                       | (vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[8U] 
                                          ^ vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[8U])) 
                                      | (vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[9U] 
                                         ^ vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[9U])) 
                                     | (vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0xaU] 
                                        ^ vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0xaU])) 
                                    | (vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0xbU] 
                                       ^ vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0xbU]))))) {
                VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:72: Assertion failed in %Ntb_rtnn_c2_soc_42: CDC response bundle changed before TCK capture\n",
                          64,VL_TIME_UNITED_Q(1),-12,
                          vlSymsp->name());
                VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 72, "");
            }
            if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__response_pending_tck_q) {
                __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard_active = 0U;
            }
        }
    } else {
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard_active = 0U;
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[1U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[1U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[2U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[2U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[3U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[3U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[4U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[4U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[5U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[5U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[6U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[6U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[7U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[7U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[8U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[8U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[9U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[9U];
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0xaU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0xaU];
        __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0xbU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0xbU];
    }
    if (vlSelf->tb_rtnn_c2_soc_42__DOT__rst_n) {
        tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__rst_shadow_set_q = 5U;
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_d;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_d;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_d;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_d;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_d;
        }
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_update) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q 
                = (0xffffffU & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                        >> 8U)));
        }
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ctrl_update) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q 
                = (3U & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                 >> 1U)));
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q 
                = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__lsu_sign_ext;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_type_q 
                = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__lsu_type;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q 
                = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__lsu_we;
        }
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_en_internal) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_d;
        }
        if ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
             >> 0x1fU)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__31__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x40000000U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__30__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x20000000U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__29__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x10000000U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__28__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x8000000U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__27__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x4000000U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__26__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x2000000U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__25__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x1000000U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__24__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x800000U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__23__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x400000U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__22__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x200000U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__21__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x100000U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__20__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x80000U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__19__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x40000U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__18__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x20000U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__17__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x10000U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__16__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x8000U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__15__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x4000U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__14__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x2000U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__13__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x1000U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__12__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x800U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__11__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x400U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__10__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x200U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__9__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x100U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__8__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x80U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__7__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x40U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__6__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x20U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__5__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((0x10U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__4__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((8U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__3__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((4U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__2__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if ((2U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__1__KET____DOT__rf_reg_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_last_q 
                = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_addr_incr_req)
                    ? ((IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                >> 3U)) << 2U) : (IData)(
                                                         (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                          >> 1U)));
        }
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns;
        if (((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.dummy_instr_id_o) 
             & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_dummy_r0__DOT__rf_r0_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        }
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__data_req_out) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_ram_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__ram_data_hit;
            if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_access_err) {
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_err_q = 1U;
                vlSelf->tb_rtnn_c2_soc_42__DOT__bus_fault = 1U;
            } else {
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_err_q = 0U;
            }
            if (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__mmio_write_valid) 
                 & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__lsu_we))) {
                if ((1U & (~ ((0x88U == (0x3fcU & ((IData)(
                                                           (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                            >> 3U)) 
                                                   << 2U))) 
                              & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_be))))) {
                    if (((0x8cU <= (0x3fcU & ((IData)(
                                                      (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                       >> 3U)) 
                                              << 2U))) 
                         & (0xb8U >= (0x3fcU & ((IData)(
                                                        (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                         >> 3U)) 
                                                << 2U))))) {
                        if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_be))) {
                            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vlvbound_hd6210828__0 
                                = (0xffU & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core));
                            if ((0xbU >= (0xfU & ((IData)(
                                                          (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                           >> 3U)) 
                                                  - (IData)(3U))))) {
                                __Vdlyvval__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v0 
                                    = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vlvbound_hd6210828__0;
                                __Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v0 = 1U;
                                __Vdlyvlsb__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v0 = 0U;
                                __Vdlyvdim0__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v0 
                                    = (0xfU & ((IData)(
                                                       (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                        >> 3U)) 
                                               - (IData)(3U)));
                            }
                            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vlvbound_h11b922a8__0 = 1U;
                            if ((0x2fU >= (0x3fU & 
                                           VL_SHIFTL_III(6,32,32, 
                                                         (0xfU 
                                                          & ((IData)(
                                                                     (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                      >> 3U)) 
                                                             - (IData)(3U))), 2U)))) {
                                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_byte_written_q 
                                    = (((~ (1ULL << 
                                            (0x3fU 
                                             & VL_SHIFTL_III(6,32,32, 
                                                             (0xfU 
                                                              & ((IData)(
                                                                         (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                          >> 3U)) 
                                                                 - (IData)(3U))), 2U)))) 
                                        & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_byte_written_q) 
                                       | (0xffffffffffffULL 
                                          & ((QData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vlvbound_h11b922a8__0)) 
                                             << (0x3fU 
                                                 & VL_SHIFTL_III(6,32,32, 
                                                                 (0xfU 
                                                                  & ((IData)(
                                                                             (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                              >> 3U)) 
                                                                     - (IData)(3U))), 2U)))));
                            }
                        }
                        if ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_be))) {
                            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vlvbound_hd6210828__0 
                                = (0xffU & (IData)(
                                                   (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
                                                    >> 8U)));
                            if ((0xbU >= (0xfU & ((IData)(
                                                          (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                           >> 3U)) 
                                                  - (IData)(3U))))) {
                                __Vdlyvval__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v1 
                                    = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vlvbound_hd6210828__0;
                                __Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v1 = 1U;
                                __Vdlyvlsb__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v1 = 8U;
                                __Vdlyvdim0__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v1 
                                    = (0xfU & ((IData)(
                                                       (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                        >> 3U)) 
                                               - (IData)(3U)));
                            }
                            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vlvbound_h11b922a8__0 = 1U;
                            if ((0x2fU >= (0x3fU & 
                                           ((IData)(1U) 
                                            + VL_SHIFTL_III(6,32,32, 
                                                            (0xfU 
                                                             & ((IData)(
                                                                        (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                         >> 3U)) 
                                                                - (IData)(3U))), 2U))))) {
                                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_byte_written_q 
                                    = (((~ (1ULL << 
                                            (0x3fU 
                                             & ((IData)(1U) 
                                                + VL_SHIFTL_III(6,32,32, 
                                                                (0xfU 
                                                                 & ((IData)(
                                                                            (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                             >> 3U)) 
                                                                    - (IData)(3U))), 2U))))) 
                                        & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_byte_written_q) 
                                       | (0xffffffffffffULL 
                                          & ((QData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vlvbound_h11b922a8__0)) 
                                             << (0x3fU 
                                                 & ((IData)(1U) 
                                                    + 
                                                    VL_SHIFTL_III(6,32,32, 
                                                                  (0xfU 
                                                                   & ((IData)(
                                                                              (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                               >> 3U)) 
                                                                      - (IData)(3U))), 2U))))));
                            }
                        }
                        if ((4U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_be))) {
                            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vlvbound_hd6210828__0 
                                = (0xffU & (IData)(
                                                   (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
                                                    >> 0x10U)));
                            if ((0xbU >= (0xfU & ((IData)(
                                                          (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                           >> 3U)) 
                                                  - (IData)(3U))))) {
                                __Vdlyvval__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v2 
                                    = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vlvbound_hd6210828__0;
                                __Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v2 = 1U;
                                __Vdlyvlsb__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v2 = 0x10U;
                                __Vdlyvdim0__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v2 
                                    = (0xfU & ((IData)(
                                                       (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                        >> 3U)) 
                                               - (IData)(3U)));
                            }
                            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vlvbound_h11b922a8__0 = 1U;
                            if ((0x2fU >= (0x3fU & 
                                           ((IData)(2U) 
                                            + VL_SHIFTL_III(6,32,32, 
                                                            (0xfU 
                                                             & ((IData)(
                                                                        (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                         >> 3U)) 
                                                                - (IData)(3U))), 2U))))) {
                                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_byte_written_q 
                                    = (((~ (1ULL << 
                                            (0x3fU 
                                             & ((IData)(2U) 
                                                + VL_SHIFTL_III(6,32,32, 
                                                                (0xfU 
                                                                 & ((IData)(
                                                                            (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                             >> 3U)) 
                                                                    - (IData)(3U))), 2U))))) 
                                        & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_byte_written_q) 
                                       | (0xffffffffffffULL 
                                          & ((QData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vlvbound_h11b922a8__0)) 
                                             << (0x3fU 
                                                 & ((IData)(2U) 
                                                    + 
                                                    VL_SHIFTL_III(6,32,32, 
                                                                  (0xfU 
                                                                   & ((IData)(
                                                                              (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                               >> 3U)) 
                                                                      - (IData)(3U))), 2U))))));
                            }
                        }
                        if ((8U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_be))) {
                            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vlvbound_hd6210828__0 
                                = (0xffU & (IData)(
                                                   (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
                                                    >> 0x18U)));
                            if ((0xbU >= (0xfU & ((IData)(
                                                          (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                           >> 3U)) 
                                                  - (IData)(3U))))) {
                                __Vdlyvval__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v3 
                                    = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vlvbound_hd6210828__0;
                                __Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v3 = 1U;
                                __Vdlyvlsb__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v3 = 0x18U;
                                __Vdlyvdim0__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v3 
                                    = (0xfU & ((IData)(
                                                       (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                        >> 3U)) 
                                               - (IData)(3U)));
                            }
                            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vlvbound_h11b922a8__0 = 1U;
                            if ((0x2fU >= (0x3fU & 
                                           ((IData)(3U) 
                                            + VL_SHIFTL_III(6,32,32, 
                                                            (0xfU 
                                                             & ((IData)(
                                                                        (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                         >> 3U)) 
                                                                - (IData)(3U))), 2U))))) {
                                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_byte_written_q 
                                    = (((~ (1ULL << 
                                            (0x3fU 
                                             & ((IData)(3U) 
                                                + VL_SHIFTL_III(6,32,32, 
                                                                (0xfU 
                                                                 & ((IData)(
                                                                            (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                             >> 3U)) 
                                                                    - (IData)(3U))), 2U))))) 
                                        & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_byte_written_q) 
                                       | (0xffffffffffffULL 
                                          & ((QData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vlvbound_h11b922a8__0)) 
                                             << (0x3fU 
                                                 & ((IData)(3U) 
                                                    + 
                                                    VL_SHIFTL_III(6,32,32, 
                                                                  (0xfU 
                                                                   & ((IData)(
                                                                              (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                               >> 3U)) 
                                                                      - (IData)(3U))), 2U))))));
                            }
                        }
                    } else if ((0xbcU == (0x3fcU & 
                                          ((IData)(
                                                   (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                    >> 3U)) 
                                           << 2U)))) {
                        if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_commit_match) {
                            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_byte_written_q = 0ULL;
                        }
                    }
                    if ((1U & (~ ((0x8cU <= (0x3fcU 
                                             & ((IData)(
                                                        (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                         >> 3U)) 
                                                << 2U))) 
                                  & (0xb8U >= (0x3fcU 
                                               & ((IData)(
                                                          (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                           >> 3U)) 
                                                  << 2U))))))) {
                        if ((0xbcU == (0x3fcU & ((IData)(
                                                         (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                          >> 3U)) 
                                                 << 2U)))) {
                            if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_commit_match)))) {
                                vlSelf->tb_rtnn_c2_soc_42__DOT__bus_fault = 1U;
                            }
                        }
                    }
                }
            }
        }
        if (((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_req_o) 
             & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__instr_hit)))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__bus_fault = 1U;
        }
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__data_req_out) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__mmio_read_data_q 
                = (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__mmio_read_valid) 
                    & (~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__lsu_we)))
                    ? ((0x20U == (0x3fcU & ((IData)(
                                                    (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                     >> 3U)) 
                                            << 2U)))
                        ? (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__request_valid)
                        : ((0x31fU >= (0x3ffU & VL_SHIFTL_III(10,32,32, 
                                                              (0x1fU 
                                                               & ((IData)(
                                                                          (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                           >> 3U)) 
                                                                  - (IData)(9U))), 5U)))
                            ? (((0U == (0x1fU & VL_SHIFTL_III(10,32,32, 
                                                              (0x1fU 
                                                               & ((IData)(
                                                                          (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                           >> 3U)) 
                                                                  - (IData)(9U))), 5U)))
                                 ? 0U : (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[
                                         (((IData)(0x1fU) 
                                           + (0x3ffU 
                                              & VL_SHIFTL_III(10,32,32, 
                                                              (0x1fU 
                                                               & ((IData)(
                                                                          (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                           >> 3U)) 
                                                                  - (IData)(9U))), 5U))) 
                                          >> 5U)] << 
                                         ((IData)(0x20U) 
                                          - (0x1fU 
                                             & VL_SHIFTL_III(10,32,32, 
                                                             (0x1fU 
                                                              & ((IData)(
                                                                         (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                          >> 3U)) 
                                                                 - (IData)(9U))), 5U))))) 
                               | (vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[
                                  (0x1fU & (VL_SHIFTL_III(10,32,32, 
                                                          (0x1fU 
                                                           & ((IData)(
                                                                      (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                       >> 3U)) 
                                                              - (IData)(9U))), 5U) 
                                            >> 5U))] 
                                  >> (0x1fU & VL_SHIFTL_III(10,32,32, 
                                                            (0x1fU 
                                                             & ((IData)(
                                                                        (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                         >> 3U)) 
                                                                - (IData)(9U))), 5U))))
                            : 0U)) : 0U);
        }
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_capture_pending_sys_q) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[1U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[1U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[2U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[2U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[3U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[3U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[4U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[4U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[5U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[5U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[6U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[6U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[7U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[7U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[8U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[8U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[9U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[9U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0xaU] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xaU];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0xbU] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xbU];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0xcU] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xcU];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0xdU] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xdU];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0xeU] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xeU];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0xfU] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0xfU];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x10U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x10U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x11U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x11U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x12U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x12U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x13U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x13U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x14U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x14U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x15U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x15U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x16U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x16U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x17U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x17U];
            vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x18U] 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q[0x18U];
            __Vdly__tb_rtnn_c2_soc_42__DOT__request_valid = 1U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_capture_pending_sys_q = 0U;
        }
        if (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_sync2_sys_q) 
             != (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_seen_sys_q))) {
            __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_seen_sys_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_sync2_sys_q;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_capture_pending_sys_q = 1U;
            __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__busy_sys_q = 1U;
            __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sys_q = 0U;
        }
        if (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__request_valid) 
             & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__request_accept))) {
            __Vdly__tb_rtnn_c2_soc_42__DOT__request_valid = 0U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_ack_toggle_sys_q 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_seen_sys_q;
        }
        if (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__response_commit) 
             & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__busy_sys_q))) {
            __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_toggle_sys_q 
                = (1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_toggle_sys_q)));
            __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__busy_sys_q = 0U;
            __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sys_q = 1U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__error_sys_q 
                = (0U != (0xffU & (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
                                   [1U] >> 8U)));
        }
        if ((((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_consume_sync2_sys_q) 
              == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_toggle_sys_q)) 
             & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sys_q))) {
            __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sys_q = 0U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__error_sys_q = 0U;
        }
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_accept = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__response_commit = 0U;
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__data_req_out) {
            if (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__mmio_write_valid) 
                 & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__lsu_we))) {
                if (((0x88U == (0x3fcU & ((IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                   >> 3U)) 
                                          << 2U))) 
                     & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_be))) {
                    vlSelf->tb_rtnn_c2_soc_42__DOT__request_accept = 1U;
                }
                if ((1U & (~ ((0x88U == (0x3fcU & ((IData)(
                                                           (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                            >> 3U)) 
                                                   << 2U))) 
                              & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_be))))) {
                    if ((1U & (~ ((0x8cU <= (0x3fcU 
                                             & ((IData)(
                                                        (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                         >> 3U)) 
                                                << 2U))) 
                                  & (0xb8U >= (0x3fcU 
                                               & ((IData)(
                                                          (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                           >> 3U)) 
                                                  << 2U))))))) {
                        if ((0xbcU == (0x3fcU & ((IData)(
                                                         (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                          >> 3U)) 
                                                 << 2U)))) {
                            if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_commit_match) {
                                vlSelf->tb_rtnn_c2_soc_42__DOT__response_commit = 1U;
                            }
                        }
                    }
                }
            }
        }
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__instr_err_q 
            = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_req_o) 
               & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__instr_hit)));
    } else {
        __Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v4 = 1U;
        tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__rst_shadow_set_q = 0xaU;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_ram_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_err_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__31__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__30__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__29__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__28__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__27__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__26__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__25__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__24__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__23__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__22__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__21__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__20__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__19__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__18__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__17__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__16__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__15__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__14__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__13__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__12__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__11__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__10__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__9__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__8__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__7__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__6__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__5__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__4__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__3__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__2__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__1__KET____DOT__rf_reg_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_last_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_dummy_r0__DOT__rf_r0_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_type_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_byte_written_q = 0ULL;
        vlSelf->tb_rtnn_c2_soc_42__DOT__bus_fault = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__mmio_read_data_q = 0U;
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_toggle_sys_q = 0U;
        __Vdly__tb_rtnn_c2_soc_42__DOT__request_valid = 0U;
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__busy_sys_q = 0U;
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sys_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_capture_pending_sys_q = 0U;
        __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_seen_sys_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_ack_toggle_sys_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[1U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[1U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[2U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[2U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[3U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[3U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[4U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[4U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[5U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[5U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[6U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[6U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[7U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[7U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[8U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[8U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[9U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[9U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0xaU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xaU];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0xbU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xbU];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0xcU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xcU];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0xdU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xdU];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0xeU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xeU];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0xfU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xfU];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x10U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x10U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x11U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x11U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x12U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x12U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x13U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x13U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x14U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x14U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x15U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x15U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x16U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x16U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x17U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x17U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[0x18U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x18U];
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__error_sys_q = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__request_accept = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__response_commit = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__instr_err_q = 0U;
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_q 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__rst_n) 
           && (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_d));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_valid_q 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__rst_n) 
           && (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__data_req_out));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_q 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__rst_n) 
           && (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_d));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__rst_n) 
           && (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d));
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[1U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[1U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[2U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[2U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[3U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[3U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[4U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[4U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[5U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[5U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[6U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[6U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[7U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[7U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[8U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[8U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[9U] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[9U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0xaU] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0xaU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0xbU] 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0xbU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard_active 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__rsp_sys_guard_active;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_hold = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_valid = 0U;
    if ((4U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
        if ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
            if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q)))) {
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_hold = 0U;
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_valid = 1U;
            }
        }
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x1fU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__31__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x1eU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__30__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x1dU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__29__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x1cU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__28__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x1bU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__27__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x1aU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__26__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x19U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__25__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x18U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__24__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x17U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__23__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x16U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__22__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x15U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__21__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x14U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__20__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x13U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__19__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x12U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__18__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x11U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__17__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x10U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__16__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0xfU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__15__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0xeU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__14__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0xdU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__13__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0xcU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__12__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0xbU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__11__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0xaU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__10__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[9U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__9__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[8U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__8__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[7U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__7__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[6U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__6__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[5U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__5__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[4U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__4__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[3U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__3__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[2U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__2__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[1U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__1__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_or_pmp_err 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_q) 
           | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_err_q) 
              | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_resp_valid 
        = (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_valid_q) 
            | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q)) 
           & (0U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_addr_incr_req = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_update = 0U;
    if ((4U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
        if ((1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)))) {
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_addr_incr_req = 1U;
                if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_valid_q) {
                    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_update 
                        = (1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q)));
                }
            }
        }
    } else if ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_addr_incr_req 
            = ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) 
               || (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_q));
        if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)))) {
            if (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_valid_q) 
                 | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q))) {
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_update 
                    = (1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q)));
            }
        }
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_seen_sys_q 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_seen_sys_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__request_valid = __Vdly__tb_rtnn_c2_soc_42__DOT__request_valid;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__busy_sys_q 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__busy_sys_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_toggle_sys_q 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_toggle_sys_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sys_q 
        = __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sys_q;
    if (__Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v0) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q[__Vdlyvdim0__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v0))) 
                & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
                [__Vdlyvdim0__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v0]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v0) 
                                   << (IData)(__Vdlyvlsb__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v0))));
    }
    if (__Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v1) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q[__Vdlyvdim0__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v1] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v1))) 
                & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
                [__Vdlyvdim0__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v1]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v1) 
                                   << (IData)(__Vdlyvlsb__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v1))));
    }
    if (__Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v2) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q[__Vdlyvdim0__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v2] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v2))) 
                & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
                [__Vdlyvdim0__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v2]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v2) 
                                   << (IData)(__Vdlyvlsb__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v2))));
    }
    if (__Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v3) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q[__Vdlyvdim0__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v3] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v3))) 
                & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
                [__Vdlyvdim0__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v3]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v3) 
                                   << (IData)(__Vdlyvlsb__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v3))));
    }
    if (__Vdlyvset__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q__v4) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q[0U] = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q[1U] = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q[2U] = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q[3U] = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q[4U] = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q[5U] = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q[6U] = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q[7U] = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q[8U] = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q[9U] = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q[0xaU] = 0U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q[0xbU] = 0U;
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
        [0U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[1U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
        [1U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[2U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
        [2U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[3U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
        [3U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[4U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
        [4U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[5U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
        [5U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[6U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
        [6U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[7U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
        [7U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[8U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
        [8U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[9U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
        [9U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0xaU] 
        = (IData)((((QData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
                                    [0xbU])) << 0x20U) 
                   | (QData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
                                     [0xaU]))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0xbU] 
        = (IData)(((((QData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
                                     [0xbU])) << 0x20U) 
                    | (QData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
                                      [0xaU]))) >> 0x20U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_consume_sync2_sys_q 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__rst_n) 
           && (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_consume_sync1_sys_q));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_sync2_sys_q 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__rst_n) 
           && (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_sync1_sys_q));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_consume_sync1_sys_q 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__rst_n) 
           && (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_consume_toggle_tck_q));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_sync1_sys_q 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__rst_n) 
           && (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_toggle_tck_q));
}

extern const VlUnpacked<CData/*0:0*/, 128> Vtb_rtnn_c2_soc_42__ConstPool__TABLE_hd5b48b0a_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_rtnn_c2_soc_42__ConstPool__TABLE_hb804351c_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_rtnn_c2_soc_42__ConstPool__TABLE_h2fe71d6b_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_rtnn_c2_soc_42__ConstPool__TABLE_ha686e182_0;

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__3(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__3\n"); );
    // Init
    QData/*33:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand1;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand1 = 0;
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*6:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*6:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    // Body
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0U] 
        = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.dummy_instr_id_o)
            ? vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_dummy_r0__DOT__rf_r0_q
            : 0U);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a = 1ULL;
    __Vtableidx4 = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_left 
        = Vtb_rtnn_c2_soc_42__ConstPool__TABLE_hd5b48b0a_0
        [__Vtableidx4];
    __Vtableidx2 = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_signed 
        = Vtb_rtnn_c2_soc_42__ConstPool__TABLE_hb804351c_0
        [__Vtableidx2];
    __Vtableidx1 = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift1 
        = Vtb_rtnn_c2_soc_42__ConstPool__TABLE_h2fe71d6b_0
        [__Vtableidx1];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift2 
        = Vtb_rtnn_c2_soc_42__ConstPool__TABLE_h2fe71d6b_0
        [__Vtableidx1];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift3 
        = Vtb_rtnn_c2_soc_42__ConstPool__TABLE_h2fe71d6b_0
        [__Vtableidx1];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_b_negate 
        = Vtb_rtnn_c2_soc_42__ConstPool__TABLE_ha686e182_0
        [__Vtableidx1];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel 
        = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.div_sel_ex_o) 
           | (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.mult_sel_ex_o));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__ram_instr_rvalid 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__rst_n) 
           && (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_req_o));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg
        [(0x1fU & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                   >> 0x14U))];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_a 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg
        [(0x1fU & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                   >> 0xfU))];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_op_b 
        = (0xffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_op_a 
        = (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_a 
           >> 0x10U);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult1_res_uns 
        = (0x3ffffffffULL & VL_MULS_QQQ(34, (0x3ffffffffULL 
                                             & VL_EXTENDS_QI(34,17, 
                                                             (0xffffU 
                                                              & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_a))), 
                                        (0x3ffffffffULL 
                                         & VL_EXTENDS_QI(34,17, 
                                                         (0xffffU 
                                                          & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b 
        = (1ULL | ((QData)((IData)((~ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b))) 
                   << 1U));
    if ((4U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
        if ((1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a = 1ULL;
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b 
                    = (1ULL | ((QData)((IData)((~ (
                                                   (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U] 
                                                    << 0x1eU) 
                                                   | (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[1U] 
                                                      >> 2U))))) 
                               << 1U));
            } else {
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a 
                    = (1ULL | ((QData)((IData)(((vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U] 
                                                 << 0x1eU) 
                                                | (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[1U] 
                                                   >> 2U)))) 
                               << 1U));
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b 
                    = (1ULL | ((QData)((IData)((~ vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[0U]))) 
                               << 1U));
            }
        }
    } else if ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
        if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a 
                = (1ULL | ((QData)((IData)(((vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U] 
                                             << 0x1eU) 
                                            | (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[1U] 
                                               >> 2U)))) 
                           << 1U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b 
                = (1ULL | ((QData)((IData)((~ vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[0U]))) 
                           << 1U));
        } else {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a = 1ULL;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b 
                = (1ULL | ((QData)((IData)((~ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b))) 
                           << 1U));
        }
    } else {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a = 1ULL;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b 
            = ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))
                ? (1ULL | ((QData)((IData)((~ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_a))) 
                           << 1U)) : (1ULL | ((QData)((IData)(
                                                              (~ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b))) 
                                              << 1U)));
    }
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand1 
        = (QData)((IData)((0xffffU & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult1_res_uns 
                                              >> 0x10U)))));
    if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q) {
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_op_b 
                = (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b 
                   >> 0x10U);
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_op_a 
                = (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_a 
                   >> 0x10U);
            tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand1 = 0ULL;
        }
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand1_ext 
        = (((QData)((IData)((1U & (IData)((tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand1 
                                           >> 0x21U))))) 
            << 0x22U) | tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand1);
}

extern const VlUnpacked<CData/*0:0*/, 1024> Vtb_rtnn_c2_soc_42__ConstPool__TABLE_h9d63e220_0;

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__4(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__4\n"); );
    // Init
    IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__operand_a_rev;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__operand_a_rev = 0;
    IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_operand;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_operand = 0;
    QData/*32:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext_signed;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext_signed = 0;
    QData/*32:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext = 0;
    IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result = 0;
    IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__bwlogic_result;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__bwlogic_result = 0;
    CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__is_greater_equal;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__is_greater_equal = 0;
    SData/*9:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    // Body
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__operand_a_rev 
        = ((vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
            << 0x1fU) | ((0x40000000U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                         << 0x1dU)) 
                         | ((0x20000000U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                            << 0x1bU)) 
                            | ((0x10000000U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                               << 0x19U)) 
                               | ((0x8000000U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                 << 0x17U)) 
                                  | ((0x4000000U & 
                                      (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                       << 0x15U)) | 
                                     ((0x2000000U & 
                                       (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                        << 0x13U)) 
                                      | ((0x1000000U 
                                          & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                             << 0x11U)) 
                                         | ((0x800000U 
                                             & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                << 0xfU)) 
                                            | ((0x400000U 
                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                   << 0xdU)) 
                                               | ((0x200000U 
                                                   & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                      << 0xbU)) 
                                                  | ((0x100000U 
                                                      & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                         << 9U)) 
                                                     | ((0x80000U 
                                                         & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                            << 7U)) 
                                                        | ((0x40000U 
                                                            & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                               << 5U)) 
                                                           | ((0x20000U 
                                                               & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                  << 3U)) 
                                                              | ((0x10000U 
                                                                  & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                     << 1U)) 
                                                                 | ((0x8000U 
                                                                     & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                        >> 1U)) 
                                                                    | ((0x4000U 
                                                                        & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                           >> 3U)) 
                                                                       | ((0x2000U 
                                                                           & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                              >> 5U)) 
                                                                          | ((0x1000U 
                                                                              & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 7U)) 
                                                                             | ((0x800U 
                                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 9U)) 
                                                                                | ((0x400U 
                                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 0xbU)) 
                                                                                | ((0x200U 
                                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 0xdU)) 
                                                                                | ((0x100U 
                                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 0xfU)) 
                                                                                | ((0x80U 
                                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 0x11U)) 
                                                                                | ((0x40U 
                                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 0x13U)) 
                                                                                | ((0x20U 
                                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 0x15U)) 
                                                                                | ((0x10U 
                                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 0x17U)) 
                                                                                | ((8U 
                                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 0x1bU)) 
                                                                                | ((2U 
                                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 0x1dU)) 
                                                                                | (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 0x1fU))))))))))))))))))))))))))))))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__bwlogic_result 
        = (((3U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator)) 
            | (6U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator)))
            ? (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
               | vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.alu_operand_b_ex_o)
            : (((4U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator)) 
                | (7U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator)))
                ? (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                   & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.alu_operand_b_ex_o)
                : (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                   ^ vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.alu_operand_b_ex_o)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
        = (0x3ffffffffULL & (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
                               ? vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a
                               : ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift1)
                                   ? (1ULL | ((QData)((IData)(
                                                              (0x7fffffffU 
                                                               & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a))) 
                                              << 2U))
                                   : ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift2)
                                       ? (1ULL | ((QData)((IData)(
                                                                  (0x3fffffffU 
                                                                   & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a))) 
                                                  << 3U))
                                       : ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift3)
                                           ? (1ULL 
                                              | ((QData)((IData)(
                                                                 (0x1fffffffU 
                                                                  & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a))) 
                                                 << 4U))
                                           : (1ULL 
                                              | ((QData)((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a)) 
                                                 << 1U)))))) 
                             + (0x1ffffffffULL & ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
                                                   ? vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b
                                                   : 
                                                  ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_b_negate)
                                                    ? 
                                                   (~ 
                                                    ((QData)((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.alu_operand_b_ex_o)) 
                                                     << 1U))
                                                    : 
                                                   ((QData)((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.alu_operand_b_ex_o)) 
                                                    << 1U))))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_operand 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_left)
            ? tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__operand_a_rev
            : vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a);
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext_signed 
        = (0x1ffffffffULL & VL_SHIFTRS_QQI(33,33,5, 
                                           (((QData)((IData)(
                                                             ((8U 
                                                               == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator)) 
                                                              & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_operand 
                                                                 >> 0x1fU)))) 
                                             << 0x20U) 
                                            | (QData)((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_operand))), 
                                           (0x1fU & 
                                            ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.instr_first_cycle_id_o)
                                              ? vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.alu_operand_b_ex_o
                                              : (- vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.alu_operand_b_ex_o)))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext 
        = tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext_signed;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
        = (IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xfffffff8U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((4U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                     >> 0x1bU)) | ((2U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                          >> 0x1dU)) 
                                   | (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                      >> 0x1fU))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xffffffc7U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x20U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                        >> 0x15U)) | ((0x10U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                >> 0x17U)) 
                                      | (8U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                               >> 0x19U)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xfffffe3fU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x100U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                         >> 0xfU)) | ((0x80U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                >> 0x11U)) 
                                      | (0x40U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                  >> 0x13U)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xfffff1ffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x800U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                         >> 9U)) | ((0x400U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                               >> 0xbU)) 
                                    | (0x200U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                 >> 0xdU)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xffff8fffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x4000U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                          >> 3U)) | ((0x2000U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                 >> 5U)) 
                                     | (0x1000U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                   >> 7U)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xfffc7fffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x20000U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                           << 3U)) | ((0x10000U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                   << 1U)) 
                                      | (0x8000U & 
                                         (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                          >> 1U)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xffe3ffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x100000U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                            << 9U)) | ((0x80000U & 
                                        (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                         << 7U)) | 
                                       (0x40000U & 
                                        (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                         << 5U)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xff1fffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x800000U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                            << 0xfU)) | ((0x400000U 
                                          & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                             << 0xdU)) 
                                         | (0x200000U 
                                            & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                               << 0xbU)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xf8ffffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x4000000U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                             << 0x15U)) | ((0x2000000U 
                                            & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                               << 0x13U)) 
                                           | (0x1000000U 
                                              & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                 << 0x11U)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xc7ffffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x20000000U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                              << 0x1bU)) | ((0x10000000U 
                                             & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                << 0x19U)) 
                                            | (0x8000000U 
                                               & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                  << 0x17U)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0x3fffffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
               << 0x1fU) | (0x40000000U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                           << 0x1dU))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_left)
            ? vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev
            : tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__mmio_read_valid 
        = ((0x20000U == (0xfffffc00U & ((IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                 >> 3U)) 
                                        << 2U))) & 
           ((8U == (0xffU & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                     >> 3U)))) | ((0x24U 
                                                   <= 
                                                   (0x3fcU 
                                                    & ((IData)(
                                                               (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                >> 3U)) 
                                                       << 2U))) 
                                                  & (0x84U 
                                                     >= 
                                                     (0x3fcU 
                                                      & ((IData)(
                                                                 (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                  >> 3U)) 
                                                         << 2U))))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__mmio_write_valid 
        = ((0x20000U == (0xfffffc00U & ((IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                 >> 3U)) 
                                        << 2U))) & 
           ((0x22U == (0xffU & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                        >> 3U)))) | 
            (((0x8cU <= (0x3fcU & ((IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                            >> 3U)) 
                                   << 2U))) & (0xb8U 
                                               >= (0x3fcU 
                                                   & ((IData)(
                                                              (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                               >> 3U)) 
                                                      << 2U)))) 
             | (0x2fU == (0xffU & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                           >> 3U)))))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__is_greater_equal 
        = (1U & ((1U & ((vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U] 
                         >> 1U) ^ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[0U] 
                                   >> 0x1fU))) ? (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U] 
                                                  >> 1U)
                  : (~ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                >> 0x20U)))));
    __Vtableidx3 = (((0U != (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                     >> 1U))) << 9U) 
                    | ((0x100U & ((((vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                     ^ vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.alu_operand_b_ex_o) 
                                    >> 0x1fU) ? ((vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                  >> 0x1fU) 
                                                 ^ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_signed))
                                    : (~ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                  >> 0x20U)))) 
                                  << 8U)) | (((0U == (IData)(
                                                             (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                              >> 1U))) 
                                              << 7U) 
                                             | (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result 
        = Vtb_rtnn_c2_soc_42__ConstPool__TABLE_h9d63e220_0
        [__Vtableidx3];
    if (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__is_greater_equal) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_remainder 
            = (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                       >> 1U));
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_quotient 
            = ((QData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_q)) 
               | (QData)((IData)(((IData)(1U) << (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_q)))));
    } else {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_remainder 
            = ((vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U] 
                << 0x1eU) | (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[1U] 
                             >> 2U));
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_quotient 
            = (QData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_q));
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_result = 0U;
    if ((0x40U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))) {
        if ((1U & (~ ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator) 
                      >> 5U)))) {
            if ((1U & (~ ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator)))) {
                                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_result = 0U;
                            }
                        }
                    }
                }
            }
        }
    } else {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_result 
            = ((0x20U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                ? ((0x10U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                    ? 0U : ((8U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                             ? ((4U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                 ? ((2U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                     ? 0U : ((1U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                              ? 0U : (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result)))
                                 : ((2U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                     ? ((1U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                         ? (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result)
                                         : 0U) : 0U))
                             : 0U)) : ((0x10U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                        ? ((8U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                            ? ((4U 
                                                & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                ? (
                                                   (2U 
                                                    & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                     ? 0U
                                                     : (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result))
                                                    : (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result))
                                                : (
                                                   (2U 
                                                    & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                    ? (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                     ? (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result)
                                                     : (IData)(
                                                               (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                >> 1U)))))
                                            : ((4U 
                                                & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                ? (
                                                   (2U 
                                                    & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                    ? (IData)(
                                                              (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                               >> 1U))
                                                    : 0U)
                                                : 0U))
                                        : ((8U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                            ? ((4U 
                                                & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                ? (
                                                   (2U 
                                                    & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                     ? 0U
                                                     : tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result))
                                                : tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result)
                                            : ((4U 
                                                & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                ? tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__bwlogic_result
                                                : (
                                                   (2U 
                                                    & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                    ? tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__bwlogic_result
                                                    : (IData)(
                                                              (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                               >> 1U)))))));
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_d 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_q;
    if ((1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q) 
                  >> 2U)))) {
        if ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
            if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_d 
                    = (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_quotient);
            }
        } else if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_d = 0U;
        }
    }
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__6(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__6\n"); );
    // Init
    IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__instr_rdata;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__instr_rdata = 0;
    QData/*38:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o = 0;
    QData/*38:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_instr_secded__DOT__sv2v_cast_39__180__Vfuncout;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_instr_secded__DOT__sv2v_cast_39__180__Vfuncout = 0;
    QData/*38:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_instr_secded__DOT__sv2v_cast_39__180__inp;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_instr_secded__DOT__sv2v_cast_39__180__inp = 0;
    // Body
    if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__ram_dreq) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__data_hit_q 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__ram_data_hit;
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__instr_ram_q 
        = ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem3
            [vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__instr_idx] 
            << 0x18U) | ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem2
                          [vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__instr_idx] 
                          << 0x10U) | ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem1
                                        [vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__instr_idx] 
                                        << 8U) | vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem0
                                       [vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__instr_idx])));
    if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_req_o) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__instr_hit_q 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__instr_hit;
    }
    if ((((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__ram_dreq) 
          & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__ram_data_hit)) 
         & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__lsu_we))) {
        if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_be))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem0[vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__data_idx] 
                = (0xffU & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core));
        }
        if ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_be))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem1[vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__data_idx] 
                = (0xffU & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
                                    >> 8U)));
        }
        if ((4U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_be))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem2[vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__data_idx] 
                = (0xffU & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
                                    >> 0x10U)));
        }
        if ((8U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_be))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem3[vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__data_idx] 
                = (0xffU & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
                                    >> 0x18U)));
        }
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__data_ram_q 
        = ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem3
            [vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__data_idx] 
            << 0x18U) | ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem2
                          [vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__data_idx] 
                          << 0x10U) | ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem1
                                        [vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__data_idx] 
                                        << 8U) | vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem0
                                       [vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__data_idx])));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__instr_rdata 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__instr_hit_q)
            ? vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__instr_ram_q
            : 0U);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_instr_secded__DOT__sv2v_cast_39__180__inp 
        = (QData)((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__instr_rdata));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_instr_secded__DOT__sv2v_cast_39__180__Vfuncout 
        = __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_instr_secded__DOT__sv2v_cast_39__180__inp;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o 
        = __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_instr_secded__DOT__sv2v_cast_39__180__Vfuncout;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o 
        = ((0x7effffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x2606bd25ULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o))))) 
              << 0x20U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o 
        = ((0x7dffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0xdeba8050ULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o))))) 
              << 0x21U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o 
        = ((0x7bffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x413d89aaULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o))))) 
              << 0x22U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o 
        = ((0x77ffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x31234ed1ULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o))))) 
              << 0x23U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o 
        = ((0x6fffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0xc2c1323bULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o))))) 
              << 0x24U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o 
        = ((0x5fffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x2dcc624cULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o))))) 
              << 0x25U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o 
        = ((0x3fffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x98505586ULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o))))) 
              << 0x26U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o 
        = (0x2a00000000ULL ^ tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
        = (((QData)((IData)((0x7fU & (IData)((tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o 
                                              >> 0x20U))))) 
            << 0x20U) | (QData)((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__instr_rdata)));
}

extern const VlUnpacked<CData/*3:0*/, 32> Vtb_rtnn_c2_soc_42__ConstPool__TABLE_hee875898_0;

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__10(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__10\n"); );
    // Init
    QData/*34:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_ext;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_ext = 0;
    CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_a;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_a = 0;
    CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_b;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_b = 0;
    QData/*33:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d = 0;
    CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_a;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_a = 0;
    CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_b;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_b = 0;
    IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_denominator_d;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_denominator_d = 0;
    QData/*33:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_res;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_res = 0;
    CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_sign_a;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_sign_a = 0;
    CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_sign_b;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_sign_b = 0;
    QData/*33:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2 = 0;
    QData/*33:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3 = 0;
    QData/*34:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2_ext;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2_ext = 0;
    QData/*34:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3_ext;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3_ext = 0;
    CData/*4:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    // Body
    __Vtableidx5 = (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_q) 
                     << 4U) | ((0xcU & ((IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                 >> 1U)) 
                                        << 2U)) | (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__lsu_type)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_be 
        = Vtb_rtnn_c2_soc_42__ConstPool__TABLE_hee875898_0
        [__Vtableidx5];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__split_misaligned_access 
        = (((0U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__lsu_type)) 
            & (0U != (3U & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                    >> 1U))))) | (IData)(
                                                         ((1U 
                                                           == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__lsu_type)) 
                                                          & (6ULL 
                                                             == 
                                                             (6ULL 
                                                              & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext)))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_a 
        = ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_a 
            >> 0x1fU) & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_signed_mode));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_b 
        = ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b 
            >> 0x1fU) & ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_signed_mode) 
                         >> 1U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_a 
        = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_signed_mode) 
           & (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_a 
              >> 0x1fU));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_b 
        = (IData)((((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_signed_mode) 
                    >> 1U) & (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b 
                              >> 0x1fU)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_d = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_d 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_hold = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_store_err 
        = (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_or_pmp_err) 
            & ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q) 
               & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_resp_valid))) 
           & ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__VdfgTmp_h50e2f79d__0) 
              & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__lsu_we)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_load_err 
        = (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_or_pmp_err) 
            & ((~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q)) 
               & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_resp_valid))) 
           & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.expecting_load_resp_o));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_d 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_q;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_denominator_d 
        = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[0U];
    if ((1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q)))) {
                if ((2U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_operator))) {
                    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_d 
                        = (0U == (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                          >> 1U)));
                }
            }
            if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_d 
                    = ((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_a)
                        ? (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                   >> 1U)) : vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_a);
            }
        }
        if ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
            if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q)))) {
                tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_denominator_d 
                    = ((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_b)
                        ? (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                   >> 1U)) : vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b);
            }
        }
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_d 
        = (0x1fU & ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_q) 
                    - (IData)(1U)));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d 
        = (0x3ffffffffULL & (((QData)((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U])) 
                              << 0x1eU) | ((QData)((IData)(
                                                           vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[1U])) 
                                           >> 2U)));
    if ((4U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_d 
            = ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))
                ? 0U : ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))
                         ? 6U : 5U));
        if ((1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q) 
                      >> 1U)))) {
            tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d 
                = (0x3ffffffffULL & ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))
                                      ? ((2U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_operator))
                                          ? (((~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_q)) 
                                              & ((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_a) 
                                                 ^ (IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_b)))
                                              ? (QData)((IData)(
                                                                (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                 >> 1U)))
                                              : (((QData)((IData)(
                                                                  vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U])) 
                                                  << 0x3eU) 
                                                 | (((QData)((IData)(
                                                                     vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U])) 
                                                     << 0x1eU) 
                                                    | ((QData)((IData)(
                                                                       vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[1U])) 
                                                       >> 2U))))
                                          : ((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_a)
                                              ? (QData)((IData)(
                                                                (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                 >> 1U)))
                                              : (((QData)((IData)(
                                                                  vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U])) 
                                                  << 0x3eU) 
                                                 | (((QData)((IData)(
                                                                     vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U])) 
                                                     << 0x1eU) 
                                                    | ((QData)((IData)(
                                                                       vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[1U])) 
                                                       >> 2U)))))
                                      : ((2U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_operator))
                                          ? vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_quotient
                                          : (QData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_remainder)))));
        }
    } else if ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
        if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_d 
                = ((1U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_q))
                    ? 4U : 3U);
            tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d 
                = (((QData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_remainder)) 
                    << 1U) | (QData)((IData)((1U & 
                                              (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_q 
                                               >> (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_d))))));
        } else {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_d = 3U;
            tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d 
                = (QData)((IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_q 
                                   >> 0x1fU)));
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_d = 0x1fU;
        }
    } else if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_d = 2U;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_d = 0x1fU;
    } else {
        if ((2U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_operator))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_d 
                = (((~ ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
                        >> 1U)) & (0U == (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                  >> 1U))))
                    ? 6U : 1U);
            tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d = 0x3ffffffffULL;
        } else {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_d 
                = (((~ ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
                        >> 1U)) & (0U == (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                  >> 1U))))
                    ? 6U : 1U);
            tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d 
                = (QData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_a));
        }
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_d = 0x1fU;
    }
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_sign_a 
        = tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_a;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2 
        = (0x3ffffffffULL & VL_MULS_QQQ(34, (0x3ffffffffULL 
                                             & VL_EXTENDS_QI(34,17, 
                                                             (0xffffU 
                                                              & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_a))), 
                                        (0x3ffffffffULL 
                                         & VL_EXTENDS_QI(34,17, 
                                                         (((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_b) 
                                                           << 0x10U) 
                                                          | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b 
                                                             >> 0x10U))))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_sign_b = 0U;
    if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_d = 0U;
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_hold = 0U;
            tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_sign_a 
                = tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_a;
            tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2 
                = (((QData)((IData)((0xffffU & (- (IData)(
                                                          ((0U 
                                                            != (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_signed_mode)) 
                                                           & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U] 
                                                              >> 3U))))))) 
                    << 0x12U) | (QData)((IData)((0x3ffffU 
                                                 & ((vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U] 
                                                     << 0xeU) 
                                                    | (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[1U] 
                                                       >> 0x12U))))));
        }
    } else {
        if ((0U != (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_operator))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_d = 1U;
        }
        if ((0U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_operator))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_hold = 0U;
        }
    }
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2_ext 
        = (((QData)((IData)((1U & (IData)((tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2 
                                           >> 0x21U))))) 
            << 0x22U) | tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2);
    if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q) {
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q) {
            tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_sign_b 
                = tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_b;
        }
    }
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_res 
        = (0x3ffffffffULL & VL_MULS_QQQ(34, (0x3ffffffffULL 
                                             & VL_EXTENDS_QI(34,17, 
                                                             (((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_sign_a) 
                                                               << 0x10U) 
                                                              | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_op_a)))), 
                                        (0x3ffffffffULL 
                                         & VL_EXTENDS_QI(34,17, 
                                                         (((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_sign_b) 
                                                           << 0x10U) 
                                                          | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_op_b))))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3 
        = tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_res;
    if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q) {
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q) {
            tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3 
                = tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_res;
        }
    }
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3_ext 
        = (((QData)((IData)((1U & (IData)((tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3 
                                           >> 0x21U))))) 
            << 0x22U) | tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3);
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_ext 
        = (0x7ffffffffULL & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand1_ext 
                              ^ (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2_ext 
                                 ^ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3_ext)) 
                             + VL_SHIFTL_QQI(35,35,32, 
                                             ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand1_ext 
                                               & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2_ext 
                                                  | tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3_ext)) 
                                              | (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2_ext 
                                                 & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3_ext)), 1U)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d 
        = (QData)((IData)((((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_ext) 
                            << 0x10U) | (0xffffU & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult1_res_uns)))));
    if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q) {
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d 
                = (0x3ffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_ext);
        }
    } else if ((0U != (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_operator))) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d 
            = (0x3ffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_ext);
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_d_ex[0U] 
        = (IData)(((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
                    ? (QData)((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_denominator_d))
                    : 0ULL));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_d_ex[1U] 
        = (((IData)(((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
                      ? ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.div_sel_ex_o)
                          ? tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d
                          : vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d)
                      : 0ULL)) << 2U) | (IData)((((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
                                                   ? (QData)((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_denominator_d))
                                                   : 0ULL) 
                                                 >> 0x20U)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_d_ex[2U] 
        = (((IData)(((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
                      ? ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.div_sel_ex_o)
                          ? tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d
                          : vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d)
                      : 0ULL)) >> 0x1eU) | ((IData)(
                                                    (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
                                                       ? 
                                                      ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.div_sel_ex_o)
                                                        ? tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d
                                                        : vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d)
                                                       : 0ULL) 
                                                     >> 0x20U)) 
                                            << 2U));
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42___024root___nba_comb__TOP__1(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___nba_comb__TOP__1\n"); );
    // Init
    IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_rdata;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_rdata = 0;
    QData/*38:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o = 0;
    IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o = 0;
    QData/*38:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_data_secded__DOT__sv2v_cast_39__179__Vfuncout;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_data_secded__DOT__sv2v_cast_39__179__Vfuncout = 0;
    QData/*38:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_data_secded__DOT__sv2v_cast_39__179__inp;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_data_secded__DOT__sv2v_cast_39__179__inp = 0;
    // Body
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_rdata 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_ram_q)
            ? ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__data_hit_q)
                ? vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__data_ram_q
                : 0U) : vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__mmio_read_data_q);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_data_secded__DOT__sv2v_cast_39__179__inp 
        = (QData)((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_rdata));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_data_secded__DOT__sv2v_cast_39__179__Vfuncout 
        = __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_data_secded__DOT__sv2v_cast_39__179__inp;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o 
        = __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_data_secded__DOT__sv2v_cast_39__179__Vfuncout;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o 
        = ((0x7effffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x2606bd25ULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o))))) 
              << 0x20U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o 
        = ((0x7dffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0xdeba8050ULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o))))) 
              << 0x21U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o 
        = ((0x7bffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x413d89aaULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o))))) 
              << 0x22U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o 
        = ((0x77ffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x31234ed1ULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o))))) 
              << 0x23U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o 
        = ((0x6fffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0xc2c1323bULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o))))) 
              << 0x24U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o 
        = ((0x5fffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x2dcc624cULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o))))) 
              << 0x25U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o 
        = ((0x3fffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x98505586ULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o))))) 
              << 0x26U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o 
        = (0x2a00000000ULL ^ tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
        = (((QData)((IData)((0x7fU & (IData)((tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o 
                                              >> 0x20U))))) 
            << 0x20U) | (QData)((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_rdata)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_rdata_ext 
        = ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_type_q))
            ? ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                ? ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                    ? ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                        ? (((- (IData)((1U & (IData)(
                                                     (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                      >> 0x1fU))))) 
                            << 8U) | (0xffU & (IData)(
                                                      (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                       >> 0x18U))))
                        : (0xffU & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                            >> 0x18U))))
                    : ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                        ? (((- (IData)((1U & (IData)(
                                                     (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                      >> 0x17U))))) 
                            << 8U) | (0xffU & (IData)(
                                                      (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                       >> 0x10U))))
                        : (0xffU & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                            >> 0x10U)))))
                : ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                    ? ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                        ? (((- (IData)((1U & (IData)(
                                                     (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                      >> 0xfU))))) 
                            << 8U) | (0xffU & (IData)(
                                                      (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                       >> 8U))))
                        : (0xffU & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                            >> 8U))))
                    : ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                        ? (((- (IData)((1U & (IData)(
                                                     (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                      >> 7U))))) 
                            << 8U) | (0xffU & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf)))
                        : (0xffU & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf)))))
            : ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_type_q))
                ? ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                    ? ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                        ? ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                            ? (((- (IData)((1U & (IData)(
                                                         (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                          >> 7U))))) 
                                << 0x10U) | ((0xff00U 
                                              & ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf) 
                                                 << 8U)) 
                                             | (0xffU 
                                                & (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q 
                                                   >> 0x10U))))
                            : ((0xff00U & ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf) 
                                           << 8U)) 
                               | (0xffU & (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q 
                                           >> 0x10U))))
                        : ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                            ? (((- (IData)((1U & (IData)(
                                                         (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                          >> 0x1fU))))) 
                                << 0x10U) | (0xffffU 
                                             & (IData)(
                                                       (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                        >> 0x10U))))
                            : (0xffffU & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                  >> 0x10U)))))
                    : ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                        ? ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                            ? (((- (IData)((1U & (IData)(
                                                         (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                          >> 0x17U))))) 
                                << 0x10U) | (0xffffU 
                                             & (IData)(
                                                       (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                        >> 8U))))
                            : (0xffffU & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                  >> 8U))))
                        : ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                            ? (((- (IData)((1U & (IData)(
                                                         (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                          >> 0xfU))))) 
                                << 0x10U) | (0xffffU 
                                             & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf)))
                            : (0xffffU & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf)))))
                : ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                    ? ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                        ? (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf) 
                            << 8U) | (0xffU & (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q 
                                               >> 0x10U)))
                        : (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf) 
                            << 0x10U) | (0xffffU & 
                                         (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q 
                                          >> 8U))))
                    : ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                        ? (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf) 
                            << 0x18U) | vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q)
                        : (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o 
        = ((0x7eU & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
           | (1U & VL_REDXOR_64((0x12606bd25ULL & (0x2a00000000ULL 
                                                   ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o 
        = ((0x7dU & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
           | (2U & (VL_REDXOR_64((0x2deba8050ULL & 
                                  (0x2a00000000ULL 
                                   ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf))) 
                    << 1U)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o 
        = ((0x7bU & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
           | (4U & (VL_REDXOR_64((0x4413d89aaULL & 
                                  (0x2a00000000ULL 
                                   ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf))) 
                    << 2U)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o 
        = ((0x77U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
           | (8U & (VL_REDXOR_64((0x831234ed1ULL & 
                                  (0x2a00000000ULL 
                                   ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf))) 
                    << 3U)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o 
        = ((0x6fU & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
           | (0x10U & (VL_REDXOR_64((0x10c2c1323bULL 
                                     & (0x2a00000000ULL 
                                        ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf))) 
                       << 4U)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o 
        = ((0x5fU & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
           | (0x20U & (VL_REDXOR_64((0x202dcc624cULL 
                                     & (0x2a00000000ULL 
                                        ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf))) 
                       << 5U)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o 
        = ((0x3fU & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
           | (0x40U & (VL_REDXOR_64((0x4098505586ULL 
                                     & (0x2a00000000ULL 
                                        ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf))) 
                       << 6U)));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xfffffffcU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((2U & (((0x54U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                      ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                 >> 1U))) << 1U)) | 
              (1U & ((0x19U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                     ^ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf)))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xfffffff3U & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((8U & (((0x34U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                      ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                 >> 3U))) << 3U)) | 
              (4U & (((0x61U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                      ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                 >> 2U))) << 2U))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xffffffcfU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x20U & (((0x15U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                         ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                    >> 5U))) << 5U)) 
              | (0x10U & (((0x1aU == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                           ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                      >> 4U))) << 4U))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xffffff3fU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x80U & (((0x4cU == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                         ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                    >> 7U))) << 7U)) 
              | (0x40U & (((0x2aU == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                           ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                      >> 6U))) << 6U))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xfffffcffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x200U & (((0x38U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                          ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                     >> 9U))) << 9U)) 
              | (0x100U & (((0x45U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                            ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                       >> 8U))) << 8U))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xfffff3ffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x800U & (((0xdU == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                          ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                     >> 0xbU))) << 0xbU)) 
              | (0x400U & (((0x49U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                            ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                       >> 0xaU))) << 0xaU))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xffffcfffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x2000U & (((0x31U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                           ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                      >> 0xdU))) << 0xdU)) 
              | (0x1000U & (((0x51U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                             ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                        >> 0xcU))) 
                            << 0xcU))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xffff3fffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x8000U & (((7U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                           ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                      >> 0xfU))) << 0xfU)) 
              | (0x4000U & (((0x68U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                             ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                        >> 0xeU))) 
                            << 0xeU))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xfffcffffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x20000U & (((0xbU == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                            ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                       >> 0x11U))) 
                           << 0x11U)) | (0x10000U & 
                                         (((0x1cU == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                                           ^ (IData)(
                                                     (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                      >> 0x10U))) 
                                          << 0x10U))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xfff3ffffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x80000U & (((0x26U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                            ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                       >> 0x13U))) 
                           << 0x13U)) | (0x40000U & 
                                         (((0x25U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                                           ^ (IData)(
                                                     (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                      >> 0x12U))) 
                                          << 0x12U))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xffcfffffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x200000U & (((0xeU == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                             ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                        >> 0x15U))) 
                            << 0x15U)) | (0x100000U 
                                          & (((0x46U 
                                               == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                                              ^ (IData)(
                                                        (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                         >> 0x14U))) 
                                             << 0x14U))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xff3fffffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x800000U & (((0x32U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                             ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                        >> 0x17U))) 
                            << 0x17U)) | (0x400000U 
                                          & (((0x70U 
                                               == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                                              ^ (IData)(
                                                        (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                         >> 0x16U))) 
                                             << 0x16U))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xfcffffffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x2000000U & (((0x13U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                              ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                         >> 0x19U))) 
                             << 0x19U)) | (0x1000000U 
                                           & (((0x2cU 
                                                == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                                               ^ (IData)(
                                                         (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                          >> 0x18U))) 
                                              << 0x18U))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xf3ffffffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x8000000U & (((0x62U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                              ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                         >> 0x1bU))) 
                             << 0x1bU)) | (0x4000000U 
                                           & (((0x23U 
                                                == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                                               ^ (IData)(
                                                         (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                          >> 0x1aU))) 
                                              << 0x1aU))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xcfffffffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x20000000U & (((0x29U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                               ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                          >> 0x1dU))) 
                              << 0x1dU)) | (0x10000000U 
                                            & (((0x4aU 
                                                 == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                                                ^ (IData)(
                                                          (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                           >> 0x1cU))) 
                                               << 0x1cU))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0x3fffffffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((((0x52U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                           >> 0x1fU))) << 0x1fU) | 
              (0x40000000U & (((0x16U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                               ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                          >> 0x1eU))) 
                              << 0x1eU))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__ecc_err 
        = ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__ecc_err)) 
           | (1U & VL_REDXOR_8(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__ecc_err 
        = ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__ecc_err)) 
           | (((~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__ecc_err)) 
               & (0U != (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o))) 
              << 1U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT____VdfgTmp_h3fd48639__0 
        = ((0U != (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__ecc_err)) 
           & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_valid_q));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_lsu 
        = (((0U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)) 
            & ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_valid_q) 
               & ((~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_or_pmp_err)) 
                  & ((~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q)) 
                     & (~ (IData)((0U != (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__ecc_err)))))))) 
           & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.expecting_load_resp_o));
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42___024root___nba_comb__TOP__3(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___nba_comb__TOP__3\n"); );
    // Init
    CData/*0:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__174__Vfuncout;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__174__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__174__a;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__174__a = 0;
    SData/*15:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__177__Vfuncout;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__177__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__177__a;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__177__a = 0;
    // Body
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__perf_instr_ret_wb 
        = (((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__ebrk_insn)) 
            & ((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__ecall_insn_dec)) 
               & ((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__decoder_i__DOT__illegal_insn)) 
                  & ((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.illegal_csr_insn_o)) 
                     & ((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_fetch_err_o)) 
                        & (~ (((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.csr_access_o) 
                               & ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__VdfgTmp_hc09de8e0__0) 
                                  & ((0xb02U == (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                 >> 0x14U)) 
                                     | (0xb82U == (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                                                   >> 0x14U))))) 
                              | (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__VdfgTmp_h20a3cc49__0)))))))) 
           & ((~ (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_load_err) 
                   | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_store_err)) 
                  & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_resp_valid))) 
              & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.en_wb_o)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal 
        = ((~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_hold)) 
           & ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__instr_executing_spec) 
              & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__div_en_dec)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ctrl_update = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_d 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__data_req_out = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_d 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_q;
    if ((4U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
        if ((1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)))) {
                if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_valid_q) {
                    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d = 0U;
                    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update 
                        = (1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_err_q)));
                    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_d 
                        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_err_q;
                }
            }
        }
        if ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = 0U;
        } else if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = 0U;
        } else if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_valid_q) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = 0U;
        }
    } else if ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
        if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)))) {
            if (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_valid_q) 
                 | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q))) {
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d = 0U;
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_d 
                    = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_err_q) 
                       | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q));
            }
        }
        if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = 0U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update 
                = (1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_q)));
        } else if (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_valid_q) 
                    | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = 0U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update 
                = (1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_err_q) 
                            | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q))));
        } else {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = 4U;
        }
    } else {
        if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d = 0U;
            if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.lsu_req_o) {
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d = 0U;
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_d = 0U;
            }
        }
        if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = 2U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update = 1U;
        } else if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.lsu_req_o) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns 
                = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__split_misaligned_access)
                    ? 2U : 0U);
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update = 1U;
        }
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__perf_store = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__perf_load = 0U;
    if ((1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs) 
                  >> 2U)))) {
        if ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
            if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ctrl_update = 1U;
            }
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_d = 0U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__data_req_out = 1U;
        } else if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ctrl_update = 1U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_d = 1U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__data_req_out = 1U;
        } else if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.lsu_req_o) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ctrl_update = 1U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_d 
                = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__split_misaligned_access;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__data_req_out = 1U;
        }
        if ((1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)))) {
                if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.lsu_req_o) {
                    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__perf_store 
                        = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__lsu_we;
                    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__perf_load 
                        = (1U & (~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__lsu_we)));
                }
            }
        }
    }
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__174__a 
        = (0xfffffffcU & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_d);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__174__Vfuncout 
        = (0x100000U == (0xfffc0000U & __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__174__a));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__instr_hit 
        = __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__174__Vfuncout;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__177__a 
        = (0xfffffffcU & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_d);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__177__Vfuncout 
        = (0xffffU & (([&]() {
                    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__178__a 
                        = __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__177__a;
                    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__178__Vfuncout 
                        = (0x1f8000U == (0xffff8000U 
                                         & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__178__a));
                }(), (IData)(vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__178__Vfuncout))
                       ? (0xe000U | (0x1fffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__177__a 
                                                >> 2U)))
                       : (__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__177__a 
                          >> 2U)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__instr_idx 
        = __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__177__Vfuncout;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_we_ex 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
            ? (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal) 
                << 1U) | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_en_internal) 
                          | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal)))
            : 0U);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__ram_dreq 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__data_req_out) 
           & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__ram_data_hit));
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42___024root___nba_comb__TOP__4(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___nba_comb__TOP__4\n"); );
    // Body
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb 
        = (((- (IData)((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.rf_we_id_o))) 
            & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.rf_wdata_id_o) 
           | ((- (IData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_lsu))) 
              & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_rdata_ext));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_lsu) 
           | (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.rf_we_id_o));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffffffeU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | (IData)(((0U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                      & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffffffdU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x80U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 1U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffffffbU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x100U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 2U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffffff7U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x180U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 3U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffffffefU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x200U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 4U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffffffdfU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x280U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 5U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffffffbfU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x300U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 6U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffffff7fU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x380U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 7U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffffeffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x400U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 8U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffffdffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x480U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 9U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffffbffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x500U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0xaU));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffff7ffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x580U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0xbU));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffffefffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x600U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0xcU));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffffdfffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x680U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0xdU));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffffbfffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x700U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0xeU));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffff7fffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x780U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0xfU));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffeffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x800U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x10U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffdffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x880U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x11U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffbffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x900U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x12U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfff7ffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0x980U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x13U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffefffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xa00U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x14U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffdfffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xa80U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x15U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffbfffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xb00U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x16U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xff7fffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xb80U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x17U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfeffffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xc00U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x18U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfdffffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xc80U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x19U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfbffffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xd00U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x1aU));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xf7ffffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xd80U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x1bU));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xefffffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xe00U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x1cU));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xdfffffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xe80U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x1dU));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xbfffffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xf00U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x1eU));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0x7fffffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | ((IData)(((0xf80U == (0xf80U & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o)) 
                       & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb))) 
              << 0x1fU));
}

void Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__1(Vtb_rtnn_c2_soc_42___024root* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__0(Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__0(Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__0(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__1(Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__1(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf);
void Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__5(Vtb_rtnn_c2_soc_42___024root* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__2(Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* vlSelf);
void Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__7(Vtb_rtnn_c2_soc_42___024root* vlSelf);
void Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__8(Vtb_rtnn_c2_soc_42___024root* vlSelf);
void Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__9(Vtb_rtnn_c2_soc_42___024root* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__2(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__1(Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__3(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__3(Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__0(Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__0(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__4(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__1(Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__5(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__2(Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* vlSelf);

void Vtb_rtnn_c2_soc_42___024root___eval_nba(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___eval_nba\n"); );
    // Body
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x40ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__2(vlSelf);
        Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__0((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i));
        Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__0((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i));
        Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__0((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i));
        Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__3(vlSelf);
        Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__1((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i));
        Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__1((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i));
        Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((0x80ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__5(vlSelf);
    }
    if ((0x20ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__6(vlSelf);
        Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__2((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i));
    }
    if ((0x3c0ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_rtnn_c2_soc_42___024root___act_comb__TOP__0(vlSelf);
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__7(vlSelf);
    }
    if ((0x40ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__8(vlSelf);
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__9(vlSelf);
        Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__2((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i));
        Vtb_rtnn_c2_soc_42___024root___nba_sequent__TOP__10(vlSelf);
        Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__1((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i));
        Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__3((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i));
        Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__3((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i));
    }
    if ((0x30ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_rtnn_c2_soc_42___024root___nba_comb__TOP__1(vlSelf);
        Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__0((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i));
        Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__0((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i));
    }
    if ((0x11ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__0((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i));
        Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__0((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i));
    }
    if ((0x12ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__1((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i));
        Vtb_rtnn_c2_soc_42___024root___act_sequent__TOP__0(vlSelf);
        Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__2((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i));
    }
    if ((0x17ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__4((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i));
        Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__0((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i));
        Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__1((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i));
        Vtb_rtnn_c2_soc_42___024root___nba_comb__TOP__3(vlSelf);
        Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__1((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i));
    }
    if ((0x37ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__5((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i));
        Vtb_rtnn_c2_soc_42___024root___nba_comb__TOP__4(vlSelf);
        Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__2((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i));
    }
}
