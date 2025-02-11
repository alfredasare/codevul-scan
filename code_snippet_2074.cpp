static void jpg_unescape(const uint8_t *src, int src_size, uint8_t *dst, int *dst_size) {
    const uint8_t *src_end = src + src_size;
    uint8_t *dst_start = dst;
    const char *allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._~"; // Whitelist of allowed characters

    while (src < src_end) {
        uint8_t x = *src++;

        if (strchr(allowed_chars, x)) {
            *dst++ = x;
        } else {
            *dst++ = '%';
            *dst++ = 'x';
            sprintf((char*)dst, "%02x", x);
            dst += strlen((char*)dst);
        }
    }
    *dst_size = dst - dst_start;
}