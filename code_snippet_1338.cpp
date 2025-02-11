void DontProceed() {
  if (!interstitial_page_ || interstitial_page_->isEmpty()) {
    std::cerr << "Error: interstitial_page_ is invalid" << std::endl;
    return;
  }
  interstitial_page_->DontProceed();
}