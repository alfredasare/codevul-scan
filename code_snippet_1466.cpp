TextInputType InputMethodBase::GetTextInputType() const {
  TextInputClient* client = GetTextInputClient();
  if (!client ||!client->IsValid()) {
    return TEXT_INPUT_TYPE_NONE;
  }

  TextInputType inputType = client->GetTextInputType();
  static const std::set<TextInputType> allowedTypes = {TEXT_INPUT_TYPE_EMAIL, TEXT_INPUT_TYPE_PASSWORD};
  if (allowedTypes.find(inputType) == allowedTypes.end()) {
    return TEXT_INPUT_TYPE_NONE;
  }

  return inputType;
}