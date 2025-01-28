// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-12);
}

Vtop::~Vtop() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vtop::_initial__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*159:0*/ __Vtemp2[5];
    // Body
    vlTOPp->pe_top__DOT____Vxrand1 = VL_RAND_RESET_I(32);
    vlTOPp->pe_top__DOT__im2col_done = 1U;
    __Vtemp2[0U] = 0x2e747874U;
    __Vtemp2[1U] = 0x696e6974U;
    __Vtemp2[2U] = 0x6d656d5fU;
    __Vtemp2[3U] = 0x6d656d2fU;
    __Vtemp2[4U] = 0x2e2e2fU;
    VL_READMEM_N(true, 32, 20480, 0, VL_CVT_PACK_STR_NW(5, __Vtemp2)
                 , vlTOPp->pe_top__DOT__mem, 0, ~0ULL);
    vlTOPp->pe_top__DOT__state = 0U;
    vlTOPp->pe_top__DOT__rst_cnt = 3U;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__pe_top__DOT__systolic_done 
        = vlTOPp->pe_top__DOT__systolic_done;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__pe_top__DOT__rst_systolic 
        = vlTOPp->__VinpClk__TOP__pe_top__DOT__rst_systolic;
    vlTOPp->_initial__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity[3U] = 1U;
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlTOPp->__Vclklast__TOP__pe_top__DOT__im2col_done = 1U;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    pe_top__DOT____Vxrand1 = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(96, pe_top__DOT__X);
    pe_top__DOT__W = VL_RAND_RESET_Q(64);
    VL_RAND_RESET_W(192, pe_top__DOT__Y);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            VL_RAND_RESET_W(96, pe_top__DOT__X_buffer[__Vi0]);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            pe_top__DOT__W_buffer[__Vi0] = VL_RAND_RESET_Q(64);
    }}
    pe_top__DOT__addr_rd = VL_RAND_RESET_I(32);
    pe_top__DOT__addr_wr = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<20480; ++__Vi0) {
            pe_top__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    pe_top__DOT__data_rd = VL_RAND_RESET_I(32);
    pe_top__DOT__data_wr = VL_RAND_RESET_I(32);
    pe_top__DOT__mem_wr_en = VL_RAND_RESET_I(1);
    pe_top__DOT__rst_im2col = VL_RAND_RESET_I(1);
    pe_top__DOT__rst_systolic = VL_RAND_RESET_I(1);
    pe_top__DOT__im2col_done = VL_RAND_RESET_I(1);
    pe_top__DOT__systolic_done = VL_RAND_RESET_I(1);
    pe_top__DOT__state = VL_RAND_RESET_I(2);
    pe_top__DOT__rst_n = VL_RAND_RESET_I(1);
    pe_top__DOT__rst_cnt = VL_RAND_RESET_I(2);
    pe_top__DOT__X_count = VL_RAND_RESET_I(32);
    pe_top__DOT____Vlvbound2 = VL_RAND_RESET_I(32);
    __Vdlyvdim0__pe_top__DOT__mem__v0 = 0;
    __Vdlyvval__pe_top__DOT__mem__v0 = VL_RAND_RESET_I(32);
    __Vdlyvset__pe_top__DOT__mem__v0 = 0;
    __Vdly__pe_top__DOT__state = VL_RAND_RESET_I(2);
    __Vdly__pe_top__DOT__rst_cnt = VL_RAND_RESET_I(2);
    __VinpClk__TOP__pe_top__DOT__rst_systolic = VL_RAND_RESET_I(1);
    __Vchglast__TOP__pe_top__DOT__rst_systolic = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
