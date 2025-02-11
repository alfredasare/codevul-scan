size_t ASessionDescription::countTracks() const {
    if (!isValid()) {
        throw std::runtime_error("Object not initialized");
    }
    if (!hasAccessPermission()) {
        throw std::runtime_error("Insufficient permissions");
    }
    return mTracks.size();
}