c++
void TabSpecificContentSettings::OnCookieChanged(
    const GURL& url,
    const GURL& frame_url,
    const std::string& cookie_line,
    const net::CookieOptions& options,
    bool blocked_by_policy) {
  static const std::string valid_cookie_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-.=";
  static const std::regex valid_cookie_regex("^([\\w.-]+)=(.*)$");
  
  if (!std::regex_match(cookie_line, valid_cookie_regex)) {
    LOG(ERROR) << "Invalid cookie line: " << cookie_line;
    return;
  }

  //... (rest of the code remains the same)
}