/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <datagram-transport/multi_single.h>
#include <stdbool.h>

static int send(void* _self, const uint8_t* data, size_t size)
{
    DatagramTransportSingleToFromMulti* self = (DatagramTransportSingleToFromMulti*) _self;

    return self->multi.sendTo(self->multi.self, self->filterConnectionIndex, data, size);
}

static ssize_t receive(void* _self, uint8_t* data, size_t size)
{
    DatagramTransportSingleToFromMulti* self = (DatagramTransportSingleToFromMulti*) _self;
    while (true) {
        int foundConnectionIndex;
        int octetCountRead = self->multi.receiveFrom(self->multi.self, &foundConnectionIndex, data, size);
        if (octetCountRead <= 0) {
            return octetCountRead;
        }
        if (foundConnectionIndex == self->filterConnectionIndex) {
            return octetCountRead;
        }
    }
}

void datagramTransportSingleToFromMultiInit(DatagramTransportSingleToFromMulti* self, DatagramTransportMulti inout,
                                            int onlyForConnectionIndex)
{
    self->multi = inout;
    self->filterConnectionIndex = onlyForConnectionIndex;
    self->transport.receive = receive;
    self->transport.send = send;
    self->transport.self = self;
}
