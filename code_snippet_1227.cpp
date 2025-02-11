void MediaStreamDispatcherHost::OnDeviceStopped(const std::string& label, const blink::MediaStreamDevice& device) {
  DCHECK_CURRENTLY_ON(BrowserThread::IO);

  // Sanitize the label to prevent path traversal attacks
  label = boost::algorithm::to_lower_copy(label);
  label.erase(std::remove(label.begin(), label.end(), '/'), label.end());

  GetMediaStreamDeviceObserver()->OnDeviceStopped(label, device);
}