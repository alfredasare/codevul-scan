uint64_t SparseHistogram::name_hash() const {
  if (samples_ != nullptr) {
    return samples_->id();
  } else {
    // Return a default or error value if samples_ is null
    return 0;
  }
}