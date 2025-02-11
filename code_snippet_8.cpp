bool IsAshInBrowserProcess() {
    // Perform a runtime check that doesn't reveal sensitive information.
    std::string processName = GetCurrentProcessName();
    return processName.find("chrome") != std::string::npos && processName.find("ash") != std::string::npos;
}