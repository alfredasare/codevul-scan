static void xdr_init(struct xdr_stream *stream, void *buf, int len)
{
	if (buf && len > 0) {
		stream->p = stream->buf = buf;
		stream->end = stream->buf + len;
	} else {
		// Handle error scenario
	}
}