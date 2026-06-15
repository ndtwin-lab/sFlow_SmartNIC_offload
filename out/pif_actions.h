/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_ACTIONS_H__
#define __PIF_ACTIONS_H__

/* Warning: generated file - your edits to this file may be lost */

/* Action operation IDs */

#define PIF_ACTION_ID_num_decrement 0
#define PIF_ACTION_ID_need_recirculate 1
#define PIF_ACTION_ID_do_recirculate 2
#define PIF_ACTION_ID_drop_act 3
#define PIF_ACTION_ID_stop_recirculate2 4
#define PIF_ACTION_ID_stop_recirculate1 5
#define PIF_ACTION_ID_record_flow2 6
#define PIF_ACTION_ID_stop_flow1 7
#define PIF_ACTION_ID_record_flow1 8
#define PIF_ACTION_ID_forward 9
#define PIF_ACTION_ID_stop_flow2 10
#define PIF_ACTION_ID_fdo_recirculate 11
#define PIF_ACTION_ID_MAX 11

/* Match action data structure */

__packed struct pif_action_actiondata_num_decrement {
    uint8_t __pif_padding[2]; /* padding */
    uint16_t espec;
};

__packed struct pif_action_actiondata_need_recirculate {
    uint8_t __pif_padding[2]; /* padding */
    uint16_t espec;
};

__packed struct pif_action_actiondata_record_flow2 {
    uint8_t __pif_padding[2]; /* padding */
    uint16_t espec;
};

__packed struct pif_action_actiondata_record_flow1 {
    uint8_t __pif_padding[2]; /* padding */
    uint16_t espec;
};

__packed struct pif_action_actiondata_forward {
    uint8_t __pif_padding[2]; /* padding */
    uint16_t espec;
};

#endif /* __PIF_ACTIONS_H__ */
