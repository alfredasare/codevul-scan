#include <cstring> // for std::size()

std::string toString() const {
    constexpr std::size_t MAX_LENGTH = 100;

    if (m_string.length() > MAX_LENGTH) {
        throw std::runtime_error("String length exceeds the maximum allowed length");
    }

    std::string sanitized_string(m_string);
    std::replace_if(sanitized_string.begin(), sanitized_string.end(),
                    [](unsigned char c) { return !isalnum(c); }, '_');

    return sanitized_string;
}