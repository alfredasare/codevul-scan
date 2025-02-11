sp<MetaData> NuPlayer::GenericSource::doGetFormatMeta(bool audio) const {
    sp<MediaSource> source = (audio ? mAudioTrack.mSource : mVideoTrack.mSource);

    if (source != nullptr) {
        return source->getFormat();
    } else {
        return nullptr;
    }
}