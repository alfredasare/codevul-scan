static int64_t pva_read_timestamp(struct AVFormatContext *s, int stream_index,
                                      int64_t *pos, int64_t pos_limit) {
    AVIOContext *pb = s->pb;
    PVAContext *pvactx = s->priv_data;
    int length, streamid;
    int64_t res = AV_NOPTS_VALUE;

    pos_limit = FFMIN(*pos + PVA_MAX_PAYLOAD_LENGTH * 8, (uint64_t) *pos + pos_limit);

    while (*pos < pos_limit) {
        res = AV_NOPTS_VALUE;
        if (*pos + sizeof(int64_t) > pos_limit) {
            break;
        }
        avio_seek(pb, *pos, SEEK_SET);

        pvactx->continue_pes = 0;
        if (read_part_of_packet(s, &res, &length, &streamid, 0)) {
            (*pos)++;
            continue;
        }
        if (streamid - 1 != stream_index || res == AV_NOPTS_VALUE) {
            *pos = avio_tell(pb) + length;
            continue;
        }
        break;
    }

    pvactx->continue_pes = 0;
    return res;
}