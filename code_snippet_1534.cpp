surface_->SetTransportDIBAllocAndFree(
          NewCallback(plugin_proxy_, &WebPluginProxy::AllocSurfaceDIB),
          NewCallback(plugin_proxy_, &WebPluginProxy::FreeSurfaceDIB));