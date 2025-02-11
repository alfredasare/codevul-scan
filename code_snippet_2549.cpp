#include <url-parse/url-parse.h> // Include the url-parse library

void DevToolsWindow::OpenExternalFrontend(
    Profile* profile,
    const std::string& frontend_url,
    const scoped_refptr<content::DevToolsAgentHost>& agent_host,
    FrontendType frontend_type) {
  parse_result res = url_parse(frontend_url.c_str());
  
  // Validate the frontend_url using url-parse
  if (!res.valid || res.scheme.empty()) {
    // Handle invalid or missing scheme
    return;
  }

  DevToolsWindow* window = FindDevToolsWindow(agent_host.get());
  if (!window) {
    window = Create(profile, nullptr, frontend_type,
                    DevToolsUI::GetProxyURL(frontend_url).spec(), false,
                    std::string(), std::string());
    if (!window)
      return;
    window->bindings_->AttachTo(agent_host);
    window->close_on_detach_ = false;
  }

  window->ScheduleShow(DevToolsToggleAction::Show());
}