void UpdateScreenInfo(float pixel_ratio) {
  std::unique_ptr<ClientHints> updatedClientHints = client_hints_->Clone();
  updatedClientHints->UpdateScreenInfo(pixel_ratio);
  client_hints_ = std::move(updatedClientHints);
}