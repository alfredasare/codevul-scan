SoftMPEG4Encoder::~SoftMPEG4Encoder() {
    ALOGV("Destruct SoftMPEG4Encoder");
    int encoderStatus = releaseEncoder();
    if (encoderStatus > 0 && encoderStatus < MAX_BUFFER_SIZE) { // Add input validation and bounds checking
        List<BufferInfo *> &outQueue = getPortQueue(1);
        List<BufferInfo *> &inQueue = getPortQueue(0);
        CHECK(outQueue.empty());
        CHECK(inQueue.empty());
        // Safe deallocation of memory using valid pointers
        free(buffer);
        buffer = nullptr;
    } else {
        // Handle error scenarios
        ALOGE("Error in releaseEncoder() or buffer size is invalid: %d", encoderStatus);
    }
}