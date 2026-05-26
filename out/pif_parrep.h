/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PARREP_H__
#define __PIF_PARREP_H__

/* Generated C source defining layout of parsed representation */
/* Warning: your edits to this file may be lost */

/*
 * Parsed representation control data
 */
struct pif_parrep_ctldata {
    unsigned int valid:1;
    unsigned int t0_valid:1;
    unsigned int t0_dirty:1;
    unsigned int t0_orig_len:1;
    unsigned int t1_valid:1;
    unsigned int t1_dirty:1;
    unsigned int t1_orig_len:1;
    unsigned int t2_valid:1;
    unsigned int t2_dirty:1;
    unsigned int t2_orig_len:1;
    unsigned int t3_valid:1;
    unsigned int t3_dirty:1;
    unsigned int t3_orig_len:1;
    unsigned int t4_valid:1;
    unsigned int t4_dirty:1;
    unsigned int t4_orig_len:1;
    unsigned int t5_valid:1;
    unsigned int t5_type:1;
    unsigned int t5_dirty:1;
    unsigned int t5_orig_len:8;
    unsigned int _padding_0:5;
    unsigned int t6_valid:1;
    unsigned int t6_type:1;
    unsigned int t6_dirty:1;
    unsigned int t6_orig_len:8;
};

#define PIF_PARREP_CTLDATA_OFF_LW 0
#define PIF_PARREP_CTLDATA_LEN_LW 2

/*
 * Parsed representation layout
 */

/* Parsed represention tier types */
/* tier 5 */
#define PIF_PARREP_TYPE_sflow_counter 0
#define PIF_PARREP_TYPE_sflow_sample 1
/* tier 6 */
#define PIF_PARREP_TYPE_sflow_counter2 0
#define PIF_PARREP_TYPE_sflow_sample2 1

/* Parse state values */
#define PIF_PARREP_STATE_exit -1
#define PIF_PARREP_STATE__condition_0 (PIF_PARREP_STATE_exit)
#define PIF_PARREP_STATE_eth_parse 1
#define PIF_PARREP_STATE_parse_sflow_counter 6
#define PIF_PARREP_STATE_parse_udp 3
#define PIF_PARREP_STATE_parse_sflow_header 4
#define PIF_PARREP_STATE_parse_sflow_counter_2 8
#define PIF_PARREP_STATE_start 0
#define PIF_PARREP_STATE_parse_sflow_sample_2 9
#define PIF_PARREP_STATE_parse_sflow_sample_header 5
#define PIF_PARREP_STATE_parse_sflow_sample 7
#define PIF_PARREP_STATE_parse_ipv4 2
#define PIF_PARREP_MAX_STATE 9

/* Tier 0 */
#define PIF_PARREP_T0_OFF_LW 2
#define PIF_PARREP_T0_LEN_LW 4
#define PIF_PARREP_eth_OFF_LW (PIF_PARREP_T0_OFF_LW)
#define PIF_PARREP_eth_LEN_LW 4
#define PIF_PARREP_eth_LEN_B 14

/* Tier 1 */
#define PIF_PARREP_T1_OFF_LW 6
#define PIF_PARREP_T1_LEN_LW 5
#define PIF_PARREP_ipv4_OFF_LW (PIF_PARREP_T1_OFF_LW)
#define PIF_PARREP_ipv4_LEN_LW 5
#define PIF_PARREP_ipv4_LEN_B 20

/* Tier 2 */
#define PIF_PARREP_T2_OFF_LW 11
#define PIF_PARREP_T2_LEN_LW 2
#define PIF_PARREP_udp_OFF_LW (PIF_PARREP_T2_OFF_LW)
#define PIF_PARREP_udp_LEN_LW 2
#define PIF_PARREP_udp_LEN_B 8

/* Tier 3 */
#define PIF_PARREP_T3_OFF_LW 13
#define PIF_PARREP_T3_LEN_LW 7
#define PIF_PARREP_sflow_header_OFF_LW (PIF_PARREP_T3_OFF_LW)
#define PIF_PARREP_sflow_header_LEN_LW 7
#define PIF_PARREP_sflow_header_LEN_B 28

/* Tier 4 */
#define PIF_PARREP_T4_OFF_LW 20
#define PIF_PARREP_T4_LEN_LW 2
#define PIF_PARREP_sflow_sample_header_OFF_LW (PIF_PARREP_T4_OFF_LW)
#define PIF_PARREP_sflow_sample_header_LEN_LW 2
#define PIF_PARREP_sflow_sample_header_LEN_B 8

/* Tier 5 */
#define PIF_PARREP_T5_OFF_LW 22
#define PIF_PARREP_T5_LEN_LW 42
#define PIF_PARREP_sflow_counter_OFF_LW (PIF_PARREP_T5_OFF_LW)
#define PIF_PARREP_sflow_counter_LEN_LW 42
#define PIF_PARREP_sflow_counter_LEN_B 168
#define PIF_PARREP_sflow_sample_OFF_LW (PIF_PARREP_T5_OFF_LW)
#define PIF_PARREP_sflow_sample_LEN_LW 8
#define PIF_PARREP_sflow_sample_LEN_B 32

/* Tier 6 */
#define PIF_PARREP_T6_OFF_LW 64
#define PIF_PARREP_T6_LEN_LW 44
#define PIF_PARREP_sflow_counter2_OFF_LW (PIF_PARREP_T6_OFF_LW)
#define PIF_PARREP_sflow_counter2_LEN_LW 44
#define PIF_PARREP_sflow_counter2_LEN_B 176
#define PIF_PARREP_sflow_sample2_OFF_LW (PIF_PARREP_T6_OFF_LW)
#define PIF_PARREP_sflow_sample2_LEN_LW 10
#define PIF_PARREP_sflow_sample2_LEN_B 40

/*
 * Metadata
 */

#define PIF_PARREP_standard_metadata_OFF_LW 108
#define PIF_PARREP_standard_metadata_LEN_LW 4

#define PIF_PARREP_num_metadata_OFF_LW 112
#define PIF_PARREP_num_metadata_LEN_LW 1

#define PIF_PARREP_recirculate_fl_OFF_LW 113
#define PIF_PARREP_recirculate_fl_LEN_LW 1

#define PIF_PARREP_LEN_LW 114

/* Parsing branches to a constant control entry point */
#define PIF_PARREP_NO_VARIABLE_EXIT

/* Control data macros */
#define PIF_PARREP_VALID(_ctl) (_ctl->valid)
#define PIF_PARREP_SET_VALID(_ctl) \
    do { _ctl->valid = 1; } while (0)

/* Tier 0 */
#define PIF_PARREP_T0_TYPE(ctl) ( ((ctl)->t0_type))
#define PIF_PARREP_T0_VALID(ctl) ( ((ctl)->t0_valid))
#define PIF_PARREP_eth_VALID(ctl) ( ((ctl)->t0_valid) )
#define PIF_PARREP_SET_eth_VALID(ctl) \
    do { \
        (ctl)->t0_valid = 1; \
    } while(0);
#define PIF_PARREP_CLEAR_eth_VALID(ctl) \
    do { \
        (ctl)->t0_valid = 0; \
    } while(0);

#define PIF_PARREP_eth_DIRTY(_ctl) ((_ctl)->t0_dirty)
#define PIF_PARREP_T0_DIRTY(_ctl) ((_ctl)->t0_dirty)
#define PIF_PARREP_CLEAR_T0_DIRTY(_ctl)     do { \
        (_ctl)->t0_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T0_DIRTY(_ctl)     do { \
        (_ctl)->t0_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_eth_DIRTY(_ctl) \
    do { \
        (_ctl)->t0_dirty = 1; \
    } while(0);

#define PIF_PARREP_T0_ORIG_LEN(ctl) (((ctl)->t0_orig_len) ? PIF_PARREP_eth_LEN_B : 0)
#define PIF_PARREP_SET_T0_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t0_orig_len = (len == 0 ? 0 : 1); \
    } while(0);
#define PIF_PARREP_eth_ORIG_LEN(ctl) (((ctl)->t0_orig_len) ? PIF_PARREP_eth_LEN_B : 0)
#define PIF_PARREP_CLEAR_eth_ORIG_LEN(ctl) \
    do { \
        (ctl)->t0_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_eth_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t0_orig_len = 1; \
    } while(0);

/* Tier 1 */
#define PIF_PARREP_T1_TYPE(ctl) ( ((ctl)->t1_type))
#define PIF_PARREP_T1_VALID(ctl) ( ((ctl)->t1_valid))
#define PIF_PARREP_ipv4_VALID(ctl) ( ((ctl)->t1_valid) )
#define PIF_PARREP_SET_ipv4_VALID(ctl) \
    do { \
        (ctl)->t1_valid = 1; \
    } while(0);
#define PIF_PARREP_CLEAR_ipv4_VALID(ctl) \
    do { \
        (ctl)->t1_valid = 0; \
    } while(0);

#define PIF_PARREP_ipv4_DIRTY(_ctl) ((_ctl)->t1_dirty)
#define PIF_PARREP_T1_DIRTY(_ctl) ((_ctl)->t1_dirty)
#define PIF_PARREP_CLEAR_T1_DIRTY(_ctl)     do { \
        (_ctl)->t1_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T1_DIRTY(_ctl)     do { \
        (_ctl)->t1_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_ipv4_DIRTY(_ctl) \
    do { \
        (_ctl)->t1_dirty = 1; \
    } while(0);

#define PIF_PARREP_T1_ORIG_LEN(ctl) (((ctl)->t1_orig_len) ? PIF_PARREP_ipv4_LEN_B : 0)
#define PIF_PARREP_SET_T1_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t1_orig_len = (len == 0 ? 0 : 1); \
    } while(0);
#define PIF_PARREP_ipv4_ORIG_LEN(ctl) (((ctl)->t1_orig_len) ? PIF_PARREP_ipv4_LEN_B : 0)
#define PIF_PARREP_CLEAR_ipv4_ORIG_LEN(ctl) \
    do { \
        (ctl)->t1_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_ipv4_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t1_orig_len = 1; \
    } while(0);

/* Tier 2 */
#define PIF_PARREP_T2_TYPE(ctl) ( ((ctl)->t2_type))
#define PIF_PARREP_T2_VALID(ctl) ( ((ctl)->t2_valid))
#define PIF_PARREP_udp_VALID(ctl) ( ((ctl)->t2_valid) )
#define PIF_PARREP_SET_udp_VALID(ctl) \
    do { \
        (ctl)->t2_valid = 1; \
    } while(0);
#define PIF_PARREP_CLEAR_udp_VALID(ctl) \
    do { \
        (ctl)->t2_valid = 0; \
    } while(0);

#define PIF_PARREP_udp_DIRTY(_ctl) ((_ctl)->t2_dirty)
#define PIF_PARREP_T2_DIRTY(_ctl) ((_ctl)->t2_dirty)
#define PIF_PARREP_CLEAR_T2_DIRTY(_ctl)     do { \
        (_ctl)->t2_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T2_DIRTY(_ctl)     do { \
        (_ctl)->t2_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_udp_DIRTY(_ctl) \
    do { \
        (_ctl)->t2_dirty = 1; \
    } while(0);

#define PIF_PARREP_T2_ORIG_LEN(ctl) (((ctl)->t2_orig_len) ? PIF_PARREP_udp_LEN_B : 0)
#define PIF_PARREP_SET_T2_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t2_orig_len = (len == 0 ? 0 : 1); \
    } while(0);
#define PIF_PARREP_udp_ORIG_LEN(ctl) (((ctl)->t2_orig_len) ? PIF_PARREP_udp_LEN_B : 0)
#define PIF_PARREP_CLEAR_udp_ORIG_LEN(ctl) \
    do { \
        (ctl)->t2_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_udp_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t2_orig_len = 1; \
    } while(0);

/* Tier 3 */
#define PIF_PARREP_T3_TYPE(ctl) ( ((ctl)->t3_type))
#define PIF_PARREP_T3_VALID(ctl) ( ((ctl)->t3_valid))
#define PIF_PARREP_sflow_header_VALID(ctl) ( ((ctl)->t3_valid) )
#define PIF_PARREP_SET_sflow_header_VALID(ctl) \
    do { \
        (ctl)->t3_valid = 1; \
    } while(0);
#define PIF_PARREP_CLEAR_sflow_header_VALID(ctl) \
    do { \
        (ctl)->t3_valid = 0; \
    } while(0);

#define PIF_PARREP_sflow_header_DIRTY(_ctl) ((_ctl)->t3_dirty)
#define PIF_PARREP_T3_DIRTY(_ctl) ((_ctl)->t3_dirty)
#define PIF_PARREP_CLEAR_T3_DIRTY(_ctl)     do { \
        (_ctl)->t3_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T3_DIRTY(_ctl)     do { \
        (_ctl)->t3_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_sflow_header_DIRTY(_ctl) \
    do { \
        (_ctl)->t3_dirty = 1; \
    } while(0);

#define PIF_PARREP_T3_ORIG_LEN(ctl) (((ctl)->t3_orig_len) ? PIF_PARREP_sflow_header_LEN_B : 0)
#define PIF_PARREP_SET_T3_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t3_orig_len = (len == 0 ? 0 : 1); \
    } while(0);
#define PIF_PARREP_sflow_header_ORIG_LEN(ctl) (((ctl)->t3_orig_len) ? PIF_PARREP_sflow_header_LEN_B : 0)
#define PIF_PARREP_CLEAR_sflow_header_ORIG_LEN(ctl) \
    do { \
        (ctl)->t3_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_sflow_header_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t3_orig_len = 1; \
    } while(0);

/* Tier 4 */
#define PIF_PARREP_T4_TYPE(ctl) ( ((ctl)->t4_type))
#define PIF_PARREP_T4_VALID(ctl) ( ((ctl)->t4_valid))
#define PIF_PARREP_sflow_sample_header_VALID(ctl) ( ((ctl)->t4_valid) )
#define PIF_PARREP_SET_sflow_sample_header_VALID(ctl) \
    do { \
        (ctl)->t4_valid = 1; \
    } while(0);
#define PIF_PARREP_CLEAR_sflow_sample_header_VALID(ctl) \
    do { \
        (ctl)->t4_valid = 0; \
    } while(0);

#define PIF_PARREP_sflow_sample_header_DIRTY(_ctl) ((_ctl)->t4_dirty)
#define PIF_PARREP_T4_DIRTY(_ctl) ((_ctl)->t4_dirty)
#define PIF_PARREP_CLEAR_T4_DIRTY(_ctl)     do { \
        (_ctl)->t4_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T4_DIRTY(_ctl)     do { \
        (_ctl)->t4_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_sflow_sample_header_DIRTY(_ctl) \
    do { \
        (_ctl)->t4_dirty = 1; \
    } while(0);

#define PIF_PARREP_T4_ORIG_LEN(ctl) (((ctl)->t4_orig_len) ? PIF_PARREP_sflow_sample_header_LEN_B : 0)
#define PIF_PARREP_SET_T4_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t4_orig_len = (len == 0 ? 0 : 1); \
    } while(0);
#define PIF_PARREP_sflow_sample_header_ORIG_LEN(ctl) (((ctl)->t4_orig_len) ? PIF_PARREP_sflow_sample_header_LEN_B : 0)
#define PIF_PARREP_CLEAR_sflow_sample_header_ORIG_LEN(ctl) \
    do { \
        (ctl)->t4_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_sflow_sample_header_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t4_orig_len = 1; \
    } while(0);

/* Tier 5 */
#define PIF_PARREP_T5_TYPE(ctl) ( ((ctl)->t5_type))
#define PIF_PARREP_T5_VALID(ctl) ( ((ctl)->t5_valid & 0x1) )
#define PIF_PARREP_sflow_counter_VALID(ctl) ( ((ctl)->t5_valid & 0x1) && ((ctl)->t5_type == PIF_PARREP_TYPE_sflow_counter) )
#define PIF_PARREP_SET_sflow_counter_VALID(ctl) \
    do { \
        (ctl)->t5_valid = 1; \
        (ctl)->t5_type = PIF_PARREP_TYPE_sflow_counter; \
    } while(0);
#define PIF_PARREP_CLEAR_sflow_counter_VALID(ctl) \
    do { \
        (ctl)->t5_valid = 0; \
    } while(0);
#define PIF_PARREP_sflow_sample_VALID(ctl) ( ((ctl)->t5_valid & 0x1) && ((ctl)->t5_type == PIF_PARREP_TYPE_sflow_sample) )
#define PIF_PARREP_SET_sflow_sample_VALID(ctl) \
    do { \
        (ctl)->t5_valid = 1; \
        (ctl)->t5_type = PIF_PARREP_TYPE_sflow_sample; \
    } while(0);
#define PIF_PARREP_CLEAR_sflow_sample_VALID(ctl) \
    do { \
        (ctl)->t5_valid = 0; \
    } while(0);

#define PIF_PARREP_sflow_counter_DIRTY(_ctl) ((_ctl)->t5_dirty)
#define PIF_PARREP_sflow_sample_DIRTY(_ctl) ((_ctl)->t5_dirty)
#define PIF_PARREP_T5_DIRTY(_ctl) ((_ctl)->t5_dirty)
#define PIF_PARREP_CLEAR_T5_DIRTY(_ctl)     do { \
        (_ctl)->t5_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T5_DIRTY(_ctl)     do { \
        (_ctl)->t5_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_sflow_counter_DIRTY(_ctl) \
    do { \
        (_ctl)->t5_dirty = 1; \
    } while(0);
#define PIF_PARREP_SET_sflow_sample_DIRTY(_ctl) \
    do { \
        (_ctl)->t5_dirty = 1; \
    } while(0);

#define PIF_PARREP_T5_ORIG_LEN(ctl) ((ctl)->t5_orig_len)
#define PIF_PARREP_SET_T5_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t5_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_T5_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t5_orig_len += len; \
    } while(0);
#define PIF_PARREP_sflow_counter_ORIG_LEN(ctl) ((ctl)->t5_orig_len)
#define PIF_PARREP_CLEAR_sflow_counter_ORIG_LEN(ctl) \
    do { \
        (ctl)->t5_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_sflow_counter_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t5_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_sflow_counter_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t5_orig_len += len; \
    } while(0);
#define PIF_PARREP_sflow_sample_ORIG_LEN(ctl) ((ctl)->t5_orig_len)
#define PIF_PARREP_CLEAR_sflow_sample_ORIG_LEN(ctl) \
    do { \
        (ctl)->t5_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_sflow_sample_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t5_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_sflow_sample_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t5_orig_len += len; \
    } while(0);

/* Tier 6 */
#define PIF_PARREP_T6_TYPE(ctl) ( ((ctl)->t6_type))
#define PIF_PARREP_T6_VALID(ctl) ( ((ctl)->t6_valid & 0x1) )
#define PIF_PARREP_sflow_counter2_VALID(ctl) ( ((ctl)->t6_valid & 0x1) && ((ctl)->t6_type == PIF_PARREP_TYPE_sflow_counter2) )
#define PIF_PARREP_SET_sflow_counter2_VALID(ctl) \
    do { \
        (ctl)->t6_valid = 1; \
        (ctl)->t6_type = PIF_PARREP_TYPE_sflow_counter2; \
    } while(0);
#define PIF_PARREP_CLEAR_sflow_counter2_VALID(ctl) \
    do { \
        (ctl)->t6_valid = 0; \
    } while(0);
#define PIF_PARREP_sflow_sample2_VALID(ctl) ( ((ctl)->t6_valid & 0x1) && ((ctl)->t6_type == PIF_PARREP_TYPE_sflow_sample2) )
#define PIF_PARREP_SET_sflow_sample2_VALID(ctl) \
    do { \
        (ctl)->t6_valid = 1; \
        (ctl)->t6_type = PIF_PARREP_TYPE_sflow_sample2; \
    } while(0);
#define PIF_PARREP_CLEAR_sflow_sample2_VALID(ctl) \
    do { \
        (ctl)->t6_valid = 0; \
    } while(0);

#define PIF_PARREP_sflow_counter2_DIRTY(_ctl) ((_ctl)->t6_dirty)
#define PIF_PARREP_sflow_sample2_DIRTY(_ctl) ((_ctl)->t6_dirty)
#define PIF_PARREP_T6_DIRTY(_ctl) ((_ctl)->t6_dirty)
#define PIF_PARREP_CLEAR_T6_DIRTY(_ctl)     do { \
        (_ctl)->t6_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T6_DIRTY(_ctl)     do { \
        (_ctl)->t6_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_sflow_counter2_DIRTY(_ctl) \
    do { \
        (_ctl)->t6_dirty = 1; \
    } while(0);
#define PIF_PARREP_SET_sflow_sample2_DIRTY(_ctl) \
    do { \
        (_ctl)->t6_dirty = 1; \
    } while(0);

#define PIF_PARREP_T6_ORIG_LEN(ctl) ((ctl)->t6_orig_len)
#define PIF_PARREP_SET_T6_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t6_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_T6_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t6_orig_len += len; \
    } while(0);
#define PIF_PARREP_sflow_counter2_ORIG_LEN(ctl) ((ctl)->t6_orig_len)
#define PIF_PARREP_CLEAR_sflow_counter2_ORIG_LEN(ctl) \
    do { \
        (ctl)->t6_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_sflow_counter2_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t6_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_sflow_counter2_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t6_orig_len += len; \
    } while(0);
#define PIF_PARREP_sflow_sample2_ORIG_LEN(ctl) ((ctl)->t6_orig_len)
#define PIF_PARREP_CLEAR_sflow_sample2_ORIG_LEN(ctl) \
    do { \
        (ctl)->t6_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_sflow_sample2_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t6_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_sflow_sample2_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t6_orig_len += len; \
    } while(0);



void pif_value_set_scan_configs();

#endif /* __PIF_PARREP_H__ */
