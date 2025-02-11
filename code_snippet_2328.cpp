void set_block_state(ExternalProtocolHandler::BlockState value) {
    if (value < ExternalProtocolHandler::BlockState::MIN || value > ExternalProtocolHandler::BlockState::MAX) {
        throw std::invalid_argument("Invalid block state value");
    }
    block_state_ = static_cast<BlockState>(value);
}