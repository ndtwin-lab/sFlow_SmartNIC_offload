#define ETHERTYPE_IPV4 0x0800
#define ETHERTYPE_ARP 0x0806
#define SFLOW_UDP_PORT 6343
#define IPPROTO_UDP 17
#define IPPROTO_TCP 6

#define HASH_SIZE 10
#define HASH_SIZE2 10

/*===========================================================*/
/*======================= Header Part =======================*/
/*===========================================================*/

header_type eth_hdr
{
    fields
    {
    dst:
        48;
    src:
        48;
    etype:
        16;
    }
}

header_type ipv4_t
{
    fields
    {
    version:
        4;
    ihl:
        4;
    diffserv:
        8;
    totalLen:
        16;
    identification:
        16;
    flags:
        3;
    fragOffset:
        13;
    ttl:
        8;
    protocol:
        8;
    hdrChecksum:
        16;
    srcAddr:
        32;
    dstAddr:
        32;
    }
}

header_type udp_t
{
    fields
    {
    sport:
        16;
    dport:
        16;
    len:
        16;
    checksum:
        16;
    }
}

header_type sflow_header_t
{
    fields
    {
    version:
        32;
    agent_type:
        32;
    agent_ip:
        32;
    agent_id:
        32;
    seq_num:
        32;
    uptime:
        32;
    num_samples:
        32;
    }
}

// parser can parse 2 sample per circulate. Thus, total 4 times of recirculate is needed.
// maybe to use stack architecture.
// It is because one typical sflow sample header can be up to 216 bytes, and the parser can only parse 500 bytes.

header_type sflow_sample_header_t
{ // First layer, since one packet will not have counter and flow at the same time, we can use one header to parse both of them. And the sample_type field can be used to distinguish them.
    fields
    {
    sample_type:
        32;
    sample_length:
        32;
    }
}

header_type sflow_sample_t
{
    fields
    {
    in_port:
        16;
    out_port:
        16;
    sample_rate:
        32;
    eth_type:
        32;
    frame_length:
        16;
    protocol:
        16;
    srcIP:
        32;
    dstIP:
        32;
    ip_flag:
        16;
    tcp_flag:
        16;
    srcPort:
        16;
    dstPort:
        16;
    }
}

header_type sflow_counter_t
{
    fields
    {
    seqnum:
        32;
    id_index:
        32;
    counter_records:
        32;
    // do not care
    eth_foramt:
        32;
    eth_data_len:
        32;
    alig_err:
        32;
    fcs_err:
        32;
    single_collision:
        32;
    multi_collision:
        32;
    sqe_err:
        32;
    deffered:
        32;
    late_collision:
        32;
    excessive_collision:
        32;
    imt_err:
        32;
    carrier_err:
        32;
    frame_err:
        32;
    imr_err:
        32;
    symbol_err:
        32;
    // do not care
    g_format:
        32;
    g_data_len:
        32;
    g_if:
        32;
    g_type:
        32;
    g_speed:
        64;
    g_if_direction:
        32;
    g_if_status:
        32;
    g_in_octets:
        64;
    g_in_pkts:
        32;
    g_in_multicast_pkts:
        32;
    g_in_broadcast_pkts:
        32;
    g_in_discards:
        32;
    g_in_errors:
        32;
    g_in_unknown_protos:
        32;
    g_out_octets:
        64;
    g_out_pkts:
        32;
    g_out_multicast_pkts:
        32;
    g_out_broadcast_pkts:
        32;
    g_out_discards:
        32;
    g_out_errors:
        32;
    g_promiscuous_mode:
        32;
    }
}

header_type sflow_counter2_t
{
    fields
    {
    sample_type:
        32;
    sample_length:
        32;
    seqnum:
        32;
    id_index:
        32;
    counter_records:
        32;
    // do not care
    eth_foramt:
        32;
    eth_data_len:
        32;
    alig_err:
        32;
    fcs_err:
        32;
    single_collision:
        32;
    multi_collision:
        32;
    sqe_err:
        32;
    deffered:
        32;
    late_collision:
        32;
    excessive_collision:
        32;
    imt_err:
        32;
    carrier_err:
        32;
    frame_err:
        32;
    imr_err:
        32;
    symbol_err:
        32;
    // do not care
    g_format:
        32;
    g_data_len:
        32;
    g_if:
        32;
    g_type:
        32;
    g_speed:
        64;
    g_if_direction:
        32;
    g_if_status:
        32;
    g_in_octets:
        64;
    g_in_pkts:
        32;
    g_in_multicast_pkts:
        32;
    g_in_broadcast_pkts:
        32;
    g_in_discards:
        32;
    g_in_errors:
        32;
    g_in_unknown_protos:
        32;
    g_out_octets:
        64;
    g_out_pkts:
        32;
    g_out_multicast_pkts:
        32;
    g_out_broadcast_pkts:
        32;
    g_out_discards:
        32;
    g_out_errors:
        32;
    g_promiscuous_mode:
        32;
    }
}

header_type sflow_sample2_t
{
    fields
    {
        sample_type:
        32;
    sample_length:
        32;
    in_port:
        16;
    out_port:
        16;
    sample_rate:
        32;
    eth_type:
        32;
    frame_length:
        16;
    protocol:
        16;
    srcIP:
        32;
    dstIP:
        32;
    ip_flag:
        16;
    tcp_flag:
        16;
    srcPort:
        16;
    dstPort:
        16;
    }
}

header_type num_metadata_t
{
    fields
    {
    cur_num:
        8; // trace current smaple number
    }
}


header_type recirculate_fl_t{
    fields{
        recirculate_count: 8;
        fl : 8;
    }
}

primitive_action update_frame();
primitive_action update_frame2();
primitive_action update_counter2();
primitive_action update_counter();

header eth_hdr eth;
header ipv4_t ipv4;
header udp_t udp;
header sflow_header_t sflow_header; // max two smaple header to extract
header sflow_sample_header_t sflow_sample_header;

header sflow_counter_t sflow_counter;
header sflow_counter2_t sflow_counter2;

header sflow_sample_t sflow_sample;
header sflow_sample2_t sflow_sample2;

metadata num_metadata_t num_metadata;
metadata recirculate_fl_t recirculate_fl;


field_list parse_next{
    recirculate_fl.recirculate_count;
    recirculate_fl.fl;
}


@pragma netro no_lookup_caching



/*===========================================================*/
/*======================= Parser Part =======================*/
/*===========================================================*/

parser start
{
    return eth_parse;
}

parser eth_parse
{
    extract(eth);
    return select(eth.etype)
    {
    ETHERTYPE_IPV4:
        parse_ipv4;
    default:
        ingress;
    }
}

parser parse_ipv4
{
    extract(ipv4);
    return select(ipv4.protocol)
    {
    IPPROTO_UDP:
        parse_udp;
    default:
        ingress;
    }
}

parser parse_udp
{
    extract(udp);
    return select(udp.dport)
    {
    SFLOW_UDP_PORT:
        parse_sflow_header;
    default:
        ingress;
    }
}


parser parse_sflow_header
{
    extract(sflow_header);
    set_metadata(num_metadata.cur_num, sflow_header.num_samples);
    return select(num_metadata.cur_num)
    {
        0 : ingress;
    default:
        parse_sflow_sample_header;
    }
}

parser parse_sflow_sample_header
{
    extract(sflow_sample_header);
    return select(sflow_sample_header.sample_type)
    {
        2 : parse_sflow_counter;
        5 : parse_sflow_sample;
        default: ingress;
    }
}

parser parse_sflow_counter
{
    extract(sflow_counter);
    return select(num_metadata.cur_num)
    {
        1 : ingress;
    default:
        parse_sflow_counter_2;
    }
}

parser parse_sflow_counter_2
{
    extract(sflow_counter2);
    return ingress;
}

parser parse_sflow_sample
{
    extract(sflow_sample);
    return select(num_metadata.cur_num)
    {
        1 : ingress;
    default:
        parse_sflow_sample_2;
    }
}

parser parse_sflow_sample_2
{
    extract(sflow_sample2);
    return ingress;
}

/*===========================================================*/
/*======================= Action part =======================*/
/*===========================================================*/

action drop_act()
{
    drop();
}

action frecord1st()
{
    // modify_field_with_hash_based_offset(hash_index.val, 0, five_tuple_hash, HASH_SIZE);

    // record data
    update_frame();

    subtract_from_field(sflow_header.num_samples,1);
}

action frecord2nd()
{
    // modify_field_with_hash_based_offset(hash_index.val, 0, five_tuple2_hash, HASH_SIZE);

    // record data
    update_frame2();

    // record data
    subtract_from_field(sflow_header.num_samples,1);
}



action forward(espec)
{
    modify_field(standard_metadata.egress_spec, espec);
}


action counter_record()
{
    // modify_field_with_hash_based_offset(hash_index.val, 0, counter_tuple_hash, HASH_SIZE2);

    update_counter();
    subtract_from_field(sflow_header.num_samples,1);
}

action counter_record2()
{
    // modify_field_with_hash_based_offset(hash_index.val, 0, counter_tuple2_hash, HASH_SIZE2);

    update_counter2();
    subtract_from_field(sflow_header.num_samples,1);
}

action need_recirculate(espec)
{
    counter_record();
    counter_record2();

    modify_field(standard_metadata.egress_spec, espec); // must have
}

action stop_recirculate2(){
    counter_record();
    counter_record2();
    
    drop();
}

action stop_recirculate1(){
    counter_record();
    
    drop(); //
}

action do_recirculate()
{   
    remove_header(sflow_sample_header);
    remove_header(sflow_counter);
    remove_header(sflow_counter2);
    recirculate(parse_next);
}

action num_decrement(espec){
    subtract_from_field(sflow_header.num_samples,1);
    modify_field(standard_metadata.egress_spec, espec); // must have
}

action record_flow1(espec)
{
    frecord1st();
    modify_field(standard_metadata.egress_spec, espec); // must have
}

action record_flow2(espec)
{
    frecord2nd();
    modify_field(standard_metadata.egress_spec, espec); // must have
}

action stop_flow1()
{
    frecord1st();
    //drop(); //* will drop it immediately.
}

action stop_flow2()
{
    frecord2nd();
    drop();
}

action fdo_recirculate()
{   
    remove_header(sflow_sample_header);
    remove_header(sflow_sample);
    remove_header(sflow_sample2);
    recirculate(parse_next);
}

/*==========================================================*/
/*======================= Table part =======================*/
/*==========================================================*/

table no_record_flow1
{
    reads
    {
        num_metadata.cur_num : exact;
    }
    actions
    {
        num_decrement;

        drop_act;
    }
}

table no_record_flow2
{
    reads
    {
        num_metadata.cur_num : exact;
    }
    actions
    {
        num_decrement;
        drop_act;
    }
}

table record_flow1
{
    reads
    {
        num_metadata.cur_num : exact;
    }
    actions
    {
        record_flow1;
        stop_flow1;
    }
}

table record_flow2
{
    reads
    {
        num_metadata.cur_num : exact;
    }
    actions
    {
        record_flow2;
        stop_flow2;
    }
}

table in_tbl2
{
    reads
    {
        num_metadata.cur_num : exact;
    }
    actions
    {
        need_recirculate;
        stop_recirculate2;
        stop_recirculate1;
    }
}

table nor_tbl
{
    reads
    {
        standard_metadata.ingress_port : exact;
    }
    actions
    {
        forward;
        drop_act;
    }
}

table t_do_recirculate{
    actions {do_recirculate;}
}

table t_do_frecirculate{
    actions {fdo_recirculate;}
}

/*============================================================*/
/*======================= Ingress part =======================*/
/*============================================================*/

control ingress
{

    if (valid(udp) and udp.dport == SFLOW_UDP_PORT)
    {
        if (valid(sflow_counter))
        {
            apply(in_tbl2);
        }else
        {
            if(valid(sflow_sample) and sflow_sample.ip_flag&0b0001111111111111 == 0 and sflow_sample.eth_type !=  ETHERTYPE_ARP){
                apply(record_flow1);
            }else if(valid(sflow_sample)){
                apply(no_record_flow1);
            }

            if(valid(sflow_sample2) and sflow_sample2.ip_flag&0b0001111111111111 == 0 and sflow_sample.eth_type != ETHERTYPE_ARP){
                apply(record_flow2);
            }else if(valid(sflow_sample2)){
                apply(no_record_flow2);
            }
        }
    }
    else
    {
        apply(nor_tbl);
    }
}

/*===========================================================*/
/*======================= Egress part =======================*/
/*===========================================================*/

control egress
{
    if(valid(sflow_counter)){
        if(num_metadata.cur_num > 2){
            apply(t_do_recirculate);
        }
    }
    if(valid(sflow_sample)){
        if(num_metadata.cur_num > 2){
            apply(t_do_frecirculate);
        }
    }
}