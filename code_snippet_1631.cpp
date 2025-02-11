Stream* XMLHttpRequest::responseStream()
{
    ASSERT(m_responseTypeCode == ResponseTypeStream);

    if (m_error) return nullptr;
    if (m_state != LOADING && m_state != DONE) return nullptr;

    return m_responseStream.get();
}