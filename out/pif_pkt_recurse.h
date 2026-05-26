/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PKT_RECURSE_H__
#define __PIF_PKT_RECURSE_H__
#include <nfp.h>

/* Generated C source defining pkt_recurse related bits and bobs  */
/* Warning: your edits to this file may be lost */


#define PIF_PKT_RECURSE_FIELD_LISTS_MAX 31

#define PIF_PKT_RECURSE_FIELDLIST_ID_parse_next 1
#define PIF_PKT_RECURSE_FIELDLIST_LAST 1

#define PIF_RECURSE_PACKET
extern __nnr uint32_t recurse_field_list;
void pif_resubmit_post_ingress(__lmem uint32_t *parrep);

#endif /* __PIF_PKT_RECURSE_H__ */
