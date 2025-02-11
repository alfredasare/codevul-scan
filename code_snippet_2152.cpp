PasswordStore::FormDigest CredentialManagerImpl::GetSynthesizedFormForOrigin() const {
  PasswordStore::FormDigest digest = {autofill::PasswordForm::SCHEME_HTML,
                                      std::string(),
                                      GetLastCommittedURL().GetOrigin().GetSpec()};
  digest.signon_realm = digest.origin;
  return digest;
}