RenderProcessHost* SharedWorkerDevToolsAgentHost::GetProcess() {
  if (!worker_host_) {
    return nullptr;
  }

  // Validate the process_id()
  uint32_t process_id = worker_host_->process_id();
  if (process_id > std::numeric_limits<uint32_t>::max() || process_id < 0) {
    LOG_ERROR("Invalid process ID: " << process_id);
    return nullptr;
  }

  return RenderProcessHost::FromID(process_id);
}