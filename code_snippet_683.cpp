VideoCaptureController* VideoCaptureManager::GetOrCreateController(
    media::VideoCaptureSessionId capture_session_id,
    const media::VideoCaptureParams& params) {
  DCHECK_CURRENTLY_ON(BrowserThread::IO);

  auto session_it = sessions_.find(capture_session_id);
  if (session_it == sessions_.end())
    return nullptr;
  const MediaStreamDevice& device_info = session_it->second;

  VideoCaptureController* existing_device =
      LookupControllerByMediaTypeAndDeviceId(device_info.type, device_info.id);

  if (existing_device) {
    DCHECK_EQ(device_info.type, existing_device->stream_type());
    return existing_device;
  }

  // Check if a controller already exists for the device before creating a new one.
  for (const auto& controller : controllers_) {
    if (controller->stream_type() == device_info.type &&
        controller->device_id() == device_info.id) {
      return controller;
    }
  }

  VideoCaptureController* new_controller = new VideoCaptureController(
      device_info.id, device_info.type, params,
      video_capture_provider_->CreateDeviceLauncher(), emit_log_message_cb_);
  controllers_.emplace_back(new_controller);
  return new_controller;
}