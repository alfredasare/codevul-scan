c++
status_t SoundTriggerHwService::attach(const sound_trigger_module_handle_t handle,
                                       const sp<ISoundTriggerClient>& client,
                                       sp<ISoundTrigger>& moduleInterface)
{
    ALOGV("attach module %d", handle);
    AutoMutex lock(mServiceLock);
    if (!captureHotwordAllowed()) {
        return PERMISSION_DENIED;
    }
    moduleInterface.clear();
    if (client == 0) {
        return BAD_VALUE;
    }
    ssize_t index = mModules.indexOfKey(handle);
    if (index < 0) {
        return BAD_VALUE;
    }
    sp<Module> module = mModules.valueAt(index);
    module->setClient(client);
    IInterface::asBinder(client)->linkToDeath(module);
    module->setCaptureState_l(mCaptureState);
    moduleInterface = module;
    return NO_ERROR;
}