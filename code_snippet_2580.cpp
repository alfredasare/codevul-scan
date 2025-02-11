#include <sys/select.h> // for FD_SETSIZE

bool StartHandlerForClient(int fd) {
    if (fd < 0 || fd >= FD_SETSIZE) {
        fprintf(stderr, "Invalid file descriptor value: %d\n", fd);
        return false;
    }

    return HandlerStarter::Get()->StartHandlerForClient(GetCrashReporterClient(), fd);
}