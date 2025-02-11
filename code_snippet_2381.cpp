status_t OMXNodeInstance::createPersistentInputSurface(
    sp<IGraphicBufferProducer> *bufferProducer,
    sp<IGraphicBufferConsumer> *bufferConsumer) {
    String8 name("GraphicBufferSource");
    // Validate the input name
    if (name.indexOf('/') != -1 || !isAllowedName(name.string())) {
        ALOGE("Invalid name: %s", name.string());
        return BAD_VALUE;
    }

    sp<IGraphicBufferProducer> producer;
    sp<IGraphicBufferConsumer> consumer;
    BufferQueue::createBufferQueue(&producer, &consumer);
    consumer->setConsumerName(name);
    consumer->setConsumerUsageBits(GRALLOC_USAGE_HW_VIDEO_ENCODER);

    //... (rest of the function remains unchanged)

    return OK;
}

bool isAllowedName(const char* name) {
    static const char* allowedNames[] = {"GraphicBufferSource", "AllowedName1", "AllowedName2"};
    for (const char* allowedName : allowedNames) {
        if (strcmp(name, allowedName) == 0) {
            return true;
        }
    }
    return false;
}