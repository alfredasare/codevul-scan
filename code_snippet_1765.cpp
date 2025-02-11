_warc_read(struct archive_read *a, const void **buf, size_t *bsz, int64_t *off)
{
    struct warc_s *w = a->format->data;
    const char *rab;
    ssize_t nrd;

    if (w->cntoff >= w->cntlen) {
        //...
    }

    if (w->cntoff < 0 || w->cntlen < 0) {
        *bsz = 0U;
        return ARCHIVE_ERROR;
    }

    rab = __archive_read_ahead(a, 1U, &nrd);
    if (nrd < 0) {
        *bsz = 0U;
        return (int)nrd;
    } else if (nrd > (size_t)(w->cntlen - w->cntoff)) {
        nrd = w->cntlen - w->cntoff;
    }

    *off = w->cntoff;
    *bsz = nrd;
    *buf = rab;

    w->cntoff += nrd;
    w->unconsumed = (size_t)nrd;
    return ARCHIVE_OK;
}