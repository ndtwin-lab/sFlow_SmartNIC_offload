/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#include <nfp/me.h>
#include "pif_common.h"

/****************************************
 * ingress_flow                         *
 ****************************************/

/* State transition functions */

static int handle_ingress_flow_record_flow1(__lmem uint32_t *_pif_parrep, __mem __addr40 uint32_t *actbuf, unsigned int actbuf_off, int *actlen, int *state)
{
    __gpr int action_id, ret;
    int next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_ingress_flow_record_flow1");
#endif

    {
        struct pif_lookup_result result;
        result = pif_lookup(PIF_TABLE_ID_record_flow1, _pif_parrep, actbuf, actbuf_off);
        action_id = result.action_id;
        *actlen = result.action_len;
    }

    next_state = PIF_CTLFLOW_STATE_ingress_flow__condition_4; /* always */

    if (*actlen > 0) {
        __critical_path();
        ret = pif_action_execute(_pif_parrep, actbuf, actbuf_off, *actlen);
        if (ret < 0)
            return ret;
        __critical_path();
        if (ret > 0)
            next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;
        __critical_path();
    }

    *state = next_state;
    return 0;
}

static int handle_ingress_flow__condition_4(__lmem uint32_t *_pif_parrep)
{
    unsigned int pif_expression__condition_4_register_2;
    __lmem struct pif_header_sflow_sample *sflow_sample;
    __lmem struct pif_header_sflow_sample2 *sflow_sample2;
    __lmem struct pif_parrep_ctldata *prdata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_ingress_flow__condition_4");
#endif

    sflow_sample = (__lmem struct pif_header_sflow_sample *) (_pif_parrep + PIF_PARREP_sflow_sample_OFF_LW);
    sflow_sample2 = (__lmem struct pif_header_sflow_sample2 *) (_pif_parrep + PIF_PARREP_sflow_sample2_OFF_LW);

    //expression _condition_4: ((valid(sflow_sample2)) and (((sflow_sample2.ip_flag) & (8191)) == (0))) and ((sflow_sample.eth_type) != (2054))
    {
    unsigned int pif_expression__condition_4_register_0;
    unsigned int pif_expression__condition_4_register_1;
    unsigned int pif_expression__condition_4_register_3;
    unsigned int pif_expression__condition_4_register_4;
    //subexpression 5: valid(sflow_sample2)
    pif_expression__condition_4_register_0 = PIF_PARREP_sflow_sample2_VALID(prdata);
    //subexpression 10: 8191
    // constant : 0x1fff

    //subexpression 7: (sflow_sample2.ip_flag)&(8191)
    pif_expression__condition_4_register_2 = sflow_sample2->ip_flag;
    pif_expression__condition_4_register_3 = 0x1fff;
    /* implicit cast 13 -> 16 */
    pif_expression__condition_4_register_4 = pif_expression__condition_4_register_3 & 0x1fff;
    pif_expression__condition_4_register_1 = pif_expression__condition_4_register_2 & pif_expression__condition_4_register_4;
    //subexpression 8: 0
    // constant : 0x0

    //subexpression 6: ((sflow_sample2.ip_flag)&(8191))==(0)
    pif_expression__condition_4_register_2 = 0x0;
    /* implicit cast 1 -> 16 */
    pif_expression__condition_4_register_3 = pif_expression__condition_4_register_2 & 0x1;
    pif_expression__condition_4_register_4 = (pif_expression__condition_4_register_1 == pif_expression__condition_4_register_3);
    //subexpression 1: (valid(sflow_sample2))and(((sflow_sample2.ip_flag)&(8191))==(0))
    pif_expression__condition_4_register_3 = (pif_expression__condition_4_register_0) && (pif_expression__condition_4_register_4);
    //subexpression 4: 2054
    // constant : 0x806

    //subexpression 2: (sflow_sample.eth_type)!=(2054)
    pif_expression__condition_4_register_0 = sflow_sample->eth_type;
    pif_expression__condition_4_register_1 = 0x806;
    /* implicit cast 12 -> 32 */
    pif_expression__condition_4_register_2 = pif_expression__condition_4_register_1 & 0xfff;
    pif_expression__condition_4_register_4 = (pif_expression__condition_4_register_0 != pif_expression__condition_4_register_2);
    //subexpression 0: ((valid(sflow_sample2))and(((sflow_sample2.ip_flag)&(8191))==(0)))and((sflow_sample.eth_type)!=(2054))
    pif_expression__condition_4_register_2 = (pif_expression__condition_4_register_3) && (pif_expression__condition_4_register_4);
    }

    if (pif_expression__condition_4_register_2)
        return PIF_CTLFLOW_STATE_ingress_flow_record_flow2;
    else
        return PIF_CTLFLOW_STATE_ingress_flow__condition_5;
}

static int handle_ingress_flow__condition_2(__lmem uint32_t *_pif_parrep)
{
    unsigned int pif_expression__condition_2_register_2;
    __lmem struct pif_header_sflow_sample *sflow_sample;
    __lmem struct pif_parrep_ctldata *prdata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_ingress_flow__condition_2");
#endif

    sflow_sample = (__lmem struct pif_header_sflow_sample *) (_pif_parrep + PIF_PARREP_sflow_sample_OFF_LW);

    //expression _condition_2: ((valid(sflow_sample)) and (((sflow_sample.ip_flag) & (8191)) == (0))) and ((sflow_sample.eth_type) != (2054))
    {
    unsigned int pif_expression__condition_2_register_0;
    unsigned int pif_expression__condition_2_register_1;
    unsigned int pif_expression__condition_2_register_3;
    unsigned int pif_expression__condition_2_register_4;
    //subexpression 5: valid(sflow_sample)
    pif_expression__condition_2_register_0 = PIF_PARREP_sflow_sample_VALID(prdata);
    //subexpression 10: 8191
    // constant : 0x1fff

    //subexpression 7: (sflow_sample.ip_flag)&(8191)
    pif_expression__condition_2_register_2 = sflow_sample->ip_flag;
    pif_expression__condition_2_register_3 = 0x1fff;
    /* implicit cast 13 -> 16 */
    pif_expression__condition_2_register_4 = pif_expression__condition_2_register_3 & 0x1fff;
    pif_expression__condition_2_register_1 = pif_expression__condition_2_register_2 & pif_expression__condition_2_register_4;
    //subexpression 8: 0
    // constant : 0x0

    //subexpression 6: ((sflow_sample.ip_flag)&(8191))==(0)
    pif_expression__condition_2_register_2 = 0x0;
    /* implicit cast 1 -> 16 */
    pif_expression__condition_2_register_3 = pif_expression__condition_2_register_2 & 0x1;
    pif_expression__condition_2_register_4 = (pif_expression__condition_2_register_1 == pif_expression__condition_2_register_3);
    //subexpression 1: (valid(sflow_sample))and(((sflow_sample.ip_flag)&(8191))==(0))
    pif_expression__condition_2_register_3 = (pif_expression__condition_2_register_0) && (pif_expression__condition_2_register_4);
    //subexpression 4: 2054
    // constant : 0x806

    //subexpression 2: (sflow_sample.eth_type)!=(2054)
    pif_expression__condition_2_register_0 = sflow_sample->eth_type;
    pif_expression__condition_2_register_1 = 0x806;
    /* implicit cast 12 -> 32 */
    pif_expression__condition_2_register_2 = pif_expression__condition_2_register_1 & 0xfff;
    pif_expression__condition_2_register_4 = (pif_expression__condition_2_register_0 != pif_expression__condition_2_register_2);
    //subexpression 0: ((valid(sflow_sample))and(((sflow_sample.ip_flag)&(8191))==(0)))and((sflow_sample.eth_type)!=(2054))
    pif_expression__condition_2_register_2 = (pif_expression__condition_2_register_3) && (pif_expression__condition_2_register_4);
    }

    if (pif_expression__condition_2_register_2)
        return PIF_CTLFLOW_STATE_ingress_flow_record_flow1;
    else
        return PIF_CTLFLOW_STATE_ingress_flow__condition_3;
}

static int handle_ingress_flow__condition_3(__lmem uint32_t *_pif_parrep)
{
    unsigned int pif_expression__condition_3_register_0;
    __lmem struct pif_parrep_ctldata *prdata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_ingress_flow__condition_3");
#endif

    //expression _condition_3: valid(sflow_sample)
    {
    //subexpression 0: valid(sflow_sample)
    pif_expression__condition_3_register_0 = PIF_PARREP_sflow_sample_VALID(prdata);
    }

    if (pif_expression__condition_3_register_0)
        return PIF_CTLFLOW_STATE_ingress_flow_no_record_flow1;
    else
        return PIF_CTLFLOW_STATE_ingress_flow_exit_control_flow;
}

static int handle_ingress_flow__condition_1(__lmem uint32_t *_pif_parrep)
{
    unsigned int pif_expression__condition_1_register_0;
    __lmem struct pif_parrep_ctldata *prdata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_ingress_flow__condition_1");
#endif

    //expression _condition_1: valid(sflow_counter)
    {
    //subexpression 0: valid(sflow_counter)
    pif_expression__condition_1_register_0 = PIF_PARREP_sflow_counter_VALID(prdata);
    }

    if (pif_expression__condition_1_register_0)
        return PIF_CTLFLOW_STATE_ingress_flow_in_tbl2;
    else
        return PIF_CTLFLOW_STATE_ingress_flow__condition_2;
}

static int handle_ingress_flow_in_tbl2(__lmem uint32_t *_pif_parrep, __mem __addr40 uint32_t *actbuf, unsigned int actbuf_off, int *actlen, int *state)
{
    __gpr int action_id, ret;
    int next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_ingress_flow_in_tbl2");
#endif

    {
        struct pif_lookup_result result;
        result = pif_lookup(PIF_TABLE_ID_in_tbl2, _pif_parrep, actbuf, actbuf_off);
        action_id = result.action_id;
        *actlen = result.action_len;
    }

    next_state = PIF_CTLFLOW_STATE_ingress_flow_exit_control_flow; /* always */

    if (*actlen > 0) {
        __critical_path();
        ret = pif_action_execute(_pif_parrep, actbuf, actbuf_off, *actlen);
        if (ret < 0)
            return ret;
        __critical_path();
        if (ret > 0)
            next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;
        __critical_path();
    }

    *state = next_state;
    return 0;
}

static int handle_ingress_flow__condition_6(__lmem uint32_t *_pif_parrep)
{
    unsigned int pif_expression__condition_6_register_4;
    __lmem struct pif_header_udp *udp;
    __lmem struct pif_parrep_ctldata *prdata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_ingress_flow__condition_6");
#endif

    udp = (__lmem struct pif_header_udp *) (_pif_parrep + PIF_PARREP_udp_OFF_LW);

    //expression _condition_6: (valid(udp)) and (((udp.dport) == (67)) or ((udp.dport) == (68)))
    {
    unsigned int pif_expression__condition_6_register_0;
    unsigned int pif_expression__condition_6_register_1;
    unsigned int pif_expression__condition_6_register_2;
    unsigned int pif_expression__condition_6_register_3;
    unsigned int pif_expression__condition_6_register_5;
    //subexpression 1: valid(udp)
    pif_expression__condition_6_register_0 = PIF_PARREP_udp_VALID(prdata);
    //subexpression 8: 67
    // constant : 0x43

    //subexpression 3: (udp.dport)==(67)
    pif_expression__condition_6_register_2 = udp->dport;
    pif_expression__condition_6_register_3 = 0x43;
    /* implicit cast 7 -> 16 */
    pif_expression__condition_6_register_4 = pif_expression__condition_6_register_3 & 0x7f;
    pif_expression__condition_6_register_1 = (pif_expression__condition_6_register_2 == pif_expression__condition_6_register_4);
    //subexpression 6: 68
    // constant : 0x44

    //subexpression 4: (udp.dport)==(68)
    pif_expression__condition_6_register_2 = udp->dport;
    pif_expression__condition_6_register_3 = 0x44;
    /* implicit cast 7 -> 16 */
    pif_expression__condition_6_register_5 = pif_expression__condition_6_register_3 & 0x7f;
    pif_expression__condition_6_register_4 = (pif_expression__condition_6_register_2 == pif_expression__condition_6_register_5);
    //subexpression 2: ((udp.dport)==(67))or((udp.dport)==(68))
    pif_expression__condition_6_register_5 = pif_expression__condition_6_register_1 || pif_expression__condition_6_register_4;
    //subexpression 0: (valid(udp))and(((udp.dport)==(67))or((udp.dport)==(68)))
    pif_expression__condition_6_register_4 = (pif_expression__condition_6_register_0) && (pif_expression__condition_6_register_5);
    }

    if (pif_expression__condition_6_register_4)
        return PIF_CTLFLOW_STATE_ingress_flow_exit_control_flow;
    else
        return PIF_CTLFLOW_STATE_ingress_flow_nor_tbl;
}

static int handle_ingress_flow_no_record_flow1(__lmem uint32_t *_pif_parrep, __mem __addr40 uint32_t *actbuf, unsigned int actbuf_off, int *actlen, int *state)
{
    __gpr int action_id, ret;
    int next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_ingress_flow_no_record_flow1");
#endif

    {
        struct pif_lookup_result result;
        result = pif_lookup(PIF_TABLE_ID_no_record_flow1, _pif_parrep, actbuf, actbuf_off);
        action_id = result.action_id;
        *actlen = result.action_len;
    }

    next_state = PIF_CTLFLOW_STATE_ingress_flow__condition_4; /* always */

    if (*actlen > 0) {
        __critical_path();
        ret = pif_action_execute(_pif_parrep, actbuf, actbuf_off, *actlen);
        if (ret < 0)
            return ret;
        __critical_path();
        if (ret > 0)
            next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;
        __critical_path();
    }

    *state = next_state;
    return 0;
}

static int handle_ingress_flow__condition_0(__lmem uint32_t *_pif_parrep)
{
    unsigned int pif_expression__condition_0_register_4;
    __lmem struct pif_header_udp *udp;
    __lmem struct pif_parrep_ctldata *prdata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_ingress_flow__condition_0");
#endif

    udp = (__lmem struct pif_header_udp *) (_pif_parrep + PIF_PARREP_udp_OFF_LW);

    //expression _condition_0: (valid(udp)) and ((udp.dport) == (6343))
    {
    unsigned int pif_expression__condition_0_register_0;
    unsigned int pif_expression__condition_0_register_1;
    unsigned int pif_expression__condition_0_register_2;
    unsigned int pif_expression__condition_0_register_3;
    //subexpression 1: valid(udp)
    pif_expression__condition_0_register_0 = PIF_PARREP_udp_VALID(prdata);
    //subexpression 4: 6343
    // constant : 0x18c7

    //subexpression 2: (udp.dport)==(6343)
    pif_expression__condition_0_register_2 = udp->dport;
    pif_expression__condition_0_register_3 = 0x18c7;
    /* implicit cast 13 -> 16 */
    pif_expression__condition_0_register_4 = pif_expression__condition_0_register_3 & 0x1fff;
    pif_expression__condition_0_register_1 = (pif_expression__condition_0_register_2 == pif_expression__condition_0_register_4);
    //subexpression 0: (valid(udp))and((udp.dport)==(6343))
    pif_expression__condition_0_register_4 = (pif_expression__condition_0_register_0) && (pif_expression__condition_0_register_1);
    }

    if (pif_expression__condition_0_register_4)
        return PIF_CTLFLOW_STATE_ingress_flow__condition_1;
    else
        return PIF_CTLFLOW_STATE_ingress_flow__condition_6;
}

static int handle_ingress_flow__condition_5(__lmem uint32_t *_pif_parrep)
{
    unsigned int pif_expression__condition_5_register_0;
    __lmem struct pif_parrep_ctldata *prdata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_ingress_flow__condition_5");
#endif

    //expression _condition_5: valid(sflow_sample2)
    {
    //subexpression 0: valid(sflow_sample2)
    pif_expression__condition_5_register_0 = PIF_PARREP_sflow_sample2_VALID(prdata);
    }

    if (pif_expression__condition_5_register_0)
        return PIF_CTLFLOW_STATE_ingress_flow_no_record_flow2;
    else
        return PIF_CTLFLOW_STATE_ingress_flow_exit_control_flow;
}

static int handle_ingress_flow_no_record_flow2(__lmem uint32_t *_pif_parrep, __mem __addr40 uint32_t *actbuf, unsigned int actbuf_off, int *actlen, int *state)
{
    __gpr int action_id, ret;
    int next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_ingress_flow_no_record_flow2");
#endif

    {
        struct pif_lookup_result result;
        result = pif_lookup(PIF_TABLE_ID_no_record_flow2, _pif_parrep, actbuf, actbuf_off);
        action_id = result.action_id;
        *actlen = result.action_len;
    }

    next_state = PIF_CTLFLOW_STATE_ingress_flow_exit_control_flow; /* always */

    if (*actlen > 0) {
        __critical_path();
        ret = pif_action_execute(_pif_parrep, actbuf, actbuf_off, *actlen);
        if (ret < 0)
            return ret;
        __critical_path();
        if (ret > 0)
            next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;
        __critical_path();
    }

    *state = next_state;
    return 0;
}

static int handle_ingress_flow_record_flow2(__lmem uint32_t *_pif_parrep, __mem __addr40 uint32_t *actbuf, unsigned int actbuf_off, int *actlen, int *state)
{
    __gpr int action_id, ret;
    int next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_ingress_flow_record_flow2");
#endif

    {
        struct pif_lookup_result result;
        result = pif_lookup(PIF_TABLE_ID_record_flow2, _pif_parrep, actbuf, actbuf_off);
        action_id = result.action_id;
        *actlen = result.action_len;
    }

    next_state = PIF_CTLFLOW_STATE_ingress_flow_exit_control_flow; /* always */

    if (*actlen > 0) {
        __critical_path();
        ret = pif_action_execute(_pif_parrep, actbuf, actbuf_off, *actlen);
        if (ret < 0)
            return ret;
        __critical_path();
        if (ret > 0)
            next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;
        __critical_path();
    }

    *state = next_state;
    return 0;
}

static int handle_ingress_flow_nor_tbl(__lmem uint32_t *_pif_parrep, __mem __addr40 uint32_t *actbuf, unsigned int actbuf_off, int *actlen, int *state)
{
    __gpr int action_id, ret;
    int next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_ingress_flow_nor_tbl");
#endif

    {
        struct pif_lookup_result result;
        result = pif_lookup(PIF_TABLE_ID_nor_tbl, _pif_parrep, actbuf, actbuf_off);
        action_id = result.action_id;
        *actlen = result.action_len;
    }

    next_state = PIF_CTLFLOW_STATE_ingress_flow_exit_control_flow; /* always */

    if (*actlen > 0) {
        __critical_path();
        ret = pif_action_execute(_pif_parrep, actbuf, actbuf_off, *actlen);
        if (ret < 0)
            return ret;
        __critical_path();
        if (ret > 0)
            next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;
        __critical_path();
    }

    *state = next_state;
    return 0;
}

/* Control flow entry point */

int pif_ctlflow_ingress_flow(int *start_state, __lmem uint32_t *_pif_parrep, __mem __addr40 uint32_t *actbuf, unsigned int actbuf_off)
{
    __gpr int actlen, totlen = 0;
    __gpr int ret;
    int pif_ctlflow_state_ingress_flow = PIF_CTLFLOW_STATE_ingress_flow__condition_0;

    while (pif_ctlflow_state_ingress_flow != PIF_CTLFLOW_STATE_ingress_flow_DONE) {
        PIF_DEBUG_SET_STATE(PIF_DEBUG_STATE_CONTROL, ((0 << 16) + pif_ctlflow_state_ingress_flow));
#ifdef PIF_DEBUG
        __debug_label("pif_ctlflow_state_ingress_flow");
#endif
        switch (pif_ctlflow_state_ingress_flow) {
        case PIF_CTLFLOW_STATE_ingress_flow_record_flow1:
            ret = handle_ingress_flow_record_flow1(_pif_parrep, actbuf, actbuf_off + totlen, (int *)&actlen, (int *)&pif_ctlflow_state_ingress_flow);
            break;
        case PIF_CTLFLOW_STATE_ingress_flow__condition_4:
            pif_ctlflow_state_ingress_flow = handle_ingress_flow__condition_4(_pif_parrep);
            continue;
        case PIF_CTLFLOW_STATE_ingress_flow__condition_2:
            pif_ctlflow_state_ingress_flow = handle_ingress_flow__condition_2(_pif_parrep);
            continue;
        case PIF_CTLFLOW_STATE_ingress_flow__condition_3:
            pif_ctlflow_state_ingress_flow = handle_ingress_flow__condition_3(_pif_parrep);
            continue;
        case PIF_CTLFLOW_STATE_ingress_flow__condition_1:
            pif_ctlflow_state_ingress_flow = handle_ingress_flow__condition_1(_pif_parrep);
            continue;
        case PIF_CTLFLOW_STATE_ingress_flow_in_tbl2:
            ret = handle_ingress_flow_in_tbl2(_pif_parrep, actbuf, actbuf_off + totlen, (int *)&actlen, (int *)&pif_ctlflow_state_ingress_flow);
            break;
        case PIF_CTLFLOW_STATE_ingress_flow__condition_6:
            pif_ctlflow_state_ingress_flow = handle_ingress_flow__condition_6(_pif_parrep);
            continue;
        case PIF_CTLFLOW_STATE_ingress_flow_no_record_flow1:
            ret = handle_ingress_flow_no_record_flow1(_pif_parrep, actbuf, actbuf_off + totlen, (int *)&actlen, (int *)&pif_ctlflow_state_ingress_flow);
            break;
        case PIF_CTLFLOW_STATE_ingress_flow__condition_0:
            pif_ctlflow_state_ingress_flow = handle_ingress_flow__condition_0(_pif_parrep);
            continue;
        case PIF_CTLFLOW_STATE_ingress_flow__condition_5:
            pif_ctlflow_state_ingress_flow = handle_ingress_flow__condition_5(_pif_parrep);
            continue;
        case PIF_CTLFLOW_STATE_ingress_flow_no_record_flow2:
            ret = handle_ingress_flow_no_record_flow2(_pif_parrep, actbuf, actbuf_off + totlen, (int *)&actlen, (int *)&pif_ctlflow_state_ingress_flow);
            break;
        case PIF_CTLFLOW_STATE_ingress_flow_record_flow2:
            ret = handle_ingress_flow_record_flow2(_pif_parrep, actbuf, actbuf_off + totlen, (int *)&actlen, (int *)&pif_ctlflow_state_ingress_flow);
            break;
        case PIF_CTLFLOW_STATE_ingress_flow_nor_tbl:
            ret = handle_ingress_flow_nor_tbl(_pif_parrep, actbuf, actbuf_off + totlen, (int *)&actlen, (int *)&pif_ctlflow_state_ingress_flow);
            break;
        }
        if (actlen < 0) /* error! */
            return actlen & ((~(1 << PIF_LOOKUP_ERROR_BIT)));
        __critical_path();
        totlen += actlen;
        if (ret < 0)
            return -totlen;
    }

    return totlen;
}

/****************************************
 * egress_flow                          *
 ****************************************/

/* State transition functions */

static int handle_egress_flow__condition_8(__lmem uint32_t *_pif_parrep)
{
    unsigned int pif_expression__condition_8_register_0;
    __lmem struct pif_header_num_metadata *num_metadata;

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_egress_flow__condition_8");
#endif

    num_metadata = (__lmem struct pif_header_num_metadata *) (_pif_parrep + PIF_PARREP_num_metadata_OFF_LW);

    //expression _condition_8: (num_metadata.cur_num) > (2)
    {
    unsigned int pif_expression__condition_8_register_1;
    unsigned int pif_expression__condition_8_register_2;
    unsigned int pif_expression__condition_8_register_3;
    //subexpression 2: 2
    // constant : 0x2

    //subexpression 0: (num_metadata.cur_num)>(2)
    pif_expression__condition_8_register_1 = num_metadata->cur_num;
    pif_expression__condition_8_register_2 = 0x2;
    /* implicit cast 2 -> 8 */
    pif_expression__condition_8_register_3 = pif_expression__condition_8_register_2 & 0x3;
    pif_expression__condition_8_register_0 = pif_expression__condition_8_register_1 > pif_expression__condition_8_register_3;
    }

    if (pif_expression__condition_8_register_0)
        return PIF_CTLFLOW_STATE_egress_flow_t_do_recirculate;
    else
        return PIF_CTLFLOW_STATE_egress_flow_exit_control_flow;
}

static int handle_egress_flow__condition_10(__lmem uint32_t *_pif_parrep)
{
    unsigned int pif_expression__condition_10_register_0;
    __lmem struct pif_header_num_metadata *num_metadata;

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_egress_flow__condition_10");
#endif

    num_metadata = (__lmem struct pif_header_num_metadata *) (_pif_parrep + PIF_PARREP_num_metadata_OFF_LW);

    //expression _condition_10: (num_metadata.cur_num) > (2)
    {
    unsigned int pif_expression__condition_10_register_1;
    unsigned int pif_expression__condition_10_register_2;
    unsigned int pif_expression__condition_10_register_3;
    //subexpression 2: 2
    // constant : 0x2

    //subexpression 0: (num_metadata.cur_num)>(2)
    pif_expression__condition_10_register_1 = num_metadata->cur_num;
    pif_expression__condition_10_register_2 = 0x2;
    /* implicit cast 2 -> 8 */
    pif_expression__condition_10_register_3 = pif_expression__condition_10_register_2 & 0x3;
    pif_expression__condition_10_register_0 = pif_expression__condition_10_register_1 > pif_expression__condition_10_register_3;
    }

    if (pif_expression__condition_10_register_0)
        return PIF_CTLFLOW_STATE_egress_flow_t_do_frecirculate;
    else
        return PIF_CTLFLOW_STATE_egress_flow_exit_control_flow;
}

static int handle_egress_flow__condition_7(__lmem uint32_t *_pif_parrep)
{
    unsigned int pif_expression__condition_7_register_0;
    __lmem struct pif_parrep_ctldata *prdata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_egress_flow__condition_7");
#endif

    //expression _condition_7: valid(sflow_counter)
    {
    //subexpression 0: valid(sflow_counter)
    pif_expression__condition_7_register_0 = PIF_PARREP_sflow_counter_VALID(prdata);
    }

    if (pif_expression__condition_7_register_0)
        return PIF_CTLFLOW_STATE_egress_flow__condition_8;
    else
        return PIF_CTLFLOW_STATE_egress_flow__condition_9;
}

static int handle_egress_flow__condition_9(__lmem uint32_t *_pif_parrep)
{
    unsigned int pif_expression__condition_9_register_0;
    __lmem struct pif_parrep_ctldata *prdata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_egress_flow__condition_9");
#endif

    //expression _condition_9: valid(sflow_sample)
    {
    //subexpression 0: valid(sflow_sample)
    pif_expression__condition_9_register_0 = PIF_PARREP_sflow_sample_VALID(prdata);
    }

    if (pif_expression__condition_9_register_0)
        return PIF_CTLFLOW_STATE_egress_flow__condition_10;
    else
        return PIF_CTLFLOW_STATE_egress_flow_exit_control_flow;
}

static int handle_egress_flow_t_do_recirculate(__lmem uint32_t *_pif_parrep, __mem __addr40 uint32_t *actbuf, unsigned int actbuf_off, int *actlen, int *state)
{
    __gpr int action_id, ret;
    int next_state = PIF_CTLFLOW_STATE_egress_flow_DONE;

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_egress_flow_t_do_recirculate");
#endif

    {
        struct pif_lookup_result result;
        result = pif_lookup(PIF_TABLE_ID_t_do_recirculate, _pif_parrep, actbuf, actbuf_off);
        action_id = result.action_id;
        *actlen = result.action_len;
    }

    if (action_id == PIF_ACTION_ID_do_recirculate)
        next_state = PIF_CTLFLOW_STATE_egress_flow_exit_control_flow;
    else /* default */
        next_state = PIF_CTLFLOW_STATE_egress_flow__condition_9;

    if (*actlen > 0) {
        __critical_path();
        ret = pif_action_execute(_pif_parrep, actbuf, actbuf_off, *actlen);
        if (ret < 0)
            return ret;
        __critical_path();
        if (ret > 0)
            next_state = PIF_CTLFLOW_STATE_egress_flow_DONE;
        __critical_path();
    }

    *state = next_state;
    return 0;
}

static int handle_egress_flow_t_do_frecirculate(__lmem uint32_t *_pif_parrep, __mem __addr40 uint32_t *actbuf, unsigned int actbuf_off, int *actlen, int *state)
{
    __gpr int action_id, ret;
    int next_state = PIF_CTLFLOW_STATE_egress_flow_DONE;

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_egress_flow_t_do_frecirculate");
#endif

    {
        struct pif_lookup_result result;
        result = pif_lookup(PIF_TABLE_ID_t_do_frecirculate, _pif_parrep, actbuf, actbuf_off);
        action_id = result.action_id;
        *actlen = result.action_len;
    }

    next_state = PIF_CTLFLOW_STATE_egress_flow_exit_control_flow; /* always */

    if (*actlen > 0) {
        __critical_path();
        ret = pif_action_execute(_pif_parrep, actbuf, actbuf_off, *actlen);
        if (ret < 0)
            return ret;
        __critical_path();
        if (ret > 0)
            next_state = PIF_CTLFLOW_STATE_egress_flow_DONE;
        __critical_path();
    }

    *state = next_state;
    return 0;
}

/* Control flow entry point */

int pif_ctlflow_egress_flow(int *start_state, __lmem uint32_t *_pif_parrep, __mem __addr40 uint32_t *actbuf, unsigned int actbuf_off)
{
    __gpr int actlen, totlen = 0;
    __gpr int ret;
    int pif_ctlflow_state_egress_flow = PIF_CTLFLOW_STATE_egress_flow__condition_7;

    while (pif_ctlflow_state_egress_flow != PIF_CTLFLOW_STATE_egress_flow_DONE) {
        PIF_DEBUG_SET_STATE(PIF_DEBUG_STATE_CONTROL, ((1 << 16) + pif_ctlflow_state_egress_flow));
#ifdef PIF_DEBUG
        __debug_label("pif_ctlflow_state_egress_flow");
#endif
        switch (pif_ctlflow_state_egress_flow) {
        case PIF_CTLFLOW_STATE_egress_flow__condition_8:
            pif_ctlflow_state_egress_flow = handle_egress_flow__condition_8(_pif_parrep);
            continue;
        case PIF_CTLFLOW_STATE_egress_flow__condition_10:
            pif_ctlflow_state_egress_flow = handle_egress_flow__condition_10(_pif_parrep);
            continue;
        case PIF_CTLFLOW_STATE_egress_flow__condition_7:
            pif_ctlflow_state_egress_flow = handle_egress_flow__condition_7(_pif_parrep);
            continue;
        case PIF_CTLFLOW_STATE_egress_flow__condition_9:
            pif_ctlflow_state_egress_flow = handle_egress_flow__condition_9(_pif_parrep);
            continue;
        case PIF_CTLFLOW_STATE_egress_flow_t_do_recirculate:
            ret = handle_egress_flow_t_do_recirculate(_pif_parrep, actbuf, actbuf_off + totlen, (int *)&actlen, (int *)&pif_ctlflow_state_egress_flow);
            break;
        case PIF_CTLFLOW_STATE_egress_flow_t_do_frecirculate:
            ret = handle_egress_flow_t_do_frecirculate(_pif_parrep, actbuf, actbuf_off + totlen, (int *)&actlen, (int *)&pif_ctlflow_state_egress_flow);
            break;
        }
        if (actlen < 0) /* error! */
            return actlen & ((~(1 << PIF_LOOKUP_ERROR_BIT)));
        __critical_path();
        totlen += actlen;
        if (ret < 0)
            return -totlen;
    }

    return totlen;
}
