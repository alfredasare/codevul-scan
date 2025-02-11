ssize_t utf32_to_utf8_length(const char32_t *src, size_t src_len)
{
    if (src == NULL || src_len == 0) {
        return -1;
    }

    size_t ret = 0;
    const char32_t *end = src + src_len;
    while (src < end) {
        if (*src >= 0xd800 && *src < 0xe000) {
            // Handle surrogate pairs
            src++;
            if (src >= end || *src >= 0xd800 || *src < 0xdc00) {
                break;
            }
            src++;
        } else {
            ret += utf32_codepoint_utf8_length(*src++);
        }
    }

    return ret;
}