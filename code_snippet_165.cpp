void HTMLDocument::setAlinkColor(const AtomicString& value)
{
    String sanitizedValue = value.toLowerCase();
    if (sanitizedValue.match("^#([a-f0-9]{6}|[a-f0-9]{3})$", false)) {
        setBodyAttribute(alinkAttr, value);
    }
    // Handle invalid input gracefully, e.g., by logging an error or setting a default value
}