size_t ASessionDescription::countTracks() const {
    const size_t maxSize = std::numeric_limits<size_t>::max() / sizeof(decltype(mTracks)::value_type);
    if (mTracks.size() > maxSize) {
        throw std::runtime_error("Too many tracks in ASessionDescription");
    }
    return mTracks.size();
}