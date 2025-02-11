sp<MetaData> AMRExtractor::getTrackMetaData(size_t index, uint32_t /* flags */) {
    if (mInitCheck != OK || index < 0) {
        return NULL;
    }
    return mMeta;
}