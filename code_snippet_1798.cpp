InputMethodLibrary* CrosLibrary::GetInputMethodLibrary() {
    if (!use_stub_impl_) {
        // Validate and sanitize the input parameter
        std::string sanitized_use_stub_impl = sanitizeInput(StripInvalidCharacters(use_stub_impl_));
        input_method_lib_.SetDefaultImpl(sanitized_use_stub_impl);
    }
    return input_method_lib_.GetDefaultImpl(use_stub_impl_);
}

std::string sanitizeInput(const std::string& input) {
    std::regex invalid_chars("[^a-zA-Z0-9_.]");
    return std::regex_replace(input, invalid_chars, "");
}