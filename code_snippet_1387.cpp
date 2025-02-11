void MediaStreamDispatcherHost::OnDeviceStopped(
    const std::string& label,
    const blink::MediaStreamDevice& device) {
  DCHECK_CURRENTLY_ON(BrowserThread::IO);

  if (device == nullptr) {
    return;
  }

  GetMediaStreamDeviceObserver()->OnDeviceStopped(label, device);
}