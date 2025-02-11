void QuicTransportHost::CreateStream(
    std::unique_ptr<QuicStreamHost> stream_host) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);

  if (quic_transport_ == nullptr) {
    // Handle the error condition, e.g., return an error code, throw an exception,
    // or log an error message.
    return;
  }

  P2PQuicStream* p2p_stream = quic_transport_->CreateStream();
  if (p2p_stream == nullptr) {
    // Handle the error condition, e.g., return an error code, throw an exception,
    // or log an error message.
    return;
  }

  stream_host->Initialize(this, p2p_stream);
  stream_hosts_.insert(
      std::make_pair(stream_host.get(), std::move(stream_host)));
}