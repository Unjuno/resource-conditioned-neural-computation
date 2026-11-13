// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VTB_RTNN_C2_SOC_42_H_
#define VERILATED_VTB_RTNN_C2_SOC_42_H_  // guard

#include "verilated.h"

class Vtb_rtnn_c2_soc_42__Syms;
class Vtb_rtnn_c2_soc_42___024root;
class Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9;
class Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8;
class Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7;


// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vtb_rtnn_c2_soc_42 VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vtb_rtnn_c2_soc_42__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.
    Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* const __PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i;
    Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* const __PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i;
    Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9* const __PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i;
    Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* const __PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__if_stage_i;
    Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* const __PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__id_stage_i;
    Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9* const __PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__cs_registers_i;

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vtb_rtnn_c2_soc_42___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vtb_rtnn_c2_soc_42(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vtb_rtnn_c2_soc_42(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vtb_rtnn_c2_soc_42();
  private:
    VL_UNCOPYABLE(Vtb_rtnn_c2_soc_42);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
};

#endif  // guard
