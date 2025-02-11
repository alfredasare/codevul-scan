static int mov_read_mdat(MOVContext *c, AVIOContext *pb, MOVAtom atom)
{
    if (atom.size > AVIO_BUFFER_SIZE || atom.size < 0) {
        av_log(c, AV_LOG_ERROR, "Invalid atom size: %d\n", atom.size);
        return -1;
    }

    c->found_mdat = 1;
    if (avio_read(pb, c->mdat_buffer, atom.size) < 0) {
        av_log(c, AV_LOG_ERROR, "Error reading mdat data\n");
        return -1;
    }

    if (atom.size == 0) { /* wrong one (MP4) */
        av_log(c, AV_LOG_WARNING, "Invalid atom size: 0\n");
        return -1;
    }

    return 0; /* now go for moov */
}