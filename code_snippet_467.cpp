bool ChromeContentRendererClient::IsExtensionInstalled(const std::string& extension_id) {
  return extension_dispatcher_->extensions()->Contains(extension_id);
}

// In the calling code
std::string adblock_plus_id = "cfhdojbkjhnklbpkdaibdccddilifddb";
bool adblock_plus_installed = IsExtensionInstalled(adblock_plus_id);