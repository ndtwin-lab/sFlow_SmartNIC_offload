/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_SFLOW_HEADER_H__
#define __PIF_PLUGIN_SFLOW_HEADER_H__

/* This file is generated, edit at your peril */

/*
 * Header type definition
 */

/* sflow_header (28B) */
struct pif_plugin_sflow_header {
    unsigned int version:32;
    unsigned int agent_type:32;
    unsigned int agent_ip:32;
    unsigned int agent_id:32;
    unsigned int seq_num:32;
    unsigned int uptime:32;
    unsigned int num_samples:32;
};

/* sflow_header field accessor macros */
#define PIF_HEADER_GET_sflow_header___version(_hdr_p) (((_hdr_p)->version)) /* sflow_header.version [32;0] */

#define PIF_HEADER_SET_sflow_header___version(_hdr_p, _val) \
    do { \
        (_hdr_p)->version = (unsigned)(((_val))); \
    } while (0) /* sflow_header.version[32;0] */

#define PIF_HEADER_GET_sflow_header___agent_type(_hdr_p) (((_hdr_p)->agent_type)) /* sflow_header.agent_type [32;0] */

#define PIF_HEADER_SET_sflow_header___agent_type(_hdr_p, _val) \
    do { \
        (_hdr_p)->agent_type = (unsigned)(((_val))); \
    } while (0) /* sflow_header.agent_type[32;0] */

#define PIF_HEADER_GET_sflow_header___agent_ip(_hdr_p) (((_hdr_p)->agent_ip)) /* sflow_header.agent_ip [32;0] */

#define PIF_HEADER_SET_sflow_header___agent_ip(_hdr_p, _val) \
    do { \
        (_hdr_p)->agent_ip = (unsigned)(((_val))); \
    } while (0) /* sflow_header.agent_ip[32;0] */

#define PIF_HEADER_GET_sflow_header___agent_id(_hdr_p) (((_hdr_p)->agent_id)) /* sflow_header.agent_id [32;0] */

#define PIF_HEADER_SET_sflow_header___agent_id(_hdr_p, _val) \
    do { \
        (_hdr_p)->agent_id = (unsigned)(((_val))); \
    } while (0) /* sflow_header.agent_id[32;0] */

#define PIF_HEADER_GET_sflow_header___seq_num(_hdr_p) (((_hdr_p)->seq_num)) /* sflow_header.seq_num [32;0] */

#define PIF_HEADER_SET_sflow_header___seq_num(_hdr_p, _val) \
    do { \
        (_hdr_p)->seq_num = (unsigned)(((_val))); \
    } while (0) /* sflow_header.seq_num[32;0] */

#define PIF_HEADER_GET_sflow_header___uptime(_hdr_p) (((_hdr_p)->uptime)) /* sflow_header.uptime [32;0] */

#define PIF_HEADER_SET_sflow_header___uptime(_hdr_p, _val) \
    do { \
        (_hdr_p)->uptime = (unsigned)(((_val))); \
    } while (0) /* sflow_header.uptime[32;0] */

#define PIF_HEADER_GET_sflow_header___num_samples(_hdr_p) (((_hdr_p)->num_samples)) /* sflow_header.num_samples [32;0] */

#define PIF_HEADER_SET_sflow_header___num_samples(_hdr_p, _val) \
    do { \
        (_hdr_p)->num_samples = (unsigned)(((_val))); \
    } while (0) /* sflow_header.num_samples[32;0] */



#define PIF_PLUGIN_sflow_header_T __lmem struct pif_plugin_sflow_header

/*
 * Access function prototypes
 */

int pif_plugin_hdr_sflow_header_present(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_sflow_header_T *pif_plugin_hdr_get_sflow_header(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_sflow_header_T *pif_plugin_hdr_readonly_get_sflow_header(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_sflow_header_add(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_sflow_header_remove(EXTRACTED_HEADERS_T *extracted_headers);






/*
 * Access function implementations
 */

#include "pif_parrep.h"

__forceinline int pif_plugin_hdr_sflow_header_present(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return PIF_PARREP_sflow_header_VALID(_ctl);
}

__forceinline PIF_PLUGIN_sflow_header_T *pif_plugin_hdr_get_sflow_header(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    PIF_PARREP_SET_sflow_header_DIRTY(_ctl);
    return (PIF_PLUGIN_sflow_header_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_sflow_header_OFF_LW);
}

__forceinline PIF_PLUGIN_sflow_header_T *pif_plugin_hdr_readonly_get_sflow_header(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return (PIF_PLUGIN_sflow_header_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_sflow_header_OFF_LW);
}

__forceinline int pif_plugin_hdr_sflow_header_add(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not addable in the P4 design */
}

__forceinline int pif_plugin_hdr_sflow_header_remove(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not removable in the P4 design */
}

#endif /* __PIF_PLUGIN_SFLOW_HEADER_H__ */
