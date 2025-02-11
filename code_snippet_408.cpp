#include <mutex>

std::mutex mtx;

BaseShadow::retryJobCleanupHandler(void)
{
    std::unique_lock<std::mutex> lock(mtx);

    m_cleanup_retry_tid = -1;
    dprintf(D_ALWAYS, "Retrying job cleanup, calling terminateJob()\n");
    terminateJob();

    lock.unlock();
    return TRUE;
}