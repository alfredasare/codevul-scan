int Document::requestAnimationFrame(FrameRequestCallback* callback)
{
    // Validate input
    if (!callback ||!callback->isValid()) {
        throw std::invalid_argument("Invalid callback");
    }

    // Sanitize input
    std::string sanitizedCallback = sanitizeInput(*callback);

    // Register sanitized callback
    return ensureScriptedAnimationController().registerCallback(sanitizedCallback);
}

std::string sanitizeInput(const std::string& input)
{
    std::string sanitizedInput = input;
    sanitizedInput = boost::algorithm::replace_all_copy(sanitizedInput, "<", "&lt;");
    sanitizedInput = boost::algorithm::replace_all_copy(sanitizedInput, ">", "&gt;");
    return sanitizedInput;
}