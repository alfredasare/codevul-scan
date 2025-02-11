void RTCPeerConnectionHandler::ReportICEState(
    webrtc::PeerConnectionInterface::IceConnectionState new_state) {
  DCHECK(task_runner_->RunsTasksInCurrentSequence());
  std::map<webrtc::PeerConnectionInterface::IceConnectionState, bool> ice_state_seen_ = {{new_state, false}};
  if (ice_state_seen_.at(new_state)) {
    return;
  }
  ice_state_seen_.at(new_state) = true;
  UMA_HISTOGRAM_ENUMERATION("WebRTC.PeerConnection.ConnectionState", new_state,
                            webrtc::PeerConnectionInterface::kIceConnectionMax);
}