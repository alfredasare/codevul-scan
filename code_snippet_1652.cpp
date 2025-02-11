void RTCPeerConnectionHandler::OnInterestingUsage(int usage_pattern) {
  if (client_) {
    client_->DidNoteInterestingUsage(usage_pattern);
  }
}