void ResourceDispatcherHostImpl::OnTransferRequestToNewPage(int new_routing_id,
                                                         int request_id) {
  base::FilePath new_routing_path = filter_->child_id()->ToFilePath();
  new_routing_path.Append(new_routing_id);

  PendingRequestList::iterator i = pending_requests_.find(
      GlobalRequestID(new_routing_path.Value(), request_id));
  if (i == pending_requests_.end()) {
    DVLOG(1) << "Updating a request that wasn't found";
    return;
  }
  net::URLRequest* request = i->second;
  ResourceRequestInfoImpl* info = ResourceRequestInfoImpl::ForRequest(request);
  info->set_route_id(new_routing_id);
}