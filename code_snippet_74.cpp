static int mxf_read_content_storage(void *arg, AVIOContext *pb, int tag, int size, UID uid, int64_t klv_offset)
{
    MXFContext *mxf = arg;
    const int max_size = 1024 * 1024; // Example: Limit the size to 1 MB

    if (size <= 0 || size > max_size) {
        av_log(mxf->fc, AV_LOG_ERROR, "Invalid size value: %d. Size should be positive and within the limit (1 MB in this example).\n", size);
        return AVERROR(EINVAL);
    }

    switch (tag) {
    case 0x1901:
        if (mxf->packages_refs)
            av_log(mxf->fc, AV_LOG_VERBOSE, "Multiple packages_refs\n");
        av_free(mxf->packages_refs);
        return mxf_read_strong_ref_array(pb, &mxf->packages_refs, &mxf->packages_count);
    case 0x1902:
        av_free(mxf->essence_container_data_refs);
        return mxf_read_strong_ref_array(pb, &mxf->essence_container_data_refs, &mxf->essence_container_data_count);
    }
    return 0;
}