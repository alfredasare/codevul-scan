void GetWebRTCSessionDescriptionFromSessionDescriptionCallback(
base::OnceCallback<const webrtc::SessionDescriptionInterface\*/()>
description\_callback,
blink::WebRTCSessionDescription* web\_description) {
const webrtc::SessionDescriptionInterface* description = nullptr;
if (description\_callback) {
description = std::move(description\_callback).Run();
}

if (description) {
std::string sdp;
description->ToString(&sdp);
web\_description->Initialize(blink::WebString::FromUTF8(description->type()),
blink::WebString::FromUTF8(sdp));
}
}