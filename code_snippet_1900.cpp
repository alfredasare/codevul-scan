Sample Histogram::ranges(uint32_t i) const {
  if (bucket_ranges_ == nullptr) {
    return std::vector<Range>(); // Replace with appropriate error handling
  }
  return bucket_ranges_->range(i);
}