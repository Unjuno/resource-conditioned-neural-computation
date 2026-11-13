// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rtnn_c2_soc_42.h for the primary calling header

#include "Vtb_rtnn_c2_soc_42__pch.h"
#include "Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9.h"

VL_INLINE_OPT void Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___eval_initial__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i(Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rtnn_c2_soc_42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtb_rtnn_c2_soc_42_ibex_cs_registers__pi9___eval_initial__TOP__tb_rtnn_c2_soc_42__DOT__u_soc__DOT__u_ibex__DOT__u_ibex_core__DOT__cs_registers_i\n"); );
    // Body
    vlSelf->__PVT__mhpmevent[0U] = 0U;
    vlSelf->__PVT__mhpmevent[1U] = 0U;
    vlSelf->__PVT__mhpmevent[2U] = 0U;
    vlSelf->__PVT__mhpmevent[3U] = 0U;
    vlSelf->__PVT__mhpmevent[3U] = (1U | vlSelf->__PVT__mhpmevent
                                    [3U]);
    vlSelf->__PVT__mhpmevent[4U] = 0U;
    vlSelf->__PVT__mhpmevent[4U] = (2U | vlSelf->__PVT__mhpmevent
                                    [4U]);
    vlSelf->__PVT__mhpmevent[5U] = 0U;
    vlSelf->__PVT__mhpmevent[5U] = (4U | vlSelf->__PVT__mhpmevent
                                    [5U]);
    vlSelf->__PVT__mhpmevent[6U] = 0U;
    vlSelf->__PVT__mhpmevent[6U] = (8U | vlSelf->__PVT__mhpmevent
                                    [6U]);
    vlSelf->__PVT__mhpmevent[7U] = 0U;
    vlSelf->__PVT__mhpmevent[7U] = (0x10U | vlSelf->__PVT__mhpmevent
                                    [7U]);
    vlSelf->__PVT__mhpmevent[8U] = 0U;
    vlSelf->__PVT__mhpmevent[8U] = (0x20U | vlSelf->__PVT__mhpmevent
                                    [8U]);
    vlSelf->__PVT__mhpmevent[9U] = 0U;
    vlSelf->__PVT__mhpmevent[9U] = (0x40U | vlSelf->__PVT__mhpmevent
                                    [9U]);
    vlSelf->__PVT__mhpmevent[0xaU] = 0U;
    vlSelf->__PVT__mhpmevent[0xaU] = (0x80U | vlSelf->__PVT__mhpmevent
                                      [0xaU]);
    vlSelf->__PVT__mhpmevent[0xbU] = 0U;
    vlSelf->__PVT__mhpmevent[0xbU] = (0x100U | vlSelf->__PVT__mhpmevent
                                      [0xbU]);
    vlSelf->__PVT__mhpmevent[0xcU] = 0U;
    vlSelf->__PVT__mhpmevent[0xcU] = (0x200U | vlSelf->__PVT__mhpmevent
                                      [0xcU]);
    vlSelf->__PVT__mhpmevent[0xdU] = 0U;
    vlSelf->__PVT__mhpmevent[0xdU] = (0x400U | vlSelf->__PVT__mhpmevent
                                      [0xdU]);
    vlSelf->__PVT__mhpmevent[0xeU] = 0U;
    vlSelf->__PVT__mhpmevent[0xeU] = (0x800U | vlSelf->__PVT__mhpmevent
                                      [0xeU]);
    vlSelf->__PVT__mhpmevent[0xfU] = 0U;
    vlSelf->__PVT__mhpmevent[0xfU] = (0x1000U | vlSelf->__PVT__mhpmevent
                                      [0xfU]);
    vlSelf->__PVT__mhpmevent[0x10U] = 0U;
    vlSelf->__PVT__mhpmevent[0x10U] = (0x2000U | vlSelf->__PVT__mhpmevent
                                       [0x10U]);
    vlSelf->__PVT__mhpmevent[0x11U] = 0U;
    vlSelf->__PVT__mhpmevent[0x11U] = (0x4000U | vlSelf->__PVT__mhpmevent
                                       [0x11U]);
    vlSelf->__PVT__mhpmevent[0x12U] = 0U;
    vlSelf->__PVT__mhpmevent[0x12U] = (0x8000U | vlSelf->__PVT__mhpmevent
                                       [0x12U]);
    vlSelf->__PVT__mhpmevent[0x13U] = 0U;
    vlSelf->__PVT__mhpmevent[0x13U] = (0x10000U | vlSelf->__PVT__mhpmevent
                                       [0x13U]);
    vlSelf->__PVT__mhpmevent[0x14U] = 0U;
    vlSelf->__PVT__mhpmevent[0x14U] = (0x20000U | vlSelf->__PVT__mhpmevent
                                       [0x14U]);
    vlSelf->__PVT__mhpmevent[0x15U] = 0U;
    vlSelf->__PVT__mhpmevent[0x15U] = (0x40000U | vlSelf->__PVT__mhpmevent
                                       [0x15U]);
    vlSelf->__PVT__mhpmevent[0x16U] = 0U;
    vlSelf->__PVT__mhpmevent[0x16U] = (0x80000U | vlSelf->__PVT__mhpmevent
                                       [0x16U]);
    vlSelf->__PVT__mhpmevent[0x17U] = 0U;
    vlSelf->__PVT__mhpmevent[0x17U] = (0x100000U | 
                                       vlSelf->__PVT__mhpmevent
                                       [0x17U]);
    vlSelf->__PVT__mhpmevent[0x18U] = 0U;
    vlSelf->__PVT__mhpmevent[0x18U] = (0x200000U | 
                                       vlSelf->__PVT__mhpmevent
                                       [0x18U]);
    vlSelf->__PVT__mhpmevent[0x19U] = 0U;
    vlSelf->__PVT__mhpmevent[0x19U] = (0x400000U | 
                                       vlSelf->__PVT__mhpmevent
                                       [0x19U]);
    vlSelf->__PVT__mhpmevent[0x1aU] = 0U;
    vlSelf->__PVT__mhpmevent[0x1aU] = (0x800000U | 
                                       vlSelf->__PVT__mhpmevent
                                       [0x1aU]);
    vlSelf->__PVT__mhpmevent[0x1bU] = 0U;
    vlSelf->__PVT__mhpmevent[0x1bU] = (0x1000000U | 
                                       vlSelf->__PVT__mhpmevent
                                       [0x1bU]);
    vlSelf->__PVT__mhpmevent[0x1cU] = 0U;
    vlSelf->__PVT__mhpmevent[0x1cU] = (0x2000000U | 
                                       vlSelf->__PVT__mhpmevent
                                       [0x1cU]);
    vlSelf->__PVT__mhpmevent[0x1dU] = 0U;
    vlSelf->__PVT__mhpmevent[0x1dU] = (0x4000000U | 
                                       vlSelf->__PVT__mhpmevent
                                       [0x1dU]);
    vlSelf->__PVT__mhpmevent[0x1eU] = 0U;
    vlSelf->__PVT__mhpmevent[0x1eU] = (0x8000000U | 
                                       vlSelf->__PVT__mhpmevent
                                       [0x1eU]);
    vlSelf->__PVT__mhpmevent[0x1fU] = 0U;
    vlSelf->__PVT__mhpmevent[0x1fU] = (0x10000000U 
                                       | vlSelf->__PVT__mhpmevent
                                       [0x1fU]);
    vlSelf->__PVT__mhpmevent[1U] = 0U;
    vlSelf->__PVT__mhpmevent[3U] = 0U;
    vlSelf->__PVT__mhpmevent[4U] = 0U;
    vlSelf->__PVT__mhpmevent[5U] = 0U;
    vlSelf->__PVT__mhpmevent[6U] = 0U;
    vlSelf->__PVT__mhpmevent[7U] = 0U;
    vlSelf->__PVT__mhpmevent[8U] = 0U;
    vlSelf->__PVT__mhpmevent[9U] = 0U;
    vlSelf->__PVT__mhpmevent[0xaU] = 0U;
    vlSelf->__PVT__mhpmevent[0xbU] = 0U;
    vlSelf->__PVT__mhpmevent[0xcU] = 0U;
    vlSelf->__PVT__mhpmevent[0xdU] = 0U;
    vlSelf->__PVT__mhpmevent[0xeU] = 0U;
    vlSelf->__PVT__mhpmevent[0xfU] = 0U;
    vlSelf->__PVT__mhpmevent[0x10U] = 0U;
    vlSelf->__PVT__mhpmevent[0x11U] = 0U;
    vlSelf->__PVT__mhpmevent[0x12U] = 0U;
    vlSelf->__PVT__mhpmevent[0x13U] = 0U;
    vlSelf->__PVT__mhpmevent[0x14U] = 0U;
    vlSelf->__PVT__mhpmevent[0x15U] = 0U;
    vlSelf->__PVT__mhpmevent[0x16U] = 0U;
    vlSelf->__PVT__mhpmevent[0x17U] = 0U;
    vlSelf->__PVT__mhpmevent[0x18U] = 0U;
    vlSelf->__PVT__mhpmevent[0x19U] = 0U;
    vlSelf->__PVT__mhpmevent[0x1aU] = 0U;
    vlSelf->__PVT__mhpmevent[0x1bU] = 0U;
    vlSelf->__PVT__mhpmevent[0x1cU] = 0U;
    vlSelf->__PVT__mhpmevent[0x1dU] = 0U;
    vlSelf->__PVT__mhpmevent[0x1eU] = 0U;
    vlSelf->__PVT__mhpmevent[0x1fU] = 0U;
    vlSelf->__PVT__mhpmcounter[1U] = 0ULL;
    vlSelf->__PVT__mhpmcounter[3U] = 0ULL;
    vlSelf->__PVT__mhpmcounter[4U] = 0ULL;
    vlSelf->__PVT__mhpmcounter[5U] = 0ULL;
    vlSelf->__PVT__mhpmcounter[6U] = 0ULL;
    vlSelf->__PVT__mhpmcounter[7U] = 0ULL;
    vlSelf->__PVT__mhpmcounter[8U] = 0ULL;
    vlSelf->__PVT__mhpmcounter[9U] = 0ULL;
    vlSelf->__PVT__mhpmcounter[0xaU] = 0ULL;
    vlSelf->__PVT__mhpmcounter[0xbU] = 0ULL;
    vlSelf->__PVT__mhpmcounter[0xcU] = 0ULL;
    vlSelf->__PVT__mhpmcounter[0xdU] = 0ULL;
    vlSelf->__PVT__mhpmcounter[0xeU] = 0ULL;
    vlSelf->__PVT__mhpmcounter[0xfU] = 0ULL;
    vlSelf->__PVT__mhpmcounter[0x10U] = 0ULL;
    vlSelf->__PVT__mhpmcounter[0x11U] = 0ULL;
    vlSelf->__PVT__mhpmcounter[0x12U] = 0ULL;
    vlSelf->__PVT__mhpmcounter[0x13U] = 0ULL;
    vlSelf->__PVT__mhpmcounter[0x14U] = 0ULL;
    vlSelf->__PVT__mhpmcounter[0x15U] = 0ULL;
    vlSelf->__PVT__mhpmcounter[0x16U] = 0ULL;
    vlSelf->__PVT__mhpmcounter[0x17U] = 0ULL;
    vlSelf->__PVT__mhpmcounter[0x18U] = 0ULL;
    vlSelf->__PVT__mhpmcounter[0x19U] = 0ULL;
    vlSelf->__PVT__mhpmcounter[0x1aU] = 0ULL;
    vlSelf->__PVT__mhpmcounter[0x1bU] = 0ULL;
    vlSelf->__PVT__mhpmcounter[0x1cU] = 0ULL;
    vlSelf->__PVT__mhpmcounter[0x1dU] = 0ULL;
    vlSelf->__PVT__mhpmcounter[0x1eU] = 0ULL;
    vlSelf->__PVT__mhpmcounter[0x1fU] = 0ULL;
    vlSelf->__PVT__pmp_cfg_rdata[0U] = 0U;
    vlSelf->__PVT__pmp_cfg_rdata[1U] = 0U;
    vlSelf->__PVT__pmp_cfg_rdata[2U] = 0U;
    vlSelf->__PVT__pmp_cfg_rdata[3U] = 0U;
    vlSelf->__PVT__pmp_cfg_rdata[4U] = 0U;
    vlSelf->__PVT__pmp_cfg_rdata[5U] = 0U;
    vlSelf->__PVT__pmp_cfg_rdata[6U] = 0U;
    vlSelf->__PVT__pmp_cfg_rdata[7U] = 0U;
    vlSelf->__PVT__pmp_cfg_rdata[8U] = 0U;
    vlSelf->__PVT__pmp_cfg_rdata[9U] = 0U;
    vlSelf->__PVT__pmp_cfg_rdata[0xaU] = 0U;
    vlSelf->__PVT__pmp_cfg_rdata[0xbU] = 0U;
    vlSelf->__PVT__pmp_cfg_rdata[0xcU] = 0U;
    vlSelf->__PVT__pmp_cfg_rdata[0xdU] = 0U;
    vlSelf->__PVT__pmp_cfg_rdata[0xeU] = 0U;
    vlSelf->__PVT__pmp_cfg_rdata[0xfU] = 0U;
    vlSelf->__PVT__pmp_addr_rdata[0U] = 0U;
    vlSelf->__PVT__pmp_addr_rdata[1U] = 0U;
    vlSelf->__PVT__pmp_addr_rdata[2U] = 0U;
    vlSelf->__PVT__pmp_addr_rdata[3U] = 0U;
    vlSelf->__PVT__pmp_addr_rdata[4U] = 0U;
    vlSelf->__PVT__pmp_addr_rdata[5U] = 0U;
    vlSelf->__PVT__pmp_addr_rdata[6U] = 0U;
    vlSelf->__PVT__pmp_addr_rdata[7U] = 0U;
    vlSelf->__PVT__pmp_addr_rdata[8U] = 0U;
    vlSelf->__PVT__pmp_addr_rdata[9U] = 0U;
    vlSelf->__PVT__pmp_addr_rdata[0xaU] = 0U;
    vlSelf->__PVT__pmp_addr_rdata[0xbU] = 0U;
    vlSelf->__PVT__pmp_addr_rdata[0xcU] = 0U;
    vlSelf->__PVT__pmp_addr_rdata[0xdU] = 0U;
    vlSelf->__PVT__pmp_addr_rdata[0xeU] = 0U;
    vlSelf->__PVT__pmp_addr_rdata[0xfU] = 0U;
}
