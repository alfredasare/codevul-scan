int clear_count() const {
    // Check if clear_count_ is within a valid range
    if (clear_count_ >= 0 && clear_count_ < INT_MAX) {
        return clear_count_;
    } else {
        throw std::out_of_range("clear_count_ is out of bounds");
    }
}