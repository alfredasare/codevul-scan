#include <boost/algorithm/string/replace.hpp>
#include <sstream>
#include <cctype>

String HTMLFormElement::method() const
{
    std::string unsafe_method = FormSubmission::Attributes::methodString(m_attributes.method());
    std::string safe_method;

    std::stringstream ss(unsafe_method);
    std::string token;
    while (ss >> token) {
        token.erase(std::remove_if(token.begin(), token.end(), [](char c) {
            return !std::isalnum(c, std::locale()) && c != '_' && c != '-' && c != '+';
        }), token.end());
        if (!token.empty()) {
            safe_method += (safe_method.empty() ? "" : " ") + token;
        }
    }

    if (!safe_method.empty()) {
        boost::replace_all(safe_method, " ,", ",");
        boost::to_lower(safe_method);
    } else {
        safe_method = "get";
    }

    return safe_method;
}