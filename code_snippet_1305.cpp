bool NavigateToUrlWithEdge(const base::string16& url) {
  if (!IsValidProtocol(url)) {
    return false; // or log an error, depending on your requirements
  }

  base::string16 protocol_url = L"microsoft-edge:" + url;
  protocol_url = base::PathCanonicalize(protocol_url);

  SHELLEXECUTEINFO info = { sizeof(info) };
  info.fMask = SEE_MASK_NOASYNC | SEE_MASK_FLAG_NO_UI;
  info.lpVerb = L"open";
  info.lpFile = protocol_url.c_str();
  info.nShow = SW_SHOWNORMAL;

  if (::ShellExecuteEx(&info))
    return true;

  PLOG(ERROR) << "Failed to launch Edge for uninstall survey";
  return false;
}

bool IsValidProtocol(const base::string16& url) {
  static const std::set<std::string> allowed_protocols = {"http", "https", "file"};
  base::string16 protocol = GetProtocolFromUrl(url);
  return allowed_protocols.count(protocol);
}

base::string16 GetProtocolFromUrl(const base::string16& url) {
  size_t pos = url.find("://");
  return url.substr(0, pos);
}