PassRefPtr<Element> ApplyBlockElementCommand::createBlockElement() const
{
    RefPtr<Element> element = createHTMLElement(document(), validateTagName(m_tagName));
    if (!m_inlineStyle.isEmpty()) {
        element->setAttribute(styleAttr, sanitizeInlineStyle(m_inlineStyle));
    }
    return element.release();
}

String ApplyBlockElementCommand::validateTagName(const String& tagName) const
{
    static const Set<String> allowedTagNames = {"div", "span"};
    return allowedTagNames.contains(tagName)? tagName : "";
}

String ApplyBlockElementCommand::sanitizeInlineStyle(const String& inlineStyle) const
{
    static const Regex invalidChars = Regex("[^a-zA-Z0-9_;:]");
    return invalidChars.replace(inlineStyle, "");
}