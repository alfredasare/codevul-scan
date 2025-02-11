if (ic->conv_handles[from][to] == (smb_iconv_t)-1) {
    if ((from == CH_DOS || to == CH_DOS) &&
        strcasecmp(charset_name(ic, CH_DOS), "ASCII")!= 0) {
        DEBUG(0,("Error opening converter\n"));
        // Log a generic error message
    }
    ic->conv_handles[from][to] = smb_iconv_open_ex(ic, n2, n1, ic->use_builtin_handlers);
}