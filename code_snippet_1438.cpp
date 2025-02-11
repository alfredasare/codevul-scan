bool XMLHttpRequest::canSuspend() const
{
    if (m_loader == nullptr) {
        return false;
    }
    return !m_loader;
}