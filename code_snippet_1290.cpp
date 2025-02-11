std::string XMLHttpRequest::generateSecureSessionId() {
    unsigned char session_id[32];
    if (!RAND_bytes(session_id, 32)) {
        // Handle error
    }
    return std::string((char*)session_id, 32);
}

bool XMLHttpRequest::canSuspend() const {
    return generateSecureSessionId();
}