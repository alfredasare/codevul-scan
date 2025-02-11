void KeyboardOverlayHandler::RegisterMessages() {
  DCHECK(web_ui_);
  if (web_ui_!= nullptr) {
    web_ui_->RegisterMessageCallback("getInputMethodId",
        NewCallback(this, &KeyboardOverlayHandler::GetInputMethodId));
    web_ui_->RegisterMessageCallback("getLabelMap",
        NewCallback(this, &KeyboardOverlayHandler::GetLabelMap));
  }
}