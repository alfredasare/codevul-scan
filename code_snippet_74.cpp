static int mxf_read_content_storage(void *arg, AVIOContext *pb, int tag, int size, UID uid, int64_t klv_offset)
{
    MXFContext *mxf = arg;
    switch (tag) {
    case 0x1901:
        if (mxf->packages_refs) {
            int count = mxf_read_strong_ref_array(pb, &mxf->packages_refs, &mxf->packages_count);
            if (count >= 0) {
                for (int i = 0; i < count; i++) {
                    // Process the array elements
                }
            } else {
                av_log(mxf->fc, AV_LOG_VERBOSE, "Error reading packages_refs\n");
                return -1;
            }
        }
        return 0;
    case 0x1902:
        int count = mxf_read_strong_ref_array(pb, &mxf->essence_container_data_refs, &mxf->essence_container_data_count);
        if (count >= 0) {
            for (int i = 0; i < count; i++) {
                // Process the array elements
            }
        } else {
            av_log(mxf->fc, AV_LOG_VERBOSE, "Error reading essence_container_data_refs\n");
            return -1;
        }
        return 0;
    }
    return 0;
}