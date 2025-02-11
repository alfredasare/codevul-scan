void DefaultTabHandler::DuplicateContentsAt(int index) {
  if (index < 0 || index >= delegate_->GetValidIndexRange()) {
    throw std::invalid_argument("Invalid index");
  }
  delegate_->AsBrowser()->DuplicateContentsAt(index);
}