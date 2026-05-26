/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_FIELD_LISTS_H__
#define __PIF_FIELD_LISTS_H__

/* Generated C source defining layout of field lists in memory */
/* Warning: your edits to this file may be lost */

struct pif_field_list_parse_next {
    union {
        struct {
            unsigned int _padding_0:16;
            /* recirculate_fl.recirculate_count[8;0] */
            unsigned int __recirculate_fl__recirculate_count:8;
            /* recirculate_fl.fl[8;0] */
            unsigned int __recirculate_fl__fl:8;
        };
        uint32_t _raw[1];
    };
};

struct pif_field_list_parse_next_packed {
    union {
        __packed struct {
            /* recirculate_fl.recirculate_count[8;0] */
            unsigned int __recirculate_fl__recirculate_count:8;
            /* recirculate_fl.fl[8;8] */
            unsigned int __recirculate_fl__fl:8;
            unsigned int _padding:16;
        };
        uint32_t _raw[1];
    };
};

#endif /* __PIF_FIELD_LISTS_H__ */
