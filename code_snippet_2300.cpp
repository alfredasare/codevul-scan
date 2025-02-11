bool HevcParameterSets::findParam64(uint32_t key, uint64_t *param) {
    if (key > UINT32_MAX) {
        throw std::overflow_error("Key value exceeds maximum allowed value");
    }
    return findParam(static_cast<uint32_t>(key), param, mParams);
}