# Datagram Transport

Minimal interface to unreliable [Datagram](https://en.wikipedia.org/wiki/Datagram) transports.

## Usage

The core functions are send and receive.

### Send

```c
int datagramTransportReceive(DatagramTransport* self, uint8_t* data, size_t size);
```


### Receive

```c
int datagramTransportSend(DatagramTransport* self, const uint8_t* data, size_t size);
```
