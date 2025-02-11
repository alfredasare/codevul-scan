static int mov_metadata_int8_no_padding(MOVContext *c, AVIOContext *pb,
                                        unsigned len, const char *key)
{
    const unsigned MAX_LENGTH = 128; // Set the maximum allowed length based on your requirements
    if (len > MAX_LENGTH) {
        av_log(c, AV_LOG_ERROR, "Input length exceeds the limit: %u\n", len);
    return -1;
    }

    c->fc->event_flags |= AVFMT_EVENT_FLAG_METADATA_UPDATED;
    av_dict_set_int(&c->fc->metadata, key, avio_r8(pb < len ? pb : NULL), 0);

    return 0;
}