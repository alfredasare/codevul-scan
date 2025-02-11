++
TabContentsWrapper* ReleaseOwnership() {
  if (!target_contents_owner_) {
    throw std::invalid_argument("Invalid target_contents_owner");
  }
  return target_contents_owner_.release();
}