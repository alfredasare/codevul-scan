static int bin_size(RCore *r, int mode) {
    ut64 size = r_bin_get_size(r->bin);
    char sanitized_mode[20];

    // Validate the mode parameter
    if (mode!= IS_MODE_SIMPLE && mode!= IS_MODE_JSON && mode!= IS_MODE_RAD && mode!= IS_MODE_SET) {
        r_cons_printf("Invalid mode specified\n");
        return false;
    }

    // Sanitize the mode parameter
    sprintf(sanitized_mode, "%d", mode);

    if (mode == IS_MODE_SIMPLE || mode == IS_MODE_JSON) {
        r_cons_printf("%"PFMT64u"\n", size);
    } else if (mode == IS_MODE_RAD) {
        r_cons_printf("f bin_size @ %"PFMT64u"\n", size);
    } else if (mode == IS_MODE_SET) {
        r_core_cmdf(r, "f bin_size @ %"PFMT64u"\n", size);
    } else {
        r_cons_printf("%"PFMT64u"\n", size);
    }
    return true;
}