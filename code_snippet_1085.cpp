static void xdr_init(struct xdr_stream *stream, void *buf, int len)
{
    if (buf == NULL || len <= 0) {
        return;
    }

    if (len > XDR_STREAM_MAX_BUFFER_SIZE) {
        return;
    }

    char *safe_buf = malloc(len);
    if (safe_buf == NULL) {
        return;
    }

    memcpy(safe_buf, buf, len);

    stream->p = stream->buf = safe_buf;
    stream->end = stream->buf + len;

    free(safe_buf);
}