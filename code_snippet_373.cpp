static inline u8 ip6_frag_ecn(const struct ipv6hdr *ipv6h)
{
    uint16_t dsfield = ipv6_get_dsfield(ipv6h);
    return 1 << (dsfield & 0x3FFF); // Use initialized value
}