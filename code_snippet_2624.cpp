const std::string MessageIterator::NextString() const {
  std::unique_ptr<std::string> val_ptr = std::make_unique<std::string>();
  if (!iter_.ReadString(val_ptr.get()))
    NOTREACHED();
  return std::move(*val_ptr);
}