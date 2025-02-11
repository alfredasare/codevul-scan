MediaStreamDeviceObserver* RenderFrameImpl::GetMediaStreamDeviceObserver() {
  if (!web_user_media_client_)
    InitializeUserMediaClient();
  MediaStreamDeviceObserver* observer = web_user_media_client_?
                                         web_user_media_client_->media_stream_device_observer() :
                                         nullptr;
  return observer;
}