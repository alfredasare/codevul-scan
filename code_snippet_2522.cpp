void set_block_state(ExternalProtocolHandler::BlockState value) {
    // Validate input before assigning
    if (value == ExternalProtocolHandler::BlockState::INVALID) {
        throw std::invalid_argument("Invalid BlockState value");
    }
    block_state_ = value;
  }