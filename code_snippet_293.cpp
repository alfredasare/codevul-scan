status_t MediaPlayer::invoke(const Parcel& request, Parcel *reply)
{
 Mutex::Autolock _l(mLock);
 const bool hasBeenInitialized =
 ((uint32_t)mCurrentState!= (uint32_t)MEDIA_PLAYER_STATE_ERROR) &&
 (((uint32_t)mCurrentState & (uint32_t)MEDIA_PLAYER_IDLE)!= (uint32_t)MEDIA_PLAYER_IDLE);
 if ((mPlayer!= NULL) && hasBeenInitialized) {
        ALOGV("invoke %zu", request.dataSize());
 return  mPlayer->invoke(request, reply);
 }
 ALOGE("invoke failed: wrong state %X", (uint32_t)mCurrentState);
 return INVALID_OPERATION;
}