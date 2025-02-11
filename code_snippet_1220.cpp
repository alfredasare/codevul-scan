file_fmtcheck(struct magic_set *ms, const struct magic *m, const char *def,
              const char *file, size_t line)
{
        char buffer[1024];
        int len = vsnprintf(buffer, sizeof(buffer), m->desc, def);
        if (len < 0 || (size_t)len >= sizeof(buffer)) {
                file_magerror(ms,
                              "%s, %" SIZE_T_FORMAT "u: format `%s' resulted in "
                              "a string too long for the buffer",
                              file, line, m->desc);
                return NULL;
        }
        if (memcmp(buffer, m->desc, len) != 0) {
                file_magerror(ms,
                              "%s, %" SIZE_T_FORMAT "u: format `%s' does not match "
                              "with `%s'",
                              file, line, m->desc, def);
        }
        return buffer;
}