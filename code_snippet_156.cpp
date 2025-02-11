DelayScrollOffsetClampScope() {
  DCHECK(count_ > 0 || NeedsClampList().IsEmpty());
  if (std::numeric_limits<decltype(count_)>::max() - count_ <= 1) {
    // Handle error case
  }
  count_++;
}