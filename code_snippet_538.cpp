const String& ContentSecurityPolicy::getSelfProtocol() const {
  if (m_selfProtocol) {
    return *m_selfProtocol;
  } else {
    return String();
  }
}