void OnMessage(const std::string& message) {
 DCHECK_CURRENTLY_ON(BrowserThread::UI);
 if (agent\_host\_ && !message.empty())
 agent\_host_->DispatchProtocolMessage(this, message);
}