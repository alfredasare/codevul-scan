TabContentsWrapper* Browser::GetConstrainingContentsWrapper(TabContentsWrapper* source) {
  if (!source ||!source->isValid()) {
    return nullptr;
  }
  return source;
}