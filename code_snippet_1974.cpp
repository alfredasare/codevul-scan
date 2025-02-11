void TestCtrlClick(const std::string& id_of_anchor_to_click) {
  if (!IsValidAnchorId(id_of_anchor_to_click)) {
    LOG(ERROR) << "Invalid anchor ID: " << id_of_anchor_to_click;
    return;
  }
  // Rest of the code remains the same
}

bool IsValidAnchorId(const std::string& anchor_id) {
  static const std::set<char> allowed_chars = {"a-zA-Z0-9-_."};
  static const size_t max_length = 64;

  if (anchor_id.find_first_not_of(allowed_chars)!= std::string::npos) {
    return false;
  }

  if (anchor_id.length() > max_length) {
    return false;
  }

  return true;
}