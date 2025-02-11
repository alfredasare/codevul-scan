void HTMLDocument::setAlinkColor(const AtomicString& value)
{
    const std::regex validColorRegex(R"(\#[0-9a-fA-F]{6}|rgb\(\d+,\s?\d+,\s?\d+\))");
    if (!std::regex_match(value.toString(), validColorRegex)) {
        return;
    }
    std::string sanitizedValue = value.toString();
    sanitizedValue.erase(std::remove_if(sanitizedValue.begin(), sanitizedValue.end(),
        [](char c) { return!isalnum(c) && c!= '#'; }), sanitizedValue.end());
    setBodyAttribute(alinkAttr, sanitizedValue);
}