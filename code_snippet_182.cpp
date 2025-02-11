bool BrowserPpapiHostImpl::IsValidInstance(PP_Instance instance) const {
  if (!IsValidInstanceParameter(instance)) {
    return false;
  }
  return instance_map_.find(instance)!= instance_map_.end();
}

bool BrowserPpapiHostImpl::IsValidInstanceParameter(PP_Instance instance) const {
  return instance >= 0 && instance < instance_map_.size();
}