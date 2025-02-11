code:


static size_t StringSize(const uint8_t *start, uint8_t encoding) {
    if (encoding < 0x00 || encoding > 0x03) {
        return 0;
    }
    const size_t MAX_BUFFER_SIZE = 1024;
    char buffer[MAX_BUFFER_SIZE] = {0};
    size_t n = 0;
    while (n < MAX_BUFFER_SIZE && (start[n]!= '\0' || start[n + 1]!= '\0')) {
        n += 2;
    }
    memcpy(buffer, (const char *)start, n);
    return n;
}