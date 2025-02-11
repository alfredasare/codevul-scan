#define MAX_GID 65535 // or whatever the maximum allowed value for gid is

xps_decode_font_char(xps_font_t *font, int code)
{
    int gid = xps_decode_font_char_imp(font, code);
    if (gid >= 0 && gid <= MAX_GID)
        return gid;
    else
        return -1;
}