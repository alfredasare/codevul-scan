void SplitStringAlongWhitespace(const std::wstring& str, std::vector<std::wstring>* result) {
    if (result == nullptr) {
        throw std::invalid_argument("result pointer is null");
    }

    if (!SplitStringAlongWhitespaceT(str, result)) {
        throw std::runtime_error("SplitStringAlongWhitespaceT failed");
    }
}