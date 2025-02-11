++
void OMXCodec::setG711Format(int32_t sampleRate, int32_t numChannels) {
    CHECK(!mIsEncoder);

    // Validate input parameters
    if (sampleRate < 0 || sampleRate > 48000) {
        throw std::invalid_argument("Invalid sample rate");
    }
    if (numChannels < 1 || numChannels > 2) {
        throw std::invalid_argument("Invalid number of channels");
    }

    // Use safer arithmetic operations
    int32_t rawSampleRate = std::max(1, std::min(48000, sampleRate));
    int32_t rawNumChannels = std::max(1, std::min(2, numChannels));

    setRawAudioFormat(kPortIndexInput, rawSampleRate, rawNumChannels);
}