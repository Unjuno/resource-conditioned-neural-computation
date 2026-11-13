// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rtnn_c2_soc_42.h for the primary calling header

#include "Vtb_rtnn_c2_soc_42__pch.h"
#include "Vtb_rtnn_c2_soc_42___024root.h"

VL_ATTR_COLD void Vtb_rtnn_c2_soc_42___024root___eval_static__TOP(Vtb_rtnn_c2_soc_42___024root* vlSelf);

VL_ATTR_COLD void Vtb_rtnn_c2_soc_42___024root___eval_static(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___eval_static\n"); );
    // Body
    Vtb_rtnn_c2_soc_42___024root___eval_static__TOP(vlSelf);
}

extern const VlWide<25>/*799:0*/ Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0;
extern const VlWide<12>/*383:0*/ Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0;

VL_ATTR_COLD void Vtb_rtnn_c2_soc_42___024root___eval_static__TOP(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->tb_rtnn_c2_soc_42__DOT__clk = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__tck = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__rst_n = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__trst_n = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__tdi = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__update_dr = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__ir = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__case_limit = 0x2aU;
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_toggle_guard = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_guard_active = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[1U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[1U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[2U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[2U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[3U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[3U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[4U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[4U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[5U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[5U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[6U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[6U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[7U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[7U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[8U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[8U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[9U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[9U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xaU] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xaU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xbU] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xbU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xcU] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xcU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xdU] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xdU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xeU] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xeU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0xfU] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xfU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x10U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x10U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x11U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x11U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x12U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x12U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x13U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x13U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x14U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x14U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x15U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x15U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x16U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x16U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x17U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x17U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard[0x18U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x18U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard_active = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard_active = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_pending_seen = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[1U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[1U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[2U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[2U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[3U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[3U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[4U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[4U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[5U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[5U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[6U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[6U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[7U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[7U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[8U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[8U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[9U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[9U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0xaU] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0xaU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard[0xbU] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0xbU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[1U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[1U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[2U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[2U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[3U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[3U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[4U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[4U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[5U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[5U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[6U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[6U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[7U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[7U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[8U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[8U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[9U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[9U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0xaU] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0xaU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard[0xbU] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0xbU];
}

VL_ATTR_COLD void Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_1;
    VlWide<5>/*159:0*/ __Vtemp_2;
    VlWide<5>/*159:0*/ __Vtemp_3;
    VlWide<5>/*159:0*/ __Vtemp_4;
    // Body
    __Vtemp_1[0U] = 0x2e686578U;
    __Vtemp_1[1U] = 0x616e6530U;
    __Vtemp_1[2U] = 0x616d5f6cU;
    __Vtemp_1[3U] = 0x6e6e5f72U;
    __Vtemp_1[4U] = 0x7274U;
    VL_READMEM_N(true, 8, 65536, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_1)
                 ,  &(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem0)
                 , 0, ~0ULL);
    __Vtemp_2[0U] = 0x2e686578U;
    __Vtemp_2[1U] = 0x616e6531U;
    __Vtemp_2[2U] = 0x616d5f6cU;
    __Vtemp_2[3U] = 0x6e6e5f72U;
    __Vtemp_2[4U] = 0x7274U;
    VL_READMEM_N(true, 8, 65536, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_2)
                 ,  &(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem1)
                 , 0, ~0ULL);
    __Vtemp_3[0U] = 0x2e686578U;
    __Vtemp_3[1U] = 0x616e6532U;
    __Vtemp_3[2U] = 0x616d5f6cU;
    __Vtemp_3[3U] = 0x6e6e5f72U;
    __Vtemp_3[4U] = 0x7274U;
    VL_READMEM_N(true, 8, 65536, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_3)
                 ,  &(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem2)
                 , 0, ~0ULL);
    __Vtemp_4[0U] = 0x2e686578U;
    __Vtemp_4[1U] = 0x616e6533U;
    __Vtemp_4[2U] = 0x616d5f6cU;
    __Vtemp_4[3U] = 0x6e6e5f72U;
    __Vtemp_4[4U] = 0x7274U;
    VL_READMEM_N(true, 8, 65536, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_4)
                 ,  &(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem3)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vtb_rtnn_c2_soc_42___024root___eval_final(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rtnn_c2_soc_42___024root___dump_triggers__stl(Vtb_rtnn_c2_soc_42___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_rtnn_c2_soc_42___024root___eval_phase__stl(Vtb_rtnn_c2_soc_42___024root* vlSelf);

VL_ATTR_COLD void Vtb_rtnn_c2_soc_42___024root___eval_settle(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtb_rtnn_c2_soc_42___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb_rtnn_c2_soc_42_capture_edge.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_rtnn_c2_soc_42___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rtnn_c2_soc_42___024root___dump_triggers__stl(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
    if ((2ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 1 is active: @([hybrid] tb_rtnn_c2_soc_42.u_soc.u_ibex.u_ibex_core.id_stage_i.en_wb_o or [hybrid] tb_rtnn_c2_soc_42.u_soc.u_ibex.u_ibex_core.id_stage_i.instr_executing_spec)\n");
    }
    if ((4ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 2 is active: @([hybrid] tb_rtnn_c2_soc_42.u_soc.u_ibex.u_ibex_core.id_stage_i.instr_executing_spec)\n");
    }
    if ((8ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 3 is active: @([hybrid] tb_rtnn_c2_soc_42.u_soc.u_ibex.u_ibex_core.id_stage_i.id_in_ready_o)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_rtnn_c2_soc_42___024root___eval_triggers__stl(Vtb_rtnn_c2_soc_42___024root* vlSelf);
VL_ATTR_COLD void Vtb_rtnn_c2_soc_42___024root___eval_stl(Vtb_rtnn_c2_soc_42___024root* vlSelf);

VL_ATTR_COLD bool Vtb_rtnn_c2_soc_42___024root___eval_phase__stl(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_rtnn_c2_soc_42___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_rtnn_c2_soc_42___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rtnn_c2_soc_42___024root___dump_triggers__act(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([hybrid] tb_rtnn_c2_soc_42.u_soc.u_ibex.u_ibex_core.id_stage_i.en_wb_o or [hybrid] tb_rtnn_c2_soc_42.u_soc.u_ibex.u_ibex_core.id_stage_i.instr_executing_spec)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([hybrid] tb_rtnn_c2_soc_42.u_soc.u_ibex.u_ibex_core.id_stage_i.instr_executing_spec)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([hybrid] tb_rtnn_c2_soc_42.u_soc.u_ibex.u_ibex_core.id_stage_i.id_in_ready_o)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(posedge tb_rtnn_c2_soc_42.tck or negedge tb_rtnn_c2_soc_42.trst_n)\n");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @(posedge tb_rtnn_c2_soc_42.clk or negedge tb_rtnn_c2_soc_42.rst_n)\n");
    }
    if ((0x20ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @(posedge tb_rtnn_c2_soc_42.clk)\n");
    }
    if ((0x40ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 6 is active: @(posedge tb_rtnn_c2_soc_42.tck or negedge tb_rtnn_c2_soc_42.u_mailbox.tck_reset_released)\n");
    }
    if ((0x80ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 7 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((0x100ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 8 is active: @(negedge tb_rtnn_c2_soc_42.clk)\n");
    }
    if ((0x200ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 9 is active: @(posedge tb_rtnn_c2_soc_42.tck)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rtnn_c2_soc_42___024root___dump_triggers__nba(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([hybrid] tb_rtnn_c2_soc_42.u_soc.u_ibex.u_ibex_core.id_stage_i.en_wb_o or [hybrid] tb_rtnn_c2_soc_42.u_soc.u_ibex.u_ibex_core.id_stage_i.instr_executing_spec)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([hybrid] tb_rtnn_c2_soc_42.u_soc.u_ibex.u_ibex_core.id_stage_i.instr_executing_spec)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([hybrid] tb_rtnn_c2_soc_42.u_soc.u_ibex.u_ibex_core.id_stage_i.id_in_ready_o)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(posedge tb_rtnn_c2_soc_42.tck or negedge tb_rtnn_c2_soc_42.trst_n)\n");
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @(posedge tb_rtnn_c2_soc_42.clk or negedge tb_rtnn_c2_soc_42.rst_n)\n");
    }
    if ((0x20ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @(posedge tb_rtnn_c2_soc_42.clk)\n");
    }
    if ((0x40ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 6 is active: @(posedge tb_rtnn_c2_soc_42.tck or negedge tb_rtnn_c2_soc_42.u_mailbox.tck_reset_released)\n");
    }
    if ((0x80ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 7 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((0x100ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 8 is active: @(negedge tb_rtnn_c2_soc_42.clk)\n");
    }
    if ((0x200ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 9 is active: @(posedge tb_rtnn_c2_soc_42.tck)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_rtnn_c2_soc_42___024root___ctor_var_reset(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_rtnn_c2_soc_42__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__tck = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__trst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__tdi = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__update_dr = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__ir = VL_RAND_RESET_I(3);
    vlSelf->tb_rtnn_c2_soc_42__DOT__tdo = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__request_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__request_accept = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_commit = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(800, vlSelf->tb_rtnn_c2_soc_42__DOT__request_data);
    for (int __Vi0 = 0; __Vi0 < 42; ++__Vi0) {
        VL_RAND_RESET_W(800, vlSelf->tb_rtnn_c2_soc_42__DOT__requests[__Vi0]);
    }
    VL_RAND_RESET_W(384, vlSelf->tb_rtnn_c2_soc_42__DOT__response_data);
    for (int __Vi0 = 0; __Vi0 < 42; ++__Vi0) {
        VL_RAND_RESET_W(288, vlSelf->tb_rtnn_c2_soc_42__DOT__expected[__Vi0]);
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__bus_fault = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__case_limit = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_toggle_guard = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__req_guard_active = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(800, vlSelf->tb_rtnn_c2_soc_42__DOT__req_hold_guard);
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard_active = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard_active = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_pending_seen = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(384, vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_sys_guard);
    VL_RAND_RESET_W(384, vlSelf->tb_rtnn_c2_soc_42__DOT__rsp_tck_guard);
    VL_RAND_RESET_W(800, vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model);
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk12__DOT__s = VL_RAND_RESET_I(8);
    vlSelf->tb_rtnn_c2_soc_42__DOT____Vlvbound_hbf14d360__0 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(800, vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q);
    VL_RAND_RESET_W(800, vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q);
    VL_RAND_RESET_W(384, vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q);
    VL_RAND_RESET_W(384, vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_capture_pending_sys_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_capture_pending_tck_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__build_shift_tck_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__status_shift_tck_q = VL_RAND_RESET_I(8);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_count_tck_q = VL_RAND_RESET_I(11);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_release_q = VL_RAND_RESET_I(2);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_released = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_toggle_tck_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_sync1_sys_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_sync2_sys_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_seen_sys_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_ack_toggle_sys_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_ack_sync1_tck_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_ack_sync2_tck_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_toggle_sys_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_sync1_tck_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_sync2_tck_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_seen_tck_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_consume_toggle_tck_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_consume_sync1_sys_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_consume_sync2_sys_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__busy_sys_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__error_sys_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sys_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__busy_sync1_tck_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__busy_sync2_tck_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__error_sync1_tck_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__error_sync2_tck_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sync1_tck_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sync2_tck_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__pending_tck_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__response_pending_tck_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__protocol_error_tck_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_count_tck_q = VL_RAND_RESET_I(11);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__instr_hit = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__instr_err_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_err_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__ram_data_hit = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__ram_instr_rvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_access_err = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__mmio_read_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__mmio_write_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__ram_dreq = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_ram_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_valid_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__mmio_read_data_q = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 12; ++__Vi0) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_byte_written_q = VL_RAND_RESET_Q(48);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_commit_match = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vlvbound_hd6210828__0 = VL_RAND_RESET_I(8);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vlvbound_h11b922a8__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem0[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem1[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem2[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem3[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__data_idx = VL_RAND_RESET_I(16);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__instr_idx = VL_RAND_RESET_I(16);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__data_ram_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__instr_ram_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__data_hit_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__instr_hit_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core = VL_RAND_RESET_Q(39);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core = VL_RAND_RESET_Q(39);
    VL_RAND_RESET_W(68, vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_d_ex);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_we_ex = VL_RAND_RESET_I(2);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_load_err = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_store_err = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_addr_incr_req = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_a = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_lsu = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_resp_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__data_req_out = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__perf_instr_ret_wb = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__perf_load = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__perf_store = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_result = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b = VL_RAND_RESET_Q(33);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a = VL_RAND_RESET_Q(33);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext = VL_RAND_RESET_Q(34);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift1 = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift2 = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift3 = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_b_negate = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_signed = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_left = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d = VL_RAND_RESET_Q(34);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_d = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_d = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_remainder = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_quotient = VL_RAND_RESET_Q(33);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_q = VL_RAND_RESET_I(5);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_d = VL_RAND_RESET_I(5);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_hold = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_hold = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_d = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_en_internal = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q = VL_RAND_RESET_I(3);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_d = VL_RAND_RESET_I(3);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_d = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult1_res_uns = VL_RAND_RESET_Q(34);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_op_a = VL_RAND_RESET_I(16);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_op_b = VL_RAND_RESET_I(16);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand1_ext = VL_RAND_RESET_Q(35);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_last_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ctrl_update = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_update = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q = VL_RAND_RESET_I(24);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q = VL_RAND_RESET_I(2);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_type_q = VL_RAND_RESET_I(2);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_be = VL_RAND_RESET_I(4);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_rdata_ext = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__split_misaligned_access = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_d = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_q = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_d = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_or_pmp_err = VL_RAND_RESET_I(1);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs = VL_RAND_RESET_I(3);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = VL_RAND_RESET_I(3);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__ecc_err = VL_RAND_RESET_I(2);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf = VL_RAND_RESET_Q(39);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT____VdfgTmp_h3fd48639__0 = 0;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o = VL_RAND_RESET_I(7);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__1__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__2__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__3__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__4__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__5__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__6__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__7__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__8__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__9__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__10__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__11__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__12__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__13__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__14__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__15__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__16__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__17__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__18__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__19__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__20__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__21__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__22__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__23__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__24__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__25__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__26__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__27__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__28__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__29__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__30__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__31__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_dummy_r0__DOT__rf_r0_q = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(384, vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__34__got);
    VL_RAND_RESET_W(384, vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__69__got);
    VL_RAND_RESET_W(224, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix);
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c = VL_RAND_RESET_I(32);
    vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index = VL_RAND_RESET_I(32);
    vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__unnamedblk10__DOT__n = 0;
    vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__done = VL_RAND_RESET_I(1);
    vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__seq = VL_RAND_RESET_I(32);
    vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__mode = VL_RAND_RESET_I(32);
    vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__iid = VL_RAND_RESET_I(32);
    vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__admit = VL_RAND_RESET_I(32);
    vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__exec_exit = VL_RAND_RESET_I(32);
    vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__pred = VL_RAND_RESET_I(32);
    vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__label = VL_RAND_RESET_I(32);
    vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__budget = VL_RAND_RESET_I(16);
    vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__stop = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__172__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__172__a = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__173__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__173__a = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__176__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__176__a = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__178__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__178__a = VL_RAND_RESET_I(32);
    vlSelf->__Vdlyvval__tb_rtnn_c2_soc_42__DOT__tck__v0 = VL_RAND_RESET_I(1);
    vlSelf->__Vdlyvset__tb_rtnn_c2_soc_42__DOT__tck__v0 = 0;
    vlSelf->__Vdlyvval__tb_rtnn_c2_soc_42__DOT__clk__v0 = VL_RAND_RESET_I(1);
    vlSelf->__Vdlyvset__tb_rtnn_c2_soc_42__DOT__clk__v0 = 0;
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__response_pending_tck_q = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_toggle_tck_q = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(800, vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q);
    vlSelf->__Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_consume_toggle_tck_q = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__en_wb_o__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i____PVT__instr_executing_spec__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__id_in_ready_o__0 = VL_RAND_RESET_I(1);
    vlSelf->__VstlDidInit = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__en_wb_o__1 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i____PVT__instr_executing_spec__1 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__id_in_ready_o__1 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__tck__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__trst_n__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__rst_n__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_released__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
}
