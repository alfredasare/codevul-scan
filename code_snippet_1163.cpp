void PolkitResultEventLoop::requestQuit(const PolkitQt1::Authority::Result& result)
{
    if (result.isValid() && result.size() <= sizeof(m_result)) {
        m_result = result;
        quit();
    } else {
        qWarning() << "Invalid or oversized result object";
    }
}