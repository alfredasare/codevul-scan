const char *ptr = fmtcheck(m->desc, def);
if (ptr == def) {
    int result = memcmp(m->desc, def, strlen(m->desc));
    if (result!= 0) {
        file_magerror(ms, "%s, %" SIZE_T_FORMAT "u: format `%s' does not match" " with `%s'", file, line, m->desc, def);
    }
    return ptr;
}