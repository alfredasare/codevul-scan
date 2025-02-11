static int asf_read_close(AVFormatContext *s)
{
    if (!s) {
        av_log(NULL, AV_LOG_ERROR, "asf_read_close: Invalid format context\n");
        return AVERROR(EINVAL);
    }

    asf_reset_header(s);

    return 0;
}