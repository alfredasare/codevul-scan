c++
std::vector<string16> Extension::GetPermissionMessageStrings() const {
  std::vector<string16> messages;
  PermissionMessages permissions = GetPermissionMessages();
  constexpr size_t kMaxMessageLength = 1024;  // adjust based on your requirement
  for (PermissionMessages::const_iterator i = permissions.begin();
       i != permissions.end(); ++i) {
    string16 message = i->message();
    if (message.length() > kMaxMessageLength) {
      // Handle error case, e.g., logging or throwing an exception
    } else {
      messages.push_back(message);
    }
  }
  return messages;
}