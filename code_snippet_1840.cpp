void ApiTestBase::SetUp() {
  ModuleSystemTest::SetUp();
  std::string escaped_env = boost::lexical_cast<std::string>(env());
  test_env_.reset(new ApiTestEnvironment(escaped_env));
}