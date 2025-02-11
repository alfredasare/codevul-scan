#include <cassert>
#include <string>

void SplitStringAlongWhitespace(const std::wstring& str,
                                std::vector<std::wstring>* result) {
    constexpr size_t MAX_INPUT_LENGTH = 1024;
    assert(str.length() <= MAX_INPUT_LENGTH);

    for (wchar_t c : str) {
        if (!iswspace(c) && c != L'\0') {
            throw std::runtime_error("Invalid character found in input string");
        }
    }

    SplitStringAlongWhitespaceT(str, result);
}