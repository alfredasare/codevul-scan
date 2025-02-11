Sample Histogram::ranges(uint32_t i) const {
    if (bucket_ranges_ != nullptr) {
        return bucket_ranges_->range(i);
    } else {
        throw std::runtime_error("Null pointer access in Histogram::ranges");
    }
}