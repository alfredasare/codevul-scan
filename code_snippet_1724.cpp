void AudioSource::rampVolume(
    int32_t startFrame, int32_t rampDurationFrames,
    uint8_t *data, size_t bytes) {

    const int32_t kShift = 14;
    int32_t fixedMultiplier = (startFrame << kShift) / rampDurationFrames;
    const int32_t nChannels = mRecord->channelCount();
    int32_t stopFrame = std::min(startFrame + bytes / sizeof(int16_t), rampDurationFrames);

    //... (rest of the code remains the same)
}