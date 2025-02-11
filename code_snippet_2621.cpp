uint8_t *faad_getbitbuffer(bitfile *ld, uint32_t bits DEBUGDEC)
{
    int i;
    unsigned int temp;
    int bytes = bits >>