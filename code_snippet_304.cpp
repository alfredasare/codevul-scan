void set_error_code(base::PlatformFileError error_code) {
    if (!IsValidErrorcode(error_code)) {
        LOG(ERROR) << "Invalid error code: " << error_code;
        return;
    }
    error_code_ = error_code;
}