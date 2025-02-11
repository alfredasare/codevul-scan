static int mov_write_dref_tag(AVIOContext *pb)
{
    const int tag_size = 28;
    const int url_size = 12;

    if (avio_size(pb) + tag_size > avio_limit(pb)) {
        av_log(NULL, AV_LOG_ERROR, "Buffer overflow\n");
        return AVERROR_EOF;
    }

    avio_wb32(pb, 28); /* size */
    ffio_wfourcc(pb, "dref");
    avio_wb32(pb, 0); /* version & flags */
    avio_wb32(pb, 1); /* entry count */

    const int position = avio_tell(pb);
    if (avio_size(pb) + url_size > avio_limit(pb)) {
        av_log(NULL, AV_LOG_ERROR, "Buffer overflow\n");
        return AVERROR_EOF;
    }

    avio_wb32(pb, url_size); /* size */
    ffio_wfourcc(pb, "url ");
    avio_wb32(pb, 1); /* version & flags */

    return position + tag_size;
}