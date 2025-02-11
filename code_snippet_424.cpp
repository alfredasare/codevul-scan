void RunMojoCallbacks() {
    if (generate_stream_cb && IsValidGenerateStreamCb(generate_stream_cb)) {
        generate_stream_cb.Run(MEDIA_DEVICE_FAILED_DUE_TO_SHUTDOWN, std::string(), MediaStreamDevices(), MediaStreamDevices());
    }

    if (open_device_cb && IsValidOpenDeviceCb(open_device_cb)) {
        open_device_cb.Run(false /* success */, std::string(), MediaStreamDevice());
    }
}

bool IsValidGenerateStreamCb(GenerateStreamCb cb) {
    return cb && IsValidCbSignature(cb);
}

bool IsValidOpenDeviceCb(OpenDeviceCb cb) {
    return cb && IsValidCbSignature(cb);
}

bool IsValidCbSignature(Cb cb) {
    return cb && (cb == GenerateStreamCbSignature || cb == OpenDeviceCbSignature);
}

GenerateStreamCbSignature = [](std::string, MediaStreamDevices, MediaStreamDevices) {};
OpenDeviceCbSignature = [](bool, std::string, MediaStreamDevice) {};