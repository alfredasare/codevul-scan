bool AreWeShowingSignin(GURL url, SyncPromoUI::Source source, std::string email) {
  GURL::Replacements replacements;
  replacements.ClearQuery();
  GURL clean_login_url = GURL(GaiaUrls::GetInstance()->service_login_url()).ReplaceComponents(replacements);

  try {
    return (url.ReplaceComponents(replacements) == clean_login_url &&
            source!= SyncPromoUI::SOURCE_UNKNOWN) ||
           (IsValidGaiaSigninRedirectOrResponseURL(url) &&
            url.spec().find("ChromeLoginPrompt")!= std::string::npos &&
           !email.empty());
  } catch (const GURL::Replacements::InvalidReplacement& e) {
    LOG(ERROR) << "Error replacing URL components: " << e.what();
    return false;
  }
}