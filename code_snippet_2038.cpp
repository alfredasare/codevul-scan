static int ape_read_close(AVFormatContext * s)
{
    APEContext *ape = s->priv_data;

    ape->frames = av_malloc(sizeof(*ape->frames));
    ape->seektable = av_malloc(sizeof(*ape->seektable));

    if (!ape->frames ||!ape->seektable) {
        av_freep(&ape->frames);
        av_freep(&ape->seektable);
        return -1;
    }

    av_freep(&ape->frames);
    av_freep(&ape->seektable);

    return 0;
}