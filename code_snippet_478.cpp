void RunMojoCallbacks() {
> if (generate_stream_cb && MediaDeviceFailedDueToShutdownIsValid()) {
  generate\_stream\_cb.Run(MEDIA\_DEVICE\_FAILED\_DUE\_TO\_SHUTDOWN, std::string(),
       MediaStreamDevices(), MediaStreamDevices());
}

if (open\_device\_cb) {
  std::string error\_message;
> if (IsValidMediaStreamDevice(MediaStreamDevice())) {
    open\_device\_cb.Run(false /* success */, std::string(), MediaStreamDevice());
  } else {
    error\_message = "Invalid MediaStreamDevice";
  }
}
}

// Add helper functions to validate input parameters
bool MediaDeviceFailedDueToShutdownIsValid() {
// Implement validation logic
}

bool IsValidMediaStreamDevice(const MediaStreamDevice& device) {
// Implement validation logic
}