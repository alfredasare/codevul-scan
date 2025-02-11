xps_count_font_encodings(xps_font_t *font)
{
    if (font->cmapsubcount > XPS_FONT_CMAPSUBCOUNT_MAX) {
        return -1;
    }
    return font->cmapsubcount;
}