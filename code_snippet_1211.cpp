file_fmtcheck(struct magic_set *ms, const struct magic *m, const char *def,
             const char *file, size_t line)
{
    int offset = 0;
    const char *ptr = fmtcheck(m->desc, def);
    if (ptr == def)
    {
        if (offset < 0 || offset >= strlen(m->desc))
        {
            file_magerror(ms, "%s, %zu: format `%s' does not match with `%s'", file, line, m->desc, def);
        }
        else
        {
            file_magerror(ms, "%s, %zu: format `%.*s' does not match with `%s'", file, line, offset, &m->desc[offset], def);
        }
    }
    return ptr;
}