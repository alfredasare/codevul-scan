void XMLHttpRequest::send(DOMFormData* body, ExceptionState& es)
{
    if (!initSend(es))
        return;

    if (areMethodAndURLValidForSend()) {
        m_requestEntityBody = FormData::createMultiPart(*(static_cast<FormDataList*>(body)), body->encoding(), document());

        String contentType = getRequestHeader("Content-Type");
        if (contentType.isEmpty()) {
            contentType = sanitizeContentType("multipart/form-data; boundary=") + m_requestEntityBody->boundary().data();
            setRequestHeaderInternal("Content-Type", contentType);
        }
    }

    createRequest(es);
}

String XMLHttpRequest::sanitizeContentType(const String& contentType)
{
    // Define a whitelist of allowed content types
    const char* allowedContentTypes[] = {"application/x-www-form-urlencoded", "multipart/form-data"};

    // Check if the provided contentType matches any of the allowed content types
    for (const char* allowedContentType : allowedContentTypes) {
        if (contentType.startsWithIgnoreCase(allowedContentType)) {
            return contentType;
        }
    }

    // Return an error or use a default value if the contentType is not allowed
    return "application/x-www-form-urlencoded";
}