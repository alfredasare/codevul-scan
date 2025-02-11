static inline std::string transformTextStringToXHTMLDocumentString(const std::string& text)
{
    std::string sanitizedText = htmlEscape(text);
    std::string xhtmlDoc = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">\n"
        "<html xmlns=\"http://www.w3.org/1999/xhtml\">\n"
        "<head><title/></head>\n"
        "<body>\n"
        "<pre>";
    xhtmlDoc += sanitizedText;
    xhtmlDoc += "</pre>\n</body></html>";
    return xhtmlDoc;
}

std::string htmlEscape(const std::string& str)
{
    std::string result;
    for (char c : str) {
        if (c == '&') {
            result += "&amp;";
        } else if (c == '<') {
            result += "&lt;";
        } else if (c == '>') {
            result += "&gt;";
        } else {
            result += c;
        }
    }
    return result;
}