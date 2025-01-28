// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vtop::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vtop::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vtop::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vtop::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+33,"clk", false,-1);
        tracep->declBit(c+33,"pe_top clk", false,-1);
        tracep->declBus(c+35,"pe_top IMG_C", false,-1, 31,0);
        tracep->declBus(c+36,"pe_top IMG_H", false,-1, 31,0);
        tracep->declBus(c+37,"pe_top IMG_W", false,-1, 31,0);
        tracep->declBus(c+38,"pe_top FILTER_NUM", false,-1, 31,0);
        tracep->declBus(c+37,"pe_top FILTER_SIZE", false,-1, 31,0);
        tracep->declBus(c+36,"pe_top M", false,-1, 31,0);
        tracep->declBus(c+35,"pe_top N", false,-1, 31,0);
        tracep->declBus(c+38,"pe_top K", false,-1, 31,0);
        tracep->declBus(c+39,"pe_top DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+39,"pe_top ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+40,"pe_top MEM_SIZE", false,-1, 31,0);
        tracep->declBus(c+41,"pe_top IMG_BASE", false,-1, 31,0);
        tracep->declBus(c+42,"pe_top WEIGHT_BASE", false,-1, 31,0);
        tracep->declBus(c+43,"pe_top IM2COL_BASE", false,-1, 31,0);
        tracep->declBus(c+44,"pe_top OUTPUT_BASE", false,-1, 31,0);
        tracep->declArray(c+2,"pe_top X", false,-1, 95,0);
        tracep->declQuad(c+5,"pe_top W", false,-1, 63,0);
        tracep->declArray(c+45,"pe_top Y", false,-1, 191,0);
        {int i; for (i=0; i<4; i++) {
                tracep->declArray(c+8+i*3,"pe_top X_buffer", true,(i+0), 95,0);}}
        {int i; for (i=0; i<4; i++) {
                tracep->declQuad(c+20+i*2,"pe_top W_buffer", true,(i+0), 63,0);}}
        tracep->declBus(c+51,"pe_top addr_rd", false,-1, 31,0);
        tracep->declBus(c+52,"pe_top addr_wr", false,-1, 31,0);
        tracep->declBus(c+34,"pe_top data_rd", false,-1, 31,0);
        tracep->declBus(c+53,"pe_top data_wr", false,-1, 31,0);
        tracep->declBit(c+54,"pe_top mem_wr_en", false,-1);
        tracep->declBit(c+28,"pe_top rst_im2col", false,-1);
        tracep->declBit(c+29,"pe_top rst_systolic", false,-1);
        tracep->declBit(c+1,"pe_top im2col_done", false,-1);
        tracep->declBit(c+55,"pe_top systolic_done", false,-1);
        tracep->declBus(c+30,"pe_top state", false,-1, 1,0);
        tracep->declBit(c+31,"pe_top rst_n", false,-1);
        tracep->declBus(c+32,"pe_top rst_cnt", false,-1, 1,0);
        tracep->declBus(c+7,"pe_top X_count", false,-1, 31,0);
        tracep->declBus(c+35,"pe_top im2col IMG_C", false,-1, 31,0);
        tracep->declBus(c+37,"pe_top im2col IMG_W", false,-1, 31,0);
        tracep->declBus(c+36,"pe_top im2col IMG_H", false,-1, 31,0);
        tracep->declBus(c+39,"pe_top im2col DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+39,"pe_top im2col ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+37,"pe_top im2col FILTER_SIZE", false,-1, 31,0);
        tracep->declBus(c+41,"pe_top im2col IMG_BASE", false,-1, 31,0);
        tracep->declBus(c+43,"pe_top im2col IM2COL_BASE", false,-1, 31,0);
        tracep->declBit(c+33,"pe_top im2col clk", false,-1);
        tracep->declBit(c+28,"pe_top im2col rst_n", false,-1);
        tracep->declBus(c+34,"pe_top im2col data_rd", false,-1, 31,0);
        tracep->declBus(c+53,"pe_top im2col data_wr", false,-1, 31,0);
        tracep->declBus(c+52,"pe_top im2col addr_wr", false,-1, 31,0);
        tracep->declBus(c+51,"pe_top im2col addr_rd", false,-1, 31,0);
        tracep->declBit(c+1,"pe_top im2col done", false,-1);
        tracep->declBit(c+54,"pe_top im2col mem_wr_en", false,-1);
        tracep->declBus(c+36,"pe_top systolic_array M", false,-1, 31,0);
        tracep->declBus(c+35,"pe_top systolic_array N", false,-1, 31,0);
        tracep->declBus(c+38,"pe_top systolic_array K", false,-1, 31,0);
        tracep->declBus(c+39,"pe_top systolic_array DATA_WIDTH", false,-1, 31,0);
        tracep->declBit(c+33,"pe_top systolic_array clk", false,-1);
        tracep->declBit(c+29,"pe_top systolic_array rst_n", false,-1);
        tracep->declArray(c+2,"pe_top systolic_array X", false,-1, 95,0);
        tracep->declQuad(c+5,"pe_top systolic_array W", false,-1, 63,0);
        tracep->declArray(c+45,"pe_top systolic_array Y", false,-1, 191,0);
        tracep->declBit(c+55,"pe_top systolic_array done", false,-1);
    }
}

void Vtop::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vtop::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vtop::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->pe_top__DOT__im2col_done));
        tracep->fullWData(oldp+2,(vlTOPp->pe_top__DOT__X),96);
        tracep->fullQData(oldp+5,(vlTOPp->pe_top__DOT__W),64);
        tracep->fullIData(oldp+7,(vlTOPp->pe_top__DOT__X_count),32);
        tracep->fullWData(oldp+8,(vlTOPp->pe_top__DOT__X_buffer[0]),96);
        tracep->fullWData(oldp+11,(vlTOPp->pe_top__DOT__X_buffer[1]),96);
        tracep->fullWData(oldp+14,(vlTOPp->pe_top__DOT__X_buffer[2]),96);
        tracep->fullWData(oldp+17,(vlTOPp->pe_top__DOT__X_buffer[3]),96);
        tracep->fullQData(oldp+20,(vlTOPp->pe_top__DOT__W_buffer[0]),64);
        tracep->fullQData(oldp+22,(vlTOPp->pe_top__DOT__W_buffer[1]),64);
        tracep->fullQData(oldp+24,(vlTOPp->pe_top__DOT__W_buffer[2]),64);
        tracep->fullQData(oldp+26,(vlTOPp->pe_top__DOT__W_buffer[3]),64);
        tracep->fullBit(oldp+28,(vlTOPp->pe_top__DOT__rst_im2col));
        tracep->fullBit(oldp+29,(vlTOPp->pe_top__DOT__rst_systolic));
        tracep->fullCData(oldp+30,(vlTOPp->pe_top__DOT__state),2);
        tracep->fullBit(oldp+31,(vlTOPp->pe_top__DOT__rst_n));
        tracep->fullCData(oldp+32,(vlTOPp->pe_top__DOT__rst_cnt),2);
        tracep->fullBit(oldp+33,(vlTOPp->clk));
        tracep->fullIData(oldp+34,(vlTOPp->pe_top__DOT__data_rd),32);
        tracep->fullIData(oldp+35,(4U),32);
        tracep->fullIData(oldp+36,(3U),32);
        tracep->fullIData(oldp+37,(1U),32);
        tracep->fullIData(oldp+38,(2U),32);
        tracep->fullIData(oldp+39,(0x20U),32);
        tracep->fullIData(oldp+40,(0x5000U),32);
        tracep->fullIData(oldp+41,(0U),32);
        tracep->fullIData(oldp+42,(0x1000U),32);
        tracep->fullIData(oldp+43,(0x2000U),32);
        tracep->fullIData(oldp+44,(0x3000U),32);
        tracep->fullWData(oldp+45,(vlTOPp->pe_top__DOT__Y),192);
        tracep->fullIData(oldp+51,(vlTOPp->pe_top__DOT__addr_rd),32);
        tracep->fullIData(oldp+52,(vlTOPp->pe_top__DOT__addr_wr),32);
        tracep->fullIData(oldp+53,(vlTOPp->pe_top__DOT__data_wr),32);
        tracep->fullBit(oldp+54,(vlTOPp->pe_top__DOT__mem_wr_en));
        tracep->fullBit(oldp+55,(vlTOPp->pe_top__DOT__systolic_done));
    }
}
