class BookmarkManagerView {
 public:
  //...
  std::wstring GetWindowName() const {
    return GetDynamicWindowName();
  }

 private:
  virtual std::wstring GetDynamicWindowName() const {
    return prefs::kBookmarkManagerPlacement;
  }
};