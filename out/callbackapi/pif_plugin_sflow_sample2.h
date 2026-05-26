/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_SFLOW_SAMPLE2_H__
#define __PIF_PLUGIN_SFLOW_SAMPLE2_H__

/* This file is generated, edit at your peril */

/*
 * Header type definition
 */

/* sflow_sample2 (40B) */
struct pif_plugin_sflow_sample2 {
    unsigned int sample_type:32;
    unsigned int sample_length:32;
    unsigned int in_port:16;
    unsigned int out_port:16;
    unsigned int sample_rate:32;
    unsigned int eth_type:32;
    unsigned int frame_length:16;
    unsigned int protocol:16;
    unsigned int srcIP:32;
    unsigned int dstIP:32;
    unsigned int ip_flag:16;
    unsigned int tcp_flag:16;
    unsigned int srcPort:16;
    unsigned int dstPort:16;
};

/* sflow_sample2 field accessor macros */
#define PIF_HEADER_GET_sflow_sample2___sample_type(_hdr_p) (((_hdr_p)->sample_type)) /* sflow_sample2.sample_type [32;0] */

#define PIF_HEADER_SET_sflow_sample2___sample_type(_hdr_p, _val) \
    do { \
        (_hdr_p)->sample_type = (unsigned)(((_val))); \
    } while (0) /* sflow_sample2.sample_type[32;0] */

#define PIF_HEADER_GET_sflow_sample2___sample_length(_hdr_p) (((_hdr_p)->sample_length)) /* sflow_sample2.sample_length [32;0] */

#define PIF_HEADER_SET_sflow_sample2___sample_length(_hdr_p, _val) \
    do { \
        (_hdr_p)->sample_length = (unsigned)(((_val))); \
    } while (0) /* sflow_sample2.sample_length[32;0] */

#define PIF_HEADER_GET_sflow_sample2___in_port(_hdr_p) (((_hdr_p)->in_port)) /* sflow_sample2.in_port [16;0] */

#define PIF_HEADER_SET_sflow_sample2___in_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->in_port = (unsigned)(((_val))); \
    } while (0) /* sflow_sample2.in_port[16;0] */

#define PIF_HEADER_GET_sflow_sample2___out_port(_hdr_p) (((_hdr_p)->out_port)) /* sflow_sample2.out_port [16;0] */

#define PIF_HEADER_SET_sflow_sample2___out_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->out_port = (unsigned)(((_val))); \
    } while (0) /* sflow_sample2.out_port[16;0] */

#define PIF_HEADER_GET_sflow_sample2___sample_rate(_hdr_p) (((_hdr_p)->sample_rate)) /* sflow_sample2.sample_rate [32;0] */

#define PIF_HEADER_SET_sflow_sample2___sample_rate(_hdr_p, _val) \
    do { \
        (_hdr_p)->sample_rate = (unsigned)(((_val))); \
    } while (0) /* sflow_sample2.sample_rate[32;0] */

#define PIF_HEADER_GET_sflow_sample2___eth_type(_hdr_p) (((_hdr_p)->eth_type)) /* sflow_sample2.eth_type [32;0] */

#define PIF_HEADER_SET_sflow_sample2___eth_type(_hdr_p, _val) \
    do { \
        (_hdr_p)->eth_type = (unsigned)(((_val))); \
    } while (0) /* sflow_sample2.eth_type[32;0] */

#define PIF_HEADER_GET_sflow_sample2___frame_length(_hdr_p) (((_hdr_p)->frame_length)) /* sflow_sample2.frame_length [16;0] */

#define PIF_HEADER_SET_sflow_sample2___frame_length(_hdr_p, _val) \
    do { \
        (_hdr_p)->frame_length = (unsigned)(((_val))); \
    } while (0) /* sflow_sample2.frame_length[16;0] */

#define PIF_HEADER_GET_sflow_sample2___protocol(_hdr_p) (((_hdr_p)->protocol)) /* sflow_sample2.protocol [16;0] */

#define PIF_HEADER_SET_sflow_sample2___protocol(_hdr_p, _val) \
    do { \
        (_hdr_p)->protocol = (unsigned)(((_val))); \
    } while (0) /* sflow_sample2.protocol[16;0] */

#define PIF_HEADER_GET_sflow_sample2___srcIP(_hdr_p) (((_hdr_p)->srcIP)) /* sflow_sample2.srcIP [32;0] */

#define PIF_HEADER_SET_sflow_sample2___srcIP(_hdr_p, _val) \
    do { \
        (_hdr_p)->srcIP = (unsigned)(((_val))); \
    } while (0) /* sflow_sample2.srcIP[32;0] */

#define PIF_HEADER_GET_sflow_sample2___dstIP(_hdr_p) (((_hdr_p)->dstIP)) /* sflow_sample2.dstIP [32;0] */

#define PIF_HEADER_SET_sflow_sample2___dstIP(_hdr_p, _val) \
    do { \
        (_hdr_p)->dstIP = (unsigned)(((_val))); \
    } while (0) /* sflow_sample2.dstIP[32;0] */

#define PIF_HEADER_GET_sflow_sample2___ip_flag(_hdr_p) (((_hdr_p)->ip_flag)) /* sflow_sample2.ip_flag [16;0] */

#define PIF_HEADER_SET_sflow_sample2___ip_flag(_hdr_p, _val) \
    do { \
        (_hdr_p)->ip_flag = (unsigned)(((_val))); \
    } while (0) /* sflow_sample2.ip_flag[16;0] */

#define PIF_HEADER_GET_sflow_sample2___tcp_flag(_hdr_p) (((_hdr_p)->tcp_flag)) /* sflow_sample2.tcp_flag [16;0] */

#define PIF_HEADER_SET_sflow_sample2___tcp_flag(_hdr_p, _val) \
    do { \
        (_hdr_p)->tcp_flag = (unsigned)(((_val))); \
    } while (0) /* sflow_sample2.tcp_flag[16;0] */

#define PIF_HEADER_GET_sflow_sample2___srcPort(_hdr_p) (((_hdr_p)->srcPort)) /* sflow_sample2.srcPort [16;0] */

#define PIF_HEADER_SET_sflow_sample2___srcPort(_hdr_p, _val) \
    do { \
        (_hdr_p)->srcPort = (unsigned)(((_val))); \
    } while (0) /* sflow_sample2.srcPort[16;0] */

#define PIF_HEADER_GET_sflow_sample2___dstPort(_hdr_p) (((_hdr_p)->dstPort)) /* sflow_sample2.dstPort [16;0] */

#define PIF_HEADER_SET_sflow_sample2___dstPort(_hdr_p, _val) \
    do { \
        (_hdr_p)->dstPort = (unsigned)(((_val))); \
    } while (0) /* sflow_sample2.dstPort[16;0] */



#define PIF_PLUGIN_sflow_sample2_T __lmem struct pif_plugin_sflow_sample2

/*
 * Access function prototypes
 */

int pif_plugin_hdr_sflow_sample2_present(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_sflow_sample2_T *pif_plugin_hdr_get_sflow_sample2(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_sflow_sample2_T *pif_plugin_hdr_readonly_get_sflow_sample2(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_sflow_sample2_add(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_sflow_sample2_remove(EXTRACTED_HEADERS_T *extracted_headers);






/*
 * Access function implementations
 */

#include "pif_parrep.h"

__forceinline int pif_plugin_hdr_sflow_sample2_present(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return PIF_PARREP_sflow_sample2_VALID(_ctl);
}

__forceinline PIF_PLUGIN_sflow_sample2_T *pif_plugin_hdr_get_sflow_sample2(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    PIF_PARREP_SET_sflow_sample2_DIRTY(_ctl);
    return (PIF_PLUGIN_sflow_sample2_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_sflow_sample2_OFF_LW);
}

__forceinline PIF_PLUGIN_sflow_sample2_T *pif_plugin_hdr_readonly_get_sflow_sample2(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return (PIF_PLUGIN_sflow_sample2_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_sflow_sample2_OFF_LW);
}

__forceinline int pif_plugin_hdr_sflow_sample2_add(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not addable in the P4 design */
}

__forceinline int pif_plugin_hdr_sflow_sample2_remove(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    if (!PIF_PARREP_sflow_sample2_VALID(_ctl))
        return -1; /* header is not present */
    PIF_PARREP_CLEAR_sflow_sample2_VALID(_ctl);
    return 0;
}

#endif /* __PIF_PLUGIN_SFLOW_SAMPLE2_H__ */
