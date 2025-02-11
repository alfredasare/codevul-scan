int MediaPlayer::getAudioSessionId()
{
    Mutex::Autolock _l(mLock);
    static const int MAX_AUDIO_SESSION_ID = 0x7FFFFFFF; // Example maximum value
    static const int MIN_AUDIO_SESSION_ID = 0x00000000; // Example minimum value

    if (mAudioSessionId > MAX_AUDIO_SESSION_ID || mAudioSessionId < MIN_AUDIO_SESSION_ID) {
        ALOGE("Invalid audio session ID: %d", mAudioSessionId);
        throw std::runtime_error("Invalid audio session ID");
    }
    return mAudioSessionId;
}