void TargetHandler::Wire(UberDispatcher* dispatcher) {
  frontend_.reset(new Target::Frontend(ValidateChannel(dispatcher->channel())));
  Target::Dispatcher::wire(dispatcher, this);
}

std::string ValidateChannel(const std::string& channel) {
  // Sanitize and validate the input string
  // For example, remove any disallowed characters or check for a specific pattern
  if (!channel.empty() &&!IsAllowedCharacter(channel[0])) {
    throw std::invalid_argument("Invalid channel");
  }
  return channel;
}