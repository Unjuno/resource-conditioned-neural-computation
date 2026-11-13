// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_RTNN_C2_SOC_42__SYMS_H_
#define VERILATED_VTB_RTNN_C2_SOC_42__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_rtnn_c2_soc_42.h"

// INCLUDE MODULE CLASSES
#include "Vtb_rtnn_c2_soc_42___024root.h"
#include "Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7.h"
#include "Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8.h"
#include "Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtb_rtnn_c2_soc_42__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_rtnn_c2_soc_42* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_rtnn_c2_soc_42___024root   TOP;
    Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9 TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__cs_registers_i;
    Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8 TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__id_stage_i;
    Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7 TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__if_stage_i;
    Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9 TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i;
    Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8 TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i;
    Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7 TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i;

    // SCOPE NAMES
    VerilatedScope __Vscope_tb_rtnn_c2_soc_42;
    VerilatedScope __Vscope_tb_rtnn_c2_soc_42__expect_error_request;
    VerilatedScope __Vscope_tb_rtnn_c2_soc_42__run_case;
    VerilatedScope __Vscope_tb_rtnn_c2_soc_42__run_case__unnamedblk10;
    VerilatedScope __Vscope_tb_rtnn_c2_soc_42__unnamedblk12;
    VerilatedScope __Vscope_tb_rtnn_c2_soc_42__wait_for_ready;

    // CONSTRUCTORS
    Vtb_rtnn_c2_soc_42__Syms(VerilatedContext* contextp, const char* namep, Vtb_rtnn_c2_soc_42* modelp);
    ~Vtb_rtnn_c2_soc_42__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
