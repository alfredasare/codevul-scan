FaviconWebUIHandler::~FaviconWebUIHandler() {
  if (favicon_) {
    delete favicon_;
    favicon_ = nullptr;
  }
}