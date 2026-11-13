// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rtnn_c2_soc_42.h for the primary calling header

#include "Vtb_rtnn_c2_soc_42__pch.h"
#include "Vtb_rtnn_c2_soc_42__Syms.h"
#include "Vtb_rtnn_c2_soc_42___024root.h"

extern const VlWide<12>/*383:0*/ Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0;
extern const VlWide<9>/*287:0*/ Vtb_rtnn_c2_soc_42__ConstPool__CONST_h9a2fc1c8_0;
extern const VlWide<25>/*799:0*/ Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0;

VlCoroutine Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__0__3(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___eval_initial__TOP__Vtiming__0__3\n"); );
    // Init
    VlWide<25>/*799:0*/ tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build;
    VL_ZERO_W(800, tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build);
    CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__unnamedblk12__DOT__observed_busy;
    tb_rtnn_c2_soc_42__DOT__unnamedblk12__DOT__observed_busy = 0;
    IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__unnamedblk12__DOT__unnamedblk13__DOT__n;
    tb_rtnn_c2_soc_42__DOT__unnamedblk12__DOT__unnamedblk13__DOT__n = 0;
    IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__Vfuncout;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by = 0;
    VlWide<25>/*799:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload;
    VL_ZERO_W(800, __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload);
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__expected_status;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__expected_status = 0;
    std::string __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__tag;
    IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__unnamedblk9__DOT__n;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__unnamedblk9__DOT__n = 0;
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__s;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__s = 0;
    VlWide<12>/*383:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got;
    VL_ZERO_W(384, __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got);
    CData/*0:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__done;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__done = 0;
    IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__106__unnamedblk8__DOT__n;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__106__unnamedblk8__DOT__n = 0;
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__106__s;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__106__s = 0;
    CData/*0:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__106__ready;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__106__ready = 0;
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__107__value;
    __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__107__value = 0;
    VlWide<25>/*799:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload;
    VL_ZERO_W(800, __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload);
    IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__unnamedblk2__DOT__b;
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__unnamedblk2__DOT__b = 0;
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__114__value;
    __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__114__value = 0;
    VlWide<12>/*383:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value;
    VL_ZERO_W(384, __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value);
    IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__unnamedblk3__DOT__b;
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__unnamedblk3__DOT__b = 0;
    IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__Vfuncout;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__Vfuncout = 0;
    VlWide<11>/*351:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix;
    VL_ZERO_W(352, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix);
    IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c = 0;
    CData/*7:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by = 0;
    IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__Vfuncout;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__Vfuncout = 0;
    VlWide<7>/*223:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix;
    VL_ZERO_W(224, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix);
    IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c = 0;
    CData/*7:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by = 0;
    VlWide<25>/*799:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload;
    VL_ZERO_W(800, __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload);
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__expected_status;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__expected_status = 0;
    std::string __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__tag;
    IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__unnamedblk9__DOT__n;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__unnamedblk9__DOT__n = 0;
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__s;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__s = 0;
    VlWide<12>/*383:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got;
    VL_ZERO_W(384, __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got);
    CData/*0:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__done;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__done = 0;
    IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__124__unnamedblk8__DOT__n;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__124__unnamedblk8__DOT__n = 0;
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__124__s;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__124__s = 0;
    CData/*0:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__124__ready;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__124__ready = 0;
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__125__value;
    __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__125__value = 0;
    VlWide<25>/*799:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload;
    VL_ZERO_W(800, __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload);
    IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__unnamedblk2__DOT__b;
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__unnamedblk2__DOT__b = 0;
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__132__value;
    __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__132__value = 0;
    VlWide<12>/*383:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value;
    VL_ZERO_W(384, __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value);
    IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__unnamedblk3__DOT__b;
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__unnamedblk3__DOT__b = 0;
    IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__Vfuncout;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__Vfuncout = 0;
    VlWide<11>/*351:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix;
    VL_ZERO_W(352, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix);
    IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c = 0;
    CData/*7:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by = 0;
    IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__140__unnamedblk8__DOT__n;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__140__unnamedblk8__DOT__n = 0;
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__140__s;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__140__s = 0;
    CData/*0:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__140__ready;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__140__ready = 0;
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__141__value;
    __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__141__value = 0;
    VlWide<25>/*799:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload;
    VL_ZERO_W(800, __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload);
    IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__unnamedblk2__DOT__b;
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__unnamedblk2__DOT__b = 0;
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__148__value;
    __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__148__value = 0;
    IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__151__unnamedblk8__DOT__n;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__151__unnamedblk8__DOT__n = 0;
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__151__s;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__151__s = 0;
    CData/*0:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__151__ready;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__151__ready = 0;
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__152__value;
    __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__152__value = 0;
    IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__156__unnamedblk8__DOT__n;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__156__unnamedblk8__DOT__n = 0;
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__156__s;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__156__s = 0;
    CData/*0:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__156__ready;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__156__ready = 0;
    CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__157__value;
    __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__157__value = 0;
    VlWide<25>/*799:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload;
    VL_ZERO_W(800, __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload);
    IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__unnamedblk2__DOT__b;
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__unnamedblk2__DOT__b = 0;
    // Body
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__by 
        = (vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix[6U] 
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
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__Vfuncout 
        = (~ vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c);
    vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[7U] 
        = __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__Vfuncout;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__tag = 
        std::string{"unknown_model_id"};
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__expected_status = 3U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[1U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[1U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[2U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[2U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[3U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[3U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[4U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[4U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[5U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[5U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[6U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[6U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[7U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[7U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[8U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[8U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[9U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[9U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0xaU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0xaU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0xbU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0xbU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0xcU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0xcU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0xdU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0xdU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0xeU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0xeU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0xfU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0xfU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0x10U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0x10U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0x11U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0x11U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0x12U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0x12U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0x13U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0x13U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0x14U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0x14U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0x15U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0x15U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0x16U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0x16U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0x17U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0x17U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0x18U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model[0x18U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__106__ready = 0U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__106__unnamedblk8__DOT__n = 0U;
    {
        while (VL_GTS_III(32, 0x3e8U, __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__106__unnamedblk8__DOT__n)) {
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__107__value = 0U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__ir = 3U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__107__value 
                = ((0xfeU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__107__value)) 
                   | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__107__value 
                = ((0xfdU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__107__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 1U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__107__value 
                = ((0xfbU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__107__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 2U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__107__value 
                = ((0xf7U & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__107__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 3U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__107__value 
                = ((0xefU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__107__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 4U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__107__value 
                = ((0xdfU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__107__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 5U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__107__value 
                = ((0xbfU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__107__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 6U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__107__value 
                = ((0x7fU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__107__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 7U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__106__s 
                = __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__107__value;
            if ((8U & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__106__s))) {
                __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__106__ready = 1U;
                goto __Vlabel13;
            }
            __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__106__unnamedblk8__DOT__n 
                = ((IData)(1U) + __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__106__unnamedblk8__DOT__n);
        }
        __Vlabel13: ;
    }
    if (VL_UNLIKELY((1U & (~ (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__106__ready))))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42_capture_edge.sv:171: Assertion failed in %Ntb_rtnn_c2_soc_42.wait_for_ready: JTAG mailbox READY/ERROR timeout status=%02x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  8,(IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__106__s));
        VL_STOP_MT("tb_rtnn_c2_soc_42_capture_edge.sv", 171, "");
    }
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[0U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[1U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[1U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[2U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[2U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[3U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[3U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[4U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[4U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[5U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[5U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[6U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[6U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[7U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[7U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[8U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[8U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[9U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[9U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[0xaU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0xaU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[0xbU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0xbU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[0xcU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0xcU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[0xdU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0xdU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[0xeU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0xeU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[0xfU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0xfU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[0x10U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0x10U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[0x11U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0x11U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[0x12U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0x12U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[0x13U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0x13U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[0x14U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0x14U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[0x15U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0x15U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[0x16U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0x16U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[0x17U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0x17U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[0x18U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__payload[0x18U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__ir = 1U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 1U;
    co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                       118);
    co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                       118);
    vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 0U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__unnamedblk2__DOT__b = 0U;
    while (VL_GTS_III(32, 0x320U, __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__unnamedblk2__DOT__b)) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__tdi = ((0x31fU 
                                                >= 
                                                (0x3ffU 
                                                 & __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__unnamedblk2__DOT__b)) 
                                               && (1U 
                                                   & (__Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__payload[
                                                      (0x1fU 
                                                       & (__Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__unnamedblk2__DOT__b 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__unnamedblk2__DOT__b))));
        vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
        co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                           "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                           118);
        co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                           "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                           118);
        vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__unnamedblk2__DOT__b 
            = ((IData)(1U) + __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__110__unnamedblk2__DOT__b);
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__update_dr = 1U;
    co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                       118);
    co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                       118);
    vlSelf->tb_rtnn_c2_soc_42__DOT__update_dr = 0U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__done = 0U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__unnamedblk9__DOT__n = 0U;
    {
        while (VL_GTS_III(32, 0x186a0U, __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__unnamedblk9__DOT__n)) {
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__114__value = 0U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__ir = 3U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__114__value 
                = ((0xfeU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__114__value)) 
                   | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__114__value 
                = ((0xfdU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__114__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 1U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__114__value 
                = ((0xfbU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__114__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 2U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__114__value 
                = ((0xf7U & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__114__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 3U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__114__value 
                = ((0xefU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__114__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 4U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__114__value 
                = ((0xdfU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__114__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 5U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__114__value 
                = ((0xbfU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__114__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 6U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__114__value 
                = ((0x7fU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__114__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 7U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__s 
                = __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__114__value;
            if ((0x40U & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__s))) {
                __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__done = 1U;
                goto __Vlabel14;
            }
            __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__unnamedblk9__DOT__n 
                = ((IData)(1U) + __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__unnamedblk9__DOT__n);
        }
        __Vlabel14: ;
    }
    if (VL_UNLIKELY((1U & (~ (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__done))))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42_capture_edge.sv:187: Assertion failed in %Ntb_rtnn_c2_soc_42.expect_error_request: negative request completion timeout: %@ status=%02x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  -1,&(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__tag),
                  8,(IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__s));
        VL_STOP_MT("tb_rtnn_c2_soc_42_capture_edge.sv", 187, "");
    }
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[0U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[1U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[1U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[2U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[2U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[3U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[3U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[4U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[4U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[5U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[5U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[6U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[6U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[7U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[7U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[8U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[8U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[9U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[9U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[0xaU] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0xaU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[0xbU] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0xbU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__ir = 2U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 1U;
    co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                       118);
    co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                       118);
    vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 0U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__unnamedblk3__DOT__b = 0U;
    while (VL_GTS_III(32, 0x180U, __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__unnamedblk3__DOT__b)) {
        vlSelf->tb_rtnn_c2_soc_42__DOT____Vlvbound_hbf14d360__0 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__tdo;
        if (VL_LIKELY((0x17fU >= (0x1ffU & __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__unnamedblk3__DOT__b)))) {
            __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[(0xfU 
                                                                            & (__Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__unnamedblk3__DOT__b 
                                                                               >> 5U))] 
                = (((~ ((IData)(1U) << (0x1fU & __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__unnamedblk3__DOT__b))) 
                    & __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[
                    (0xfU & (__Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__unnamedblk3__DOT__b 
                             >> 5U))]) | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT____Vlvbound_hbf14d360__0) 
                                          << (0x1fU 
                                              & __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__unnamedblk3__DOT__b)));
        }
        vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
        co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                           "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                           118);
        co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                           "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                           118);
        vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
        __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__unnamedblk3__DOT__b 
            = ((IData)(1U) + __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__unnamedblk3__DOT__b);
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__update_dr = 1U;
    co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                       118);
    co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                       118);
    vlSelf->tb_rtnn_c2_soc_42__DOT__update_dr = 0U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[0U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[0U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[1U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[1U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[2U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[2U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[3U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[3U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[4U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[4U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[5U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[5U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[6U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[6U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[7U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[7U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[8U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[8U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[9U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[9U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[0xaU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[0xaU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[0xbU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__117__value[0xbU];
    if (VL_UNLIKELY(((0xffU & (__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[1U] 
                               >> 8U)) != (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__expected_status)))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42_capture_edge.sv:192: Assertion failed in %Ntb_rtnn_c2_soc_42.expect_error_request: negative response status %@ got=%0# expected=%0#\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  -1,&(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__tag),
                  8,(0xffU & (__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[1U] 
                              >> 8U)),8,(IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__expected_status));
        VL_STOP_MT("tb_rtnn_c2_soc_42_capture_edge.sv", 192, "");
    }
    if (VL_UNLIKELY((0U != __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[6U]))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42_capture_edge.sv:194: Assertion failed in %Ntb_rtnn_c2_soc_42.expect_error_request: negative request returned nonzero inference cycles: %@\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  -1,&(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__tag));
        VL_STOP_MT("tb_rtnn_c2_soc_42_capture_edge.sv", 194, "");
    }
    if (VL_UNLIKELY((__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[0xbU] 
                     != ([&]() {
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[0U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[0U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[1U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[1U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[2U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[2U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[3U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[3U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[4U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[4U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[5U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[5U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[6U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[6U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[7U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[7U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[8U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[8U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[9U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[9U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[0xaU] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[0xaU];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c = 0xffffffffU;
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[0U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[0U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[0U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[0U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[1U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[1U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[1U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[1U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[2U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[2U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[2U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[2U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[3U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[3U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[3U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[3U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[4U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[4U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[4U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[4U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[5U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[5U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[5U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[5U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[6U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[6U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[6U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[6U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[7U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[7U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[7U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[7U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[8U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[8U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[8U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[8U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[9U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[9U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[9U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[9U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[0xaU]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[0xaU] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[0xaU] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__prefix[0xaU] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__Vfuncout 
                            = (~ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__c);
                    }(), __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__121__Vfuncout)))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42_capture_edge.sv:196: Assertion failed in %Ntb_rtnn_c2_soc_42.expect_error_request: negative response CRC mismatch: %@\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  -1,&(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__tag));
        VL_STOP_MT("tb_rtnn_c2_soc_42_capture_edge.sv", 196, "");
    }
    if (VL_UNLIKELY(vlSelf->tb_rtnn_c2_soc_42__DOT__bus_fault)) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42_capture_edge.sv:197: Assertion failed in %Ntb_rtnn_c2_soc_42.expect_error_request: negative request caused SoC fault/halt: %@\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  -1,&(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__tag));
        VL_STOP_MT("tb_rtnn_c2_soc_42_capture_edge.sv", 197, "");
    }
    VL_WRITEF("C2_SOC_NEGATIVE_PASS tag=%@ response_status=%0#\n",
              -1,&(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__tag),
              8,(0xffU & (__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__105__got[1U] 
                          >> 8U)));
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[1U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][1U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[2U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][2U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[3U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][3U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[4U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][4U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[5U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][5U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[6U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][6U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[7U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][7U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[8U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][8U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[9U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][9U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0xaU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0xaU];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0xbU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0xbU];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0xcU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0xcU];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0xdU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0xdU];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0xeU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0xeU];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0xfU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0xfU];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0x10U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x10U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0x11U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x11U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0x12U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x12U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0x13U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x13U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0x14U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x14U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0x15U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x15U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0x16U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x16U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0x17U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x17U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0x18U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[1U][0x18U];
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[2U] = 0x3ebU;
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[6U] = 0xdeadbeefU;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[0U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0U];
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[1U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[1U];
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[2U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[2U];
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[3U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[3U];
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[4U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[4U];
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[5U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[5U];
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[6U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[6U];
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c = 0xffffffffU;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[0U]);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[0U] 
                    >> 8U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[0U] 
                    >> 0x10U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[0U] 
           >> 0x18U);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[1U]);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[1U] 
                    >> 8U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[1U] 
                    >> 0x10U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[1U] 
           >> 0x18U);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[2U]);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[2U] 
                    >> 8U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[2U] 
                    >> 0x10U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[2U] 
           >> 0x18U);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[3U]);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[3U] 
                    >> 8U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[3U] 
                    >> 0x10U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[3U] 
           >> 0x18U);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[4U]);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[4U] 
                    >> 8U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[4U] 
                    >> 0x10U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[4U] 
           >> 0x18U);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[5U]);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[5U] 
                    >> 8U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[5U] 
                    >> 0x10U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[5U] 
           >> 0x18U);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[6U]);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[6U] 
                    >> 8U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[6U] 
                    >> 0x10U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__prefix[6U] 
           >> 0x18U);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
           ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__by));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c 
        = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c)
            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U))
            : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c, 1U));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__Vfuncout 
        = (~ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__c);
    tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[7U] 
        = __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__122__Vfuncout;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__tag = 
        std::string{"unknown_build_id"};
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__expected_status = 3U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[1U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[1U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[2U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[2U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[3U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[3U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[4U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[4U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[5U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[5U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[6U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[6U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[7U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[7U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[8U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[8U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[9U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[9U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0xaU] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0xaU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0xbU] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0xbU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0xcU] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0xcU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0xdU] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0xdU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0xeU] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0xeU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0xfU] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0xfU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0x10U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0x10U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0x11U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0x11U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0x12U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0x12U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0x13U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0x13U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0x14U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0x14U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0x15U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0x15U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0x16U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0x16U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0x17U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0x17U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0x18U] 
        = tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_build[0x18U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__124__ready = 0U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__124__unnamedblk8__DOT__n = 0U;
    {
        while (VL_GTS_III(32, 0x3e8U, __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__124__unnamedblk8__DOT__n)) {
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__125__value = 0U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__ir = 3U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__125__value 
                = ((0xfeU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__125__value)) 
                   | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__125__value 
                = ((0xfdU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__125__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 1U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__125__value 
                = ((0xfbU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__125__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 2U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__125__value 
                = ((0xf7U & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__125__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 3U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__125__value 
                = ((0xefU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__125__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 4U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__125__value 
                = ((0xdfU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__125__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 5U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__125__value 
                = ((0xbfU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__125__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 6U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__125__value 
                = ((0x7fU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__125__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 7U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__124__s 
                = __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__125__value;
            if ((8U & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__124__s))) {
                __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__124__ready = 1U;
                goto __Vlabel15;
            }
            __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__124__unnamedblk8__DOT__n 
                = ((IData)(1U) + __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__124__unnamedblk8__DOT__n);
        }
        __Vlabel15: ;
    }
    if (VL_UNLIKELY((1U & (~ (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__124__ready))))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42_capture_edge.sv:171: Assertion failed in %Ntb_rtnn_c2_soc_42.wait_for_ready: JTAG mailbox READY/ERROR timeout status=%02x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  8,(IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__124__s));
        VL_STOP_MT("tb_rtnn_c2_soc_42_capture_edge.sv", 171, "");
    }
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[0U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[1U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[1U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[2U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[2U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[3U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[3U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[4U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[4U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[5U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[5U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[6U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[6U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[7U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[7U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[8U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[8U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[9U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[9U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[0xaU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0xaU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[0xbU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0xbU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[0xcU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0xcU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[0xdU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0xdU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[0xeU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0xeU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[0xfU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0xfU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[0x10U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0x10U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[0x11U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0x11U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[0x12U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0x12U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[0x13U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0x13U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[0x14U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0x14U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[0x15U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0x15U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[0x16U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0x16U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[0x17U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0x17U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[0x18U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__payload[0x18U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__ir = 1U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 1U;
    co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                       118);
    co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                       118);
    vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 0U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__unnamedblk2__DOT__b = 0U;
    while (VL_GTS_III(32, 0x320U, __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__unnamedblk2__DOT__b)) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__tdi = ((0x31fU 
                                                >= 
                                                (0x3ffU 
                                                 & __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__unnamedblk2__DOT__b)) 
                                               && (1U 
                                                   & (__Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__payload[
                                                      (0x1fU 
                                                       & (__Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__unnamedblk2__DOT__b 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__unnamedblk2__DOT__b))));
        vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
        co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                           "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                           118);
        co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                           "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                           118);
        vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__unnamedblk2__DOT__b 
            = ((IData)(1U) + __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__128__unnamedblk2__DOT__b);
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__update_dr = 1U;
    co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                       118);
    co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                       118);
    vlSelf->tb_rtnn_c2_soc_42__DOT__update_dr = 0U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__done = 0U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__unnamedblk9__DOT__n = 0U;
    {
        while (VL_GTS_III(32, 0x186a0U, __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__unnamedblk9__DOT__n)) {
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__132__value = 0U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__ir = 3U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__132__value 
                = ((0xfeU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__132__value)) 
                   | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__132__value 
                = ((0xfdU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__132__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 1U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__132__value 
                = ((0xfbU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__132__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 2U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__132__value 
                = ((0xf7U & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__132__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 3U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__132__value 
                = ((0xefU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__132__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 4U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__132__value 
                = ((0xdfU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__132__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 5U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__132__value 
                = ((0xbfU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__132__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 6U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__132__value 
                = ((0x7fU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__132__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 7U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__s 
                = __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__132__value;
            if ((0x40U & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__s))) {
                __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__done = 1U;
                goto __Vlabel16;
            }
            __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__unnamedblk9__DOT__n 
                = ((IData)(1U) + __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__unnamedblk9__DOT__n);
        }
        __Vlabel16: ;
    }
    if (VL_UNLIKELY((1U & (~ (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__done))))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42_capture_edge.sv:187: Assertion failed in %Ntb_rtnn_c2_soc_42.expect_error_request: negative request completion timeout: %@ status=%02x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  -1,&(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__tag),
                  8,(IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__s));
        VL_STOP_MT("tb_rtnn_c2_soc_42_capture_edge.sv", 187, "");
    }
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[0U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[1U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[1U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[2U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[2U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[3U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[3U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[4U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[4U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[5U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[5U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[6U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[6U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[7U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[7U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[8U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[8U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[9U] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[9U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[0xaU] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0xaU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[0xbU] 
        = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h997e551f_0[0xbU];
    vlSelf->tb_rtnn_c2_soc_42__DOT__ir = 2U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 1U;
    co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                       118);
    co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                       118);
    vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 0U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__unnamedblk3__DOT__b = 0U;
    while (VL_GTS_III(32, 0x180U, __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__unnamedblk3__DOT__b)) {
        vlSelf->tb_rtnn_c2_soc_42__DOT____Vlvbound_hbf14d360__0 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__tdo;
        if (VL_LIKELY((0x17fU >= (0x1ffU & __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__unnamedblk3__DOT__b)))) {
            __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[(0xfU 
                                                                            & (__Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__unnamedblk3__DOT__b 
                                                                               >> 5U))] 
                = (((~ ((IData)(1U) << (0x1fU & __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__unnamedblk3__DOT__b))) 
                    & __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[
                    (0xfU & (__Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__unnamedblk3__DOT__b 
                             >> 5U))]) | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT____Vlvbound_hbf14d360__0) 
                                          << (0x1fU 
                                              & __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__unnamedblk3__DOT__b)));
        }
        vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
        co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                           "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                           118);
        co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                           "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                           118);
        vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
        __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__unnamedblk3__DOT__b 
            = ((IData)(1U) + __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__unnamedblk3__DOT__b);
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__update_dr = 1U;
    co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                       118);
    co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                       118);
    vlSelf->tb_rtnn_c2_soc_42__DOT__update_dr = 0U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[0U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[0U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[1U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[1U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[2U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[2U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[3U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[3U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[4U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[4U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[5U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[5U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[6U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[6U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[7U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[7U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[8U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[8U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[9U] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[9U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[0xaU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[0xaU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[0xbU] 
        = __Vtask_tb_rtnn_c2_soc_42__DOT__response_scan_read__135__value[0xbU];
    if (VL_UNLIKELY(((0xffU & (__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[1U] 
                               >> 8U)) != (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__expected_status)))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42_capture_edge.sv:192: Assertion failed in %Ntb_rtnn_c2_soc_42.expect_error_request: negative response status %@ got=%0# expected=%0#\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  -1,&(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__tag),
                  8,(0xffU & (__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[1U] 
                              >> 8U)),8,(IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__expected_status));
        VL_STOP_MT("tb_rtnn_c2_soc_42_capture_edge.sv", 192, "");
    }
    if (VL_UNLIKELY((0U != __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[6U]))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42_capture_edge.sv:194: Assertion failed in %Ntb_rtnn_c2_soc_42.expect_error_request: negative request returned nonzero inference cycles: %@\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  -1,&(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__tag));
        VL_STOP_MT("tb_rtnn_c2_soc_42_capture_edge.sv", 194, "");
    }
    if (VL_UNLIKELY((__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[0xbU] 
                     != ([&]() {
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[0U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[0U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[1U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[1U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[2U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[2U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[3U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[3U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[4U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[4U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[5U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[5U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[6U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[6U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[7U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[7U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[8U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[8U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[9U] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[9U];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[0xaU] 
                            = __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[0xaU];
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c = 0xffffffffU;
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[0U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[0U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[0U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[0U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[1U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[1U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[1U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[1U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[2U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[2U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[2U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[2U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[3U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[3U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[3U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[3U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[4U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[4U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[4U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[4U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[5U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[5U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[5U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[5U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[6U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[6U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[6U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[6U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[7U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[7U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[7U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[7U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[8U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[8U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[8U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[8U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[9U]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[9U] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[9U] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[9U] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[0xaU]);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[0xaU] 
                                        >> 8U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (0xffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[0xaU] 
                                        >> 0x10U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__prefix[0xaU] 
                               >> 0x18U);
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = (__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                               ^ (IData)(__Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__by));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c 
                            = ((1U & __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U))
                                : VL_SHIFTR_III(32,32,32, __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c, 1U));
                        __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__Vfuncout 
                            = (~ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__c);
                    }(), __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_44__139__Vfuncout)))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42_capture_edge.sv:196: Assertion failed in %Ntb_rtnn_c2_soc_42.expect_error_request: negative response CRC mismatch: %@\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  -1,&(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__tag));
        VL_STOP_MT("tb_rtnn_c2_soc_42_capture_edge.sv", 196, "");
    }
    if (VL_UNLIKELY(vlSelf->tb_rtnn_c2_soc_42__DOT__bus_fault)) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42_capture_edge.sv:197: Assertion failed in %Ntb_rtnn_c2_soc_42.expect_error_request: negative request caused SoC fault/halt: %@\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  -1,&(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__tag));
        VL_STOP_MT("tb_rtnn_c2_soc_42_capture_edge.sv", 197, "");
    }
    VL_WRITEF("C2_SOC_NEGATIVE_PASS tag=%@ response_status=%0#\n",
              -1,&(__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__tag),
              8,(0xffU & (__Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__123__got[1U] 
                          >> 8U)));
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__140__ready = 0U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__140__unnamedblk8__DOT__n = 0U;
    {
        while (VL_GTS_III(32, 0x3e8U, __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__140__unnamedblk8__DOT__n)) {
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__141__value = 0U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__ir = 3U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__141__value 
                = ((0xfeU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__141__value)) 
                   | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__141__value 
                = ((0xfdU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__141__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 1U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__141__value 
                = ((0xfbU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__141__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 2U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__141__value 
                = ((0xf7U & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__141__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 3U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__141__value 
                = ((0xefU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__141__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 4U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__141__value 
                = ((0xdfU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__141__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 5U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__141__value 
                = ((0xbfU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__141__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 6U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__141__value 
                = ((0x7fU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__141__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 7U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__140__s 
                = __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__141__value;
            if ((8U & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__140__s))) {
                __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__140__ready = 1U;
                goto __Vlabel17;
            }
            __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__140__unnamedblk8__DOT__n 
                = ((IData)(1U) + __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__140__unnamedblk8__DOT__n);
        }
        __Vlabel17: ;
    }
    if (VL_UNLIKELY((1U & (~ (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__140__ready))))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42_capture_edge.sv:171: Assertion failed in %Ntb_rtnn_c2_soc_42.wait_for_ready: JTAG mailbox READY/ERROR timeout status=%02x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  8,(IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__140__s));
        VL_STOP_MT("tb_rtnn_c2_soc_42_capture_edge.sv", 171, "");
    }
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[0U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][0U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[1U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][1U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[2U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][2U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[3U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][3U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[4U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][4U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[5U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][5U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[6U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][6U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[7U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][7U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[8U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][8U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[9U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][9U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[0xaU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][0xaU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[0xbU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][0xbU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[0xcU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][0xcU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[0xdU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][0xdU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[0xeU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][0xeU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[0xfU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][0xfU];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[0x10U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][0x10U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[0x11U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][0x11U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[0x12U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][0x12U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[0x13U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][0x13U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[0x14U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][0x14U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[0x15U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][0x15U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[0x16U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][0x16U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[0x17U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][0x17U];
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[0x18U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__requests[0x29U][0x18U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__ir = 1U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 1U;
    co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                       118);
    co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                       118);
    vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 0U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__unnamedblk2__DOT__b = 0U;
    while (VL_GTS_III(32, 0x320U, __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__unnamedblk2__DOT__b)) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__tdi = ((0x31fU 
                                                >= 
                                                (0x3ffU 
                                                 & __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__unnamedblk2__DOT__b)) 
                                               && (1U 
                                                   & (__Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__payload[
                                                      (0x1fU 
                                                       & (__Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__unnamedblk2__DOT__b 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__unnamedblk2__DOT__b))));
        vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
        co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                           "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                           118);
        co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                           "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                           118);
        vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__unnamedblk2__DOT__b 
            = ((IData)(1U) + __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__144__unnamedblk2__DOT__b);
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__update_dr = 1U;
    co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                       118);
    co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                       118);
    vlSelf->tb_rtnn_c2_soc_42__DOT__update_dr = 0U;
    tb_rtnn_c2_soc_42__DOT__unnamedblk12__DOT__observed_busy = 0U;
    tb_rtnn_c2_soc_42__DOT__unnamedblk12__DOT__unnamedblk13__DOT__n = 0U;
    {
        while (VL_GTS_III(32, 0x3e8U, tb_rtnn_c2_soc_42__DOT__unnamedblk12__DOT__unnamedblk13__DOT__n)) {
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__148__value = 0U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__ir = 3U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__148__value 
                = ((0xfeU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__148__value)) 
                   | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__148__value 
                = ((0xfdU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__148__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 1U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__148__value 
                = ((0xfbU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__148__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 2U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__148__value 
                = ((0xf7U & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__148__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 3U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__148__value 
                = ((0xefU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__148__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 4U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__148__value 
                = ((0xdfU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__148__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 5U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__148__value 
                = ((0xbfU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__148__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 6U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__148__value 
                = ((0x7fU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__148__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 7U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk12__DOT__s 
                = __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__148__value;
            if ((IData)((0U != (0x30U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__unnamedblk12__DOT__s))))) {
                tb_rtnn_c2_soc_42__DOT__unnamedblk12__DOT__observed_busy = 1U;
                goto __Vlabel18;
            }
            tb_rtnn_c2_soc_42__DOT__unnamedblk12__DOT__unnamedblk13__DOT__n 
                = ((IData)(1U) + tb_rtnn_c2_soc_42__DOT__unnamedblk12__DOT__unnamedblk13__DOT__n);
        }
        __Vlabel18: ;
    }
    if (VL_UNLIKELY((1U & (~ (IData)(tb_rtnn_c2_soc_42__DOT__unnamedblk12__DOT__observed_busy))))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42_capture_edge.sv:300: Assertion failed in %Ntb_rtnn_c2_soc_42.unnamedblk12: did not observe BUSY/PENDING before reset\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("tb_rtnn_c2_soc_42_capture_edge.sv", 300, "");
    }
    co_await vlSelf->__VtrigSched_h23c93641__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_rtnn_c2_soc_42.clk)", 
                                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                       302);
    vlSelf->tb_rtnn_c2_soc_42__DOT__rst_n = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__trst_n = 0U;
    co_await vlSelf->__VtrigSched_h23c93641__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_rtnn_c2_soc_42.clk)", 
                                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                       303);
    co_await vlSelf->__VtrigSched_h23c93641__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_rtnn_c2_soc_42.clk)", 
                                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                       303);
    co_await vlSelf->__VtrigSched_h23c93641__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_rtnn_c2_soc_42.clk)", 
                                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                       303);
    co_await vlSelf->__VtrigSched_h23c93641__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_rtnn_c2_soc_42.clk)", 
                                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                       303);
    co_await vlSelf->__VtrigSched_h23c93641__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_rtnn_c2_soc_42.clk)", 
                                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                       303);
    vlSelf->tb_rtnn_c2_soc_42__DOT__rst_n = 1U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__trst_n = 1U;
    co_await vlSelf->__VtrigSched_h23c93641__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_rtnn_c2_soc_42.clk)", 
                                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                       305);
    co_await vlSelf->__VtrigSched_h23c93641__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_rtnn_c2_soc_42.clk)", 
                                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                       305);
    co_await vlSelf->__VtrigSched_h23c93641__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_rtnn_c2_soc_42.clk)", 
                                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                       305);
    co_await vlSelf->__VtrigSched_h23c93641__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_rtnn_c2_soc_42.clk)", 
                                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                       305);
    co_await vlSelf->__VtrigSched_h23c93641__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_rtnn_c2_soc_42.clk)", 
                                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                       305);
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__151__ready = 0U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__151__unnamedblk8__DOT__n = 0U;
    {
        while (VL_GTS_III(32, 0x3e8U, __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__151__unnamedblk8__DOT__n)) {
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__152__value = 0U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__ir = 3U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__152__value 
                = ((0xfeU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__152__value)) 
                   | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__152__value 
                = ((0xfdU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__152__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 1U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__152__value 
                = ((0xfbU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__152__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 2U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__152__value 
                = ((0xf7U & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__152__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 3U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__152__value 
                = ((0xefU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__152__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 4U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__152__value 
                = ((0xdfU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__152__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 5U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__152__value 
                = ((0xbfU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__152__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 6U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__152__value 
                = ((0x7fU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__152__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 7U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__151__s 
                = __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__152__value;
            if ((8U & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__151__s))) {
                __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__151__ready = 1U;
                goto __Vlabel19;
            }
            __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__151__unnamedblk8__DOT__n 
                = ((IData)(1U) + __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__151__unnamedblk8__DOT__n);
        }
        __Vlabel19: ;
    }
    if (VL_UNLIKELY((1U & (~ (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__151__ready))))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42_capture_edge.sv:171: Assertion failed in %Ntb_rtnn_c2_soc_42.wait_for_ready: JTAG mailbox READY/ERROR timeout status=%02x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  8,(IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__151__s));
        VL_STOP_MT("tb_rtnn_c2_soc_42_capture_edge.sv", 171, "");
    }
    vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index = 0U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__156__ready = 0U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__156__unnamedblk8__DOT__n = 0U;
    if ((0x29U >= (0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index))) {
        vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__seq 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__expected
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][0U];
        vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__iid 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__expected
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][1U];
        vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__mode 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__expected
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][2U];
        vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__admit 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__expected
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][3U];
        vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__exec_exit 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__expected
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][4U];
        vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__pred 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__expected
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][5U];
        vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__label 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__expected
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][6U];
        vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__budget 
            = (0xffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__expected
               [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][7U]);
        vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__stop 
            = (0xffU & vlSelf->tb_rtnn_c2_soc_42__DOT__expected
               [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][8U]);
    } else {
        vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__seq 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h9a2fc1c8_0[0U];
        vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__iid 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h9a2fc1c8_0[1U];
        vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__mode 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h9a2fc1c8_0[2U];
        vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__admit 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h9a2fc1c8_0[3U];
        vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__exec_exit 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h9a2fc1c8_0[4U];
        vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__pred 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h9a2fc1c8_0[5U];
        vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__label 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_h9a2fc1c8_0[6U];
        vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__budget 
            = (0xffffU & Vtb_rtnn_c2_soc_42__ConstPool__CONST_h9a2fc1c8_0[7U]);
        vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__stop 
            = (0xffU & Vtb_rtnn_c2_soc_42__ConstPool__CONST_h9a2fc1c8_0[8U]);
    }
    {
        while (VL_GTS_III(32, 0x3e8U, __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__156__unnamedblk8__DOT__n)) {
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__157__value = 0U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__ir = 3U;
            vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__157__value 
                = ((0xfeU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__157__value)) 
                   | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__157__value 
                = ((0xfdU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__157__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 1U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__157__value 
                = ((0xfbU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__157__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 2U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__157__value 
                = ((0xf7U & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__157__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 3U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__157__value 
                = ((0xefU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__157__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 4U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__157__value 
                = ((0xdfU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__157__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 5U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__157__value 
                = ((0xbfU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__157__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 6U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__157__value 
                = ((0x7fU & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__157__value)) 
                   | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__tdo) 
                      << 7U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
            co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                               118);
            co_await vlSelf->__VdlySched.delay(1ULL, 
                                               nullptr, 
                                               "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                               118);
            vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
            __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__156__s 
                = __Vtask_tb_rtnn_c2_soc_42__DOT__status_scan__157__value;
            if ((8U & (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__156__s))) {
                __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__156__ready = 1U;
                goto __Vlabel20;
            }
            __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__156__unnamedblk8__DOT__n 
                = ((IData)(1U) + __Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__156__unnamedblk8__DOT__n);
        }
        __Vlabel20: ;
    }
    if (VL_UNLIKELY((1U & (~ (IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__156__ready))))) {
        VL_WRITEF("[%0t] %%Fatal: tb_rtnn_c2_soc_42_capture_edge.sv:171: Assertion failed in %Ntb_rtnn_c2_soc_42.wait_for_ready: JTAG mailbox READY/ERROR timeout status=%02x\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                  8,(IData)(__Vtask_tb_rtnn_c2_soc_42__DOT__wait_for_ready__156__s));
        VL_STOP_MT("tb_rtnn_c2_soc_42_capture_edge.sv", 171, "");
    }
    if ((0x29U >= (0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index))) {
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0U] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][0U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[1U] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][1U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[2U] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][2U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[3U] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][3U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[4U] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][4U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[5U] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][5U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[6U] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][6U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[7U] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][7U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[8U] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][8U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[9U] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][9U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0xaU] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][0xaU];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0xbU] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][0xbU];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0xcU] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][0xcU];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0xdU] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][0xdU];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0xeU] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][0xeU];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0xfU] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][0xfU];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0x10U] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][0x10U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0x11U] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][0x11U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0x12U] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][0x12U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0x13U] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][0x13U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0x14U] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][0x14U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0x15U] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][0x15U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0x16U] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][0x16U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0x17U] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][0x17U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0x18U] 
            = vlSelf->tb_rtnn_c2_soc_42__DOT__requests
            [(0x3fU & vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index)][0x18U];
    } else {
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[1U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[1U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[2U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[2U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[3U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[3U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[4U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[4U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[5U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[5U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[6U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[6U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[7U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[7U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[8U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[8U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[9U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[9U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0xaU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xaU];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0xbU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xbU];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0xcU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xcU];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0xdU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xdU];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0xeU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xeU];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0xfU] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0xfU];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0x10U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x10U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0x11U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x11U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0x12U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x12U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0x13U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x13U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0x14U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x14U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0x15U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x15U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0x16U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x16U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0x17U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x17U];
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[0x18U] 
            = Vtb_rtnn_c2_soc_42__ConstPool__CONST_hff85231a_0[0x18U];
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__ir = 1U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 1U;
    co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                       118);
    co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                       118);
    vlSelf->tb_rtnn_c2_soc_42__DOT__capture_dr = 0U;
    __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__unnamedblk2__DOT__b = 0U;
    while (VL_GTS_III(32, 0x320U, __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__unnamedblk2__DOT__b)) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__tdi = ((0x31fU 
                                                >= 
                                                (0x3ffU 
                                                 & __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__unnamedblk2__DOT__b)) 
                                               && (1U 
                                                   & (__Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__payload[
                                                      (0x1fU 
                                                       & (__Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__unnamedblk2__DOT__b 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x1fU 
                                                       & __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__unnamedblk2__DOT__b))));
        vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 1U;
        co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                           "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                           118);
        co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                           "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                           118);
        vlSelf->tb_rtnn_c2_soc_42__DOT__shift_dr = 0U;
        __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__unnamedblk2__DOT__b 
            = ((IData)(1U) + __Vtask_tb_rtnn_c2_soc_42__DOT__request_scan__160__unnamedblk2__DOT__b);
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__update_dr = 1U;
    co_await vlSelf->__VtrigSched_h6e9b7ca3__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rtnn_c2_soc_42.tck)", 
                                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                                       118);
    co_await vlSelf->__VdlySched.delay(1ULL, nullptr, 
                                       "tb_rtnn_c2_soc_42_capture_edge.sv", 
                                       118);
    vlSelf->tb_rtnn_c2_soc_42__DOT__update_dr = 0U;
    vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__done = 0U;
    vlSelf->__Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__unnamedblk10__DOT__n = 0U;
}
