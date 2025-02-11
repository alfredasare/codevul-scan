void NavigationController::DiscardTransientEntry() {
  if (transient_entry_index_ == -1)
    return;
  if (transient_entry_index_ >= entries_.size()) {
    // Return early if transient_entry_index_ is out of bounds
    return;
  }
  entries_.erase(entries_.begin() + transient_entry_index_);
  if (last_committed_entry_index_ > transient_entry_index_)
    last_committed_entry_index_--;
  transient_entry_index_ = -1;
}