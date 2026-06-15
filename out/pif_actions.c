/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#include <nfp/mem_atomic.h>
#include <nfp/mem_ring.h>
#include <nfp/me.h>
#include <nfp/cls.h>
#include "mac_time.h"
#include "pif_common.h"
#include "pkt_clone.h"

#ifdef PIF_DEBUG
    __export __emem_n(0) uint64_t pif_act_stats[PIF_ACTION_ID_MAX + 1];
#endif

extern __nnr uint32_t calc_fld_bmsk;

#define BITRANGE(var, width, offset) \
    (((var) >> (offset)) & ((1 << (width)) - 1))

extern __lmem __shared struct mac_time_state mac_time_state;

/* external action primitive update_counter */
extern int pif_plugin_update_counter(__lmem uint32_t *parrep, __xread uint32_t *actdatabuf);

/* external action primitive update_frame2 */
extern int pif_plugin_update_frame2(__lmem uint32_t *parrep, __xread uint32_t *actdatabuf);

/* external action primitive update_frame */
extern int pif_plugin_update_frame(__lmem uint32_t *parrep, __xread uint32_t *actdatabuf);

/* external action primitive update_counter2 */
extern int pif_plugin_update_counter2(__lmem uint32_t *parrep, __xread uint32_t *actdatabuf);

static int pif_action_exec_num_decrement(__lmem uint32_t *_pif_parrep, __xread uint32_t *_pif_actdatabuf, unsigned _pif_debug)
{
    int _pif_return = PIF_RETURN_FORWARD;
    __xread struct pif_action_actiondata_num_decrement *_pif_act_data = (__xread struct pif_action_actiondata_num_decrement *)_pif_actdatabuf;
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
    __lmem struct pif_header_standard_metadata *standard_metadata;
    __lmem struct pif_header_sflow_header *sflow_header;
#ifdef PIF_DEBUG
    __debug_label("pif_action_state_num_decrement");
#endif

    standard_metadata = (__lmem struct pif_header_standard_metadata *) (_pif_parrep + PIF_PARREP_standard_metadata_OFF_LW);
    sflow_header = (__lmem struct pif_header_sflow_header *) (_pif_parrep + PIF_PARREP_sflow_header_OFF_LW);
    PIF_PARREP_SET_sflow_header_DIRTY(_pif_ctldata);

    {
        /* subtract_from_field(sflow_header.num_samples,0x1) */
        unsigned int pif_expression___pif_convexpr__0_register_0;

        /* primitive body */
        //expression __pif_convexpr__0: (sflow_header.num_samples) - (0x1)
        {
        unsigned int pif_expression___pif_convexpr__0_register_1;
        unsigned int pif_expression___pif_convexpr__0_register_2;
        //subexpression 2: 0x1
        // constant : 0x1

        //subexpression 0: (sflow_header.num_samples)-(0x1)
        pif_expression___pif_convexpr__0_register_1 = sflow_header->num_samples;
        pif_expression___pif_convexpr__0_register_2 = 0x1;
        pif_expression___pif_convexpr__0_register_0 = pif_expression___pif_convexpr__0_register_1 - pif_expression___pif_convexpr__0_register_2;
        }

        sflow_header->num_samples = pif_expression___pif_convexpr__0_register_0;

    }
    {
        /* modify_field(standard_metadata.egress_spec,espec) */

        /* primitive body */
        standard_metadata->egress_spec = _pif_act_data->espec;

    }
    return _pif_return;
}

static int pif_action_exec_need_recirculate(__lmem uint32_t *_pif_parrep, __xread uint32_t *_pif_actdatabuf, unsigned _pif_debug)
{
    int _pif_return = PIF_RETURN_FORWARD;
    __xread struct pif_action_actiondata_need_recirculate *_pif_act_data = (__xread struct pif_action_actiondata_need_recirculate *)_pif_actdatabuf;
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
    __lmem struct pif_header_standard_metadata *standard_metadata;
    __lmem struct pif_header_sflow_header *sflow_header;
#ifdef PIF_DEBUG
    __debug_label("pif_action_state_need_recirculate");
#endif

    standard_metadata = (__lmem struct pif_header_standard_metadata *) (_pif_parrep + PIF_PARREP_standard_metadata_OFF_LW);
    sflow_header = (__lmem struct pif_header_sflow_header *) (_pif_parrep + PIF_PARREP_sflow_header_OFF_LW);
    PIF_PARREP_SET_sflow_header_DIRTY(_pif_ctldata);

    {
        /* update_counter() */

        /* primitive body */
        /* external primitive update_counter */
        _pif_return = pif_plugin_update_counter(_pif_parrep, 0);
    }
    {
        /* subtract_from_field(sflow_header.num_samples,0x1) */
        unsigned int pif_expression___pif_convexpr__1_register_0;

        /* primitive body */
        //expression __pif_convexpr__1: (sflow_header.num_samples) - (0x1)
        {
        unsigned int pif_expression___pif_convexpr__1_register_1;
        unsigned int pif_expression___pif_convexpr__1_register_2;
        //subexpression 2: 0x1
        // constant : 0x1

        //subexpression 0: (sflow_header.num_samples)-(0x1)
        pif_expression___pif_convexpr__1_register_1 = sflow_header->num_samples;
        pif_expression___pif_convexpr__1_register_2 = 0x1;
        pif_expression___pif_convexpr__1_register_0 = pif_expression___pif_convexpr__1_register_1 - pif_expression___pif_convexpr__1_register_2;
        }

        sflow_header->num_samples = pif_expression___pif_convexpr__1_register_0;

    }
    {
        /* update_counter2() */

        /* primitive body */
        /* external primitive update_counter2 */
        _pif_return = pif_plugin_update_counter2(_pif_parrep, 0);
    }
    {
        /* subtract_from_field(sflow_header.num_samples,0x1) */
        unsigned int pif_expression___pif_convexpr__2_register_0;

        /* primitive body */
        //expression __pif_convexpr__2: (sflow_header.num_samples) - (0x1)
        {
        unsigned int pif_expression___pif_convexpr__2_register_1;
        unsigned int pif_expression___pif_convexpr__2_register_2;
        //subexpression 2: 0x1
        // constant : 0x1

        //subexpression 0: (sflow_header.num_samples)-(0x1)
        pif_expression___pif_convexpr__2_register_1 = sflow_header->num_samples;
        pif_expression___pif_convexpr__2_register_2 = 0x1;
        pif_expression___pif_convexpr__2_register_0 = pif_expression___pif_convexpr__2_register_1 - pif_expression___pif_convexpr__2_register_2;
        }

        sflow_header->num_samples = pif_expression___pif_convexpr__2_register_0;

    }
    {
        /* modify_field(standard_metadata.egress_spec,espec) */

        /* primitive body */
        standard_metadata->egress_spec = _pif_act_data->espec;

    }
    return _pif_return;
}

static int pif_action_exec_do_recirculate(__lmem uint32_t *_pif_parrep, __xread uint32_t *_pif_actdatabuf, unsigned _pif_debug)
{
    int _pif_return = PIF_RETURN_FORWARD;
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
    __lmem struct pif_header_sflow_sample_header *sflow_sample_header;
    __lmem struct pif_header_recirculate_fl *recirculate_fl;
    __lmem struct pif_header_sflow_counter2 *sflow_counter2;
    __lmem struct pif_header_sflow_counter *sflow_counter;
#ifdef PIF_DEBUG
    __debug_label("pif_action_state_do_recirculate");
#endif

    sflow_sample_header = (__lmem struct pif_header_sflow_sample_header *) (_pif_parrep + PIF_PARREP_sflow_sample_header_OFF_LW);
    recirculate_fl = (__lmem struct pif_header_recirculate_fl *) (_pif_parrep + PIF_PARREP_recirculate_fl_OFF_LW);
    sflow_counter2 = (__lmem struct pif_header_sflow_counter2 *) (_pif_parrep + PIF_PARREP_sflow_counter2_OFF_LW);
    sflow_counter = (__lmem struct pif_header_sflow_counter *) (_pif_parrep + PIF_PARREP_sflow_counter_OFF_LW);
    PIF_PARREP_SET_sflow_counter2_DIRTY(_pif_ctldata);
    PIF_PARREP_SET_sflow_sample_header_DIRTY(_pif_ctldata);
    PIF_PARREP_SET_sflow_counter_DIRTY(_pif_ctldata);

    {
        /* remove_header(sflow_sample_header) */

        /* primitive body */
        {
            PIF_PARREP_CLEAR_sflow_sample_header_VALID(_pif_ctldata);
        }
    }
    {
        /* remove_header(sflow_counter) */

        /* primitive body */
        {
            PIF_PARREP_CLEAR_sflow_counter_VALID(_pif_ctldata);
        }
    }
    {
        /* remove_header(sflow_counter2) */

        /* primitive body */
        {
            PIF_PARREP_CLEAR_sflow_counter2_VALID(_pif_ctldata);
        }
    }
    {
        /* recirculate(parse_next) */

        /* primitive body */
        {
            __lmem struct pif_header_standard_metadata *stdmd = (__lmem struct pif_header_standard_metadata *) (parrep + PIF_PARREP_standard_metadata_OFF_LW);

            /* 
             * Set packet type as RECIRCULATE packet and
             * set top bit in recurse_field_list spec field (indicating recirculate) as well as bit for recirculate field list.
             */
            if (PIF_PKT_RECURSE_FIELDLIST_ID_parse_next <= PIF_PKT_RECURSE_FIELD_LISTS_MAX) {
                pkt_dup_state.__raw = PIF_DUP_ACTION_SET(PIF_PKT_INSTANCE_TYPE_INGRESS_RECIRC);
                recurse_field_list |= (0x01 << 31);
                recurse_field_list |= (1 << (PIF_PKT_RECURSE_FIELDLIST_ID_parse_next - 1));
            }
        }
    }
    return _pif_return;
}

static int pif_action_exec_drop_act(__lmem uint32_t *_pif_parrep, __xread uint32_t *_pif_actdatabuf, unsigned _pif_debug)
{
    int _pif_return = PIF_RETURN_FORWARD;
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
#ifdef PIF_DEBUG
    __debug_label("pif_action_state_drop_act");
#endif


    {
        /* drop() */

        /* primitive body */
        _pif_return = PIF_RETURN_DROP;
    }
    return _pif_return;
}

static int pif_action_exec_stop_recirculate2(__lmem uint32_t *_pif_parrep, __xread uint32_t *_pif_actdatabuf, unsigned _pif_debug)
{
    int _pif_return = PIF_RETURN_FORWARD;
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
    __lmem struct pif_header_sflow_header *sflow_header;
#ifdef PIF_DEBUG
    __debug_label("pif_action_state_stop_recirculate2");
#endif

    sflow_header = (__lmem struct pif_header_sflow_header *) (_pif_parrep + PIF_PARREP_sflow_header_OFF_LW);
    PIF_PARREP_SET_sflow_header_DIRTY(_pif_ctldata);

    {
        /* update_counter() */

        /* primitive body */
        /* external primitive update_counter */
        _pif_return = pif_plugin_update_counter(_pif_parrep, 0);
    }
    {
        /* subtract_from_field(sflow_header.num_samples,0x1) */
        unsigned int pif_expression___pif_convexpr__3_register_0;

        /* primitive body */
        //expression __pif_convexpr__3: (sflow_header.num_samples) - (0x1)
        {
        unsigned int pif_expression___pif_convexpr__3_register_1;
        unsigned int pif_expression___pif_convexpr__3_register_2;
        //subexpression 2: 0x1
        // constant : 0x1

        //subexpression 0: (sflow_header.num_samples)-(0x1)
        pif_expression___pif_convexpr__3_register_1 = sflow_header->num_samples;
        pif_expression___pif_convexpr__3_register_2 = 0x1;
        pif_expression___pif_convexpr__3_register_0 = pif_expression___pif_convexpr__3_register_1 - pif_expression___pif_convexpr__3_register_2;
        }

        sflow_header->num_samples = pif_expression___pif_convexpr__3_register_0;

    }
    {
        /* update_counter2() */

        /* primitive body */
        /* external primitive update_counter2 */
        _pif_return = pif_plugin_update_counter2(_pif_parrep, 0);
    }
    {
        /* subtract_from_field(sflow_header.num_samples,0x1) */
        unsigned int pif_expression___pif_convexpr__4_register_0;

        /* primitive body */
        //expression __pif_convexpr__4: (sflow_header.num_samples) - (0x1)
        {
        unsigned int pif_expression___pif_convexpr__4_register_1;
        unsigned int pif_expression___pif_convexpr__4_register_2;
        //subexpression 2: 0x1
        // constant : 0x1

        //subexpression 0: (sflow_header.num_samples)-(0x1)
        pif_expression___pif_convexpr__4_register_1 = sflow_header->num_samples;
        pif_expression___pif_convexpr__4_register_2 = 0x1;
        pif_expression___pif_convexpr__4_register_0 = pif_expression___pif_convexpr__4_register_1 - pif_expression___pif_convexpr__4_register_2;
        }

        sflow_header->num_samples = pif_expression___pif_convexpr__4_register_0;

    }
    {
        /* drop() */

        /* primitive body */
        _pif_return = PIF_RETURN_DROP;
    }
    return _pif_return;
}

static int pif_action_exec_stop_recirculate1(__lmem uint32_t *_pif_parrep, __xread uint32_t *_pif_actdatabuf, unsigned _pif_debug)
{
    int _pif_return = PIF_RETURN_FORWARD;
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
    __lmem struct pif_header_sflow_header *sflow_header;
#ifdef PIF_DEBUG
    __debug_label("pif_action_state_stop_recirculate1");
#endif

    sflow_header = (__lmem struct pif_header_sflow_header *) (_pif_parrep + PIF_PARREP_sflow_header_OFF_LW);
    PIF_PARREP_SET_sflow_header_DIRTY(_pif_ctldata);

    {
        /* update_counter() */

        /* primitive body */
        /* external primitive update_counter */
        _pif_return = pif_plugin_update_counter(_pif_parrep, 0);
    }
    {
        /* subtract_from_field(sflow_header.num_samples,0x1) */
        unsigned int pif_expression___pif_convexpr__5_register_0;

        /* primitive body */
        //expression __pif_convexpr__5: (sflow_header.num_samples) - (0x1)
        {
        unsigned int pif_expression___pif_convexpr__5_register_1;
        unsigned int pif_expression___pif_convexpr__5_register_2;
        //subexpression 2: 0x1
        // constant : 0x1

        //subexpression 0: (sflow_header.num_samples)-(0x1)
        pif_expression___pif_convexpr__5_register_1 = sflow_header->num_samples;
        pif_expression___pif_convexpr__5_register_2 = 0x1;
        pif_expression___pif_convexpr__5_register_0 = pif_expression___pif_convexpr__5_register_1 - pif_expression___pif_convexpr__5_register_2;
        }

        sflow_header->num_samples = pif_expression___pif_convexpr__5_register_0;

    }
    {
        /* drop() */

        /* primitive body */
        _pif_return = PIF_RETURN_DROP;
    }
    return _pif_return;
}

static int pif_action_exec_record_flow2(__lmem uint32_t *_pif_parrep, __xread uint32_t *_pif_actdatabuf, unsigned _pif_debug)
{
    int _pif_return = PIF_RETURN_FORWARD;
    __xread struct pif_action_actiondata_record_flow2 *_pif_act_data = (__xread struct pif_action_actiondata_record_flow2 *)_pif_actdatabuf;
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
    __lmem struct pif_header_standard_metadata *standard_metadata;
    __lmem struct pif_header_sflow_header *sflow_header;
#ifdef PIF_DEBUG
    __debug_label("pif_action_state_record_flow2");
#endif

    standard_metadata = (__lmem struct pif_header_standard_metadata *) (_pif_parrep + PIF_PARREP_standard_metadata_OFF_LW);
    sflow_header = (__lmem struct pif_header_sflow_header *) (_pif_parrep + PIF_PARREP_sflow_header_OFF_LW);
    PIF_PARREP_SET_sflow_header_DIRTY(_pif_ctldata);

    {
        /* update_frame2() */

        /* primitive body */
        /* external primitive update_frame2 */
        _pif_return = pif_plugin_update_frame2(_pif_parrep, 0);
    }
    {
        /* subtract_from_field(sflow_header.num_samples,0x1) */
        unsigned int pif_expression___pif_convexpr__6_register_0;

        /* primitive body */
        //expression __pif_convexpr__6: (sflow_header.num_samples) - (0x1)
        {
        unsigned int pif_expression___pif_convexpr__6_register_1;
        unsigned int pif_expression___pif_convexpr__6_register_2;
        //subexpression 2: 0x1
        // constant : 0x1

        //subexpression 0: (sflow_header.num_samples)-(0x1)
        pif_expression___pif_convexpr__6_register_1 = sflow_header->num_samples;
        pif_expression___pif_convexpr__6_register_2 = 0x1;
        pif_expression___pif_convexpr__6_register_0 = pif_expression___pif_convexpr__6_register_1 - pif_expression___pif_convexpr__6_register_2;
        }

        sflow_header->num_samples = pif_expression___pif_convexpr__6_register_0;

    }
    {
        /* modify_field(standard_metadata.egress_spec,espec) */

        /* primitive body */
        standard_metadata->egress_spec = _pif_act_data->espec;

    }
    return _pif_return;
}

static int pif_action_exec_stop_flow1(__lmem uint32_t *_pif_parrep, __xread uint32_t *_pif_actdatabuf, unsigned _pif_debug)
{
    int _pif_return = PIF_RETURN_FORWARD;
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
    __lmem struct pif_header_sflow_header *sflow_header;
#ifdef PIF_DEBUG
    __debug_label("pif_action_state_stop_flow1");
#endif

    sflow_header = (__lmem struct pif_header_sflow_header *) (_pif_parrep + PIF_PARREP_sflow_header_OFF_LW);
    PIF_PARREP_SET_sflow_header_DIRTY(_pif_ctldata);

    {
        /* update_frame() */

        /* primitive body */
        /* external primitive update_frame */
        _pif_return = pif_plugin_update_frame(_pif_parrep, 0);
    }
    {
        /* subtract_from_field(sflow_header.num_samples,0x1) */
        unsigned int pif_expression___pif_convexpr__7_register_0;

        /* primitive body */
        //expression __pif_convexpr__7: (sflow_header.num_samples) - (0x1)
        {
        unsigned int pif_expression___pif_convexpr__7_register_1;
        unsigned int pif_expression___pif_convexpr__7_register_2;
        //subexpression 2: 0x1
        // constant : 0x1

        //subexpression 0: (sflow_header.num_samples)-(0x1)
        pif_expression___pif_convexpr__7_register_1 = sflow_header->num_samples;
        pif_expression___pif_convexpr__7_register_2 = 0x1;
        pif_expression___pif_convexpr__7_register_0 = pif_expression___pif_convexpr__7_register_1 - pif_expression___pif_convexpr__7_register_2;
        }

        sflow_header->num_samples = pif_expression___pif_convexpr__7_register_0;

    }
    return _pif_return;
}

static int pif_action_exec_record_flow1(__lmem uint32_t *_pif_parrep, __xread uint32_t *_pif_actdatabuf, unsigned _pif_debug)
{
    int _pif_return = PIF_RETURN_FORWARD;
    __xread struct pif_action_actiondata_record_flow1 *_pif_act_data = (__xread struct pif_action_actiondata_record_flow1 *)_pif_actdatabuf;
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
    __lmem struct pif_header_standard_metadata *standard_metadata;
    __lmem struct pif_header_sflow_header *sflow_header;
#ifdef PIF_DEBUG
    __debug_label("pif_action_state_record_flow1");
#endif

    standard_metadata = (__lmem struct pif_header_standard_metadata *) (_pif_parrep + PIF_PARREP_standard_metadata_OFF_LW);
    sflow_header = (__lmem struct pif_header_sflow_header *) (_pif_parrep + PIF_PARREP_sflow_header_OFF_LW);
    PIF_PARREP_SET_sflow_header_DIRTY(_pif_ctldata);

    {
        /* update_frame() */

        /* primitive body */
        /* external primitive update_frame */
        _pif_return = pif_plugin_update_frame(_pif_parrep, 0);
    }
    {
        /* subtract_from_field(sflow_header.num_samples,0x1) */
        unsigned int pif_expression___pif_convexpr__8_register_0;

        /* primitive body */
        //expression __pif_convexpr__8: (sflow_header.num_samples) - (0x1)
        {
        unsigned int pif_expression___pif_convexpr__8_register_1;
        unsigned int pif_expression___pif_convexpr__8_register_2;
        //subexpression 2: 0x1
        // constant : 0x1

        //subexpression 0: (sflow_header.num_samples)-(0x1)
        pif_expression___pif_convexpr__8_register_1 = sflow_header->num_samples;
        pif_expression___pif_convexpr__8_register_2 = 0x1;
        pif_expression___pif_convexpr__8_register_0 = pif_expression___pif_convexpr__8_register_1 - pif_expression___pif_convexpr__8_register_2;
        }

        sflow_header->num_samples = pif_expression___pif_convexpr__8_register_0;

    }
    {
        /* modify_field(standard_metadata.egress_spec,espec) */

        /* primitive body */
        standard_metadata->egress_spec = _pif_act_data->espec;

    }
    return _pif_return;
}

static int pif_action_exec_forward(__lmem uint32_t *_pif_parrep, __xread uint32_t *_pif_actdatabuf, unsigned _pif_debug)
{
    int _pif_return = PIF_RETURN_FORWARD;
    __xread struct pif_action_actiondata_forward *_pif_act_data = (__xread struct pif_action_actiondata_forward *)_pif_actdatabuf;
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
    __lmem struct pif_header_standard_metadata *standard_metadata;
#ifdef PIF_DEBUG
    __debug_label("pif_action_state_forward");
#endif

    standard_metadata = (__lmem struct pif_header_standard_metadata *) (_pif_parrep + PIF_PARREP_standard_metadata_OFF_LW);

    {
        /* modify_field(standard_metadata.egress_spec,espec) */

        /* primitive body */
        standard_metadata->egress_spec = _pif_act_data->espec;

    }
    return _pif_return;
}

static int pif_action_exec_stop_flow2(__lmem uint32_t *_pif_parrep, __xread uint32_t *_pif_actdatabuf, unsigned _pif_debug)
{
    int _pif_return = PIF_RETURN_FORWARD;
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
    __lmem struct pif_header_sflow_header *sflow_header;
#ifdef PIF_DEBUG
    __debug_label("pif_action_state_stop_flow2");
#endif

    sflow_header = (__lmem struct pif_header_sflow_header *) (_pif_parrep + PIF_PARREP_sflow_header_OFF_LW);
    PIF_PARREP_SET_sflow_header_DIRTY(_pif_ctldata);

    {
        /* update_frame2() */

        /* primitive body */
        /* external primitive update_frame2 */
        _pif_return = pif_plugin_update_frame2(_pif_parrep, 0);
    }
    {
        /* subtract_from_field(sflow_header.num_samples,0x1) */
        unsigned int pif_expression___pif_convexpr__9_register_0;

        /* primitive body */
        //expression __pif_convexpr__9: (sflow_header.num_samples) - (0x1)
        {
        unsigned int pif_expression___pif_convexpr__9_register_1;
        unsigned int pif_expression___pif_convexpr__9_register_2;
        //subexpression 2: 0x1
        // constant : 0x1

        //subexpression 0: (sflow_header.num_samples)-(0x1)
        pif_expression___pif_convexpr__9_register_1 = sflow_header->num_samples;
        pif_expression___pif_convexpr__9_register_2 = 0x1;
        pif_expression___pif_convexpr__9_register_0 = pif_expression___pif_convexpr__9_register_1 - pif_expression___pif_convexpr__9_register_2;
        }

        sflow_header->num_samples = pif_expression___pif_convexpr__9_register_0;

    }
    {
        /* drop() */

        /* primitive body */
        _pif_return = PIF_RETURN_DROP;
    }
    return _pif_return;
}

static int pif_action_exec_fdo_recirculate(__lmem uint32_t *_pif_parrep, __xread uint32_t *_pif_actdatabuf, unsigned _pif_debug)
{
    int _pif_return = PIF_RETURN_FORWARD;
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
    __lmem struct pif_header_sflow_sample *sflow_sample;
    __lmem struct pif_header_sflow_sample2 *sflow_sample2;
    __lmem struct pif_header_sflow_sample_header *sflow_sample_header;
    __lmem struct pif_header_recirculate_fl *recirculate_fl;
#ifdef PIF_DEBUG
    __debug_label("pif_action_state_fdo_recirculate");
#endif

    sflow_sample = (__lmem struct pif_header_sflow_sample *) (_pif_parrep + PIF_PARREP_sflow_sample_OFF_LW);
    sflow_sample2 = (__lmem struct pif_header_sflow_sample2 *) (_pif_parrep + PIF_PARREP_sflow_sample2_OFF_LW);
    sflow_sample_header = (__lmem struct pif_header_sflow_sample_header *) (_pif_parrep + PIF_PARREP_sflow_sample_header_OFF_LW);
    recirculate_fl = (__lmem struct pif_header_recirculate_fl *) (_pif_parrep + PIF_PARREP_recirculate_fl_OFF_LW);
    PIF_PARREP_SET_sflow_sample_header_DIRTY(_pif_ctldata);
    PIF_PARREP_SET_sflow_sample_DIRTY(_pif_ctldata);
    PIF_PARREP_SET_sflow_sample2_DIRTY(_pif_ctldata);

    {
        /* remove_header(sflow_sample_header) */

        /* primitive body */
        {
            PIF_PARREP_CLEAR_sflow_sample_header_VALID(_pif_ctldata);
        }
    }
    {
        /* remove_header(sflow_sample) */

        /* primitive body */
        {
            PIF_PARREP_CLEAR_sflow_sample_VALID(_pif_ctldata);
        }
    }
    {
        /* remove_header(sflow_sample2) */

        /* primitive body */
        {
            PIF_PARREP_CLEAR_sflow_sample2_VALID(_pif_ctldata);
        }
    }
    {
        /* recirculate(parse_next) */

        /* primitive body */
        {
            __lmem struct pif_header_standard_metadata *stdmd = (__lmem struct pif_header_standard_metadata *) (parrep + PIF_PARREP_standard_metadata_OFF_LW);

            /* 
             * Set packet type as RECIRCULATE packet and
             * set top bit in recurse_field_list spec field (indicating recirculate) as well as bit for recirculate field list.
             */
            if (PIF_PKT_RECURSE_FIELDLIST_ID_parse_next <= PIF_PKT_RECURSE_FIELD_LISTS_MAX) {
                pkt_dup_state.__raw = PIF_DUP_ACTION_SET(PIF_PKT_INSTANCE_TYPE_INGRESS_RECIRC);
                recurse_field_list |= (0x01 << 31);
                recurse_field_list |= (1 << (PIF_PKT_RECURSE_FIELDLIST_ID_parse_next - 1));
            }
        }
    }
    return _pif_return;
}

extern __forceinline int pif_action_exec_op(__lmem uint32_t *parrep, __xread uint32_t *_actdata)
{
    __xread union pif_action_opdata *opdata = (__xread union pif_action_opdata *) _actdata;
    int ret = -1;

    if (opdata->action_id > PIF_ACTION_ID_MAX) {
        /* FIXME: TODO: account for bad action id */
        return -1;
    }

    PIF_DEBUG_SET_STATE(PIF_DEBUG_STATE_ACTION, opdata->action_id);
    switch (opdata->action_id) {
    case PIF_ACTION_ID_num_decrement:
        ret = pif_action_exec_num_decrement(parrep, _actdata + PIF_ACTION_OPDATA_LW, opdata->dbg_flags);
        break;
    case PIF_ACTION_ID_need_recirculate:
        ret = pif_action_exec_need_recirculate(parrep, _actdata + PIF_ACTION_OPDATA_LW, opdata->dbg_flags);
        break;
    case PIF_ACTION_ID_do_recirculate:
        ret = pif_action_exec_do_recirculate(parrep, _actdata + PIF_ACTION_OPDATA_LW, opdata->dbg_flags);
        break;
    case PIF_ACTION_ID_drop_act:
        ret = pif_action_exec_drop_act(parrep, _actdata + PIF_ACTION_OPDATA_LW, opdata->dbg_flags);
        break;
    case PIF_ACTION_ID_stop_recirculate2:
        ret = pif_action_exec_stop_recirculate2(parrep, _actdata + PIF_ACTION_OPDATA_LW, opdata->dbg_flags);
        break;
    case PIF_ACTION_ID_stop_recirculate1:
        ret = pif_action_exec_stop_recirculate1(parrep, _actdata + PIF_ACTION_OPDATA_LW, opdata->dbg_flags);
        break;
    case PIF_ACTION_ID_record_flow2:
        ret = pif_action_exec_record_flow2(parrep, _actdata + PIF_ACTION_OPDATA_LW, opdata->dbg_flags);
        break;
    case PIF_ACTION_ID_stop_flow1:
        ret = pif_action_exec_stop_flow1(parrep, _actdata + PIF_ACTION_OPDATA_LW, opdata->dbg_flags);
        break;
    case PIF_ACTION_ID_record_flow1:
        ret = pif_action_exec_record_flow1(parrep, _actdata + PIF_ACTION_OPDATA_LW, opdata->dbg_flags);
        break;
    case PIF_ACTION_ID_forward:
        ret = pif_action_exec_forward(parrep, _actdata + PIF_ACTION_OPDATA_LW, opdata->dbg_flags);
        break;
    case PIF_ACTION_ID_stop_flow2:
        ret = pif_action_exec_stop_flow2(parrep, _actdata + PIF_ACTION_OPDATA_LW, opdata->dbg_flags);
        break;
    case PIF_ACTION_ID_fdo_recirculate:
        ret = pif_action_exec_fdo_recirculate(parrep, _actdata + PIF_ACTION_OPDATA_LW, opdata->dbg_flags);
        break;
    }
#ifdef PIF_DEBUG
        mem_incr64((__mem __addr40 uint64_t *)(pif_act_stats + opdata->action_id));
#endif

    return ret;
}
