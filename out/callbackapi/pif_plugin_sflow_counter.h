/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_SFLOW_COUNTER_H__
#define __PIF_PLUGIN_SFLOW_COUNTER_H__

/* This file is generated, edit at your peril */

/*
 * Header type definition
 */

/* sflow_counter (168B) */
struct pif_plugin_sflow_counter {
    unsigned int seqnum:32;
    unsigned int id_index:32;
    unsigned int counter_records:32;
    unsigned int eth_foramt:32;
    unsigned int eth_data_len:32;
    unsigned int alig_err:32;
    unsigned int fcs_err:32;
    unsigned int single_collision:32;
    unsigned int multi_collision:32;
    unsigned int sqe_err:32;
    unsigned int deffered:32;
    unsigned int late_collision:32;
    unsigned int excessive_collision:32;
    unsigned int imt_err:32;
    unsigned int carrier_err:32;
    unsigned int frame_err:32;
    unsigned int imr_err:32;
    unsigned int symbol_err:32;
    unsigned int g_format:32;
    unsigned int g_data_len:32;
    unsigned int g_if:32;
    unsigned int g_type:32;
    /* g_speed [32;32] */
    unsigned int g_speed:32;
    /* g_speed [32;0] */
    unsigned int __g_speed_1:32;
    unsigned int g_if_direction:32;
    unsigned int g_if_status:32;
    /* g_in_octets [32;32] */
    unsigned int g_in_octets:32;
    /* g_in_octets [32;0] */
    unsigned int __g_in_octets_1:32;
    unsigned int g_in_pkts:32;
    unsigned int g_in_multicast_pkts:32;
    unsigned int g_in_broadcast_pkts:32;
    unsigned int g_in_discards:32;
    unsigned int g_in_errors:32;
    unsigned int g_in_unknown_protos:32;
    /* g_out_octets [32;32] */
    unsigned int g_out_octets:32;
    /* g_out_octets [32;0] */
    unsigned int __g_out_octets_1:32;
    unsigned int g_out_pkts:32;
    unsigned int g_out_multicast_pkts:32;
    unsigned int g_out_broadcast_pkts:32;
    unsigned int g_out_discards:32;
    unsigned int g_out_errors:32;
    unsigned int g_promiscuous_mode:32;
};

/* sflow_counter field accessor macros */
#define PIF_HEADER_GET_sflow_counter___seqnum(_hdr_p) (((_hdr_p)->seqnum)) /* sflow_counter.seqnum [32;0] */

#define PIF_HEADER_SET_sflow_counter___seqnum(_hdr_p, _val) \
    do { \
        (_hdr_p)->seqnum = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.seqnum[32;0] */

#define PIF_HEADER_GET_sflow_counter___id_index(_hdr_p) (((_hdr_p)->id_index)) /* sflow_counter.id_index [32;0] */

#define PIF_HEADER_SET_sflow_counter___id_index(_hdr_p, _val) \
    do { \
        (_hdr_p)->id_index = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.id_index[32;0] */

#define PIF_HEADER_GET_sflow_counter___counter_records(_hdr_p) (((_hdr_p)->counter_records)) /* sflow_counter.counter_records [32;0] */

#define PIF_HEADER_SET_sflow_counter___counter_records(_hdr_p, _val) \
    do { \
        (_hdr_p)->counter_records = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.counter_records[32;0] */

#define PIF_HEADER_GET_sflow_counter___eth_foramt(_hdr_p) (((_hdr_p)->eth_foramt)) /* sflow_counter.eth_foramt [32;0] */

#define PIF_HEADER_SET_sflow_counter___eth_foramt(_hdr_p, _val) \
    do { \
        (_hdr_p)->eth_foramt = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.eth_foramt[32;0] */

#define PIF_HEADER_GET_sflow_counter___eth_data_len(_hdr_p) (((_hdr_p)->eth_data_len)) /* sflow_counter.eth_data_len [32;0] */

#define PIF_HEADER_SET_sflow_counter___eth_data_len(_hdr_p, _val) \
    do { \
        (_hdr_p)->eth_data_len = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.eth_data_len[32;0] */

#define PIF_HEADER_GET_sflow_counter___alig_err(_hdr_p) (((_hdr_p)->alig_err)) /* sflow_counter.alig_err [32;0] */

#define PIF_HEADER_SET_sflow_counter___alig_err(_hdr_p, _val) \
    do { \
        (_hdr_p)->alig_err = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.alig_err[32;0] */

#define PIF_HEADER_GET_sflow_counter___fcs_err(_hdr_p) (((_hdr_p)->fcs_err)) /* sflow_counter.fcs_err [32;0] */

#define PIF_HEADER_SET_sflow_counter___fcs_err(_hdr_p, _val) \
    do { \
        (_hdr_p)->fcs_err = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.fcs_err[32;0] */

#define PIF_HEADER_GET_sflow_counter___single_collision(_hdr_p) (((_hdr_p)->single_collision)) /* sflow_counter.single_collision [32;0] */

#define PIF_HEADER_SET_sflow_counter___single_collision(_hdr_p, _val) \
    do { \
        (_hdr_p)->single_collision = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.single_collision[32;0] */

#define PIF_HEADER_GET_sflow_counter___multi_collision(_hdr_p) (((_hdr_p)->multi_collision)) /* sflow_counter.multi_collision [32;0] */

#define PIF_HEADER_SET_sflow_counter___multi_collision(_hdr_p, _val) \
    do { \
        (_hdr_p)->multi_collision = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.multi_collision[32;0] */

#define PIF_HEADER_GET_sflow_counter___sqe_err(_hdr_p) (((_hdr_p)->sqe_err)) /* sflow_counter.sqe_err [32;0] */

#define PIF_HEADER_SET_sflow_counter___sqe_err(_hdr_p, _val) \
    do { \
        (_hdr_p)->sqe_err = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.sqe_err[32;0] */

#define PIF_HEADER_GET_sflow_counter___deffered(_hdr_p) (((_hdr_p)->deffered)) /* sflow_counter.deffered [32;0] */

#define PIF_HEADER_SET_sflow_counter___deffered(_hdr_p, _val) \
    do { \
        (_hdr_p)->deffered = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.deffered[32;0] */

#define PIF_HEADER_GET_sflow_counter___late_collision(_hdr_p) (((_hdr_p)->late_collision)) /* sflow_counter.late_collision [32;0] */

#define PIF_HEADER_SET_sflow_counter___late_collision(_hdr_p, _val) \
    do { \
        (_hdr_p)->late_collision = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.late_collision[32;0] */

#define PIF_HEADER_GET_sflow_counter___excessive_collision(_hdr_p) (((_hdr_p)->excessive_collision)) /* sflow_counter.excessive_collision [32;0] */

#define PIF_HEADER_SET_sflow_counter___excessive_collision(_hdr_p, _val) \
    do { \
        (_hdr_p)->excessive_collision = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.excessive_collision[32;0] */

#define PIF_HEADER_GET_sflow_counter___imt_err(_hdr_p) (((_hdr_p)->imt_err)) /* sflow_counter.imt_err [32;0] */

#define PIF_HEADER_SET_sflow_counter___imt_err(_hdr_p, _val) \
    do { \
        (_hdr_p)->imt_err = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.imt_err[32;0] */

#define PIF_HEADER_GET_sflow_counter___carrier_err(_hdr_p) (((_hdr_p)->carrier_err)) /* sflow_counter.carrier_err [32;0] */

#define PIF_HEADER_SET_sflow_counter___carrier_err(_hdr_p, _val) \
    do { \
        (_hdr_p)->carrier_err = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.carrier_err[32;0] */

#define PIF_HEADER_GET_sflow_counter___frame_err(_hdr_p) (((_hdr_p)->frame_err)) /* sflow_counter.frame_err [32;0] */

#define PIF_HEADER_SET_sflow_counter___frame_err(_hdr_p, _val) \
    do { \
        (_hdr_p)->frame_err = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.frame_err[32;0] */

#define PIF_HEADER_GET_sflow_counter___imr_err(_hdr_p) (((_hdr_p)->imr_err)) /* sflow_counter.imr_err [32;0] */

#define PIF_HEADER_SET_sflow_counter___imr_err(_hdr_p, _val) \
    do { \
        (_hdr_p)->imr_err = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.imr_err[32;0] */

#define PIF_HEADER_GET_sflow_counter___symbol_err(_hdr_p) (((_hdr_p)->symbol_err)) /* sflow_counter.symbol_err [32;0] */

#define PIF_HEADER_SET_sflow_counter___symbol_err(_hdr_p, _val) \
    do { \
        (_hdr_p)->symbol_err = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.symbol_err[32;0] */

#define PIF_HEADER_GET_sflow_counter___g_format(_hdr_p) (((_hdr_p)->g_format)) /* sflow_counter.g_format [32;0] */

#define PIF_HEADER_SET_sflow_counter___g_format(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_format = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_format[32;0] */

#define PIF_HEADER_GET_sflow_counter___g_data_len(_hdr_p) (((_hdr_p)->g_data_len)) /* sflow_counter.g_data_len [32;0] */

#define PIF_HEADER_SET_sflow_counter___g_data_len(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_data_len = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_data_len[32;0] */

#define PIF_HEADER_GET_sflow_counter___g_if(_hdr_p) (((_hdr_p)->g_if)) /* sflow_counter.g_if [32;0] */

#define PIF_HEADER_SET_sflow_counter___g_if(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_if = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_if[32;0] */

#define PIF_HEADER_GET_sflow_counter___g_type(_hdr_p) (((_hdr_p)->g_type)) /* sflow_counter.g_type [32;0] */

#define PIF_HEADER_SET_sflow_counter___g_type(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_type = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_type[32;0] */

#define PIF_HEADER_GET_sflow_counter___g_speed___0(_hdr_p) (((_hdr_p)->__g_speed_1)) /* sflow_counter.g_speed [32;0] */

#define PIF_HEADER_SET_sflow_counter___g_speed___0(_hdr_p, _val) \
    do { \
        (_hdr_p)->__g_speed_1 = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_speed[32;0] */

#define PIF_HEADER_GET_sflow_counter___g_speed___1(_hdr_p) (((_hdr_p)->g_speed)) /* sflow_counter.g_speed [32;32] */

#define PIF_HEADER_SET_sflow_counter___g_speed___1(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_speed = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_speed[32;32] */

#define PIF_HEADER_GET_sflow_counter___g_if_direction(_hdr_p) (((_hdr_p)->g_if_direction)) /* sflow_counter.g_if_direction [32;0] */

#define PIF_HEADER_SET_sflow_counter___g_if_direction(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_if_direction = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_if_direction[32;0] */

#define PIF_HEADER_GET_sflow_counter___g_if_status(_hdr_p) (((_hdr_p)->g_if_status)) /* sflow_counter.g_if_status [32;0] */

#define PIF_HEADER_SET_sflow_counter___g_if_status(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_if_status = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_if_status[32;0] */

#define PIF_HEADER_GET_sflow_counter___g_in_octets___0(_hdr_p) (((_hdr_p)->__g_in_octets_1)) /* sflow_counter.g_in_octets [32;0] */

#define PIF_HEADER_SET_sflow_counter___g_in_octets___0(_hdr_p, _val) \
    do { \
        (_hdr_p)->__g_in_octets_1 = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_in_octets[32;0] */

#define PIF_HEADER_GET_sflow_counter___g_in_octets___1(_hdr_p) (((_hdr_p)->g_in_octets)) /* sflow_counter.g_in_octets [32;32] */

#define PIF_HEADER_SET_sflow_counter___g_in_octets___1(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_in_octets = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_in_octets[32;32] */

#define PIF_HEADER_GET_sflow_counter___g_in_pkts(_hdr_p) (((_hdr_p)->g_in_pkts)) /* sflow_counter.g_in_pkts [32;0] */

#define PIF_HEADER_SET_sflow_counter___g_in_pkts(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_in_pkts = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_in_pkts[32;0] */

#define PIF_HEADER_GET_sflow_counter___g_in_multicast_pkts(_hdr_p) (((_hdr_p)->g_in_multicast_pkts)) /* sflow_counter.g_in_multicast_pkts [32;0] */

#define PIF_HEADER_SET_sflow_counter___g_in_multicast_pkts(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_in_multicast_pkts = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_in_multicast_pkts[32;0] */

#define PIF_HEADER_GET_sflow_counter___g_in_broadcast_pkts(_hdr_p) (((_hdr_p)->g_in_broadcast_pkts)) /* sflow_counter.g_in_broadcast_pkts [32;0] */

#define PIF_HEADER_SET_sflow_counter___g_in_broadcast_pkts(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_in_broadcast_pkts = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_in_broadcast_pkts[32;0] */

#define PIF_HEADER_GET_sflow_counter___g_in_discards(_hdr_p) (((_hdr_p)->g_in_discards)) /* sflow_counter.g_in_discards [32;0] */

#define PIF_HEADER_SET_sflow_counter___g_in_discards(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_in_discards = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_in_discards[32;0] */

#define PIF_HEADER_GET_sflow_counter___g_in_errors(_hdr_p) (((_hdr_p)->g_in_errors)) /* sflow_counter.g_in_errors [32;0] */

#define PIF_HEADER_SET_sflow_counter___g_in_errors(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_in_errors = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_in_errors[32;0] */

#define PIF_HEADER_GET_sflow_counter___g_in_unknown_protos(_hdr_p) (((_hdr_p)->g_in_unknown_protos)) /* sflow_counter.g_in_unknown_protos [32;0] */

#define PIF_HEADER_SET_sflow_counter___g_in_unknown_protos(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_in_unknown_protos = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_in_unknown_protos[32;0] */

#define PIF_HEADER_GET_sflow_counter___g_out_octets___0(_hdr_p) (((_hdr_p)->__g_out_octets_1)) /* sflow_counter.g_out_octets [32;0] */

#define PIF_HEADER_SET_sflow_counter___g_out_octets___0(_hdr_p, _val) \
    do { \
        (_hdr_p)->__g_out_octets_1 = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_out_octets[32;0] */

#define PIF_HEADER_GET_sflow_counter___g_out_octets___1(_hdr_p) (((_hdr_p)->g_out_octets)) /* sflow_counter.g_out_octets [32;32] */

#define PIF_HEADER_SET_sflow_counter___g_out_octets___1(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_out_octets = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_out_octets[32;32] */

#define PIF_HEADER_GET_sflow_counter___g_out_pkts(_hdr_p) (((_hdr_p)->g_out_pkts)) /* sflow_counter.g_out_pkts [32;0] */

#define PIF_HEADER_SET_sflow_counter___g_out_pkts(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_out_pkts = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_out_pkts[32;0] */

#define PIF_HEADER_GET_sflow_counter___g_out_multicast_pkts(_hdr_p) (((_hdr_p)->g_out_multicast_pkts)) /* sflow_counter.g_out_multicast_pkts [32;0] */

#define PIF_HEADER_SET_sflow_counter___g_out_multicast_pkts(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_out_multicast_pkts = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_out_multicast_pkts[32;0] */

#define PIF_HEADER_GET_sflow_counter___g_out_broadcast_pkts(_hdr_p) (((_hdr_p)->g_out_broadcast_pkts)) /* sflow_counter.g_out_broadcast_pkts [32;0] */

#define PIF_HEADER_SET_sflow_counter___g_out_broadcast_pkts(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_out_broadcast_pkts = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_out_broadcast_pkts[32;0] */

#define PIF_HEADER_GET_sflow_counter___g_out_discards(_hdr_p) (((_hdr_p)->g_out_discards)) /* sflow_counter.g_out_discards [32;0] */

#define PIF_HEADER_SET_sflow_counter___g_out_discards(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_out_discards = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_out_discards[32;0] */

#define PIF_HEADER_GET_sflow_counter___g_out_errors(_hdr_p) (((_hdr_p)->g_out_errors)) /* sflow_counter.g_out_errors [32;0] */

#define PIF_HEADER_SET_sflow_counter___g_out_errors(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_out_errors = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_out_errors[32;0] */

#define PIF_HEADER_GET_sflow_counter___g_promiscuous_mode(_hdr_p) (((_hdr_p)->g_promiscuous_mode)) /* sflow_counter.g_promiscuous_mode [32;0] */

#define PIF_HEADER_SET_sflow_counter___g_promiscuous_mode(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_promiscuous_mode = (unsigned)(((_val))); \
    } while (0) /* sflow_counter.g_promiscuous_mode[32;0] */



#define PIF_PLUGIN_sflow_counter_T __lmem struct pif_plugin_sflow_counter

/*
 * Access function prototypes
 */

int pif_plugin_hdr_sflow_counter_present(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_sflow_counter_T *pif_plugin_hdr_get_sflow_counter(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_sflow_counter_T *pif_plugin_hdr_readonly_get_sflow_counter(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_sflow_counter_add(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_sflow_counter_remove(EXTRACTED_HEADERS_T *extracted_headers);






/*
 * Access function implementations
 */

#include "pif_parrep.h"

__forceinline int pif_plugin_hdr_sflow_counter_present(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return PIF_PARREP_sflow_counter_VALID(_ctl);
}

__forceinline PIF_PLUGIN_sflow_counter_T *pif_plugin_hdr_get_sflow_counter(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    PIF_PARREP_SET_sflow_counter_DIRTY(_ctl);
    return (PIF_PLUGIN_sflow_counter_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_sflow_counter_OFF_LW);
}

__forceinline PIF_PLUGIN_sflow_counter_T *pif_plugin_hdr_readonly_get_sflow_counter(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return (PIF_PLUGIN_sflow_counter_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_sflow_counter_OFF_LW);
}

__forceinline int pif_plugin_hdr_sflow_counter_add(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not addable in the P4 design */
}

__forceinline int pif_plugin_hdr_sflow_counter_remove(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    if (!PIF_PARREP_sflow_counter_VALID(_ctl))
        return -1; /* header is not present */
    PIF_PARREP_CLEAR_sflow_counter_VALID(_ctl);
    return 0;
}

#endif /* __PIF_PLUGIN_SFLOW_COUNTER_H__ */
