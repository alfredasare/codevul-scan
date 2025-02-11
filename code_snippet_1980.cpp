void ApiTestBase::SetUp() {
  ModuleSystemTest::SetUp();
  // Call env() after setting up the ModuleSystemTest to ensure consistent environment value
  auto test_env_env = env();
  test_env_.reset(new ApiTestEnvironment(test_env_env));
}