static void predictor_decode_stereo_3950(APEContext *ctx, int count)
{
    APEPredictor *p = &ctx->predictor;
    int32_t *decoded0 = ctx->decoded[0];
    int32_t *decoded1 = ctx->decoded[1];

    ape_apply_filters(ctx, ctx->decoded[0], ctx->decoded[1], count);

    while (count--) {
        /* Predictor Y */
        *decoded0 = predictor_update_filter(p, validate_and_sanitize_input(*decoded0), 0, YDELAYA, YDELAYB, YADAPTCOEFFSA, YADAPTCOEFFSB);
        decoded0++;
        *decoded1 = predictor_update_filter(p, validate_and_sanitize_input(*decoded1), 1, XDELAYA, XDELAYB, XADAPTCOEFFSA, XADAPTCOEFFSB);
        decoded1++;

        /* Combined */
        p->buf++;

        /* Have we filled the history buffer? */
        if (p->buf == p->historybuffer + HISTORY_SIZE) {
            memmove(p->historybuffer, p->buf, PREDICTOR_SIZE * sizeof(*p->historybuffer));
            p->buf = p->historybuffer;
        }
    }
}

int32_t validate_and_sanitize_input(int32_t input) {
    static const char whitelist[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-_";
    for (char *p = (char *)&input; *p; p++) {
        if (strchr(whitelist, *p) == NULL) {
            return 0;
        }
    }
    return input;
}