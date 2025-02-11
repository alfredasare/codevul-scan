void PolkitResultEventLoop::requestQuit(const PolkitQt1::Authority::Result& result)
{
    if (result.isValid()) { 
        m_result = result;
    } else {
        // Handle invalid result error
        //...
    }
    quit();
}