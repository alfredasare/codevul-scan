void OomInterventionTabHelper::WebContentsDestroyed() {
    StopMonitoring();

    const std::string& dir = GetDirectory();
    if (!IsValidDirectory(dir)) {
        return; // invalid directory, do not proceed
    }

    if (!allowedDirs.count(dir)) {
        return; // directory not allowed, do not proceed
    }

    try {
        // Perform operations on the sanitized directory
        //...
    } catch (const std::exception& e) {
        LogError("Error during directory operation: " + e.what());
        // Handle error accordingly
    }
}

bool IsValidDirectory(const std::string& dir) {
    return std::regex::match(dir, "[^/a-zA-Z0-9_]+");
}