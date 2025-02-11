FaviconWebUIHandler::~FaviconWebUIHandler() {
    if (faviconHandle!= nullptr) {
        CloseHandle(faviconHandle);
        faviconHandle = nullptr;
    }
    delete[] faviconData;
}