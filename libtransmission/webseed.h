/*
 * This file Copyright (C) Mnemosyne LLC
 *
 * This file is licensed by the GPL version 2. Works owned by the
 * Transmission project are granted a special exemption to clause 2(b)
 * so that the bulk of its code can remain under the MIT license.
 * This exemption does not extend to derived works not owned by
 * the Transmission project.
 *
 * $Id: webseed.h 12204 2011-03-22 15:19:54Z jordan $
 */

#ifndef __TRANSMISSION__
#error only libtransmission should #include this header.
#endif

#ifndef TR_WEBSEED_H
#define TR_WEBSEED_H

typedef struct tr_webseed tr_webseed;

#include "peer-common.h"

tr_webseed* tr_webseedNew( struct tr_torrent * torrent,
                           const char        * url,
                           tr_peer_callback  * callback,
                           void              * callback_data );

void        tr_webseedFree( tr_webseed * );

/** @return true if a request is being processed, or false if idle */
bool        tr_webseedGetSpeed_Bps( const tr_webseed * w,
                                    uint64_t           now,
                                    int              * setme_Bps );

/** @return true if a request is being processed, or false if idle */
bool        tr_webseedIsActive( const tr_webseed * w );

void increment_webseed_strike_count (tr_webseed          * webseed,
                 struct tr_torrent * torrent,
                 tr_piece_index_t    pieceIndex);

#endif
