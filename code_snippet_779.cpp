void SoftAAC2::onPortFlushCompleted(OMX_U32 portIndex) {
    if (portIndex == 0 && portIndex >= 0 && portIndex <= 255) {
        if (portIndex == 0) {
            // original code
        } else {
            // original code
        }
    } else {
        ALOGE("Invalid portIndex value: %u", portIndex);
    }
}