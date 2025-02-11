static int init_blocksize(vorb *f, size_t b, size_t n)
{
    size_t n2 = n >> 1;
    size_t n4 = n >> 2;
    size_t n8 = n >> 3;
    f->A[b] = (float *) setup_malloc(f, sizeof(float) * n2);
    f->B[b] = (float *) setup_malloc(f, sizeof(float) * n2);
    f->C[b] = (float *) setup_malloc(f, sizeof(float) * n4);
    if (!f->A[b] ||!f->B[b] ||!f->C[b]) return error(f, VORBIS_outofmem);
    compute_twiddle_factors(n, f->A[b], f->B[b], f->C[b]);
    f->window[b] = (float *) setup_malloc(f, sizeof(float) * n2);
    if (!f->window[b]) return error(f, VORBIS_outofmem);
    compute_window(n, f->window[b]);
    f->bit_reverse[b] = (uint16 *) setup_malloc(f, sizeof(uint16) * n8);
    if (!f->bit_reverse[b]) return error(f, VORBIS_outofmem);
    compute_bitreverse(n, f->bit_reverse[b]);
    return TRUE;
}