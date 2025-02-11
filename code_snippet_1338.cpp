__inline int c99_snprintf(char *outBuf, size_t size, const char *format, ...) {
    int count;
    va_list ap;

    va_start(ap, format);
    count = c99_vsnprintf(outBuf, size, format, ap);
    if (count < 0 || count >= size) {
        // Handle error or truncation
        // ...
    }
    va_end(ap);

    return count;
}