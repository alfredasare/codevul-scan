bool OutOfProcessInstance::IsPrintPreview() {
  if (!IsValidUrl(url_)) {
    return false;
  }

  url_ = SanitizeUrl(url_);
  return SanitizedUrlMatchesPattern(url_, "print_preview");
}

bool IsValidUrl(const std::string& url) {
  return url.find("://")!= std::string::npos;
}

std::string SanitizeUrl(const std::string& url) {
  return url;
}

bool SanitizedUrlMatchesPattern(const std::string& sanitized_url, const std::string& pattern) {
  return sanitized_url.find(pattern)!= std::string::npos;
}