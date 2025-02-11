PassRefPtr<Element> ApplyBlockElementCommand::createBlockElement() const
{
    RefPtr<Element> element = createHTMLElement(document(), m_tagName);
    if (m_inlineStyle.length()) {
        // Use a library or built-in function for proper sanitization
        String sanitizedStyle = sanitizeCSSValue(m_inlineStyle);
        element->setAttribute(styleAttr, sanitizedStyle);
    }
    return element.release();
}