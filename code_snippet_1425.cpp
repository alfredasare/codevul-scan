static av_cold int init(AVFilterContext *ctx)
{
    FPSContext *s = ctx->priv;
    AVFrame **fifo;

    if (!(fifo = av_calloc(2, sizeof(AVFrame*)))) {
        av_log(ctx, AV_LOG_ERROR, "Failed to allocate fifo\n");
        return AVERROR(ENOMEM);
    }

    s->fifo = fifo;
    s->pts          = AV_NOPTS_VALUE;
    s->first_pts    = AV_NOPTS_VALUE;

    av_log(ctx, AV_LOG_VERBOSE, "fps=%d/%d\n", s->framerate.num, s->framerate.den);
    return 0;
}