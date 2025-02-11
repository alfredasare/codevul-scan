c++
#include <cctype> // for std::isalnum

bool ReplacePathURL(const char* base,
                const Parsed& base_parsed,
                const Replacements<char>& replacements,
                CanonOutput* output,
                Parsed* new_parsed) {
    // Validate input by checking if the base parameter is not empty and only contains alphanumeric characters
    if (base == nullptr || strlen(base) == 0 || std::any_of(base, base + strlen(base), [](char c) { return !std::isalnum(c); })) {
        return false;
    }

    URLComponentSource<char> source(base);
    Parsed parsed(base_parsed);
    SetupOverrideComponents(base, replacements, &source, &parsed);
    return DoCanonicalizePathURL<char, unsigned char>(
        source, parsed, output, new_parsed);
}