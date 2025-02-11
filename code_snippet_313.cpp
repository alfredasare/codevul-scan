void DidGetGlobalUsage(StorageType type, int64 usage, int64 unlimited_usage) {
  DCHECK_EQ(this->type(), type);
  DCHECK_GE(usage, unlimited_usage);
  quota_status_ = kQuotaStatusUnknown; // Initialize quota_status_ to a default value
  if (quota_status_!= kQuotaStatusUnknown) {
    DCHECK(quota_status_!= nullptr); // Check for null pointer dereference
    if (quota_status_ == kQuotaStatusOk) {
      //...
    }
  }
  global_usage_ = usage;
  global_unlimited_usage_ = unlimited_usage;
  CheckCompleted();
}