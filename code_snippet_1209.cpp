ExtensionDevToolsClientHost* DebuggerFunction::FindClientHost() {
const std::string& extension\_id = extension()->id();
if (extension\_id.empty()) {
return nullptr;
}
DevToolsAgentHost* agent\_host = agent\_host\_get();
if (!agent\_host) {
return nullptr;
}
AttachedClientHosts& hosts = g\_attached\_client\_hosts.Get();
AttachedClientHosts::iterator it = std::find\_if(
hosts.begin(), hosts.end(),
[&agent\_host, &extension\_id](ExtensionDevToolsClientHost* client\_host) {
return client\_host->agent\_host() == agent\_host &&
client\_host->extension\_id() == extension\_id;
});

return it == hosts.end() ? nullptr : \*it;
}