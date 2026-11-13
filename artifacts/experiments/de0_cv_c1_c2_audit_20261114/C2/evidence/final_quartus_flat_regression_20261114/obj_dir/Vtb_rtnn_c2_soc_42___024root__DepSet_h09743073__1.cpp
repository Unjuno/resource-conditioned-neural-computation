// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rtnn_c2_soc_42.h for the primary calling header

#include "Vtb_rtnn_c2_soc_42__pch.h"
#include "Vtb_rtnn_c2_soc_42__Syms.h"
#include "Vtb_rtnn_c2_soc_42___024root.h"

extern const VlWide<12>/*383:0*/ Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0;

VlCoroutine Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__0__2(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__0__2\n"); );
    // Init
    VlWide<25>/*799:0*/ tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input;
    VL_ZERO_W(800, tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input);
    IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__Vfuncout;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__Vfuncout = 0;
    VlWide<11>/*351:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix;
    VL_ZERO_W(352, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix);
    IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c = 0;
    CData/*7:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by = 0;
    IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__Vfuncout;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__Vfuncout = 0;
    VlWide<7>/*223:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix;
    VL_ZERO_W(224, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix);
    IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c = 0;
    CData/*7:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by = 0;
    VlWide<25>/*799:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload;
    VL_ZERO_W(800, __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload);
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__expected_status;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__expected_status = 0;
    std::string __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__tag;
    IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__unnamedblk9__DOT__n;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__unnamedblk9__DOT__n = 0;
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__s;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__s = 0;
    VlWide<12>/*383:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got;
    VL_ZERO_W(384, __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got);
    CData/*0:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__done;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__done = 0;
    IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__88__unnamedblk8__DOT__n;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__88__unnamedblk8__DOT__n = 0;
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__88__s;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__88__s = 0;
    CData/*0:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__88__ready;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__88__ready = 0;
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__89__value;
    __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__89__value = 0;
    VlWide<25>/*799:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload;
    VL_ZERO_W(800, __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload);
    IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__unnamedblk2__DOT__b;
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__unnamedblk2__DOT__b = 0;
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__96__value;
    __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__96__value = 0;
    VlWide<12>/*383:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value;
    VL_ZERO_W(384, __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value);
    IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__unnamedblk3__DOT__b;
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__unnamedblk3__DOT__b = 0;
    IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__Vfuncout;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__Vfuncout = 0;
    VlWide<11>/*351:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix;
    VL_ZERO_W(352, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix);
    IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c = 0;
    CData/*7:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by = 0;
    CData/*7:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by = 0;
    // Body
    if (VL_UNLIKELY((vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__69__got[0xbU] 
                     != ([&]() {
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[0U] 
                            = vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__69__got[0U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[1U] 
                            = vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__69__got[1U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[2U] 
                            = vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__69__got[2U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[3U] 
                            = vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__69__got[3U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[4U] 
                            = vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__69__got[4U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[5U] 
                            = vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__69__got[5U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[6U] 
                            = vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__69__got[6U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[7U] 
                            = vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__69__got[7U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[8U] 
                            = vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__69__got[8U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[9U] 
                            = vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__69__got[9U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[0xaU] 
                            = vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__69__got[0xaU];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c = 0xffffffffU;
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[0U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[0U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[0U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[0U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[1U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[1U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[1U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[1U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[2U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[2U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[2U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[2U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[3U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[3U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[3U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[3U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[4U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[4U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[4U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[4U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[5U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[5U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[5U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[5U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[6U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[6U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[6U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[6U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[7U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[7U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[7U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[7U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[8U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[8U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[8U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[8U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[9U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[9U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[9U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[9U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[0xaU]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[0xaU] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[0xaU] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__prefix[0xaU] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__Vfuncout 
                            = (~ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__c);
                    }(), __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__85__Vfuncout)))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:196: Assertion failed in %Ntb_rtnn_c2_soc_42.expect_error_request: negative response CRC mismatch: %@\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  -1,&(vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__69__tag));
        VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 196, "");
    }
    if (VL_UNLIKELY(vlSelf->tb_rtnn_c2_soc_42__DOT__bus_fault)) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:197: Assertion failed in %Ntb_rtnn_c2_soc_42.expect_error_request: negative request caused SoC fault/halt: %@\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  -1,&(vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__69__tag));
        VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 197, "");
    }
    VL_WRITEF("C2_SOC_NEGATIVE_PASS tag=%@ response_status=%0#\n",
              -1,&(vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__69__tag),
              8,(0xffU & (vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__69__got[1U] 
                          >> 8U)));
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[1U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][1U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[2U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][2U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[3U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][3U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[4U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][4U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[5U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][5U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[6U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][6U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[7U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][7U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[8U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][8U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[9U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][9U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0xaU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0xaU];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0xbU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0xbU];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0xcU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0xcU];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0xdU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0xdU];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0xeU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0xeU];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0xfU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0xfU];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0x10U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x10U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0x11U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x11U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0x12U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x12U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0x13U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x13U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0x14U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x14U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0x15U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x15U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0x16U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x16U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0x17U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x17U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0x18U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x18U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[2U] = 0x3e9U;
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[3U] 
        = (0xffffU | (0xffff0000U & tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[3U]));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[0U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0U];
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[1U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[1U];
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[2U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[2U];
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[3U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[3U];
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[4U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[4U];
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[5U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[5U];
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[6U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[6U];
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c = 0xffffffffU;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[0U]);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[0U] 
                    >> 8U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[0U] 
                    >> 0x10U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[0U] 
           >> 0x18U);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[1U]);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[1U] 
                    >> 8U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[1U] 
                    >> 0x10U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[1U] 
           >> 0x18U);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[2U]);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[2U] 
                    >> 8U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[2U] 
                    >> 0x10U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[2U] 
           >> 0x18U);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[3U]);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[3U] 
                    >> 8U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[3U] 
                    >> 0x10U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[3U] 
           >> 0x18U);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[4U]);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[4U] 
                    >> 8U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[4U] 
                    >> 0x10U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[4U] 
           >> 0x18U);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[5U]);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[5U] 
                    >> 8U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[5U] 
                    >> 0x10U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[5U] 
           >> 0x18U);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[6U]);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[6U] 
                    >> 8U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[6U] 
                    >> 0x10U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__prefix[6U] 
           >> 0x18U);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__Vfuncout 
        = (~ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__c);
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[7U] 
        = __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__86__Vfuncout;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__tag = 
        std::string{"unknown_input_id"};
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__expected_status = 4U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[1U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[1U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[2U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[2U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[3U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[3U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[4U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[4U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[5U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[5U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[6U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[6U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[7U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[7U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[8U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[8U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[9U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[9U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0xaU] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0xaU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0xbU] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0xbU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0xcU] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0xcU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0xdU] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0xdU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0xeU] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0xeU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0xfU] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0xfU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0x10U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0x10U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0x11U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0x11U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0x12U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0x12U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0x13U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0x13U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0x14U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0x14U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0x15U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0x15U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0x16U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0x16U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0x17U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0x17U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0x18U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_input[0x18U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__88__ready = 0U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__88__unnamedblk8__DOT__n = 0U;
    {
        while (VL_GTS_III(32, 0x3e8U, __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__88__unnamedblk8__DOT__n)) {
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__89__value = 0U;
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
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__89__value 
                = ((0xfeU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__89__value)) 
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
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__89__value 
                = ((0xfdU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__89__value)) 
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
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__89__value 
                = ((0xfbU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__89__value)) 
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
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__89__value 
                = ((0xf7U & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__89__value)) 
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
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__89__value 
                = ((0xefU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__89__value)) 
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
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__89__value 
                = ((0xdfU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__89__value)) 
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
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__89__value 
                = ((0xbfU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__89__value)) 
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
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__89__value 
                = ((0x7fU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__89__value)) 
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
            __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__88__s 
                = __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__89__value;
            if ((8U & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__88__s))) {
                __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__88__ready = 1U;
                goto __Vlabel11;
            }
            __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__88__unnamedblk8__DOT__n 
                = ((IData)(1U) + __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__88__unnamedblk8__DOT__n);
        }
        __Vlabel11: ;
    }
    if (VL_UNLIKELY((1U & (~ (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__88__ready))))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:171: Assertion failed in %Ntb_rtnn_c2_soc_42.wait_for_ready: JTAG mailbox READY/ERROR timeout status=%02x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  8,(IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__88__s));
        VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 171, "");
    }
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[0U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[1U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[1U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[2U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[2U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[3U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[3U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[4U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[4U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[5U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[5U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[6U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[6U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[7U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[7U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[8U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[8U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[9U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[9U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[0xaU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0xaU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[0xbU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0xbU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[0xcU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0xcU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[0xdU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0xdU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[0xeU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0xeU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[0xfU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0xfU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[0x10U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0x10U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[0x11U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0x11U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[0x12U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0x12U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[0x13U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0x13U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[0x14U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0x14U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[0x15U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0x15U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[0x16U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0x16U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[0x17U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0x17U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[0x18U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__payload[0x18U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__ir = 1U;
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
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__unnamedblk2__DOT__b = 0U;
    while (VL_GTS_III(32, 0x320U, __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__unnamedblk2__DOT__b)) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__tdi = ((0x31fU 
                                                >= 
                                                (0x3ffU 
                                                 & __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__unnamedblk2__DOT__b)) 
                                               && (1U 
                                                   & (__Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__payload[
                                                      (0x1fU 
                                                       & (__Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__unnamedblk2__DOT__b 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__unnamedblk2__DOT__b))));
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
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__unnamedblk2__DOT__b 
            = ((IData)(1U) + __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__92__unnamedblk2__DOT__b);
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
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__done = 0U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__unnamedblk9__DOT__n = 0U;
    {
        while (VL_GTS_III(32, 0x186a0U, __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__unnamedblk9__DOT__n)) {
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__96__value = 0U;
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
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__96__value 
                = ((0xfeU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__96__value)) 
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
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__96__value 
                = ((0xfdU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__96__value)) 
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
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__96__value 
                = ((0xfbU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__96__value)) 
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
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__96__value 
                = ((0xf7U & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__96__value)) 
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
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__96__value 
                = ((0xefU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__96__value)) 
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
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__96__value 
                = ((0xdfU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__96__value)) 
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
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__96__value 
                = ((0xbfU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__96__value)) 
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
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__96__value 
                = ((0x7fU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__96__value)) 
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
            __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__s 
                = __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__96__value;
            if ((0x40U & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__s))) {
                __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__done = 1U;
                goto __Vlabel12;
            }
            __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__unnamedblk9__DOT__n 
                = ((IData)(1U) + __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__unnamedblk9__DOT__n);
        }
        __Vlabel12: ;
    }
    if (VL_UNLIKELY((1U & (~ (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__done))))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:187: Assertion failed in %Ntb_rtnn_c2_soc_42.expect_error_request: negative request completion timeout: %@ status=%02x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  -1,&(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__tag),
                  8,(IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__s));
        VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 187, "");
    }
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[0U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[1U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[1U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[2U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[2U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[3U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[3U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[4U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[4U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[5U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[5U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[6U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[6U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[7U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[7U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[8U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[8U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[9U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[9U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[0xaU] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0xaU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[0xbU] 
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
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__unnamedblk3__DOT__b = 0U;
    while (VL_GTS_III(32, 0x180U, __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__unnamedblk3__DOT__b)) {
        vlSelf->tb_rtnn_c2_soc_42__DOT____Vlvbound_hbf14d360__0 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__tdo;
        if (VL_LIKELY((0x17fU >= (0x1ffU & __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__unnamedblk3__DOT__b)))) {
            __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[(0xfU 
                                                                           & (__Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__unnamedblk3__DOT__b 
                                                                              >> 5U))] 
                = (((~ ((IData)(1U) << (0x1fU & __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__unnamedblk3__DOT__b))) 
                    & __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[
                    (0xfU & (__Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__unnamedblk3__DOT__b 
                             >> 5U))]) | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT____Vlvbound_hbf14d360__0) 
                                          << (0x1fU 
                                              & __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__unnamedblk3__DOT__b)));
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
        __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__unnamedblk3__DOT__b 
            = ((IData)(1U) + __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__unnamedblk3__DOT__b);
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
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[0U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[0U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[1U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[1U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[2U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[2U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[3U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[3U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[4U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[4U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[5U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[5U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[6U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[6U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[7U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[7U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[8U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[8U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[9U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[9U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[0xaU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[0xaU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[0xbU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__99__value[0xbU];
    if (VL_UNLIKELY(((0xffU & (__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[1U] 
                               >> 8U)) != (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__expected_status)))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:192: Assertion failed in %Ntb_rtnn_c2_soc_42.expect_error_request: negative response status %@ got=%0# expected=%0#\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  -1,&(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__tag),
                  8,(0xffU & (__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[1U] 
                              >> 8U)),8,(IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__expected_status));
        VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 192, "");
    }
    if (VL_UNLIKELY((0U != __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[6U]))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:194: Assertion failed in %Ntb_rtnn_c2_soc_42.expect_error_request: negative request returned nonzero inference cycles: %@\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  -1,&(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__tag));
        VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 194, "");
    }
    if (VL_UNLIKELY((__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[0xbU] 
                     != ([&]() {
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[0U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[0U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[1U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[1U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[2U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[2U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[3U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[3U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[4U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[4U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[5U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[5U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[6U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[6U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[7U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[7U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[8U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[8U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[9U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[9U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[0xaU] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[0xaU];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c = 0xffffffffU;
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[0U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[0U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[0U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[0U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[1U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[1U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[1U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[1U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[2U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[2U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[2U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[2U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[3U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[3U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[3U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[3U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[4U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[4U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[4U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[4U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[5U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[5U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[5U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[5U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[6U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[6U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[6U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[6U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[7U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[7U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[7U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[7U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[8U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[8U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[8U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[8U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[9U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[9U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[9U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[9U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[0xaU]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[0xaU] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[0xaU] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__prefix[0xaU] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__Vfuncout 
                            = (~ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__c);
                    }(), __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__103__Vfuncout)))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:196: Assertion failed in %Ntb_rtnn_c2_soc_42.expect_error_request: negative response CRC mismatch: %@\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  -1,&(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__tag));
        VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 196, "");
    }
    if (VL_UNLIKELY(vlSelf->tb_rtnn_c2_soc_42__DOT__bus_fault)) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42.sv:197: Assertion failed in %Ntb_rtnn_c2_soc_42.expect_error_request: negative request caused SoC fault/halt: %@\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  -1,&(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__tag));
        VL_STOP_MT("tb_rtnn_c2_soc_42.sv", 197, "");
    }
    VL_WRITEF("C2_SOC_NEGATIVE_PASS tag=%@ response_status=%0#\n",
              -1,&(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__tag),
              8,(0xffU & (__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__87__got[1U] 
                          >> 8U)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[1U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][1U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[2U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][2U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[3U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][3U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[4U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][4U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[5U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][5U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[6U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][6U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[7U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][7U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[8U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][8U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[9U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][9U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0xaU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0xaU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0xbU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0xbU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0xcU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0xcU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0xdU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0xdU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0xeU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0xeU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0xfU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0xfU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0x10U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x10U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0x11U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x11U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0x12U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x12U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0x13U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x13U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0x14U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x14U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0x15U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x15U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0x16U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x16U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0x17U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x17U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0x18U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x18U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[2U] = 0x3eaU;
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[5U] = 0xdeadbeefU;
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[0U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0U];
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[1U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[1U];
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[2U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[2U];
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[3U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[3U];
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[4U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[4U];
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[5U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[5U];
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[6U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[6U];
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c = 0xffffffffU;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (0xffU & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[0U]);
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (0xffU & (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[0U] 
                    >> 8U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (0xffU & (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[0U] 
                    >> 0x10U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[0U] 
           >> 0x18U);
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (0xffU & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[1U]);
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (0xffU & (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[1U] 
                    >> 8U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (0xffU & (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[1U] 
                    >> 0x10U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[1U] 
           >> 0x18U);
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (0xffU & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[2U]);
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (0xffU & (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[2U] 
                    >> 8U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (0xffU & (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[2U] 
                    >> 0x10U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[2U] 
           >> 0x18U);
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (0xffU & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[3U]);
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (0xffU & (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[3U] 
                    >> 8U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (0xffU & (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[3U] 
                    >> 0x10U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[3U] 
           >> 0x18U);
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (0xffU & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[4U]);
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (0xffU & (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[4U] 
                    >> 8U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (0xffU & (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[4U] 
                    >> 0x10U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[4U] 
           >> 0x18U);
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (0xffU & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[5U]);
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (0xffU & (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[5U] 
                    >> 8U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (0xffU & (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[5U] 
                    >> 0x10U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[5U] 
           >> 0x18U);
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (0xffU & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[6U]);
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (0xffU & (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[6U] 
                    >> 8U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = ((1U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U))
            : VL_SHIFTR_III(32,32,32, vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (0xffU & (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[6U] 
                    >> 0x10U));
    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by));
}
