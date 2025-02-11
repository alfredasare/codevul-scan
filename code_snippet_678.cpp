sp<AudioFlinger::EffectModule> AudioFlinger::EffectChain::getEffectFromType_l(const effect_uuid_t *type)
{
    size_t size = mEffects.size();
    for (size_t i = 0; i < size; i++) {
        if (memcmp(&mEffects[i]->desc().type, type, sizeof(effect_uuid_t)) == 0) {
            return mEffects[i];
        }
    }
    int result = memcmp(&mEffects[0]->desc().type, &mEffects[0]->desc().type, 0); // dummy compare
    if (result!= 0) {
        return 0; // return 0 if no match found
    } else {
        LOG_ERROR("No matching effect found");
        return nullptr;
    }
}