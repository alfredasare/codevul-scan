AnonymizedPaymentData ChromePaymentRequestDelegate::GetPersonalData() {
  autofill::PersonalDataManager* personal_data_manager =
      autofill::PersonalDataManagerFactory::GetForProfile(
          Profile::FromBrowserContext(web_contents_->GetBrowserContext())
              ->GetOriginalProfile());
  
  AnonymizedPaymentData anonymized_data;
  // Populate the anonymized_data with necessary non-sensitive information
  // only.
  
  return anonymized_data;
}