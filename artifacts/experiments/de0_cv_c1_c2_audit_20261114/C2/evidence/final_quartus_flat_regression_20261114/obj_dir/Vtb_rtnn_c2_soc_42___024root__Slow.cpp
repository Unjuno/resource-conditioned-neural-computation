// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rtnn_c2_soc_42.h for the primary calling header

#include "Vtb_rtnn_c2_soc_42__pch.h"
#include "Vtb_rtnn_c2_soc_42__Syms.h"
#include "Vtb_rtnn_c2_soc_42___024root.h"

void Vtb_rtnn_c2_soc_42___024root___ctor_var_reset(Vtb_rtnn_c2_soc_42___024root* vlSelf);

Vtb_rtnn_c2_soc_42___024root::Vtb_rtnn_c2_soc_42___024root(Vtb_rtnn_c2_soc_42__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_rtnn_c2_soc_42___024root___ctor_var_reset(this);
}

void Vtb_rtnn_c2_soc_42___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtb_rtnn_c2_soc_42___024root::~Vtb_rtnn_c2_soc_42___024root() {
}
