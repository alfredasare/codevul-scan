void PopulateDataInBuilder(BlobDataBuilder* builder,
                           size_t index,
                           base::TaskRunner* file_runner) {
  constexpr size_t kMaxStringLength = 5;  // adjust based on the maximum length of the string literals
  if (index % 2 != 0) {
    char buffer[kMaxStringLength];
    snprintf(buffer, sizeof(buffer), "abcde");
    builder->PopulateFutureData(0, buffer, 0, std::min(kMaxStringLength, strlen(buffer)));
    if (index % 3 == 0) {
      char buffer2[2];
      snprintf(buffer2, sizeof(buffer2), "z");
      builder->PopulateFutureData(1, buffer2, 0, std::min(sizeof(buffer2), strlen(buffer2)));
    }
  } else if (index % 3 == 0) {
    scoped_refptr<ShareableFileReference> file_ref =
        ShareableFileReference::GetOrCreate(
            base::FilePath::FromUTF8Unsafe(
                base::SizeTToString(index + kTotalRawBlobs)),
            ShareableFileReference::DONT_DELETE_ON_FINAL_RELEASE, file_runner);
    builder->PopulateFutureFile(0, file_ref, base::Time::Max());
  }
}