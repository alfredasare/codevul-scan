fbStore_a4 (FbBits *bits, const CARD32 *values, int x, int width, miIndexedPtr indexed)
{
    int i;
    for (i = 0; i < width; ++i) {
        CARD32 value = values[i];
        Store4(bits, i + x, (value >> 28) & 0xFF);
    }
}