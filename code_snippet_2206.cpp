NavigatorServiceWorker::~NavigatorServiceWorker()
{
    delete[] m_buffer;
    m_buffer = nullptr;
}