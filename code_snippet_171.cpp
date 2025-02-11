status_t MediaPlayerService::AudioOutput::attachAuxEffect(int effectId)
{
    ALOGV("attachAuxEffect(%d)", effectId);
    const int minEffectId = 0;
    const int maxEffectId = 100; // or any other appropriate upper limit
    Mutex::Autolock lock(mLock);
    if (effectId < minEffectId || effectId > maxEffectId) {
        ALOGE("Invalid effectId: %d. Must be between %d and %d.", effectId, minEffectId, maxEffectId);
        return INVALID_OPERATION;
    }
    mAuxEffectId = effectId;
    if (mTrack != 0) {
        return mTrack->attachAuxEffect(effectId);
    }
    return NO_ERROR;
}