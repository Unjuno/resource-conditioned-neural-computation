// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_rtnn_c2_soc_42__pch.h"

//============================================================
// Constructors

Vtb_rtnn_c2_soc_42::Vtb_rtnn_c2_soc_42(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_rtnn_c2_soc_42__Syms(contextp(), _vcname__, this)}
    , __PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i{vlSymsp->TOP.__PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i}
    , __PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i{vlSymsp->TOP.__PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i}
    , __PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i{vlSymsp->TOP.__PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i}
    , __PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__if_stage_i{vlSymsp->TOP.__PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__if_stage_i}
    , __PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__id_stage_i{vlSymsp->TOP.__PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__id_stage_i}
    , __PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__cs_registers_i{vlSymsp->TOP.__PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__cs_registers_i}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_rtnn_c2_soc_42::Vtb_rtnn_c2_soc_42(const char* _vcname__)
    : Vtb_rtnn_c2_soc_42(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_rtnn_c2_soc_42::~Vtb_rtnn_c2_soc_42() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_rtnn_c2_soc_42___024root___eval_debug_assertions(Vtb_rtnn_c2_soc_42___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_rtnn_c2_soc_42___024root___eval_static(Vtb_rtnn_c2_soc_42___024root* vlSelf);
void Vtb_rtnn_c2_soc_42___024root___eval_initial(Vtb_rtnn_c2_soc_42___024root* vlSelf);
void Vtb_rtnn_c2_soc_42___024root___eval_settle(Vtb_rtnn_c2_soc_42___024root* vlSelf);
void Vtb_rtnn_c2_soc_42___024root___eval(Vtb_rtnn_c2_soc_42___024root* vlSelf);

void Vtb_rtnn_c2_soc_42::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_rtnn_c2_soc_42::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_rtnn_c2_soc_42___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_rtnn_c2_soc_42___024root___eval_static(&(vlSymsp->TOP));
        Vtb_rtnn_c2_soc_42___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_rtnn_c2_soc_42___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_rtnn_c2_soc_42___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_rtnn_c2_soc_42::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vtb_rtnn_c2_soc_42::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_rtnn_c2_soc_42::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_rtnn_c2_soc_42___024root___eval_final(Vtb_rtnn_c2_soc_42___024root* vlSelf);

VL_ATTR_COLD void Vtb_rtnn_c2_soc_42::final() {
    Vtb_rtnn_c2_soc_42___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_rtnn_c2_soc_42::hierName() const { return vlSymsp->name(); }
const char* Vtb_rtnn_c2_soc_42::modelName() const { return "Vtb_rtnn_c2_soc_42"; }
unsigned Vtb_rtnn_c2_soc_42::threads() const { return 1; }
void Vtb_rtnn_c2_soc_42::prepareClone() const { contextp()->prepareClone(); }
void Vtb_rtnn_c2_soc_42::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vtb_rtnn_c2_soc_42::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtb_rtnn_c2_soc_42::trace()' called on model that was Verilated without --trace option");
}
