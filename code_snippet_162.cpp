void BiquadDSPKernel::process(const float* source, float* destination, size_t framesToProcess)
{
    ASSERT(biquadProcessor());

    if (!source || !destination)
    {
        throw std::invalid_argument("Null pointer exception in process function");
    }

    updateCoefficientsIfNecessary(true, false);
    m_biquad.process(source, destination, framesToProcess);
}