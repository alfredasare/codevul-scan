#include "url_formatter.h"

bool AreWeShowingSignin(GURL url, SyncPromoUI::Source source,
                        std::string email) {
  // Sanitize the URL using url_formatter::FormatUrl()
  std::string clean_url_string = url_formatter::FormatUrl(url.spec());
  GURL clean_login_url(clean_url_string);

  GURL::Replacements replacements;
  replacements.ClearQuery();

  GURL cleaned_url = clean_login_url.ReplaceComponents(replacements);

  return (cleaned_url == clean_login_url && source != SyncPromoUI::SOURCE_UNKNOWN) ||
      (IsValidGaiaSigninRedirectOrResponseURL(cleaned_url) &&
       cleaned_url.spec().find("ChromeLoginPrompt") != std::string::npos &&
       !email.empty());
}