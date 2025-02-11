static int mov_write_tfrf_tags(AVIOContext *pb, MOVMuxContext *mov,
                           MOVTrack *track)
{
    int64_t pos = avio_tell(pb);
    int i;
    if (mov->ism_lookahead < 0 || mov->ism_lookahead >= track->nb_frag_info) {
        av_log(NULL, AV_LOG_ERROR, "ism_lookahead out of bounds\n");
        return -1;
    }
    for (i = 0; i < mov->ism_lookahead; i++) {
        /* Update the tfrf tag for the last ism_lookahead fragments,
         * nb_frag_info - 1 is the next fragment to be written. */
        if (track->nb_frag_info - 2 - i < 0 || track->nb_frag_info - 2 - i >= track->nb_frag_info) {
            av_log(NULL, AV_LOG_ERROR, "frag_info index out of bounds\n");
            return -1;
        }
        mov_write_tfrf_tag(pb, mov, track, track->nb_frag_info - 2 - i);
    }
    avio_seek(pb, pos, SEEK_SET);
    return 0;
}