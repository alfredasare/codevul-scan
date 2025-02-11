uint_least32_t SparseHistogram::name_hash() const {
  uint_least32_t result = static_cast<uint_least32_t>(samples_->id());
  return result;
}