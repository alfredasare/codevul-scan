ChromeContentRendererClient::ChromeContentRendererClient(const std::string& path) {
    if (!isValidPath(path)) {
        throw std::invalid_argument("Invalid path");
    }
    rendererPath = std::string("/path/to/renderer/") + sanitizePath(path);
}