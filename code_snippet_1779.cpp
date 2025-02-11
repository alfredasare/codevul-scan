bool CGaiaCredentialBase::AreCredentialsValid() const {
  if (password_.empty()) {
    return false;
  }
  return CanAttemptWindowsLogon() && IsWindowsPasswordValidForStoredUser(password_) == S_OK;
}