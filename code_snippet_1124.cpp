static inline int padr_bcast(PCNetState *s, const uint8_t *buf, size_t size)
{
    static const uint8_t BCAST[6] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
    struct qemu_ether_header *hdr = (void *)buf;
    int result = (size >= sizeof(hdr->ether_dhost)) &&!CSR_DRCVBC(s) &&!memcmp(hdr->ether_dhost, BCAST, 6);
#ifdef PCNET_DEBUG_MATCH
    printf("padr_bcast result=%d\n", result);
#endif
    return result;
}