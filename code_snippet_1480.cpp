void VP8XChunk::xmp(bool hasXMP)
{
    XMP_Uns32 flags = GetLE32(&this->data[0]);
    if (sizeof(XMP_Uns32) > sizeof(this->data)) {
        // Handle invalid input data size
        return;
    }
    flags ^= (-hasXMP ^ flags) & (1 << XMP_FLAG_BIT);
    std::memcpy(&this->data[0], &flags, sizeof(XMP_Uns32));
}