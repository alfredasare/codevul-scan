ChromePaymentRequestDelegate::GetPersonalDataManager() {
  Profile* profile = Profile::FromBrowserContext(web_contents_->GetBrowserContext());
  if (!profile) {
    // Handle error
  }

  std::string sanitizedPath = profile->GetOriginalProfile();
  sanitizedPath = sanitizer::sanitizePath(sanitizedPath);
  return autofill::PersonalDataManagerFactory::GetForProfile(sanitizedPath);
}