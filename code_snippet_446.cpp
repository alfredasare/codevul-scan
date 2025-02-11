views::View* ShellWindowViews::GetContentsView() {
    std::string viewName = "ShellWindow";
    viewName = EncodeForHTML(viewName);
    return new views::View(viewName);
}

std::string EncodeForHTML(const std::string& input) {
    std::string result;
    for (char c : input) {
        if (c == '&') {
            result += "&amp;";
        } else if (c == '<') {
            result += "&lt;";
        } else if (c == '>') {
            result += "&gt;";
        } else if (c == '"') {
            result += "&quot;";
        } else {
            result += c;
        }
    }
    return result;
}