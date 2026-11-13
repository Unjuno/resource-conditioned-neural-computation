// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_rtnn_c2_soc_42__pch.h"
#include "Vtb_rtnn_c2_soc_42.h"
#include "Vtb_rtnn_c2_soc_42___024root.h"
#include "Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7.h"
#include "Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8.h"
#include "Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9.h"

// FUNCTIONS
Vtb_rtnn_c2_soc_42__Syms::~Vtb_rtnn_c2_soc_42__Syms()
{
}

Vtb_rtnn_c2_soc_42__Syms::Vtb_rtnn_c2_soc_42__Syms(VerilatedContext* contextp, const char* namep, Vtb_rtnn_c2_soc_42* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__cs_registers_i{this, Verilated::catName(namep, "tb_rtnn_c2_soc_42.u_soc.u_ibex.gen_lockstep.u_ibex_lockstep.u_shadow_core.cs_registers_i")}
    , TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__id_stage_i{this, Verilated::catName(namep, "tb_rtnn_c2_soc_42.u_soc.u_ibex.gen_lockstep.u_ibex_lockstep.u_shadow_core.id_stage_i")}
    , TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__if_stage_i{this, Verilated::catName(namep, "tb_rtnn_c2_soc_42.u_soc.u_ibex.gen_lockstep.u_ibex_lockstep.u_shadow_core.if_stage_i")}
    , TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i{this, Verilated::catName(namep, "tb_rtnn_c2_soc_42.u_soc.u_ibex.u_ibex_core.cs_registers_i")}
    , TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i{this, Verilated::catName(namep, "tb_rtnn_c2_soc_42.u_soc.u_ibex.u_ibex_core.id_stage_i")}
    , TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i{this, Verilated::catName(namep, "tb_rtnn_c2_soc_42.u_soc.u_ibex.u_ibex_core.if_stage_i")}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__cs_registers_i = &TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__cs_registers_i;
    TOP.__PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__id_stage_i = &TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__id_stage_i;
    TOP.__PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__if_stage_i = &TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__if_stage_i;
    TOP.__PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i = &TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i;
    TOP.__PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i = &TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i;
    TOP.__PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i = &TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__cs_registers_i.__Vconfigure(true);
    TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__id_stage_i.__Vconfigure(true);
    TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__if_stage_i.__Vconfigure(true);
    TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__Vconfigure(false);
    TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__Vconfigure(false);
    TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.__Vconfigure(false);
    // Setup scopes
    __Vscope_tb_rtnn_c2_soc_42.configure(this, name(), "tb_rtnn_c2_soc_42", "tb_rtnn_c2_soc_42", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_rtnn_c2_soc_42__expect_error_request.configure(this, name(), "tb_rtnn_c2_soc_42.expect_error_request", "expect_error_request", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_rtnn_c2_soc_42__run_case.configure(this, name(), "tb_rtnn_c2_soc_42.run_case", "run_case", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_rtnn_c2_soc_42__run_case__unnamedblk10.configure(this, name(), "tb_rtnn_c2_soc_42.run_case.unnamedblk10", "unnamedblk10", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_rtnn_c2_soc_42__unnamedblk12.configure(this, name(), "tb_rtnn_c2_soc_42.unnamedblk12", "unnamedblk12", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_rtnn_c2_soc_42__wait_for_ready.configure(this, name(), "tb_rtnn_c2_soc_42.wait_for_ready", "wait_for_ready", -12, VerilatedScope::SCOPE_OTHER);
}
