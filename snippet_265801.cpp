bool CWebSession::IsAdmin() const { return IsLoggedIn() && m_pUser->IsAdmin(); }