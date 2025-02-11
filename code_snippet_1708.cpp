void AppendCopyOf(int pos, int size) {
  if (pos < 0 || pos >= data_->size()) {
    throw std::invalid_argument("Invalid position");
  }
  if (size < 1 || size > data_->size() - pos) {
    throw std::invalid_argument("Invalid size");
  }
  target_.AppendCopyOf(data_->data() + pos, size);
}