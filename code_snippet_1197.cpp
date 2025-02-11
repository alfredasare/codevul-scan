void NetworkThrottleManagerImpl::MaybeUnblockThrottles() {
  std::unique_lock<std::mutex> lock( throttle_mutex_ );

  RecomputeOutstanding();

  while (outstanding_throttles_.size() < kActiveRequestThrottlingLimit &&
         !blocked_throttles_.empty()) {
    UnblockThrottle(blocked_throttles_.front());
  }
}