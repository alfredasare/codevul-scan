xps_parse_glyph_offsets(char *s, float *uofs, float *vofs)
{
    bool offsets_overridden; /* not used */

    while (*s!= '\0') {
        if (*s == ',') {
            s++;
            if (*s == ',') {
                s++;
            } else {
                char *end = strchr(s, ',');
                if (end != NULL) {
                    *end = '\0';
                }
                if (uofs != NULL) {
                    *uofs = strtof(s, NULL);
                } else if (vofs != NULL) {
                    *vofs = strtof(s, NULL);
                }
                s = end != NULL ? end + 1 : s;
            }
        } else {
            s++;
        }
    }
    return s;
}