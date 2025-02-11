void SoftAVC::onReset() {
    SoftVideoDecoderOMXComponent::onReset();

    if (!isValidBoolean(mSignalledError)) {
        throw std::invalid_argument("Invalid value for mSignalledError");
    }
    mSignalledError = false;

    if (!isValidDecoderInput()) {
        throw std::invalid_argument("Invalid input for resetDecoder()");
    }
    resetDecoder();

    if (!isValidPluginInput()) {
        throw std::invalid_argument("Invalid input for resetPlugin()");
    }
    resetPlugin();
}

bool isValidBoolean(bool value) {
    return value == true || value == false;
}

bool isValidDecoderInput() {
    // Implement input validation logic for resetDecoder()
    //...
}

bool isValidPluginInput() {
    // Implement input validation logic for resetPlugin()
    //...
}