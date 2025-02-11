static inline int DefragTrackerCompare(DefragTracker *t, Packet *p)
{
    uint32_t id;
    if (PKT_IS_IPV4(p) && IPV4_GET_IPID_VALID(p)) {
        id = (uint32_t)IPV4_GET_IPID(p);
    } else if (PKT_IS_IPV6(p) && IPV6_EXTHDR_GET_FH_ID_VALID(p)) {
        id = IPV6_EXTHDR_GET_FH_ID(p);
    } else {
        return -1; // or any other appropriate error value
    }

    return CMP_DEFRAGTRACKER(t, p, id);
}