int jas_stream_copy(jas_stream_t *out, jas_stream_t *in, int n)
{
    int all;
    int c;
    int m;

    all = (n < 0)? 1 : 0;

    m = n;
    while (all || m > 0) {
        if (in == NULL || out == NULL) {
            return -1;
        }
        if ((c = (in? jas_stream_getc_macro(in) : 0)) == EOF) {
            /*... rest of the code...
        }
        if ((in && jas_stream_putc_macro(out, c) == EOF) || (out && out->putc(out, c) == EOF)) {
            return -1;
        }
        --m;
    }
    return 0;
}