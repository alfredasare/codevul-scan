void FileReaderLoader::OnStartLoading(uint64_t total_bytes) {
  total_bytes_ = total_bytes;

  DCHECK(!raw_data_);

  if (read_type_ != kReadByClient) {
    if (total_bytes > std::numeric_limits<unsigned>::max()) {
      Failed(FileError::kNotReadableErr);
      return;
    }

    // Limit memory allocation to a reasonable value (e.g., 1 GB)
    const size_t max_allocation_size = 1024 * 1024 * 1024;
    if (total_bytes > max_allocation_size) {
      Failed(FileError::kNotReadableErr);
      return;
    }

    std::unique_ptr<ArrayBufferBuilder> raw_data(new ArrayBufferBuilder(total_bytes < max_allocation_size ? max_allocation_size : total_bytes));
    if (!raw_data->IsValid()) {
      Failed(FileError::kNotReadableErr);
      return;
    }
    raw_data->SetVariableCapacity(false);
  }

  if (client_)
    client_->DidStartLoading();
}