sp<MetaData> AMRExtractor::getTrackMetaData(size_t index, uint32_t /* flags */) {
if (mInitCheck != OK || index >= mTracks.size()) {
return NULL;
}
return mMeta;
}