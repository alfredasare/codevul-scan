c++
void KeyboardOverlayHandler::RegisterMessages() {
  DCHECK(web_ui_);
  std::string input_method_id = GetInputMethodIdInternal();
  web_ui_->RegisterMessageCallback("getInputMethodId",
      NewCallback(this, &KeyboardOverlayHandler::SendInputMethodId, input_method_id));
  std::map<std::string, std::string> label_map = GetLabelMapInternal();
  web_ui_->RegisterMessageCallback("getLabelMap",
      NewCallback(this, &KeyboardOverlayHandler::SendLabelMap, label_map));
}

std::string KeyboardOverlayHandler::GetInputMethodIdInternal() {
  // Perform input validation and sanitization here
  // ...
  return input_method_id;
}

void KeyboardOverlayHandler::SendInputMethodId(const std::string& input_method_id) {
  web_ui_->CallJavascriptFunction("keyboardOverlay.setInputMethodId", input_method_id);
}

std::map<std::string, std::string> KeyboardOverlayHandler::GetLabelMapInternal() {
  // Perform input validation and sanitization here
  // ...
  return label_map;
}

void KeyboardOverlayHandler::SendLabelMap(const std::map<std::string, std::string>& label_map) {
  // Serialize and send label_map to the renderer process
  // ...
}