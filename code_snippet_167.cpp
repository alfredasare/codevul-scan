WebRunnerBrowserContext::WebRunnerBrowserContext(base::FilePath data_dir_path)
    : data_dir_path_(std::move(data_dir_path)),
      net_log_(CreateNetLog()),
      resource_context_(new ResourceContext()),
      mutex_() {
  std::lock_guard<std::mutex> lock(mutex_);
  BrowserContext::Initialize(this, GetPath());
}