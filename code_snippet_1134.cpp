int xps_decode_font_char(xps_font_t *font, int code)
{
    int gid;
    if (code < 0 || code > 255) {
        return code;
    }
    gid = xps_decode_font_char_imp(font, code);
    if (gid < 0 || gid > 255) {
        gid = 0;
    }
    return gid;
}