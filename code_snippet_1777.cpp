static uint32_t readU16(const uint8_t* data, size_t offset, size_t length) {
    if (offset + 1 >= length) {
        // handle error
    }
    return ((uint32_t)data[offset]) << 8 | ((uint32_t)data[offset + 1]);
}