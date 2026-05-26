/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#include <nfp/me.h>
#include <hashmap.h>
#include "pif_common.h"

extern __forceinline
pif_parrep_extract(__lmem uint32_t *_pif_parrep, __mem __addr40 uint8_t *_pif_parrep_pktdata, unsigned int _pif_parrep_pktlen, __lmem uint32_t *_pif_parrep_fk_ptr, __gpr uint32_t *_pif_parrep_fk_len)
{
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
    PIF_PKT_INFO_TYPE struct pif_pkt_info *pkt_info = &pif_pkt_info_global;
    __xread uint32_t _pif_read_xbuf[24];
    unsigned int _pif_read_xbuf_off = 2;
    __gpr unsigned int _pif_parrep_pktoff = -2;
    unsigned int _pif_t_index;
    __gpr int _pif_parrep_state = 0;
    __gpr int _pif_parrep_error = 0;
    int i;

    /* First zero the parsed representation control data fields */
    for (i = 0; i < PIF_PARREP_CTLDATA_LEN_LW; i++)
        _pif_parrep[PIF_PARREP_CTLDATA_OFF_LW + i] = 0;

    _pif_parrep_pktdata -= _pif_read_xbuf_off;
    mem_read32(_pif_read_xbuf, _pif_parrep_pktdata, sizeof(_pif_read_xbuf));
    _pif_t_index = ((__ctx() << 5) | __xfer_reg_number(_pif_read_xbuf)) << 2;
__label_start:
    { /* implementation of parse node start */
        __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
#ifdef PIF_DEBUG
        __debug_label("pif_parrep_state_start");
#endif

        __critical_path(); /* prioritize the fall through */
    } /* end of implementation of parse node start */
__label_eth_parse:
    { /* implementation of parse node eth_parse */
        __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
        __lmem struct pif_header_eth *eth;
#ifdef PIF_DEBUG
        __debug_label("pif_parrep_state_eth_parse");
#endif

        eth = (__lmem struct pif_header_eth *) (_pif_parrep + PIF_PARREP_eth_OFF_LW);
        {
            /* extract(eth) */

            /* primitive body */
            {
                __gpr uint32_t _pif_parrep_hdrsz = 0;

                {
                    __lmem uint32_t *lm32;
                    unsigned int sizeLW, sizeB;
                    unsigned int lmoff;
                    unsigned int i;

                    sizeLW = PIF_PARREP_eth_LEN_LW;
                    sizeB = PIF_PARREP_eth_LEN_B;
                    lm32 = _pif_parrep + PIF_PARREP_eth_OFF_LW;

                    if (_pif_read_xbuf_off + sizeB > 24 * 4) {
                        _pif_parrep_pktoff += _pif_read_xbuf_off;
                        _pif_parrep_pktdata += _pif_read_xbuf_off;
                        mem_read32(_pif_read_xbuf, _pif_parrep_pktdata, sizeof(_pif_read_xbuf));
                        _pif_read_xbuf_off = 0;
                    }
                    __critical_path();


                    if (_pif_read_xbuf_off & 0x3) {
                        unsigned int lmval;

                        local_csr_write(local_csr_t_index_byte_index, _pif_t_index + _pif_read_xbuf_off);
                        __asm byte_align_be[--, *$index++];
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    } else {
                        unsigned int lmval;

                        __critical_path();
                        local_csr_write(local_csr_t_index, _pif_t_index + _pif_read_xbuf_off);
                         /* unroll lw 0 of 4 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 1 of 4 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 2 of 4 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 3 of 4 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    }
                        __implicit_read(_pif_read_xbuf);
                    _pif_read_xbuf_off += sizeB;
                }
                _pif_parrep_hdrsz = PIF_PARREP_eth_LEN_B;

                if (_pif_parrep_pktoff + _pif_read_xbuf_off > _pif_parrep_pktlen) {
                    _pif_parrep_error = PIF_PARSE_ERROR_OUT_OF_PACKET;
                    _pif_parrep_state = PIF_PARREP_STATE_eth_parse;
                    goto _pif_parrep_label_error;
                }
                __critical_path();
                PIF_PARREP_SET_eth_VALID(_pif_ctldata);
                PIF_PARREP_SET_eth_ORIG_LEN(_pif_ctldata, _pif_parrep_hdrsz);
            }
        }
        if (((eth->etype) == (0x800))) {
            __critical_path(); /* prioritize the fall through */
        } else {
            goto _pif_parrep_label_exit;
        }
    } /* end of implementation of parse node eth_parse */
__label_parse_ipv4:
    { /* implementation of parse node parse_ipv4 */
        __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
        __lmem struct pif_header_ipv4 *ipv4;
#ifdef PIF_DEBUG
        __debug_label("pif_parrep_state_parse_ipv4");
#endif

        ipv4 = (__lmem struct pif_header_ipv4 *) (_pif_parrep + PIF_PARREP_ipv4_OFF_LW);
        {
            /* extract(ipv4) */

            /* primitive body */
            {
                __gpr uint32_t _pif_parrep_hdrsz = 0;

                {
                    __lmem uint32_t *lm32;
                    unsigned int sizeLW, sizeB;
                    unsigned int lmoff;
                    unsigned int i;

                    sizeLW = PIF_PARREP_ipv4_LEN_LW;
                    sizeB = PIF_PARREP_ipv4_LEN_B;
                    lm32 = _pif_parrep + PIF_PARREP_ipv4_OFF_LW;

                    if (_pif_read_xbuf_off + sizeB > 24 * 4) {
                        _pif_parrep_pktoff += _pif_read_xbuf_off;
                        _pif_parrep_pktdata += _pif_read_xbuf_off;
                        mem_read32(_pif_read_xbuf, _pif_parrep_pktdata, sizeof(_pif_read_xbuf));
                        _pif_read_xbuf_off = 0;
                    }
                    __critical_path();


                    if (_pif_read_xbuf_off & 0x3) {
                        unsigned int lmval;

                        local_csr_write(local_csr_t_index_byte_index, _pif_t_index + _pif_read_xbuf_off);
                        __asm byte_align_be[--, *$index++];
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    } else {
                        unsigned int lmval;

                        __critical_path();
                        local_csr_write(local_csr_t_index, _pif_t_index + _pif_read_xbuf_off);
                         /* unroll lw 0 of 5 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 1 of 5 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 2 of 5 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 3 of 5 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 4 of 5 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    }
                        __implicit_read(_pif_read_xbuf);
                    _pif_read_xbuf_off += sizeB;
                }
                _pif_parrep_hdrsz = PIF_PARREP_ipv4_LEN_B;

                if (_pif_parrep_pktoff + _pif_read_xbuf_off > _pif_parrep_pktlen) {
                    _pif_parrep_error = PIF_PARSE_ERROR_OUT_OF_PACKET;
                    _pif_parrep_state = PIF_PARREP_STATE_parse_ipv4;
                    goto _pif_parrep_label_error;
                }
                __critical_path();
                PIF_PARREP_SET_ipv4_VALID(_pif_ctldata);
                PIF_PARREP_SET_ipv4_ORIG_LEN(_pif_ctldata, _pif_parrep_hdrsz);
            }
        }
        if (((ipv4->protocol) == (0x11))) {
            __critical_path(); /* prioritize the fall through */
        } else {
            goto _pif_parrep_label_exit;
        }
    } /* end of implementation of parse node parse_ipv4 */
__label_parse_udp:
    { /* implementation of parse node parse_udp */
        __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
        __lmem struct pif_header_udp *udp;
#ifdef PIF_DEBUG
        __debug_label("pif_parrep_state_parse_udp");
#endif

        udp = (__lmem struct pif_header_udp *) (_pif_parrep + PIF_PARREP_udp_OFF_LW);
        {
            /* extract(udp) */

            /* primitive body */
            {
                __gpr uint32_t _pif_parrep_hdrsz = 0;

                {
                    __lmem uint32_t *lm32;
                    unsigned int sizeLW, sizeB;
                    unsigned int lmoff;
                    unsigned int i;

                    sizeLW = PIF_PARREP_udp_LEN_LW;
                    sizeB = PIF_PARREP_udp_LEN_B;
                    lm32 = _pif_parrep + PIF_PARREP_udp_OFF_LW;

                    if (_pif_read_xbuf_off + sizeB > 24 * 4) {
                        _pif_parrep_pktoff += _pif_read_xbuf_off;
                        _pif_parrep_pktdata += _pif_read_xbuf_off;
                        mem_read32(_pif_read_xbuf, _pif_parrep_pktdata, sizeof(_pif_read_xbuf));
                        _pif_read_xbuf_off = 0;
                    }
                    __critical_path();


                    if (_pif_read_xbuf_off & 0x3) {
                        unsigned int lmval;

                        local_csr_write(local_csr_t_index_byte_index, _pif_t_index + _pif_read_xbuf_off);
                        __asm byte_align_be[--, *$index++];
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    } else {
                        unsigned int lmval;

                        __critical_path();
                        local_csr_write(local_csr_t_index, _pif_t_index + _pif_read_xbuf_off);
                         /* unroll lw 0 of 2 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 1 of 2 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    }
                        __implicit_read(_pif_read_xbuf);
                    _pif_read_xbuf_off += sizeB;
                }
                _pif_parrep_hdrsz = PIF_PARREP_udp_LEN_B;

                if (_pif_parrep_pktoff + _pif_read_xbuf_off > _pif_parrep_pktlen) {
                    _pif_parrep_error = PIF_PARSE_ERROR_OUT_OF_PACKET;
                    _pif_parrep_state = PIF_PARREP_STATE_parse_udp;
                    goto _pif_parrep_label_error;
                }
                __critical_path();
                PIF_PARREP_SET_udp_VALID(_pif_ctldata);
                PIF_PARREP_SET_udp_ORIG_LEN(_pif_ctldata, _pif_parrep_hdrsz);
            }
        }
#ifndef PIF_GLOBAL_FLOWCACHE_DISABLED
        {
            __lmem struct pif_global_flowkey_udp *_pif_fk = (__lmem struct pif_global_flowkey_udp *)(_pif_parrep_fk_ptr + (*_pif_parrep_fk_len));
            _pif_fk->udp__dport = udp->dport;
            _pif_fk->__padding = 0;
            (*_pif_parrep_fk_len) += 1;
        }
#endif
        if (((udp->dport) == (0x18c7))) {
            __critical_path(); /* prioritize the fall through */
        } else {
            goto _pif_parrep_label_exit;
        }
    } /* end of implementation of parse node parse_udp */
__label_parse_sflow_header:
    { /* implementation of parse node parse_sflow_header */
        __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
        __lmem struct pif_header_num_metadata *num_metadata;
        __lmem struct pif_header_sflow_header *sflow_header;
#ifdef PIF_DEBUG
        __debug_label("pif_parrep_state_parse_sflow_header");
#endif

        num_metadata = (__lmem struct pif_header_num_metadata *) (_pif_parrep + PIF_PARREP_num_metadata_OFF_LW);
        sflow_header = (__lmem struct pif_header_sflow_header *) (_pif_parrep + PIF_PARREP_sflow_header_OFF_LW);
        {
            /* extract(sflow_header) */

            /* primitive body */
            {
                __gpr uint32_t _pif_parrep_hdrsz = 0;

                {
                    __lmem uint32_t *lm32;
                    unsigned int sizeLW, sizeB;
                    unsigned int lmoff;
                    unsigned int i;

                    sizeLW = PIF_PARREP_sflow_header_LEN_LW;
                    sizeB = PIF_PARREP_sflow_header_LEN_B;
                    lm32 = _pif_parrep + PIF_PARREP_sflow_header_OFF_LW;

                    if (_pif_read_xbuf_off + sizeB > 24 * 4) {
                        _pif_parrep_pktoff += _pif_read_xbuf_off;
                        _pif_parrep_pktdata += _pif_read_xbuf_off;
                        mem_read32(_pif_read_xbuf, _pif_parrep_pktdata, sizeof(_pif_read_xbuf));
                        _pif_read_xbuf_off = 0;
                    }
                    __critical_path();


                    if (_pif_read_xbuf_off & 0x3) {
                        unsigned int lmval;

                        local_csr_write(local_csr_t_index_byte_index, _pif_t_index + _pif_read_xbuf_off);
                        __asm byte_align_be[--, *$index++];
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    } else {
                        unsigned int lmval;

                        __critical_path();
                        local_csr_write(local_csr_t_index, _pif_t_index + _pif_read_xbuf_off);
                         /* unroll lw 0 of 7 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 1 of 7 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 2 of 7 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 3 of 7 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 4 of 7 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 5 of 7 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 6 of 7 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    }
                        __implicit_read(_pif_read_xbuf);
                    _pif_read_xbuf_off += sizeB;
                }
                _pif_parrep_hdrsz = PIF_PARREP_sflow_header_LEN_B;

                if (_pif_parrep_pktoff + _pif_read_xbuf_off > _pif_parrep_pktlen) {
                    _pif_parrep_error = PIF_PARSE_ERROR_OUT_OF_PACKET;
                    _pif_parrep_state = PIF_PARREP_STATE_parse_sflow_header;
                    goto _pif_parrep_label_error;
                }
                __critical_path();
                PIF_PARREP_SET_sflow_header_VALID(_pif_ctldata);
                PIF_PARREP_SET_sflow_header_ORIG_LEN(_pif_ctldata, _pif_parrep_hdrsz);
            }
        }
        {
            /* set(num_metadata.cur_num,sflow_header.num_samples) */

            /* primitive body */
            num_metadata->cur_num = sflow_header->num_samples;

        }
        if (((num_metadata->cur_num) == (0x0))) {
            goto _pif_parrep_label_exit;
        } else {
            __critical_path(); /* prioritize the fall through */
        }
    } /* end of implementation of parse node parse_sflow_header */
__label_parse_sflow_sample_header:
    { /* implementation of parse node parse_sflow_sample_header */
        __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
        __lmem struct pif_header_sflow_sample_header *sflow_sample_header;
#ifdef PIF_DEBUG
        __debug_label("pif_parrep_state_parse_sflow_sample_header");
#endif

        sflow_sample_header = (__lmem struct pif_header_sflow_sample_header *) (_pif_parrep + PIF_PARREP_sflow_sample_header_OFF_LW);
        {
            /* extract(sflow_sample_header) */

            /* primitive body */
            {
                __gpr uint32_t _pif_parrep_hdrsz = 0;

                {
                    __lmem uint32_t *lm32;
                    unsigned int sizeLW, sizeB;
                    unsigned int lmoff;
                    unsigned int i;

                    sizeLW = PIF_PARREP_sflow_sample_header_LEN_LW;
                    sizeB = PIF_PARREP_sflow_sample_header_LEN_B;
                    lm32 = _pif_parrep + PIF_PARREP_sflow_sample_header_OFF_LW;

                    if (_pif_read_xbuf_off + sizeB > 24 * 4) {
                        _pif_parrep_pktoff += _pif_read_xbuf_off;
                        _pif_parrep_pktdata += _pif_read_xbuf_off;
                        mem_read32(_pif_read_xbuf, _pif_parrep_pktdata, sizeof(_pif_read_xbuf));
                        _pif_read_xbuf_off = 0;
                    }
                    __critical_path();


                    if (_pif_read_xbuf_off & 0x3) {
                        unsigned int lmval;

                        local_csr_write(local_csr_t_index_byte_index, _pif_t_index + _pif_read_xbuf_off);
                        __asm byte_align_be[--, *$index++];
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    } else {
                        unsigned int lmval;

                        __critical_path();
                        local_csr_write(local_csr_t_index, _pif_t_index + _pif_read_xbuf_off);
                         /* unroll lw 0 of 2 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 1 of 2 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    }
                        __implicit_read(_pif_read_xbuf);
                    _pif_read_xbuf_off += sizeB;
                }
                _pif_parrep_hdrsz = PIF_PARREP_sflow_sample_header_LEN_B;

                if (_pif_parrep_pktoff + _pif_read_xbuf_off > _pif_parrep_pktlen) {
                    _pif_parrep_error = PIF_PARSE_ERROR_OUT_OF_PACKET;
                    _pif_parrep_state = PIF_PARREP_STATE_parse_sflow_sample_header;
                    goto _pif_parrep_label_error;
                }
                __critical_path();
                PIF_PARREP_SET_sflow_sample_header_VALID(_pif_ctldata);
                PIF_PARREP_SET_sflow_sample_header_ORIG_LEN(_pif_ctldata, _pif_parrep_hdrsz);
            }
        }
        if (((sflow_sample_header->sample_type) == (0x2))) {
            __critical_path(); /* prioritize the fall through */
        } else if (((sflow_sample_header->sample_type) == (0x5))) {
            goto __label_parse_sflow_sample;
        } else {
            goto _pif_parrep_label_exit;
        }
    } /* end of implementation of parse node parse_sflow_sample_header */
__label_parse_sflow_counter:
    { /* implementation of parse node parse_sflow_counter */
        __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
        __lmem struct pif_header_num_metadata *num_metadata;
        __lmem struct pif_header_sflow_counter *sflow_counter;
#ifdef PIF_DEBUG
        __debug_label("pif_parrep_state_parse_sflow_counter");
#endif

        num_metadata = (__lmem struct pif_header_num_metadata *) (_pif_parrep + PIF_PARREP_num_metadata_OFF_LW);
        sflow_counter = (__lmem struct pif_header_sflow_counter *) (_pif_parrep + PIF_PARREP_sflow_counter_OFF_LW);
        {
            /* extract(sflow_counter) */

            /* primitive body */
            {
                __gpr uint32_t _pif_parrep_hdrsz = 0;

                mem2lmem_copy(_pif_parrep_pktdata + _pif_read_xbuf_off, _pif_parrep,
                            PIF_PARREP_sflow_counter_OFF_LW,
                            PIF_PARREP_sflow_counter_LEN_LW);
                _pif_parrep_hdrsz = PIF_PARREP_sflow_counter_LEN_B;
                _pif_read_xbuf_off += _pif_parrep_hdrsz;

                if (_pif_parrep_pktoff + _pif_read_xbuf_off > _pif_parrep_pktlen) {
                    _pif_parrep_error = PIF_PARSE_ERROR_OUT_OF_PACKET;
                    _pif_parrep_state = PIF_PARREP_STATE_parse_sflow_counter;
                    goto _pif_parrep_label_error;
                }
                __critical_path();
                PIF_PARREP_SET_sflow_counter_VALID(_pif_ctldata);
                PIF_PARREP_SET_sflow_counter_ORIG_LEN(_pif_ctldata, _pif_parrep_hdrsz);
            }
        }
        if (((num_metadata->cur_num) == (0x1))) {
            goto _pif_parrep_label_exit;
        } else {
            __critical_path(); /* prioritize the fall through */
        }
    } /* end of implementation of parse node parse_sflow_counter */
__label_parse_sflow_counter_2:
    { /* implementation of parse node parse_sflow_counter_2 */
        __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
        __lmem struct pif_header_sflow_counter2 *sflow_counter2;
#ifdef PIF_DEBUG
        __debug_label("pif_parrep_state_parse_sflow_counter_2");
#endif

        sflow_counter2 = (__lmem struct pif_header_sflow_counter2 *) (_pif_parrep + PIF_PARREP_sflow_counter2_OFF_LW);
        {
            /* extract(sflow_counter2) */

            /* primitive body */
            {
                __gpr uint32_t _pif_parrep_hdrsz = 0;

                mem2lmem_copy(_pif_parrep_pktdata + _pif_read_xbuf_off, _pif_parrep,
                            PIF_PARREP_sflow_counter2_OFF_LW,
                            PIF_PARREP_sflow_counter2_LEN_LW);
                _pif_parrep_hdrsz = PIF_PARREP_sflow_counter2_LEN_B;
                _pif_read_xbuf_off += _pif_parrep_hdrsz;

                if (_pif_parrep_pktoff + _pif_read_xbuf_off > _pif_parrep_pktlen) {
                    _pif_parrep_error = PIF_PARSE_ERROR_OUT_OF_PACKET;
                    _pif_parrep_state = PIF_PARREP_STATE_parse_sflow_counter_2;
                    goto _pif_parrep_label_error;
                }
                __critical_path();
                PIF_PARREP_SET_sflow_counter2_VALID(_pif_ctldata);
                PIF_PARREP_SET_sflow_counter2_ORIG_LEN(_pif_ctldata, _pif_parrep_hdrsz);
            }
        }
        goto _pif_parrep_label_exit;
    } /* end of implementation of parse node parse_sflow_counter_2 */
__label_parse_sflow_sample:
    { /* implementation of parse node parse_sflow_sample */
        __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
        __lmem struct pif_header_num_metadata *num_metadata;
        __lmem struct pif_header_sflow_sample *sflow_sample;
#ifdef PIF_DEBUG
        __debug_label("pif_parrep_state_parse_sflow_sample");
#endif

        num_metadata = (__lmem struct pif_header_num_metadata *) (_pif_parrep + PIF_PARREP_num_metadata_OFF_LW);
        sflow_sample = (__lmem struct pif_header_sflow_sample *) (_pif_parrep + PIF_PARREP_sflow_sample_OFF_LW);
        {
            /* extract(sflow_sample) */

            /* primitive body */
            {
                __gpr uint32_t _pif_parrep_hdrsz = 0;

                {
                    __lmem uint32_t *lm32;
                    unsigned int sizeLW, sizeB;
                    unsigned int lmoff;
                    unsigned int i;

                    sizeLW = PIF_PARREP_sflow_sample_LEN_LW;
                    sizeB = PIF_PARREP_sflow_sample_LEN_B;
                    lm32 = _pif_parrep + PIF_PARREP_sflow_sample_OFF_LW;

                    if (_pif_read_xbuf_off + sizeB > 24 * 4) {
                        _pif_parrep_pktoff += _pif_read_xbuf_off;
                        _pif_parrep_pktdata += _pif_read_xbuf_off;
                        mem_read32(_pif_read_xbuf, _pif_parrep_pktdata, sizeof(_pif_read_xbuf));
                        _pif_read_xbuf_off = 0;
                    }
                    __critical_path();


                    if (_pif_read_xbuf_off & 0x3) {
                        unsigned int lmval;

                        local_csr_write(local_csr_t_index_byte_index, _pif_t_index + _pif_read_xbuf_off);
                        __asm byte_align_be[--, *$index++];
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    } else {
                        unsigned int lmval;

                        __critical_path();
                        local_csr_write(local_csr_t_index, _pif_t_index + _pif_read_xbuf_off);
                         /* unroll lw 0 of 8 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 1 of 8 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 2 of 8 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 3 of 8 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 4 of 8 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 5 of 8 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 6 of 8 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 7 of 8 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    }
                        __implicit_read(_pif_read_xbuf);
                    _pif_read_xbuf_off += sizeB;
                }
                _pif_parrep_hdrsz = PIF_PARREP_sflow_sample_LEN_B;

                if (_pif_parrep_pktoff + _pif_read_xbuf_off > _pif_parrep_pktlen) {
                    _pif_parrep_error = PIF_PARSE_ERROR_OUT_OF_PACKET;
                    _pif_parrep_state = PIF_PARREP_STATE_parse_sflow_sample;
                    goto _pif_parrep_label_error;
                }
                __critical_path();
                PIF_PARREP_SET_sflow_sample_VALID(_pif_ctldata);
                PIF_PARREP_SET_sflow_sample_ORIG_LEN(_pif_ctldata, _pif_parrep_hdrsz);
            }
        }
#ifndef PIF_GLOBAL_FLOWCACHE_DISABLED
        {
            __lmem struct pif_global_flowkey_sflow_sample *_pif_fk = (__lmem struct pif_global_flowkey_sflow_sample *)(_pif_parrep_fk_ptr + (*_pif_parrep_fk_len));
            _pif_fk->sflow_sample__eth_type = sflow_sample->eth_type;
            _pif_fk->sflow_sample__ip_flag = sflow_sample->ip_flag;
            _pif_fk->__padding = 0;
            (*_pif_parrep_fk_len) += 2;
        }
#endif
        if (((num_metadata->cur_num) == (0x1))) {
            goto _pif_parrep_label_exit;
        } else {
            __critical_path(); /* prioritize the fall through */
        }
    } /* end of implementation of parse node parse_sflow_sample */
__label_parse_sflow_sample_2:
    { /* implementation of parse node parse_sflow_sample_2 */
        __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
        __lmem struct pif_header_sflow_sample2 *sflow_sample2;
#ifdef PIF_DEBUG
        __debug_label("pif_parrep_state_parse_sflow_sample_2");
#endif

        sflow_sample2 = (__lmem struct pif_header_sflow_sample2 *) (_pif_parrep + PIF_PARREP_sflow_sample2_OFF_LW);
        {
            /* extract(sflow_sample2) */

            /* primitive body */
            {
                __gpr uint32_t _pif_parrep_hdrsz = 0;

                {
                    __lmem uint32_t *lm32;
                    unsigned int sizeLW, sizeB;
                    unsigned int lmoff;
                    unsigned int i;

                    sizeLW = PIF_PARREP_sflow_sample2_LEN_LW;
                    sizeB = PIF_PARREP_sflow_sample2_LEN_B;
                    lm32 = _pif_parrep + PIF_PARREP_sflow_sample2_OFF_LW;

                    if (_pif_read_xbuf_off + sizeB > 24 * 4) {
                        _pif_parrep_pktoff += _pif_read_xbuf_off;
                        _pif_parrep_pktdata += _pif_read_xbuf_off;
                        mem_read32(_pif_read_xbuf, _pif_parrep_pktdata, sizeof(_pif_read_xbuf));
                        _pif_read_xbuf_off = 0;
                    }
                    __critical_path();


                    if (_pif_read_xbuf_off & 0x3) {
                        unsigned int lmval;

                        local_csr_write(local_csr_t_index_byte_index, _pif_t_index + _pif_read_xbuf_off);
                        __asm byte_align_be[--, *$index++];
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                        __asm byte_align_be[lmval, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    } else {
                        unsigned int lmval;

                        __critical_path();
                        local_csr_write(local_csr_t_index, _pif_t_index + _pif_read_xbuf_off);
                         /* unroll lw 0 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 1 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 2 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 3 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 4 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 5 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 6 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 7 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 8 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                         /* unroll lw 9 of 10 */
                        __asm alu[lmval, --, B, *$index++];
                        *lm32 = lmval;
                        lm32 += 1;
                    }
                        __implicit_read(_pif_read_xbuf);
                    _pif_read_xbuf_off += sizeB;
                }
                _pif_parrep_hdrsz = PIF_PARREP_sflow_sample2_LEN_B;

                if (_pif_parrep_pktoff + _pif_read_xbuf_off > _pif_parrep_pktlen) {
                    _pif_parrep_error = PIF_PARSE_ERROR_OUT_OF_PACKET;
                    _pif_parrep_state = PIF_PARREP_STATE_parse_sflow_sample_2;
                    goto _pif_parrep_label_error;
                }
                __critical_path();
                PIF_PARREP_SET_sflow_sample2_VALID(_pif_ctldata);
                PIF_PARREP_SET_sflow_sample2_ORIG_LEN(_pif_ctldata, _pif_parrep_hdrsz);
            }
        }
#ifndef PIF_GLOBAL_FLOWCACHE_DISABLED
        {
            __lmem struct pif_global_flowkey_sflow_sample2 *_pif_fk = (__lmem struct pif_global_flowkey_sflow_sample2 *)(_pif_parrep_fk_ptr + (*_pif_parrep_fk_len));
            _pif_fk->sflow_sample2__ip_flag = sflow_sample2->ip_flag;
            _pif_fk->__padding = 0;
            (*_pif_parrep_fk_len) += 1;
        }
#endif
        goto _pif_parrep_label_exit;
    } /* end of implementation of parse node parse_sflow_sample_2 */
_pif_parrep_label_exit:
    pif_pkt_info_spec.pkt_pl_off = _pif_parrep_pktoff + _pif_read_xbuf_off;
    PIF_PARREP_SET_VALID(_pif_ctldata);
#ifndef PIF_GLOBAL_FLOWCACHE_DISABLED
    {
        __lmem struct pif_header_num_metadata *num_metadata = (__lmem struct pif_header_num_metadata *)(parrep + PIF_PARREP_num_metadata_OFF_LW);
        __lmem struct pif_header_standard_metadata *standard_metadata = (__lmem struct pif_header_standard_metadata *)(parrep + PIF_PARREP_standard_metadata_OFF_LW);
        __lmem struct pif_global_flowkey_metadata *_pif_fk = (__lmem struct pif_global_flowkey_metadata *)(_pif_parrep_fk_ptr + *_pif_parrep_fk_len);
        _pif_fk->num_metadata__cur_num = num_metadata->cur_num;
        _pif_fk->standard_metadata__ingress_port = standard_metadata->ingress_port;
        _pif_fk->__padding = 0;
        (*_pif_parrep_fk_len) += 1;
        }
    _pif_parrep_fk_ptr[(*_pif_parrep_fk_len) + 0] = _pif_parrep[PIF_PARREP_CTLDATA_OFF_LW + 0] & 0x8100c000;
    _pif_parrep_fk_ptr[(*_pif_parrep_fk_len) + 1] = _pif_parrep[PIF_PARREP_CTLDATA_OFF_LW + 1] & 0xc0000000;
    (*_pif_parrep_fk_len) += PIF_PARREP_CTLDATA_LEN_LW;
#endif /* !PIF_GLOBAL_FLOWCACHE_DISABLED */
    return 0;
_pif_parrep_label_error:
    pif_pkt_info_spec.pkt_pl_off = _pif_parrep_pktoff + _pif_read_xbuf_off;
    pif_global_set_stdmd_parser_error_location(_pif_parrep, _pif_parrep_state);
    return -_pif_parrep_error;
}

extern __forceinline int
pif_parrep_exceptions(__lmem uint32_t *_pif_parrep, int _pif_pe_error, __lmem uint32_t *_pif_parrep_fk_ptr, __gpr uint32_t *_pif_parrep_fk_len)
{
    return -1; /* no exceptions, always fail */
}
