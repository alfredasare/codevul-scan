++
bool FormHasNonEmptyPasswordField(const FormData& form) {
  if (form.fields.empty()) {
    return false;
  }

  for (size_t i = 0; i < form.fields.size(); ++i) {
    const auto& field = form.fields[i];
    if (field.IsPasswordInputElement()) {
      if (!field.value.empty() ||!field.typed_value.empty())
        return true;
    }
  }
  return false;
}