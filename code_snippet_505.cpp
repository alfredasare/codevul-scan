RenderSetBit(unsigned char *line, int x, int bit, size_t line_size)
{
    unsigned char mask;

    if (x < 0 || x >= (line_size << 3)) {
        return; // handle error by returning or using error codes
    }

    if (screenInfo.bitmapBitOrder == LSBFirst)
        mask = (1 << (x & 7));
    else
        mask = (0x80 >> (x & 7));
    line += (x >> 3);
    if (bit)
        *line |= mask;
    else
        *line &= ~mask;
}