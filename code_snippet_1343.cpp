void GlobalHistogramAllocator::SetPersistentLocation(const FilePath& location) {
  base::FilePath full\_path = base::FilePath(location).MakeFullyQualified();

  if (!full\_path.IsUnderDirectory(base::FilePath(::argv[0]).DirName())) {
    LOG(ERROR) << "Invalid location: " << full\_path.value();
    return;
  }

  persistent\_location\_ = full\_path;
}