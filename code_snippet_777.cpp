#include <mutex>

std::mutex mtx;

void IPCThreadState::decStrongHandle(int32_t handle)
{
    std::unique_lock<std::mutex> lock(mtx);

    LOG_REMOTEREFS("IPCThreadState::decStrongHandle(%d)\n", handle);

    mOut.writeInt32(BC_RELEASE);
    mOut.writeInt32(handle);

    // Release the handle and ensure it's not used afterward
    // Perform cleanup or other operations here if necessary
}