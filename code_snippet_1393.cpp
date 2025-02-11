void WebPluginAcceleratedSurfaceProxy::SetTransportDIBAllocAndFree(const std::string& directory_path) {
  if (directory_path.find("..")!= std::string::npos || directory_path.find("/")!= std::string::npos || directory_path.find("\\")!= std::string::npos) {
    // Handle invalid directory path
    return;
  }

  surface_->SetTransportDIBAllocAndFree(NewCallback(plugin_proxy_, &WebPluginProxy::AllocSurfaceDIB, directory_path), NewCallback(plugin_proxy_, &WebPluginProxy::FreeSurfaceDIB, directory_path));
}