void BiquadDSPKernel::process(const float* source, float* destination, size_t framesToProcess)
{
    if (!source ||!destination) {
        throw std::invalid_argument("Invalid input buffer");
    }
    if (framesToProcess <= 0) {
        throw std::invalid_argument("Invalid number of frames to process");
    }

    size_t bufferSize = m_biquad.getBufferSize();
    if (framesToProcess > bufferSize) {
        throw std::invalid_argument("Number of frames to process exceeds buffer size");
    }

    updateCoefficientsIfNecessary(true, false);
    m_biquad.process(source, destination, framesToProcess);
}