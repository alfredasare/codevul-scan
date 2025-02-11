PasswordStore::FormDigest CredentialManagerImpl::GetSynthesizedFormForOrigin() const {
  PasswordStore::FormDigest digest = {autofill::PasswordForm::SCHEME_HTML, "", GetLastCommittedURL().GetOrigin()};
  std::string origin_spec = digest.origin.spec();
  if (origin_spec.size() > digest.signon_realm.size()) {
    throw std::length_error("signon_realm buffer too small");
  }
  std::copy(origin_spec.begin(), origin_spec.end(), digest.signon_realm.begin());
  return digest;
}