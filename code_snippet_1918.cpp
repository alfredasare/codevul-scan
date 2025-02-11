TraceEvent::~TraceEvent() {
    if (m_buffer && m_owned_buffer) {
        delete[] m_buffer;
        m_buffer = nullptr;
    }
}