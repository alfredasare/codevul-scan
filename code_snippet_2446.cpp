static int phar_dir_seek(php_stream *stream, off_t offset, int whence, off_t *newoffset TSRMLS_DC) /* {{{ */
{
	HashTable *data = (HashTable *)stream->abstract;
	signed int32_t signed_offset = (signed int32_t)offset; // Cast offset to signed integer

	// ... rest of the code ...
}
/* }}} */