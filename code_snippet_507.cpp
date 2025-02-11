void l2tp_framing_cap_print(netdissect_options *ndo, const u_char *dat, size_t len)
{
    if (len < sizeof(uint32_t)) {
        return; // early exit if dat is too short
    }

    const uint32_t *ptr = (const uint32_t *)dat;

    if (EXTRACT_32BITS(ptr) &  L2TP_FRAMING_CAP_ASYNC_MASK) {
        ND_PRINT((ndo, "A"));
    }
    if (EXTRACT_32BITS(ptr) &  L2TP_FRAMING_CAP_SYNC_MASK) {
        ND_PRINT((ndo, "S"));
    }
}