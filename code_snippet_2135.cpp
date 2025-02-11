static inline unsigned char *PopHexPixel(const char *const *hex_digits, const size_t pixel, unsigned char *pixels) {
    register const char *hex;

    hex = hex_digits[pixel];
    while (*hex && *hex != '\0') {
        if (strchr("0123456789abcdefABCDEF", *hex)) {
            *pixels++ = (unsigned char) (*hex & 0x0f);
            hex++;
        } else {
            *pixels++ = (unsigned char) 0; // or handle invalid character as needed
        }
    }
    return pixels;
}