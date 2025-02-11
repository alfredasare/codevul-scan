static int aa_read_close(AVFormatContext *s)
{
    AADemuxContext *c = s ? s->priv_data : NULL;

    if (c) {
        av_freep(&c->tea_ctx);
    }

    return 0;
}