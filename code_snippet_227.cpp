class ControlledRenderProcessHost {
 public:
  ControlledRenderProcessHost(base::Optional<int32_t> process_id, SharedWorkerDevToolsAgentHost* host)
      : process_id_(process_id), host_(host) {}

  RenderProcessHost* GetProcess() const {
    if (!host_ || !host_->worker_host() || host_->worker_host()->process_id() != *process_id_) {
      return nullptr;
    }

    return RenderProcessHost::FromID(*process_id_);
  }

 private:
  base::Optional<int32_t> process_id_;
  SharedWorkerDevToolsAgentHost* host_;
};

ControlledRenderProcessHost* SharedWorkerDevToolsAgentHost::GetControlledProcess() {
  if (!worker_host_) {
    return nullptr;
  }

  return new ControlledRenderProcessHost(worker_host_->process_id(), this);
}