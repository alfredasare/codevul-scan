void beforeLoadEventSender::dispatchPendingEvents() {
    // Code for dispatching pending events
}

void ImageLoader::dispatchPendingBeforeLoadEvents() {
    beforeLoadEventSender beforeLoadEventSenderInstance;
    beforeLoadEventSenderInstance.dispatchPendingEvents();
}