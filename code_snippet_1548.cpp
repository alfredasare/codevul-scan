void Document::open(Document* ownerDocument, ExceptionState& exceptionState)
{
    if (!isValidOwnerDocument(ownerDocument)) {
        exceptionState.throwDOMException(InvalidStateError, "Invalid owner document.");
        return;
    }

    if (importLoader()) {
        exceptionState.throwDOMException(InvalidStateError, "Imported document doesn't support open().");
        return;
    }

    if (!isHTMLDocument()) {
        exceptionState.throwDOMException(InvalidStateError, "Only HTML documents support open().");
        return;
    }

    if (ownerDocument) {
        setURL(ownerDocument->url());
        m_cookieURL = ownerDocument->cookieURL();
        setSecurityOrigin(ownerDocument->securityOrigin());
    }

    open();
}

bool Document::isValidOwnerDocument(Document* ownerDocument)
{
    // Whitelist validation
    if (!ownerDocument ||!isHTMLDocument() ||!ownerDocument->isHTMLDocument()) {
        return false;
    }
    return true;
}