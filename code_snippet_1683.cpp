void GetWebRTCSessionDescriptionFromSessionDescriptionCallback(
    base::OnceCallback<const webrtc::SessionDescriptionInterface*()> description_callback,
    blink::WebRTCSessionDescription* web_description) {
  const webrtc::SessionDescriptionInterface* description = nullptr;
  {
    auto callback = std::move(description_callback);
    description = callback.Run();
  }
  if (description) {
    std::string sdp;
    description->ToString(&sdp);
    web_description->Initialize(blink::WebString::FromUTF8(description->type()),
                                blink::WebString::FromUTF8(sdp));
  }
}