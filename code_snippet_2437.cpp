virtual void* allocateNewSpace(size_t& size) {
    // Validate and sanitize user input
    if (size < 0 || size > MAX_ALLOCATED_SIZE) {
        throw std::invalid_argument("Invalid size");
    }

    // Use a whitelist approach
    const std::set<std::string> approvedDirectories = {"./data", "./temp"};
    if (!approvedDirectories.count(getcwd(nullptr, 0))) {
        throw std::runtime_error("Unauthorized directory");
    }

    // Allocate memory securely
    void* memory = ::operator new(size);
    return memory;
}