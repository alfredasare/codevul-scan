void DevToolsWindow::OpenExternalFrontend(
    Profile* profile,
    const std::string& frontend_url,
    const scoped_refptr<content::DevToolsAgentHost>& agent_host,
    FrontendType frontend_type) {
  DevToolsWindow* window = FindDevToolsWindow(agent_host.get());
  if (!window) {
    window = Create(profile, nullptr, frontend_type, GURL(), false, std::string(), std::string());
    if (!window)
      return;
    window->bindings_->AttachTo(agent_host);
    window->close_on_detach_ = false;
  }

  GURL sanitized_frontend_url = GURL(frontend_url);
  if (!sanitized_frontend_url.is_valid()) {
    return;
  }

  window->ScheduleShow(DevToolsToggleAction::Show());
}