void Location::assign(LocalDOMWindow* current_window,
                  LocalDOMWindow* entered_window,
                  const USVStringOrTrustedURL& stringOrUrl,
                  ExceptionState& exception_state) {
  if (!BindingSecurity::ShouldAllowAccessTo(current_window, this,
                                            exception_state)) {
    return;
  }

  if (stringOrUrl.IsUSVString()) {
    USVString urlString = stringOrUrl.GetUSVString();
    if (!IsValidURL(urlString)) {
      exception_state.Raise(InputError, "Invalid URL format");
      return;
    }
    SetLocation(urlString, current_window, entered_window, &exception_state);
  } else {
    String url = GetStringFromTrustedURL(stringOrUrl, current_window->document(),
                                         exception_state);
    if (!exception_state.HadException()) {
      SetLocation(url, current_window, entered_window, &exception_state);
    }
  }
}