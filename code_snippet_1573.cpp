static av_cold int init(AVFilterContext *ctx)
{
    FPSContext *s = ctx->priv;

    if (!(s->fifo = av_fifo_alloc(2 * sizeof(AVFrame*) + sizeof(void*) - 1)))
        return AVERROR(ENOMEM);

    if (!s->fifo) {
        av_log(ctx, AV_LOG_ERROR, "Failed to allocate memory for the FIFO.\n");
        return AVERROR(ENOMEM);
    }

    s->pts = AV_NOPTS_VALUE;
    s->first_pts = AV_NOPTS_VALUE;

    av_log(ctx, AV_LOG_VERBOSE, "fps=%d/%d\n", s->framerate.num, s->framerate.den);
    return 0;
}