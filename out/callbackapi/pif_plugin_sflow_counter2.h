/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_SFLOW_COUNTER2_H__
#define __PIF_PLUGIN_SFLOW_COUNTER2_H__

/* This file is generated, edit at your peril */

/*
 * Header type definition
 */

/* sflow_counter2 (176B) */
struct pif_plugin_sflow_counter2 {
    unsigned int sample_type:32;
    unsigned int sample_length:32;
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

/* sflow_counter2 field accessor macros */
#define PIF_HEADER_GET_sflow_counter2___sample_type(_hdr_p) (((_hdr_p)->sample_type)) /* sflow_counter2.sample_type [32;0] */

#define PIF_HEADER_SET_sflow_counter2___sample_type(_hdr_p, _val) \
    do { \
        (_hdr_p)->sample_type = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.sample_type[32;0] */

#define PIF_HEADER_GET_sflow_counter2___sample_length(_hdr_p) (((_hdr_p)->sample_length)) /* sflow_counter2.sample_length [32;0] */

#define PIF_HEADER_SET_sflow_counter2___sample_length(_hdr_p, _val) \
    do { \
        (_hdr_p)->sample_length = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.sample_length[32;0] */

#define PIF_HEADER_GET_sflow_counter2___seqnum(_hdr_p) (((_hdr_p)->seqnum)) /* sflow_counter2.seqnum [32;0] */

#define PIF_HEADER_SET_sflow_counter2___seqnum(_hdr_p, _val) \
    do { \
        (_hdr_p)->seqnum = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.seqnum[32;0] */

#define PIF_HEADER_GET_sflow_counter2___id_index(_hdr_p) (((_hdr_p)->id_index)) /* sflow_counter2.id_index [32;0] */

#define PIF_HEADER_SET_sflow_counter2___id_index(_hdr_p, _val) \
    do { \
        (_hdr_p)->id_index = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.id_index[32;0] */

#define PIF_HEADER_GET_sflow_counter2___counter_records(_hdr_p) (((_hdr_p)->counter_records)) /* sflow_counter2.counter_records [32;0] */

#define PIF_HEADER_SET_sflow_counter2___counter_records(_hdr_p, _val) \
    do { \
        (_hdr_p)->counter_records = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.counter_records[32;0] */

#define PIF_HEADER_GET_sflow_counter2___eth_foramt(_hdr_p) (((_hdr_p)->eth_foramt)) /* sflow_counter2.eth_foramt [32;0] */

#define PIF_HEADER_SET_sflow_counter2___eth_foramt(_hdr_p, _val) \
    do { \
        (_hdr_p)->eth_foramt = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.eth_foramt[32;0] */

#define PIF_HEADER_GET_sflow_counter2___eth_data_len(_hdr_p) (((_hdr_p)->eth_data_len)) /* sflow_counter2.eth_data_len [32;0] */

#define PIF_HEADER_SET_sflow_counter2___eth_data_len(_hdr_p, _val) \
    do { \
        (_hdr_p)->eth_data_len = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.eth_data_len[32;0] */

#define PIF_HEADER_GET_sflow_counter2___alig_err(_hdr_p) (((_hdr_p)->alig_err)) /* sflow_counter2.alig_err [32;0] */

#define PIF_HEADER_SET_sflow_counter2___alig_err(_hdr_p, _val) \
    do { \
        (_hdr_p)->alig_err = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.alig_err[32;0] */

#define PIF_HEADER_GET_sflow_counter2___fcs_err(_hdr_p) (((_hdr_p)->fcs_err)) /* sflow_counter2.fcs_err [32;0] */

#define PIF_HEADER_SET_sflow_counter2___fcs_err(_hdr_p, _val) \
    do { \
        (_hdr_p)->fcs_err = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.fcs_err[32;0] */

#define PIF_HEADER_GET_sflow_counter2___single_collision(_hdr_p) (((_hdr_p)->single_collision)) /* sflow_counter2.single_collision [32;0] */

#define PIF_HEADER_SET_sflow_counter2___single_collision(_hdr_p, _val) \
    do { \
        (_hdr_p)->single_collision = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.single_collision[32;0] */

#define PIF_HEADER_GET_sflow_counter2___multi_collision(_hdr_p) (((_hdr_p)->multi_collision)) /* sflow_counter2.multi_collision [32;0] */

#define PIF_HEADER_SET_sflow_counter2___multi_collision(_hdr_p, _val) \
    do { \
        (_hdr_p)->multi_collision = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.multi_collision[32;0] */

#define PIF_HEADER_GET_sflow_counter2___sqe_err(_hdr_p) (((_hdr_p)->sqe_err)) /* sflow_counter2.sqe_err [32;0] */

#define PIF_HEADER_SET_sflow_counter2___sqe_err(_hdr_p, _val) \
    do { \
        (_hdr_p)->sqe_err = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.sqe_err[32;0] */

#define PIF_HEADER_GET_sflow_counter2___deffered(_hdr_p) (((_hdr_p)->deffered)) /* sflow_counter2.deffered [32;0] */

#define PIF_HEADER_SET_sflow_counter2___deffered(_hdr_p, _val) \
    do { \
        (_hdr_p)->deffered = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.deffered[32;0] */

#define PIF_HEADER_GET_sflow_counter2___late_collision(_hdr_p) (((_hdr_p)->late_collision)) /* sflow_counter2.late_collision [32;0] */

#define PIF_HEADER_SET_sflow_counter2___late_collision(_hdr_p, _val) \
    do { \
        (_hdr_p)->late_collision = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.late_collision[32;0] */

#define PIF_HEADER_GET_sflow_counter2___excessive_collision(_hdr_p) (((_hdr_p)->excessive_collision)) /* sflow_counter2.excessive_collision [32;0] */

#define PIF_HEADER_SET_sflow_counter2___excessive_collision(_hdr_p, _val) \
    do { \
        (_hdr_p)->excessive_collision = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.excessive_collision[32;0] */

#define PIF_HEADER_GET_sflow_counter2___imt_err(_hdr_p) (((_hdr_p)->imt_err)) /* sflow_counter2.imt_err [32;0] */

#define PIF_HEADER_SET_sflow_counter2___imt_err(_hdr_p, _val) \
    do { \
        (_hdr_p)->imt_err = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.imt_err[32;0] */

#define PIF_HEADER_GET_sflow_counter2___carrier_err(_hdr_p) (((_hdr_p)->carrier_err)) /* sflow_counter2.carrier_err [32;0] */

#define PIF_HEADER_SET_sflow_counter2___carrier_err(_hdr_p, _val) \
    do { \
        (_hdr_p)->carrier_err = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.carrier_err[32;0] */

#define PIF_HEADER_GET_sflow_counter2___frame_err(_hdr_p) (((_hdr_p)->frame_err)) /* sflow_counter2.frame_err [32;0] */

#define PIF_HEADER_SET_sflow_counter2___frame_err(_hdr_p, _val) \
    do { \
        (_hdr_p)->frame_err = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.frame_err[32;0] */

#define PIF_HEADER_GET_sflow_counter2___imr_err(_hdr_p) (((_hdr_p)->imr_err)) /* sflow_counter2.imr_err [32;0] */

#define PIF_HEADER_SET_sflow_counter2___imr_err(_hdr_p, _val) \
    do { \
        (_hdr_p)->imr_err = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.imr_err[32;0] */

#define PIF_HEADER_GET_sflow_counter2___symbol_err(_hdr_p) (((_hdr_p)->symbol_err)) /* sflow_counter2.symbol_err [32;0] */

#define PIF_HEADER_SET_sflow_counter2___symbol_err(_hdr_p, _val) \
    do { \
        (_hdr_p)->symbol_err = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.symbol_err[32;0] */

#define PIF_HEADER_GET_sflow_counter2___g_format(_hdr_p) (((_hdr_p)->g_format)) /* sflow_counter2.g_format [32;0] */

#define PIF_HEADER_SET_sflow_counter2___g_format(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_format = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_format[32;0] */

#define PIF_HEADER_GET_sflow_counter2___g_data_len(_hdr_p) (((_hdr_p)->g_data_len)) /* sflow_counter2.g_data_len [32;0] */

#define PIF_HEADER_SET_sflow_counter2___g_data_len(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_data_len = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_data_len[32;0] */

#define PIF_HEADER_GET_sflow_counter2___g_if(_hdr_p) (((_hdr_p)->g_if)) /* sflow_counter2.g_if [32;0] */

#define PIF_HEADER_SET_sflow_counter2___g_if(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_if = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_if[32;0] */

#define PIF_HEADER_GET_sflow_counter2___g_type(_hdr_p) (((_hdr_p)->g_type)) /* sflow_counter2.g_type [32;0] */

#define PIF_HEADER_SET_sflow_counter2___g_type(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_type = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_type[32;0] */

#define PIF_HEADER_GET_sflow_counter2___g_speed___0(_hdr_p) (((_hdr_p)->__g_speed_1)) /* sflow_counter2.g_speed [32;0] */

#define PIF_HEADER_SET_sflow_counter2___g_speed___0(_hdr_p, _val) \
    do { \
        (_hdr_p)->__g_speed_1 = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_speed[32;0] */

#define PIF_HEADER_GET_sflow_counter2___g_speed___1(_hdr_p) (((_hdr_p)->g_speed)) /* sflow_counter2.g_speed [32;32] */

#define PIF_HEADER_SET_sflow_counter2___g_speed___1(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_speed = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_speed[32;32] */

#define PIF_HEADER_GET_sflow_counter2___g_if_direction(_hdr_p) (((_hdr_p)->g_if_direction)) /* sflow_counter2.g_if_direction [32;0] */

#define PIF_HEADER_SET_sflow_counter2___g_if_direction(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_if_direction = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_if_direction[32;0] */

#define PIF_HEADER_GET_sflow_counter2___g_if_status(_hdr_p) (((_hdr_p)->g_if_status)) /* sflow_counter2.g_if_status [32;0] */

#define PIF_HEADER_SET_sflow_counter2___g_if_status(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_if_status = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_if_status[32;0] */

#define PIF_HEADER_GET_sflow_counter2___g_in_octets___0(_hdr_p) (((_hdr_p)->__g_in_octets_1)) /* sflow_counter2.g_in_octets [32;0] */

#define PIF_HEADER_SET_sflow_counter2___g_in_octets___0(_hdr_p, _val) \
    do { \
        (_hdr_p)->__g_in_octets_1 = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_in_octets[32;0] */

#define PIF_HEADER_GET_sflow_counter2___g_in_octets___1(_hdr_p) (((_hdr_p)->g_in_octets)) /* sflow_counter2.g_in_octets [32;32] */

#define PIF_HEADER_SET_sflow_counter2___g_in_octets___1(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_in_octets = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_in_octets[32;32] */

#define PIF_HEADER_GET_sflow_counter2___g_in_pkts(_hdr_p) (((_hdr_p)->g_in_pkts)) /* sflow_counter2.g_in_pkts [32;0] */

#define PIF_HEADER_SET_sflow_counter2___g_in_pkts(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_in_pkts = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_in_pkts[32;0] */

#define PIF_HEADER_GET_sflow_counter2___g_in_multicast_pkts(_hdr_p) (((_hdr_p)->g_in_multicast_pkts)) /* sflow_counter2.g_in_multicast_pkts [32;0] */

#define PIF_HEADER_SET_sflow_counter2___g_in_multicast_pkts(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_in_multicast_pkts = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_in_multicast_pkts[32;0] */

#define PIF_HEADER_GET_sflow_counter2___g_in_broadcast_pkts(_hdr_p) (((_hdr_p)->g_in_broadcast_pkts)) /* sflow_counter2.g_in_broadcast_pkts [32;0] */

#define PIF_HEADER_SET_sflow_counter2___g_in_broadcast_pkts(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_in_broadcast_pkts = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_in_broadcast_pkts[32;0] */

#define PIF_HEADER_GET_sflow_counter2___g_in_discards(_hdr_p) (((_hdr_p)->g_in_discards)) /* sflow_counter2.g_in_discards [32;0] */

#define PIF_HEADER_SET_sflow_counter2___g_in_discards(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_in_discards = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_in_discards[32;0] */

#define PIF_HEADER_GET_sflow_counter2___g_in_errors(_hdr_p) (((_hdr_p)->g_in_errors)) /* sflow_counter2.g_in_errors [32;0] */

#define PIF_HEADER_SET_sflow_counter2___g_in_errors(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_in_errors = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_in_errors[32;0] */

#define PIF_HEADER_GET_sflow_counter2___g_in_unknown_protos(_hdr_p) (((_hdr_p)->g_in_unknown_protos)) /* sflow_counter2.g_in_unknown_protos [32;0] */

#define PIF_HEADER_SET_sflow_counter2___g_in_unknown_protos(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_in_unknown_protos = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_in_unknown_protos[32;0] */

#define PIF_HEADER_GET_sflow_counter2___g_out_octets___0(_hdr_p) (((_hdr_p)->__g_out_octets_1)) /* sflow_counter2.g_out_octets [32;0] */

#define PIF_HEADER_SET_sflow_counter2___g_out_octets___0(_hdr_p, _val) \
    do { \
        (_hdr_p)->__g_out_octets_1 = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_out_octets[32;0] */

#define PIF_HEADER_GET_sflow_counter2___g_out_octets___1(_hdr_p) (((_hdr_p)->g_out_octets)) /* sflow_counter2.g_out_octets [32;32] */

#define PIF_HEADER_SET_sflow_counter2___g_out_octets___1(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_out_octets = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_out_octets[32;32] */

#define PIF_HEADER_GET_sflow_counter2___g_out_pkts(_hdr_p) (((_hdr_p)->g_out_pkts)) /* sflow_counter2.g_out_pkts [32;0] */

#define PIF_HEADER_SET_sflow_counter2___g_out_pkts(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_out_pkts = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_out_pkts[32;0] */

#define PIF_HEADER_GET_sflow_counter2___g_out_multicast_pkts(_hdr_p) (((_hdr_p)->g_out_multicast_pkts)) /* sflow_counter2.g_out_multicast_pkts [32;0] */

#define PIF_HEADER_SET_sflow_counter2___g_out_multicast_pkts(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_out_multicast_pkts = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_out_multicast_pkts[32;0] */

#define PIF_HEADER_GET_sflow_counter2___g_out_broadcast_pkts(_hdr_p) (((_hdr_p)->g_out_broadcast_pkts)) /* sflow_counter2.g_out_broadcast_pkts [32;0] */

#define PIF_HEADER_SET_sflow_counter2___g_out_broadcast_pkts(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_out_broadcast_pkts = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_out_broadcast_pkts[32;0] */

#define PIF_HEADER_GET_sflow_counter2___g_out_discards(_hdr_p) (((_hdr_p)->g_out_discards)) /* sflow_counter2.g_out_discards [32;0] */

#define PIF_HEADER_SET_sflow_counter2___g_out_discards(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_out_discards = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_out_discards[32;0] */

#define PIF_HEADER_GET_sflow_counter2___g_out_errors(_hdr_p) (((_hdr_p)->g_out_errors)) /* sflow_counter2.g_out_errors [32;0] */

#define PIF_HEADER_SET_sflow_counter2___g_out_errors(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_out_errors = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_out_errors[32;0] */

#define PIF_HEADER_GET_sflow_counter2___g_promiscuous_mode(_hdr_p) (((_hdr_p)->g_promiscuous_mode)) /* sflow_counter2.g_promiscuous_mode [32;0] */

#define PIF_HEADER_SET_sflow_counter2___g_promiscuous_mode(_hdr_p, _val) \
    do { \
        (_hdr_p)->g_promiscuous_mode = (unsigned)(((_val))); \
    } while (0) /* sflow_counter2.g_promiscuous_mode[32;0] */



#define PIF_PLUGIN_sflow_counter2_T __lmem struct pif_plugin_sflow_counter2

/*
 * Access function prototypes
 */

int pif_plugin_hdr_sflow_counter2_present(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_sflow_counter2_T *pif_plugin_hdr_get_sflow_counter2(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_sflow_counter2_T *pif_plugin_hdr_readonly_get_sflow_counter2(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_sflow_counter2_add(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_sflow_counter2_remove(EXTRACTED_HEADERS_T *extracted_headers);






/*
 * Access function implementations
 */

#include "pif_parrep.h"

__forceinline int pif_plugin_hdr_sflow_counter2_present(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return PIF_PARREP_sflow_counter2_VALID(_ctl);
}

__forceinline PIF_PLUGIN_sflow_counter2_T *pif_plugin_hdr_get_sflow_counter2(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    PIF_PARREP_SET_sflow_counter2_DIRTY(_ctl);
    return (PIF_PLUGIN_sflow_counter2_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_sflow_counter2_OFF_LW);
}

__forceinline PIF_PLUGIN_sflow_counter2_T *pif_plugin_hdr_readonly_get_sflow_counter2(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return (PIF_PLUGIN_sflow_counter2_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_sflow_counter2_OFF_LW);
}

__forceinline int pif_plugin_hdr_sflow_counter2_add(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not addable in the P4 design */
}

__forceinline int pif_plugin_hdr_sflow_counter2_remove(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    if (!PIF_PARREP_sflow_counter2_VALID(_ctl))
        return -1; /* header is not present */
    PIF_PARREP_CLEAR_sflow_counter2_VALID(_ctl);
    return 0;
}

#endif /* __PIF_PLUGIN_SFLOW_COUNTER2_H__ */
