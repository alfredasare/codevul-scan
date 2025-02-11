void NetworkThrottleManagerImpl::MaybeUnblockThrottles() {
  RecomputeOutstanding();

  while (outstanding_throttles_.size() < kActiveRequestThrottlingLimit &&
        !blocked_throttles_.empty()) {
    BlockedThrottle* blockedThrottle = blocked_throttles_.front();
    if (IsAuthorizedBlockedThrottle(blockedThrottle)) {
      UnblockThrottle(blockedThrottle);
    } else {
      // Handle unauthorized blocked throttle
    }
  }
}

bool NetworkThrottleManagerImpl::IsAuthorizedBlockedThrottle(BlockedThrottle* blockedThrottle) {
  return blockedThrottle->GetOwner()->IsAuthorized();
}