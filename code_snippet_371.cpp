static void bs_read (Bitstream *bs)
{
    // Initialize or reset the error field to a known value (e.g. 0)
    bs->error = 0;
    bs->ptr = bs->buf;
}