explicit CreateSessionDescriptionRequest(
    const scoped_refptr<base::SingleThreadTaskRunner>& main_thread,
    const blink::WebRTCSessionDescriptionRequest& request,
    const base::WeakPtr<RTCPeerConnectionHandler>& handler,
    const base::WeakPtr<PeerConnectionTracker>& tracker,
    PeerConnectionTracker::Action action)
    : main_thread_(main_thread),
      webkit_request_(request) {
  if (!handler || !handler.get()) {
    LOG(ERROR) << "Invalid handler weak pointer";
    return;
  }
  handler_ = handler;

  if (!tracker || !tracker.get()) {
    LOG(ERROR) << "Invalid tracker weak pointer";
    return;
  }
  tracker_ = tracker;
  action_ = action;
}

void DoSomethingWithHandler() {
  if (!handler_ || !handler_.get()) {
    LOG(ERROR) << "Invalid handler weak pointer";
    return;
  }
  // Use handler_
}

void DoSomethingWithTracker() {
  if (!tracker_ || !tracker_.get()) {
    LOG(ERROR) << "Invalid tracker weak pointer";
    return;
  }
  // Use tracker_
}