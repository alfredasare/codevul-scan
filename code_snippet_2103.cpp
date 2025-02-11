#include <string>
#include <vector>
#include <algorithm>

class WebPageSerializerTest {
public:
    WebPageSerializerTest() : m_supportedSchemes(getAllowedSchemes()) {
        for (int i = 0; i < m_supportedSchemes.size(); i++) {
            if (!std::any_of(getAllowedSchemes().begin(), getAllowedSchemes().end(), [&](const std::string& scheme) { return scheme == m_supportedSchemes[i]; })) {
                throw std::runtime_error("Invalid scheme");
            }
        }
    }

private:
    static const std::vector<std::string> getAllowedSchemes() {
        std::vector<std::string> allowedSchemes = {"http", "https", "file"};
        return allowedSchemes;
    }

    std::vector<std::string> m_supportedSchemes;
};