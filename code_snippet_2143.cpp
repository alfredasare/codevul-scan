QuicAsyncStatus QuicClientPromisedInfo::FinalValidation() {
  if (!client_request_delegate_->CheckVary(*client_request_headers_, *request_headers_, *response_headers_)) {
    Reset(QUIC_PROMISE_VARY_MISMATCH);
    return QUIC_FAILURE;
  }
  QuicSpdyStream* stream = session_->GetPromisedStream(id_);
  if (!stream) {
    QUIC_BUG << "missing promised stream" << id_;
  }
  size_t input_size = client_request_delegate_->GetInputSize();
  if (input_size > QUIC_MAX_INPUT_SIZE) {
    QUIC_BUG << "Input size exceeds maximum allowed size";
    return QUIC_FAILURE;
  }
  std::vector<char> buffer(input_size);
  client_request_delegate_->CopyInputToBuffer(buffer.data(), input_size);
  // Rest of the code remains the same
}