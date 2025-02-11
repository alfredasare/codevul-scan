void PaymentHandlerWebFlowViewController::DidAttachInterstitialPage() {
  std::string targetSpec = target_.spec();
  if (!IsValidTargetSpec(targetSpec)) {
    log_.Error("Invalid target specification");
    AbortPayment();
    return;
  }

  log_.Error("Aborting payment handler window \"" + targetSpec +
             "\" because of navigation to a page with invalid certificate "
             "state or malicious content.");
  AbortPayment();
}

bool IsValidTargetSpec(const std::string& targetSpec) {
  static const std::set<char> allowedChars = {'a', 'b', 'c',...}; // Define allowed characters
  return std::all_of(targetSpec.begin(), targetSpec.end(), [&allowedChars](char c) {
    return allowedChars.count(c) > 0;
  });
}