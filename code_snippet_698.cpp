#include <string>
#include <codecvt>

bool ProcessNeedsProfileDir(const std::string& process_type) {
    std::wstring_convert<std::conditional_t<true, std::codecvt_utf8<char16_t>, std::codecvt_utf8<char32_t>>, char16_t> converter;
    std::u16string utf16_process_type = converter.from_bytes(process_type);

    return ProcessNeedsProfileDir(GetProcessType(utf16_process_type));
}