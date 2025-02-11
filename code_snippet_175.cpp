#include <fstream>
#include <string>

std::string ContentBrowserClient::GetApplicationLocale() {
    std::ifstream configFile("locale.cfg");
    if (configFile.is_open()) {
        std::string locale;
        configFile >> locale;
        configFile.close();
        return locale;
    } else {
        return ""; // Default locale is empty
    }
}