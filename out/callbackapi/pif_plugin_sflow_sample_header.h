/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_SFLOW_SAMPLE_HEADER_H__
#define __PIF_PLUGIN_SFLOW_SAMPLE_HEADER_H__

/* This file is generated, edit at your peril */

/*
 * Header type definition
 */

/* sflow_sample_header (8B) */
struct pif_plugin_sflow_sample_header {
    unsigned int sample_type:32;
    unsigned int sample_length:32;
};

/* sflow_sample_header field accessor macros */
#define PIF_HEADER_GET_sflow_sample_header___sample_type(_hdr_p) (((_hdr_p)->sample_type)) /* sflow_sample_header.sample_type [32;0] */

#define PIF_HEADER_SET_sflow_sample_header___sample_type(_hdr_p, _val) \
    do { \
        (_hdr_p)->sample_type = (unsigned)(((_val))); \
    } while (0) /* sflow_sample_header.sample_type[32;0] */

#define PIF_HEADER_GET_sflow_sample_header___sample_length(_hdr_p) (((_hdr_p)->sample_length)) /* sflow_sample_header.sample_length [32;0] */

#define PIF_HEADER_SET_sflow_sample_header___sample_length(_hdr_p, _val) \
    do { \
        (_hdr_p)->sample_length = (unsigned)(((_val))); \
    } while (0) /* sflow_sample_header.sample_length[32;0] */



#define PIF_PLUGIN_sflow_sample_header_T __lmem struct pif_plugin_sflow_sample_header

/*
 * Access function prototypes
 */

int pif_plugin_hdr_sflow_sample_header_present(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_sflow_sample_header_T *pif_plugin_hdr_get_sflow_sample_header(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_sflow_sample_header_T *pif_plugin_hdr_readonly_get_sflow_sample_header(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_sflow_sample_header_add(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_sflow_sample_header_remove(EXTRACTED_HEADERS_T *extracted_headers);






/*
 * Access function implementations
 */

#include "pif_parrep.h"

__forceinline int pif_plugin_hdr_sflow_sample_header_present(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return PIF_PARREP_sflow_sample_header_VALID(_ctl);
}

__forceinline PIF_PLUGIN_sflow_sample_header_T *pif_plugin_hdr_get_sflow_sample_header(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    PIF_PARREP_SET_sflow_sample_header_DIRTY(_ctl);
    return (PIF_PLUGIN_sflow_sample_header_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_sflow_sample_header_OFF_LW);
}

__forceinline PIF_PLUGIN_sflow_sample_header_T *pif_plugin_hdr_readonly_get_sflow_sample_header(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return (PIF_PLUGIN_sflow_sample_header_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_sflow_sample_header_OFF_LW);
}

__forceinline int pif_plugin_hdr_sflow_sample_header_add(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not addable in the P4 design */
}

__forceinline int pif_plugin_hdr_sflow_sample_header_remove(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    if (!PIF_PARREP_sflow_sample_header_VALID(_ctl))
        return -1; /* header is not present */
    PIF_PARREP_CLEAR_sflow_sample_header_VALID(_ctl);
    return 0;
}

#endif /* __PIF_PLUGIN_SFLOW_SAMPLE_HEADER_H__ */
