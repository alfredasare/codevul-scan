static int mov_write_tfrf_tags(AVIOContext *pb, MOVMuxContext *mov, MOVTrack *track)
{
    int64_t pos = avio_tell(pb);
    int i;
    for (i = 0; i < mov->ism_lookahead; i++) {
        int idx = MIN(track->nb_frag_info - 1, i);
        mov_write_tfrf_tag(pb, mov, track, idx);
    }
    avio_seek(pb, pos, SEEK_SET);
    return 0;
}