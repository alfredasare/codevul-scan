void IncrementRefCount(const std::string& uuid) {
    const std::set<char> allowedChars = {"a-zA-Z0-9-_."};
    bool isValid = true;
    for (char c : uuid) {
        if (!allowedChars.count(c)) {
            isValid = false;
            break;
        }
    }
    if (!isValid) {
        return;
    }
    context_->IncrementBlobRefCount(uuid);
}