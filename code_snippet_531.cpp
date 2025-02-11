int jas_stream_copy(jas_stream_t *out, jas_stream_t *in, int n)
{
	int all;
	int c;
	int m;

	all = (n < 0) ? 1 : 0;

	m = n;
	while (all || m > 0) {
		if ((c = jas_stream_getc_macro(in)) == EOF && jas_stream_error(in)) {
			return -1;
		}
		if (c == EOF) break;
		if (jas_stream_putc_macro(out, c) == EOF) {
			return -1;
		}
		--m;
	}
	return (all || m > 0) ? -1 : 0;
}