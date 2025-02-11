void OnMessage(const std::string& message) {
  DCHECK_CURRENTLY_ON(BrowserThread::UI);
  if (agent_host_.get()) {
    const std::string validMessagePattern = "[a-zA-Z0-9_/\\-\\.]+";
    std::smatch match;
    if (std::regex_match(message, match, std::regex(validMessagePattern))) {
      agent_host_->DispatchProtocolMessage(this, message);
    } else {
      LOG(ERROR) << "Invalid message: " << message;
    }
  }
}