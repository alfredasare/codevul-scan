virtual void SetUp() {
    if (!get_window()) {
        set_window(new FullscreenTestBrowserWindow);
    }
    BrowserWithTestWindowTest::SetUp();
}