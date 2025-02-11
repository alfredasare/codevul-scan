const std::string MessageIterator::NextString() const {
  std::string val;
  size_t maxLength = 1024; // adjust this value based on your requirements
  iter_.ReadString(&val, maxLength);
  if (val.length() > maxLength) {
    val = val.substr(0, maxLength);
  }
  return val;
}