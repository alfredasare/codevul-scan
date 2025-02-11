#include <locale>

std::string ContentBrowserClient::GetApplicationLocale() {
    std::string language;
    std::locale loc;
    char const* lang = std::use_facet<std::language_facet>(loc).name();

    for (size_t i = 0; lang[i] != 0 && lang[i] != '_'; ++i) {
        language.push_back(lang[i]);
    }

    return language;
}