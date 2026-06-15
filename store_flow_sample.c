#include <pif_plugin.h>
#include <pif_plugin_metadata.h>
#include <pif_common.h>
#include <pif_headers.h>
#include <memory.h>
#include <stdint.h>
#include <nfp.h>
#include <nfp/me.h>
#include <nfp/mem_bulk.h>
#include <nfp6000/nfp_me.h>
#include <nfp/mem_atomic.h>
#include <pkt/pkt.h>
#include <mac_time.h> // view C:\NFP_SDK_6.1.0-preview\p4\components\nfp_pif\me\lib\pif\include, it's about ingress time.

#define HASH_SIZE 20000 // can be 16,384, 2^15 so that mod can use "&" .
#define NO_ONE_STATE 0x00000000
#define WRITTEN_STATE 0x00000001
#define FINISH_STATE 0x00000002
// for test > using the below method  to count how many packets and store the val in reg.

struct flow_key
{
    uint32_t src_ip : 32;
    uint32_t dst_ip : 32;
    uint32_t sampling_rate : 32;
    uint32_t agent_ip : 32;
    uint16_t in_if : 16;
    uint16_t out_if : 16;
    uint16_t src_port : 16;
    uint16_t dst_port : 16;
    uint32_t protocol : 32;
    uint32_t padding : 32;
};

struct stored_flow_key
{
    uint32_t src_ip : 32;
    uint32_t dst_ip : 32;
    uint32_t sampling_rate : 32;
    uint32_t agent_ip : 32;
    uint16_t in_if : 16;
    uint16_t out_if : 16;
    uint16_t src_port : 16;
    uint16_t dst_port : 16;
    uint32_t protocol : 32;
    uint32_t tcp_flag : 32;
};

struct flow_data
{
    uint32_t byte_cnt_0 : 32;
    uint32_t byte_cnt_1 : 32;
    uint32_t packet_cnt_0 : 32;
    uint32_t packet_cnt_1 : 32;
    struct mac_time_data start_time;
    struct mac_time_data end_time;
};

static __forceinline struct mac_time_data
get_current_mac_time(void)
{
    __xread struct mac_time_state time_xfer;
    struct mac_time_state time_state;

    mac_time_fetch(&time_xfer);
    time_state = time_xfer;

    return mac_time_calc(time_state);
}

volatile __export __emem uint32_t global_semaphores[HASH_SIZE];
__export __emem __align256 struct stored_flow_key _flow_key[HASH_SIZE];
__export __emem __align256 struct flow_data _flow_data[HASH_SIZE];
volatile __export __emem uint32_t global_semaphores_dup[HASH_SIZE];
__export __emem __align256 struct stored_flow_key _flow_key_dup[HASH_SIZE];
__export __emem __align256 struct flow_data _flow_data_dup[HASH_SIZE];
__export __emem __align256 uint32_t _cur_state;
__export __emem __align256 uint32_t _processing_me[2];

static __intrinsic uint32_t read_storage_state(void)
{
    __xread uint32_t state_xfer;

    mem_read_atomic(&state_xfer, (__mem __addr40 uint32_t *)&_cur_state, sizeof(state_xfer));
    return state_xfer & 1;
}

static __intrinsic void processing_me_enter(uint32_t state)
{
    __xwrite uint32_t one = 1;

    mem_add32(&one, (__mem __addr40 uint32_t *)&_processing_me[state & 1], sizeof(one));
}

static __intrinsic void processing_me_leave(uint32_t state)
{
    __xwrite uint32_t one = 1;

    mem_sub32(&one, (__mem __addr40 uint32_t *)&_processing_me[state & 1], sizeof(one));
}

static __intrinsic uint32_t acquire_storage_state(void)
{
    uint32_t state_tmp;

    while (1)
    {
        state_tmp = read_storage_state();
        processing_me_enter(state_tmp);

        if (read_storage_state() == state_tmp)
        {
            return state_tmp;
        }

        processing_me_leave(state_tmp);
    }
}

static __intrinsic void write_key_record(__mem __addr40 uint32_t *dst,
                                         struct stored_flow_key flow_key)
{
    __xwrite struct stored_flow_key key_xfer = flow_key;

    mem_write_atomic(&key_xfer, dst, sizeof(key_xfer));
}

static __intrinsic void write_data_record(__mem __addr40 uint64_t *dst,
                                          uint32_t frame_length,
                                          struct mac_time_data sample_time)
{
    __xwrite struct flow_data data_xfer;

    data_xfer.byte_cnt_0 = frame_length;
    data_xfer.byte_cnt_1 = 0;
    data_xfer.packet_cnt_0 = 1;
    data_xfer.packet_cnt_1 = 0;
    data_xfer.start_time = sample_time;
    data_xfer.end_time = sample_time;

    mem_write_atomic(&data_xfer, dst, sizeof(data_xfer));
}

static __intrinsic void add_flow_counts(__mem __addr40 uint64_t *dst,
                                        uint32_t frame_length)
{
    __xwrite uint64_t count_xfer = ((uint64_t)frame_length<<32) | 0;
    __xwrite uint64_t packet_cnt_xfer = ((uint64_t)1<<32) | 0;

    mem_add64(&count_xfer, dst, sizeof(count_xfer));
    mem_add64(&packet_cnt_xfer, dst + 1, sizeof(packet_cnt_xfer));
}

static __intrinsic void write_flow_end_time(__mem __addr40 uint64_t *dst,
                                            struct mac_time_data sample_time)
{
    __xwrite struct mac_time_data time_xfer = sample_time;

    mem_write_atomic(&time_xfer, dst, sizeof(time_xfer));
}

static __intrinsic void set_flow_tcp_flags(__mem __addr40 uint32_t *dst,
                                           uint32_t tcp_flag)
{
    __xwrite uint32_t tcp_flag_xfer = tcp_flag;

    mem_bitset(&tcp_flag_xfer, dst, sizeof(tcp_flag_xfer));
}

static __intrinsic void write_first_data_to_mem(
    uint32_t index,
    struct stored_flow_key flow_key,
    uint32_t frame_length,
    struct mac_time_data sample_time,
    uint32_t state)
{
    __mem __addr40 uint32_t *_pif_hdrptr_key;
    __mem __addr40 uint64_t *_pif_hdrptr_data;

    if ((state & 1) == 0)
    {
        _pif_hdrptr_key = (__mem __addr40 uint32_t *)&(_flow_key[index]);
        _pif_hdrptr_data = (__mem __addr40 uint64_t *)&(_flow_data[index]);
    }
    else
    {
        _pif_hdrptr_key = (__mem __addr40 uint32_t *)&(_flow_key_dup[index]);
        _pif_hdrptr_data = (__mem __addr40 uint64_t *)&(_flow_data_dup[index]);
    }

    write_key_record(_pif_hdrptr_key, flow_key);
    write_data_record(_pif_hdrptr_data, frame_length, sample_time);
}

static __intrinsic void write_data_to_mem(
    uint32_t index,
    struct stored_flow_key flow_key,
    uint32_t frame_length,
    struct mac_time_data sample_time,
    uint32_t state)
{
    __mem __addr40 uint32_t *_pif_hdrptr_key;
    __mem __addr40 uint64_t *_pif_hdrptr_data;

    if ((state & 1) == 0)
    {
        _pif_hdrptr_key = (__mem __addr40 uint32_t *)&(_flow_key[index]);
        _pif_hdrptr_data = (__mem __addr40 uint64_t *)&(_flow_data[index]);
    }
    else
    {
        _pif_hdrptr_key = (__mem __addr40 uint32_t *)&(_flow_key_dup[index]);
        _pif_hdrptr_data = (__mem __addr40 uint64_t *)&(_flow_data_dup[index]);
    }

    add_flow_counts(_pif_hdrptr_data, frame_length);
    write_flow_end_time(_pif_hdrptr_data + 3, sample_time);
    set_flow_tcp_flags(_pif_hdrptr_key + 7, flow_key.tcp_flag);
}

static __intrinsic uint8_t read_and_check(
    uint32_t index,
    struct stored_flow_key flow,
    uint32_t state)
{
    __xread uint32_t key[7];
    __mem __addr40 uint32_t *_pif_hdrptr =
        ((state & 1) == 0) ?
        (__mem __addr40 uint32_t *)&(_flow_key[index]) :
        (__mem __addr40 uint32_t *)&(_flow_key_dup[index]);

    mem_read_atomic(&key, _pif_hdrptr, sizeof(key));

    return key[0] == flow.src_ip &&
           key[1] == flow.dst_ip &&
           key[2] == flow.sampling_rate &&
           key[3] == flow.agent_ip &&
           key[4] == (((uint32_t)flow.in_if << 16) | flow.out_if) &&
           key[5] == (((uint32_t)flow.src_port << 16) | flow.dst_port) &&
           key[6] == flow.protocol;
}

static __intrinsic void storing_data(
    uint32_t pif_index,
    struct stored_flow_key flow,
    uint32_t frame_length,
    struct mac_time_data sample_time)
{
    __mem __addr40 uint32_t *_pif_hdrptr;
    __xrw uint32_t xfer;
    uint32_t state_tmp = acquire_storage_state();
    uint16_t cnt = 0;

    while (1)
    {
        xfer = WRITTEN_STATE;
        _pif_hdrptr = (state_tmp == 0) ?
            (__mem __addr40 uint32_t *)&global_semaphores[pif_index] :
            (__mem __addr40 uint32_t *)&global_semaphores_dup[pif_index];
        mem_test_set(&xfer, _pif_hdrptr, sizeof(xfer));
        if (xfer == NO_ONE_STATE)
        { // no one occupy this slot, can write data.
            write_first_data_to_mem(pif_index, flow, frame_length,
                                    sample_time, state_tmp);
            xfer = FINISH_STATE;
            mem_test_set(&xfer, _pif_hdrptr, sizeof(xfer)); // set to finish state, so that other can read the data and know that the data is ready.
            processing_me_leave(state_tmp);
            break;
        }
        else if ((xfer & WRITTEN_STATE) == WRITTEN_STATE && (xfer & FINISH_STATE) == 0)
        { // other is writting this slot.
            sleep(50);
            continue;
        }
        if (read_and_check(pif_index, flow, state_tmp))
        {
            write_data_to_mem(pif_index, flow, frame_length,
                              sample_time, state_tmp);
            processing_me_leave(state_tmp);
            break;
        }
        else
        {
            pif_index = (pif_index + 1) % HASH_SIZE;
        }
        cnt += 1;
        if (cnt > HASH_SIZE)
        {
            processing_me_leave(state_tmp);
            break;
        }
    }
}

static __intrinsic uint32_t hash_add(uint32_t hash, uint16_t value)
{
    hash += value;
    hash += (hash << 10);
    hash ^= (hash >> 6);

    return hash;
}

static __intrinsic uint32_t hash_function(struct stored_flow_key key)
{
    uint32_t hash = 0;

    hash = hash_add(hash, key.src_ip >> 16);
    hash = hash_add(hash, key.src_ip);
    hash = hash_add(hash, key.dst_ip >> 16);
    hash = hash_add(hash, key.dst_ip);
    hash = hash_add(hash, key.sampling_rate >> 16);
    hash = hash_add(hash, key.sampling_rate);
    hash = hash_add(hash, key.agent_ip >> 16);
    hash = hash_add(hash, key.agent_ip);
    hash = hash_add(hash, key.in_if);
    hash = hash_add(hash, key.out_if);
    hash = hash_add(hash, key.src_port);
    hash = hash_add(hash, key.dst_port);
    hash = hash_add(hash, key.protocol >> 16);
    hash = hash_add(hash, key.protocol);

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash;
}

int pif_plugin_update_frame2(EXTRACTED_HEADERS_T *headers, MATCH_DATA_T *data)
{
    PIF_PLUGIN_sflow_sample2_T *sflow_sample2;
    PIF_PLUGIN_sflow_header_T *sflow_header;
    uint32_t _pif_index;
    uint32_t frame_length;
    struct stored_flow_key flow;
    struct mac_time_data sample_time;

    sflow_sample2 = pif_plugin_hdr_get_sflow_sample2(headers);
    sflow_header = pif_plugin_hdr_get_sflow_header(headers);

    frame_length = PIF_HEADER_GET_sflow_sample2___frame_length(sflow_sample2);
    sample_time = get_current_mac_time();

    flow.src_ip = PIF_HEADER_GET_sflow_sample2___srcIP(sflow_sample2);
    flow.dst_ip = PIF_HEADER_GET_sflow_sample2___dstIP(sflow_sample2);
    flow.src_port = PIF_HEADER_GET_sflow_sample2___srcPort(sflow_sample2);
    flow.dst_port = PIF_HEADER_GET_sflow_sample2___dstPort(sflow_sample2);
    flow.protocol = (uint32_t)PIF_HEADER_GET_sflow_sample2___protocol(sflow_sample2);
    flow.sampling_rate = PIF_HEADER_GET_sflow_sample2___sample_rate(sflow_sample2);
    flow.agent_ip = PIF_HEADER_GET_sflow_header___agent_ip(sflow_header);
    flow.in_if = PIF_HEADER_GET_sflow_sample2___in_port(sflow_sample2);
    flow.out_if = PIF_HEADER_GET_sflow_sample2___out_port(sflow_sample2);
    flow.tcp_flag = (uint32_t)PIF_HEADER_GET_sflow_sample2___tcp_flag(sflow_sample2);

    _pif_index = hash_function(flow) % HASH_SIZE;
    storing_data(_pif_index, flow, frame_length, sample_time);
    return PIF_PLUGIN_RETURN_FORWARD;
}

int pif_plugin_update_frame(EXTRACTED_HEADERS_T *headers, MATCH_DATA_T *data)
{
    PIF_PLUGIN_sflow_sample_T *sflow_sample;
    PIF_PLUGIN_sflow_header_T *sflow_header;
    uint32_t _pif_index;
    uint32_t frame_length;
    struct stored_flow_key flow;
    struct mac_time_data sample_time;

    // _pif_index = pif_plugin_meta_get__hash_index__val(headers);
    sflow_sample = pif_plugin_hdr_get_sflow_sample(headers);
    sflow_header = pif_plugin_hdr_get_sflow_header(headers);

    frame_length = PIF_HEADER_GET_sflow_sample___frame_length(sflow_sample);
    sample_time = get_current_mac_time();

    flow.src_ip = PIF_HEADER_GET_sflow_sample___srcIP(sflow_sample);
    flow.dst_ip = PIF_HEADER_GET_sflow_sample___dstIP(sflow_sample);
    flow.src_port = PIF_HEADER_GET_sflow_sample___srcPort(sflow_sample);
    flow.dst_port = PIF_HEADER_GET_sflow_sample___dstPort(sflow_sample);
    flow.protocol = (uint32_t)PIF_HEADER_GET_sflow_sample___protocol(sflow_sample);
    flow.sampling_rate = PIF_HEADER_GET_sflow_sample___sample_rate(sflow_sample);
    flow.agent_ip = PIF_HEADER_GET_sflow_header___agent_ip(sflow_header);
    flow.in_if = PIF_HEADER_GET_sflow_sample___in_port(sflow_sample);
    flow.out_if = PIF_HEADER_GET_sflow_sample___out_port(sflow_sample);
    flow.tcp_flag = (uint32_t)PIF_HEADER_GET_sflow_sample___tcp_flag(sflow_sample);

    _pif_index = hash_function(flow) % HASH_SIZE;
    storing_data(_pif_index, flow, frame_length, sample_time);
    return PIF_PLUGIN_RETURN_FORWARD;
}
