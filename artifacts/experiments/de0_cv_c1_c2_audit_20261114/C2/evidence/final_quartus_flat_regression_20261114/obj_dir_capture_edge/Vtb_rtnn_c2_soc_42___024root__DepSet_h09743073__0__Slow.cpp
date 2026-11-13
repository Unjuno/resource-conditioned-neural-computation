// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rtnn_c2_soc_42.h for the primary calling header

#include "Vtb_rtnn_c2_soc_42__pch.h"
#include "Vtb_rtnn_c2_soc_42__Syms.h"
#include "Vtb_rtnn_c2_soc_42___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rtnn_c2_soc_42___024root___dump_triggers__stl(Vtb_rtnn_c2_soc_42___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_rtnn_c2_soc_42___024root___eval_triggers__stl(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
    vlSelf->__VstlTriggered.set(1U, (((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.en_wb_o) 
                                      != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__en_wb_o__0)) 
                                     | ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__instr_executing_spec) 
                                        != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i____PVT__instr_executing_spec__0))));
    vlSelf->__VstlTriggered.set(2U, ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__instr_executing_spec) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i____PVT__instr_executing_spec__0)));
    vlSelf->__VstlTriggered.set(3U, ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.id_in_ready_o) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__id_in_ready_o__0)));
    vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__en_wb_o__0 
        = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.en_wb_o;
    vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i____PVT__instr_executing_spec__0 
        = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__instr_executing_spec;
    vlSelf->__Vtrigprevexpr___TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__id_in_ready_o__0 
        = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.id_in_ready_o;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VstlDidInit))))) {
        vlSelf->__VstlDidInit = 1U;
        vlSelf->__VstlTriggered.set(1U, 1U);
        vlSelf->__VstlTriggered.set(2U, 1U);
        vlSelf->__VstlTriggered.set(3U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_rtnn_c2_soc_42___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void Vtb_rtnn_c2_soc_42___024root___stl_sequent__TOP__0(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___stl_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__instr_rdata;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__instr_rdata = 0;
    IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_rdata;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_rdata = 0;
    QData/*38:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o = 0;
    QData/*38:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o = 0;
    QData/*33:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand1;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand1 = 0;
    IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o = 0;
    QData/*38:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_data_secded__DOT__sv2v_cast_39__179__Vfuncout;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_data_secded__DOT__sv2v_cast_39__179__Vfuncout = 0;
    QData/*38:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_data_secded__DOT__sv2v_cast_39__179__inp;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_data_secded__DOT__sv2v_cast_39__179__inp = 0;
    QData/*38:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_instr_secded__DOT__sv2v_cast_39__180__Vfuncout;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_instr_secded__DOT__sv2v_cast_39__180__Vfuncout = 0;
    QData/*38:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_instr_secded__DOT__sv2v_cast_39__180__inp;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_instr_secded__DOT__sv2v_cast_39__180__inp = 0;
    // Body
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
        [0U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[1U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
        [1U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[2U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
        [2U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[3U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
        [3U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[4U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
        [4U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[5U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
        [5U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[6U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
        [6U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[7U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
        [7U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[8U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
        [8U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[9U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
        [9U];
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0xaU] 
        = (IData)((((QData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
                                    [0xbU])) << 0x20U) 
                   | (QData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
                                     [0xaU]))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__response_data[0xbU] 
        = (IData)(((((QData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
                                     [0xbU])) << 0x20U) 
                    | (QData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
                                      [0xaU]))) >> 0x20U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_released 
        = (1U & ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__tck_reset_release_q) 
                 >> 1U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_update = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__tdo = (1U & ((4U 
                                                  & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir))
                                                  ? 
                                                 ((1U 
                                                   & (~ 
                                                      ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir) 
                                                       >> 1U))) 
                                                  && ((1U 
                                                       & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir))) 
                                                      && (1U 
                                                          & vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__build_shift_tck_q)))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir))
                                                    ? (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__status_shift_tck_q)
                                                    : 
                                                   vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__rsp_shift_tck_q[0U])
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__ir)) 
                                                   && (1U 
                                                       & vlSelf->tb_rtnn_c2_soc_42__DOT__u_mailbox__DOT__req_shift_tck_q[0U])))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_hold = 0U;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_rdata 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_ram_q)
            ? ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__data_hit_q)
                ? vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__data_ram_q
                : 0U) : vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__mmio_read_data_q);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a = 1ULL;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__instr_rdata 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__instr_hit_q)
            ? vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__instr_ram_q
            : 0U);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_or_pmp_err 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_q) 
           | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_err_q) 
              | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_valid = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_resp_valid 
        = (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_valid_q) 
            | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q)) 
           & (0U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_addr_incr_req = 0U;
    if ((4U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
        if ((1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)))) {
                if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_valid_q) {
                    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_update 
                        = (1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q)));
                }
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_addr_incr_req = 1U;
            }
        }
    } else if ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
        if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)))) {
            if (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_valid_q) 
                 | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q))) {
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_update 
                    = (1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q)));
            }
        }
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_addr_incr_req 
            = ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) 
               || (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_q));
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[1U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__1__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[2U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__2__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[3U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__3__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[4U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__4__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[5U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__5__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[6U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__6__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[7U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__7__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[8U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__8__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[9U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__9__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0xaU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__10__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0xbU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__11__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0xcU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__12__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0xdU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__13__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0xeU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__14__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0xfU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__15__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x10U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__16__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x11U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__17__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x12U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__18__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x13U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__19__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x14U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__20__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x15U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__21__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x16U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__22__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x17U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__23__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x18U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__24__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x19U] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__25__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x1aU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__26__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x1bU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__27__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x1cU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__28__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x1dU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__29__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x1eU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__30__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x1fU] 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__31__KET____DOT__rf_reg_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0U] 
        = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.dummy_instr_id_o)
            ? vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_dummy_r0__DOT__rf_r0_q
            : 0U);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_data_secded__DOT__sv2v_cast_39__179__inp 
        = (QData)((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_rdata));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_data_secded__DOT__sv2v_cast_39__179__Vfuncout 
        = __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_data_secded__DOT__sv2v_cast_39__179__inp;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o 
        = __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_data_secded__DOT__sv2v_cast_39__179__Vfuncout;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o 
        = ((0x7effffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x2606bd25ULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o))))) 
              << 0x20U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o 
        = ((0x7dffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0xdeba8050ULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o))))) 
              << 0x21U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o 
        = ((0x7bffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x413d89aaULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o))))) 
              << 0x22U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o 
        = ((0x77ffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x31234ed1ULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o))))) 
              << 0x23U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o 
        = ((0x6fffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0xc2c1323bULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o))))) 
              << 0x24U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o 
        = ((0x5fffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x2dcc624cULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o))))) 
              << 0x25U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o 
        = ((0x3fffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x98505586ULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o))))) 
              << 0x26U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o 
        = (0x2a00000000ULL ^ tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o);
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_instr_secded__DOT__sv2v_cast_39__180__inp 
        = (QData)((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__instr_rdata));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_instr_secded__DOT__sv2v_cast_39__180__Vfuncout 
        = __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_instr_secded__DOT__sv2v_cast_39__180__inp;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o 
        = __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_instr_secded__DOT__sv2v_cast_39__180__Vfuncout;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o 
        = ((0x7effffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x2606bd25ULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o))))) 
              << 0x20U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o 
        = ((0x7dffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0xdeba8050ULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o))))) 
              << 0x21U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o 
        = ((0x7bffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x413d89aaULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o))))) 
              << 0x22U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o 
        = ((0x77ffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x31234ed1ULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o))))) 
              << 0x23U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o 
        = ((0x6fffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0xc2c1323bULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o))))) 
              << 0x24U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o 
        = ((0x5fffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x2dcc624cULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o))))) 
              << 0x25U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o 
        = ((0x3fffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x98505586ULL 
                                                  & tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o))))) 
              << 0x26U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o 
        = (0x2a00000000ULL ^ tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg
        [(0x1fU & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                   >> 0x14U))];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_a 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg
        [(0x1fU & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i.instr_rdata_id_o 
                   >> 0xfU))];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
        = (((QData)((IData)((0x7fU & (IData)((tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_data_secded__data_o 
                                              >> 0x20U))))) 
            << 0x20U) | (QData)((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_rdata)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__instr_rdata_core 
        = (((QData)((IData)((0x7fU & (IData)((tb_rtnn_c2_soc_42__DOT__u_soc__DOT____Vcellout__u_instr_secded__data_o 
                                              >> 0x20U))))) 
            << 0x20U) | (QData)((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__instr_rdata)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_op_b 
        = (0xffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_op_a 
        = (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_a 
           >> 0x10U);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult1_res_uns 
        = (0x3ffffffffULL & VL_MULS_QQQ(34, (0x3ffffffffULL 
                                             & VL_EXTENDS_QI(34,17, 
                                                             (0xffffU 
                                                              & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_a))), 
                                        (0x3ffffffffULL 
                                         & VL_EXTENDS_QI(34,17, 
                                                         (0xffffU 
                                                          & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b 
        = (1ULL | ((QData)((IData)((~ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b))) 
                   << 1U));
    if ((4U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
        if ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
            if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q)))) {
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_hold = 0U;
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_valid = 1U;
            }
        }
        if ((1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a = 1ULL;
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b 
                    = (1ULL | ((QData)((IData)((~ (
                                                   (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U] 
                                                    << 0x1eU) 
                                                   | (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[1U] 
                                                      >> 2U))))) 
                               << 1U));
            } else {
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a 
                    = (1ULL | ((QData)((IData)(((vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U] 
                                                 << 0x1eU) 
                                                | (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[1U] 
                                                   >> 2U)))) 
                               << 1U));
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b 
                    = (1ULL | ((QData)((IData)((~ vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[0U]))) 
                               << 1U));
            }
        }
    } else if ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
        if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a 
                = (1ULL | ((QData)((IData)(((vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U] 
                                             << 0x1eU) 
                                            | (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[1U] 
                                               >> 2U)))) 
                           << 1U));
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b 
                = (1ULL | ((QData)((IData)((~ vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[0U]))) 
                           << 1U));
        } else {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a = 1ULL;
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b 
                = (1ULL | ((QData)((IData)((~ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b))) 
                           << 1U));
        }
    } else {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a = 1ULL;
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b 
            = ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))
                ? (1ULL | ((QData)((IData)((~ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_a))) 
                           << 1U)) : (1ULL | ((QData)((IData)(
                                                              (~ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b))) 
                                              << 1U)));
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_rdata_ext 
        = ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_type_q))
            ? ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                ? ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                    ? ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                        ? (((- (IData)((1U & (IData)(
                                                     (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                      >> 0x1fU))))) 
                            << 8U) | (0xffU & (IData)(
                                                      (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                       >> 0x18U))))
                        : (0xffU & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                            >> 0x18U))))
                    : ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                        ? (((- (IData)((1U & (IData)(
                                                     (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                      >> 0x17U))))) 
                            << 8U) | (0xffU & (IData)(
                                                      (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                       >> 0x10U))))
                        : (0xffU & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                            >> 0x10U)))))
                : ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                    ? ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                        ? (((- (IData)((1U & (IData)(
                                                     (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                      >> 0xfU))))) 
                            << 8U) | (0xffU & (IData)(
                                                      (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                       >> 8U))))
                        : (0xffU & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                            >> 8U))))
                    : ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                        ? (((- (IData)((1U & (IData)(
                                                     (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                      >> 7U))))) 
                            << 8U) | (0xffU & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf)))
                        : (0xffU & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf)))))
            : ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_type_q))
                ? ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                    ? ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                        ? ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                            ? (((- (IData)((1U & (IData)(
                                                         (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                          >> 7U))))) 
                                << 0x10U) | ((0xff00U 
                                              & ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf) 
                                                 << 8U)) 
                                             | (0xffU 
                                                & (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q 
                                                   >> 0x10U))))
                            : ((0xff00U & ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf) 
                                           << 8U)) 
                               | (0xffU & (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q 
                                           >> 0x10U))))
                        : ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                            ? (((- (IData)((1U & (IData)(
                                                         (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                          >> 0x1fU))))) 
                                << 0x10U) | (0xffffU 
                                             & (IData)(
                                                       (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                        >> 0x10U))))
                            : (0xffffU & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                  >> 0x10U)))))
                    : ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                        ? ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                            ? (((- (IData)((1U & (IData)(
                                                         (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                          >> 0x17U))))) 
                                << 0x10U) | (0xffffU 
                                             & (IData)(
                                                       (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                        >> 8U))))
                            : (0xffffU & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                  >> 8U))))
                        : ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                            ? (((- (IData)((1U & (IData)(
                                                         (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                          >> 0xfU))))) 
                                << 0x10U) | (0xffffU 
                                             & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf)))
                            : (0xffffU & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf)))))
                : ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                    ? ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                        ? (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf) 
                            << 8U) | (0xffU & (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q 
                                               >> 0x10U)))
                        : (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf) 
                            << 0x10U) | (0xffffU & 
                                         (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q 
                                          >> 8U))))
                    : ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                        ? (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf) 
                            << 0x18U) | vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q)
                        : (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o 
        = ((0x7eU & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
           | (1U & VL_REDXOR_64((0x12606bd25ULL & (0x2a00000000ULL 
                                                   ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o 
        = ((0x7dU & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
           | (2U & (VL_REDXOR_64((0x2deba8050ULL & 
                                  (0x2a00000000ULL 
                                   ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf))) 
                    << 1U)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o 
        = ((0x7bU & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
           | (4U & (VL_REDXOR_64((0x4413d89aaULL & 
                                  (0x2a00000000ULL 
                                   ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf))) 
                    << 2U)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o 
        = ((0x77U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
           | (8U & (VL_REDXOR_64((0x831234ed1ULL & 
                                  (0x2a00000000ULL 
                                   ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf))) 
                    << 3U)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o 
        = ((0x6fU & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
           | (0x10U & (VL_REDXOR_64((0x10c2c1323bULL 
                                     & (0x2a00000000ULL 
                                        ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf))) 
                       << 4U)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o 
        = ((0x5fU & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
           | (0x20U & (VL_REDXOR_64((0x202dcc624cULL 
                                     & (0x2a00000000ULL 
                                        ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf))) 
                       << 5U)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o 
        = ((0x3fU & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
           | (0x40U & (VL_REDXOR_64((0x4098505586ULL 
                                     & (0x2a00000000ULL 
                                        ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf))) 
                       << 6U)));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xfffffffcU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((2U & (((0x54U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                      ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                 >> 1U))) << 1U)) | 
              (1U & ((0x19U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                     ^ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf)))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xfffffff3U & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((8U & (((0x34U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                      ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                 >> 3U))) << 3U)) | 
              (4U & (((0x61U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                      ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                 >> 2U))) << 2U))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xffffffcfU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x20U & (((0x15U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                         ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                    >> 5U))) << 5U)) 
              | (0x10U & (((0x1aU == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                           ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                      >> 4U))) << 4U))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xffffff3fU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x80U & (((0x4cU == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                         ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                    >> 7U))) << 7U)) 
              | (0x40U & (((0x2aU == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                           ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                      >> 6U))) << 6U))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xfffffcffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x200U & (((0x38U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                          ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                     >> 9U))) << 9U)) 
              | (0x100U & (((0x45U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                            ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                       >> 8U))) << 8U))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xfffff3ffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x800U & (((0xdU == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                          ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                     >> 0xbU))) << 0xbU)) 
              | (0x400U & (((0x49U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                            ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                       >> 0xaU))) << 0xaU))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xffffcfffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x2000U & (((0x31U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                           ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                      >> 0xdU))) << 0xdU)) 
              | (0x1000U & (((0x51U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                             ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                        >> 0xcU))) 
                            << 0xcU))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xffff3fffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x8000U & (((7U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                           ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                      >> 0xfU))) << 0xfU)) 
              | (0x4000U & (((0x68U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                             ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                        >> 0xeU))) 
                            << 0xeU))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xfffcffffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x20000U & (((0xbU == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                            ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                       >> 0x11U))) 
                           << 0x11U)) | (0x10000U & 
                                         (((0x1cU == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                                           ^ (IData)(
                                                     (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                      >> 0x10U))) 
                                          << 0x10U))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xfff3ffffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x80000U & (((0x26U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                            ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                       >> 0x13U))) 
                           << 0x13U)) | (0x40000U & 
                                         (((0x25U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                                           ^ (IData)(
                                                     (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                      >> 0x12U))) 
                                          << 0x12U))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xffcfffffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x200000U & (((0xeU == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                             ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                        >> 0x15U))) 
                            << 0x15U)) | (0x100000U 
                                          & (((0x46U 
                                               == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                                              ^ (IData)(
                                                        (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                         >> 0x14U))) 
                                             << 0x14U))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xff3fffffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x800000U & (((0x32U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                             ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                        >> 0x17U))) 
                            << 0x17U)) | (0x400000U 
                                          & (((0x70U 
                                               == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                                              ^ (IData)(
                                                        (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                         >> 0x16U))) 
                                             << 0x16U))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xfcffffffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x2000000U & (((0x13U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                              ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                         >> 0x19U))) 
                             << 0x19U)) | (0x1000000U 
                                           & (((0x2cU 
                                                == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                                               ^ (IData)(
                                                         (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                          >> 0x18U))) 
                                              << 0x18U))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xf3ffffffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x8000000U & (((0x62U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                              ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                         >> 0x1bU))) 
                             << 0x1bU)) | (0x4000000U 
                                           & (((0x23U 
                                                == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                                               ^ (IData)(
                                                         (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                          >> 0x1aU))) 
                                              << 0x1aU))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0xcfffffffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((0x20000000U & (((0x29U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                               ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                          >> 0x1dU))) 
                              << 0x1dU)) | (0x10000000U 
                                            & (((0x4aU 
                                                 == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                                                ^ (IData)(
                                                          (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                                           >> 0x1cU))) 
                                               << 0x1cU))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o 
        = ((0x3fffffffU & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__data_o) 
           | ((((0x52U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                           >> 0x1fU))) << 0x1fU) | 
              (0x40000000U & (((0x16U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)) 
                               ^ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__data_rdata_buf 
                                          >> 0x1eU))) 
                              << 0x1eU))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__ecc_err 
        = ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__ecc_err)) 
           | (1U & VL_REDXOR_8(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__ecc_err 
        = ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__ecc_err)) 
           | (((~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__ecc_err)) 
               & (0U != (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__u_data_intg_dec__DOT__syndrome_o))) 
              << 1U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand1 
        = (QData)((IData)((0xffffU & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult1_res_uns 
                                              >> 0x10U)))));
    if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q) {
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_op_b 
                = (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b 
                   >> 0x10U);
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_op_a 
                = (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_a 
                   >> 0x10U);
            tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand1 = 0ULL;
        }
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT____VdfgTmp_h3fd48639__0 
        = ((0U != (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__ecc_err)) 
           & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_valid_q));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand1_ext 
        = (((QData)((IData)((1U & (IData)((tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand1 
                                           >> 0x21U))))) 
            << 0x22U) | tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand1);
}

extern const VlUnpacked<CData/*0:0*/, 128> Vtb_rtnn_c2_soc_42__ConstPool__TABLE_hd5b48b0a_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_rtnn_c2_soc_42__ConstPool__TABLE_hb804351c_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_rtnn_c2_soc_42__ConstPool__TABLE_h2fe71d6b_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtb_rtnn_c2_soc_42__ConstPool__TABLE_ha686e182_0;
extern const VlUnpacked<CData/*3:0*/, 32> Vtb_rtnn_c2_soc_42__ConstPool__TABLE_hee875898_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vtb_rtnn_c2_soc_42__ConstPool__TABLE_h9d63e220_0;

VL_ATTR_COLD void Vtb_rtnn_c2_soc_42___024root___stl_sequent__TOP__1(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___stl_sequent__TOP__1\n"); );
    // Init
    IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__operand_a_rev;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__operand_a_rev = 0;
    IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_operand;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_operand = 0;
    QData/*32:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext_signed;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext_signed = 0;
    QData/*32:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext = 0;
    IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result = 0;
    IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__bwlogic_result;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__bwlogic_result = 0;
    QData/*34:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_ext;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_ext = 0;
    CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_a;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_a = 0;
    CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_b;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_b = 0;
    QData/*33:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d = 0;
    CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_a;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_a = 0;
    CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_b;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_b = 0;
    CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__is_greater_equal;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__is_greater_equal = 0;
    IData/*31:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_denominator_d;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_denominator_d = 0;
    QData/*33:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_res;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_res = 0;
    CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_sign_a;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_sign_a = 0;
    CData/*0:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_sign_b;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_sign_b = 0;
    QData/*33:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2 = 0;
    QData/*33:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3 = 0;
    QData/*34:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2_ext;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2_ext = 0;
    QData/*34:0*/ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3_ext;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3_ext = 0;
    SData/*15:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__175__Vfuncout;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__175__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__175__a;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__175__a = 0;
    QData/*38:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_wdata_ecc__DOT__u_data_gen__DOT__sv2v_cast_39__185__Vfuncout;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_wdata_ecc__DOT__u_data_gen__DOT__sv2v_cast_39__185__Vfuncout = 0;
    QData/*38:0*/ __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_wdata_ecc__DOT__u_data_gen__DOT__sv2v_cast_39__185__inp;
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_wdata_ecc__DOT__u_data_gen__DOT__sv2v_cast_39__185__inp = 0;
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*6:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    SData/*9:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*6:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    CData/*4:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    // Body
    __Vtableidx4 = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_left 
        = Vtb_rtnn_c2_soc_42__ConstPool__TABLE_hd5b48b0a_0
        [__Vtableidx4];
    __Vtableidx2 = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_signed 
        = Vtb_rtnn_c2_soc_42__ConstPool__TABLE_hb804351c_0
        [__Vtableidx2];
    __Vtableidx1 = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift1 
        = Vtb_rtnn_c2_soc_42__ConstPool__TABLE_h2fe71d6b_0
        [__Vtableidx1];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift2 
        = Vtb_rtnn_c2_soc_42__ConstPool__TABLE_h2fe71d6b_0
        [__Vtableidx1];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift3 
        = Vtb_rtnn_c2_soc_42__ConstPool__TABLE_h2fe71d6b_0
        [__Vtableidx1];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_b_negate 
        = Vtb_rtnn_c2_soc_42__ConstPool__TABLE_ha686e182_0
        [__Vtableidx1];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel 
        = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.div_sel_ex_o) 
           | (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.mult_sel_ex_o));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_a 
        = ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_a 
            >> 0x1fU) & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_signed_mode));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_b 
        = ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b 
            >> 0x1fU) & ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_signed_mode) 
                         >> 1U));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_a 
        = ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_signed_mode) 
           & (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_a 
              >> 0x1fU));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_b 
        = (IData)((((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_signed_mode) 
                    >> 1U) & (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b 
                              >> 0x1fU)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_d = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_hold = 0U;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_store_err 
        = (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_or_pmp_err) 
            & ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q) 
               & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_resp_valid))) 
           & ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__VdfgTmp_h50e2f79d__0) 
              & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__lsu_we)));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__operand_a_rev 
        = ((vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
            << 0x1fU) | ((0x40000000U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                         << 0x1dU)) 
                         | ((0x20000000U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                            << 0x1bU)) 
                            | ((0x10000000U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                               << 0x19U)) 
                               | ((0x8000000U & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                 << 0x17U)) 
                                  | ((0x4000000U & 
                                      (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                       << 0x15U)) | 
                                     ((0x2000000U & 
                                       (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                        << 0x13U)) 
                                      | ((0x1000000U 
                                          & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                             << 0x11U)) 
                                         | ((0x800000U 
                                             & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                << 0xfU)) 
                                            | ((0x400000U 
                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                   << 0xdU)) 
                                               | ((0x200000U 
                                                   & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                      << 0xbU)) 
                                                  | ((0x100000U 
                                                      & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                         << 9U)) 
                                                     | ((0x80000U 
                                                         & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                            << 7U)) 
                                                        | ((0x40000U 
                                                            & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                               << 5U)) 
                                                           | ((0x20000U 
                                                               & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                  << 3U)) 
                                                              | ((0x10000U 
                                                                  & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                     << 1U)) 
                                                                 | ((0x8000U 
                                                                     & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                        >> 1U)) 
                                                                    | ((0x4000U 
                                                                        & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                           >> 3U)) 
                                                                       | ((0x2000U 
                                                                           & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                              >> 5U)) 
                                                                          | ((0x1000U 
                                                                              & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 7U)) 
                                                                             | ((0x800U 
                                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 9U)) 
                                                                                | ((0x400U 
                                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 0xbU)) 
                                                                                | ((0x200U 
                                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 0xdU)) 
                                                                                | ((0x100U 
                                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 0xfU)) 
                                                                                | ((0x80U 
                                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 0x11U)) 
                                                                                | ((0x40U 
                                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 0x13U)) 
                                                                                | ((0x20U 
                                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 0x15U)) 
                                                                                | ((0x10U 
                                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 0x17U)) 
                                                                                | ((8U 
                                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 0x1bU)) 
                                                                                | ((2U 
                                                                                & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 0x1dU)) 
                                                                                | (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                                                >> 0x1fU))))))))))))))))))))))))))))))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_we_lsu 
        = (((0U == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)) 
            & ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_valid_q) 
               & ((~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_or_pmp_err)) 
                  & ((~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q)) 
                     & (~ (IData)((0U != (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_rdata_ecc__DOT__ecc_err)))))))) 
           & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.expecting_load_resp_o));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_load_err 
        = (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_or_pmp_err) 
            & ((~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q)) 
               & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__lsu_resp_valid))) 
           & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.expecting_load_resp_o));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__bwlogic_result 
        = (((3U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator)) 
            | (6U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator)))
            ? (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
               | vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.alu_operand_b_ex_o)
            : (((4U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator)) 
                | (7U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator)))
                ? (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                   & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.alu_operand_b_ex_o)
                : (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                   ^ vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.alu_operand_b_ex_o)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
        = (0x3ffffffffULL & (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
                               ? vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a
                               : ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift1)
                                   ? (1ULL | ((QData)((IData)(
                                                              (0x7fffffffU 
                                                               & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a))) 
                                              << 2U))
                                   : ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift2)
                                       ? (1ULL | ((QData)((IData)(
                                                                  (0x3fffffffU 
                                                                   & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a))) 
                                                  << 3U))
                                       : ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift3)
                                           ? (1ULL 
                                              | ((QData)((IData)(
                                                                 (0x1fffffffU 
                                                                  & vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a))) 
                                                 << 4U))
                                           : (1ULL 
                                              | ((QData)((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a)) 
                                                 << 1U)))))) 
                             + (0x1ffffffffULL & ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
                                                   ? vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b
                                                   : 
                                                  ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_b_negate)
                                                    ? 
                                                   (~ 
                                                    ((QData)((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.alu_operand_b_ex_o)) 
                                                     << 1U))
                                                    : 
                                                   ((QData)((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.alu_operand_b_ex_o)) 
                                                    << 1U))))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_sign_a 
        = tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_a;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2 
        = (0x3ffffffffULL & VL_MULS_QQQ(34, (0x3ffffffffULL 
                                             & VL_EXTENDS_QI(34,17, 
                                                             (0xffffU 
                                                              & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_a))), 
                                        (0x3ffffffffULL 
                                         & VL_EXTENDS_QI(34,17, 
                                                         (((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_b) 
                                                           << 0x10U) 
                                                          | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b 
                                                             >> 0x10U))))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_sign_b = 0U;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_operand 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_left)
            ? tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__operand_a_rev
            : vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a);
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext_signed 
        = (0x1ffffffffULL & VL_SHIFTRS_QQI(33,33,5, 
                                           (((QData)((IData)(
                                                             ((8U 
                                                               == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator)) 
                                                              & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_operand 
                                                                 >> 0x1fU)))) 
                                             << 0x20U) 
                                            | (QData)((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_operand))), 
                                           (0x1fU & 
                                            ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.instr_first_cycle_id_o)
                                              ? vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.alu_operand_b_ex_o
                                              : (- vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.alu_operand_b_ex_o)))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext 
        = tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext_signed;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
        = (IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xfffffff8U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((4U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                     >> 0x1bU)) | ((2U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                          >> 0x1dU)) 
                                   | (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                      >> 0x1fU))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xffffffc7U & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x20U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                        >> 0x15U)) | ((0x10U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                >> 0x17U)) 
                                      | (8U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                               >> 0x19U)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xfffffe3fU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x100U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                         >> 0xfU)) | ((0x80U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                >> 0x11U)) 
                                      | (0x40U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                  >> 0x13U)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xfffff1ffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x800U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                         >> 9U)) | ((0x400U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                               >> 0xbU)) 
                                    | (0x200U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                 >> 0xdU)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xffff8fffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x4000U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                          >> 3U)) | ((0x2000U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                 >> 5U)) 
                                     | (0x1000U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                   >> 7U)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xfffc7fffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x20000U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                           << 3U)) | ((0x10000U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                   << 1U)) 
                                      | (0x8000U & 
                                         (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                          >> 1U)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xffe3ffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x100000U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                            << 9U)) | ((0x80000U & 
                                        (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                         << 7U)) | 
                                       (0x40000U & 
                                        (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                         << 5U)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xff1fffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x800000U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                            << 0xfU)) | ((0x400000U 
                                          & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                             << 0xdU)) 
                                         | (0x200000U 
                                            & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                               << 0xbU)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xf8ffffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x4000000U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                             << 0x15U)) | ((0x2000000U 
                                            & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                               << 0x13U)) 
                                           | (0x1000000U 
                                              & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                 << 0x11U)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xc7ffffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x20000000U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                              << 0x1bU)) | ((0x10000000U 
                                             & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                << 0x19U)) 
                                            | (0x8000000U 
                                               & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                  << 0x17U)))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0x3fffffffU & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
               << 0x1fU) | (0x40000000U & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                           << 0x1dU))));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
        = ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_left)
            ? vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev
            : tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_d 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_q;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_d 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_q;
    __Vtableidx5 = (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_q) 
                     << 4U) | ((0xcU & ((IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                 >> 1U)) 
                                        << 2U)) | (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__lsu_type)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_be 
        = Vtb_rtnn_c2_soc_42__ConstPool__TABLE_hee875898_0
        [__Vtableidx5];
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__mmio_read_valid 
        = ((0x20000U == (0xfffffc00U & ((IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                 >> 3U)) 
                                        << 2U))) & 
           ((8U == (0xffU & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                     >> 3U)))) | ((0x24U 
                                                   <= 
                                                   (0x3fcU 
                                                    & ((IData)(
                                                               (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                >> 3U)) 
                                                       << 2U))) 
                                                  & (0x84U 
                                                     >= 
                                                     (0x3fcU 
                                                      & ((IData)(
                                                                 (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                  >> 3U)) 
                                                         << 2U))))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__mmio_write_valid 
        = ((0x20000U == (0xfffffc00U & ((IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                 >> 3U)) 
                                        << 2U))) & 
           ((0x22U == (0xffU & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                        >> 3U)))) | 
            (((0x8cU <= (0x3fcU & ((IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                            >> 3U)) 
                                   << 2U))) & (0xb8U 
                                               >= (0x3fcU 
                                                   & ((IData)(
                                                              (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                               >> 3U)) 
                                                      << 2U)))) 
             | (0x2fU == (0xffU & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                           >> 3U)))))));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__175__a 
        = ((IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                    >> 3U)) << 2U);
    if ((1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q)))) {
                if ((2U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_operator))) {
                    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_d 
                        = (0U == (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                          >> 1U)));
                }
            }
            if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_d 
                    = ((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_a)
                        ? (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                   >> 1U)) : vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_a);
            }
        }
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_d 
        = ((4U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))
            ? ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))
                ? 0U : ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))
                         ? 6U : 5U)) : ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))
                                         ? ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))
                                             ? ((1U 
                                                 == (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_q))
                                                 ? 4U
                                                 : 3U)
                                             : 3U) : 
                                        ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))
                                          ? 2U : ((2U 
                                                   == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_operator))
                                                   ? 
                                                  (((~ 
                                                     ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
                                                      >> 1U)) 
                                                    & (0U 
                                                       == (IData)(
                                                                  (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                   >> 1U))))
                                                    ? 6U
                                                    : 1U)
                                                   : 
                                                  (((~ 
                                                     ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i.__PVT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
                                                      >> 1U)) 
                                                    & (0U 
                                                       == (IData)(
                                                                  (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                   >> 1U))))
                                                    ? 6U
                                                    : 1U)))));
    if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_d = 0U;
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_hold = 0U;
            tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_sign_a 
                = tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_a;
            tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2 
                = (((QData)((IData)((0xffffU & (- (IData)(
                                                          ((0U 
                                                            != (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_signed_mode)) 
                                                           & (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U] 
                                                              >> 3U))))))) 
                    << 0x12U) | (QData)((IData)((0x3ffffU 
                                                 & ((vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U] 
                                                     << 0xeU) 
                                                    | (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[1U] 
                                                       >> 0x12U))))));
            tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_sign_b 
                = tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_b;
        }
    } else {
        if ((0U != (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_operator))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_d = 1U;
        }
        if ((0U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_operator))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_hold = 0U;
        }
    }
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__175__Vfuncout 
        = (0xffffU & (([&]() {
                    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__176__a 
                        = __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__175__a;
                    vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__176__Vfuncout 
                        = (0x1f8000U == (0xffff8000U 
                                         & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__176__a));
                }(), (IData)(vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__176__Vfuncout))
                       ? (0xe000U | (0x1fffU & (__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__175__a 
                                                >> 2U)))
                       : (__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__175__a 
                          >> 2U)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__data_idx 
        = __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__word_index__175__Vfuncout;
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_denominator_d 
        = vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[0U];
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_wdata_ecc__DOT__u_data_gen__DOT__sv2v_cast_39__185__inp 
        = (QData)((IData)(((1U & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                          >> 2U))) ? 
                           ((1U & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                           >> 1U)))
                             ? ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b 
                                 << 0x18U) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b 
                                              >> 8U))
                             : ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b 
                                 << 0x10U) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b 
                                              >> 0x10U)))
                            : ((1U & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                              >> 1U)))
                                ? ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b 
                                    << 8U) | (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b 
                                              >> 0x18U))
                                : vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b))));
    __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_wdata_ecc__DOT__u_data_gen__DOT__sv2v_cast_39__185__Vfuncout 
        = __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_wdata_ecc__DOT__u_data_gen__DOT__sv2v_cast_39__185__inp;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
        = __Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__g_mem_wdata_ecc__DOT__u_data_gen__DOT__sv2v_cast_39__185__Vfuncout;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
        = ((0x7effffffffULL & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x2606bd25ULL 
                                                  & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core))))) 
              << 0x20U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
        = ((0x7dffffffffULL & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0xdeba8050ULL 
                                                  & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core))))) 
              << 0x21U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
        = ((0x7bffffffffULL & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x413d89aaULL 
                                                  & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core))))) 
              << 0x22U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
        = ((0x77ffffffffULL & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x31234ed1ULL 
                                                  & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core))))) 
              << 0x23U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
        = ((0x6fffffffffULL & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0xc2c1323bULL 
                                                  & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core))))) 
              << 0x24U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
        = ((0x5fffffffffULL & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x2dcc624cULL 
                                                  & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core))))) 
              << 0x25U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
        = ((0x3fffffffffULL & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x98505586ULL 
                                                  & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core))))) 
              << 0x26U));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core 
        = (0x2a00000000ULL ^ vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core);
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__split_misaligned_access 
        = (((0U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__lsu_type)) 
            & (0U != (3U & (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                    >> 1U))))) | (IData)(
                                                         ((1U 
                                                           == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__lsu_type)) 
                                                          & (6ULL 
                                                             == 
                                                             (6ULL 
                                                              & vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext)))));
    if ((1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q) 
                  >> 2U)))) {
        if ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
            if ((1U & (~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q)))) {
                tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_denominator_d 
                    = ((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_b)
                        ? (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                   >> 1U)) : vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_b);
            }
        }
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__ram_data_hit 
        = (([&]() {
                vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__172__a 
                    = ((IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                >> 3U)) << 2U);
                vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__172__Vfuncout 
                    = (0x100000U == (0xfffc0000U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__172__a));
            }(), (IData)(vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_direct__172__Vfuncout)) 
           | ([&]() {
                vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__173__a 
                    = ((IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                >> 3U)) << 2U);
                vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__173__Vfuncout 
                    = (0x1f8000U == (0xffff8000U & vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__173__a));
            }(), (IData)(vlSelf->__Vfunc_tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ram__DOT__is_stack_alias__173__Vfuncout)));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__is_greater_equal 
        = (1U & ((1U & ((vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U] 
                         >> 1U) ^ (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[0U] 
                                   >> 0x1fU))) ? (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U] 
                                                  >> 1U)
                  : (~ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                >> 0x20U)))));
    __Vtableidx3 = (((0U != (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                     >> 1U))) << 9U) 
                    | ((0x100U & ((((vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                     ^ vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.alu_operand_b_ex_o) 
                                    >> 0x1fU) ? ((vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operand_a 
                                                  >> 0x1fU) 
                                                 ^ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_signed))
                                    : (~ (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                  >> 0x20U)))) 
                                  << 8U)) | (((0U == (IData)(
                                                             (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                              >> 1U))) 
                                              << 7U) 
                                             | (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result 
        = Vtb_rtnn_c2_soc_42__ConstPool__TABLE_h9d63e220_0
        [__Vtableidx3];
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2_ext 
        = (((QData)((IData)((1U & (IData)((tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2 
                                           >> 0x21U))))) 
            << 0x22U) | tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2);
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_res 
        = (0x3ffffffffULL & VL_MULS_QQQ(34, (0x3ffffffffULL 
                                             & VL_EXTENDS_QI(34,17, 
                                                             (((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_sign_a) 
                                                               << 0x10U) 
                                                              | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_op_a)))), 
                                        (0x3ffffffffULL 
                                         & VL_EXTENDS_QI(34,17, 
                                                         (((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_sign_b) 
                                                           << 0x10U) 
                                                          | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_op_b))))));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_commit_match 
        = ((0xffffffffffffULL == vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_byte_written_q) 
           & (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__data_wdata_core) 
               == vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[2U]) 
              & (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__response_words_q
                 [2U] == vlSelf->tb_rtnn_c2_soc_42__DOT__request_data[2U])));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__data_access_err 
        = (1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__ram_data_hit) 
                    | ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__mmio_read_valid) 
                       | (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__mmio_write_valid)))));
    if (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__is_greater_equal) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_remainder 
            = (IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                       >> 1U));
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_quotient 
            = ((QData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_q)) 
               | (QData)((IData)(((IData)(1U) << (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_q)))));
    } else {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_remainder 
            = ((vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U] 
                << 0x1eU) | (vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[1U] 
                             >> 2U));
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_quotient 
            = (QData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_q));
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_result = 0U;
    if ((0x40U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))) {
        if ((1U & (~ ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator) 
                      >> 5U)))) {
            if ((1U & (~ ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator)))) {
                                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_result = 0U;
                            }
                        }
                    }
                }
            }
        }
    } else {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_result 
            = ((0x20U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                ? ((0x10U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                    ? 0U : ((8U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                             ? ((4U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                 ? ((2U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                     ? 0U : ((1U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                              ? 0U : (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result)))
                                 : ((2U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                     ? ((1U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                         ? (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result)
                                         : 0U) : 0U))
                             : 0U)) : ((0x10U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                        ? ((8U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                            ? ((4U 
                                                & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                ? (
                                                   (2U 
                                                    & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                     ? 0U
                                                     : (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result))
                                                    : (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result))
                                                : (
                                                   (2U 
                                                    & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                    ? (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                     ? (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result)
                                                     : (IData)(
                                                               (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                >> 1U)))))
                                            : ((4U 
                                                & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                ? (
                                                   (2U 
                                                    & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                    ? (IData)(
                                                              (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                               >> 1U))
                                                    : 0U)
                                                : 0U))
                                        : ((8U & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                            ? ((4U 
                                                & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                ? (
                                                   (2U 
                                                    & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                     ? 0U
                                                     : tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result))
                                                : tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result)
                                            : ((4U 
                                                & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                ? tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__bwlogic_result
                                                : (
                                                   (2U 
                                                    & (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__alu_operator))
                                                    ? tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__bwlogic_result
                                                    : (IData)(
                                                              (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                               >> 1U)))))));
    }
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3 
        = tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_res;
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_d 
        = vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_q;
    if ((1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q) 
                  >> 2U)))) {
        if ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
            if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
                vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_d 
                    = (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_quotient);
            }
        } else if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_d = 0U;
        }
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_d 
        = (0x1fU & ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_q) 
                    - (IData)(1U)));
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d 
        = (0x3ffffffffULL & (((QData)((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U])) 
                              << 0x1eU) | ((QData)((IData)(
                                                           vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[1U])) 
                                           >> 2U)));
    if ((4U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
        if ((1U & (~ ((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q) 
                      >> 1U)))) {
            tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d 
                = (0x3ffffffffULL & ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))
                                      ? ((2U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_operator))
                                          ? (((~ (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_q)) 
                                              & ((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_a) 
                                                 ^ (IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_b)))
                                              ? (QData)((IData)(
                                                                (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                 >> 1U)))
                                              : (((QData)((IData)(
                                                                  vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U])) 
                                                  << 0x3eU) 
                                                 | (((QData)((IData)(
                                                                     vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U])) 
                                                     << 0x1eU) 
                                                    | ((QData)((IData)(
                                                                       vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[1U])) 
                                                       >> 2U))))
                                          : ((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_a)
                                              ? (QData)((IData)(
                                                                (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                 >> 1U)))
                                              : (((QData)((IData)(
                                                                  vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U])) 
                                                  << 0x3eU) 
                                                 | (((QData)((IData)(
                                                                     vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[2U])) 
                                                     << 0x1eU) 
                                                    | ((QData)((IData)(
                                                                       vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__imd_val_q[1U])) 
                                                       >> 2U)))))
                                      : ((2U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_operator))
                                          ? vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_quotient
                                          : (QData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_remainder)))));
        }
    } else if ((2U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
        if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
            tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d 
                = (((QData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_remainder)) 
                    << 1U) | (QData)((IData)((1U & 
                                              (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_q 
                                               >> (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_d))))));
        } else {
            tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d 
                = (QData)((IData)((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_q 
                                   >> 0x1fU)));
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_d = 0x1fU;
        }
    } else if ((1U & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_d = 0x1fU;
    } else {
        tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d 
            = ((2U == (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_operator))
                ? 0x3ffffffffULL : (QData)((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__rf_rdata_a)));
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_d = 0x1fU;
    }
    if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q) {
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q) {
            tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3 
                = tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult3_res;
        }
    }
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3_ext 
        = (((QData)((IData)((1U & (IData)((tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3 
                                           >> 0x21U))))) 
            << 0x22U) | tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3);
    tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_ext 
        = (0x7ffffffffULL & ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand1_ext 
                              ^ (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2_ext 
                                 ^ tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3_ext)) 
                             + VL_SHIFTL_QQI(35,35,32, 
                                             ((vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand1_ext 
                                               & (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2_ext 
                                                  | tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3_ext)) 
                                              | (tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand2_ext 
                                                 & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__summand3_ext)), 1U)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d 
        = (QData)((IData)((((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_ext) 
                            << 0x10U) | (0xffffU & (IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult1_res_uns)))));
    if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q) {
        if (vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_single_cycle__DOT__mult_state_q) {
            vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d 
                = (0x3ffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_ext);
        }
    } else if ((0U != (IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.__PVT__multdiv_operator))) {
        vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d 
            = (0x3ffffffffULL & tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_ext);
    }
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_d_ex[0U] 
        = (IData)(((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
                    ? (QData)((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_denominator_d))
                    : 0ULL));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_d_ex[1U] 
        = (((IData)(((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
                      ? ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.div_sel_ex_o)
                          ? tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d
                          : vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d)
                      : 0ULL)) << 2U) | (IData)((((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
                                                   ? (QData)((IData)(tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_denominator_d))
                                                   : 0ULL) 
                                                 >> 0x20U)));
    vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__imd_val_d_ex[2U] 
        = (((IData)(((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
                      ? ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.div_sel_ex_o)
                          ? tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d
                          : vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d)
                      : 0ULL)) >> 0x1eU) | ((IData)(
                                                    (((IData)(vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
                                                       ? 
                                                      ((IData)(vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i.div_sel_ex_o)
                                                        ? tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d
                                                        : vlSelf->tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d)
                                                       : 0ULL) 
                                                     >> 0x20U)) 
                                            << 2U));
}

VL_ATTR_COLD void Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___stl_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__0(Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* vlSelf);
VL_ATTR_COLD void Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___stl_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__0(Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9* vlSelf);
VL_ATTR_COLD void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___stl_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__0(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf);
VL_ATTR_COLD void Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___stl_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__1(Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__3(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__3(Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__0(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__0(Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__1(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf);
void Vtb_rtnn_c2_soc_42___024root___act_sequent__TOP__0(Vtb_rtnn_c2_soc_42___024root* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__2(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__0(Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__0(Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__0(Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7* vlSelf);
void Vtb_rtnn_c2_soc_42___024root___act_comb__TOP__1(Vtb_rtnn_c2_soc_42___024root* vlSelf);
void Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__1(Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9* vlSelf);

VL_ATTR_COLD void Vtb_rtnn_c2_soc_42___024root___eval_stl(Vtb_rtnn_c2_soc_42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rtnn_c2_soc_42___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_rtnn_c2_soc_42___024root___stl_sequent__TOP__0(vlSelf);
        Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___stl_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__0((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i));
        Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___stl_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__0((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i));
        Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___stl_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__0((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i));
        Vtb_rtnn_c2_soc_42___024root___stl_sequent__TOP__1(vlSelf);
        Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___stl_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__1((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i));
        Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__3((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i));
        Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___nba_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__3((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i));
    }
    if ((3ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__0((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i));
        Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__0((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i));
    }
    if ((5ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__1((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i));
        Vtb_rtnn_c2_soc_42___024root___act_sequent__TOP__0(vlSelf);
        Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_sequent__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__2((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i));
    }
    if ((0xfULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_rtnn_c2_soc_42_ibex_id_stage__pi8___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i__0((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__id_stage_i));
        Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__0((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i));
        Vtb_rtnn_c2_soc_42_ibex_if_stage__pi7___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i__0((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__if_stage_i));
        Vtb_rtnn_c2_soc_42___024root___act_comb__TOP__1(vlSelf);
        Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___act_comb__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i__1((&vlSymsp->TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i));
    }
}
