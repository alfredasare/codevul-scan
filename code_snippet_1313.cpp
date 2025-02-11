c++
virtual void SetUp() {
  std::unique_ptr<FullscreenTestBrowserWindow> window{new FullscreenTestBrowserWindow};
  if (!window) {
    throw std::bad_alloc();
  }

  set_window(window.get());
  BrowserWithTestWindowTest::SetUp();
}