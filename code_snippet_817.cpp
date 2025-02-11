c++
static bool compare_effect_uuid(const effect_uuid_t* a, const effect_uuid_t* b) {
    for (size_t i = 0; i < sizeof(effect_uuid_t); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

sp<AudioFlinger::EffectModule> AudioFlinger::EffectChain::getEffectFromType_l(
        const effect_uuid_t *type)
{
    size_t size = mEffects.size();

    for (size_t i = 0; i < size; i++) {
        if (compare_effect_uuid(&mEffects[i]->desc().type, type)) {
            return mEffects[i];
        }
    }
    return nullptr; // prefer nullptr instead of 0 for null pointers in modern C++ code
}