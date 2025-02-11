c++
void PopulateDataInBuilder(BlobDataBuilder* builder,
                           size_t index,
                           base::TaskRunner* file_runner) {
  if (index % 2 != 0) {
    builder->PopulateFutureData(0, "abcde", 0, 5);
    if (index % 3 == 0) {
      builder->PopulateFutureData(1, "z", 0, 1);
    }
  } else if (index % 3 == 0) {
    const std::set<std::string> allowedPaths = {"path1", "path2",...}; // Whitelist of allowed paths
    std::string filePath = base::FilePath::FromUTF8Safe(
        base::StringPrintf("path/to/expected/directory/%zu", index + kTotalRawBlobs));
    if (allowedPaths.find(filePath) == allowedPaths.end()) {
      LOG(ERROR) << "Path traversal attempt detected: " << filePath;
      return; // Abort the operation
    }
    scoped_refptr<ShareableFileReference> file_ref =
        ShareableFileReference::GetOrCreate(
            base::FilePath::FromUTF8Safe(filePath),
            ShareableFileReference::DONT_DELETE_ON_FINAL_RELEASE, file_runner);
    builder->PopulateFutureFile(0, file_ref, base::Time::Max());
  }
}