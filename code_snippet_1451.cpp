#include <regex>

bool IsApprovedProtocol(const base::string16& url) {
  std::wregex protocol_regex(L"^(http|https)://");
  return std::regex_match(url.begin(), url.end(), protocol_regex);
}

bool NavigateToUrlWithEdge(const base::string16& url) {
  if (!IsApprovedProtocol(url)) return false;

  base::string16 approved_url = L"microsoft-edge://" + url;
  SHELLEXECUTEINFO info = { sizeof(info) };
  info.fMask = SEE_MASK_NOASYNC | SEE_MASK_FLAG_NO_UI;
  info.lpVerb = L"open";
  info.lpFile = approved_url.c_str();
  info.nShow = SW_SHOWNORMAL;
  if (::ShellExecuteEx(&info))
    return true;
  PLOG(ERROR) << "Failed to launch Edge for uninstall survey";
  return false;
}