InputEngine::~InputEngine() {
    if (resource_) {
        delete resource_;
        resource_ = nullptr;
    }
}