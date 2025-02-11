static int cine_read_packet(AVFormatContext *avctx, AVPacket *pkt)
{
    CineDemuxContext *cine = avctx->priv_data;
    AVStream *st = avctx->streams[0];
    AVIOContext *pb = avctx->pb;
    int n, size, ret;

    if (cine->pts >= st->duration)
        return AVERROR_EOF;

    avio_seek(pb, st->index_entries[cine->pts].pos, SEEK_SET);
    n = avio_rl32(pb);
    if (n < 8)
        return AVERROR_INVALIDDATA;
    if (n > INT_MAX - AV_INPUT_BUFFER_PADDING_SIZE) {
        av_log(avctx, AV_LOG_ERROR, "Invalid 'n' value: %d\n", n);
        return AVERROR_INVALIDDATA;
    }
    avio_skip(pb, n -