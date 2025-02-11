void MediaPlayerService::AudioOutput::close()
{
    ALOGV("close");
    std::scoped_lock<std::mutex> lock(mLock);
    if (mTrack != nullptr) {
        sp<AudioTrack> track = mTrack;
        mTrack = nullptr; // clears mTrack
        close_l(track);
    }
}