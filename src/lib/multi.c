/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <datagram-transport/multi.h>

/// Tries to receive a datagram
/// Can be blocking or non-blocking
/// @param self multi transport
/// @param addressIndex the address index that the datagram was received from
/// @param target the buffer to write the datagram to
/// @param maxOctetCount maximum size in octets of the target buffer
/// @return number of octets received and written to target
ssize_t datagramTransportMultiReceiveFrom(DatagramTransportMulti* self, int* addressIndex, uint8_t* target,
                                      size_t maxOctetCount)
{
    return self->receiveFrom(self->self, addressIndex, target, maxOctetCount);
}

/// Send to a specific address referred to by an index
/// @param self multi transport
/// @param addressIndex the address index to send to
/// @param source the octet payload to send
/// @param octetCount the number of octets in source
/// @return negative on error
int datagramTransportMultiSendTo(DatagramTransportMulti* self, int addressIndex, const uint8_t* source,
                                 size_t octetCount)
{
    return self->sendTo(self->self, addressIndex, source, octetCount);
}
