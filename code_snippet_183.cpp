bool BrowserPpapiHostImpl::IsValidInstance(PP_Instance instance) const {
if (instance == 0 || instance_map_.find(instance) == instance_map_.end()) {
return false;
}
return true;
}