c++
status_t MediaPlayer::invoke(const Parcel& request, Parcel *reply)
{
 Mutex::Autolock _l(mLock);
 if (mPlayer != NULL) {
        ALOGV("invoke %zu", request.dataSize());
        return  mPlayer->invoke(request, reply);
    }
    ALOGE("invoke failed: wrong state %X", mCurrentState);
    return INVALID_OPERATION;
}