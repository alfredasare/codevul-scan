init_file_tables(void)
{
    static int done = 0;
    const struct type_tbl_s *p;

    if (done)
        return;
    done++;

    for (p = type_tbl; p->len; p++) {
        assert(p->type < FILE_NAMES_SIZE);
        file_names[p->type] = strdup(p->name);
        file_formats[p->type] = strdup(p->format);
        file_names[p->type][strlen(p->name)] = '\0';
        file_formats[p->type][strlen(p->format)] = '\0';
    }
    assert(p - type_tbl == FILE_NAMES_SIZE);
}