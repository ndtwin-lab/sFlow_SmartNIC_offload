/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#include <nfp.h>
#include <nfp/me.h>
#include <nfp/cls.h>
#include <pif_common.h>
#include <pif_counters.h>
#include "pkt_clone.h"

/* Generated C source defining pkt_recurse related bits and bobs  */
/* Warning: your edits to this file may be lost */

__nnr uint32_t recurse_field_list = 0;

void pif_resubmit_post_ingress(__lmem uint32_t *parrep)
{
    /* Save the parsed header from local memory to CLS,
     * clear out the parsed header in local memory,
     * and then copy the saved fields from CLS as specified in resubmit field list.
     * Resubmit fields of same structures are grouped together to allow for a 
     * single CLS read for better performance.
     */
    __gpr uint32_t list_resubmit_fields = recurse_field_list;
    __gpr uint32_t field_id;
    __gpr uint32_t i;

    recurse_field_list = 0;
    /* save parsed header from local memory to CLS */
    save_parrep(parrep, (__cls uint32_t *)parrep_copy, PIF_PARREP_LEN_LW);

    /* clean out parsed header */
    for (i = 0; i < PIF_PARREP_LEN_LW; i++) {
        parrep[i] = 0x00;
    }

    {
        /* initialise parsed header and set instance_type */
        __lmem struct pif_header_standard_metadata *lm_ptr = (__lmem struct pif_header_standard_metadata *) (parrep + PIF_PARREP_standard_metadata_OFF_LW);

        pif_global_metadata_init(parrep);
        lm_ptr->instance_type = pkt_dup_state.type;
    }

    /* Get the field lists from recurse_field_list if top bit and any other bit is set indicating that there were resubmits */
    if ((list_resubmit_fields & (0x01<<31)) > 0)
    {
        /*
         * Top bit will always be set, break if top bit only is set
         * ffs returns 0 - 31 .. 0 and field lists are #define field_list 1 .. 31 
         */
        field_id = ffs(list_resubmit_fields) + 1;
        while (field_id <= PIF_PKT_RECURSE_FIELD_LISTS_MAX)
        {
            switch (field_id)
            {
                case 1:
                {
                    __lmem struct pif_header_recirculate_fl *lm_recirculate_fl_ptr = (__lmem struct pif_header_recirculate_fl *) (parrep + PIF_PARREP_recirculate_fl_OFF_LW);
                    __cls struct pif_header_recirculate_fl *cls_recirculate_fl_ptr = (__cls struct pif_header_recirculate_fl *) (parrep_copy + PIF_PARREP_recirculate_fl_OFF_LW);
                    __xread struct pif_header_recirculate_fl xr_data;

                    cls_read(&xr_data, cls_recirculate_fl_ptr, sizeof(xr_data));

                    lm_recirculate_fl_ptr->fl = xr_data.fl;
                    lm_recirculate_fl_ptr->recirculate_count = xr_data.recirculate_count;
                }
                break;

            } // switch

            /* clear the bit we have processed */
            list_resubmit_fields = (list_resubmit_fields & ~(0x01<<(field_id - 1)));

            /* get the next set bit */
            field_id = ffs(list_resubmit_fields) + 1;
        }

    }
    PIF_DUP_ACTION_CLEAR(pkt_dup_state);

    /*  increment counters */
    if (pkt_dup_state.type == PIF_PKT_INSTANCE_TYPE_INGRESS_RECIRC)
        PIF_COUNT(RECIRCULATE);

    return;
}
