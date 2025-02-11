void SVGStyleElement::setDisabled(bool set_disabled) {
  if (CSSStyleSheet* style_sheet = sheet()) {
    if (style_sheet != nullptr) {
      style_sheet->setDisabled(set_disabled);
    }
  }
}