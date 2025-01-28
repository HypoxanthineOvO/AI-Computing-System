// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("vsrc/sim/top.v", 12, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("vsrc/sim/top.v", 12, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->pe_top__DOT__mem[0x3000U] = vlTOPp->pe_top__DOT__Y[0U];
    vlTOPp->pe_top__DOT__mem[0x3001U] = vlTOPp->pe_top__DOT__Y[1U];
    vlTOPp->pe_top__DOT__mem[0x3002U] = vlTOPp->pe_top__DOT__Y[2U];
    vlTOPp->pe_top__DOT__mem[0x3003U] = vlTOPp->pe_top__DOT__Y[3U];
    vlTOPp->pe_top__DOT__mem[0x3004U] = vlTOPp->pe_top__DOT__Y[4U];
    vlTOPp->pe_top__DOT__mem[0x3005U] = vlTOPp->pe_top__DOT__Y[5U];
}

VL_INLINE_OPT void Vtop::_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__2\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__pe_top__DOT__rst_cnt = vlTOPp->pe_top__DOT__rst_cnt;
    vlTOPp->__Vdlyvset__pe_top__DOT__mem__v0 = 0U;
    vlTOPp->__Vdly__pe_top__DOT__state = vlTOPp->pe_top__DOT__state;
    if (vlTOPp->pe_top__DOT__mem_wr_en) {
        vlTOPp->pe_top__DOT____Vlvbound2 = vlTOPp->pe_top__DOT__data_wr;
        if ((0x4fffU >= (0x7fffU & vlTOPp->pe_top__DOT__addr_wr))) {
            vlTOPp->__Vdlyvval__pe_top__DOT__mem__v0 
                = vlTOPp->pe_top__DOT____Vlvbound2;
            vlTOPp->__Vdlyvset__pe_top__DOT__mem__v0 = 1U;
            vlTOPp->__Vdlyvdim0__pe_top__DOT__mem__v0 
                = (0x7fffU & vlTOPp->pe_top__DOT__addr_wr);
        }
    }
    vlTOPp->pe_top__DOT__data_rd = ((0x4fffU >= (0x7fffU 
                                                 & vlTOPp->pe_top__DOT__addr_rd))
                                     ? vlTOPp->pe_top__DOT__mem
                                    [(0x7fffU & vlTOPp->pe_top__DOT__addr_rd)]
                                     : vlTOPp->pe_top__DOT____Vxrand1);
}

VL_INLINE_OPT void Vtop::_sequent__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__3\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    IData/*31:0*/ __Vdly__pe_top__DOT__X_count;
    // Body
    __Vdly__pe_top__DOT__X_count = vlTOPp->pe_top__DOT__X_count;
    if (vlTOPp->pe_top__DOT__rst_systolic) {
        __Vdly__pe_top__DOT__X_count = ((IData)(1U) 
                                        + vlTOPp->pe_top__DOT__X_count);
        if ((4U > vlTOPp->pe_top__DOT__X_count)) {
            vlTOPp->pe_top__DOT__X[0U] = vlTOPp->pe_top__DOT__X_buffer
                [(3U & vlTOPp->pe_top__DOT__X_count)][0U];
            vlTOPp->pe_top__DOT__X[1U] = vlTOPp->pe_top__DOT__X_buffer
                [(3U & vlTOPp->pe_top__DOT__X_count)][1U];
            vlTOPp->pe_top__DOT__X[2U] = vlTOPp->pe_top__DOT__X_buffer
                [(3U & vlTOPp->pe_top__DOT__X_count)][2U];
            vlTOPp->pe_top__DOT__W = vlTOPp->pe_top__DOT__W_buffer
                [(3U & vlTOPp->pe_top__DOT__X_count)];
        } else {
            vlTOPp->pe_top__DOT__X[0U] = 0U;
            vlTOPp->pe_top__DOT__X[1U] = 0U;
            vlTOPp->pe_top__DOT__X[2U] = 0U;
        }
    } else {
        vlTOPp->pe_top__DOT__X[0U] = 0U;
        vlTOPp->pe_top__DOT__X[1U] = 0U;
        vlTOPp->pe_top__DOT__X[2U] = 0U;
        vlTOPp->pe_top__DOT__W = 0ULL;
        __Vdly__pe_top__DOT__X_count = 0U;
    }
    vlTOPp->pe_top__DOT__X_count = __Vdly__pe_top__DOT__X_count;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__5\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*5:0*/ __Vdlyvlsb__pe_top__DOT__W_buffer__v0;
    CData/*5:0*/ __Vdlyvlsb__pe_top__DOT__W_buffer__v1;
    CData/*5:0*/ __Vdlyvlsb__pe_top__DOT__W_buffer__v2;
    CData/*5:0*/ __Vdlyvlsb__pe_top__DOT__W_buffer__v3;
    CData/*5:0*/ __Vdlyvlsb__pe_top__DOT__W_buffer__v4;
    CData/*5:0*/ __Vdlyvlsb__pe_top__DOT__W_buffer__v5;
    CData/*5:0*/ __Vdlyvlsb__pe_top__DOT__W_buffer__v6;
    CData/*5:0*/ __Vdlyvlsb__pe_top__DOT__W_buffer__v7;
    CData/*6:0*/ __Vdlyvlsb__pe_top__DOT__X_buffer__v0;
    CData/*6:0*/ __Vdlyvlsb__pe_top__DOT__X_buffer__v1;
    CData/*6:0*/ __Vdlyvlsb__pe_top__DOT__X_buffer__v2;
    CData/*6:0*/ __Vdlyvlsb__pe_top__DOT__X_buffer__v3;
    CData/*6:0*/ __Vdlyvlsb__pe_top__DOT__X_buffer__v4;
    CData/*6:0*/ __Vdlyvlsb__pe_top__DOT__X_buffer__v5;
    CData/*6:0*/ __Vdlyvlsb__pe_top__DOT__X_buffer__v6;
    CData/*6:0*/ __Vdlyvlsb__pe_top__DOT__X_buffer__v7;
    CData/*6:0*/ __Vdlyvlsb__pe_top__DOT__X_buffer__v8;
    CData/*6:0*/ __Vdlyvlsb__pe_top__DOT__X_buffer__v9;
    CData/*6:0*/ __Vdlyvlsb__pe_top__DOT__X_buffer__v10;
    CData/*6:0*/ __Vdlyvlsb__pe_top__DOT__X_buffer__v11;
    IData/*31:0*/ __Vdlyvval__pe_top__DOT__W_buffer__v0;
    IData/*31:0*/ __Vdlyvval__pe_top__DOT__W_buffer__v1;
    IData/*31:0*/ __Vdlyvval__pe_top__DOT__W_buffer__v2;
    IData/*31:0*/ __Vdlyvval__pe_top__DOT__W_buffer__v3;
    IData/*31:0*/ __Vdlyvval__pe_top__DOT__W_buffer__v4;
    IData/*31:0*/ __Vdlyvval__pe_top__DOT__W_buffer__v5;
    IData/*31:0*/ __Vdlyvval__pe_top__DOT__W_buffer__v6;
    IData/*31:0*/ __Vdlyvval__pe_top__DOT__W_buffer__v7;
    IData/*31:0*/ __Vdlyvval__pe_top__DOT__X_buffer__v0;
    IData/*31:0*/ __Vdlyvval__pe_top__DOT__X_buffer__v1;
    IData/*31:0*/ __Vdlyvval__pe_top__DOT__X_buffer__v2;
    IData/*31:0*/ __Vdlyvval__pe_top__DOT__X_buffer__v3;
    IData/*31:0*/ __Vdlyvval__pe_top__DOT__X_buffer__v4;
    IData/*31:0*/ __Vdlyvval__pe_top__DOT__X_buffer__v5;
    IData/*31:0*/ __Vdlyvval__pe_top__DOT__X_buffer__v6;
    IData/*31:0*/ __Vdlyvval__pe_top__DOT__X_buffer__v7;
    IData/*31:0*/ __Vdlyvval__pe_top__DOT__X_buffer__v8;
    IData/*31:0*/ __Vdlyvval__pe_top__DOT__X_buffer__v9;
    IData/*31:0*/ __Vdlyvval__pe_top__DOT__X_buffer__v10;
    IData/*31:0*/ __Vdlyvval__pe_top__DOT__X_buffer__v11;
    // Body
    __Vdlyvval__pe_top__DOT__W_buffer__v0 = vlTOPp->pe_top__DOT__mem
        [0x1000U];
    __Vdlyvlsb__pe_top__DOT__W_buffer__v0 = 0U;
    __Vdlyvval__pe_top__DOT__W_buffer__v1 = vlTOPp->pe_top__DOT__mem
        [0x1001U];
    __Vdlyvlsb__pe_top__DOT__W_buffer__v1 = 0x20U;
    __Vdlyvval__pe_top__DOT__W_buffer__v2 = vlTOPp->pe_top__DOT__mem
        [0x1002U];
    __Vdlyvlsb__pe_top__DOT__W_buffer__v2 = 0U;
    __Vdlyvval__pe_top__DOT__W_buffer__v3 = vlTOPp->pe_top__DOT__mem
        [0x1003U];
    __Vdlyvlsb__pe_top__DOT__W_buffer__v3 = 0x20U;
    __Vdlyvval__pe_top__DOT__W_buffer__v4 = vlTOPp->pe_top__DOT__mem
        [0x1004U];
    __Vdlyvlsb__pe_top__DOT__W_buffer__v4 = 0U;
    __Vdlyvval__pe_top__DOT__W_buffer__v5 = vlTOPp->pe_top__DOT__mem
        [0x1005U];
    __Vdlyvlsb__pe_top__DOT__W_buffer__v5 = 0x20U;
    __Vdlyvval__pe_top__DOT__W_buffer__v6 = vlTOPp->pe_top__DOT__mem
        [0x1006U];
    __Vdlyvlsb__pe_top__DOT__W_buffer__v6 = 0U;
    __Vdlyvval__pe_top__DOT__W_buffer__v7 = vlTOPp->pe_top__DOT__mem
        [0x1007U];
    __Vdlyvlsb__pe_top__DOT__W_buffer__v7 = 0x20U;
    __Vdlyvval__pe_top__DOT__X_buffer__v0 = vlTOPp->pe_top__DOT__mem
        [0x2000U];
    __Vdlyvlsb__pe_top__DOT__X_buffer__v0 = 0U;
    __Vdlyvval__pe_top__DOT__X_buffer__v1 = vlTOPp->pe_top__DOT__mem
        [0x2001U];
    __Vdlyvlsb__pe_top__DOT__X_buffer__v1 = 0x20U;
    __Vdlyvval__pe_top__DOT__X_buffer__v2 = vlTOPp->pe_top__DOT__mem
        [0x2002U];
    __Vdlyvlsb__pe_top__DOT__X_buffer__v2 = 0x40U;
    __Vdlyvval__pe_top__DOT__X_buffer__v3 = vlTOPp->pe_top__DOT__mem
        [0x2003U];
    __Vdlyvlsb__pe_top__DOT__X_buffer__v3 = 0U;
    __Vdlyvval__pe_top__DOT__X_buffer__v4 = vlTOPp->pe_top__DOT__mem
        [0x2004U];
    __Vdlyvlsb__pe_top__DOT__X_buffer__v4 = 0x20U;
    __Vdlyvval__pe_top__DOT__X_buffer__v5 = vlTOPp->pe_top__DOT__mem
        [0x2005U];
    __Vdlyvlsb__pe_top__DOT__X_buffer__v5 = 0x40U;
    __Vdlyvval__pe_top__DOT__X_buffer__v6 = vlTOPp->pe_top__DOT__mem
        [0x2006U];
    __Vdlyvlsb__pe_top__DOT__X_buffer__v6 = 0U;
    __Vdlyvval__pe_top__DOT__X_buffer__v7 = vlTOPp->pe_top__DOT__mem
        [0x2007U];
    __Vdlyvlsb__pe_top__DOT__X_buffer__v7 = 0x20U;
    __Vdlyvval__pe_top__DOT__X_buffer__v8 = vlTOPp->pe_top__DOT__mem
        [0x2008U];
    __Vdlyvlsb__pe_top__DOT__X_buffer__v8 = 0x40U;
    __Vdlyvval__pe_top__DOT__X_buffer__v9 = vlTOPp->pe_top__DOT__mem
        [0x2009U];
    __Vdlyvlsb__pe_top__DOT__X_buffer__v9 = 0U;
    __Vdlyvval__pe_top__DOT__X_buffer__v10 = vlTOPp->pe_top__DOT__mem
        [0x200aU];
    __Vdlyvlsb__pe_top__DOT__X_buffer__v10 = 0x20U;
    __Vdlyvval__pe_top__DOT__X_buffer__v11 = vlTOPp->pe_top__DOT__mem
        [0x200bU];
    __Vdlyvlsb__pe_top__DOT__X_buffer__v11 = 0x40U;
    vlTOPp->pe_top__DOT__W_buffer[0U] = (((~ (0xffffffffULL 
                                              << (IData)(__Vdlyvlsb__pe_top__DOT__W_buffer__v0))) 
                                          & vlTOPp->pe_top__DOT__W_buffer
                                          [0U]) | ((QData)((IData)(__Vdlyvval__pe_top__DOT__W_buffer__v0)) 
                                                   << (IData)(__Vdlyvlsb__pe_top__DOT__W_buffer__v0)));
    vlTOPp->pe_top__DOT__W_buffer[0U] = (((~ (0xffffffffULL 
                                              << (IData)(__Vdlyvlsb__pe_top__DOT__W_buffer__v1))) 
                                          & vlTOPp->pe_top__DOT__W_buffer
                                          [0U]) | ((QData)((IData)(__Vdlyvval__pe_top__DOT__W_buffer__v1)) 
                                                   << (IData)(__Vdlyvlsb__pe_top__DOT__W_buffer__v1)));
    vlTOPp->pe_top__DOT__W_buffer[1U] = (((~ (0xffffffffULL 
                                              << (IData)(__Vdlyvlsb__pe_top__DOT__W_buffer__v2))) 
                                          & vlTOPp->pe_top__DOT__W_buffer
                                          [1U]) | ((QData)((IData)(__Vdlyvval__pe_top__DOT__W_buffer__v2)) 
                                                   << (IData)(__Vdlyvlsb__pe_top__DOT__W_buffer__v2)));
    vlTOPp->pe_top__DOT__W_buffer[1U] = (((~ (0xffffffffULL 
                                              << (IData)(__Vdlyvlsb__pe_top__DOT__W_buffer__v3))) 
                                          & vlTOPp->pe_top__DOT__W_buffer
                                          [1U]) | ((QData)((IData)(__Vdlyvval__pe_top__DOT__W_buffer__v3)) 
                                                   << (IData)(__Vdlyvlsb__pe_top__DOT__W_buffer__v3)));
    vlTOPp->pe_top__DOT__W_buffer[2U] = (((~ (0xffffffffULL 
                                              << (IData)(__Vdlyvlsb__pe_top__DOT__W_buffer__v4))) 
                                          & vlTOPp->pe_top__DOT__W_buffer
                                          [2U]) | ((QData)((IData)(__Vdlyvval__pe_top__DOT__W_buffer__v4)) 
                                                   << (IData)(__Vdlyvlsb__pe_top__DOT__W_buffer__v4)));
    vlTOPp->pe_top__DOT__W_buffer[2U] = (((~ (0xffffffffULL 
                                              << (IData)(__Vdlyvlsb__pe_top__DOT__W_buffer__v5))) 
                                          & vlTOPp->pe_top__DOT__W_buffer
                                          [2U]) | ((QData)((IData)(__Vdlyvval__pe_top__DOT__W_buffer__v5)) 
                                                   << (IData)(__Vdlyvlsb__pe_top__DOT__W_buffer__v5)));
    vlTOPp->pe_top__DOT__W_buffer[3U] = (((~ (0xffffffffULL 
                                              << (IData)(__Vdlyvlsb__pe_top__DOT__W_buffer__v6))) 
                                          & vlTOPp->pe_top__DOT__W_buffer
                                          [3U]) | ((QData)((IData)(__Vdlyvval__pe_top__DOT__W_buffer__v6)) 
                                                   << (IData)(__Vdlyvlsb__pe_top__DOT__W_buffer__v6)));
    vlTOPp->pe_top__DOT__W_buffer[3U] = (((~ (0xffffffffULL 
                                              << (IData)(__Vdlyvlsb__pe_top__DOT__W_buffer__v7))) 
                                          & vlTOPp->pe_top__DOT__W_buffer
                                          [3U]) | ((QData)((IData)(__Vdlyvval__pe_top__DOT__W_buffer__v7)) 
                                                   << (IData)(__Vdlyvlsb__pe_top__DOT__W_buffer__v7)));
    VL_ASSIGNSEL_WIII(32,(IData)(__Vdlyvlsb__pe_top__DOT__X_buffer__v0), 
                      vlTOPp->pe_top__DOT__X_buffer
                      [0U], __Vdlyvval__pe_top__DOT__X_buffer__v0);
    VL_ASSIGNSEL_WIII(32,(IData)(__Vdlyvlsb__pe_top__DOT__X_buffer__v1), 
                      vlTOPp->pe_top__DOT__X_buffer
                      [0U], __Vdlyvval__pe_top__DOT__X_buffer__v1);
    VL_ASSIGNSEL_WIII(32,(IData)(__Vdlyvlsb__pe_top__DOT__X_buffer__v2), 
                      vlTOPp->pe_top__DOT__X_buffer
                      [0U], __Vdlyvval__pe_top__DOT__X_buffer__v2);
    VL_ASSIGNSEL_WIII(32,(IData)(__Vdlyvlsb__pe_top__DOT__X_buffer__v3), 
                      vlTOPp->pe_top__DOT__X_buffer
                      [1U], __Vdlyvval__pe_top__DOT__X_buffer__v3);
    VL_ASSIGNSEL_WIII(32,(IData)(__Vdlyvlsb__pe_top__DOT__X_buffer__v4), 
                      vlTOPp->pe_top__DOT__X_buffer
                      [1U], __Vdlyvval__pe_top__DOT__X_buffer__v4);
    VL_ASSIGNSEL_WIII(32,(IData)(__Vdlyvlsb__pe_top__DOT__X_buffer__v5), 
                      vlTOPp->pe_top__DOT__X_buffer
                      [1U], __Vdlyvval__pe_top__DOT__X_buffer__v5);
    VL_ASSIGNSEL_WIII(32,(IData)(__Vdlyvlsb__pe_top__DOT__X_buffer__v6), 
                      vlTOPp->pe_top__DOT__X_buffer
                      [2U], __Vdlyvval__pe_top__DOT__X_buffer__v6);
    VL_ASSIGNSEL_WIII(32,(IData)(__Vdlyvlsb__pe_top__DOT__X_buffer__v7), 
                      vlTOPp->pe_top__DOT__X_buffer
                      [2U], __Vdlyvval__pe_top__DOT__X_buffer__v7);
    VL_ASSIGNSEL_WIII(32,(IData)(__Vdlyvlsb__pe_top__DOT__X_buffer__v8), 
                      vlTOPp->pe_top__DOT__X_buffer
                      [2U], __Vdlyvval__pe_top__DOT__X_buffer__v8);
    VL_ASSIGNSEL_WIII(32,(IData)(__Vdlyvlsb__pe_top__DOT__X_buffer__v9), 
                      vlTOPp->pe_top__DOT__X_buffer
                      [3U], __Vdlyvval__pe_top__DOT__X_buffer__v9);
    VL_ASSIGNSEL_WIII(32,(IData)(__Vdlyvlsb__pe_top__DOT__X_buffer__v10), 
                      vlTOPp->pe_top__DOT__X_buffer
                      [3U], __Vdlyvval__pe_top__DOT__X_buffer__v10);
    VL_ASSIGNSEL_WIII(32,(IData)(__Vdlyvlsb__pe_top__DOT__X_buffer__v11), 
                      vlTOPp->pe_top__DOT__X_buffer
                      [3U], __Vdlyvval__pe_top__DOT__X_buffer__v11);
}

VL_INLINE_OPT void Vtop::_sequent__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__6\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*159:0*/ __Vtemp3[5];
    // Body
    if (VL_UNLIKELY((0U == (IData)(vlTOPp->pe_top__DOT__state)))) {
        __Vtemp3[0U] = 0x2e747874U;
        __Vtemp3[1U] = 0x5f6f7574U;
        __Vtemp3[2U] = 0x2f6d656dU;
        __Vtemp3[3U] = 0x2f6d656dU;
        __Vtemp3[4U] = 0x2e2eU;
        VL_WRITEMEM_N(true, 32, 20480, 0, VL_CVT_PACK_STR_NW(5, __Vtemp3)
                      , vlTOPp->pe_top__DOT__mem, 0
                      , ~0ULL);
        vlTOPp->pe_top__DOT__rst_im2col = 0U;
        vlTOPp->pe_top__DOT__rst_systolic = 0U;
        vlTOPp->__Vdly__pe_top__DOT__state = ((IData)(vlTOPp->pe_top__DOT__rst_n)
                                               ? 1U
                                               : 0U);
    } else {
        if ((1U == (IData)(vlTOPp->pe_top__DOT__state))) {
            vlTOPp->pe_top__DOT__rst_im2col = 1U;
            vlTOPp->pe_top__DOT__rst_systolic = 0U;
            vlTOPp->__Vdly__pe_top__DOT__state = ((IData)(vlTOPp->pe_top__DOT__im2col_done)
                                                   ? 2U
                                                   : 1U);
        } else {
            if ((2U == (IData)(vlTOPp->pe_top__DOT__state))) {
                vlTOPp->pe_top__DOT__rst_im2col = 0U;
                vlTOPp->pe_top__DOT__rst_systolic = 1U;
                vlTOPp->__Vdly__pe_top__DOT__state 
                    = ((IData)(vlTOPp->pe_top__DOT__systolic_done)
                        ? 0U : 2U);
            }
        }
    }
    vlTOPp->pe_top__DOT__state = vlTOPp->__Vdly__pe_top__DOT__state;
    if (vlTOPp->__Vdlyvset__pe_top__DOT__mem__v0) {
        vlTOPp->pe_top__DOT__mem[vlTOPp->__Vdlyvdim0__pe_top__DOT__mem__v0] 
            = vlTOPp->__Vdlyvval__pe_top__DOT__mem__v0;
    }
    if ((0U == (IData)(vlTOPp->pe_top__DOT__rst_cnt))) {
        vlTOPp->pe_top__DOT__rst_n = 0U;
        vlTOPp->__Vdly__pe_top__DOT__rst_cnt = 0U;
    } else {
        if ((1U == (IData)(vlTOPp->pe_top__DOT__rst_cnt))) {
            vlTOPp->pe_top__DOT__rst_n = 1U;
        }
        if ((2U == (IData)(vlTOPp->pe_top__DOT__rst_cnt))) {
            vlTOPp->pe_top__DOT__rst_n = 0U;
        }
        vlTOPp->__Vdly__pe_top__DOT__rst_cnt = (3U 
                                                & ((IData)(vlTOPp->pe_top__DOT__rst_cnt) 
                                                   - (IData)(1U)));
    }
    vlTOPp->pe_top__DOT__rst_cnt = vlTOPp->__Vdly__pe_top__DOT__rst_cnt;
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->pe_top__DOT__systolic_done) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__pe_top__DOT__systolic_done)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->__VinpClk__TOP__pe_top__DOT__rst_systolic)) 
            & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__pe_top__DOT__rst_systolic)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((IData)(vlTOPp->pe_top__DOT__im2col_done) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__pe_top__DOT__im2col_done)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
        vlTOPp->__Vm_traceActivity[3U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__pe_top__DOT__systolic_done 
        = vlTOPp->pe_top__DOT__systolic_done;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__pe_top__DOT__rst_systolic 
        = vlTOPp->__VinpClk__TOP__pe_top__DOT__rst_systolic;
    vlTOPp->__Vclklast__TOP__pe_top__DOT__im2col_done 
        = vlTOPp->pe_top__DOT__im2col_done;
    vlTOPp->__VinpClk__TOP__pe_top__DOT__rst_systolic 
        = vlTOPp->pe_top__DOT__rst_systolic;
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop::_change_request_1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request_1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->pe_top__DOT__rst_systolic ^ vlTOPp->__Vchglast__TOP__pe_top__DOT__rst_systolic));
    VL_DEBUG_IF( if(__req && ((vlTOPp->pe_top__DOT__rst_systolic ^ vlTOPp->__Vchglast__TOP__pe_top__DOT__rst_systolic))) VL_DBG_MSGF("        CHANGE: vsrc/sim/top.v:48: pe_top.rst_systolic\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__pe_top__DOT__rst_systolic 
        = vlTOPp->pe_top__DOT__rst_systolic;
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
