void HTMLStyleElement::setDisabled(bool set_disabled) {
  CSSStyleSheet* sheet_ptr = sheet();
  if (sheet_ptr != nullptr) {
    sheet_ptr->setDisabled(set_disabled);
  }
}