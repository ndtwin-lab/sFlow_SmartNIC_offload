#include <stdlib.h>
#include <pif_plugin.h>
#include <pif_plugin_metadata.h>
#include <pif_common.h>
#include <pif_headers.h>
#include <memory.h>
#include <string.h>
#include <stdint.h>
#include <nfp.h>
#include <nfp/me.h>
#include <nfp/mem_bulk.h>
#include <nfp6000/nfp_me.h>
#include <nfp/mem_atomic.h>
#include <pkt/pkt.h>

#define HASH_SIZE 20000 // can be 16,384, 2^15 so that mod can use "&" .
#define NO_ONE_STATE 0x00000000
#define WRITTEN_STATE 0x00000001
#define FINISH_STATE 0x00000002
#define CHANGE_STORAGE_STATE 0x00000004
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
    uint16_t protocol : 16;
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
    uint16_t protocol : 16;
    uint16_t tcp_flag : 16;
};

struct flow_data
{
    struct stored_flow_key key;
    uint32_t frame_length : 32;
};

volatile __export __emem uint32_t global_semaphores[HASH_SIZE];
__export __emem __align256 struct flow_data _flow_data[HASH_SIZE];
volatile __export __emem uint32_t global_semaphores_dup[HASH_SIZE];
__export __emem __align256 struct flow_data _flow_data_dup[HASH_SIZE];
__export __emem __align256 uint32_t _cur_state;

void write_first_data_to_mem(uint32_t *index, struct flow_data *flow, uint32_t *state)
{
    __mem __addr40 uint32_t *_pif_hdrptr = (__mem __addr40 uint32_t *)&(_flow_data[*index]);
    if(*state == 1){
        _pif_hdrptr = (__mem __addr40 uint32_t *)&(_flow_data_dup[*index]);
    }

    {
        __xwrite struct stored_flow_key _pif_wreg = flow->key;
        mem_write_atomic(&_pif_wreg, _pif_hdrptr, sizeof(struct stored_flow_key));
    }
    {
        __xwrite uint32_t _pif_wreg = flow->frame_length;
        _pif_hdrptr += 7;
        mem_write_atomic(&_pif_wreg, _pif_hdrptr, 4);
    }
}


void write_data_to_mem(uint32_t *index, struct flow_data *flow, uint32_t *state)
{
    __mem __addr40 uint32_t *_pif_hdrptr = (__mem __addr40 uint32_t *)&(_flow_data[*index]);
    if(*state == 1){
        _pif_hdrptr = (__mem __addr40 uint32_t *)&(_flow_data_dup[*index]);
    }
    // update data.
    {
        __xwrite uint32_t _pif_wreg = flow->frame_length;
        mem_add32(&_pif_wreg, _pif_hdrptr + 7, 4);
    }
    {
        __xwrite uint32_t _pif_wreg = (flow->key.protocol<<16) | flow->key.tcp_flag;
        mem_bitset(&_pif_wreg, _pif_hdrptr + 6, 4);
        // __xwrite uint16_t _pif_wreg_16 = flow->key.tcp_flag;
        // mem_write_atomic(&_pif_wreg_16, _pif_hdrptr + 6, 4);
    }
}


uint8_t read_and_check(uint32_t *index, struct flow_data *flow, uint32_t *state)
{
    __lmem struct flow_key old_flow;
    __lmem struct flow_key empty;
    __xread struct flow_key key;
    __mem __addr40 uint32_t *_pif_hdrptr = (__mem __addr40 uint32_t *)&(_flow_data[*index]);
    __lmem struct stored_flow_key cur_flow = flow->key;

    if(*state == 1){
        _pif_hdrptr = (__mem __addr40 uint32_t *)&(_flow_data_dup[*index]);
    }
    
    mem_read_atomic(&key, _pif_hdrptr, sizeof(struct flow_key));

    old_flow = key;

    if(memcmp_lmem_lmem(&old_flow, &empty, sizeof(struct flow_key) - 4) == 0)
    {
        return 2; // this slot is empty, means change to dup.
    }

    if (memcmp_lmem_lmem(&old_flow, &cur_flow, sizeof(struct flow_key) - 4) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void collision_handler(uint32_t *index)
{
    // linear probing.
    *index = ((*index) + 1) % HASH_SIZE;
    // complex probing algorithm.
}

void storing_data(uint32_t *_pif_index, struct flow_data *flow)
{
    __mem __addr40 uint32_t *_pif_hdrptr;
    __xrw uint32_t xfer;
    __xread uint32_t xfer3;
    __xwrite uint32_t xfer4;
    uint32_t original_index = *_pif_index;
    uint32_t state_tmp;
    uint16_t cnt = 0;
    uint32_t check_result = 0;
    while (1)
    {
        xfer = WRITTEN_STATE;
        mem_read_atomic(&xfer3, (__mem __addr40 uint32_t *)&_cur_state, sizeof(xfer3));
        state_tmp = xfer3;
        _pif_hdrptr = (__mem __addr40 uint32_t *)&global_semaphores[*_pif_index];
        if(state_tmp == 1){
            _pif_hdrptr = (__mem __addr40 uint32_t *)&global_semaphores_dup[*_pif_index];
        }
        mem_test_set(&xfer, _pif_hdrptr, sizeof(xfer));
        if (xfer == NO_ONE_STATE)
        { // no one occupy this slot, can write data.
            // write data.
            write_first_data_to_mem(_pif_index, flow, &state_tmp);
            // exit.
            xfer = FINISH_STATE;
            mem_test_set(&xfer, _pif_hdrptr, sizeof(xfer)); // set to finish state, so that other can read the data and know that the data is ready.
            break;
        }
        else if ((xfer & WRITTEN_STATE) == WRITTEN_STATE && (xfer & FINISH_STATE) == 0 && (xfer & CHANGE_STORAGE_STATE) == 0)
        { // other is writting this slot.
            sleep(500);
            // read the data and check if it is the same flow, if it is the same flow, then update the data, otherwise, increase the _pif_index and try again.
            // for optimization, this condition only need to sleep.
            check_result = read_and_check(_pif_index, flow, &state_tmp);
            if (check_result == 1)
            {
                write_data_to_mem(_pif_index, flow, &state_tmp);
                break;
            }
            else if (check_result == 2)
            {
                *_pif_index = original_index;
            }
            else
            {
                // do linear probing.
                collision_handler(_pif_index);
            }
        }
        else if ((xfer & FINISH_STATE) == FINISH_STATE && (xfer & CHANGE_STORAGE_STATE) == 0)
        { // other is reading this slot, can not write data, but can wait for a while and try again.
            check_result = read_and_check(_pif_index, flow, &state_tmp);

            if (check_result == 1)
            {
                write_data_to_mem(_pif_index, flow, &state_tmp);
                break;
            }
            else if (check_result == 2)
            {
                *_pif_index = original_index;
            }
            else
            {
                // do linear probing.
                collision_handler(_pif_index);
            }
        }
        else if ((xfer & CHANGE_STORAGE_STATE) == CHANGE_STORAGE_STATE)
        { // need to change storage, restore the original index and try again.
            *_pif_index = original_index;
            if(state_tmp == 0){
                xfer4 = 1;
            }else{
                xfer4 = 0;
            }

            mem_write_atomic(&xfer4, (__mem __addr40 uint32_t *)&_cur_state, sizeof(xfer3));
            cnt = 0;
            continue;
        }
        cnt += 1;
        if (cnt > HASH_SIZE)
        {
            break;
        }
    }
}

#define FLOW_LENGTH_OFFSET 13

uint32_t hash_function(struct stored_flow_key *key)
{

    uint16_t *val = (uint16_t *)key;
    uint32_t hash = 0;
    uint32_t i;
    
    for (i = 0; i < FLOW_LENGTH_OFFSET; i++) {
        hash += val[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    
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
    struct flow_data flow;

    // _pif_index = pif_plugin_meta_get__hash_index__val(headers);
    sflow_sample2 = pif_plugin_hdr_get_sflow_sample2(headers);
    sflow_header = pif_plugin_hdr_get_sflow_header(headers);
    flow.frame_length = PIF_HEADER_GET_sflow_sample2___frame_length(sflow_sample2);
    flow.key.src_ip = PIF_HEADER_GET_sflow_sample2___srcIP(sflow_sample2);
    flow.key.dst_ip = PIF_HEADER_GET_sflow_sample2___dstIP(sflow_sample2);
    flow.key.src_port = PIF_HEADER_GET_sflow_sample2___srcPort(sflow_sample2);
    flow.key.dst_port = PIF_HEADER_GET_sflow_sample2___dstPort(sflow_sample2);
    flow.key.protocol = PIF_HEADER_GET_sflow_sample2___protocol(sflow_sample2);
    flow.key.sampling_rate = PIF_HEADER_GET_sflow_sample2___sample_rate(sflow_sample2);
    flow.key.agent_ip = PIF_HEADER_GET_sflow_header___agent_ip(sflow_header);
    flow.key.in_if = PIF_HEADER_GET_sflow_sample2___in_port(sflow_sample2);
    flow.key.out_if = PIF_HEADER_GET_sflow_sample2___out_port(sflow_sample2);
    flow.key.tcp_flag = PIF_HEADER_GET_sflow_sample2___tcp_flag(sflow_sample2);

    _pif_index = flow.key.src_ip % HASH_SIZE;//hash_function(&flow.key) % HASH_SIZE;
    storing_data(&_pif_index, &flow);
    return PIF_PLUGIN_RETURN_FORWARD;
}

int pif_plugin_update_frame(EXTRACTED_HEADERS_T *headers, MATCH_DATA_T *data)
{
    PIF_PLUGIN_sflow_sample_T *sflow_sample;
    PIF_PLUGIN_sflow_header_T *sflow_header;
    uint32_t _pif_index;
    struct flow_data flow;

    // _pif_index = pif_plugin_meta_get__hash_index__val(headers);
    sflow_sample = pif_plugin_hdr_get_sflow_sample(headers);
    sflow_header = pif_plugin_hdr_get_sflow_header(headers);
    flow.frame_length = PIF_HEADER_GET_sflow_sample___frame_length(sflow_sample);
    flow.key.src_ip = PIF_HEADER_GET_sflow_sample___srcIP(sflow_sample);
    flow.key.dst_ip = PIF_HEADER_GET_sflow_sample___dstIP(sflow_sample);
    flow.key.src_port = PIF_HEADER_GET_sflow_sample___srcPort(sflow_sample);
    flow.key.dst_port = PIF_HEADER_GET_sflow_sample___dstPort(sflow_sample);
    flow.key.protocol = PIF_HEADER_GET_sflow_sample___protocol(sflow_sample);
    flow.key.sampling_rate = PIF_HEADER_GET_sflow_sample___sample_rate(sflow_sample);
    flow.key.agent_ip = PIF_HEADER_GET_sflow_header___agent_ip(sflow_header);
    flow.key.in_if = PIF_HEADER_GET_sflow_sample___in_port(sflow_sample);
    flow.key.out_if = PIF_HEADER_GET_sflow_sample___out_port(sflow_sample);
    flow.key.tcp_flag = PIF_HEADER_GET_sflow_sample___tcp_flag(sflow_sample);

    _pif_index = flow.key.src_ip % HASH_SIZE;//hash_function(&flow.key) % HASH_SIZE;
    storing_data(&_pif_index, &flow);
    return PIF_PLUGIN_RETURN_FORWARD;
}