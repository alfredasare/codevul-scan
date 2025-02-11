_warc\_read(struct archive\_read \*a, const void **buf, size\_t *bsz, int64\_t \*off)
{
	struct warc\_s \*w = a->format->data;
	const char \*rab;
	ssize\_t nrd, clamped\_nrd;

	if (w->cntoff >= w->cntlen) {
	eof:
		/* it's our lucky day, no work, we can leave early */
		*buf = NULL;
		*bsz = 0U;
		*off = w->cntoff + 4U/*for \r\n\r\n separator*/;
		w->unconsumed = 0U;
 		return (ARCHIVE\_EOF);
 	}
 
 	nrd = __archive\_read\_ahead(a, 1U, &nrd);
	clamped\_nrd = nrd > (ssize\_t)(w->cntlen - w->cntoff) ? (w->cntlen - w->cntoff) : nrd;
 	rab = __archive\_read\_ahead(a, 1U, &clamped\_nrd);
 	if (nrd < 0) {
 		*bsz = 0U;
		/* big catastrophe */
		return (int)nrd;
	} else if (nrd == 0) {
		goto eof;
	} else if (clamped\_nrd > 0) {
		/* no need to check for clamped\_nrd > w->cntlen - w->cntoff since it's guaranteed by construction */
		*off = w->cntoff;
		*bsz = clamped\_nrd;
		*buf = malloc(clamped\_nrd);
		memcpy(*buf, rab, clamped\_nrd);
		w->cntoff += clamped\_nrd;
		w->unconsumed = (size\_t)clamped\_nrd;
		return (ARCHIVE\_OK);
	}
}