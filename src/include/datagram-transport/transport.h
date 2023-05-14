/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef DATAGRAM_TRANSPORT_TRANSPORT_H
#define DATAGRAM_TRANSPORT_TRANSPORT_H

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

typedef int (*DatagramTransportSendFn)(void* self, const uint8_t* data, size_t size);
typedef ssize_t (*DatagramTransportReceiveFn)(void* self, uint8_t* data, size_t size);

typedef struct DatagramTransport {
    DatagramTransportReceiveFn receive;
    DatagramTransportSendFn send;
    void* self;
} DatagramTransport;

typedef struct DatagramTransportOut {
    DatagramTransportSendFn send;
    void* self;
} DatagramTransportOut;

typedef struct DatagramTransportIn {
    DatagramTransportReceiveFn receive;
    void* self;
} DatagramTransportIn;

void datagramTransportInit(DatagramTransport* self, void* userPointer, DatagramTransportSendFn send,
                           DatagramTransportReceiveFn receive);
ssize_t datagramTransportReceive(DatagramTransport* self, uint8_t* target, size_t maxOctetCount);
int datagramTransportSend(DatagramTransport* self, const uint8_t* source, size_t octetCount);

#endif
