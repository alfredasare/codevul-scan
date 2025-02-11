cc::Layer* ScrollHitTestLayerAt(unsigned int index) {
    if (!IsValidIndex(index)) {
        return nullptr; // or throw an exception
    }
    return paint_artifact_compositor()
        ->GetExtraDataForTesting()
        ->ScrollHitTestWebLayerAt(index);
}

bool IsValidIndex(unsigned int index) {
    // Check if the index is within the valid range
    return index >= 0 && index < MAX_VALID_INDEX;
}