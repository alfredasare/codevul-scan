int __archive_write_close_filter(struct archive_write_filter *f)
{
	if (f->close != NULL)
		return (f->close)(f);

	if (__archive_write_close_filter(f->next_filter) != ARCHIVE_OK)
		return ARCHIVE_FATAL;

	return (ARCHIVE_OK);
}