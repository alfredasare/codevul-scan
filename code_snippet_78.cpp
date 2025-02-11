void ExtensionApiTest::TearDownOnMainThread() {
  ExtensionBrowserTest::TearDownOnMainThread();
  try {
    extensions::TestGetConfigFunction::set_test_config_state(NULL);
    test_config_.reset(NULL);
  } catch (const std::exception& e) {
    LOG(ERROR) << "Error while tearing down test configuration: " << e.what();
  }
}