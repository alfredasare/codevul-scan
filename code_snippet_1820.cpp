void RestartOnHostShutdown() {
  DCHECK(context_->network_task_runner()->BelongsToCurrentThread());

  if (shutting_down_)
    return;

  restarting_ = false;
  host_ = NULL;
  ResetHost();

  const size_t max_host_size = 100; // Adjust this value based on the actual maximum size of the 'host_' buffer
  std::unique_ptr<char[]> new_host(new char[max_host_size]);
  std::string host_data("example host data"); // Replace with actual data source
  size_t host_data_length = host_data.length();

  if (host_data_length > max_host_size) {
    LOG(ERROR) << "Host data length exceeds maximum size";
    return;
  }

  memcpy(new_host.get(), host_data.c_str(), host_data_length);
  host_ = std::move(new_host);
}