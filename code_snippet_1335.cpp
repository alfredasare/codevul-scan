bool LayerTreeHost::supportsAcceleratedCompositing(const std::string& input) {
    if (!input.empty()) {
        if (input.find_first_not_of("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_)")!= std::string::npos) {
            return false;
        }
    }
    return true;
}