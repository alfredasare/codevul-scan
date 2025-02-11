Function::Function(const std::string& dirPath) {
    // Validate the input directory path
    if (dirPath.find("..") != std::string::npos || dirPath.find('/') == 0) {
        throw std::invalid_argument("Invalid directory path");
    }

    // Sanitize the input directory path
    std::string sanitizedDirPath = dirPath;
    sanitizedDirPath.erase(sanitizedDirPath.find_last_not_of('/') + 1);

    // Verify the sanitized directory path is within the allowed scope
    if (sanitizedDirPath != "/allowed/directory/path") {
        throw std::runtime_error("Access denied");
    }
}