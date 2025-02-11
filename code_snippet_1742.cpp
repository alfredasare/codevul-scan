virtual ssize_t readAt(off64_t offset, void *buffer, size_t size) {
    //...
    int32_t len = reply.readInt32();
    if (len > 0) {
        char* buffer_char = static_cast<char*>(buffer);
        memcpy(buffer_char, mMemory->pointer(), len);
        buffer_char[len] = '\0'; // Add null termination character
    }
    return len;
}