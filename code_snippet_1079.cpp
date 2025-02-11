status_t OMX::createPersistentInputSurface(
        sp<IGraphicBufferProducer> *bufferProducer,
        sp<IGraphicBufferConsumer> *bufferConsumer) {
    if (bufferProducer == nullptr || bufferConsumer == nullptr) {
        return BAD_VALUE;
    }

    return OMXNodeInstance::createPersistentInputSurface(
            bufferProducer, bufferConsumer);
}