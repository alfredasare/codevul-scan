void *WavpackGetWrapperLocation (void *first_block, uint32_t *size)
{
    void *loc = NULL;

    WavpackLittleEndianToNative (first_block, WavpackHeaderFormat);
    loc = find_metadata (first_block, ID_RIFF_HEADER, size);

    if (!loc)
        loc = find_metadata (first_block, ID_ALT_HEADER, size);

    WavpackNativeToLittleEndian (first_block, WavpackHeaderFormat);

    if (loc != NULL)
        return loc;
    else
        return NULL;
}