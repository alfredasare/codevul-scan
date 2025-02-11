static size_t StringSize(const uint8_t *start, uint8_t encoding) {
    if (encoding != 0x00 && encoding != 0x03) {
        return 0; // Or throw an exception or any other error handling as per your requirements
    }

    if (encoding == 0x00) {
        return strlen((const char *)start) + 1;
    } else {
        size_t n = 0;
        while (start[n] != '\0' || start[n + 1] != '\0') {
            n += 2;
        }
        return n + 2;
    }
}