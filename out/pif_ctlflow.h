/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_CTLFLOW_H__
#define __PIF_CTLFLOW_H__

/* Defines for checking flow presence */
#define PIF_CTLFLOW_HAS_ingress_flow
#define PIF_CTLFLOW_HAS_egress_flow

#define PIF_CTLFLOW_STATE_ingress 0
#define PIF_CTLFLOW_STATE_accept 0
/* Control state nodes for ingress_flow */
#define PIF_CTLFLOW_STATE_ingress_flow_DONE -1
#define PIF_CTLFLOW_STATE_ingress_flow_exit_control_flow -1
#define PIF_CTLFLOW_STATE_ingress_flow 0

#define PIF_CTLFLOW_STATE_ingress_flow_record_flow1 0
#define PIF_CTLFLOW_STATE_ingress_flow__condition_4 1
#define PIF_CTLFLOW_STATE_ingress_flow__condition_2 2
#define PIF_CTLFLOW_STATE_ingress_flow__condition_3 3
#define PIF_CTLFLOW_STATE_ingress_flow__condition_1 4
#define PIF_CTLFLOW_STATE_ingress_flow_in_tbl2 5
#define PIF_CTLFLOW_STATE_ingress_flow_no_record_flow1 6
#define PIF_CTLFLOW_STATE_ingress_flow__condition_0 7
#define PIF_CTLFLOW_STATE_ingress_flow__condition_5 8
#define PIF_CTLFLOW_STATE_ingress_flow_no_record_flow2 9
#define PIF_CTLFLOW_STATE_ingress_flow_record_flow2 10
#define PIF_CTLFLOW_STATE_ingress_flow_nor_tbl 11

/* Control state nodes for egress_flow */
#define PIF_CTLFLOW_STATE_egress_flow_DONE -1
#define PIF_CTLFLOW_STATE_egress_flow_exit_control_flow -1
#define PIF_CTLFLOW_STATE_egress_flow 0

#define PIF_CTLFLOW_STATE_egress_flow__condition_8 0
#define PIF_CTLFLOW_STATE_egress_flow__condition_9 1
#define PIF_CTLFLOW_STATE_egress_flow_t_do_frecirculate 2
#define PIF_CTLFLOW_STATE_egress_flow__condition_7 3
#define PIF_CTLFLOW_STATE_egress_flow_t_do_recirculate 4
#define PIF_CTLFLOW_STATE_egress_flow__condition_6 5

/* Unified control state numbers */
#define PIF_CTLFLOW_STATE_record_flow1 0
#define PIF_CTLFLOW_STATE__condition_4 1
#define PIF_CTLFLOW_STATE__condition_2 2
#define PIF_CTLFLOW_STATE__condition_3 3
#define PIF_CTLFLOW_STATE__condition_1 4
#define PIF_CTLFLOW_STATE_in_tbl2 5
#define PIF_CTLFLOW_STATE_no_record_flow1 6
#define PIF_CTLFLOW_STATE__condition_0 7
#define PIF_CTLFLOW_STATE__condition_5 8
#define PIF_CTLFLOW_STATE_no_record_flow2 9
#define PIF_CTLFLOW_STATE_record_flow2 10
#define PIF_CTLFLOW_STATE_nor_tbl 11
#define PIF_CTLFLOW_STATE__condition_8 12
#define PIF_CTLFLOW_STATE__condition_9 13
#define PIF_CTLFLOW_STATE_t_do_frecirculate 14
#define PIF_CTLFLOW_STATE__condition_7 15
#define PIF_CTLFLOW_STATE_t_do_recirculate 16
#define PIF_CTLFLOW_STATE__condition_6 17

/* Control flow entry points  */
int pif_ctlflow_ingress_flow(int *start_state, __lmem uint32_t *_pif_parrep, __mem __addr40 uint32_t *actbuf, unsigned int actbuf_off);
int pif_ctlflow_egress_flow(int *start_state, __lmem uint32_t *_pif_parrep, __mem __addr40 uint32_t *actbuf, unsigned int actbuf_off);

#endif /* __PIF_CTLFLOW_H__ */
