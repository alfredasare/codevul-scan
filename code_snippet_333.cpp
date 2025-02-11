int MediaPlayer::getAudioSessionId()
{
    Mutex::Lock lock(mLock); // Acquire lock before accessing mAudioSessionId
    Mutex::Autolock _l(lock); // Use an autolock to unlock the lock
    return mAudioSessionId;
}