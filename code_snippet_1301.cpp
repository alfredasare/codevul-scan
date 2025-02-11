static inline int padr_bcast(PCNetState *s, const uint8_t *buf, int size)
{
    static const uint8_t BCAST[6] = {