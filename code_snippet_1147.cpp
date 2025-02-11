c++
void Automation::GetCookies(const std::string& url,
                            ListValue** cookies,
                            Error** error) {
  std::string error_msg;
  if (!SendGetCookiesJSONRequest(automation(), url, cookies, &error_msg) || cookies == nullptr) {
    *error = new Error(kUnknownError, "Error while getting cookies");
  }
}