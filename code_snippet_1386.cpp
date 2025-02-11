BpSoundTriggerHwService(const sp<IBinder>& impl, size_t maxBufferSize = std::numeric_limits<size_t>::max())
    : BpInterface<ISoundTriggerHwService>(impl)
{
    mMaxBufferSize = maxBufferSize;
}