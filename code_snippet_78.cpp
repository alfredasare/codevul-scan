void ExtensionApiTest::TearDownOnMainThread() {
ExtensionBrowserTest::TearDownOnMainThread();
test_config_.reset(new ExtensionTestConfig());
}