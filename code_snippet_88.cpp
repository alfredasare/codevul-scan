static void t1_scan_param(PDF pdf)
{
    static const char *lenIV = "/lenIV";
    if (!t1_scan || *t1_line_array!= '/')
        return;
    if (t1_prefix(lenIV)) {
        char* sanitized_input = sanitize_numerics(t1_line_array + strlen(lenIV));
        short t1_lenIV = t1_scan_num(sanitized_input, 0);
        if (t1_lenIV < 0)
            normal_error("type 1", "negative value of lenIV is not supported");
        free(sanitized_input);
        return;
    }
    t1_scan_keys(pdf);
}