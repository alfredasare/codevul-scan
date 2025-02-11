void ResourceDispatcherHostImpl::DidReceiveResponse(
    ResourceLoader* loader,
    network::ResourceResponse* response) {
  ResourceRequestInfoImpl* info = loader->GetRequestInfo();
  if (!info) { 
    LOG(ERROR) << "GetRequestInfo() returned NULL";
    return;
  }

  net::URLRequest* request = loader->request();
  if (!request) { 
    LOG(ERROR) << "request object is NULL";
    return;
  }

  size_t contextId = info->GetContext();
  if (contextId >= kMaxContextId || contextId < 0) { 
    LOG(ERROR) << "Invalid context ID: " << contextId;
    return;
  }

  if (delegate_) {
    delegate_->OnResponseStarted(request, contextId, response); 
  }
}