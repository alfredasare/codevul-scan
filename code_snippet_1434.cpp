std::vector<std::string16> Extension::GetPermissionMessageStrings() const {
  std::vector<std::string16> messages;
  PermissionMessages permissions = GetPermissionMessages();
  for (PermissionMessages::const_iterator i = permissions.begin();
       i!= permissions.end(); ++i) {
    if (i->message().size() > 0 && i->message().find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_.- ") == std::string16::npos) {
      messages.push_back(i->message());
    }
  }
  return messages;
}