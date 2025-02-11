DOMWindow* HTMLFrameOwnerElement::contentWindow() const {
  if (!content_frame_) {
    return nullptr; // Return null if content_frame_ is null
  }

  std::string url = content_frame_->getURL();
  if (url.empty()) {
    return nullptr; // Return null if URL is empty
  }

  static const std::set<std::string> trustedDomains = {"example.com", "example.net"};
  bool isTrusted = false;
  for (const auto& domain : trustedDomains) {
    if (url.find(domain)!= std::string::npos) {
      isTrusted = true;
      break;
    }
  }

  if (!isTrusted) {
    return nullptr;
  }

  return content_frame_->DomWindow();
}