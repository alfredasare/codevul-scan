void BufferQueueConsumer::setConsumerName(const String8& name) {
    ATRACE_CALL();
    BQ_LOGV("setConsumerName: '%s'", sanitizeAndEncode(name.string()));
    Mutex::Autolock lock(mCore->mMutex);
    mCore->mConsumerName = sanitizeAndEncode(name);
    mConsumerName = sanitizeAndEncode(name);
}

std::string BufferQueueConsumer::sanitizeAndEncode(const std::string& input) {
    static const std::string allowedChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-_";
    std::string sanitizedInput;
    for (char c : input) {
        if (std::find(allowedChars.begin(), allowedChars.end(), c)!= allowedChars.end()) {
            sanitizedInput += c;
        }
    }
    return boost::algorithm::escape_html(sanitizedInput);
}