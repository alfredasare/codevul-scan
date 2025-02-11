void Camera3Device::RequestThread::configurationComplete() {
    std::lock_guard<Mutex> lock(mRequestLock);
    mReconfigured = true;
}