void SVGStyleElement::setDisabled(bool set_disabled) {
if (CSSStyleSheet* style\_sheet = sheet()) {
style\_sheet->setDisabled(set\_disabled);
style\_sheet = nullptr;
}
}