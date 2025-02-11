String SystemClipboard::ReadPlainText() {
  size_t bufferLength = buffer_.size();
  size_t maxLength = 1024; // adjust this value based on your requirements

  if (bufferLength > maxLength) {
    buffer_ = buffer_.substr(0, maxLength);
  }

  return std::string(buffer_.c_str(), buffer_.size());
}