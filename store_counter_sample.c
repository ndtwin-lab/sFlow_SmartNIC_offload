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

#define HASH_SIZE2 2048 // can be 16,384, 2^15 so that mod can use "&" .
#define NO_ONE_STATE 0x00000000
#define WRITTEN_STATE 0x00000001
#define FINISH_STATE 0x00000002
#define COUNTER_COMPARE_WORDS 8
// for test > using the below method  to count how many packets and store the val in reg.

struct counter_data
{
    uint32_t agent_ip : 32;
    uint32_t if_idx : 32;
    uint32_t in_octets_0 : 32;
    uint32_t in_octets_1 : 32;
    uint32_t out_octets_0 : 32;
    uint32_t out_octets_1 : 32;
    uint32_t if_speed_0 : 32;
    uint32_t if_speed_1 : 32;
};


volatile __export __emem uint32_t cglobal_semaphores[HASH_SIZE2];
__export __emem __align256 struct counter_data _counter_data[HASH_SIZE2];

void cwrite_data_to_mem(uint32_t *index, __mem struct counter_data *counter)
{
    __mem __addr40 uint32_t *_pif_hdrptr = (__mem __addr40 uint32_t *)&(_counter_data[*index]);

    {
        __xwrite struct counter_data _pif_wreg = *counter;
        mem_write_atomic(&_pif_wreg, _pif_hdrptr, sizeof(struct counter_data));
    }
}

uint8_t cread_and_check(uint32_t *index, __mem struct counter_data *counter)
{
    __lmem struct counter_data old_counter;
    __xread struct counter_data key;
    __mem __addr40 uint32_t *_pif_hdrptr = (__mem __addr40 uint32_t *)&(_counter_data[*index]);
    
    mem_read_atomic(&key, _pif_hdrptr, sizeof(struct counter_data));

    old_counter = key;

    if (memcmp_lmem_mem(&old_counter, counter, sizeof(struct counter_data)) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void ccollision_handler(uint32_t *index)
{
    // linear probing.
    *index = ((*index) + 1) % HASH_SIZE2;
    // complex probing algorithm.
}

void cstoring_data(uint32_t *_pif_index, __mem struct counter_data *counter)
{
    __mem __addr40 uint32_t *_pif_hdrptr;
    __xrw uint32_t xfer;
    uint16_t cnt = 0;
    while (1)
    {
        xfer = WRITTEN_STATE;
        _pif_hdrptr = (__mem __addr40 uint32_t *)&cglobal_semaphores[*_pif_index];
        mem_test_set(&xfer, _pif_hdrptr, sizeof(xfer));
        if (xfer == NO_ONE_STATE)
        { // no one occupy this slot, can write data.
            // write data.
            cwrite_data_to_mem(_pif_index, counter);
            // exit.
            xfer = FINISH_STATE;
            mem_test_set(&xfer, _pif_hdrptr, sizeof(xfer)); // set to finish state, so that other can read the data and know that the data is ready.
            break;
        }
        else if ((xfer & WRITTEN_STATE) == WRITTEN_STATE && (xfer & FINISH_STATE) == 0 )
        { // other is writting this slot.
            sleep(50);
            // read the data and check if it is the same flow, if it is the same flow, then update the data, otherwise, increase the _pif_index and try again.
            // for optimization, this condition only need to sleep.
            if (cread_and_check(_pif_index, counter))
            {
                cwrite_data_to_mem(_pif_index, counter);
                break;
            }
            else
            {
                // do linear probing.
                ccollision_handler(_pif_index);
            }
        }
        else if ((xfer & FINISH_STATE) == FINISH_STATE )
        { // other is reading this slot, can not write data, but can wait for a while and try again.
            if (cread_and_check(_pif_index, counter))
            {
                cwrite_data_to_mem(_pif_index, counter);
                break;
            }
            else
            {
                // do linear probing.
                ccollision_handler(_pif_index);
            }
        }else{
            break;
        }
        cnt += 1;
        if (cnt > HASH_SIZE2)
        {
            break;
        }
    }
}

#define FLOW_LENGTH_OFFSET2 4

uint32_t hash_function2(__mem struct counter_data *cnt)
{

    uint16_t *val = (uint16_t *)cnt;
    uint32_t hash = 0;
    uint32_t i;
    
    for (i = 0; i < FLOW_LENGTH_OFFSET2; i++) {
        hash += val[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    
    return hash;
}


int pif_plugin_update_counter2(EXTRACTED_HEADERS_T *headers, MATCH_DATA_T *data)
{
    PIF_PLUGIN_sflow_counter2_T *sflow_counter2;
    PIF_PLUGIN_sflow_header_T *sflow_header;
    uint32_t _pif_index;
    __mem struct counter_data counter;

    sflow_counter2 = pif_plugin_hdr_get_sflow_counter2(headers);
    sflow_header = pif_plugin_hdr_get_sflow_header(headers);
    counter.agent_ip = PIF_HEADER_GET_sflow_header___agent_ip(sflow_header);
    counter.if_idx = PIF_HEADER_GET_sflow_counter2___g_if(sflow_counter2);
    counter.in_octets_0 = PIF_HEADER_GET_sflow_counter2___g_in_octets___0(sflow_counter2);
    counter.in_octets_1 = PIF_HEADER_GET_sflow_counter2___g_in_octets___1(sflow_counter2);
    counter.out_octets_0 = PIF_HEADER_GET_sflow_counter2___g_out_octets___0(sflow_counter2);
    counter.out_octets_1 = PIF_HEADER_GET_sflow_counter2___g_out_octets___1(sflow_counter2);
    counter.if_speed_0 = PIF_HEADER_GET_sflow_counter2___g_speed___0(sflow_counter2);
    counter.if_speed_1 = PIF_HEADER_GET_sflow_counter2___g_speed___1(sflow_counter2);

    _pif_index = hash_function2(&counter) % HASH_SIZE2;//counter.agent_ip % HASH_SIZE2; // can use more complex hash function, and also can use the hash value calculated in the parser.
    cstoring_data(&_pif_index, &counter);
    return PIF_PLUGIN_RETURN_FORWARD;
}

int pif_plugin_update_counter(EXTRACTED_HEADERS_T *headers, MATCH_DATA_T *data)
{
    PIF_PLUGIN_sflow_counter_T *sflow_counter;
    PIF_PLUGIN_sflow_header_T *sflow_header;
    uint32_t _pif_index;
    __mem struct counter_data counter;

    sflow_counter = pif_plugin_hdr_get_sflow_counter(headers);
    sflow_header = pif_plugin_hdr_get_sflow_header(headers);
    counter.agent_ip = PIF_HEADER_GET_sflow_header___agent_ip(sflow_header);
    counter.if_idx = PIF_HEADER_GET_sflow_counter___g_if(sflow_counter);
    counter.in_octets_0 = PIF_HEADER_GET_sflow_counter___g_in_octets___0(sflow_counter);
    counter.in_octets_1 = PIF_HEADER_GET_sflow_counter___g_in_octets___1(sflow_counter);
    counter.out_octets_0 = PIF_HEADER_GET_sflow_counter___g_out_octets___0(sflow_counter);
    counter.out_octets_1 = PIF_HEADER_GET_sflow_counter___g_out_octets___1(sflow_counter);
    counter.if_speed_0 = PIF_HEADER_GET_sflow_counter___g_speed___0(sflow_counter);
    counter.if_speed_1 = PIF_HEADER_GET_sflow_counter___g_speed___1(sflow_counter);

    _pif_index = hash_function2(&counter) % HASH_SIZE2;//counter.agent_ip % HASH_SIZE2; // can use more complex hash function, and also can use the hash value calculated in the parser.
    cstoring_data(&_pif_index, &counter);
    return PIF_PLUGIN_RETURN_FORWARD;

}
