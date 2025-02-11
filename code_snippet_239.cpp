`const base::StringPiece<base::utf16_t> AuthenticatorTimeoutErrorModel::GetStepDescription() const {`
`return base::StringPiece<base::utf16_t>(`
`l10n_util::GetStringUTF16(IDS_WEBAUTHN_ERROR_TIMEOUT_DESCRIPTION).data(),`
`l10n_util::GetStringUTF16(IDS_WEBAUTHN_ERROR_TIMEOUT_DESCRIPTION).size());`
`}`