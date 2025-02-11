void DevToolsUIBindings::Detach() {
  if (agent_host_) {
    agent_host_->DetachClient(this);
    agent_host_.release();
  }
}