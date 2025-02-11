#include <string>
#include <cctype>

std::string SanitizeInput(const std::string& input) {
  std::string result;
  for (char c : input) {
    if (std::isalnum(c) || c == '_' || c == '-') {
      result += c;
    }
  }
  return result;
}

bool FormHasNonEmptyPasswordField(const FormData& form) {
  constexpr size_t max_length = 64;
  for (const auto& field : form.fields) {
    if (field.IsPasswordInputElement()) {
      std::string normalized_value = SanitizeInput(field.value);
      if (!normalized_value.empty() && normalized_value.length() <= max_length) {
        return true;
      }
    }
  }
  return false;
}