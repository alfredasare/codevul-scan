NavigationType navigation_type(const std::string& input) {
    static const std::set<std::string> allowed_types = {"home", "search", "about"};

    if (!allowed_types.count(input)) {
        throw std::invalid_argument("Invalid navigation type");
    }

    std::string navigation_id = input; // Use input as navigation type identifier
    return NavigationType(navigation_id, input);
}