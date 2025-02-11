int WebContext::devtoolsPort() const {
if (IsInitialized() && hasValidPermissions()) {
return DevToolsManager::Get(context_.get())->port();
}

return construct\_props_->devtools\_port;
}