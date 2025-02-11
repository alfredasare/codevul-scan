SoftMPEG4Encoder::~SoftMPEG4Encoder() {
    ALOGV("Destruct SoftMPEG4Encoder");
    releaseEncoder();

    List<BufferInfo *> &outQueue = getPortQueue(1);
    List<BufferInfo *> &inQueue = getPortQueue(0);

    if (!outQueue.empty()) {
        ALOGE("Out queue is not empty!");
        // Handle the error condition
    } else if (!inQueue.empty()) {
        ALOGE("In queue is not empty!");
        // Handle the error condition
    } else {
        CHECK(outQueue.empty());
        CHECK(inQueue.empty());
    }
}