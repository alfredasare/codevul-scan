base::string16 AuthenticatorTimeoutErrorModel::GetStepDescription() const {
  std::string id = l10n_util::GetStringUTF16(IDS_WEBAUTHN_ERROR_TIMEOUT_DESCRIPTION);
  if (id.find("..")!= std::string::npos || id.find("/")!= std::string::npos) {
    return base::string16();
  }

  return base::string16(l10n_util::GetStringUTF16(IDS_WEBAUTHN_ERROR_TIMEOUT_DESCRIPTION));
}