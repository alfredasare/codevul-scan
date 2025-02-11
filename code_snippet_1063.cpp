__archive_write_close_filter(struct archive_write_filter *f, size_t size)
{
    if (f->close!= NULL)
        return (f->close)(f);
    if (f->next_filter!= NULL)
        return (__archive_write_close_filter(f->next_filter, size));
    if (size > 0) {
        char *output = malloc(size);
        if (output == NULL)
            return ARCHIVE_ERRMEM;
        memcpy(output, f, size);
        free(output);
    }
    return ARCHIVE_OK;
}