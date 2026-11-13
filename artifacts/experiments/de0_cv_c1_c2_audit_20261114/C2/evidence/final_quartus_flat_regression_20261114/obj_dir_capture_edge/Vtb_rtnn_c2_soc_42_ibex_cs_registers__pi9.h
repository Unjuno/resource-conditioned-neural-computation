// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_rtnn_c2_soc_42.h for the primary calling header

#ifndef VERILATED_VTB_RTNN_C2_SOC_42_IBEX_CS_REGISTERS__PI9_H_
#define VERILATED_VTB_RTNN_C2_SOC_42_IBEX_CS_REGISTERS__PI9_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_rtnn_c2_soc_42__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk_i,0,0);
        VL_IN8(rst_ni,0,0);
        VL_OUT8(priv_mode_id_o,1,0);
        VL_OUT8(priv_mode_lsu_o,1,0);
        VL_OUT8(csr_mstatus_tw_o,0,0);
        VL_IN8(csr_mtvec_init_i,0,0);
        VL_IN8(csr_access_i,0,0);
        VL_IN8(csr_op_i,1,0);
        VL_IN8(csr_op_en_i,0,0);
        VL_IN8(irq_software_i,0,0);
        VL_IN8(irq_timer_i,0,0);
        VL_IN8(irq_external_i,0,0);
        VL_IN8(nmi_mode_i,0,0);
        VL_OUT8(irq_pending_o,0,0);
        VL_OUT8(csr_mstatus_mie_o,0,0);
        VL_OUT8(__PVT__csr_pmp_mseccfg_o,2,0);
        VL_IN8(debug_mode_i,0,0);
        VL_IN8(debug_mode_entering_i,0,0);
        VL_IN8(debug_cause_i,2,0);
        VL_IN8(debug_csr_save_i,0,0);
        VL_OUT8(debug_single_step_o,0,0);
        VL_OUT8(debug_ebreakm_o,0,0);
        VL_OUT8(debug_ebreaku_o,0,0);
        VL_OUT8(__PVT__trigger_match_o,0,0);
        VL_OUT8(data_ind_timing_o,0,0);
        VL_OUT8(dummy_instr_en_o,0,0);
        VL_OUT8(dummy_instr_mask_o,2,0);
        VL_OUT8(dummy_instr_seed_en_o,0,0);
        VL_OUT8(icache_enable_o,0,0);
        VL_OUT8(csr_shadow_err_o,0,0);
        VL_IN8(ic_scr_key_valid_i,0,0);
        VL_IN8(mcounteren_writable_i,3,0);
        VL_IN8(csr_save_if_i,0,0);
        VL_IN8(csr_save_id_i,0,0);
        VL_IN8(csr_save_wb_i,0,0);
        VL_IN8(csr_restore_mret_i,0,0);
        VL_IN8(csr_restore_dret_i,0,0);
        VL_IN8(csr_save_cause_i,0,0);
        VL_IN8(csr_mcause_i,6,0);
        VL_OUT8(illegal_csr_insn_o,0,0);
        VL_OUT8(double_fault_seen_o,0,0);
        VL_IN8(instr_ret_i,0,0);
        VL_IN8(instr_ret_compressed_i,0,0);
        VL_IN8(instr_ret_spec_i,0,0);
        VL_IN8(instr_ret_compressed_spec_i,0,0);
        VL_IN8(iside_wait_i,0,0);
        VL_IN8(jump_i,0,0);
        VL_IN8(branch_i,0,0);
        VL_IN8(branch_taken_i,0,0);
        VL_IN8(mem_load_i,0,0);
        VL_IN8(mem_store_i,0,0);
        VL_IN8(dside_wait_i,0,0);
        VL_IN8(mul_wait_i,0,0);
        VL_IN8(div_wait_i,0,0);
        CData/*1:0*/ __PVT__priv_lvl_q;
        CData/*1:0*/ __PVT__priv_lvl_d;
        CData/*5:0*/ __PVT__mstatus_d;
        CData/*0:0*/ __PVT__mstatus_en;
        CData/*0:0*/ __PVT__mie_en;
        CData/*0:0*/ __PVT__mscratch_en;
        CData/*0:0*/ __PVT__mepc_en;
        CData/*6:0*/ __PVT__mcause_d;
        CData/*0:0*/ __PVT__mcause_en;
        CData/*0:0*/ __PVT__mtval_en;
    };
    struct {
        CData/*0:0*/ __PVT__mtvec_en;
        CData/*0:0*/ __PVT__dcsr_en;
        CData/*0:0*/ __PVT__depc_en;
        CData/*0:0*/ __PVT__dscratch0_en;
        CData/*0:0*/ __PVT__dscratch1_en;
        CData/*0:0*/ __PVT__mstack_en;
        CData/*2:0*/ __PVT__mcountinhibit_d;
        CData/*2:0*/ __PVT__mcountinhibit_q;
        CData/*2:0*/ __PVT__mcounteren_d;
        CData/*0:0*/ __PVT__mcounteren_we;
        CData/*7:0*/ __PVT__cpuctrlsts_part_d;
        CData/*0:0*/ __PVT__cpuctrlsts_part_we;
        CData/*0:0*/ __PVT__csr_we_int;
        CData/*0:0*/ __PVT__csr_wr;
        CData/*0:0*/ __PVT__dbg_csr;
        CData/*0:0*/ __PVT__illegal_csr;
        CData/*5:0*/ __PVT__u_mstatus_csr__DOT__rdata_q;
        CData/*6:0*/ __PVT__u_mcause_csr__DOT__rdata_q;
        CData/*2:0*/ __PVT__u_mstack_csr__DOT__rdata_q;
        CData/*6:0*/ __PVT__u_mstack_cause_csr__DOT__rdata_q;
        CData/*2:0*/ __PVT__u_mcounteren_csr__DOT__rdata_q;
        CData/*7:0*/ __PVT__u_cpuctrlsts_part_csr__DOT__rdata_q;
        CData/*1:0*/ __Vfunc_sv2v_cast_2__0__Vfuncout;
        CData/*1:0*/ __Vfunc_sv2v_cast_2__0__inp;
        VL_IN16(csr_addr_i,11,0);
        VL_IN16(irq_fast_i,14,0);
        VL_IN(hart_id_i,31,0);
        VL_OUT(csr_mtvec_o,31,0);
        VL_IN(boot_addr_i,31,0);
        VL_IN(csr_wdata_i,31,0);
        VL_OUT(csr_rdata_o,31,0);
        VL_OUT(irqs_o,17,0);
        VL_OUT(csr_mepc_o,31,0);
        VL_OUT(csr_mtval_o,31,0);
        VL_OUT(__PVT__csr_pmp_cfg_o,23,0);
        VL_OUTW(__PVT__csr_pmp_addr_o,135,0,5);
        VL_OUT(csr_depc_o,31,0);
        VL_IN(pc_if_i,31,0);
        VL_IN(pc_id_i,31,0);
        VL_IN(pc_wb_i,31,0);
        VL_OUT(dummy_instr_seed_o,31,0);
        VL_IN(csr_mtval_i,31,0);
        IData/*31:0*/ __PVT__mepc_d;
        IData/*31:0*/ __PVT__mtval_d;
        IData/*31:0*/ __PVT__dcsr_d;
        IData/*31:0*/ __PVT__depc_d;
        IData/*31:0*/ __PVT__csr_wdata_int;
        IData/*31:0*/ __PVT__csr_rdata_int;
        IData/*31:0*/ __PVT__u_mepc_csr__DOT__rdata_q;
        IData/*17:0*/ __PVT__u_mie_csr__DOT__rdata_q;
        IData/*31:0*/ __PVT__u_mscratch_csr__DOT__rdata_q;
        IData/*31:0*/ __PVT__u_mtval_csr__DOT__rdata_q;
        IData/*31:0*/ __PVT__u_mtvec_csr__DOT__rdata_q;
        IData/*31:0*/ __PVT__u_dcsr_csr__DOT__rdata_q;
        IData/*31:0*/ __PVT__u_depc_csr__DOT__rdata_q;
        IData/*31:0*/ __PVT__u_dscratch0_csr__DOT__rdata_q;
        IData/*31:0*/ __PVT__u_dscratch1_csr__DOT__rdata_q;
        IData/*31:0*/ __PVT__u_mstack_epc_csr__DOT__rdata_q;
        QData/*63:0*/ __PVT__mcycle_counter_i__DOT__counter_d;
        QData/*63:0*/ __PVT__mcycle_counter_i__DOT__counter_q;
        QData/*63:0*/ __PVT__minstret_counter_i__DOT__counter_d;
        QData/*63:0*/ __PVT__minstret_counter_i__DOT__counter_q;
        VlUnpacked<IData/*31:0*/, 16> __PVT__pmp_addr_rdata;
        VlUnpacked<CData/*7:0*/, 16> __PVT__pmp_cfg_rdata;
    };
    struct {
        VlUnpacked<QData/*63:0*/, 32> __PVT__mhpmcounter;
        VlUnpacked<IData/*31:0*/, 32> __PVT__mhpmevent;
    };

    // INTERNAL VARIABLES
    Vtb_rtnn_c2_soc_42__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9(Vtb_rtnn_c2_soc_42__Syms* symsp, const char* v__name);
    ~Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9();
    VL_UNCOPYABLE(Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
