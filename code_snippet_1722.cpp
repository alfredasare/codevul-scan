std::string toString() const {
    if (!m_string.empty() &&!std::all_of(m_string.begin(), m_string.end(), [](char c) { return std::isalnum(c) || c == '_' || c == '.'; })) {
        throw std::runtime_error("Invalid input data");
    }
    return m_string;
}