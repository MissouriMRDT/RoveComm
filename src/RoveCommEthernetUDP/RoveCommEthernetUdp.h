#ifndef RoveEthernetUdp_h
#define RoveEthernetUdp_h

#include <stdint.h>
#include <stddef.h>

#if defined(ENERGIA)
#include <Ethernet.h>
#include <EthernetUdp.h>
#elif defined(ARDUINO) && (ARDUINO > 100)
#include <NativeEthernet.h>
#include <NativeEthernetUdp.h>
#endif

#include "RoveCommManifest.h"
#include "RoveCommPacket.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class RoveCommEthernetUdp
{
public:
    struct rovecomm_packet read();

#if defined(ENERGIA)
    /////begin/////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Overloaded begin
    // Default ip address = 192.168.1.XXX
    void begin(const int board_ip_octet);
    void begin(const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4);
#elif defined(ARDUINO) && (ARDUINO > 100)
    /////begin/////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Overloaded begin
    // Default ip address = 192.168.1.XXX
    // Default MAC address = 222.173.190.168.1.xxx
    //  void begin(const int board_ip_octet, const uint8_t board_mac);
    void begin(const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4);
#endif
    void begin();

    /////write////////////////////////////////////////////////////////////////////////
    // Single-value write
    // Overloaded for each data type
    // Causes bug when doing:RoveComm.write(SINGLE_VALUE_EXAMPLE_ID, 1, analogRead(A0));
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

private:
    // Called by overloaded write functions
    void _write(const uint8_t data_type_length, const roveware::data_type_t data_type,
                const uint16_t data_id, const uint16_t data_count, const void *data);
    // Called by overloaded writeTo functions
    void _writeTo(const uint8_t data_type_length, const roveware::data_type_t data_type,
                  const uint16_t data_id, const uint16_t data_count, const void *data,
                  const uint8_t ip_octet_1, const uint8_t ip_octet_2, const uint8_t ip_octet_3, const uint8_t ip_octet_4, const uint16_t port);
    void _writeTo(const uint8_t data_type_length, const roveware::data_type_t data_type,
                  const uint16_t data_id, const uint16_t data_count, const void *data,
                  IPAddress ipaddress, const uint16_t port);
};

#endif // RoveEthernetUdp_h