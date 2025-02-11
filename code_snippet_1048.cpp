float TextAutosizer::computeAutosizedFontSize(float specifiedSize, float multiplier)
{
    const float pleasantSize = 16.0f;
    const float gradientAfterPleasantSize = 0.5f;

    float computedSize;
    if (specifiedSize <= pleasantSize)
        computedSize = multiplier * specifiedSize;
    else {
        computedSize = multiplier * pleasantSize + gradientAfterPleasantSize * (specifiedSize - pleasantSize);
        if (computedSize > FLT_MAX || computedSize < specifiedSize)
            computedSize = specifiedSize;
    }
    return computedSize;
}