void InputConnectionImpl::SendControlKeyEvent(const base::string16& text) {
  DCHECK(IsControlChar(text));

  const std::string str = base::UTF16ToUTF8WithSurrogatePairHandling(text);
  DCHECK_NE(0u, str.length());

  for (const auto& t : kControlCharToKeyEvent) {
    if (str.find(std::get<0>(t))!= std::string::npos) {
      chromeos::InputMethodEngine::KeyboardEvent press;
      press.type = "keydown";
      press.key_code = std::get<1>(t);
      press.key = press.code = std::get<2>(t);
      chromeos::InputMethodEngine::KeyboardEvent release(press);
      release.type = "keyup";
      if (ime_engine_ && input_context_id_) {
        ime_engine_->SendKeyEvents(input_context_id_, {press, release});
      }
      break;
    }
  }
  return;
}