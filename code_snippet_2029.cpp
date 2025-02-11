virtual void SetUpInProcessBrowserTestFixture() {
  FilePath test_dir;
  if (!PathService::Get(chrome::DIR_TEST_DATA, &test_dir)) {
    LOG(ERROR) << "Failed to get test directory";
    return;
  }
  std::string gpu_test_dir = HashFunction::GenerateUniqueDirectoryName();
  gpu_test_dir_ = SanitizeAndValidateDirectory(test_dir.AppendASCII("gpu").AppendASCII(gpu_test_dir));
}