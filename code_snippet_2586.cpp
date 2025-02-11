c++
void ImageLoader::dispatchPendingBeforeLoadEvents()
{
    std::unique_lock<std::mutex> lock(beforeLoadEventMutex);
    beforeLoadEventSender().dispatchPendingEvents();
}