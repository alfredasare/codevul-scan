void LayerTreeHostImpl::SetManagedMemoryPolicy(
    const ManagedMemoryPolicy& policy) {
  if (cached_managed_memory_policy_ == policy)
    return;

  // Secure implementation of ActualManagedMemoryPolicy()
  ManagedMemoryPolicy actual_policy = CalculateActualManagedMemoryPolicy();

  // Validate input parameters
  if (!ValidatePolicy(policy)) {
    LOG(ERROR) << "Invalid managed memory policy";
    return;
  }

  // Rest of the function remains the same
  ManagedMemoryPolicy old_policy = actual_policy;
  cached_managed_memory_policy_ = policy;
  actual_policy = CalculateActualManagedMemoryPolicy();

  if (old_policy == actual_policy)
    return;

  UpdateTileManagerMemoryPolicy(actual_policy);

  bool needs_commit = true;
  if (visible() &&
      actual_policy.bytes_limit_when_visible >= max_memory_needed_bytes_ &&
      old_policy.bytes_limit_when_visible >= max_memory_needed_bytes_ &&
      actual_policy.priority_cutoff_when_visible == old_policy.priority_cutoff_when_visible) {
    needs_commit = false;
  }

  if (needs_commit)
    client_->SetNeedsCommitOnImplThread();
}