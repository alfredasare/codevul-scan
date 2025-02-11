void ff_gradfun_blur_line_c(uint16_t *dc, uint16_t *buf, const uint16_t *buf1, const uint8_t *src, int src_linesize, int width)
{
    // Validate width
    if (width <= 0 || width > INT_MAX / sizeof(uint16_t)) {
        return;
    }

    // Validate src_linesize
    if (src_linesize <= 0 || src_linesize > INT_MAX / sizeof(uint8_t)) {
        return;
    }

    // Limit x to the valid width range
    for (int x = 0; x < width; x++) {
        // Ensure array indices do not exceed the valid range
        if (2 * x < 0 || 2 * x >= width || 2 * x + 1 < 0 || 2 * x + 1 >= width ||
            2 * x + src_linesize < 0 || 2 * x + src_linesize >= src_linesize ||
            2 * x + 1 + src_linesize < 0 || 2 * x + 1 + src_linesize >= src_linesize) {
            return;
        }

        uint16_t v = buf1[x] + src[2 * x] + src[2 * x + 1] + src[2 * x + src_linesize] + src[2 * x + 1 + src_linesize];
        uint16_t old = buf[x];
        buf[x] = v;
        dc[x] = v - old;
    }
}