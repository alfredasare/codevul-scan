std::unique_ptr<ContentGpuClient> ShellMainDelegate::CreateContentGpuClient() {
    std::unique_ptr<ContentGpuClient> gpu_client(new ShellContentGpuClient);
    return gpu_client;
}