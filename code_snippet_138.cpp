static long mem_seek(jas_stream_obj_t *obj, long offset, int origin)
{
    jas_stream_memobj_t *m = (jas_stream_memobj_t *)obj;
    size_t newpos;

    JAS_DBGLOG(100, ("mem_seek(%p, %ld, %d)\n", obj, offset, origin));
    switch (origin) {
        case SEEK_SET:
            newpos = (size_t)offset;
            break;
        case SEEK_END:
            newpos = (size_t)(m->len_ - offset);
            break;
        case SEEK_CUR:
            newpos = (size_t)(m->pos_ + offset);
            break;
        default:
            abort();
            break;
    }
    if (newpos < 0) {
        return -1;
    }
    m->pos_ = (long)newpos;

    return m->pos_;
}