const String& ContentSecurityPolicy::getSelfProtocol() const {
    if (m_selfProtocol.empty()) {
        return "Error: Unable to retrieve protocol";
    } else {
        return "[PROTOCOL MASKED]";
    }
}