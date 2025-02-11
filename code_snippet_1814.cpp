explicit CreateSessionDescriptionRequest(
    const std::shared_ptr<base::SingleThreadTaskRunner>& main_thread,
    const blink::WebRTCSessionDescriptionRequest& request,
    const std::shared_ptr<RTCPeerConnectionHandler>& handler,
    const std::shared_ptr<PeerConnectionTracker>& tracker,
    PeerConnectionTracker::Action action)
    : main_thread_(main_thread),
      webkit_request_(request),
      handler_(handler),
      tracker_(tracker),
      action_(action) {}