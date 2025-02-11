bool StartHandlerForClient(int fd) {
    // Validate the fd parameter
    if (fd < 0 || fd > 255) {
        return false;
    }

    // Use a whitelist approach to allow only specific and expected values
    static const int allowed_fds[] = {0, 1, 2};
    bool isValidFd = false;
    for (int i = 0; i < sizeof(allowed_fds) / sizeof(allowed_fds[0]); i++) {
        if (fd == allowed_fds[i]) {
            isValidFd = true;
            break;
        }
    }

    if (!isValidFd) {
        return false;
    }

    return HandlerStarter::Get()->StartHandlerForClient(GetCrashReporterClient(), fd);
}