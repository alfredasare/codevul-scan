class RTCPeerConnectionHandler {
 public:
  // ...

  void ReportICEState(webrtc::PeerConnectionInterface::IceConnectionState new_state) {
    std::unique_lock<std::mutex> lock(ice_state_seen_mutex_);
    DCHECK(task_runner_->RunsTasksInCurrentSequence());
    if (ice_state_seen_[new_state]) {
      lock.unlock();
      return;
    }
    ice_state_seen_[new_state] = true;
    UMA_HISTOGRAM_ENUMERATION("WebRTC.PeerConnection.ConnectionState", new_state,
                              webrtc::PeerConnectionInterface::kIceConnectionMax);
  }

 private:
  std::map<webrtc::PeerConnectionInterface::IceConnectionState, bool> ice_state_seen_;
  std::mutex ice_state_seen_mutex_;
  // ...
};