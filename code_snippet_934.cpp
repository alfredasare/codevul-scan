status_t OMX::createPersistentInputSurface(
    sp<IGraphicBufferProducer> *bufferProducer,
    sp<IGraphicBufferConsumer> *bufferConsumer) {
    if (bufferProducer == nullptr || bufferConsumer == nullptr) {
        return STATUS_ERROR;
    }
    std::set<std::string> allowedExtensions = {"png", "jpg", "jpeg"};
    if (!allowedExtensions.count(bufferProducer->getMimeType())) {
        return STATUS_ERROR;
    }
    std::string sanitizedInput = ESAPI::encodeForHTML(bufferProducer->getData());
    return OMXNodeInstance::createPersistentInputSurface(bufferProducer, bufferConsumer, sanitizedInput);
}