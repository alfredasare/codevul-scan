void SoundChannel::autoPause()
{
 Mutex::Autolock lock(&mLock);
 if (mState!= nullptr && *mState == PLAYING) {
     ALOGV("pause track");
     *mState = PAUSED;
     mAutoPaused = true;
     mAudioTrack->pause();
 } else {
     ALOGE("Error: mState is invalid or not in PLAYING state");
 }
}