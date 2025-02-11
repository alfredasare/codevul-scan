#include <linux/udp.h> /* For UDP_PROTOCOL_NUMBER */

int udp_offload_init(void)
{
    const int expected_protocol = UDP_PROTOCOL_NUMBER;
    return inet6_add_offload(&udpv6_offload, expected_protocol);
}