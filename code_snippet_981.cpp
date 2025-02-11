void Automation::GetCookies(const std::string& url,
                            ListValue** cookies,
                            Error** error) {
  std::string error_msg;
  http_response_t response = SendGetCookiesJSONRequest(automation(), url, cookies, &error_msg);
  if (response.status_code < 200 || response.status_code >= 400) {
    *error = new Error(kUnknownError, "Failed to retrieve cookies");
  } else {
    // Process the response content
  }
}