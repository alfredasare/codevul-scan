void ResourceDispatcherHostImpl::DidReceiveResponse(
ResourceLoader* loader,
network::ResourceResponse* response) {
ResourceRequestInfoImpl* info = loader->GetRequestInfo();
net::URLRequest* request = loader->request();

// Add access control checks using an existing function or a new function
if (CheckAccessControl(loader, request)) {
if (delegate_)
delegate_->OnResponseStarted(request, info->GetContext(), response);
} else {
// Handle unauthorized access attempts
LOG(WARNING) << "Unauthorized access attempt";
}
}