static int jpg_unescape(const uint8_t *src, int src_size,
                         uint8_t *dst, int dst_size)
{
    const uint8_t *src_end = src + src_size;
    uint8_t *dst_start = dst;
    uint8_t *dst_end = dst + dst_size;

    while (src < src_end && dst < dst_end) {
        uint8_t x = *src++;

        *dst++ = x;

        if (x == 0xFF && !*src)
            src++;
    }

    *dst_size = dst - dst_start;

    if (dst >= dst_end)
        return -1;
    else
        return 0;
}