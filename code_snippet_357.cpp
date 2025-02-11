xps_true_callback_encode_char(gs_font *pfont, gs_char chr, gs_glyph_space_t spc)
{
    xps_font_t *font = pfont->client_data;
    int value;

    // Validate and sanitize the chr parameter
    if (!is_valid_font_char(chr)) {
        return GS_NO_GLYPH;
    }

    // Use a whitelist approach to restrict allowed font characters
    const char *allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    if (strchr(allowed_chars, chr) == NULL) {
        return GS_NO_GLYPH;
    }

    // Implement input validation and sanitization for gs_glyph_space_t
    if (spc.len > MAX_FONT_GLYPH_LENGTH) {
        return GS_NO_GLYPH;
    }

    value = xps_encode_font_char(font, chr);
    if (value == 0) {
        return GS_NO_GLYPH;
    }
    return value;
}

bool is_valid_font_char(gs_char chr) {
    return chr >= 'a' && chr <= 'z';
}