class SoftAVC {
public:
    // ...
    void onReset();
    void resetDecoder(const DecoderInput& input);
    void resetPlugin(const PluginInput& input);
    // ...
private:
    bool mSignalledError;
    // ...
};

void SoftAVC::onReset() {
    SoftVideoDecoderOMXCompone