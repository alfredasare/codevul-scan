static int utf8_to_utf32(const char *utf8, int len, uint32_t *utf32)
{
    uint32_t ch = 0;
    int i;
    uint8_t mask;

    if (len < 1 || len > 4) {
        return -EINVAL;
    }

    if ((ch = *utf8) & 0x80) {
        if ((ch & 0xe0) == 0xc0 && len >= 2) {
            len = 2;
            mask = 0x1f;
        } else if ((ch & 0xf0) == 0xe0 && len >= 3) {
            len = 3;
            mask = 0xf;
        } else if ((ch & 0xf8) == 0xf0 && len >= 4) {
            len = 4;
            mask = 0x7;
        } else
            return -EINVAL;

        for (i = 0; i < len; i++) {
            int shift = (len - i - 1) * 6;
            if (i == 0)
                ch |= ((uint32_t)(*utf8++) & mask) << shift;
            else
                ch |= ((uint32_t)(*utf8++) & 0x3f) << shift;
        }
    } else {
        ch = *utf8;
        len = 1;
        mask = 0x7f;
    }

    *utf32 = ch;

    return len;
}