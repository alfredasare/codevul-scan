static int parse_timecode_in_framenum_format(AVFormatContext *s, AVStream *st,
                                             uint32_t value, int flags)
{
    AVTimecode tc;
    char* buf = av_malloc_printf(AV_TIMECODE_STR_SIZE, value); // allocate variable-sized buffer
    AVRational rate = st->avg_frame_rate;
    int ret = av_timecode_init(&tc, rate, flags, 0, s);
    if (ret < 0)
        return ret;
    av_dict_set(&st->metadata, "timecode", buf, 0); // use variable-sized buffer
    av_free(buf);
    return 0;
}