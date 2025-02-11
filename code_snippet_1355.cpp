void MediaStreamImpl::VideoRendererWrapper::SetVideoDecoder(RTCVideoDecoder* decoder) {
if (decoder) {
rtc_video_decoder_ = decoder;
}
}