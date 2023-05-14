/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <datagram-transport/transport.h>

/// Initializes the datagram transport
/// @param self
/// @param userPointer defined by the transport
/// @param send send function
/// @param receive receive function
void datagramTransportInit(DatagramTransport* self, void* userPointer, DatagramTransportSendFn send,
                           DatagramTransportReceiveFn receive)
{
    self->self = userPointer;
    self->receive = receive;
    self->send = send;
}

/// Tries to receive a datagram
/// It can be blocking and non-blocking depending on the configuration of the transport.
/// @param self
/// @param data
/// @param size
/// @return negative on error, positive numbers represents the number of octets received.
ssize_t datagramTransportReceive(DatagramTransport* self, uint8_t* target, size_t maxOctetCount)
{
    return self->receive(self->self, target, maxOctetCount);
}

/// Tries to send a datagram over the transport
///@param self
///@param source
///@param octetCount
///@return negative on error
int datagramTransportSend(DatagramTransport* self, const uint8_t* source, size_t octetCount)
{
    return self->send(self->self, source, octetCount);
}
