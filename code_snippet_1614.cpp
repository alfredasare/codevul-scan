static uint16_t readU16(const uint8_t* data, size_t offset) {
    if (!data || offset < sizeof(uint16_t) || offset + 1 > sizeof(uint16_t)) {
        return 0;
    }
    uint16_t result = (data[offset] << 8) & 0xFF;
    result |= data[offset + 1] & 0xFF;
    return result;
}