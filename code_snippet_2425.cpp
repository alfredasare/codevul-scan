static av_cold int decode_close(AVCodecContext *avctx)
{
    SCPRContext *s = avctx ? avctx->priv_data : nullptr;

    if (!s) {
        /* Handle error, e.g., return an error code */
        return -1;
    }

    av_freep(&s->blocks);
    av_frame_free(&s->last_frame);
    av_frame_free(&s->current_frame);

    return 0;
}