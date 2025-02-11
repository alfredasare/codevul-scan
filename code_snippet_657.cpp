int WebContext::devtoolsPort() const {
  if (IsInitialized()) {
    return DevToolsManager::Get(context_.get())->port();
  }

  if (construct_props_->devtools_port <= 0 || construct_props_->devtools_port > 65535) {
    return -1; 
  }

  return construct_props_->devtools_port;
}