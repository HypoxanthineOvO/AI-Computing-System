// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vtop::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgBit(oldp+0,(vlTOPp->pe_top__DOT__im2col_done));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgWData(oldp+1,(vlTOPp->pe_top__DOT__X),96);
            tracep->chgQData(oldp+4,(vlTOPp->pe_top__DOT__W),64);
            tracep->chgIData(oldp+6,(vlTOPp->pe_top__DOT__X_count),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgWData(oldp+7,(vlTOPp->pe_top__DOT__X_buffer[0]),96);
            tracep->chgWData(oldp+10,(vlTOPp->pe_top__DOT__X_buffer[1]),96);
            tracep->chgWData(oldp+13,(vlTOPp->pe_top__DOT__X_buffer[2]),96);
            tracep->chgWData(oldp+16,(vlTOPp->pe_top__DOT__X_buffer[3]),96);
            tracep->chgQData(oldp+19,(vlTOPp->pe_top__DOT__W_buffer[0]),64);
            tracep->chgQData(oldp+21,(vlTOPp->pe_top__DOT__W_buffer[1]),64);
            tracep->chgQData(oldp+23,(vlTOPp->pe_top__DOT__W_buffer[2]),64);
            tracep->chgQData(oldp+25,(vlTOPp->pe_top__DOT__W_buffer[3]),64);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgBit(oldp+27,(vlTOPp->pe_top__DOT__rst_im2col));
            tracep->chgBit(oldp+28,(vlTOPp->pe_top__DOT__rst_systolic));
            tracep->chgCData(oldp+29,(vlTOPp->pe_top__DOT__state),2);
            tracep->chgBit(oldp+30,(vlTOPp->pe_top__DOT__rst_n));
            tracep->chgCData(oldp+31,(vlTOPp->pe_top__DOT__rst_cnt),2);
        }
        tracep->chgBit(oldp+32,(vlTOPp->clk));
        tracep->chgIData(oldp+33,(vlTOPp->pe_top__DOT__data_rd),32);
    }
}

void Vtop::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
        vlTOPp->__Vm_traceActivity[3U] = 0U;
    }
}
