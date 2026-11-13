// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_rtnn_c2_soc_42.h for the primary calling header

#ifndef VERILATED_VTB_RTNN_C2_SOC_42___024ROOT_H_
#define VERILATED_VTB_RTNN_C2_SOC_42___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9;
class Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8;
class Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7;


class Vtb_rtnn_c2_soc_42__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_rtnn_c2_soc_42___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* __PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i;
    Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* __PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i;
    Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9* __PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i;
    Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* __PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__if_stage_i;
    Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* __PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__id_stage_i;
    Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9* __PVT__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_lockstep__DOT__u_ibex_lockstep__DOT__u_shadow_core__DOT__cs_registers_i;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__clk;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__tck;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__rst_n;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__trst_n;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_released;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__tdi;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__capture_dr;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__shift_dr;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__update_dr;
        CData/*2:0*/ tb_rtnn_c2_soc_42__DOT__ir;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__tdo;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__request_valid;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__request_accept;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__response_commit;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__bus_fault;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__req_toggle_guard;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__req_guard_active;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__rsp_sys_guard_active;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__rsp_tck_guard_active;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__rsp_pending_seen;
        CData/*7:0*/ tb_rtnn_c2_soc_42__DOT__unnamedblk12__DOT__s;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT____Vlvbound_hbf14d360__0;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_capture_pending_sys_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_capture_pending_tck_q;
        CData/*7:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__status_shift_tck_q;
        CData/*1:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_release_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_toggle_tck_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_sync1_sys_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_sync2_sys_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_seen_sys_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_ack_toggle_sys_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_ack_sync1_tck_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_ack_sync2_tck_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_toggle_sys_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_sync1_tck_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_sync2_tck_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_seen_tck_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_consume_toggle_tck_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_consume_sync1_sys_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_consume_sync2_sys_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__busy_sys_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__error_sys_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sys_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__busy_sync1_tck_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__busy_sync2_tck_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__error_sync1_tck_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__error_sync2_tck_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sync1_tck_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__done_sync2_tck_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__pending_tck_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__response_pending_tck_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__protocol_error_tck_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__instr_hit;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__instr_err_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_err_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__ram_data_hit;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__ram_instr_rvalid;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_access_err;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__mmio_read_valid;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__mmio_write_valid;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__ram_dreq;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_ram_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_valid_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_commit_match;
    };
    struct {
        CData/*7:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vlvbound_hd6210828__0;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vlvbound_h11b922a8__0;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__data_hit_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__instr_hit_q;
        CData/*1:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_we_ex;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_load_err;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_store_err;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_addr_incr_req;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_wb;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_lsu;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_valid;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_resp_valid;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__data_req_out;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__perf_instr_ret_wb;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__perf_load;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__perf_store;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift1;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift2;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift3;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_b_negate;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_signed;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_left;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_valid;
        CData/*4:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_q;
        CData/*4:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_d;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_hold;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_hold;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_d;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_en_internal;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal;
        CData/*2:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q;
        CData/*2:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_d;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_d;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ctrl_update;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_update;
        CData/*1:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q;
        CData/*1:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_type_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q;
        CData/*3:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_be;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__split_misaligned_access;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_d;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_q;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_d;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_or_pmp_err;
        CData/*2:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs;
        CData/*2:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns;
        CData/*1:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__ecc_err;
        CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT____VdfgTmp_h3fd48639__0;
        CData/*6:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o;
        CData/*0:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__done;
        CData/*7:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__stop;
        CData/*0:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__172__Vfuncout;
        CData/*0:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__173__Vfuncout;
        CData/*0:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__176__Vfuncout;
        CData/*0:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__178__Vfuncout;
    };
    struct {
        CData/*0:0*/ __Vdlyvval__tb_rtnn_c2_soc_42__DOT__tck__v0;
        CData/*0:0*/ __Vdlyvset__tb_rtnn_c2_soc_42__DOT__tck__v0;
        CData/*0:0*/ __Vdlyvval__tb_rtnn_c2_soc_42__DOT__clk__v0;
        CData/*0:0*/ __Vdlyvset__tb_rtnn_c2_soc_42__DOT__clk__v0;
        CData/*0:0*/ __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__response_pending_tck_q;
        CData/*0:0*/ __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_toggle_tck_q;
        CData/*0:0*/ __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_consume_toggle_tck_q;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__en_wb_o__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i____PVT__instr_executing_spec__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__id_in_ready_o__0;
        CData/*0:0*/ __VstlDidInit;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__en_wb_o__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i____PVT__instr_executing_spec__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__id_in_ready_o__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__tck__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__trst_n__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__rst_n__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_released__0;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
        SData/*10:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_count_tck_q;
        SData/*10:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_count_tck_q;
        SData/*15:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__data_idx;
        SData/*15:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__instr_idx;
        SData/*15:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_op_a;
        SData/*15:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_op_b;
        SData/*15:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__budget;
        VlWide<25>/*799:0*/ tb_rtnn_c2_soc_42__DOT__request_data;
        VlWide<12>/*383:0*/ tb_rtnn_c2_soc_42__DOT__response_data;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__case_limit;
        VlWide<25>/*799:0*/ tb_rtnn_c2_soc_42__DOT__req_hold_guard;
        VlWide<12>/*383:0*/ tb_rtnn_c2_soc_42__DOT__rsp_sys_guard;
        VlWide<12>/*383:0*/ tb_rtnn_c2_soc_42__DOT__rsp_tck_guard;
        VlWide<25>/*799:0*/ tb_rtnn_c2_soc_42__DOT__unnamedblk11__DOT__bad_model;
        VlWide<25>/*799:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q;
        VlWide<25>/*799:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q;
        VlWide<12>/*383:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q;
        VlWide<12>/*383:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_hold_tck_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__build_shift_tck_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__mmio_read_data_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__data_ram_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__instr_ram_q;
        VlWide<3>/*67:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_d_ex;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_a;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_wdata_wb;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_result;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_d;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_d;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_remainder;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_last_q;
        IData/*23:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_rdata_ext;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__1__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__2__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__3__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__4__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__5__KET____DOT__rf_reg_q;
    };
    struct {
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__6__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__7__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__8__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__9__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__10__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__11__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__12__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__13__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__14__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__15__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__16__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__17__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__18__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__19__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__20__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__21__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__22__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__23__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__24__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__25__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__26__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__27__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__28__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__29__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__30__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__31__KET____DOT__rf_reg_q;
        IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_dummy_r0__DOT__rf_r0_q;
        VlWide<12>/*383:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__34__got;
        VlWide<12>/*383:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__69__got;
        VlWide<7>/*223:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__prefix;
        IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__crc32_req_header__104__c;
        IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__index;
        IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__unnamedblk10__DOT__n;
        IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__seq;
        IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__mode;
        IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__iid;
        IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__admit;
        IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__exec_exit;
        IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__pred;
        IData/*31:0*/ __Vtask_tb_rtnn_c2_soc_42__DOT__run_case__155__label;
        IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__172__a;
        IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__173__a;
        IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__176__a;
        IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__178__a;
        VlWide<25>/*799:0*/ __Vdly__tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_hold_tck_q;
        IData/*31:0*/ __VactIterCount;
        QData/*47:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_byte_written_q;
        QData/*38:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core;
        QData/*38:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core;
        QData/*32:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b;
        QData/*32:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a;
        QData/*33:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext;
        QData/*33:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d;
        QData/*32:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_quotient;
        QData/*33:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult1_res_uns;
        QData/*34:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand1_ext;
        QData/*38:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf;
        VlUnpacked<VlWide<25>/*799:0*/, 42> tb_rtnn_c2_soc_42__DOT__requests;
        VlUnpacked<VlWide<9>/*287:0*/, 42> tb_rtnn_c2_soc_42__DOT__expected;
        VlUnpacked<IData/*31:0*/, 12> tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q;
        VlUnpacked<CData/*7:0*/, 65536> tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem0;
        VlUnpacked<CData/*7:0*/, 65536> tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem1;
        VlUnpacked<CData/*7:0*/, 65536> tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem2;
        VlUnpacked<CData/*7:0*/, 65536> tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__mem3;
    };
    struct {
        VlUnpacked<IData/*31:0*/, 32> tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg;
    };
    std::string __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__34__tag;
    std::string __Vtask_tb_rtnn_c2_soc_42__DOT__expect_error_request__69__tag;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h23c93641__0;
    VlTriggerScheduler __VtrigSched_h6e9b7ca3__0;
    VlTriggerScheduler __VtrigSched_h23c93590__0;
    VlTriggerVec<4> __VstlTriggered;
    VlTriggerVec<10> __VactTriggered;
    VlTriggerVec<10> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_rtnn_c2_soc_42__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_rtnn_c2_soc_42___024root(Vtb_rtnn_c2_soc_42__Syms* symsp, const char* v__name);
    ~Vtb_rtnn_c2_soc_42___024root();
    VL_UNCOPYABLE(Vtb_rtnn_c2_soc_42___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
