static int64_t pva_read_timestamp(struct AVFormatContext *s, int stream_index,
                                  int64_t *pos, int64_t pos_limit) {
    AVIOContext *pb = s->pb;
    PVAContext *pvactx = s->priv_data;
    int length, streamid;
    int64_t res = AV_NOPTS_VALUE;

    pos_limit = FFMIN(*pos+PVA_MAX_PAYLOAD_LENGTH*8, (uint64_t)*pos+pos_limit);

    while (*pos < pos_limit) {
        res = AV_NOPTS_VALUE;
        avio_seek(pb, *pos, SEEK_SET);

        pvactx->continue_pes = 0;
        if (stream_index >= 0 && stream_index < pvactx->streamid_count) {
            if (read_part_of_packet(s, &res, &length, &pvactx->streamid[stream_index], 0)) {
                (*pos)++;
                continue;
            }
        } else {
            // Handle invalid stream_index
        }
        if (res == AV_NOPTS_VALUE) {
            *pos = avio_tell(pb) + length;
            continue;
        }
        break;
    }

    pvactx->continue_pes = 0;
    return res;
}