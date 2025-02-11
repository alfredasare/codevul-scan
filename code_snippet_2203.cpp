void SVGStyleElement::ParseAttribute(const AttributeModificationParams& params) {
  if (params.name == SVGNames::titleAttr) {
    if (sheet_ && IsInDocumentTree() && !params.new_value.empty()) {
      sheet_->SetTitle(params.new_value);
    } else {
      throw std::invalid_argument("Invalid or missing title attribute value");
    }
    return;
  }

  SVGElement::ParseAttribute(params);
}