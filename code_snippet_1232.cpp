c++
float TextAutosizer::computeAutosizedFontSize(float specifiedSize, float multiplier)
{
    const float pleasantSize = 16;
    const float gradientAfterPleasantSize = 0.5;

    float computedSize;
    if (specifiedSize <= pleasantSize)
        computedSize = multiplier * specifiedSize;
    else {
        computedSize = multiplier * pleasantSize + gradientAfterPleasantSize * (specifiedSize - pleasantSize);
        if (computedSize < specifiedSize)
            computedSize = specifiedSize;

        // Add check for bounds
        if (computedSize > std::numeric_limits<float>::max()) {
            computedSize = std::numeric_limits<float>::max();
        }
        else if (computedSize < std::numeric_limits<float>::min()) {
            computedSize = std::numeric_limits<float>::min();
        }
    }
    return computedSize;
}