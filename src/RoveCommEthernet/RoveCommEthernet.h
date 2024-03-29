#ifndef RoveCommEthernet_h
#define RoveCommEthernet_h

#include <stdint.h>
#include <stddef.h>

#if defined(ENERGIA)
#include "Ethernet.h"
#elif defined(ARDUINO) && (ARDUINO > 100)
#include "NativeEthernet.h"
#endif

#include "RoveCommManifest.h"
#include "RoveCommPacket.h"
#include "../RoveCommEthernetTCP/RoveCommEthernetTCP.h"
#include "../RoveCommEthernetUDP/RoveCommEthernetUdp.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class RoveCommEthernet
{
private:
  uint8_t num_clients = 0;

public:
  RoveCommEthernetTCP TCP;
  RoveCommEthernetUdp UDP;

  struct rovecomm_packet rovecomm_packet;

  /////begin/////////////////////////////////////////////////////////////////////////////////////////////////////////
  // checks all ongoing connections for incoming packets and returns the first one as a parsed rovecomm packet
  struct rovecomm_packet read();

#if defined(ENERGIA)
  /////begin/////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Overloaded begin
  // Default ip address = 192.168.1.XXX
  // This TCP server will be configured with an IP and port from the RoveComm manifest and allow other boards and base-station
  // to securely communicate with it
  void begin(const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, EthernetServer *TCPServer);
  void begin(const uint8_t ip_octet_4, EthernetServer *TCPServer);

#elif defined(ARDUINO) && (ARDUINO > 100)
  /////begin/////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Overloaded begin
  // Default ip address = 192.168.1.XXX
  // This TCP server will be configured with an IP and port from the RoveComm manifest and allow other boards and base-station
  // to securely communicate with it
  void begin(const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, EthernetServer *TCPServer);
  // void begin(const uint8_t ip_octet_4, EthernetServer *TCPServer, const uint8_t board_mac);
#endif

  /////write////////////////////////////////////////////////////////////////////////
  // Single-value write
  // Overloaded for each data type
  // void write(const uint16_t data_id, const int     data_count, const int      data);
  void write(const uint16_t data_id, const uint16_t data_count, const uint8_t data);
  void write(const uint16_t data_id, const uint16_t data_count, const uint16_t data);
  void write(const uint16_t data_id, const uint16_t data_count, const uint32_t data);
  void write(const uint16_t data_id, const uint16_t data_count, const int8_t data);
  void write(const uint16_t data_id, const uint16_t data_count, const int16_t data);
  void write(const uint16_t data_id, const uint16_t data_count, const int32_t data);
  void write(const uint16_t data_id, const uint16_t data_count, const float data);
  void write(const uint16_t data_id, const uint16_t data_count, const double data);
  void write(const uint16_t data_id, const uint16_t data_count, const char data);

  // Array entry write
  // Overloaded for each data type
  void write(const uint16_t data_id, const int data_count, const int *data);
  void write(const uint16_t data_id, const uint16_t data_count, const uint8_t *data);
  void write(const uint16_t data_id, const uint16_t data_count, const uint16_t *data);
  void write(const uint16_t data_id, const uint16_t data_count, const uint32_t *data);
  void write(const uint16_t data_id, const uint16_t data_count, const int8_t *data);
  void write(const uint16_t data_id, const uint16_t data_count, const int16_t *data);
  void write(const uint16_t data_id, const uint16_t data_count, const int32_t *data);
  void write(const uint16_t data_id, const uint16_t data_count, const float *data);
  void write(const uint16_t data_id, const uint16_t data_count, const double *data);
  void write(const uint16_t data_id, const uint16_t data_count, const char *data);

  /////writeTo///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Single-value writeTo
  // Overloaded for each data type
  void writeTo(const uint16_t data_id, const uint16_t data_count, const int data,
               const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

  void writeTo(const uint16_t data_id, const uint16_t data_count, const uint8_t data,
               const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

  void writeTo(const uint16_t data_id, const uint16_t data_count, const uint16_t data,
               const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

  void writeTo(const uint16_t data_id, const uint16_t data_count, const uint32_t data,
               const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

  void writeTo(const uint16_t data_id, const uint16_t data_count, const int8_t data,
               const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

  void writeTo(const uint16_t data_id, const uint16_t data_count, const int16_t data,
               const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

  void writeTo(const uint16_t data_id, const uint16_t data_count, const int32_t data,
               const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

  void writeTo(const uint16_t data_id, const uint16_t data_count, const float data,
               const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

  void writeTo(const uint16_t data_id, const uint16_t data_count, const double data,
               const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

  void writeTo(const uint16_t data_id, const uint16_t data_count, const char data,
               const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

  // Array entry write
  // Overloaded for each data type
  void writeTo(const uint16_t data_id, const uint16_t data_count, const int *data,
               const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

  void writeTo(const uint16_t data_id, const uint16_t data_count, const uint8_t *data,
               const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

  void writeTo(const uint16_t data_id, const uint16_t data_count, const uint16_t *data,
               const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

  void writeTo(const uint16_t data_id, const uint16_t data_count, const uint32_t *data,
               const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

  void writeTo(const uint16_t data_id, const uint16_t data_count, const int8_t *data,
               const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

  void writeTo(const uint16_t data_id, const uint16_t data_count, const int16_t *data,
               const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

  void writeTo(const uint16_t data_id, const uint16_t data_count, const int32_t *data,
               const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

  void writeTo(const uint16_t data_id, const uint16_t data_count, const float *data,
               const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

  void writeTo(const uint16_t data_id, const uint16_t data_count, const double *data,
               const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

  void writeTo(const uint16_t data_id, const uint16_t data_count, const char *data,
               const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);

  /////writeReliable/////////////////////////////////////////////////////////////////////////////////////////////////
  // Single-value writeReliable which ensures delivery
  // Overloaded for each data type
  void writeReliable(const uint16_t data_id, const uint16_t data_count, const uint8_t data);
  void writeReliable(const uint16_t data_id, const uint16_t data_count, const uint16_t data);
  void writeReliable(const uint16_t data_id, const uint16_t data_count, const uint32_t data);
  void writeReliable(const uint16_t data_id, const uint16_t data_count, const int8_t data);
  void writeReliable(const uint16_t data_id, const uint16_t data_count, const int16_t data);
  void writeReliable(const uint16_t data_id, const uint16_t data_count, const int32_t data);
  void writeReliable(const uint16_t data_id, const uint16_t data_count, const float data);
  void writeReliable(const uint16_t data_id, const uint16_t data_count, const double data);
  void writeReliable(const uint16_t data_id, const uint16_t data_count, const char data);

  // Array entry writeReliable which ensures delivery
  // Overloaded for each data type
  void writeReliable(const uint16_t data_id, const uint16_t data_count, const uint8_t *data);
  void writeReliable(const uint16_t data_id, const uint16_t data_count, const uint16_t *data);
  void writeReliable(const uint16_t data_id, const uint16_t data_count, const uint32_t *data);
  void writeReliable(const uint16_t data_id, const uint16_t data_count, const int8_t *data);
  void writeReliable(const uint16_t data_id, const uint16_t data_count, const int16_t *data);
  void writeReliable(const uint16_t data_id, const uint16_t data_count, const int32_t *data);
  void writeReliable(const uint16_t data_id, const uint16_t data_count, const float *data);
  void writeReliable(const uint16_t data_id, const uint16_t data_count, const double *data);
  void writeReliable(const uint16_t data_id, const uint16_t data_count, const char *data);
};

#endif // RoveCommEthernet_h