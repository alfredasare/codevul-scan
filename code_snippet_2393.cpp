void listenCallback_helper(int fd, short flags, void *param) {
    try {
        android::listenCallback(fd, flags, param);
    } catch (const std::exception& e) {
        LOG_ERROR("listenCallback_helper failed: %s", e.what());
    }
}