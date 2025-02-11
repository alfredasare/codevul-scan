static int mov_read_moov(MOVContext *c, AVIOContext *pb, MOVAtom atom)
{
    int ret;
    size_t data_size;

    if ((ret = mov_read_default(c, pb, atom)) < 0)
        return ret;

    /* Get the size of data to be read */
    data_size = avio_size(pb);

    /* Check if the data size is valid before processing it */
    if (data_size > INT_MAX) {
        av_log(c, AV_LOG_ERROR, "Invalid data size: %zu\n", data_size);
        return AVERROR_INVALIDDATA;
    }

    /* we parsed the 'moov' atom, we can terminate the parsing as soon as we find the 'mdat' */
    /* so we don't parse the whole file if over a network */
    c->found_moov=1;

    return 0; /* now go for mdat */
}