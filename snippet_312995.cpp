undo_read_byte(bufinfo_T *bi)
{
#ifdef FEAT_CRYPT
    if (bi->bi_buffer != NULL)
    {
	char_u  buf[1];

	undo_read(bi, buf, (size_t)1);
	return buf[0];
    }
#endif
    return getc(bi->bi_fp);
}