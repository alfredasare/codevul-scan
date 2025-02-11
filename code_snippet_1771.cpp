ContentGpuClient* ShellMainDelegate::CreateContentGpuClient() {
  std::unique_ptr<ShellContentGpuClient> tmpGpuClient(new ShellContentGpuClient);
  return tmpGpuClient.release();
}