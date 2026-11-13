// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rtnn_c2_soc_42.h for the primary calling header

#include "Vtb_rtnn_c2_soc_42__pch.h"
#include "Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9.h"

VL_ATTR_COLD void Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___ctor_var_reset(Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___ctor_var_reset\n"); );
    // Body
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->rst_ni = VL_RAND_RESET_I(1);
    vlSelf->hart_id_i = VL_RAND_RESET_I(32);
    vlSelf->priv_mode_id_o = VL_RAND_RESET_I(2);
    vlSelf->priv_mode_lsu_o = VL_RAND_RESET_I(2);
    vlSelf->csr_mstatus_tw_o = VL_RAND_RESET_I(1);
    vlSelf->csr_mtvec_o = VL_RAND_RESET_I(32);
    vlSelf->csr_mtvec_init_i = VL_RAND_RESET_I(1);
    vlSelf->boot_addr_i = VL_RAND_RESET_I(32);
    vlSelf->csr_access_i = VL_RAND_RESET_I(1);
    vlSelf->csr_addr_i = VL_RAND_RESET_I(12);
    vlSelf->csr_wdata_i = VL_RAND_RESET_I(32);
    vlSelf->csr_op_i = VL_RAND_RESET_I(2);
    vlSelf->csr_op_en_i = VL_RAND_RESET_I(1);
    vlSelf->csr_rdata_o = VL_RAND_RESET_I(32);
    vlSelf->irq_software_i = VL_RAND_RESET_I(1);
    vlSelf->irq_timer_i = VL_RAND_RESET_I(1);
    vlSelf->irq_external_i = VL_RAND_RESET_I(1);
    vlSelf->irq_fast_i = VL_RAND_RESET_I(15);
    vlSelf->nmi_mode_i = VL_RAND_RESET_I(1);
    vlSelf->irq_pending_o = VL_RAND_RESET_I(1);
    vlSelf->irqs_o = VL_RAND_RESET_I(18);
    vlSelf->csr_mstatus_mie_o = VL_RAND_RESET_I(1);
    vlSelf->csr_mepc_o = VL_RAND_RESET_I(32);
    vlSelf->csr_mtval_o = VL_RAND_RESET_I(32);
    vlSelf->__PVT__csr_pmp_cfg_o = VL_RAND_RESET_I(24);
    vlSelf->__PVT__csr_pmp_addr_o[0] = 0U;
    vlSelf->__PVT__csr_pmp_addr_o[1] = 0U;
    vlSelf->__PVT__csr_pmp_addr_o[2] = 0U;
    vlSelf->__PVT__csr_pmp_addr_o[3] = 0U;
    vlSelf->__PVT__csr_pmp_addr_o[4] = 0U;
    vlSelf->__PVT__csr_pmp_mseccfg_o = VL_RAND_RESET_I(3);
    vlSelf->debug_mode_i = VL_RAND_RESET_I(1);
    vlSelf->debug_mode_entering_i = VL_RAND_RESET_I(1);
    vlSelf->debug_cause_i = VL_RAND_RESET_I(3);
    vlSelf->debug_csr_save_i = VL_RAND_RESET_I(1);
    vlSelf->csr_depc_o = VL_RAND_RESET_I(32);
    vlSelf->debug_single_step_o = VL_RAND_RESET_I(1);
    vlSelf->debug_ebreakm_o = VL_RAND_RESET_I(1);
    vlSelf->debug_ebreaku_o = VL_RAND_RESET_I(1);
    vlSelf->__PVT__trigger_match_o = VL_RAND_RESET_I(1);
    vlSelf->pc_if_i = VL_RAND_RESET_I(32);
    vlSelf->pc_id_i = VL_RAND_RESET_I(32);
    vlSelf->pc_wb_i = VL_RAND_RESET_I(32);
    vlSelf->data_ind_timing_o = VL_RAND_RESET_I(1);
    vlSelf->dummy_instr_en_o = VL_RAND_RESET_I(1);
    vlSelf->dummy_instr_mask_o = VL_RAND_RESET_I(3);
    vlSelf->dummy_instr_seed_en_o = VL_RAND_RESET_I(1);
    vlSelf->dummy_instr_seed_o = VL_RAND_RESET_I(32);
    vlSelf->icache_enable_o = VL_RAND_RESET_I(1);
    vlSelf->csr_shadow_err_o = VL_RAND_RESET_I(1);
    vlSelf->ic_scr_key_valid_i = VL_RAND_RESET_I(1);
    vlSelf->mcounteren_writable_i = VL_RAND_RESET_I(4);
    vlSelf->csr_save_if_i = VL_RAND_RESET_I(1);
    vlSelf->csr_save_id_i = VL_RAND_RESET_I(1);
    vlSelf->csr_save_wb_i = VL_RAND_RESET_I(1);
    vlSelf->csr_restore_mret_i = VL_RAND_RESET_I(1);
    vlSelf->csr_restore_dret_i = VL_RAND_RESET_I(1);
    vlSelf->csr_save_cause_i = VL_RAND_RESET_I(1);
    vlSelf->csr_mcause_i = VL_RAND_RESET_I(7);
    vlSelf->csr_mtval_i = VL_RAND_RESET_I(32);
    vlSelf->illegal_csr_insn_o = VL_RAND_RESET_I(1);
    vlSelf->double_fault_seen_o = VL_RAND_RESET_I(1);
    vlSelf->instr_ret_i = VL_RAND_RESET_I(1);
    vlSelf->instr_ret_compressed_i = VL_RAND_RESET_I(1);
    vlSelf->instr_ret_spec_i = VL_RAND_RESET_I(1);
    vlSelf->instr_ret_compressed_spec_i = VL_RAND_RESET_I(1);
    vlSelf->iside_wait_i = VL_RAND_RESET_I(1);
    vlSelf->jump_i = VL_RAND_RESET_I(1);
    vlSelf->branch_i = VL_RAND_RESET_I(1);
    vlSelf->branch_taken_i = VL_RAND_RESET_I(1);
    vlSelf->mem_load_i = VL_RAND_RESET_I(1);
    vlSelf->mem_store_i = VL_RAND_RESET_I(1);
    vlSelf->dside_wait_i = VL_RAND_RESET_I(1);
    vlSelf->mul_wait_i = VL_RAND_RESET_I(1);
    vlSelf->div_wait_i = VL_RAND_RESET_I(1);
    vlSelf->__PVT__priv_lvl_q = VL_RAND_RESET_I(2);
    vlSelf->__PVT__priv_lvl_d = VL_RAND_RESET_I(2);
    vlSelf->__PVT__mstatus_d = VL_RAND_RESET_I(6);
    vlSelf->__PVT__mstatus_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__mie_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__mscratch_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__mepc_d = VL_RAND_RESET_I(32);
    vlSelf->__PVT__mepc_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__mcause_d = VL_RAND_RESET_I(7);
    vlSelf->__PVT__mcause_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__mtval_d = VL_RAND_RESET_I(32);
    vlSelf->__PVT__mtval_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__mtvec_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__dcsr_d = VL_RAND_RESET_I(32);
    vlSelf->__PVT__dcsr_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__depc_d = VL_RAND_RESET_I(32);
    vlSelf->__PVT__depc_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__dscratch0_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__dscratch1_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__mstack_en = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->__PVT__pmp_addr_rdata[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->__PVT__pmp_cfg_rdata[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->__PVT__mcountinhibit_d = VL_RAND_RESET_I(3);
    vlSelf->__PVT__mcountinhibit_q = VL_RAND_RESET_I(3);
    vlSelf->__PVT__mcounteren_d = VL_RAND_RESET_I(3);
    vlSelf->__PVT__mcounteren_we = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__PVT__mhpmcounter[__Vi0] = VL_RAND_RESET_Q(64);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__PVT__mhpmevent[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__cpuctrlsts_part_d = VL_RAND_RESET_I(8);
    vlSelf->__PVT__cpuctrlsts_part_we = VL_RAND_RESET_I(1);
    vlSelf->__PVT__csr_wdata_int = VL_RAND_RESET_I(32);
    vlSelf->__PVT__csr_rdata_int = VL_RAND_RESET_I(32);
    vlSelf->__PVT__csr_we_int = VL_RAND_RESET_I(1);
    vlSelf->__PVT__csr_wr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__dbg_csr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__illegal_csr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__u_mstatus_csr__DOT__rdata_q = VL_RAND_RESET_I(6);
    vlSelf->__PVT__u_mepc_csr__DOT__rdata_q = VL_RAND_RESET_I(32);
    vlSelf->__PVT__u_mie_csr__DOT__rdata_q = VL_RAND_RESET_I(18);
    vlSelf->__PVT__u_mscratch_csr__DOT__rdata_q = VL_RAND_RESET_I(32);
    vlSelf->__PVT__u_mcause_csr__DOT__rdata_q = VL_RAND_RESET_I(7);
    vlSelf->__PVT__u_mtval_csr__DOT__rdata_q = VL_RAND_RESET_I(32);
    vlSelf->__PVT__u_mtvec_csr__DOT__rdata_q = VL_RAND_RESET_I(32);
    vlSelf->__PVT__u_dcsr_csr__DOT__rdata_q = VL_RAND_RESET_I(32);
    vlSelf->__PVT__u_depc_csr__DOT__rdata_q = VL_RAND_RESET_I(32);
    vlSelf->__PVT__u_dscratch0_csr__DOT__rdata_q = VL_RAND_RESET_I(32);
    vlSelf->__PVT__u_dscratch1_csr__DOT__rdata_q = VL_RAND_RESET_I(32);
    vlSelf->__PVT__u_mstack_csr__DOT__rdata_q = VL_RAND_RESET_I(3);
    vlSelf->__PVT__u_mstack_epc_csr__DOT__rdata_q = VL_RAND_RESET_I(32);
    vlSelf->__PVT__u_mstack_cause_csr__DOT__rdata_q = VL_RAND_RESET_I(7);
    vlSelf->__PVT__mcycle_counter_i__DOT__counter_d = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__mcycle_counter_i__DOT__counter_q = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__minstret_counter_i__DOT__counter_d = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__minstret_counter_i__DOT__counter_q = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__u_mcounteren_csr__DOT__rdata_q = VL_RAND_RESET_I(3);
    vlSelf->__PVT__u_cpuctrlsts_part_csr__DOT__rdata_q = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sv2v_cast_2__0__Vfuncout = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_sv2v_cast_2__0__inp = VL_RAND_RESET_I(2);
}
