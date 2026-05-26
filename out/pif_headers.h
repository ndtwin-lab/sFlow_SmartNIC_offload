/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_HEADERS_H__
#define __PIF_HEADERS_H__

/* Generated C source defining PIF headers, metadata and registers */
/* Warning: your edits to this file may be lost */

/*
 * Packet headers
 */

/* udp (8B) */
struct pif_header_udp {
    unsigned int sport:16;
    unsigned int dport:16;
    unsigned int len:16;
    unsigned int checksum:16;
};

/* udp field accessor macros */
#define PIF_HEADER_GET_udp___sport(_hdr_p) (((_hdr_p)->sport)) /* udp.sport [16;0] */

#define PIF_HEADER_SET_udp___sport(_hdr_p, _val) \
    do { \
        (_hdr_p)->sport = (unsigned)(((_val))); \
    } while (0) /* udp.sport[16;0] */

#define PIF_HEADER_GET_udp___dport(_hdr_p) (((_hdr_p)->dport)) /* udp.dport [16;0] */

#define PIF_HEADER_SET_udp___dport(_hdr_p, _val) \
    do { \
        (_hdr_p)->dport = (unsigned)(((_val))); \
    } while (0) /* udp.dport[16;0] */

#define PIF_HEADER_GET_udp___len(_hdr_p) (((_hdr_p)->len)) /* udp.len [16;0] */

#define PIF_HEADER_SET_udp___len(_hdr_p, _val) \
    do { \
        (_hdr_p)->len = (unsigned)(((_val))); \
    } while (0) /* udp.len[16;0] */

#define PIF_HEADER_GET_udp___checksum(_hdr_p) (((_hdr_p)->checksum)) /* udp.checksum [16;0] */

#define PIF_HEADER_SET_udp___checksum(_hdr_p, _val) \
    do { \
        (_hdr_p)->checksum = (unsigned)(((_val))); \
    } while (0) /* udp.checksum[16;0] */


/* sflow_sample (32B) */
struct pif_header_sflow_sample {
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

/* sflow_sample field accessor macros */
#define PIF_HEADER_GET_sflow_sample___in_port(_hdr_p) (((_hdr_p)->in_port)) /* sflow_sample.in_port [16;0] */

#define PIF_HEADER_SET_sflow_sample___in_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->in_port = (unsigned)(((_val))); \
    } while (0) /* sflow_sample.in_port[16;0] */

#define PIF_HEADER_GET_sflow_sample___out_port(_hdr_p) (((_hdr_p)->out_port)) /* sflow_sample.out_port [16;0] */

#define PIF_HEADER_SET_sflow_sample___out_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->out_port = (unsigned)(((_val))); \
    } while (0) /* sflow_sample.out_port[16;0] */

#define PIF_HEADER_GET_sflow_sample___sample_rate(_hdr_p) (((_hdr_p)->sample_rate)) /* sflow_sample.sample_rate [32;0] */

#define PIF_HEADER_SET_sflow_sample___sample_rate(_hdr_p, _val) \
    do { \
        (_hdr_p)->sample_rate = (unsigned)(((_val))); \
    } while (0) /* sflow_sample.sample_rate[32;0] */

#define PIF_HEADER_GET_sflow_sample___eth_type(_hdr_p) (((_hdr_p)->eth_type)) /* sflow_sample.eth_type [32;0] */

#define PIF_HEADER_SET_sflow_sample___eth_type(_hdr_p, _val) \
    do { \
        (_hdr_p)->eth_type = (unsigned)(((_val))); \
    } while (0) /* sflow_sample.eth_type[32;0] */

#define PIF_HEADER_GET_sflow_sample___frame_length(_hdr_p) (((_hdr_p)->frame_length)) /* sflow_sample.frame_length [16;0] */

#define PIF_HEADER_SET_sflow_sample___frame_length(_hdr_p, _val) \
    do { \
        (_hdr_p)->frame_length = (unsigned)(((_val))); \
    } while (0) /* sflow_sample.frame_length[16;0] */

#define PIF_HEADER_GET_sflow_sample___protocol(_hdr_p) (((_hdr_p)->protocol)) /* sflow_sample.protocol [16;0] */

#define PIF_HEADER_SET_sflow_sample___protocol(_hdr_p, _val) \
    do { \
        (_hdr_p)->protocol = (unsigned)(((_val))); \
    } while (0) /* sflow_sample.protocol[16;0] */

#define PIF_HEADER_GET_sflow_sample___srcIP(_hdr_p) (((_hdr_p)->srcIP)) /* sflow_sample.srcIP [32;0] */

#define PIF_HEADER_SET_sflow_sample___srcIP(_hdr_p, _val) \
    do { \
        (_hdr_p)->srcIP = (unsigned)(((_val))); \
    } while (0) /* sflow_sample.srcIP[32;0] */

#define PIF_HEADER_GET_sflow_sample___dstIP(_hdr_p) (((_hdr_p)->dstIP)) /* sflow_sample.dstIP [32;0] */

#define PIF_HEADER_SET_sflow_sample___dstIP(_hdr_p, _val) \
    do { \
        (_hdr_p)->dstIP = (unsigned)(((_val))); \
    } while (0) /* sflow_sample.dstIP[32;0] */

#define PIF_HEADER_GET_sflow_sample___ip_flag(_hdr_p) (((_hdr_p)->ip_flag)) /* sflow_sample.ip_flag [16;0] */

#define PIF_HEADER_SET_sflow_sample___ip_flag(_hdr_p, _val) \
    do { \
        (_hdr_p)->ip_flag = (unsigned)(((_val))); \
    } while (0) /* sflow_sample.ip_flag[16;0] */

#define PIF_HEADER_GET_sflow_sample___tcp_flag(_hdr_p) (((_hdr_p)->tcp_flag)) /* sflow_sample.tcp_flag [16;0] */

#define PIF_HEADER_SET_sflow_sample___tcp_flag(_hdr_p, _val) \
    do { \
        (_hdr_p)->tcp_flag = (unsigned)(((_val))); \
    } while (0) /* sflow_sample.tcp_flag[16;0] */

#define PIF_HEADER_GET_sflow_sample___srcPort(_hdr_p) (((_hdr_p)->srcPort)) /* sflow_sample.srcPort [16;0] */

#define PIF_HEADER_SET_sflow_sample___srcPort(_hdr_p, _val) \
    do { \
        (_hdr_p)->srcPort = (unsigned)(((_val))); \
    } while (0) /* sflow_sample.srcPort[16;0] */

#define PIF_HEADER_GET_sflow_sample___dstPort(_hdr_p) (((_hdr_p)->dstPort)) /* sflow_sample.dstPort [16;0] */

#define PIF_HEADER_SET_sflow_sample___dstPort(_hdr_p, _val) \
    do { \
        (_hdr_p)->dstPort = (unsigned)(((_val))); \
    } while (0) /* sflow_sample.dstPort[16;0] */


/* sflow_sample2 (40B) */
struct pif_header_sflow_sample2 {
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


/* sflow_sample_header (8B) */
struct pif_header_sflow_sample_header {
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


/* ipv4 (20B) */
struct pif_header_ipv4 {
    unsigned int version:4;
    unsigned int ihl:4;
    unsigned int diffserv:8;
    unsigned int totalLen:16;
    unsigned int identification:16;
    unsigned int flags:3;
    unsigned int fragOffset:13;
    unsigned int ttl:8;
    unsigned int protocol:8;
    unsigned int hdrChecksum:16;
    unsigned int srcAddr:32;
    unsigned int dstAddr:32;
};

/* ipv4 field accessor macros */
#define PIF_HEADER_GET_ipv4___version(_hdr_p) (((_hdr_p)->version)) /* ipv4.version [4;0] */

#define PIF_HEADER_SET_ipv4___version(_hdr_p, _val) \
    do { \
        (_hdr_p)->version = (unsigned)(((_val))); \
    } while (0) /* ipv4.version[4;0] */

#define PIF_HEADER_GET_ipv4___ihl(_hdr_p) (((_hdr_p)->ihl)) /* ipv4.ihl [4;0] */

#define PIF_HEADER_SET_ipv4___ihl(_hdr_p, _val) \
    do { \
        (_hdr_p)->ihl = (unsigned)(((_val))); \
    } while (0) /* ipv4.ihl[4;0] */

#define PIF_HEADER_GET_ipv4___diffserv(_hdr_p) (((_hdr_p)->diffserv)) /* ipv4.diffserv [8;0] */

#define PIF_HEADER_SET_ipv4___diffserv(_hdr_p, _val) \
    do { \
        (_hdr_p)->diffserv = (unsigned)(((_val))); \
    } while (0) /* ipv4.diffserv[8;0] */

#define PIF_HEADER_GET_ipv4___totalLen(_hdr_p) (((_hdr_p)->totalLen)) /* ipv4.totalLen [16;0] */

#define PIF_HEADER_SET_ipv4___totalLen(_hdr_p, _val) \
    do { \
        (_hdr_p)->totalLen = (unsigned)(((_val))); \
    } while (0) /* ipv4.totalLen[16;0] */

#define PIF_HEADER_GET_ipv4___identification(_hdr_p) (((_hdr_p)->identification)) /* ipv4.identification [16;0] */

#define PIF_HEADER_SET_ipv4___identification(_hdr_p, _val) \
    do { \
        (_hdr_p)->identification = (unsigned)(((_val))); \
    } while (0) /* ipv4.identification[16;0] */

#define PIF_HEADER_GET_ipv4___flags(_hdr_p) (((_hdr_p)->flags)) /* ipv4.flags [3;0] */

#define PIF_HEADER_SET_ipv4___flags(_hdr_p, _val) \
    do { \
        (_hdr_p)->flags = (unsigned)(((_val))); \
    } while (0) /* ipv4.flags[3;0] */

#define PIF_HEADER_GET_ipv4___fragOffset(_hdr_p) (((_hdr_p)->fragOffset)) /* ipv4.fragOffset [13;0] */

#define PIF_HEADER_SET_ipv4___fragOffset(_hdr_p, _val) \
    do { \
        (_hdr_p)->fragOffset = (unsigned)(((_val))); \
    } while (0) /* ipv4.fragOffset[13;0] */

#define PIF_HEADER_GET_ipv4___ttl(_hdr_p) (((_hdr_p)->ttl)) /* ipv4.ttl [8;0] */

#define PIF_HEADER_SET_ipv4___ttl(_hdr_p, _val) \
    do { \
        (_hdr_p)->ttl = (unsigned)(((_val))); \
    } while (0) /* ipv4.ttl[8;0] */

#define PIF_HEADER_GET_ipv4___protocol(_hdr_p) (((_hdr_p)->protocol)) /* ipv4.protocol [8;0] */

#define PIF_HEADER_SET_ipv4___protocol(_hdr_p, _val) \
    do { \
        (_hdr_p)->protocol = (unsigned)(((_val))); \
    } while (0) /* ipv4.protocol[8;0] */

#define PIF_HEADER_GET_ipv4___hdrChecksum(_hdr_p) (((_hdr_p)->hdrChecksum)) /* ipv4.hdrChecksum [16;0] */

#define PIF_HEADER_SET_ipv4___hdrChecksum(_hdr_p, _val) \
    do { \
        (_hdr_p)->hdrChecksum = (unsigned)(((_val))); \
    } while (0) /* ipv4.hdrChecksum[16;0] */

#define PIF_HEADER_GET_ipv4___srcAddr(_hdr_p) (((_hdr_p)->srcAddr)) /* ipv4.srcAddr [32;0] */

#define PIF_HEADER_SET_ipv4___srcAddr(_hdr_p, _val) \
    do { \
        (_hdr_p)->srcAddr = (unsigned)(((_val))); \
    } while (0) /* ipv4.srcAddr[32;0] */

#define PIF_HEADER_GET_ipv4___dstAddr(_hdr_p) (((_hdr_p)->dstAddr)) /* ipv4.dstAddr [32;0] */

#define PIF_HEADER_SET_ipv4___dstAddr(_hdr_p, _val) \
    do { \
        (_hdr_p)->dstAddr = (unsigned)(((_val))); \
    } while (0) /* ipv4.dstAddr[32;0] */


/* eth (14B) */
struct pif_header_eth {
    /* dst [32;16] */
    unsigned int dst:32;
    /* dst [16;0] */
    unsigned int __dst_1:16;
    /* src [16;32] */
    unsigned int src:16;
    /* src [32;0] */
    unsigned int __src_1:32;
    unsigned int etype:16;
};

/* eth field accessor macros */
#define PIF_HEADER_GET_eth___dst___0(_hdr_p) ((((_hdr_p)->dst & 0xffff) << 16) | ((_hdr_p)->__dst_1)) /* eth.dst [32;0] */

#define PIF_HEADER_SET_eth___dst___0(_hdr_p, _val) \
    do { \
        (_hdr_p)->dst &= (unsigned)(0xffff0000); \
        (_hdr_p)->dst |= (unsigned)((((_val) >> 16) & 0xffff)); \
        (_hdr_p)->__dst_1 = (unsigned)(((_val))); \
    } while (0) /* eth.dst[32;0] */

#define PIF_HEADER_GET_eth___dst___1(_hdr_p) ((((_hdr_p)->dst >> 16) & 0xffff)) /* eth.dst [16;32] */

#define PIF_HEADER_SET_eth___dst___1(_hdr_p, _val) \
    do { \
        (_hdr_p)->dst &= (unsigned)(0xffff); \
        (_hdr_p)->dst |= (unsigned)((((_val) & 0xffff) << 16)); \
    } while (0) /* eth.dst[16;32] */

#define PIF_HEADER_GET_eth___src___0(_hdr_p) (((_hdr_p)->__src_1)) /* eth.src [32;0] */

#define PIF_HEADER_SET_eth___src___0(_hdr_p, _val) \
    do { \
        (_hdr_p)->__src_1 = (unsigned)(((_val))); \
    } while (0) /* eth.src[32;0] */

#define PIF_HEADER_GET_eth___src___1(_hdr_p) (((_hdr_p)->src)) /* eth.src [16;32] */

#define PIF_HEADER_SET_eth___src___1(_hdr_p, _val) \
    do { \
        (_hdr_p)->src = (unsigned)(((_val))); \
    } while (0) /* eth.src[16;32] */

#define PIF_HEADER_GET_eth___etype(_hdr_p) (((_hdr_p)->etype)) /* eth.etype [16;0] */

#define PIF_HEADER_SET_eth___etype(_hdr_p, _val) \
    do { \
        (_hdr_p)->etype = (unsigned)(((_val))); \
    } while (0) /* eth.etype[16;0] */


/* sflow_counter (168B) */
struct pif_header_sflow_counter {
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


/* sflow_counter2 (176B) */
struct pif_header_sflow_counter2 {
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


/* sflow_header (28B) */
struct pif_header_sflow_header {
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


/*
 * Metadata
 */

/* standard_metadata (16B) */
struct pif_header_standard_metadata {
    unsigned int clone_spec:32;
    unsigned int egress_spec:16;
    unsigned int egress_port:16;
    unsigned int packet_length:14;
    unsigned int egress_instance:10;
    unsigned int parser_error_location:8;
    unsigned int ingress_port:10;
    unsigned int instance_type:4;
    unsigned int parser_status:3;
    unsigned int _padding_0:15;
};

/* standard_metadata field accessor macros */
#define PIF_HEADER_GET_standard_metadata___clone_spec(_hdr_p) (((_hdr_p)->clone_spec)) /* standard_metadata.clone_spec [32;0] */

#define PIF_HEADER_SET_standard_metadata___clone_spec(_hdr_p, _val) \
    do { \
        (_hdr_p)->clone_spec = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.clone_spec[32;0] */

#define PIF_HEADER_GET_standard_metadata___egress_spec(_hdr_p) (((_hdr_p)->egress_spec)) /* standard_metadata.egress_spec [16;0] */

#define PIF_HEADER_SET_standard_metadata___egress_spec(_hdr_p, _val) \
    do { \
        (_hdr_p)->egress_spec = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.egress_spec[16;0] */

#define PIF_HEADER_GET_standard_metadata___egress_port(_hdr_p) (((_hdr_p)->egress_port)) /* standard_metadata.egress_port [16;0] */

#define PIF_HEADER_SET_standard_metadata___egress_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->egress_port = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.egress_port[16;0] */

#define PIF_HEADER_GET_standard_metadata___packet_length(_hdr_p) (((_hdr_p)->packet_length)) /* standard_metadata.packet_length [14;0] */

#define PIF_HEADER_SET_standard_metadata___packet_length(_hdr_p, _val) \
    do { \
        (_hdr_p)->packet_length = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.packet_length[14;0] */

#define PIF_HEADER_GET_standard_metadata___egress_instance(_hdr_p) (((_hdr_p)->egress_instance)) /* standard_metadata.egress_instance [10;0] */

#define PIF_HEADER_SET_standard_metadata___egress_instance(_hdr_p, _val) \
    do { \
        (_hdr_p)->egress_instance = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.egress_instance[10;0] */

#define PIF_HEADER_GET_standard_metadata___parser_error_location(_hdr_p) (((_hdr_p)->parser_error_location)) /* standard_metadata.parser_error_location [8;0] */

#define PIF_HEADER_SET_standard_metadata___parser_error_location(_hdr_p, _val) \
    do { \
        (_hdr_p)->parser_error_location = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.parser_error_location[8;0] */

#define PIF_HEADER_GET_standard_metadata___ingress_port(_hdr_p) (((_hdr_p)->ingress_port)) /* standard_metadata.ingress_port [10;0] */

#define PIF_HEADER_SET_standard_metadata___ingress_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->ingress_port = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.ingress_port[10;0] */

#define PIF_HEADER_GET_standard_metadata___instance_type(_hdr_p) (((_hdr_p)->instance_type)) /* standard_metadata.instance_type [4;0] */

#define PIF_HEADER_SET_standard_metadata___instance_type(_hdr_p, _val) \
    do { \
        (_hdr_p)->instance_type = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.instance_type[4;0] */

#define PIF_HEADER_GET_standard_metadata___parser_status(_hdr_p) (((_hdr_p)->parser_status)) /* standard_metadata.parser_status [3;0] */

#define PIF_HEADER_SET_standard_metadata___parser_status(_hdr_p, _val) \
    do { \
        (_hdr_p)->parser_status = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.parser_status[3;0] */

#define PIF_HEADER_GET_standard_metadata____padding_0(_hdr_p) (((_hdr_p)->_padding_0)) /* standard_metadata._padding_0 [15;0] */

#define PIF_HEADER_SET_standard_metadata____padding_0(_hdr_p, _val) \
    do { \
        (_hdr_p)->_padding_0 = (unsigned)(((_val))); \
    } while (0) /* standard_metadata._padding_0[15;0] */


/* num_metadata (4B) */
struct pif_header_num_metadata {
    unsigned int cur_num:8;
    unsigned int _padding_0:24;
};

/* num_metadata field accessor macros */
#define PIF_HEADER_GET_num_metadata___cur_num(_hdr_p) (((_hdr_p)->cur_num)) /* num_metadata.cur_num [8;0] */

#define PIF_HEADER_SET_num_metadata___cur_num(_hdr_p, _val) \
    do { \
        (_hdr_p)->cur_num = (unsigned)(((_val))); \
    } while (0) /* num_metadata.cur_num[8;0] */

#define PIF_HEADER_GET_num_metadata____padding_0(_hdr_p) (((_hdr_p)->_padding_0)) /* num_metadata._padding_0 [24;0] */

#define PIF_HEADER_SET_num_metadata____padding_0(_hdr_p, _val) \
    do { \
        (_hdr_p)->_padding_0 = (unsigned)(((_val))); \
    } while (0) /* num_metadata._padding_0[24;0] */


/* recirculate_fl (4B) */
struct pif_header_recirculate_fl {
    unsigned int fl:8;
    unsigned int recirculate_count:8;
    unsigned int _padding_0:16;
};

/* recirculate_fl field accessor macros */
#define PIF_HEADER_GET_recirculate_fl___fl(_hdr_p) (((_hdr_p)->fl)) /* recirculate_fl.fl [8;0] */

#define PIF_HEADER_SET_recirculate_fl___fl(_hdr_p, _val) \
    do { \
        (_hdr_p)->fl = (unsigned)(((_val))); \
    } while (0) /* recirculate_fl.fl[8;0] */

#define PIF_HEADER_GET_recirculate_fl___recirculate_count(_hdr_p) (((_hdr_p)->recirculate_count)) /* recirculate_fl.recirculate_count [8;0] */

#define PIF_HEADER_SET_recirculate_fl___recirculate_count(_hdr_p, _val) \
    do { \
        (_hdr_p)->recirculate_count = (unsigned)(((_val))); \
    } while (0) /* recirculate_fl.recirculate_count[8;0] */

#define PIF_HEADER_GET_recirculate_fl____padding_0(_hdr_p) (((_hdr_p)->_padding_0)) /* recirculate_fl._padding_0 [16;0] */

#define PIF_HEADER_SET_recirculate_fl____padding_0(_hdr_p, _val) \
    do { \
        (_hdr_p)->_padding_0 = (unsigned)(((_val))); \
    } while (0) /* recirculate_fl._padding_0[16;0] */



/*
 * Registers
 */

#endif /* __PIF_HEADERS_H__ */
