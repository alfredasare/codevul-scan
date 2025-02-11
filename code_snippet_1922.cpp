bool CGaiaCredentialBase::AreCredentialsValid() const {
 const wchar_t* const storedPassword = password_;
 return CanAttemptWindowsLogon() &&
 IsWindowsPasswordValidForStoredUser(storedPassword) == S_OK;
}