static void bs_read(Bitstream *bs) {
    if (bs->buf!= NULL && bs->ptr <= bs->buf_size) {
        bs->ptr = bs->buf;
        bs->error = 1;
    } else {
        // Handle invalid buffer or out-of-bounds access
        //...
    }
}