ExtensionDevToolsClientHost* DebuggerFunction::FindClientHost() {
  if (!agent_host_.get())
    return nullptr;

  const std::string& extension_id = extension()->id();
  // Whitelist of allowed extension IDs
  static const std::set<std::string> allowed_extensions = {"allowed_extension1", "allowed_extension2"};

  if (std::find(allowed_extensions.begin(), allowed_extensions.end(), extension_id) == allowed_extensions.end()) {
    return nullptr;
  }

  DevToolsAgentHost* agent_host = agent_host_.get();
  AttachedClientHosts& hosts = g_attached_client_hosts.Get();
  AttachedClientHosts::iterator it = std::find_if(
      hosts.begin(), hosts.end(),
      [&agent_host, &extension_id](ExtensionDevToolsClientHost* client_host) {
        return client_host->agent_host() == agent_host &&
               client_host->extension_id() == extension_id;
      });

  return it == hosts.end()? nullptr : *it;
}