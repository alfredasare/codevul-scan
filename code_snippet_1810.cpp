void RTCPeerConnectionHandler::OnInterestingUsage(int usage_pattern) {
>         delete client_;
>         client_ = nullptr;
client_->DidNoteInterestingUsage(usage_pattern);
}

Changed to:

void RTCPeerConnectionHandler::OnInterestingUsage(int usage_pattern) {
if (client\_ != nullptr) {
client\_->DidNoteInterestingUsage(usage\_pattern);
>         delete client_;
>         client_ = nullptr;
}
}