/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef DATAGRAM_TRANSPORT_MULTI_H
#define DATAGRAM_TRANSPORT_MULTI_H

#include <stddef.h>
#include <stdint.h>

typedef int (*DatagramTransportMultiSendFn)(void* self, int addressIndex, const uint8_t* const source,
                                            size_t octetCount);
typedef int (*DatagramTransportMultiReceiveFn)(void* self, int* receivedFromAddressIndex, uint8_t* target,
                                               size_t maxOctetCount);

typedef struct DatagramTransportMulti {
    DatagramTransportMultiReceiveFn receiveFrom;
    DatagramTransportMultiSendFn sendTo;
    void* self;
} DatagramTransportMulti;

typedef struct DatagramTransportMultiOut {
    DatagramTransportMultiSendFn sendTo;
    void* self;
} DatagramTransportMultiOut;

typedef struct DatagramTransportMultiIn {
    DatagramTransportMultiReceiveFn receiveFrom;
    void* self;
} DatagramTransportMultiIn;

int datagramTransportMultiReceiveFrom(DatagramTransportMulti* transport, int* addressIndex, uint8_t* target,
                                      size_t maxOctetCount);
int datagramTransportMultiSendTo(DatagramTransportMulti* transport, int addressIndex, const uint8_t* source,
                                 size_t octetCount);

#endif
