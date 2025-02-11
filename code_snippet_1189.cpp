c++
void MediaStreamImpl::VideoRendererWrapper::SetVideoDecoder(RTCVideoDecoder* decoder) {
  switch (/* some condition */) {
    case /* some value */:
      // some code
      break;
    default:
      rtc_video_decoder_ = decoder;
      return;
  }
}