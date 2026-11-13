// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rtnn_c2_soc_42.h for the primary calling header

#include "Vtb_rtnn_c2_soc_42__pch.h"
#include "Vtb_rtnn_c2_soc_42__Syms.h"
#include "Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7.h"

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__0(Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__0\n"); );
    // Init
    IData/*31:0*/ __PVT__instr_decompressed;
    __PVT__instr_decompressed = 0;
    IData/*31:0*/ __PVT__exc_pc;
    __PVT__exc_pc = 0;
    CData/*4:0*/ __PVT__irq_vec;
    __PVT__irq_vec = 0;
    CData/*0:0*/ __VdfgTmp_h3d81f5b8__0;
    __VdfgTmp_h3d81f5b8__0 = 0;
    CData/*1:0*/ __PVT__compressed_decoder_i__DOT__gets_expanded;
    __PVT__compressed_decoder_i__DOT__gets_expanded = 0;
    CData/*0:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_new_req;
    __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_new_req = 0;
    CData/*0:0*/ gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_he9db8f89__0;
    gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_he9db8f89__0 = 0;
    CData/*0:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo;
    __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo = 0;
    CData/*0:0*/ __PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_en;
    __PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_en = 0;
    // Body
    __PVT__irq_vec = (0x1fU & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.exc_cause_o));
    if ((0x40U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.exc_cause_o))) {
        __PVT__irq_vec = 0x1fU;
    }
    __PVT__exc_pc = ((2U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.exc_pc_mux_o))
                      ? 0x100000U : ((1U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.exc_pc_mux_o))
                                      ? ((0xffffff00U 
                                          & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_mtvec_csr__DOT__rdata_q) 
                                         | ((IData)(__PVT__irq_vec) 
                                            << 2U))
                                      : (0xffffff00U 
                                         & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_mtvec_csr__DOT__rdata_q)));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__discard_req_d 
        = ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_req_q) 
           & ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o) 
              | (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__discard_req_q)));
    __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_new_req 
        = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.instr_req_o) 
           & ((~ ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q) 
                  >> 1U)) & ((~ (IData)((3U == (3U 
                                                & (((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                                                    >> 1U) 
                                                   | ((2U 
                                                       & ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q) 
                                                          << 1U)) 
                                                      | (1U 
                                                         & ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q) 
                                                            >> 1U)))))))) 
                             | (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o))));
    vlSelf->csr_mtvec_init_o = ((0U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_mux_o)) 
                                & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o));
    __PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_en 
        = ((IData)(vlSelf->__PVT__gen_dummy_instr__DOT__insert_dummy_instr) 
           & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.id_in_ready_o));
    vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i 
        = ((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o)) 
           & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.id_in_ready_o));
    vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_hfddf9e70__0 
        = ((~ (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_req_q)) 
           & (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_new_req));
    vlSelf->instr_req_o = ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_req_q) 
                           | (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_new_req));
    vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_d 
        = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.dummy_instr_seed_en_o)
            ? vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_instr_seed_d
            : (((~ (IData)((0U != vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q))) 
                & (IData)(__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_en))
                ? 0xac533bf4U : ((IData)(__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_en)
                                  ? ((0x80200003U & 
                                      (- (IData)((1U 
                                                  & vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q)))) 
                                     ^ VL_SHIFTR_III(32,32,32, vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q, 1U))
                                  : vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q)));
    vlSelf->__PVT__instr_new_id_d = ((IData)(vlSelf->__PVT__fetch_valid_raw) 
                                     & (IData)(vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i));
    __PVT__instr_decompressed = vlSelf->__PVT__fetch_rdata;
    vlSelf->__PVT__illegal_c_insn = 0U;
    __PVT__compressed_decoder_i__DOT__gets_expanded = 0U;
    vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d 
        = vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_q;
    vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d 
        = vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_q;
    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d 
        = vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q;
    vlSelf->__PVT__prefetch_addr = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o)
                                     ? (0xfffffffeU 
                                        & ((4U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_mux_o))
                                            ? ((2U 
                                                & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_mux_o))
                                                ? 0x100080U
                                                : (
                                                   (1U 
                                                    & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_mux_o))
                                                    ? 0x100080U
                                                    : vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_depc_csr__DOT__rdata_q))
                                            : ((2U 
                                                & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_mux_o))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_mux_o))
                                                    ? vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_mepc_csr__DOT__rdata_q
                                                    : __PVT__exc_pc)
                                                : (
                                                   (1U 
                                                    & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_mux_o))
                                                    ? (IData)(
                                                              (vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                               >> 1U))
                                                    : 0x100080U))))
                                     : 0U);
    if ((2U & vlSelf->__PVT__fetch_rdata)) {
        if ((1U & (~ vlSelf->__PVT__fetch_rdata))) {
            if ((0x8000U & vlSelf->__PVT__fetch_rdata)) {
                if ((0x4000U & vlSelf->__PVT__fetch_rdata)) {
                    if ((0x2000U & vlSelf->__PVT__fetch_rdata)) {
                        vlSelf->__PVT__illegal_c_insn = 1U;
                    } else {
                        __PVT__instr_decompressed = 
                            (0x12023U | ((0xc000000U 
                                          & (vlSelf->__PVT__fetch_rdata 
                                             << 0x13U)) 
                                         | ((0x2000000U 
                                             & (vlSelf->__PVT__fetch_rdata 
                                                << 0xdU)) 
                                            | ((0x1f00000U 
                                                & (vlSelf->__PVT__fetch_rdata 
                                                   << 0x12U)) 
                                               | (0xe00U 
                                                  & vlSelf->__PVT__fetch_rdata)))));
                    }
                } else if ((0x2000U & vlSelf->__PVT__fetch_rdata)) {
                    if ((0x1000U & vlSelf->__PVT__fetch_rdata)) {
                        if ((0x800U & vlSelf->__PVT__fetch_rdata)) {
                            if ((0x400U & vlSelf->__PVT__fetch_rdata)) {
                                if ((0x100U & vlSelf->__PVT__fetch_rdata)) {
                                    vlSelf->__PVT__illegal_c_insn = 1U;
                                } else {
                                    __PVT__compressed_decoder_i__DOT__gets_expanded = 1U;
                                    if ((4U & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                        if ((2U & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                            if ((1U 
                                                 & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                            } else {
                                                __PVT__instr_decompressed = 0x8067U;
                                                if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                    __PVT__compressed_decoder_i__DOT__gets_expanded = 3U;
                                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                                }
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                            __PVT__compressed_decoder_i__DOT__gets_expanded = 2U;
                                            if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 6U;
                                            }
                                            __PVT__instr_decompressed = 0x513U;
                                        } else {
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__spimm 
                                                = (3U 
                                                   & (vlSelf->__PVT__fetch_rdata 
                                                      >> 2U));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__rlist 
                                                = (0xfU 
                                                   & (vlSelf->__PVT__fetch_rdata 
                                                      >> 4U));
                                            __PVT__compressed_decoder_i__DOT__gets_expanded = 2U;
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__imm 
                                                = (0x7fU 
                                                   & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__imm));
                                            if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                if (
                                                    (0x1cU 
                                                     == 
                                                     (0x1fU 
                                                      & (vlSelf->__PVT__fetch_rdata 
                                                         >> 8U)))) {
                                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 5U;
                                                } else if (
                                                           (0x1eU 
                                                            == 
                                                            (0x1fU 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                >> 8U)))) {
                                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 6U;
                                                } else {
                                                    __PVT__compressed_decoder_i__DOT__gets_expanded = 3U;
                                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                                }
                                            }
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__4__spimm 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__spimm;
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__4__rlist 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__rlist;
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__4__Vfuncout 
                                                = (0x7fU 
                                                   & (([&]() {
                                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__5__rlist 
                                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__4__rlist;
                                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__5__Vfuncout 
                                                                = 
                                                                ((8U 
                                                                  & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__5__rlist))
                                                                  ? 
                                                                 ((4U 
                                                                   & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__5__rlist))
                                                                   ? 
                                                                  ((2U 
                                                                    & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__5__rlist))
                                                                    ? 
                                                                   ((1U 
                                                                     & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__5__rlist))
                                                                     ? 0x40U
                                                                     : 0x30U)
                                                                    : 0x30U)
                                                                   : 0x20U)
                                                                  : 
                                                                 ((4U 
                                                                   & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__5__rlist))
                                                                   ? 0x10U
                                                                   : 0U));
                                                        }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__5__Vfuncout)) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__4__spimm), 4U)));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__imm 
                                                = (
                                                   (0xf80U 
                                                    & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__imm)) 
                                                   | (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__4__Vfuncout));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__imm_signed 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__imm;
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__instr 
                                                = (0x10113U 
                                                   | ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__imm_signed) 
                                                      << 0x14U));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__Vfuncout 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__instr;
                                            __PVT__instr_decompressed 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__Vfuncout;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                        if ((1U & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__sp_offset 
                                                = vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_q;
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__rlist 
                                                = vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_q;
                                            if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d 
                                                    = 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_q) 
                                                        - (IData)(1U)));
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d 
                                                    = 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_q) 
                                                        - (IData)(1U)));
                                                if (
                                                    (4U 
                                                     == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_q))) {
                                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 4U;
                                                }
                                            }
                                            VL_ASSIGNSEL_II(32,12,0U, vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__instr, 
                                                            (3U 
                                                             | (([&]() {
                                                                vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist 
                                                                    = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__rlist;
                                                                vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__Vfuncout 
                                                                    = 
                                                                    (0x1fU 
                                                                     & ((0x10U 
                                                                         & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                         ? 
                                                                        ((8U 
                                                                          & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                          ? 0U
                                                                          : 
                                                                         ((4U 
                                                                           & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                           ? 0U
                                                                           : 
                                                                          ((2U 
                                                                            & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                            ? 0U
                                                                            : 
                                                                           ((1U 
                                                                             & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                             ? 0U
                                                                             : 
                                                                            ((IData)(0xbU) 
                                                                             + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))))))
                                                                         : 
                                                                        ((8U 
                                                                          & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                          ? 
                                                                         ((IData)(0xbU) 
                                                                          + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                          : 
                                                                         ((4U 
                                                                           & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                           ? 
                                                                          ((2U 
                                                                            & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                            ? 
                                                                           ((1U 
                                                                             & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                             ? 
                                                                            ((IData)(0xbU) 
                                                                             + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                             : 
                                                                            ((IData)(3U) 
                                                                             + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist)))
                                                                            : 
                                                                           ((1U 
                                                                             & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                             ? 
                                                                            ((IData)(3U) 
                                                                             + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                             : 1U))
                                                                           : 0U))));
                                                            }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__Vfuncout)) 
                                                                << 7U)));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__instr 
                                                = (0x12000U 
                                                   | ((0xfffU 
                                                       & vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__instr) 
                                                      | ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__sp_offset) 
                                                         << 0x16U)));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__Vfuncout 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__instr;
                                            __PVT__instr_decompressed 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__Vfuncout;
                                        } else {
                                            vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                    } else {
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__8__instr_rlist 
                                            = (0xfU 
                                               & (vlSelf->__PVT__fetch_rdata 
                                                  >> 4U));
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__8__rlist 
                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__8__instr_rlist;
                                        if ((0xfU == (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__8__rlist))) {
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__8__rlist = 0x10U;
                                        }
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__8__Vfuncout 
                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__8__rlist;
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d 
                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__8__Vfuncout;
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d 
                                            = (0x1fU 
                                               & (([&]() {
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__9__spimm 
                                                            = 
                                                            (3U 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                >> 2U));
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__9__rlist 
                                                            = 
                                                            (0xfU 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                >> 4U));
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__10__spimm 
                                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__9__spimm;
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__10__rlist 
                                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__9__rlist;
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__10__Vfuncout 
                                                            = 
                                                            (0x7fU 
                                                             & (([&]() {
                                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__11__rlist 
                                                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__10__rlist;
                                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__11__Vfuncout 
                                                                            = 
                                                                            ((8U 
                                                                              & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__11__rlist))
                                                                              ? 
                                                                             ((4U 
                                                                               & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__11__rlist))
                                                                               ? 
                                                                              ((2U 
                                                                                & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__11__rlist))
                                                                                ? 
                                                                               ((1U 
                                                                                & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__11__rlist))
                                                                                 ? 0x40U
                                                                                 : 0x30U)
                                                                                : 0x30U)
                                                                               : 0x20U)
                                                                              : 
                                                                             ((4U 
                                                                               & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__11__rlist))
                                                                               ? 0x10U
                                                                               : 0U));
                                                                    }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__11__Vfuncout)) 
                                                                + 
                                                                VL_SHIFTL_III(7,32,32, (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__10__spimm), 4U)));
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__9__tmp 
                                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__10__Vfuncout;
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__9__Vfuncout 
                                                            = 
                                                            (0x1fU 
                                                             & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__9__tmp) 
                                                                >> 2U));
                                                    }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__9__Vfuncout)) 
                                                  - (IData)(1U)));
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__sp_offset 
                                            = vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d;
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__rlist 
                                            = vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d;
                                        VL_ASSIGNSEL_II(32,12,0U, vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__instr, 
                                                        (3U 
                                                         | (([&]() {
                                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist 
                                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__rlist;
                                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__Vfuncout 
                                                                = 
                                                                (0x1fU 
                                                                 & ((0x10U 
                                                                     & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                     ? 
                                                                    ((8U 
                                                                      & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                      ? 0U
                                                                      : 
                                                                     ((4U 
                                                                       & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                       ? 0U
                                                                       : 
                                                                      ((2U 
                                                                        & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                        ? 0U
                                                                        : 
                                                                       ((1U 
                                                                         & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                         ? 0U
                                                                         : 
                                                                        ((IData)(0xbU) 
                                                                         + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))))))
                                                                     : 
                                                                    ((8U 
                                                                      & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                      ? 
                                                                     ((IData)(0xbU) 
                                                                      + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                      : 
                                                                     ((4U 
                                                                       & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                       ? 
                                                                      ((2U 
                                                                        & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                        ? 
                                                                       ((1U 
                                                                         & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                         ? 
                                                                        ((IData)(0xbU) 
                                                                         + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                         : 
                                                                        ((IData)(3U) 
                                                                         + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist)))
                                                                        : 
                                                                       ((1U 
                                                                         & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                         ? 
                                                                        ((IData)(3U) 
                                                                         + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                         : 1U))
                                                                       : 0U))));
                                                        }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__Vfuncout)) 
                                                            << 7U)));
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__instr 
                                            = (0x12000U 
                                               | ((0xfffU 
                                                   & vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__instr) 
                                                  | ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__sp_offset) 
                                                     << 0x16U)));
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__Vfuncout 
                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__instr;
                                        __PVT__instr_decompressed 
                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__Vfuncout;
                                        if ((3U >= (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d))) {
                                            vlSelf->__PVT__illegal_c_insn = 1U;
                                        } else if (
                                                   (4U 
                                                    == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d))) {
                                            if (((IData)(vlSelf->__Vcellinp__compressed_decoder_i__valid_i) 
                                                 & (IData)(vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 4U;
                                            }
                                        } else {
                                            vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d 
                                                = (0x1fU 
                                                   & ((IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d) 
                                                      - (IData)(1U)));
                                            vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d 
                                                = (0x1fU 
                                                   & ((IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d) 
                                                      - (IData)(1U)));
                                            if (((IData)(vlSelf->__Vcellinp__compressed_decoder_i__valid_i) 
                                                 & (IData)(vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 3U;
                                            }
                                        }
                                    }
                                }
                            } else if ((0x200U & vlSelf->__PVT__fetch_rdata)) {
                                if ((0x100U & vlSelf->__PVT__fetch_rdata)) {
                                    vlSelf->__PVT__illegal_c_insn = 1U;
                                } else {
                                    __PVT__compressed_decoder_i__DOT__gets_expanded = 1U;
                                    if ((4U & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                        if ((2U & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                            if ((1U 
                                                 & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                            } else {
                                                __PVT__instr_decompressed = 0x8067U;
                                                if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                    __PVT__compressed_decoder_i__DOT__gets_expanded = 3U;
                                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                                }
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                            __PVT__compressed_decoder_i__DOT__gets_expanded = 2U;
                                            if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 6U;
                                            }
                                            __PVT__instr_decompressed = 0x513U;
                                        } else {
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__spimm 
                                                = (3U 
                                                   & (vlSelf->__PVT__fetch_rdata 
                                                      >> 2U));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__rlist 
                                                = (0xfU 
                                                   & (vlSelf->__PVT__fetch_rdata 
                                                      >> 4U));
                                            __PVT__compressed_decoder_i__DOT__gets_expanded = 2U;
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__imm 
                                                = (0x7fU 
                                                   & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__imm));
                                            if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                if (
                                                    (0x1cU 
                                                     == 
                                                     (0x1fU 
                                                      & (vlSelf->__PVT__fetch_rdata 
                                                         >> 8U)))) {
                                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 5U;
                                                } else if (
                                                           (0x1eU 
                                                            == 
                                                            (0x1fU 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                >> 8U)))) {
                                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 6U;
                                                } else {
                                                    __PVT__compressed_decoder_i__DOT__gets_expanded = 3U;
                                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                                }
                                            }
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__18__spimm 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__spimm;
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__18__rlist 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__rlist;
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__18__Vfuncout 
                                                = (0x7fU 
                                                   & (([&]() {
                                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__19__rlist 
                                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__18__rlist;
                                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__19__Vfuncout 
                                                                = 
                                                                ((8U 
                                                                  & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__19__rlist))
                                                                  ? 
                                                                 ((4U 
                                                                   & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__19__rlist))
                                                                   ? 
                                                                  ((2U 
                                                                    & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__19__rlist))
                                                                    ? 
                                                                   ((1U 
                                                                     & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__19__rlist))
                                                                     ? 0x40U
                                                                     : 0x30U)
                                                                    : 0x30U)
                                                                   : 0x20U)
                                                                  : 
                                                                 ((4U 
                                                                   & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__19__rlist))
                                                                   ? 0x10U
                                                                   : 0U));
                                                        }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__19__Vfuncout)) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__18__spimm), 4U)));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__imm 
                                                = (
                                                   (0xf80U 
                                                    & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__imm)) 
                                                   | (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__18__Vfuncout));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__imm_signed 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__imm;
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__instr 
                                                = (0x10113U 
                                                   | ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__imm_signed) 
                                                      << 0x14U));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__Vfuncout 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__instr;
                                            __PVT__instr_decompressed 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__Vfuncout;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                        if ((1U & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__sp_offset 
                                                = vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_q;
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__rlist 
                                                = vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_q;
                                            if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d 
                                                    = 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_q) 
                                                        - (IData)(1U)));
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d 
                                                    = 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_q) 
                                                        - (IData)(1U)));
                                                if (
                                                    (4U 
                                                     == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_q))) {
                                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 4U;
                                                }
                                            }
                                            VL_ASSIGNSEL_II(32,12,0U, vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__instr, 
                                                            (3U 
                                                             | (([&]() {
                                                                vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist 
                                                                    = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__rlist;
                                                                vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__Vfuncout 
                                                                    = 
                                                                    (0x1fU 
                                                                     & ((0x10U 
                                                                         & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                         ? 
                                                                        ((8U 
                                                                          & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                          ? 0U
                                                                          : 
                                                                         ((4U 
                                                                           & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                           ? 0U
                                                                           : 
                                                                          ((2U 
                                                                            & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                            ? 0U
                                                                            : 
                                                                           ((1U 
                                                                             & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                             ? 0U
                                                                             : 
                                                                            ((IData)(0xbU) 
                                                                             + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))))))
                                                                         : 
                                                                        ((8U 
                                                                          & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                          ? 
                                                                         ((IData)(0xbU) 
                                                                          + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                          : 
                                                                         ((4U 
                                                                           & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                           ? 
                                                                          ((2U 
                                                                            & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                            ? 
                                                                           ((1U 
                                                                             & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                             ? 
                                                                            ((IData)(0xbU) 
                                                                             + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                             : 
                                                                            ((IData)(3U) 
                                                                             + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist)))
                                                                            : 
                                                                           ((1U 
                                                                             & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                             ? 
                                                                            ((IData)(3U) 
                                                                             + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                             : 1U))
                                                                           : 0U))));
                                                            }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__Vfuncout)) 
                                                                << 7U)));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__instr 
                                                = (0x12000U 
                                                   | ((0xfffU 
                                                       & vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__instr) 
                                                      | ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__sp_offset) 
                                                         << 0x16U)));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__Vfuncout 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__instr;
                                            __PVT__instr_decompressed 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__Vfuncout;
                                        } else {
                                            vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                    } else {
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__22__instr_rlist 
                                            = (0xfU 
                                               & (vlSelf->__PVT__fetch_rdata 
                                                  >> 4U));
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__22__rlist 
                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__22__instr_rlist;
                                        if ((0xfU == (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__22__rlist))) {
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__22__rlist = 0x10U;
                                        }
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__22__Vfuncout 
                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__22__rlist;
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d 
                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__22__Vfuncout;
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d 
                                            = (0x1fU 
                                               & (([&]() {
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__23__spimm 
                                                            = 
                                                            (3U 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                >> 2U));
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__23__rlist 
                                                            = 
                                                            (0xfU 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                >> 4U));
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__24__spimm 
                                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__23__spimm;
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__24__rlist 
                                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__23__rlist;
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__24__Vfuncout 
                                                            = 
                                                            (0x7fU 
                                                             & (([&]() {
                                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__25__rlist 
                                                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__24__rlist;
                                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__25__Vfuncout 
                                                                            = 
                                                                            ((8U 
                                                                              & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__25__rlist))
                                                                              ? 
                                                                             ((4U 
                                                                               & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__25__rlist))
                                                                               ? 
                                                                              ((2U 
                                                                                & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__25__rlist))
                                                                                ? 
                                                                               ((1U 
                                                                                & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__25__rlist))
                                                                                 ? 0x40U
                                                                                 : 0x30U)
                                                                                : 0x30U)
                                                                               : 0x20U)
                                                                              : 
                                                                             ((4U 
                                                                               & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__25__rlist))
                                                                               ? 0x10U
                                                                               : 0U));
                                                                    }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__25__Vfuncout)) 
                                                                + 
                                                                VL_SHIFTL_III(7,32,32, (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__24__spimm), 4U)));
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__23__tmp 
                                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__24__Vfuncout;
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__23__Vfuncout 
                                                            = 
                                                            (0x1fU 
                                                             & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__23__tmp) 
                                                                >> 2U));
                                                    }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__23__Vfuncout)) 
                                                  - (IData)(1U)));
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__sp_offset 
                                            = vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d;
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__rlist 
                                            = vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d;
                                        VL_ASSIGNSEL_II(32,12,0U, vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__instr, 
                                                        (3U 
                                                         | (([&]() {
                                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist 
                                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__rlist;
                                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__Vfuncout 
                                                                = 
                                                                (0x1fU 
                                                                 & ((0x10U 
                                                                     & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                     ? 
                                                                    ((8U 
                                                                      & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                      ? 0U
                                                                      : 
                                                                     ((4U 
                                                                       & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                       ? 0U
                                                                       : 
                                                                      ((2U 
                                                                        & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                        ? 0U
                                                                        : 
                                                                       ((1U 
                                                                         & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                         ? 0U
                                                                         : 
                                                                        ((IData)(0xbU) 
                                                                         + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))))))
                                                                     : 
                                                                    ((8U 
                                                                      & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                      ? 
                                                                     ((IData)(0xbU) 
                                                                      + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                      : 
                                                                     ((4U 
                                                                       & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                       ? 
                                                                      ((2U 
                                                                        & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                        ? 
                                                                       ((1U 
                                                                         & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                         ? 
                                                                        ((IData)(0xbU) 
                                                                         + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                         : 
                                                                        ((IData)(3U) 
                                                                         + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist)))
                                                                        : 
                                                                       ((1U 
                                                                         & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                         ? 
                                                                        ((IData)(3U) 
                                                                         + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                         : 1U))
                                                                       : 0U))));
                                                        }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__Vfuncout)) 
                                                            << 7U)));
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__instr 
                                            = (0x12000U 
                                               | ((0xfffU 
                                                   & vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__instr) 
                                                  | ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__sp_offset) 
                                                     << 0x16U)));
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__Vfuncout 
                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__instr;
                                        __PVT__instr_decompressed 
                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__Vfuncout;
                                        if ((3U >= (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d))) {
                                            vlSelf->__PVT__illegal_c_insn = 1U;
                                        } else if (
                                                   (4U 
                                                    == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d))) {
                                            if (((IData)(vlSelf->__Vcellinp__compressed_decoder_i__valid_i) 
                                                 & (IData)(vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 4U;
                                            }
                                        } else {
                                            vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d 
                                                = (0x1fU 
                                                   & ((IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d) 
                                                      - (IData)(1U)));
                                            vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d 
                                                = (0x1fU 
                                                   & ((IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d) 
                                                      - (IData)(1U)));
                                            if (((IData)(vlSelf->__Vcellinp__compressed_decoder_i__valid_i) 
                                                 & (IData)(vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 3U;
                                            }
                                        }
                                    }
                                }
                            } else if ((0x100U & vlSelf->__PVT__fetch_rdata)) {
                                vlSelf->__PVT__illegal_c_insn = 1U;
                            } else {
                                __PVT__compressed_decoder_i__DOT__gets_expanded = 1U;
                                if ((0U == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__28__instr_rlist 
                                        = (0xfU & (vlSelf->__PVT__fetch_rdata 
                                                   >> 4U));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__28__rlist 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__28__instr_rlist;
                                    if ((0xfU == (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__28__rlist))) {
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__28__rlist = 0x10U;
                                    }
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__28__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__28__rlist;
                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__28__Vfuncout;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__29__rlist 
                                        = vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__29__instr 
                                        = (0x2e23U 
                                           | (0xffff8000U 
                                              & vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__29__instr));
                                    VL_ASSIGNSEL_II(32,10,0xfU, vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__29__instr, 
                                                    (2U 
                                                     | (([&]() {
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist 
                                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__29__rlist;
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__Vfuncout 
                                                            = 
                                                            (0x1fU 
                                                             & ((0x10U 
                                                                 & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                 ? 
                                                                ((8U 
                                                                  & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                  ? 0U
                                                                  : 
                                                                 ((4U 
                                                                   & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                   ? 0U
                                                                   : 
                                                                  ((2U 
                                                                    & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                    ? 0U
                                                                    : 
                                                                   ((1U 
                                                                     & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                     ? 0U
                                                                     : 
                                                                    ((IData)(0xbU) 
                                                                     + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))))))
                                                                 : 
                                                                ((8U 
                                                                  & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                  ? 
                                                                 ((IData)(0xbU) 
                                                                  + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                  : 
                                                                 ((4U 
                                                                   & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                   ? 
                                                                  ((2U 
                                                                    & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                    ? 
                                                                   ((1U 
                                                                     & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                     ? 
                                                                    ((IData)(0xbU) 
                                                                     + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                     : 
                                                                    ((IData)(3U) 
                                                                     + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist)))
                                                                    : 
                                                                   ((1U 
                                                                     & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                     ? 
                                                                    ((IData)(3U) 
                                                                     + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                     : 1U))
                                                                   : 0U))));
                                                    }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__Vfuncout)) 
                                                        << 5U)));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__29__instr 
                                        = (0xfe000000U 
                                           | vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__29__instr);
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__29__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__29__instr;
                                    __PVT__instr_decompressed 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__29__Vfuncout;
                                    if ((3U >= (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d))) {
                                        vlSelf->__PVT__illegal_c_insn = 1U;
                                    } else if ((4U 
                                                == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d))) {
                                        if (((IData)(vlSelf->__Vcellinp__compressed_decoder_i__valid_i) 
                                             & (IData)(vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                            vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 2U;
                                        }
                                    } else {
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d 
                                            = (0x1fU 
                                               & ((IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d) 
                                                  - (IData)(1U)));
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d = 2U;
                                        if (((IData)(vlSelf->__Vcellinp__compressed_decoder_i__valid_i) 
                                             & (IData)(vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                            vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 1U;
                                        }
                                    }
                                } else if ((1U == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__sp_offset 
                                        = vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_q;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__rlist 
                                        = vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_q;
                                    if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d 
                                            = (0x1fU 
                                               & ((IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_q) 
                                                  - (IData)(1U)));
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d 
                                            = (0x1fU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_q)));
                                        if ((4U == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_q))) {
                                            vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 2U;
                                        }
                                    }
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__neg_offset_signed 
                                        = (0xfffU & 
                                           (- ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__sp_offset) 
                                               << 2U)));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__neg_offset 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__neg_offset_signed;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__instr 
                                        = (0x2023U 
                                           | ((0xffff8000U 
                                               & vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__instr) 
                                              | (0xf80U 
                                                 & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__neg_offset) 
                                                    << 7U))));
                                    VL_ASSIGNSEL_II(32,10,0xfU, vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__instr, 
                                                    (2U 
                                                     | (([&]() {
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist 
                                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__rlist;
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__Vfuncout 
                                                            = 
                                                            (0x1fU 
                                                             & ((0x10U 
                                                                 & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                 ? 
                                                                ((8U 
                                                                  & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                  ? 0U
                                                                  : 
                                                                 ((4U 
                                                                   & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                   ? 0U
                                                                   : 
                                                                  ((2U 
                                                                    & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                    ? 0U
                                                                    : 
                                                                   ((1U 
                                                                     & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                     ? 0U
                                                                     : 
                                                                    ((IData)(0xbU) 
                                                                     + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))))))
                                                                 : 
                                                                ((8U 
                                                                  & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                  ? 
                                                                 ((IData)(0xbU) 
                                                                  + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                  : 
                                                                 ((4U 
                                                                   & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                   ? 
                                                                  ((2U 
                                                                    & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                    ? 
                                                                   ((1U 
                                                                     & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                     ? 
                                                                    ((IData)(0xbU) 
                                                                     + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                     : 
                                                                    ((IData)(3U) 
                                                                     + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist)))
                                                                    : 
                                                                   ((1U 
                                                                     & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                     ? 
                                                                    ((IData)(3U) 
                                                                     + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                     : 1U))
                                                                   : 0U))));
                                                    }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__Vfuncout)) 
                                                        << 5U)));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__instr 
                                        = ((0x1ffffffU 
                                            & vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__instr) 
                                           | (0xfe000000U 
                                              & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__neg_offset) 
                                                 << 0x14U)));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__instr;
                                    __PVT__instr_decompressed 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__Vfuncout;
                                } else if ((2U == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__spimm 
                                        = (3U & (vlSelf->__PVT__fetch_rdata 
                                                 >> 2U));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__rlist 
                                        = (0xfU & (vlSelf->__PVT__fetch_rdata 
                                                   >> 4U));
                                    if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                        __PVT__compressed_decoder_i__DOT__gets_expanded = 3U;
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                    }
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__imm 
                                        = (0x7fU & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__imm));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__34__spimm 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__spimm;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__34__rlist 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__rlist;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__34__Vfuncout 
                                        = (0x7fU & 
                                           (([&]() {
                                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__35__rlist 
                                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__34__rlist;
                                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__35__Vfuncout 
                                                        = 
                                                        ((8U 
                                                          & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__35__rlist))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__35__rlist))
                                                           ? 
                                                          ((2U 
                                                            & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__35__rlist))
                                                            ? 
                                                           ((1U 
                                                             & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__35__rlist))
                                                             ? 0x40U
                                                             : 0x30U)
                                                            : 0x30U)
                                                           : 0x20U)
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__35__rlist))
                                                           ? 0x10U
                                                           : 0U));
                                                }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__35__Vfuncout)) 
                                            + VL_SHIFTL_III(7,32,32, (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__34__spimm), 4U)));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__imm 
                                        = ((0xf80U 
                                            & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__imm)) 
                                           | (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__34__Vfuncout));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__imm_signed 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__imm;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__instr 
                                        = (0x10113U 
                                           | ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__imm_signed) 
                                              << 0x14U));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__instr;
                                    __PVT__instr_decompressed 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__Vfuncout;
                                } else {
                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                }
                            }
                        } else {
                            vlSelf->__PVT__illegal_c_insn = 1U;
                        }
                    } else if ((0x800U & vlSelf->__PVT__fetch_rdata)) {
                        if ((0x400U & vlSelf->__PVT__fetch_rdata)) {
                            if ((1U == (3U & (vlSelf->__PVT__fetch_rdata 
                                              >> 5U)))) {
                                __PVT__compressed_decoder_i__DOT__gets_expanded = 1U;
                                if ((0U == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__36__rs 
                                        = (7U & (vlSelf->__PVT__fetch_rdata 
                                                 >> 7U));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__36__dst 
                                        = (((0U < (3U 
                                                   & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__36__rs) 
                                                      >> 1U))) 
                                            << 4U) 
                                           | (((0U 
                                                == 
                                                (3U 
                                                 & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__36__rs) 
                                                    >> 1U))) 
                                               << 3U) 
                                              | (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__36__rs)));
                                    __PVT__compressed_decoder_i__DOT__gets_expanded = 2U;
                                    if (((IData)(vlSelf->__Vcellinp__compressed_decoder_i__valid_i) 
                                         & (IData)(vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 7U;
                                    }
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__37__dst 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__36__dst;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__37__instr 
                                        = (0x50013U 
                                           | ((0xfff00000U 
                                               & vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__37__instr) 
                                              | ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__37__dst) 
                                                 << 7U)));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__37__instr 
                                        = (0xfffffU 
                                           & vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__37__instr);
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__37__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__37__instr;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__36__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__37__Vfuncout;
                                    __PVT__instr_decompressed 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__36__Vfuncout;
                                } else if ((7U == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__38__rs 
                                        = (7U & (vlSelf->__PVT__fetch_rdata 
                                                 >> 2U));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__38__dst 
                                        = (((0U < (3U 
                                                   & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__38__rs) 
                                                      >> 1U))) 
                                            << 4U) 
                                           | (((0U 
                                                == 
                                                (3U 
                                                 & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__38__rs) 
                                                    >> 1U))) 
                                               << 3U) 
                                              | (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__38__rs)));
                                    if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                        __PVT__compressed_decoder_i__DOT__gets_expanded = 3U;
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                    }
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__39__dst 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__38__dst;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__39__instr 
                                        = (0x58013U 
                                           | ((0xfff00000U 
                                               & vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__39__instr) 
                                              | ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__39__dst) 
                                                 << 7U)));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__39__instr 
                                        = (0xfffffU 
                                           & vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__39__instr);
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__39__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__39__instr;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__38__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__39__Vfuncout;
                                    __PVT__instr_decompressed 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__38__Vfuncout;
                                } else {
                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                }
                            } else if ((3U == (3U & 
                                               (vlSelf->__PVT__fetch_rdata 
                                                >> 5U)))) {
                                __PVT__compressed_decoder_i__DOT__gets_expanded = 1U;
                                if ((0U == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__40__rs 
                                        = (7U & (vlSelf->__PVT__fetch_rdata 
                                                 >> 7U));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__40__src 
                                        = (((0U < (3U 
                                                   & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__40__rs) 
                                                      >> 1U))) 
                                            << 4U) 
                                           | (((0U 
                                                == 
                                                (3U 
                                                 & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__40__rs) 
                                                    >> 1U))) 
                                               << 3U) 
                                              | (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__40__rs)));
                                    __PVT__compressed_decoder_i__DOT__gets_expanded = 2U;
                                    if (((IData)(vlSelf->__Vcellinp__compressed_decoder_i__valid_i) 
                                         & (IData)(vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 7U;
                                    }
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__41__src 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__40__src;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__41__instr 
                                        = (0x513U | 
                                           ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__41__src) 
                                            << 0xfU));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__41__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__41__instr;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__40__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__41__Vfuncout;
                                    __PVT__instr_decompressed 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__40__Vfuncout;
                                } else if ((7U == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__42__rs 
                                        = (7U & (vlSelf->__PVT__fetch_rdata 
                                                 >> 2U));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__42__src 
                                        = (((0U < (3U 
                                                   & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__42__rs) 
                                                      >> 1U))) 
                                            << 4U) 
                                           | (((0U 
                                                == 
                                                (3U 
                                                 & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__42__rs) 
                                                    >> 1U))) 
                                               << 3U) 
                                              | (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__42__rs)));
                                    if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                        __PVT__compressed_decoder_i__DOT__gets_expanded = 3U;
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                    }
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__43__src 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__42__src;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__43__instr 
                                        = (0x593U | 
                                           ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__43__src) 
                                            << 0xfU));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__43__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__43__instr;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__42__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__43__Vfuncout;
                                    __PVT__instr_decompressed 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__42__Vfuncout;
                                } else {
                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                }
                            } else {
                                vlSelf->__PVT__illegal_c_insn = 1U;
                            }
                        } else {
                            vlSelf->__PVT__illegal_c_insn = 1U;
                        }
                    } else {
                        vlSelf->__PVT__illegal_c_insn = 1U;
                    }
                } else if ((0x1000U & vlSelf->__PVT__fetch_rdata)) {
                    __PVT__instr_decompressed = ((0U 
                                                  != 
                                                  (0x1fU 
                                                   & (vlSelf->__PVT__fetch_rdata 
                                                      >> 2U)))
                                                  ? 
                                                 (0x33U 
                                                  | ((0x1f00000U 
                                                      & (vlSelf->__PVT__fetch_rdata 
                                                         << 0x12U)) 
                                                     | ((0xf8000U 
                                                         & (vlSelf->__PVT__fetch_rdata 
                                                            << 8U)) 
                                                        | (0xf80U 
                                                           & vlSelf->__PVT__fetch_rdata))))
                                                  : 
                                                 ((0U 
                                                   == 
                                                   (0x1fU 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       >> 7U)))
                                                   ? 0x100073U
                                                   : 
                                                  (0xe7U 
                                                   | (0xf8000U 
                                                      & (vlSelf->__PVT__fetch_rdata 
                                                         << 8U)))));
                } else if ((0U != (0x1fU & (vlSelf->__PVT__fetch_rdata 
                                            >> 2U)))) {
                    __PVT__instr_decompressed = (0x33U 
                                                 | ((0x1f00000U 
                                                     & (vlSelf->__PVT__fetch_rdata 
                                                        << 0x12U)) 
                                                    | (0xf80U 
                                                       & vlSelf->__PVT__fetch_rdata)));
                } else {
                    __PVT__instr_decompressed = (0x67U 
                                                 | (0xf8000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 8U)));
                    if ((0U == (0x1fU & (vlSelf->__PVT__fetch_rdata 
                                         >> 7U)))) {
                        vlSelf->__PVT__illegal_c_insn = 1U;
                    }
                }
            } else if ((0x4000U & vlSelf->__PVT__fetch_rdata)) {
                if ((0x2000U & vlSelf->__PVT__fetch_rdata)) {
                    vlSelf->__PVT__illegal_c_insn = 1U;
                } else {
                    __PVT__instr_decompressed = (0x12003U 
                                                 | ((0xc000000U 
                                                     & (vlSelf->__PVT__fetch_rdata 
                                                        << 0x18U)) 
                                                    | ((0x2000000U 
                                                        & (vlSelf->__PVT__fetch_rdata 
                                                           << 0xdU)) 
                                                       | ((0x1c00000U 
                                                           & (vlSelf->__PVT__fetch_rdata 
                                                              << 0x12U)) 
                                                          | (0xf80U 
                                                             & vlSelf->__PVT__fetch_rdata)))));
                    if ((0U == (0x1fU & (vlSelf->__PVT__fetch_rdata 
                                         >> 7U)))) {
                        vlSelf->__PVT__illegal_c_insn = 1U;
                    }
                }
            } else if ((0x2000U & vlSelf->__PVT__fetch_rdata)) {
                vlSelf->__PVT__illegal_c_insn = 1U;
            } else {
                __PVT__instr_decompressed = (0x1013U 
                                             | ((0x1f00000U 
                                                 & (vlSelf->__PVT__fetch_rdata 
                                                    << 0x12U)) 
                                                | ((0xf8000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 8U)) 
                                                   | (0xf80U 
                                                      & vlSelf->__PVT__fetch_rdata))));
                if ((0x1000U & vlSelf->__PVT__fetch_rdata)) {
                    vlSelf->__PVT__illegal_c_insn = 1U;
                }
            }
        }
    } else if ((1U & vlSelf->__PVT__fetch_rdata)) {
        if ((0x8000U & vlSelf->__PVT__fetch_rdata)) {
            if ((0x4000U & vlSelf->__PVT__fetch_rdata)) {
                __PVT__instr_decompressed = (0x40063U 
                                             | (((- (IData)(
                                                            (1U 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                >> 0xcU)))) 
                                                 << 0x1cU) 
                                                | ((0xc000000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 0x15U)) 
                                                   | ((0x2000000U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 0x17U)) 
                                                      | ((0x38000U 
                                                          & (vlSelf->__PVT__fetch_rdata 
                                                             << 8U)) 
                                                         | ((0x1000U 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                >> 1U)) 
                                                            | ((0xc00U 
                                                                & vlSelf->__PVT__fetch_rdata) 
                                                               | ((0x300U 
                                                                   & (vlSelf->__PVT__fetch_rdata 
                                                                      << 5U)) 
                                                                  | (0x80U 
                                                                     & (vlSelf->__PVT__fetch_rdata 
                                                                        >> 5U))))))))));
            } else if ((0x2000U & vlSelf->__PVT__fetch_rdata)) {
                __PVT__instr_decompressed = (0x6fU 
                                             | ((0x80000000U 
                                                 & (vlSelf->__PVT__fetch_rdata 
                                                    << 0x13U)) 
                                                | ((0x40000000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 0x16U)) 
                                                   | ((0x30000000U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 0x13U)) 
                                                      | ((0x8000000U 
                                                          & (vlSelf->__PVT__fetch_rdata 
                                                             << 0x15U)) 
                                                         | ((0x4000000U 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                << 0x13U)) 
                                                            | ((0x2000000U 
                                                                & (vlSelf->__PVT__fetch_rdata 
                                                                   << 0x17U)) 
                                                               | ((0x1000000U 
                                                                   & (vlSelf->__PVT__fetch_rdata 
                                                                      << 0xdU)) 
                                                                  | ((0xe00000U 
                                                                      & (vlSelf->__PVT__fetch_rdata 
                                                                         << 0x12U)) 
                                                                     | ((0x1ff000U 
                                                                         & ((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->__PVT__fetch_rdata 
                                                                                >> 0xcU)))) 
                                                                            << 0xcU)) 
                                                                        | (0x80U 
                                                                           & ((~ 
                                                                               (vlSelf->__PVT__fetch_rdata 
                                                                                >> 0xfU)) 
                                                                              << 7U))))))))))));
            } else if ((0x800U & vlSelf->__PVT__fetch_rdata)) {
                if ((0x400U & vlSelf->__PVT__fetch_rdata)) {
                    if ((0x1000U & vlSelf->__PVT__fetch_rdata)) {
                        if ((0x40U & vlSelf->__PVT__fetch_rdata)) {
                            if ((0x20U & vlSelf->__PVT__fetch_rdata)) {
                                if ((0x10U & vlSelf->__PVT__fetch_rdata)) {
                                    if ((8U & vlSelf->__PVT__fetch_rdata)) {
                                        vlSelf->__PVT__illegal_c_insn = 1U;
                                    } else if ((4U 
                                                & vlSelf->__PVT__fetch_rdata)) {
                                        __PVT__instr_decompressed 
                                            = (0xfff44413U 
                                               | ((0x38000U 
                                                   & (vlSelf->__PVT__fetch_rdata 
                                                      << 8U)) 
                                                  | (0x380U 
                                                     & vlSelf->__PVT__fetch_rdata)));
                                    } else {
                                        vlSelf->__PVT__illegal_c_insn = 1U;
                                    }
                                } else {
                                    __PVT__instr_decompressed 
                                        = ((8U & vlSelf->__PVT__fetch_rdata)
                                            ? ((4U 
                                                & vlSelf->__PVT__fetch_rdata)
                                                ? (0x60541413U 
                                                   | ((0x38000U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 8U)) 
                                                      | (0x380U 
                                                         & vlSelf->__PVT__fetch_rdata)))
                                                : (0x8044433U 
                                                   | ((0x38000U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 8U)) 
                                                      | (0x380U 
                                                         & vlSelf->__PVT__fetch_rdata))))
                                            : ((4U 
                                                & vlSelf->__PVT__fetch_rdata)
                                                ? (0x60441413U 
                                                   | ((0x38000U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 8U)) 
                                                      | (0x380U 
                                                         & vlSelf->__PVT__fetch_rdata)))
                                                : (0xff47413U 
                                                   | ((0x38000U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 8U)) 
                                                      | (0x380U 
                                                         & vlSelf->__PVT__fetch_rdata)))));
                                }
                            } else {
                                __PVT__instr_decompressed 
                                    = (0x2840433U | 
                                       ((0x700000U 
                                         & (vlSelf->__PVT__fetch_rdata 
                                            << 0x12U)) 
                                        | ((0x38000U 
                                            & (vlSelf->__PVT__fetch_rdata 
                                               << 8U)) 
                                           | (0x380U 
                                              & vlSelf->__PVT__fetch_rdata))));
                            }
                        } else {
                            vlSelf->__PVT__illegal_c_insn = 1U;
                        }
                    } else {
                        __PVT__instr_decompressed = 
                            ((0x40U & vlSelf->__PVT__fetch_rdata)
                              ? ((0x20U & vlSelf->__PVT__fetch_rdata)
                                  ? (0x847433U | ((0x700000U 
                                                   & (vlSelf->__PVT__fetch_rdata 
                                                      << 0x12U)) 
                                                  | ((0x38000U 
                                                      & (vlSelf->__PVT__fetch_rdata 
                                                         << 8U)) 
                                                     | (0x380U 
                                                        & vlSelf->__PVT__fetch_rdata))))
                                  : (0x846433U | ((0x700000U 
                                                   & (vlSelf->__PVT__fetch_rdata 
                                                      << 0x12U)) 
                                                  | ((0x38000U 
                                                      & (vlSelf->__PVT__fetch_rdata 
                                                         << 8U)) 
                                                     | (0x380U 
                                                        & vlSelf->__PVT__fetch_rdata)))))
                              : ((0x20U & vlSelf->__PVT__fetch_rdata)
                                  ? (0x844433U | ((0x700000U 
                                                   & (vlSelf->__PVT__fetch_rdata 
                                                      << 0x12U)) 
                                                  | ((0x38000U 
                                                      & (vlSelf->__PVT__fetch_rdata 
                                                         << 8U)) 
                                                     | (0x380U 
                                                        & vlSelf->__PVT__fetch_rdata))))
                                  : (0x40840433U | 
                                     ((0x700000U & 
                                       (vlSelf->__PVT__fetch_rdata 
                                        << 0x12U)) 
                                      | ((0x38000U 
                                          & (vlSelf->__PVT__fetch_rdata 
                                             << 8U)) 
                                         | (0x380U 
                                            & vlSelf->__PVT__fetch_rdata))))));
                    }
                } else {
                    __PVT__instr_decompressed = (0x47413U 
                                                 | (((- (IData)(
                                                                (1U 
                                                                 & (vlSelf->__PVT__fetch_rdata 
                                                                    >> 0xcU)))) 
                                                     << 0x1aU) 
                                                    | ((0x2000000U 
                                                        & (vlSelf->__PVT__fetch_rdata 
                                                           << 0xdU)) 
                                                       | ((0x1f00000U 
                                                           & (vlSelf->__PVT__fetch_rdata 
                                                              << 0x12U)) 
                                                          | ((0x38000U 
                                                              & (vlSelf->__PVT__fetch_rdata 
                                                                 << 8U)) 
                                                             | (0x380U 
                                                                & vlSelf->__PVT__fetch_rdata))))));
                }
            } else {
                __PVT__instr_decompressed = (0x45413U 
                                             | ((0x40000000U 
                                                 & (vlSelf->__PVT__fetch_rdata 
                                                    << 0x14U)) 
                                                | ((0x1f00000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 0x12U)) 
                                                   | ((0x38000U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 8U)) 
                                                      | (0x380U 
                                                         & vlSelf->__PVT__fetch_rdata)))));
                if ((0x1000U & vlSelf->__PVT__fetch_rdata)) {
                    vlSelf->__PVT__illegal_c_insn = 1U;
                }
            }
        } else if ((0x4000U & vlSelf->__PVT__fetch_rdata)) {
            if ((0x2000U & vlSelf->__PVT__fetch_rdata)) {
                __PVT__instr_decompressed = (0x37U 
                                             | (((- (IData)(
                                                            (1U 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                >> 0xcU)))) 
                                                 << 0x11U) 
                                                | ((0x1f000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 0xaU)) 
                                                   | (0xf80U 
                                                      & vlSelf->__PVT__fetch_rdata))));
                if ((0U == ((0x20U & (vlSelf->__PVT__fetch_rdata 
                                      >> 7U)) | (0x1fU 
                                                 & (vlSelf->__PVT__fetch_rdata 
                                                    >> 2U))))) {
                    vlSelf->__PVT__illegal_c_insn = 1U;
                }
                if ((2U == (0x1fU & (vlSelf->__PVT__fetch_rdata 
                                     >> 7U)))) {
                    __PVT__instr_decompressed = (0x10113U 
                                                 | (((- (IData)(
                                                                (1U 
                                                                 & (vlSelf->__PVT__fetch_rdata 
                                                                    >> 0xcU)))) 
                                                     << 0x1dU) 
                                                    | ((0x18000000U 
                                                        & (vlSelf->__PVT__fetch_rdata 
                                                           << 0x18U)) 
                                                       | ((0x4000000U 
                                                           & (vlSelf->__PVT__fetch_rdata 
                                                              << 0x15U)) 
                                                          | ((0x2000000U 
                                                              & (vlSelf->__PVT__fetch_rdata 
                                                                 << 0x17U)) 
                                                             | (0x1000000U 
                                                                & (vlSelf->__PVT__fetch_rdata 
                                                                   << 0x12U)))))));
                }
            } else {
                __PVT__instr_decompressed = (0x13U 
                                             | (((- (IData)(
                                                            (1U 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                >> 0xcU)))) 
                                                 << 0x1aU) 
                                                | ((0x2000000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 0xdU)) 
                                                   | ((0x1f00000U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 0x12U)) 
                                                      | (0xf80U 
                                                         & vlSelf->__PVT__fetch_rdata)))));
            }
        } else {
            __PVT__instr_decompressed = ((0x2000U & vlSelf->__PVT__fetch_rdata)
                                          ? (0x6fU 
                                             | ((0x80000000U 
                                                 & (vlSelf->__PVT__fetch_rdata 
                                                    << 0x13U)) 
                                                | ((0x40000000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 0x16U)) 
                                                   | ((0x30000000U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 0x13U)) 
                                                      | ((0x8000000U 
                                                          & (vlSelf->__PVT__fetch_rdata 
                                                             << 0x15U)) 
                                                         | ((0x4000000U 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                << 0x13U)) 
                                                            | ((0x2000000U 
                                                                & (vlSelf->__PVT__fetch_rdata 
                                                                   << 0x17U)) 
                                                               | ((0x1000000U 
                                                                   & (vlSelf->__PVT__fetch_rdata 
                                                                      << 0xdU)) 
                                                                  | ((0xe00000U 
                                                                      & (vlSelf->__PVT__fetch_rdata 
                                                                         << 0x12U)) 
                                                                     | ((0x1ff000U 
                                                                         & ((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->__PVT__fetch_rdata 
                                                                                >> 0xcU)))) 
                                                                            << 0xcU)) 
                                                                        | (0x80U 
                                                                           & ((~ 
                                                                               (vlSelf->__PVT__fetch_rdata 
                                                                                >> 0xfU)) 
                                                                              << 7U))))))))))))
                                          : (0x13U 
                                             | (((- (IData)(
                                                            (1U 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                >> 0xcU)))) 
                                                 << 0x1aU) 
                                                | ((0x2000000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 0xdU)) 
                                                   | ((0x1f00000U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 0x12U)) 
                                                      | ((0xf8000U 
                                                          & (vlSelf->__PVT__fetch_rdata 
                                                             << 8U)) 
                                                         | (0xf80U 
                                                            & vlSelf->__PVT__fetch_rdata)))))));
        }
    } else if ((0x8000U & vlSelf->__PVT__fetch_rdata)) {
        if ((0x4000U & vlSelf->__PVT__fetch_rdata)) {
            if ((0x2000U & vlSelf->__PVT__fetch_rdata)) {
                vlSelf->__PVT__illegal_c_insn = 1U;
            } else {
                __PVT__instr_decompressed = (0x842023U 
                                             | ((0x4000000U 
                                                 & (vlSelf->__PVT__fetch_rdata 
                                                    << 0x15U)) 
                                                | ((0x2000000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 0xdU)) 
                                                   | ((0x700000U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 0x12U)) 
                                                      | ((0x38000U 
                                                          & (vlSelf->__PVT__fetch_rdata 
                                                             << 8U)) 
                                                         | ((0xc00U 
                                                             & vlSelf->__PVT__fetch_rdata) 
                                                            | (0x200U 
                                                               & (vlSelf->__PVT__fetch_rdata 
                                                                  << 3U))))))));
            }
        } else if ((0x2000U & vlSelf->__PVT__fetch_rdata)) {
            vlSelf->__PVT__illegal_c_insn = 1U;
        } else if ((0x1000U & vlSelf->__PVT__fetch_rdata)) {
            vlSelf->__PVT__illegal_c_insn = 1U;
        } else if ((0x800U & vlSelf->__PVT__fetch_rdata)) {
            if ((0x400U & vlSelf->__PVT__fetch_rdata)) {
                if ((0x40U & vlSelf->__PVT__fetch_rdata)) {
                    vlSelf->__PVT__illegal_c_insn = 1U;
                } else {
                    __PVT__instr_decompressed = (0x841023U 
                                                 | ((0x700000U 
                                                     & (vlSelf->__PVT__fetch_rdata 
                                                        << 0x12U)) 
                                                    | ((0x38000U 
                                                        & (vlSelf->__PVT__fetch_rdata 
                                                           << 8U)) 
                                                       | (0x100U 
                                                          & (vlSelf->__PVT__fetch_rdata 
                                                             << 3U)))));
                }
            } else {
                __PVT__instr_decompressed = (0x840023U 
                                             | ((0x700000U 
                                                 & (vlSelf->__PVT__fetch_rdata 
                                                    << 0x12U)) 
                                                | ((0x38000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 8U)) 
                                                   | ((0x100U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 3U)) 
                                                      | (0x80U 
                                                         & (vlSelf->__PVT__fetch_rdata 
                                                            << 1U))))));
            }
        } else if ((0x400U & vlSelf->__PVT__fetch_rdata)) {
            if ((0x40U & vlSelf->__PVT__fetch_rdata)) {
                if ((0x40U & vlSelf->__PVT__fetch_rdata)) {
                    __PVT__instr_decompressed = (0x41403U 
                                                 | ((0x200000U 
                                                     & (vlSelf->__PVT__fetch_rdata 
                                                        << 0x10U)) 
                                                    | ((0x38000U 
                                                        & (vlSelf->__PVT__fetch_rdata 
                                                           << 8U)) 
                                                       | (0x380U 
                                                          & (vlSelf->__PVT__fetch_rdata 
                                                             << 5U)))));
                } else {
                    vlSelf->__PVT__illegal_c_insn = 1U;
                }
            } else {
                __PVT__instr_decompressed = (0x45403U 
                                             | ((0x200000U 
                                                 & (vlSelf->__PVT__fetch_rdata 
                                                    << 0x10U)) 
                                                | ((0x38000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 8U)) 
                                                   | (0x380U 
                                                      & (vlSelf->__PVT__fetch_rdata 
                                                         << 5U)))));
            }
        } else {
            __PVT__instr_decompressed = (0x44403U | 
                                         ((0x200000U 
                                           & (vlSelf->__PVT__fetch_rdata 
                                              << 0x10U)) 
                                          | ((0x100000U 
                                              & (vlSelf->__PVT__fetch_rdata 
                                                 << 0xeU)) 
                                             | ((0x38000U 
                                                 & (vlSelf->__PVT__fetch_rdata 
                                                    << 8U)) 
                                                | (0x380U 
                                                   & (vlSelf->__PVT__fetch_rdata 
                                                      << 5U))))));
        }
    } else if ((0x4000U & vlSelf->__PVT__fetch_rdata)) {
        if ((0x2000U & vlSelf->__PVT__fetch_rdata)) {
            vlSelf->__PVT__illegal_c_insn = 1U;
        } else {
            __PVT__instr_decompressed = (0x42403U | 
                                         ((0x4000000U 
                                           & (vlSelf->__PVT__fetch_rdata 
                                              << 0x15U)) 
                                          | ((0x3800000U 
                                              & (vlSelf->__PVT__fetch_rdata 
                                                 << 0xdU)) 
                                             | ((0x400000U 
                                                 & (vlSelf->__PVT__fetch_rdata 
                                                    << 0x10U)) 
                                                | ((0x38000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 8U)) 
                                                   | (0x380U 
                                                      & (vlSelf->__PVT__fetch_rdata 
                                                         << 5U)))))));
        }
    } else if ((0x2000U & vlSelf->__PVT__fetch_rdata)) {
        vlSelf->__PVT__illegal_c_insn = 1U;
    } else {
        __PVT__instr_decompressed = (0x10413U | ((0x3c000000U 
                                                  & (vlSelf->__PVT__fetch_rdata 
                                                     << 0x13U)) 
                                                 | ((0x3000000U 
                                                     & (vlSelf->__PVT__fetch_rdata 
                                                        << 0xdU)) 
                                                    | ((0x800000U 
                                                        & (vlSelf->__PVT__fetch_rdata 
                                                           << 0x12U)) 
                                                       | ((0x400000U 
                                                           & (vlSelf->__PVT__fetch_rdata 
                                                              << 0x10U)) 
                                                          | (0x380U 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                << 5U)))))));
        if ((0U == (0xffU & (vlSelf->__PVT__fetch_rdata 
                             >> 5U)))) {
            vlSelf->__PVT__illegal_c_insn = 1U;
        }
    }
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_d 
        = (0x7fffffffU & ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o)
                           ? (vlSelf->__PVT__prefetch_addr 
                              >> 1U) : (vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q 
                                        + ((2U & ((~ (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two)) 
                                                  << 1U)) 
                                           | (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two)))));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_d 
        = ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_req_q)
            ? vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_q
            : ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o)
                ? vlSelf->__PVT__prefetch_addr : vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fetch_addr_q));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fetch_addr_d 
        = (((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o)
             ? vlSelf->__PVT__prefetch_addr : (0xfffffffcU 
                                               & vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fetch_addr_q)) 
           + ((IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_hfddf9e70__0) 
              << 2U));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_n 
        = ((2U & ((((IData)(vlSelf->instr_req_o) & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q)) 
                   << 1U) | (0xfffffffeU & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q)))) 
           | (1U & ((IData)(vlSelf->instr_req_o) | (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q))));
    gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_he9db8f89__0 
        = ((IData)(vlSelf->instr_req_o) & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__discard_req_d));
    vlSelf->__PVT__instr_valid_id_d = ((IData)(vlSelf->__PVT__instr_new_id_d) 
                                       | ((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.instr_valid_clear_o)) 
                                          & (IData)(vlSelf->__PVT__instr_valid_id_q)));
    vlSelf->__PVT__instr_out = ((IData)(vlSelf->__PVT__gen_dummy_instr__DOT__insert_dummy_instr)
                                 ? (0x33U | (((IData)(vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_set) 
                                              << 0x19U) 
                                             | ((0x1ff8000U 
                                                 & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_data 
                                                    << 0xaU)) 
                                                | ((IData)(vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_opcode) 
                                                   << 0xcU))))
                                 : __PVT__instr_decompressed);
    vlSelf->__PVT__instr_gets_expanded = ((IData)(vlSelf->__Vcellinp__compressed_decoder_i__valid_i)
                                           ? (IData)(__PVT__compressed_decoder_i__DOT__gets_expanded)
                                           : 0U);
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_n 
        = ((2U & ((((IData)(gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_he9db8f89__0) 
                    & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q)) 
                   << 1U) | (0xfffffffeU & ((((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o) 
                                              << 1U) 
                                             & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q)) 
                                            | (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_q))))) 
           | (1U & ((IData)(gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_he9db8f89__0) 
                    | (((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o) 
                        & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q)) 
                       | (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_q)))));
    __VdfgTmp_h3d81f5b8__0 = (1U & ((~ (IData)(vlSelf->__PVT__gen_dummy_instr__DOT__insert_dummy_instr)) 
                                    & (~ ((1U == (IData)(vlSelf->__PVT__instr_gets_expanded)) 
                                          | (2U == (IData)(vlSelf->__PVT__instr_gets_expanded))))));
    vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_hd659ff45__0 
        = (((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.id_in_ready_o) 
            & (IData)(__VdfgTmp_h3d81f5b8__0)) & (IData)(vlSelf->__PVT__fetch_valid_raw));
    __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo 
        = ((IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_hd659ff45__0) 
           & ((~ (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__aligned_is_compressed)) 
              | vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_d 
        = ((((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o)) 
             & ((~ (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo)) 
                & (IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h46facb3b__0))) 
            << 2U) | ((((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o)) 
                        & ((IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo)
                            ? (IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h46facb3b__0)
                            : (IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_haf2cbd5f__0))) 
                       << 1U) | (1U & ((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o)) 
                                       & ((IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo)
                                           ? (IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_haf2cbd5f__0)
                                           : ((IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h0d767fd8__0) 
                                              | (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q)))))));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__entry_en 
        = (((IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h87841355__0) 
            << 2U) | (((((IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h46facb3b__0) 
                         & (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo)) 
                        | ((~ (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo)) 
                           & (IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h18c9f2e2__0))) 
                       << 1U) | (((IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_haf2cbd5f__0) 
                                  & (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo)) 
                                 | ((~ (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo)) 
                                    & (IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h0d767fd8__0)))));
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__0(Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__0\n"); );
    // Init
    IData/*16:0*/ __Vfunc_gen_dummy_instr__DOT__dummy_instr_i__DOT__sv2v_cast_92F3A__44__Vfuncout;
    __Vfunc_gen_dummy_instr__DOT__dummy_instr_i__DOT__sv2v_cast_92F3A__44__Vfuncout = 0;
    IData/*16:0*/ __Vfunc_gen_dummy_instr__DOT__dummy_instr_i__DOT__sv2v_cast_92F3A__44__inp;
    __Vfunc_gen_dummy_instr__DOT__dummy_instr_i__DOT__sv2v_cast_92F3A__44__inp = 0;
    // Body
    if (vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__rst_n) {
        if (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.dummy_instr_seed_en_o) {
            vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_instr_seed_q 
                = vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_instr_seed_d;
        }
        if (((~ (IData)(vlSelf->instr_req_o)) & (IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_hfddf9e70__0))) {
            vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_q 
                = vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_d;
        }
        vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
            = vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_d;
        vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_q 
            = vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d;
        vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_q 
            = vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d;
        if (vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__ram_instr_rvalid) {
            vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q 
                = (3U & VL_SHIFTR_III(2,2,32, (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_n), 1U));
            vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_q 
                = (3U & VL_SHIFTR_III(2,2,32, (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_n), 1U));
        } else {
            vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q 
                = (3U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_n));
            vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_q 
                = (3U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_n));
        }
        if (((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o) 
             | (IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_hfddf9e70__0))) {
            vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fetch_addr_q 
                = vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fetch_addr_d;
        }
        if ((1U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__entry_en))) {
            vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q[0U] 
                = vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_d[0U];
        }
        if ((2U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__entry_en))) {
            vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q[1U] 
                = vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_d[1U];
        }
        if (vlSelf->__PVT__instr_new_id_d) {
            vlSelf->instr_rdata_c_id_o = (0xffffU & vlSelf->__PVT__fetch_rdata);
            vlSelf->instr_gets_expanded_id_o = ((IData)(vlSelf->__PVT__gen_dummy_instr__DOT__insert_dummy_instr)
                                                 ? 0U
                                                 : (IData)(vlSelf->__PVT__instr_gets_expanded));
            vlSelf->instr_is_compressed_id_o = ((~ (IData)(vlSelf->__PVT__gen_dummy_instr__DOT__insert_dummy_instr)) 
                                                & (3U 
                                                   != 
                                                   (3U 
                                                    & vlSelf->__PVT__fetch_rdata)));
            vlSelf->pc_id_o = (vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q 
                               << 1U);
            vlSelf->instr_fetch_err_plus2_o = ((1U 
                                                & vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q) 
                                               && (1U 
                                                   & ((2U 
                                                       & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))
                                                       ? (IData)(
                                                                 (2U 
                                                                  == 
                                                                  (3U 
                                                                   & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q))))
                                                       : 
                                                      ((IData)(vlSelf->__PVT__instr_err) 
                                                       & ((~ (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q)) 
                                                          & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))))));
        }
        if ((1U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__entry_en))) {
            vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q 
                = ((6U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q)) 
                   | (1U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_d)));
        }
        if ((2U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__entry_en))) {
            vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q 
                = ((5U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q)) 
                   | (2U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_d)));
        }
        if ((4U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__entry_en))) {
            vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q[2U] 
                = vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_d[2U];
            vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q 
                = ((3U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q)) 
                   | (4U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_d)));
        }
        if (vlSelf->__PVT__instr_new_id_d) {
            vlSelf->instr_fetch_err_o = ((~ (IData)(vlSelf->__PVT__gen_dummy_instr__DOT__insert_dummy_instr)) 
                                         & (IData)(vlSelf->__PVT__fetch_err));
            vlSelf->instr_rdata_alu_id_o = vlSelf->__PVT__instr_out;
            vlSelf->illegal_c_insn_id_o = ((~ (IData)(vlSelf->__PVT__gen_dummy_instr__DOT__insert_dummy_instr)) 
                                           & (IData)(vlSelf->__PVT__illegal_c_insn));
            vlSelf->instr_rdata_id_o = vlSelf->__PVT__instr_out;
            vlSelf->dummy_instr_id_o = vlSelf->__PVT__gen_dummy_instr__DOT__insert_dummy_instr;
        }
        vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q 
            = (((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o) 
                & (2U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_mux_o)))
                ? 0U : (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d));
        if ((((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
              >> 2U) & ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.id_in_ready_o) 
                        & ((IData)(vlSelf->__PVT__fetch_valid_raw) 
                           | (IData)(vlSelf->__PVT__gen_dummy_instr__DOT__insert_dummy_instr))))) {
            vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_cnt_q 
                = vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_cnt_d;
        }
        if (((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o) 
             | (IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_hd659ff45__0))) {
            vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q 
                = vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_d;
        }
        vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q 
            = vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_d;
    } else {
        vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_instr_seed_q = 0U;
        vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_q = 0U;
        vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q = 0xac533bf4U;
        vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_q = 0U;
        vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_q = 0U;
        vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q = 0U;
        vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fetch_addr_q = 0U;
        vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_q = 0U;
        vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q[0U] = 0U;
        vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q[1U] = 0U;
        vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q[2U] = 0U;
        vlSelf->instr_rdata_c_id_o = 0U;
        vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q = 0U;
        vlSelf->instr_gets_expanded_id_o = 0U;
        vlSelf->instr_is_compressed_id_o = 0U;
        vlSelf->pc_id_o = 0U;
        vlSelf->instr_fetch_err_plus2_o = 0U;
        vlSelf->instr_fetch_err_o = 0U;
        vlSelf->instr_rdata_alu_id_o = 0U;
        vlSelf->illegal_c_insn_id_o = 0U;
        vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_cnt_q = 0U;
        vlSelf->instr_rdata_id_o = 0U;
        vlSelf->dummy_instr_id_o = 0U;
        vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q = 0U;
        vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q 
            = (6U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q));
        vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q 
            = (5U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q));
        vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q 
            = (3U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q));
        vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q = 0U;
    }
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__discard_req_q 
        = ((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__rst_n) 
           && (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__discard_req_d));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_req_q = 0U;
    vlSelf->__PVT__instr_valid_id_q = ((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__rst_n) 
                                       && (IData)(vlSelf->__PVT__instr_valid_id_d));
    __Vfunc_gen_dummy_instr__DOT__dummy_instr_i__DOT__sv2v_cast_92F3A__44__inp 
        = ((0x10000U & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                        >> 5U)) | ((0x8000U & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                               >> 1U)) 
                                   | ((0x4000U & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                  << 9U)) 
                                      | ((0x2000U & 
                                          (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                           << 4U)) 
                                         | ((0x1000U 
                                             & vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q) 
                                            | ((0x800U 
                                                & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                   << 0xbU)) 
                                               | ((0x400U 
                                                   & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                      >> 9U)) 
                                                  | ((0x200U 
                                                      & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                         >> 0x14U)) 
                                                     | ((0x100U 
                                                         & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                            << 4U)) 
                                                        | ((0x80U 
                                                            & vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q) 
                                                           | ((0x40U 
                                                               & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                                  << 5U)) 
                                                              | ((0x20U 
                                                                  & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                                     >> 0x17U)) 
                                                                 | ((0x10U 
                                                                     & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                                        >> 6U)) 
                                                                    | ((8U 
                                                                        & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                                           >> 0xeU)) 
                                                                       | ((4U 
                                                                           & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                                              >> 0x14U)) 
                                                                          | ((2U 
                                                                              & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                                                >> 0x16U)) 
                                                                             | (1U 
                                                                                & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q 
                                                                                >> 0xdU))))))))))))))))));
    __Vfunc_gen_dummy_instr__DOT__dummy_instr_i__DOT__sv2v_cast_92F3A__44__Vfuncout 
        = __Vfunc_gen_dummy_instr__DOT__dummy_instr_i__DOT__sv2v_cast_92F3A__44__inp;
    vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_data 
        = __Vfunc_gen_dummy_instr__DOT__dummy_instr_i__DOT__sv2v_cast_92F3A__44__Vfuncout;
    if ((0x10000U & vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_data)) {
        if ((0x8000U & vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_data)) {
            vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_set = 0U;
            vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_opcode = 7U;
        } else {
            vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_set = 1U;
            vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_opcode = 4U;
        }
    } else {
        vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_set 
            = ((0x8000U & vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_data)
                ? 1U : 0U);
        vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_opcode = 0U;
    }
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__1(Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__1\n"); );
    // Body
    vlSelf->__PVT__gen_dummy_instr__DOT__insert_dummy_instr 
        = (((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
            >> 2U) & ((IData)(vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_cnt_q) 
                      == (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_data 
                          & (3U | (0x1cU & ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
                                            >> 1U))))));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid 
        = ((~ (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_q)) 
           & (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__ram_instr_rvalid));
    vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_cnt_d 
        = ((IData)(vlSelf->__PVT__gen_dummy_instr__DOT__insert_dummy_instr)
            ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_cnt_q))));
    vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h0d767fd8__0 
        = ((~ (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q)) 
           & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid));
    vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h87841355__0 
        = ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid) 
           & (IData)((2U == (6U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q)))));
    vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h18c9f2e2__0 
        = ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid) 
           & (IData)((1U == (3U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q)))));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid 
        = (1U & ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                 | (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid)));
    vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h46facb3b__0 
        = (IData)((((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                    >> 2U) | (IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h87841355__0)));
    vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_haf2cbd5f__0 
        = (1U & ((IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h18c9f2e2__0) 
                 | ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                    >> 1U)));
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__2(Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__2\n"); );
    // Init
    IData/*31:0*/ __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o;
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o = 0;
    // Body
    vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o 
        = ((0x7eU & (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
           | (1U & VL_REDXOR_64((0x12606bd25ULL & (0x2a00000000ULL 
                                                   ^ vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core)))));
    vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o 
        = ((0x7dU & (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
           | (2U & (VL_REDXOR_64((0x2deba8050ULL & 
                                  (0x2a00000000ULL 
                                   ^ vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core))) 
                    << 1U)));
    vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o 
        = ((0x7bU & (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
           | (4U & (VL_REDXOR_64((0x4413d89aaULL & 
                                  (0x2a00000000ULL 
                                   ^ vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core))) 
                    << 2U)));
    vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o 
        = ((0x77U & (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
           | (8U & (VL_REDXOR_64((0x831234ed1ULL & 
                                  (0x2a00000000ULL 
                                   ^ vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core))) 
                    << 3U)));
    vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o 
        = ((0x6fU & (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
           | (0x10U & (VL_REDXOR_64((0x10c2c1323bULL 
                                     & (0x2a00000000ULL 
                                        ^ vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core))) 
                       << 4U)));
    vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o 
        = ((0x5fU & (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
           | (0x20U & (VL_REDXOR_64((0x202dcc624cULL 
                                     & (0x2a00000000ULL 
                                        ^ vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core))) 
                       << 5U)));
    vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o 
        = ((0x3fU & (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
           | (0x40U & (VL_REDXOR_64((0x4098505586ULL 
                                     & (0x2a00000000ULL 
                                        ^ vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core))) 
                       << 6U)));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xfffffffcU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((2U & (((0x54U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                      ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                 >> 1U))) << 1U)) | 
              (1U & ((0x19U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                     ^ (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core)))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xfffffff3U & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((8U & (((0x34U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                      ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                 >> 3U))) << 3U)) | 
              (4U & (((0x61U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                      ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                 >> 2U))) << 2U))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xffffffcfU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x20U & (((0x15U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                         ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                    >> 5U))) << 5U)) 
              | (0x10U & (((0x1aU == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                           ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                      >> 4U))) << 4U))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xffffff3fU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x80U & (((0x4cU == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                         ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                    >> 7U))) << 7U)) 
              | (0x40U & (((0x2aU == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                           ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                      >> 6U))) << 6U))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xfffffcffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x200U & (((0x38U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                          ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                     >> 9U))) << 9U)) 
              | (0x100U & (((0x45U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                            ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                       >> 8U))) << 8U))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xfffff3ffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x800U & (((0xdU == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                          ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                     >> 0xbU))) << 0xbU)) 
              | (0x400U & (((0x49U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                            ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                       >> 0xaU))) << 0xaU))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xffffcfffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x2000U & (((0x31U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                           ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                      >> 0xdU))) << 0xdU)) 
              | (0x1000U & (((0x51U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                             ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                        >> 0xcU))) 
                            << 0xcU))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xffff3fffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x8000U & (((7U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                           ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                      >> 0xfU))) << 0xfU)) 
              | (0x4000U & (((0x68U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                             ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                        >> 0xeU))) 
                            << 0xeU))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xfffcffffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x20000U & (((0xbU == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                            ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                       >> 0x11U))) 
                           << 0x11U)) | (0x10000U & 
                                         (((0x1cU == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                                           ^ (IData)(
                                                     (vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                                      >> 0x10U))) 
                                          << 0x10U))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xfff3ffffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x80000U & (((0x26U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                            ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                       >> 0x13U))) 
                           << 0x13U)) | (0x40000U & 
                                         (((0x25U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                                           ^ (IData)(
                                                     (vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                                      >> 0x12U))) 
                                          << 0x12U))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xffcfffffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x200000U & (((0xeU == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                             ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                        >> 0x15U))) 
                            << 0x15U)) | (0x100000U 
                                          & (((0x46U 
                                               == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                                              ^ (IData)(
                                                        (vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                                         >> 0x14U))) 
                                             << 0x14U))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xff3fffffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x800000U & (((0x32U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                             ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                        >> 0x17U))) 
                            << 0x17U)) | (0x400000U 
                                          & (((0x70U 
                                               == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                                              ^ (IData)(
                                                        (vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                                         >> 0x16U))) 
                                             << 0x16U))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xfcffffffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x2000000U & (((0x13U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                              ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                         >> 0x19U))) 
                             << 0x19U)) | (0x1000000U 
                                           & (((0x2cU 
                                                == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                                               ^ (IData)(
                                                         (vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                                          >> 0x18U))) 
                                              << 0x18U))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xf3ffffffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x8000000U & (((0x62U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                              ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                         >> 0x1bU))) 
                             << 0x1bU)) | (0x4000000U 
                                           & (((0x23U 
                                                == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                                               ^ (IData)(
                                                         (vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                                          >> 0x1aU))) 
                                              << 0x1aU))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0xcfffffffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((0x20000000U & (((0x29U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                               ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                          >> 0x1dU))) 
                              << 0x1dU)) | (0x10000000U 
                                            & (((0x4aU 
                                                 == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                                                ^ (IData)(
                                                          (vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                                           >> 0x1cU))) 
                                               << 0x1cU))));
    __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o 
        = ((0x3fffffffU & __PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__data_o) 
           | ((((0x52U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                           >> 0x1fU))) << 0x1fU) | 
              (0x40000000U & (((0x16U == (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)) 
                               ^ (IData)((vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
                                          >> 0x1eU))) 
                              << 0x1eU))));
    vlSelf->__PVT__g_mem_ecc__DOT__ecc_err = ((2U & (IData)(vlSelf->__PVT__g_mem_ecc__DOT__ecc_err)) 
                                              | (1U 
                                                 & VL_REDXOR_8(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o)));
    vlSelf->__PVT__g_mem_ecc__DOT__ecc_err = ((1U & (IData)(vlSelf->__PVT__g_mem_ecc__DOT__ecc_err)) 
                                              | (((~ (IData)(vlSelf->__PVT__g_mem_ecc__DOT__ecc_err)) 
                                                  & (0U 
                                                     != (IData)(vlSelf->__PVT__g_mem_ecc__DOT__u_instr_intg_dec__DOT__syndrome_o))) 
                                                 << 1U));
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__3(Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__3\n"); );
    // Body
    vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_instr_seed_d 
        = (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__csr_wdata_int 
           ^ vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_instr_seed_q);
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__0(Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__0\n"); );
    // Init
    IData/*31:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata;
    __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata = 0;
    CData/*0:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err;
    __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err = 0;
    CData/*0:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unaligned_is_compressed;
    __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unaligned_is_compressed = 0;
    // Body
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_d[0U] 
        = ((2U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))
            ? vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q[1U]
            : (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_d[1U] 
        = (IData)((((QData)((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core)) 
                    << 0x20U) | (QData)((IData)(((4U 
                                                  & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))
                                                  ? 
                                                 vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q[2U]
                                                  : (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core))))));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_d[2U] 
        = (IData)(((((QData)((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core)) 
                     << 0x20U) | (QData)((IData)(((4U 
                                                   & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))
                                                   ? 
                                                  vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q[2U]
                                                   : (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core))))) 
                   >> 0x20U));
    vlSelf->__PVT__instr_err = ((0U != (IData)(vlSelf->__PVT__g_mem_ecc__DOT__ecc_err)) 
                                | (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__instr_err_q));
    if ((1U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))) {
        __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata 
            = vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q[0U];
        __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err 
            = (1U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q));
    } else {
        __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata 
            = (IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core);
        __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err 
            = (1U & (IData)(vlSelf->__PVT__instr_err));
    }
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_d 
        = (((IData)(vlSelf->__PVT__instr_err) << 2U) 
           | ((2U & (((4U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))
                       ? ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q) 
                          >> 2U) : (IData)(vlSelf->__PVT__instr_err)) 
                     << 1U)) | (1U & ((2U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))
                                       ? ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q) 
                                          >> 1U) : (IData)(vlSelf->__PVT__instr_err)))));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__aligned_is_compressed 
        = ((~ (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err)) 
           & (3U != (3U & __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata)));
    __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unaligned_is_compressed 
        = ((~ (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err)) 
           & (3U != (3U & (__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata 
                           >> 0x10U))));
    if ((1U & vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q)) {
        if ((2U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))) {
            vlSelf->__PVT__fetch_rdata = ((vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q[1U] 
                                           << 0x10U) 
                                          | (__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata 
                                             >> 0x10U));
            vlSelf->__PVT__fetch_err = (1U & (((~ (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unaligned_is_compressed)) 
                                               & ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q) 
                                                  >> 1U)) 
                                              | (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q)));
        } else {
            vlSelf->__PVT__fetch_rdata = (((IData)(vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core) 
                                           << 0x10U) 
                                          | (__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata 
                                             >> 0x10U));
            vlSelf->__PVT__fetch_err = (1U & (((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                                               & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q)) 
                                              | ((IData)(vlSelf->__PVT__instr_err) 
                                                 & ((~ (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q)) 
                                                    | (~ (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unaligned_is_compressed))))));
        }
        if (__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unaligned_is_compressed) {
            vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two = 1U;
            vlSelf->__PVT__fetch_valid_raw = (1U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid));
        } else {
            vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two = 0U;
            vlSelf->__PVT__fetch_valid_raw = (1U & 
                                              (((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                                                >> 1U) 
                                               | ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                                                  & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid))));
        }
    } else {
        vlSelf->__PVT__fetch_rdata = __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata;
        vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two 
            = vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__aligned_is_compressed;
        vlSelf->__PVT__fetch_err = (1U & (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err));
        vlSelf->__PVT__fetch_valid_raw = (1U & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid));
    }
    vlSelf->__Vcellinp__compressed_decoder_i__valid_i 
        = ((~ (IData)(vlSelf->__PVT__fetch_err)) & (IData)(vlSelf->__PVT__fetch_valid_raw));
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__1(Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__1\n"); );
    // Init
    IData/*31:0*/ __PVT__exc_pc;
    __PVT__exc_pc = 0;
    CData/*4:0*/ __PVT__irq_vec;
    __PVT__irq_vec = 0;
    CData/*0:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_new_req;
    __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_new_req = 0;
    CData/*0:0*/ gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_he9db8f89__0;
    gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_he9db8f89__0 = 0;
    CData/*0:0*/ __PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_en;
    __PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_en = 0;
    // Body
    __PVT__irq_vec = (0x1fU & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.exc_cause_o));
    if ((0x40U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.exc_cause_o))) {
        __PVT__irq_vec = 0x1fU;
    }
    __PVT__exc_pc = ((2U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.exc_pc_mux_o))
                      ? 0x100000U : ((1U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.exc_pc_mux_o))
                                      ? ((0xffffff00U 
                                          & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_mtvec_csr__DOT__rdata_q) 
                                         | ((IData)(__PVT__irq_vec) 
                                            << 2U))
                                      : (0xffffff00U 
                                         & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_mtvec_csr__DOT__rdata_q)));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__discard_req_d 
        = ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_req_q) 
           & ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o) 
              | (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__discard_req_q)));
    __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_new_req 
        = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.instr_req_o) 
           & ((~ ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q) 
                  >> 1U)) & ((~ (IData)((3U == (3U 
                                                & (((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                                                    >> 1U) 
                                                   | ((2U 
                                                       & ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q) 
                                                          << 1U)) 
                                                      | (1U 
                                                         & ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q) 
                                                            >> 1U)))))))) 
                             | (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o))));
    vlSelf->csr_mtvec_init_o = ((0U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_mux_o)) 
                                & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o));
    __PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_en 
        = ((IData)(vlSelf->__PVT__gen_dummy_instr__DOT__insert_dummy_instr) 
           & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.id_in_ready_o));
    vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i 
        = ((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o)) 
           & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.id_in_ready_o));
    vlSelf->__PVT__prefetch_addr = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o)
                                     ? (0xfffffffeU 
                                        & ((4U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_mux_o))
                                            ? ((2U 
                                                & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_mux_o))
                                                ? 0x100080U
                                                : (
                                                   (1U 
                                                    & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_mux_o))
                                                    ? 0x100080U
                                                    : vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_depc_csr__DOT__rdata_q))
                                            : ((2U 
                                                & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_mux_o))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_mux_o))
                                                    ? vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_mepc_csr__DOT__rdata_q
                                                    : __PVT__exc_pc)
                                                : (
                                                   (1U 
                                                    & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_mux_o))
                                                    ? (IData)(
                                                              (vlSymsp->TOP.tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                               >> 1U))
                                                    : 0x100080U))))
                                     : 0U);
    vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_hfddf9e70__0 
        = ((~ (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_req_q)) 
           & (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_new_req));
    vlSelf->instr_req_o = ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_req_q) 
                           | (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_new_req));
    vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_d 
        = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.dummy_instr_seed_en_o)
            ? vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_instr_seed_d
            : (((~ (IData)((0U != vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q))) 
                & (IData)(__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_en))
                ? 0xac533bf4U : ((IData)(__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_en)
                                  ? ((0x80200003U & 
                                      (- (IData)((1U 
                                                  & vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q)))) 
                                     ^ VL_SHIFTR_III(32,32,32, vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q, 1U))
                                  : vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_i__DOT__lfsr_q)));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_d 
        = ((IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_req_q)
            ? vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_q
            : ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o)
                ? vlSelf->__PVT__prefetch_addr : vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fetch_addr_q));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fetch_addr_d 
        = (((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o)
             ? vlSelf->__PVT__prefetch_addr : (0xfffffffcU 
                                               & vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fetch_addr_q)) 
           + ((IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_hfddf9e70__0) 
              << 2U));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_n 
        = ((2U & ((((IData)(vlSelf->instr_req_o) & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q)) 
                   << 1U) | (0xfffffffeU & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q)))) 
           | (1U & ((IData)(vlSelf->instr_req_o) | (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q))));
    gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_he9db8f89__0 
        = ((IData)(vlSelf->instr_req_o) & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__discard_req_d));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_n 
        = ((2U & ((((IData)(gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_he9db8f89__0) 
                    & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q)) 
                   << 1U) | (0xfffffffeU & ((((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o) 
                                              << 1U) 
                                             & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q)) 
                                            | (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_q))))) 
           | (1U & ((IData)(gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_he9db8f89__0) 
                    | (((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o) 
                        & (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q)) 
                       | (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_q)))));
}

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__2(Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__2\n"); );
    // Init
    IData/*31:0*/ __PVT__instr_decompressed;
    __PVT__instr_decompressed = 0;
    CData/*0:0*/ __VdfgTmp_h3d81f5b8__0;
    __VdfgTmp_h3d81f5b8__0 = 0;
    CData/*1:0*/ __PVT__compressed_decoder_i__DOT__gets_expanded;
    __PVT__compressed_decoder_i__DOT__gets_expanded = 0;
    CData/*0:0*/ __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo;
    __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo = 0;
    // Body
    vlSelf->__PVT__instr_new_id_d = ((IData)(vlSelf->__PVT__fetch_valid_raw) 
                                     & (IData)(vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i));
    __PVT__instr_decompressed = vlSelf->__PVT__fetch_rdata;
    vlSelf->__PVT__illegal_c_insn = 0U;
    __PVT__compressed_decoder_i__DOT__gets_expanded = 0U;
    vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d 
        = vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_q;
    vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d 
        = vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_q;
    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d 
        = vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q;
    if ((2U & vlSelf->__PVT__fetch_rdata)) {
        if ((1U & (~ vlSelf->__PVT__fetch_rdata))) {
            if ((0x8000U & vlSelf->__PVT__fetch_rdata)) {
                if ((0x4000U & vlSelf->__PVT__fetch_rdata)) {
                    if ((0x2000U & vlSelf->__PVT__fetch_rdata)) {
                        vlSelf->__PVT__illegal_c_insn = 1U;
                    } else {
                        __PVT__instr_decompressed = 
                            (0x12023U | ((0xc000000U 
                                          & (vlSelf->__PVT__fetch_rdata 
                                             << 0x13U)) 
                                         | ((0x2000000U 
                                             & (vlSelf->__PVT__fetch_rdata 
                                                << 0xdU)) 
                                            | ((0x1f00000U 
                                                & (vlSelf->__PVT__fetch_rdata 
                                                   << 0x12U)) 
                                               | (0xe00U 
                                                  & vlSelf->__PVT__fetch_rdata)))));
                    }
                } else if ((0x2000U & vlSelf->__PVT__fetch_rdata)) {
                    if ((0x1000U & vlSelf->__PVT__fetch_rdata)) {
                        if ((0x800U & vlSelf->__PVT__fetch_rdata)) {
                            if ((0x400U & vlSelf->__PVT__fetch_rdata)) {
                                if ((0x100U & vlSelf->__PVT__fetch_rdata)) {
                                    vlSelf->__PVT__illegal_c_insn = 1U;
                                } else {
                                    __PVT__compressed_decoder_i__DOT__gets_expanded = 1U;
                                    if ((4U & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                        if ((2U & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                            if ((1U 
                                                 & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                            } else {
                                                __PVT__instr_decompressed = 0x8067U;
                                                if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                    __PVT__compressed_decoder_i__DOT__gets_expanded = 3U;
                                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                                }
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                            __PVT__compressed_decoder_i__DOT__gets_expanded = 2U;
                                            if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 6U;
                                            }
                                            __PVT__instr_decompressed = 0x513U;
                                        } else {
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__spimm 
                                                = (3U 
                                                   & (vlSelf->__PVT__fetch_rdata 
                                                      >> 2U));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__rlist 
                                                = (0xfU 
                                                   & (vlSelf->__PVT__fetch_rdata 
                                                      >> 4U));
                                            __PVT__compressed_decoder_i__DOT__gets_expanded = 2U;
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__imm 
                                                = (0x7fU 
                                                   & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__imm));
                                            if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                if (
                                                    (0x1cU 
                                                     == 
                                                     (0x1fU 
                                                      & (vlSelf->__PVT__fetch_rdata 
                                                         >> 8U)))) {
                                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 5U;
                                                } else if (
                                                           (0x1eU 
                                                            == 
                                                            (0x1fU 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                >> 8U)))) {
                                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 6U;
                                                } else {
                                                    __PVT__compressed_decoder_i__DOT__gets_expanded = 3U;
                                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                                }
                                            }
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__4__spimm 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__spimm;
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__4__rlist 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__rlist;
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__4__Vfuncout 
                                                = (0x7fU 
                                                   & (([&]() {
                                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__5__rlist 
                                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__4__rlist;
                                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__5__Vfuncout 
                                                                = 
                                                                ((8U 
                                                                  & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__5__rlist))
                                                                  ? 
                                                                 ((4U 
                                                                   & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__5__rlist))
                                                                   ? 
                                                                  ((2U 
                                                                    & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__5__rlist))
                                                                    ? 
                                                                   ((1U 
                                                                     & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__5__rlist))
                                                                     ? 0x40U
                                                                     : 0x30U)
                                                                    : 0x30U)
                                                                   : 0x20U)
                                                                  : 
                                                                 ((4U 
                                                                   & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__5__rlist))
                                                                   ? 0x10U
                                                                   : 0U));
                                                        }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__5__Vfuncout)) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__4__spimm), 4U)));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__imm 
                                                = (
                                                   (0xf80U 
                                                    & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__imm)) 
                                                   | (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__4__Vfuncout));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__imm_signed 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__imm;
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__instr 
                                                = (0x10113U 
                                                   | ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__imm_signed) 
                                                      << 0x14U));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__Vfuncout 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__instr;
                                            __PVT__instr_decompressed 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__3__Vfuncout;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                        if ((1U & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__sp_offset 
                                                = vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_q;
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__rlist 
                                                = vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_q;
                                            if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d 
                                                    = 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_q) 
                                                        - (IData)(1U)));
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d 
                                                    = 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_q) 
                                                        - (IData)(1U)));
                                                if (
                                                    (4U 
                                                     == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_q))) {
                                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 4U;
                                                }
                                            }
                                            VL_ASSIGNSEL_II(32,12,0U, vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__instr, 
                                                            (3U 
                                                             | (([&]() {
                                                                vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist 
                                                                    = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__rlist;
                                                                vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__Vfuncout 
                                                                    = 
                                                                    (0x1fU 
                                                                     & ((0x10U 
                                                                         & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                         ? 
                                                                        ((8U 
                                                                          & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                          ? 0U
                                                                          : 
                                                                         ((4U 
                                                                           & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                           ? 0U
                                                                           : 
                                                                          ((2U 
                                                                            & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                            ? 0U
                                                                            : 
                                                                           ((1U 
                                                                             & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                             ? 0U
                                                                             : 
                                                                            ((IData)(0xbU) 
                                                                             + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))))))
                                                                         : 
                                                                        ((8U 
                                                                          & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                          ? 
                                                                         ((IData)(0xbU) 
                                                                          + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                          : 
                                                                         ((4U 
                                                                           & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                           ? 
                                                                          ((2U 
                                                                            & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                            ? 
                                                                           ((1U 
                                                                             & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                             ? 
                                                                            ((IData)(0xbU) 
                                                                             + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                             : 
                                                                            ((IData)(3U) 
                                                                             + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist)))
                                                                            : 
                                                                           ((1U 
                                                                             & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                             ? 
                                                                            ((IData)(3U) 
                                                                             + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))
                                                                             : 1U))
                                                                           : 0U))));
                                                            }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__7__Vfuncout)) 
                                                                << 7U)));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__instr 
                                                = (0x12000U 
                                                   | ((0xfffU 
                                                       & vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__instr) 
                                                      | ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__sp_offset) 
                                                         << 0x16U)));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__Vfuncout 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__instr;
                                            __PVT__instr_decompressed 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__6__Vfuncout;
                                        } else {
                                            vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                    } else {
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__8__instr_rlist 
                                            = (0xfU 
                                               & (vlSelf->__PVT__fetch_rdata 
                                                  >> 4U));
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__8__rlist 
                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__8__instr_rlist;
                                        if ((0xfU == (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__8__rlist))) {
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__8__rlist = 0x10U;
                                        }
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__8__Vfuncout 
                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__8__rlist;
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d 
                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__8__Vfuncout;
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d 
                                            = (0x1fU 
                                               & (([&]() {
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__9__spimm 
                                                            = 
                                                            (3U 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                >> 2U));
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__9__rlist 
                                                            = 
                                                            (0xfU 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                >> 4U));
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__10__spimm 
                                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__9__spimm;
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__10__rlist 
                                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__9__rlist;
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__10__Vfuncout 
                                                            = 
                                                            (0x7fU 
                                                             & (([&]() {
                                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__11__rlist 
                                                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__10__rlist;
                                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__11__Vfuncout 
                                                                            = 
                                                                            ((8U 
                                                                              & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__11__rlist))
                                                                              ? 
                                                                             ((4U 
                                                                               & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__11__rlist))
                                                                               ? 
                                                                              ((2U 
                                                                                & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__11__rlist))
                                                                                ? 
                                                                               ((1U 
                                                                                & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__11__rlist))
                                                                                 ? 0x40U
                                                                                 : 0x30U)
                                                                                : 0x30U)
                                                                               : 0x20U)
                                                                              : 
                                                                             ((4U 
                                                                               & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__11__rlist))
                                                                               ? 0x10U
                                                                               : 0U));
                                                                    }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__11__Vfuncout)) 
                                                                + 
                                                                VL_SHIFTL_III(7,32,32, (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__10__spimm), 4U)));
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__9__tmp 
                                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__10__Vfuncout;
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__9__Vfuncout 
                                                            = 
                                                            (0x1fU 
                                                             & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__9__tmp) 
                                                                >> 2U));
                                                    }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__9__Vfuncout)) 
                                                  - (IData)(1U)));
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__sp_offset 
                                            = vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d;
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__rlist 
                                            = vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d;
                                        VL_ASSIGNSEL_II(32,12,0U, vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__instr, 
                                                        (3U 
                                                         | (([&]() {
                                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist 
                                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__rlist;
                                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__Vfuncout 
                                                                = 
                                                                (0x1fU 
                                                                 & ((0x10U 
                                                                     & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                     ? 
                                                                    ((8U 
                                                                      & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                      ? 0U
                                                                      : 
                                                                     ((4U 
                                                                       & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                       ? 0U
                                                                       : 
                                                                      ((2U 
                                                                        & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                        ? 0U
                                                                        : 
                                                                       ((1U 
                                                                         & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                         ? 0U
                                                                         : 
                                                                        ((IData)(0xbU) 
                                                                         + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))))))
                                                                     : 
                                                                    ((8U 
                                                                      & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                      ? 
                                                                     ((IData)(0xbU) 
                                                                      + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                      : 
                                                                     ((4U 
                                                                       & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                       ? 
                                                                      ((2U 
                                                                        & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                        ? 
                                                                       ((1U 
                                                                         & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                         ? 
                                                                        ((IData)(0xbU) 
                                                                         + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                         : 
                                                                        ((IData)(3U) 
                                                                         + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist)))
                                                                        : 
                                                                       ((1U 
                                                                         & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                         ? 
                                                                        ((IData)(3U) 
                                                                         + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))
                                                                         : 1U))
                                                                       : 0U))));
                                                        }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__13__Vfuncout)) 
                                                            << 7U)));
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__instr 
                                            = (0x12000U 
                                               | ((0xfffU 
                                                   & vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__instr) 
                                                  | ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__sp_offset) 
                                                     << 0x16U)));
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__Vfuncout 
                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__instr;
                                        __PVT__instr_decompressed 
                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__12__Vfuncout;
                                        if ((3U >= (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d))) {
                                            vlSelf->__PVT__illegal_c_insn = 1U;
                                        } else if (
                                                   (4U 
                                                    == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d))) {
                                            if (((IData)(vlSelf->__Vcellinp__compressed_decoder_i__valid_i) 
                                                 & (IData)(vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 4U;
                                            }
                                        } else {
                                            vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d 
                                                = (0x1fU 
                                                   & ((IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d) 
                                                      - (IData)(1U)));
                                            vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d 
                                                = (0x1fU 
                                                   & ((IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d) 
                                                      - (IData)(1U)));
                                            if (((IData)(vlSelf->__Vcellinp__compressed_decoder_i__valid_i) 
                                                 & (IData)(vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 3U;
                                            }
                                        }
                                    }
                                }
                            } else if ((0x200U & vlSelf->__PVT__fetch_rdata)) {
                                if ((0x100U & vlSelf->__PVT__fetch_rdata)) {
                                    vlSelf->__PVT__illegal_c_insn = 1U;
                                } else {
                                    __PVT__compressed_decoder_i__DOT__gets_expanded = 1U;
                                    if ((4U & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                        if ((2U & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                            if ((1U 
                                                 & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                            } else {
                                                __PVT__instr_decompressed = 0x8067U;
                                                if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                    __PVT__compressed_decoder_i__DOT__gets_expanded = 3U;
                                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                                }
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                            __PVT__compressed_decoder_i__DOT__gets_expanded = 2U;
                                            if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 6U;
                                            }
                                            __PVT__instr_decompressed = 0x513U;
                                        } else {
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__spimm 
                                                = (3U 
                                                   & (vlSelf->__PVT__fetch_rdata 
                                                      >> 2U));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__rlist 
                                                = (0xfU 
                                                   & (vlSelf->__PVT__fetch_rdata 
                                                      >> 4U));
                                            __PVT__compressed_decoder_i__DOT__gets_expanded = 2U;
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__imm 
                                                = (0x7fU 
                                                   & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__imm));
                                            if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                if (
                                                    (0x1cU 
                                                     == 
                                                     (0x1fU 
                                                      & (vlSelf->__PVT__fetch_rdata 
                                                         >> 8U)))) {
                                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 5U;
                                                } else if (
                                                           (0x1eU 
                                                            == 
                                                            (0x1fU 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                >> 8U)))) {
                                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 6U;
                                                } else {
                                                    __PVT__compressed_decoder_i__DOT__gets_expanded = 3U;
                                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                                }
                                            }
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__18__spimm 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__spimm;
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__18__rlist 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__rlist;
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__18__Vfuncout 
                                                = (0x7fU 
                                                   & (([&]() {
                                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__19__rlist 
                                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__18__rlist;
                                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__19__Vfuncout 
                                                                = 
                                                                ((8U 
                                                                  & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__19__rlist))
                                                                  ? 
                                                                 ((4U 
                                                                   & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__19__rlist))
                                                                   ? 
                                                                  ((2U 
                                                                    & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__19__rlist))
                                                                    ? 
                                                                   ((1U 
                                                                     & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__19__rlist))
                                                                     ? 0x40U
                                                                     : 0x30U)
                                                                    : 0x30U)
                                                                   : 0x20U)
                                                                  : 
                                                                 ((4U 
                                                                   & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__19__rlist))
                                                                   ? 0x10U
                                                                   : 0U));
                                                        }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__19__Vfuncout)) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__18__spimm), 4U)));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__imm 
                                                = (
                                                   (0xf80U 
                                                    & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__imm)) 
                                                   | (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__18__Vfuncout));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__imm_signed 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__imm;
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__instr 
                                                = (0x10113U 
                                                   | ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__imm_signed) 
                                                      << 0x14U));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__Vfuncout 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__instr;
                                            __PVT__instr_decompressed 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__17__Vfuncout;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                        if ((1U & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__sp_offset 
                                                = vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_q;
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__rlist 
                                                = vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_q;
                                            if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d 
                                                    = 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_q) 
                                                        - (IData)(1U)));
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d 
                                                    = 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_q) 
                                                        - (IData)(1U)));
                                                if (
                                                    (4U 
                                                     == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_q))) {
                                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 4U;
                                                }
                                            }
                                            VL_ASSIGNSEL_II(32,12,0U, vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__instr, 
                                                            (3U 
                                                             | (([&]() {
                                                                vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist 
                                                                    = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__rlist;
                                                                vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__Vfuncout 
                                                                    = 
                                                                    (0x1fU 
                                                                     & ((0x10U 
                                                                         & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                         ? 
                                                                        ((8U 
                                                                          & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                          ? 0U
                                                                          : 
                                                                         ((4U 
                                                                           & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                           ? 0U
                                                                           : 
                                                                          ((2U 
                                                                            & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                            ? 0U
                                                                            : 
                                                                           ((1U 
                                                                             & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                             ? 0U
                                                                             : 
                                                                            ((IData)(0xbU) 
                                                                             + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))))))
                                                                         : 
                                                                        ((8U 
                                                                          & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                          ? 
                                                                         ((IData)(0xbU) 
                                                                          + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                          : 
                                                                         ((4U 
                                                                           & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                           ? 
                                                                          ((2U 
                                                                            & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                            ? 
                                                                           ((1U 
                                                                             & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                             ? 
                                                                            ((IData)(0xbU) 
                                                                             + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                             : 
                                                                            ((IData)(3U) 
                                                                             + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist)))
                                                                            : 
                                                                           ((1U 
                                                                             & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                             ? 
                                                                            ((IData)(3U) 
                                                                             + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))
                                                                             : 1U))
                                                                           : 0U))));
                                                            }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__21__Vfuncout)) 
                                                                << 7U)));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__instr 
                                                = (0x12000U 
                                                   | ((0xfffU 
                                                       & vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__instr) 
                                                      | ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__sp_offset) 
                                                         << 0x16U)));
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__Vfuncout 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__instr;
                                            __PVT__instr_decompressed 
                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__20__Vfuncout;
                                        } else {
                                            vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                    } else {
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__22__instr_rlist 
                                            = (0xfU 
                                               & (vlSelf->__PVT__fetch_rdata 
                                                  >> 4U));
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__22__rlist 
                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__22__instr_rlist;
                                        if ((0xfU == (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__22__rlist))) {
                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__22__rlist = 0x10U;
                                        }
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__22__Vfuncout 
                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__22__rlist;
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d 
                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__22__Vfuncout;
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d 
                                            = (0x1fU 
                                               & (([&]() {
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__23__spimm 
                                                            = 
                                                            (3U 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                >> 2U));
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__23__rlist 
                                                            = 
                                                            (0xfU 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                >> 4U));
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__24__spimm 
                                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__23__spimm;
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__24__rlist 
                                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__23__rlist;
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__24__Vfuncout 
                                                            = 
                                                            (0x7fU 
                                                             & (([&]() {
                                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__25__rlist 
                                                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__24__rlist;
                                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__25__Vfuncout 
                                                                            = 
                                                                            ((8U 
                                                                              & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__25__rlist))
                                                                              ? 
                                                                             ((4U 
                                                                               & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__25__rlist))
                                                                               ? 
                                                                              ((2U 
                                                                                & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__25__rlist))
                                                                                ? 
                                                                               ((1U 
                                                                                & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__25__rlist))
                                                                                 ? 0x40U
                                                                                 : 0x30U)
                                                                                : 0x30U)
                                                                               : 0x20U)
                                                                              : 
                                                                             ((4U 
                                                                               & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__25__rlist))
                                                                               ? 0x10U
                                                                               : 0U));
                                                                    }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__25__Vfuncout)) 
                                                                + 
                                                                VL_SHIFTL_III(7,32,32, (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__24__spimm), 4U)));
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__23__tmp 
                                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__24__Vfuncout;
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__23__Vfuncout 
                                                            = 
                                                            (0x1fU 
                                                             & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__23__tmp) 
                                                                >> 2U));
                                                    }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_word__23__Vfuncout)) 
                                                  - (IData)(1U)));
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__sp_offset 
                                            = vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d;
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__rlist 
                                            = vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d;
                                        VL_ASSIGNSEL_II(32,12,0U, vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__instr, 
                                                        (3U 
                                                         | (([&]() {
                                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist 
                                                                = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__rlist;
                                                            vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__Vfuncout 
                                                                = 
                                                                (0x1fU 
                                                                 & ((0x10U 
                                                                     & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                     ? 
                                                                    ((8U 
                                                                      & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                      ? 0U
                                                                      : 
                                                                     ((4U 
                                                                       & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                       ? 0U
                                                                       : 
                                                                      ((2U 
                                                                        & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                        ? 0U
                                                                        : 
                                                                       ((1U 
                                                                         & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                         ? 0U
                                                                         : 
                                                                        ((IData)(0xbU) 
                                                                         + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))))))
                                                                     : 
                                                                    ((8U 
                                                                      & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                      ? 
                                                                     ((IData)(0xbU) 
                                                                      + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                      : 
                                                                     ((4U 
                                                                       & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                       ? 
                                                                      ((2U 
                                                                        & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                        ? 
                                                                       ((1U 
                                                                         & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                         ? 
                                                                        ((IData)(0xbU) 
                                                                         + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                         : 
                                                                        ((IData)(3U) 
                                                                         + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist)))
                                                                        : 
                                                                       ((1U 
                                                                         & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                         ? 
                                                                        ((IData)(3U) 
                                                                         + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))
                                                                         : 1U))
                                                                       : 0U))));
                                                        }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__27__Vfuncout)) 
                                                            << 7U)));
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__instr 
                                            = (0x12000U 
                                               | ((0xfffU 
                                                   & vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__instr) 
                                                  | ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__sp_offset) 
                                                     << 0x16U)));
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__Vfuncout 
                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__instr;
                                        __PVT__instr_decompressed 
                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_pop_load_reg__26__Vfuncout;
                                        if ((3U >= (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d))) {
                                            vlSelf->__PVT__illegal_c_insn = 1U;
                                        } else if (
                                                   (4U 
                                                    == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d))) {
                                            if (((IData)(vlSelf->__Vcellinp__compressed_decoder_i__valid_i) 
                                                 & (IData)(vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 4U;
                                            }
                                        } else {
                                            vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d 
                                                = (0x1fU 
                                                   & ((IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d) 
                                                      - (IData)(1U)));
                                            vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d 
                                                = (0x1fU 
                                                   & ((IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d) 
                                                      - (IData)(1U)));
                                            if (((IData)(vlSelf->__Vcellinp__compressed_decoder_i__valid_i) 
                                                 & (IData)(vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                                vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 3U;
                                            }
                                        }
                                    }
                                }
                            } else if ((0x100U & vlSelf->__PVT__fetch_rdata)) {
                                vlSelf->__PVT__illegal_c_insn = 1U;
                            } else {
                                __PVT__compressed_decoder_i__DOT__gets_expanded = 1U;
                                if ((0U == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__28__instr_rlist 
                                        = (0xfU & (vlSelf->__PVT__fetch_rdata 
                                                   >> 4U));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__28__rlist 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__28__instr_rlist;
                                    if ((0xfU == (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__28__rlist))) {
                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__28__rlist = 0x10U;
                                    }
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__28__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__28__rlist;
                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_init__28__Vfuncout;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__29__rlist 
                                        = vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__29__instr 
                                        = (0x2e23U 
                                           | (0xffff8000U 
                                              & vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__29__instr));
                                    VL_ASSIGNSEL_II(32,10,0xfU, vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__29__instr, 
                                                    (2U 
                                                     | (([&]() {
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist 
                                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__29__rlist;
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__Vfuncout 
                                                            = 
                                                            (0x1fU 
                                                             & ((0x10U 
                                                                 & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                 ? 
                                                                ((8U 
                                                                  & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                  ? 0U
                                                                  : 
                                                                 ((4U 
                                                                   & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                   ? 0U
                                                                   : 
                                                                  ((2U 
                                                                    & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                    ? 0U
                                                                    : 
                                                                   ((1U 
                                                                     & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                     ? 0U
                                                                     : 
                                                                    ((IData)(0xbU) 
                                                                     + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))))))
                                                                 : 
                                                                ((8U 
                                                                  & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                  ? 
                                                                 ((IData)(0xbU) 
                                                                  + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                  : 
                                                                 ((4U 
                                                                   & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                   ? 
                                                                  ((2U 
                                                                    & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                    ? 
                                                                   ((1U 
                                                                     & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                     ? 
                                                                    ((IData)(0xbU) 
                                                                     + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                     : 
                                                                    ((IData)(3U) 
                                                                     + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist)))
                                                                    : 
                                                                   ((1U 
                                                                     & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                     ? 
                                                                    ((IData)(3U) 
                                                                     + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))
                                                                     : 1U))
                                                                   : 0U))));
                                                    }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__30__Vfuncout)) 
                                                        << 5U)));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__29__instr 
                                        = (0xfe000000U 
                                           | vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__29__instr);
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__29__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__29__instr;
                                    __PVT__instr_decompressed 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__29__Vfuncout;
                                    if ((3U >= (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d))) {
                                        vlSelf->__PVT__illegal_c_insn = 1U;
                                    } else if ((4U 
                                                == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d))) {
                                        if (((IData)(vlSelf->__Vcellinp__compressed_decoder_i__valid_i) 
                                             & (IData)(vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                            vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 2U;
                                        }
                                    } else {
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d 
                                            = (0x1fU 
                                               & ((IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d) 
                                                  - (IData)(1U)));
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d = 2U;
                                        if (((IData)(vlSelf->__Vcellinp__compressed_decoder_i__valid_i) 
                                             & (IData)(vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                            vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 1U;
                                        }
                                    }
                                } else if ((1U == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__sp_offset 
                                        = vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_q;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__rlist 
                                        = vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_q;
                                    if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_d 
                                            = (0x1fU 
                                               & ((IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_q) 
                                                  - (IData)(1U)));
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_d 
                                            = (0x1fU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_sp_offset_q)));
                                        if ((4U == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_rlist_q))) {
                                            vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 2U;
                                        }
                                    }
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__neg_offset_signed 
                                        = (0xfffU & 
                                           (- ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__sp_offset) 
                                               << 2U)));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__neg_offset 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__neg_offset_signed;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__instr 
                                        = (0x2023U 
                                           | ((0xffff8000U 
                                               & vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__instr) 
                                              | (0xf80U 
                                                 & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__neg_offset) 
                                                    << 7U))));
                                    VL_ASSIGNSEL_II(32,10,0xfU, vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__instr, 
                                                    (2U 
                                                     | (([&]() {
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist 
                                                            = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__rlist;
                                                        vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__Vfuncout 
                                                            = 
                                                            (0x1fU 
                                                             & ((0x10U 
                                                                 & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                 ? 
                                                                ((8U 
                                                                  & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                  ? 0U
                                                                  : 
                                                                 ((4U 
                                                                   & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                   ? 0U
                                                                   : 
                                                                  ((2U 
                                                                    & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                    ? 0U
                                                                    : 
                                                                   ((1U 
                                                                     & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                     ? 0U
                                                                     : 
                                                                    ((IData)(0xbU) 
                                                                     + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))))))
                                                                 : 
                                                                ((8U 
                                                                  & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                  ? 
                                                                 ((IData)(0xbU) 
                                                                  + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                  : 
                                                                 ((4U 
                                                                   & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                   ? 
                                                                  ((2U 
                                                                    & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                    ? 
                                                                   ((1U 
                                                                     & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                     ? 
                                                                    ((IData)(0xbU) 
                                                                     + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                     : 
                                                                    ((IData)(3U) 
                                                                     + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist)))
                                                                    : 
                                                                   ((1U 
                                                                     & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                     ? 
                                                                    ((IData)(3U) 
                                                                     + (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))
                                                                     : 1U))
                                                                   : 0U))));
                                                    }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_rlist_top_reg__32__Vfuncout)) 
                                                        << 5U)));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__instr 
                                        = ((0x1ffffffU 
                                            & vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__instr) 
                                           | (0xfe000000U 
                                              & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__neg_offset) 
                                                 << 0x14U)));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__instr;
                                    __PVT__instr_decompressed 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_push_store_reg__31__Vfuncout;
                                } else if ((2U == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__spimm 
                                        = (3U & (vlSelf->__PVT__fetch_rdata 
                                                 >> 2U));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__rlist 
                                        = (0xfU & (vlSelf->__PVT__fetch_rdata 
                                                   >> 4U));
                                    if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                        __PVT__compressed_decoder_i__DOT__gets_expanded = 3U;
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                    }
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__imm 
                                        = (0x7fU & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__imm));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__34__spimm 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__spimm;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__34__rlist 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__rlist;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__34__Vfuncout 
                                        = (0x7fU & 
                                           (([&]() {
                                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__35__rlist 
                                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__34__rlist;
                                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__35__Vfuncout 
                                                        = 
                                                        ((8U 
                                                          & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__35__rlist))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__35__rlist))
                                                           ? 
                                                          ((2U 
                                                            & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__35__rlist))
                                                            ? 
                                                           ((1U 
                                                             & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__35__rlist))
                                                             ? 0x40U
                                                             : 0x30U)
                                                            : 0x30U)
                                                           : 0x20U)
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__35__rlist))
                                                           ? 0x10U
                                                           : 0U));
                                                }(), (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj_base__35__Vfuncout)) 
                                            + VL_SHIFTL_III(7,32,32, (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__34__spimm), 4U)));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__imm 
                                        = ((0xf80U 
                                            & (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__imm)) 
                                           | (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_stack_adj__34__Vfuncout));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__imm_signed 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__imm;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__instr 
                                        = (0x10113U 
                                           | ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__imm_signed) 
                                              << 0x14U));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__instr;
                                    __PVT__instr_decompressed 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_sp_addi__33__Vfuncout;
                                } else {
                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                }
                            }
                        } else {
                            vlSelf->__PVT__illegal_c_insn = 1U;
                        }
                    } else if ((0x800U & vlSelf->__PVT__fetch_rdata)) {
                        if ((0x400U & vlSelf->__PVT__fetch_rdata)) {
                            if ((1U == (3U & (vlSelf->__PVT__fetch_rdata 
                                              >> 5U)))) {
                                __PVT__compressed_decoder_i__DOT__gets_expanded = 1U;
                                if ((0U == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__36__rs 
                                        = (7U & (vlSelf->__PVT__fetch_rdata 
                                                 >> 7U));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__36__dst 
                                        = (((0U < (3U 
                                                   & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__36__rs) 
                                                      >> 1U))) 
                                            << 4U) 
                                           | (((0U 
                                                == 
                                                (3U 
                                                 & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__36__rs) 
                                                    >> 1U))) 
                                               << 3U) 
                                              | (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__36__rs)));
                                    __PVT__compressed_decoder_i__DOT__gets_expanded = 2U;
                                    if (((IData)(vlSelf->__Vcellinp__compressed_decoder_i__valid_i) 
                                         & (IData)(vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 7U;
                                    }
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__37__dst 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__36__dst;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__37__instr 
                                        = (0x50013U 
                                           | ((0xfff00000U 
                                               & vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__37__instr) 
                                              | ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__37__dst) 
                                                 << 7U)));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__37__instr 
                                        = (0xfffffU 
                                           & vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__37__instr);
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__37__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__37__instr;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__36__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__37__Vfuncout;
                                    __PVT__instr_decompressed 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__36__Vfuncout;
                                } else if ((7U == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__38__rs 
                                        = (7U & (vlSelf->__PVT__fetch_rdata 
                                                 >> 2U));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__38__dst 
                                        = (((0U < (3U 
                                                   & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__38__rs) 
                                                      >> 1U))) 
                                            << 4U) 
                                           | (((0U 
                                                == 
                                                (3U 
                                                 & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__38__rs) 
                                                    >> 1U))) 
                                               << 3U) 
                                              | (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__38__rs)));
                                    if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                        __PVT__compressed_decoder_i__DOT__gets_expanded = 3U;
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                    }
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__39__dst 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__38__dst;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__39__instr 
                                        = (0x58013U 
                                           | ((0xfff00000U 
                                               & vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__39__instr) 
                                              | ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__39__dst) 
                                                 << 7U)));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__39__instr 
                                        = (0xfffffU 
                                           & vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__39__instr);
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__39__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__39__instr;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__38__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__39__Vfuncout;
                                    __PVT__instr_decompressed 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mvsa01__38__Vfuncout;
                                } else {
                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                }
                            } else if ((3U == (3U & 
                                               (vlSelf->__PVT__fetch_rdata 
                                                >> 5U)))) {
                                __PVT__compressed_decoder_i__DOT__gets_expanded = 1U;
                                if ((0U == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__40__rs 
                                        = (7U & (vlSelf->__PVT__fetch_rdata 
                                                 >> 7U));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__40__src 
                                        = (((0U < (3U 
                                                   & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__40__rs) 
                                                      >> 1U))) 
                                            << 4U) 
                                           | (((0U 
                                                == 
                                                (3U 
                                                 & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__40__rs) 
                                                    >> 1U))) 
                                               << 3U) 
                                              | (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__40__rs)));
                                    __PVT__compressed_decoder_i__DOT__gets_expanded = 2U;
                                    if (((IData)(vlSelf->__Vcellinp__compressed_decoder_i__valid_i) 
                                         & (IData)(vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 7U;
                                    }
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__41__src 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__40__src;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__41__instr 
                                        = (0x513U | 
                                           ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__41__src) 
                                            << 0xfU));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__41__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__41__instr;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__40__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__41__Vfuncout;
                                    __PVT__instr_decompressed 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__40__Vfuncout;
                                } else if ((7U == (IData)(vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_q))) {
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__42__rs 
                                        = (7U & (vlSelf->__PVT__fetch_rdata 
                                                 >> 2U));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__42__src 
                                        = (((0U < (3U 
                                                   & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__42__rs) 
                                                      >> 1U))) 
                                            << 4U) 
                                           | (((0U 
                                                == 
                                                (3U 
                                                 & ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__42__rs) 
                                                    >> 1U))) 
                                               << 3U) 
                                              | (IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__42__rs)));
                                    if (vlSelf->__Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                        __PVT__compressed_decoder_i__DOT__gets_expanded = 3U;
                                        vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                    }
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__43__src 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__42__src;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__43__instr 
                                        = (0x593U | 
                                           ((IData)(vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__43__src) 
                                            << 0xfU));
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__43__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__43__instr;
                                    vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__42__Vfuncout 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mv_reg__43__Vfuncout;
                                    __PVT__instr_decompressed 
                                        = vlSelf->__Vfunc_compressed_decoder_i__DOT__cm_mva01s__42__Vfuncout;
                                } else {
                                    vlSelf->__PVT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                }
                            } else {
                                vlSelf->__PVT__illegal_c_insn = 1U;
                            }
                        } else {
                            vlSelf->__PVT__illegal_c_insn = 1U;
                        }
                    } else {
                        vlSelf->__PVT__illegal_c_insn = 1U;
                    }
                } else if ((0x1000U & vlSelf->__PVT__fetch_rdata)) {
                    __PVT__instr_decompressed = ((0U 
                                                  != 
                                                  (0x1fU 
                                                   & (vlSelf->__PVT__fetch_rdata 
                                                      >> 2U)))
                                                  ? 
                                                 (0x33U 
                                                  | ((0x1f00000U 
                                                      & (vlSelf->__PVT__fetch_rdata 
                                                         << 0x12U)) 
                                                     | ((0xf8000U 
                                                         & (vlSelf->__PVT__fetch_rdata 
                                                            << 8U)) 
                                                        | (0xf80U 
                                                           & vlSelf->__PVT__fetch_rdata))))
                                                  : 
                                                 ((0U 
                                                   == 
                                                   (0x1fU 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       >> 7U)))
                                                   ? 0x100073U
                                                   : 
                                                  (0xe7U 
                                                   | (0xf8000U 
                                                      & (vlSelf->__PVT__fetch_rdata 
                                                         << 8U)))));
                } else if ((0U != (0x1fU & (vlSelf->__PVT__fetch_rdata 
                                            >> 2U)))) {
                    __PVT__instr_decompressed = (0x33U 
                                                 | ((0x1f00000U 
                                                     & (vlSelf->__PVT__fetch_rdata 
                                                        << 0x12U)) 
                                                    | (0xf80U 
                                                       & vlSelf->__PVT__fetch_rdata)));
                } else {
                    __PVT__instr_decompressed = (0x67U 
                                                 | (0xf8000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 8U)));
                    if ((0U == (0x1fU & (vlSelf->__PVT__fetch_rdata 
                                         >> 7U)))) {
                        vlSelf->__PVT__illegal_c_insn = 1U;
                    }
                }
            } else if ((0x4000U & vlSelf->__PVT__fetch_rdata)) {
                if ((0x2000U & vlSelf->__PVT__fetch_rdata)) {
                    vlSelf->__PVT__illegal_c_insn = 1U;
                } else {
                    __PVT__instr_decompressed = (0x12003U 
                                                 | ((0xc000000U 
                                                     & (vlSelf->__PVT__fetch_rdata 
                                                        << 0x18U)) 
                                                    | ((0x2000000U 
                                                        & (vlSelf->__PVT__fetch_rdata 
                                                           << 0xdU)) 
                                                       | ((0x1c00000U 
                                                           & (vlSelf->__PVT__fetch_rdata 
                                                              << 0x12U)) 
                                                          | (0xf80U 
                                                             & vlSelf->__PVT__fetch_rdata)))));
                    if ((0U == (0x1fU & (vlSelf->__PVT__fetch_rdata 
                                         >> 7U)))) {
                        vlSelf->__PVT__illegal_c_insn = 1U;
                    }
                }
            } else if ((0x2000U & vlSelf->__PVT__fetch_rdata)) {
                vlSelf->__PVT__illegal_c_insn = 1U;
            } else {
                __PVT__instr_decompressed = (0x1013U 
                                             | ((0x1f00000U 
                                                 & (vlSelf->__PVT__fetch_rdata 
                                                    << 0x12U)) 
                                                | ((0xf8000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 8U)) 
                                                   | (0xf80U 
                                                      & vlSelf->__PVT__fetch_rdata))));
                if ((0x1000U & vlSelf->__PVT__fetch_rdata)) {
                    vlSelf->__PVT__illegal_c_insn = 1U;
                }
            }
        }
    } else if ((1U & vlSelf->__PVT__fetch_rdata)) {
        if ((0x8000U & vlSelf->__PVT__fetch_rdata)) {
            if ((0x4000U & vlSelf->__PVT__fetch_rdata)) {
                __PVT__instr_decompressed = (0x40063U 
                                             | (((- (IData)(
                                                            (1U 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                >> 0xcU)))) 
                                                 << 0x1cU) 
                                                | ((0xc000000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 0x15U)) 
                                                   | ((0x2000000U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 0x17U)) 
                                                      | ((0x38000U 
                                                          & (vlSelf->__PVT__fetch_rdata 
                                                             << 8U)) 
                                                         | ((0x1000U 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                >> 1U)) 
                                                            | ((0xc00U 
                                                                & vlSelf->__PVT__fetch_rdata) 
                                                               | ((0x300U 
                                                                   & (vlSelf->__PVT__fetch_rdata 
                                                                      << 5U)) 
                                                                  | (0x80U 
                                                                     & (vlSelf->__PVT__fetch_rdata 
                                                                        >> 5U))))))))));
            } else if ((0x2000U & vlSelf->__PVT__fetch_rdata)) {
                __PVT__instr_decompressed = (0x6fU 
                                             | ((0x80000000U 
                                                 & (vlSelf->__PVT__fetch_rdata 
                                                    << 0x13U)) 
                                                | ((0x40000000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 0x16U)) 
                                                   | ((0x30000000U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 0x13U)) 
                                                      | ((0x8000000U 
                                                          & (vlSelf->__PVT__fetch_rdata 
                                                             << 0x15U)) 
                                                         | ((0x4000000U 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                << 0x13U)) 
                                                            | ((0x2000000U 
                                                                & (vlSelf->__PVT__fetch_rdata 
                                                                   << 0x17U)) 
                                                               | ((0x1000000U 
                                                                   & (vlSelf->__PVT__fetch_rdata 
                                                                      << 0xdU)) 
                                                                  | ((0xe00000U 
                                                                      & (vlSelf->__PVT__fetch_rdata 
                                                                         << 0x12U)) 
                                                                     | ((0x1ff000U 
                                                                         & ((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->__PVT__fetch_rdata 
                                                                                >> 0xcU)))) 
                                                                            << 0xcU)) 
                                                                        | (0x80U 
                                                                           & ((~ 
                                                                               (vlSelf->__PVT__fetch_rdata 
                                                                                >> 0xfU)) 
                                                                              << 7U))))))))))));
            } else if ((0x800U & vlSelf->__PVT__fetch_rdata)) {
                if ((0x400U & vlSelf->__PVT__fetch_rdata)) {
                    if ((0x1000U & vlSelf->__PVT__fetch_rdata)) {
                        if ((0x40U & vlSelf->__PVT__fetch_rdata)) {
                            if ((0x20U & vlSelf->__PVT__fetch_rdata)) {
                                if ((0x10U & vlSelf->__PVT__fetch_rdata)) {
                                    if ((8U & vlSelf->__PVT__fetch_rdata)) {
                                        vlSelf->__PVT__illegal_c_insn = 1U;
                                    } else if ((4U 
                                                & vlSelf->__PVT__fetch_rdata)) {
                                        __PVT__instr_decompressed 
                                            = (0xfff44413U 
                                               | ((0x38000U 
                                                   & (vlSelf->__PVT__fetch_rdata 
                                                      << 8U)) 
                                                  | (0x380U 
                                                     & vlSelf->__PVT__fetch_rdata)));
                                    } else {
                                        vlSelf->__PVT__illegal_c_insn = 1U;
                                    }
                                } else {
                                    __PVT__instr_decompressed 
                                        = ((8U & vlSelf->__PVT__fetch_rdata)
                                            ? ((4U 
                                                & vlSelf->__PVT__fetch_rdata)
                                                ? (0x60541413U 
                                                   | ((0x38000U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 8U)) 
                                                      | (0x380U 
                                                         & vlSelf->__PVT__fetch_rdata)))
                                                : (0x8044433U 
                                                   | ((0x38000U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 8U)) 
                                                      | (0x380U 
                                                         & vlSelf->__PVT__fetch_rdata))))
                                            : ((4U 
                                                & vlSelf->__PVT__fetch_rdata)
                                                ? (0x60441413U 
                                                   | ((0x38000U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 8U)) 
                                                      | (0x380U 
                                                         & vlSelf->__PVT__fetch_rdata)))
                                                : (0xff47413U 
                                                   | ((0x38000U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 8U)) 
                                                      | (0x380U 
                                                         & vlSelf->__PVT__fetch_rdata)))));
                                }
                            } else {
                                __PVT__instr_decompressed 
                                    = (0x2840433U | 
                                       ((0x700000U 
                                         & (vlSelf->__PVT__fetch_rdata 
                                            << 0x12U)) 
                                        | ((0x38000U 
                                            & (vlSelf->__PVT__fetch_rdata 
                                               << 8U)) 
                                           | (0x380U 
                                              & vlSelf->__PVT__fetch_rdata))));
                            }
                        } else {
                            vlSelf->__PVT__illegal_c_insn = 1U;
                        }
                    } else {
                        __PVT__instr_decompressed = 
                            ((0x40U & vlSelf->__PVT__fetch_rdata)
                              ? ((0x20U & vlSelf->__PVT__fetch_rdata)
                                  ? (0x847433U | ((0x700000U 
                                                   & (vlSelf->__PVT__fetch_rdata 
                                                      << 0x12U)) 
                                                  | ((0x38000U 
                                                      & (vlSelf->__PVT__fetch_rdata 
                                                         << 8U)) 
                                                     | (0x380U 
                                                        & vlSelf->__PVT__fetch_rdata))))
                                  : (0x846433U | ((0x700000U 
                                                   & (vlSelf->__PVT__fetch_rdata 
                                                      << 0x12U)) 
                                                  | ((0x38000U 
                                                      & (vlSelf->__PVT__fetch_rdata 
                                                         << 8U)) 
                                                     | (0x380U 
                                                        & vlSelf->__PVT__fetch_rdata)))))
                              : ((0x20U & vlSelf->__PVT__fetch_rdata)
                                  ? (0x844433U | ((0x700000U 
                                                   & (vlSelf->__PVT__fetch_rdata 
                                                      << 0x12U)) 
                                                  | ((0x38000U 
                                                      & (vlSelf->__PVT__fetch_rdata 
                                                         << 8U)) 
                                                     | (0x380U 
                                                        & vlSelf->__PVT__fetch_rdata))))
                                  : (0x40840433U | 
                                     ((0x700000U & 
                                       (vlSelf->__PVT__fetch_rdata 
                                        << 0x12U)) 
                                      | ((0x38000U 
                                          & (vlSelf->__PVT__fetch_rdata 
                                             << 8U)) 
                                         | (0x380U 
                                            & vlSelf->__PVT__fetch_rdata))))));
                    }
                } else {
                    __PVT__instr_decompressed = (0x47413U 
                                                 | (((- (IData)(
                                                                (1U 
                                                                 & (vlSelf->__PVT__fetch_rdata 
                                                                    >> 0xcU)))) 
                                                     << 0x1aU) 
                                                    | ((0x2000000U 
                                                        & (vlSelf->__PVT__fetch_rdata 
                                                           << 0xdU)) 
                                                       | ((0x1f00000U 
                                                           & (vlSelf->__PVT__fetch_rdata 
                                                              << 0x12U)) 
                                                          | ((0x38000U 
                                                              & (vlSelf->__PVT__fetch_rdata 
                                                                 << 8U)) 
                                                             | (0x380U 
                                                                & vlSelf->__PVT__fetch_rdata))))));
                }
            } else {
                __PVT__instr_decompressed = (0x45413U 
                                             | ((0x40000000U 
                                                 & (vlSelf->__PVT__fetch_rdata 
                                                    << 0x14U)) 
                                                | ((0x1f00000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 0x12U)) 
                                                   | ((0x38000U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 8U)) 
                                                      | (0x380U 
                                                         & vlSelf->__PVT__fetch_rdata)))));
                if ((0x1000U & vlSelf->__PVT__fetch_rdata)) {
                    vlSelf->__PVT__illegal_c_insn = 1U;
                }
            }
        } else if ((0x4000U & vlSelf->__PVT__fetch_rdata)) {
            if ((0x2000U & vlSelf->__PVT__fetch_rdata)) {
                __PVT__instr_decompressed = (0x37U 
                                             | (((- (IData)(
                                                            (1U 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                >> 0xcU)))) 
                                                 << 0x11U) 
                                                | ((0x1f000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 0xaU)) 
                                                   | (0xf80U 
                                                      & vlSelf->__PVT__fetch_rdata))));
                if ((0U == ((0x20U & (vlSelf->__PVT__fetch_rdata 
                                      >> 7U)) | (0x1fU 
                                                 & (vlSelf->__PVT__fetch_rdata 
                                                    >> 2U))))) {
                    vlSelf->__PVT__illegal_c_insn = 1U;
                }
                if ((2U == (0x1fU & (vlSelf->__PVT__fetch_rdata 
                                     >> 7U)))) {
                    __PVT__instr_decompressed = (0x10113U 
                                                 | (((- (IData)(
                                                                (1U 
                                                                 & (vlSelf->__PVT__fetch_rdata 
                                                                    >> 0xcU)))) 
                                                     << 0x1dU) 
                                                    | ((0x18000000U 
                                                        & (vlSelf->__PVT__fetch_rdata 
                                                           << 0x18U)) 
                                                       | ((0x4000000U 
                                                           & (vlSelf->__PVT__fetch_rdata 
                                                              << 0x15U)) 
                                                          | ((0x2000000U 
                                                              & (vlSelf->__PVT__fetch_rdata 
                                                                 << 0x17U)) 
                                                             | (0x1000000U 
                                                                & (vlSelf->__PVT__fetch_rdata 
                                                                   << 0x12U)))))));
                }
            } else {
                __PVT__instr_decompressed = (0x13U 
                                             | (((- (IData)(
                                                            (1U 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                >> 0xcU)))) 
                                                 << 0x1aU) 
                                                | ((0x2000000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 0xdU)) 
                                                   | ((0x1f00000U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 0x12U)) 
                                                      | (0xf80U 
                                                         & vlSelf->__PVT__fetch_rdata)))));
            }
        } else {
            __PVT__instr_decompressed = ((0x2000U & vlSelf->__PVT__fetch_rdata)
                                          ? (0x6fU 
                                             | ((0x80000000U 
                                                 & (vlSelf->__PVT__fetch_rdata 
                                                    << 0x13U)) 
                                                | ((0x40000000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 0x16U)) 
                                                   | ((0x30000000U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 0x13U)) 
                                                      | ((0x8000000U 
                                                          & (vlSelf->__PVT__fetch_rdata 
                                                             << 0x15U)) 
                                                         | ((0x4000000U 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                << 0x13U)) 
                                                            | ((0x2000000U 
                                                                & (vlSelf->__PVT__fetch_rdata 
                                                                   << 0x17U)) 
                                                               | ((0x1000000U 
                                                                   & (vlSelf->__PVT__fetch_rdata 
                                                                      << 0xdU)) 
                                                                  | ((0xe00000U 
                                                                      & (vlSelf->__PVT__fetch_rdata 
                                                                         << 0x12U)) 
                                                                     | ((0x1ff000U 
                                                                         & ((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->__PVT__fetch_rdata 
                                                                                >> 0xcU)))) 
                                                                            << 0xcU)) 
                                                                        | (0x80U 
                                                                           & ((~ 
                                                                               (vlSelf->__PVT__fetch_rdata 
                                                                                >> 0xfU)) 
                                                                              << 7U))))))))))))
                                          : (0x13U 
                                             | (((- (IData)(
                                                            (1U 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                >> 0xcU)))) 
                                                 << 0x1aU) 
                                                | ((0x2000000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 0xdU)) 
                                                   | ((0x1f00000U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 0x12U)) 
                                                      | ((0xf8000U 
                                                          & (vlSelf->__PVT__fetch_rdata 
                                                             << 8U)) 
                                                         | (0xf80U 
                                                            & vlSelf->__PVT__fetch_rdata)))))));
        }
    } else if ((0x8000U & vlSelf->__PVT__fetch_rdata)) {
        if ((0x4000U & vlSelf->__PVT__fetch_rdata)) {
            if ((0x2000U & vlSelf->__PVT__fetch_rdata)) {
                vlSelf->__PVT__illegal_c_insn = 1U;
            } else {
                __PVT__instr_decompressed = (0x842023U 
                                             | ((0x4000000U 
                                                 & (vlSelf->__PVT__fetch_rdata 
                                                    << 0x15U)) 
                                                | ((0x2000000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 0xdU)) 
                                                   | ((0x700000U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 0x12U)) 
                                                      | ((0x38000U 
                                                          & (vlSelf->__PVT__fetch_rdata 
                                                             << 8U)) 
                                                         | ((0xc00U 
                                                             & vlSelf->__PVT__fetch_rdata) 
                                                            | (0x200U 
                                                               & (vlSelf->__PVT__fetch_rdata 
                                                                  << 3U))))))));
            }
        } else if ((0x2000U & vlSelf->__PVT__fetch_rdata)) {
            vlSelf->__PVT__illegal_c_insn = 1U;
        } else if ((0x1000U & vlSelf->__PVT__fetch_rdata)) {
            vlSelf->__PVT__illegal_c_insn = 1U;
        } else if ((0x800U & vlSelf->__PVT__fetch_rdata)) {
            if ((0x400U & vlSelf->__PVT__fetch_rdata)) {
                if ((0x40U & vlSelf->__PVT__fetch_rdata)) {
                    vlSelf->__PVT__illegal_c_insn = 1U;
                } else {
                    __PVT__instr_decompressed = (0x841023U 
                                                 | ((0x700000U 
                                                     & (vlSelf->__PVT__fetch_rdata 
                                                        << 0x12U)) 
                                                    | ((0x38000U 
                                                        & (vlSelf->__PVT__fetch_rdata 
                                                           << 8U)) 
                                                       | (0x100U 
                                                          & (vlSelf->__PVT__fetch_rdata 
                                                             << 3U)))));
                }
            } else {
                __PVT__instr_decompressed = (0x840023U 
                                             | ((0x700000U 
                                                 & (vlSelf->__PVT__fetch_rdata 
                                                    << 0x12U)) 
                                                | ((0x38000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 8U)) 
                                                   | ((0x100U 
                                                       & (vlSelf->__PVT__fetch_rdata 
                                                          << 3U)) 
                                                      | (0x80U 
                                                         & (vlSelf->__PVT__fetch_rdata 
                                                            << 1U))))));
            }
        } else if ((0x400U & vlSelf->__PVT__fetch_rdata)) {
            if ((0x40U & vlSelf->__PVT__fetch_rdata)) {
                if ((0x40U & vlSelf->__PVT__fetch_rdata)) {
                    __PVT__instr_decompressed = (0x41403U 
                                                 | ((0x200000U 
                                                     & (vlSelf->__PVT__fetch_rdata 
                                                        << 0x10U)) 
                                                    | ((0x38000U 
                                                        & (vlSelf->__PVT__fetch_rdata 
                                                           << 8U)) 
                                                       | (0x380U 
                                                          & (vlSelf->__PVT__fetch_rdata 
                                                             << 5U)))));
                } else {
                    vlSelf->__PVT__illegal_c_insn = 1U;
                }
            } else {
                __PVT__instr_decompressed = (0x45403U 
                                             | ((0x200000U 
                                                 & (vlSelf->__PVT__fetch_rdata 
                                                    << 0x10U)) 
                                                | ((0x38000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 8U)) 
                                                   | (0x380U 
                                                      & (vlSelf->__PVT__fetch_rdata 
                                                         << 5U)))));
            }
        } else {
            __PVT__instr_decompressed = (0x44403U | 
                                         ((0x200000U 
                                           & (vlSelf->__PVT__fetch_rdata 
                                              << 0x10U)) 
                                          | ((0x100000U 
                                              & (vlSelf->__PVT__fetch_rdata 
                                                 << 0xeU)) 
                                             | ((0x38000U 
                                                 & (vlSelf->__PVT__fetch_rdata 
                                                    << 8U)) 
                                                | (0x380U 
                                                   & (vlSelf->__PVT__fetch_rdata 
                                                      << 5U))))));
        }
    } else if ((0x4000U & vlSelf->__PVT__fetch_rdata)) {
        if ((0x2000U & vlSelf->__PVT__fetch_rdata)) {
            vlSelf->__PVT__illegal_c_insn = 1U;
        } else {
            __PVT__instr_decompressed = (0x42403U | 
                                         ((0x4000000U 
                                           & (vlSelf->__PVT__fetch_rdata 
                                              << 0x15U)) 
                                          | ((0x3800000U 
                                              & (vlSelf->__PVT__fetch_rdata 
                                                 << 0xdU)) 
                                             | ((0x400000U 
                                                 & (vlSelf->__PVT__fetch_rdata 
                                                    << 0x10U)) 
                                                | ((0x38000U 
                                                    & (vlSelf->__PVT__fetch_rdata 
                                                       << 8U)) 
                                                   | (0x380U 
                                                      & (vlSelf->__PVT__fetch_rdata 
                                                         << 5U)))))));
        }
    } else if ((0x2000U & vlSelf->__PVT__fetch_rdata)) {
        vlSelf->__PVT__illegal_c_insn = 1U;
    } else {
        __PVT__instr_decompressed = (0x10413U | ((0x3c000000U 
                                                  & (vlSelf->__PVT__fetch_rdata 
                                                     << 0x13U)) 
                                                 | ((0x3000000U 
                                                     & (vlSelf->__PVT__fetch_rdata 
                                                        << 0xdU)) 
                                                    | ((0x800000U 
                                                        & (vlSelf->__PVT__fetch_rdata 
                                                           << 0x12U)) 
                                                       | ((0x400000U 
                                                           & (vlSelf->__PVT__fetch_rdata 
                                                              << 0x10U)) 
                                                          | (0x380U 
                                                             & (vlSelf->__PVT__fetch_rdata 
                                                                << 5U)))))));
        if ((0U == (0xffU & (vlSelf->__PVT__fetch_rdata 
                             >> 5U)))) {
            vlSelf->__PVT__illegal_c_insn = 1U;
        }
    }
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_d 
        = (0x7fffffffU & ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o)
                           ? (vlSelf->__PVT__prefetch_addr 
                              >> 1U) : (vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q 
                                        + ((2U & ((~ (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two)) 
                                                  << 1U)) 
                                           | (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two)))));
    vlSelf->__PVT__instr_valid_id_d = ((IData)(vlSelf->__PVT__instr_new_id_d) 
                                       | ((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.instr_valid_clear_o)) 
                                          & (IData)(vlSelf->__PVT__instr_valid_id_q)));
    vlSelf->__PVT__instr_out = ((IData)(vlSelf->__PVT__gen_dummy_instr__DOT__insert_dummy_instr)
                                 ? (0x33U | (((IData)(vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_set) 
                                              << 0x19U) 
                                             | ((0x1ff8000U 
                                                 & (vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__lfsr_data 
                                                    << 0xaU)) 
                                                | ((IData)(vlSelf->__PVT__gen_dummy_instr__DOT__dummy_instr_i__DOT__dummy_opcode) 
                                                   << 0xcU))))
                                 : __PVT__instr_decompressed);
    vlSelf->__PVT__instr_gets_expanded = ((IData)(vlSelf->__Vcellinp__compressed_decoder_i__valid_i)
                                           ? (IData)(__PVT__compressed_decoder_i__DOT__gets_expanded)
                                           : 0U);
    __VdfgTmp_h3d81f5b8__0 = (1U & ((~ (IData)(vlSelf->__PVT__gen_dummy_instr__DOT__insert_dummy_instr)) 
                                    & (~ ((1U == (IData)(vlSelf->__PVT__instr_gets_expanded)) 
                                          | (2U == (IData)(vlSelf->__PVT__instr_gets_expanded))))));
    vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_hd659ff45__0 
        = (((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.id_in_ready_o) 
            & (IData)(__VdfgTmp_h3d81f5b8__0)) & (IData)(vlSelf->__PVT__fetch_valid_raw));
    __PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo 
        = ((IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_hd659ff45__0) 
           & ((~ (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__aligned_is_compressed)) 
              | vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_d 
        = ((((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o)) 
             & ((~ (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo)) 
                & (IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h46facb3b__0))) 
            << 2U) | ((((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o)) 
                        & ((IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo)
                            ? (IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h46facb3b__0)
                            : (IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_haf2cbd5f__0))) 
                       << 1U) | (1U & ((~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.pc_set_o)) 
                                       & ((IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo)
                                           ? (IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_haf2cbd5f__0)
                                           : ((IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h0d767fd8__0) 
                                              | (IData)(vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q)))))));
    vlSelf->__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__entry_en 
        = (((IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h87841355__0) 
            << 2U) | (((((IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h46facb3b__0) 
                         & (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo)) 
                        | ((~ (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo)) 
                           & (IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h18c9f2e2__0))) 
                       << 1U) | (((IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_haf2cbd5f__0) 
                                  & (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo)) 
                                 | ((~ (IData)(__PVT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo)) 
                                    & (IData)(vlSelf->gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h0d767fd8__0)))));
}
