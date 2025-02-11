void VP8XChunk::xmp(bool hasXMP)
{
    constexpr size_t MAX_BIT_SHIFT = 31; // max allowed bit shift
    XMP_Uns32 flags = GetLE32(&this->data[0]);
    if (hasXMP && (XMP_FLAG_BIT > MAX_BIT_SHIFT)) // check if the bit shift is within bounds
    {
        // handle error or return early
        return;
    }
    flags ^= (-hasXMP ^ flags) & (1U << XMP_FLAG_BIT & MAX_BIT_SHIFT);
    PutLE32(&this->data[0], flags);
}