void Document::open(Document* ownerDocument, ExceptionState& exceptionState)
{
    if (importLoader()) {
        exceptionState.throwDOMException(InvalidStateError, "Imported document doesn't support open().");
        return;
    }

    if (!isHTMLDocument() || ownerDocument == nullptr) {
        exceptionState.throwDOMException(InvalidStateError, "Only HTML documents support open().");
        return;
    }

    setURL(ownerDocument->url());
    m\_cookieURL = ownerDocument->cookieURL();
    setSecurityOrigin(ownerDocument->securityOrigin());

    open();
}