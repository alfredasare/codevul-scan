#include <regex>

// Add a helper function to sanitize the input
base::string16 SanitizeInput(const std::string& input) {
  std::string sanitized_input = input;
  // Replace any non-alphanumeric characters with an empty string
  std::regex sanitize_regex("\\W");
  sanitized_input = std::regex_replace(sanitized_input, sanitize_regex, "");
  return base::string16(sanitized_input.begin(), sanitized_input.end());
}

base::string16 GetSecondPageTitle() {
  // Assume kSecondPageTitle is user-supplied data
  std::string raw_input = kSecondPageTitle;
  // Validate and sanitize the input
  return ASCIIToUTF16(SanitizeInput(raw_input));
}