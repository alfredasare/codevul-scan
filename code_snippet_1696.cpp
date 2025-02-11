stream *streamNew(void) {
    stream *s = zmalloc(sizeof(*s));
    if (!s) goto error;
    s->rax = raxNew();
    if (!s->rax) goto error;
    s->length = 0;
    s->last_id.ms = 0;
    s->last_id.seq =