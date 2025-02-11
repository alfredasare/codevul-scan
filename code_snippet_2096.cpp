class Camera3Device {
public:
    // ...
private:
    mutable std::mutex mRequestLock;
    bool mReconfigured;
};

void Camera3Device::RequestThread::configurationComplete() {
    std::unique_lock<std::mutex> lock(mRequestLock);
    mReconfigured = true;
}