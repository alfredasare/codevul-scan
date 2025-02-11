xps_true_callback_encode_char(gs_font *pfont, gs_char chr, gs_glyph_space_t spc)
{
    xps_font_t *font = pfont->client_data;
    int value;
    int max_int = INT_MAX;

    value = xps_encode_font_char(font, chr);
    if (value > max_int) {
        /* Handle error condition */
        return GS_ERROR;
    }
    return value;
}