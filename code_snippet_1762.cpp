void PepperMediaDeviceManager::OnDeviceOpenFailed(int request_id) {
  const std::string error_message = "Device open request " + std::to_string(request_id) + " failed.";
  NotifyDeviceOpened(request_id, false, error_message);
}