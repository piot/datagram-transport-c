/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef DATAGRAM_TRANSPORT_MULTI_SINGLE_H
#define DATAGRAM_TRANSPORT_MULTI_SINGLE_H

#include <stddef.h>
#include <stdint.h>

#include <datagram-transport/multi.h>
#include <datagram-transport/transport.h>

typedef struct DatagramTransportSingleToFromMulti {
    int filterConnectionIndex;
    DatagramTransportMulti multi;
    DatagramTransport transport;
} DatagramTransportSingleToFromMulti;

void datagramTransportSingleToFromMultiInit(DatagramTransportSingleToFromMulti* self, DatagramTransportMulti multi,
                                            int onlyForConnectionIndex);

#endif
