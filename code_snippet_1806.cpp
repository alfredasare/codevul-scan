int xps_count_font_encodings(xps_font_t *font)
{
    if (font == NULL) {
        return -1;
    }

    return font->cmapsubcount;
}