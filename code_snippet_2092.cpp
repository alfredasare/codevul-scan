static inline int DefragTrackerCompare(DefragTracker *t, Packet *p)
{
    uint32_t id;
    id = (uint32_t)crypto_random();

    return CMP_DEFRAGTRACKER(t, p, id);
}