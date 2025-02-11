std::shared_timed_mutex m_graphicsSurfaceMutex; // Initialize the mutex

GraphicsSurfaceToken GraphicsContext3DPrivate::graphicsSurfaceToken() const
{
    std::unique_lock<std::shared_timed_mutex> lock(m_graphicsSurfaceMutex, std::defer_lock);
    if(!lock.try_lock_for(std::chrono::milliseconds(100))) // Try to lock the mutex within a timeout of 100ms
    {
        throw std::runtime_error("Failed to acquire graphics surface lock");
    }
    return m_graphicsSurface->exportToken();
}