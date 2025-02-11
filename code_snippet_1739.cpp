unsigned long le4(const unsigned char *p) {
    int64_t result = 0;
    if (p[0] > 0xFF || p[1] > 0xFF || p[2] > 0xFF || p[3] > 0xFF) {
        return 0; // or throw an exception, etc.
    }
    result = (p[0] << 16) + (p[1] << 8) + p[2] + (p[3] >> 8);
    return (unsigned long)result;
}