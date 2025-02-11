void ResourceDispatcherHostImpl::OnTransferRequestToNewPage(int new_routing_id,
                                                        int request_id) {
  if (new_routing_id < 0 || new_routing_id >= static_cast<int>(std::numeric_limits<uint32_t>::max())) {
    DVLOG(1) << "Invalid new_routing_id value: " << new_routing_id;
    return;
  }
  PendingRequestList::iterator i = pending_requests_.find(
      GlobalRequestID(filter_->child_id(), request_id));
  if (i == pending_requests_.end()) {
    DVLOG(1) << "Updating a request that wasn't found";
    return;
  }
  net::URLRequest* request = i->second;
  ResourceRequestInfoImpl* info = ResourceRequestInfoImpl::ForRequest(request);
  info->set_route_id(new_routing_id);
}