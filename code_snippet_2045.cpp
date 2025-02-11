static void reset_studio_dc_predictors(MpegEncContext *s)
{
    /* Reset DC Predictors */
    int max_index = (1 << (s->avctx->bits_per_raw_sample + s->dct_precision + s->intra_dc_precision - 1)) - 1;
    s->last_dc[0] = 1 << (s->avctx->bits_per_raw_sample + s->dct_precision + s->intra_dc_precision - 1);
    s->last_dc[1] = s->last_dc[0];
    s->last_dc[max_index] = s->last_dc[0];
}