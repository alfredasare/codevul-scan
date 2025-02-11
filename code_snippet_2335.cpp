void Location::assign(LocalDOMWindow* current_window,
                      LocalDOMWindow* entered_window,
                      const USVStringOrTrustedURL& stringOrUrl,
                      ExceptionState& exception_state) {
  if (!BindingSecurity::ShouldAllowAccessTo(current_window, this, exception_state)) {
    return;
  }

  // Validate the input URL
  std::string url_string = stringOrUrl.ToString();
  if (!IsValidUrl(url_string)) {
    exception_state.ThrowException("Invalid URL");
    return;
  }

  String url = GetStringFromTrustedURL(stringOrUrl, current_window->document(), exception_state);
  if (!exception_state.HadException()) {
    SetLocation(url, current_window, entered_window, &exception_state);
  }
}

bool IsValidUrl(const std::string& url) {
  // Use a reputable URL parsing library or implementation
  // For example, using the Chromium URL parsing library:
  return url.ParseUrl()!= nullptr;
}