StateStore* ExtensionSystemImpl::Shared::state_store() {
  if (isAuthorizedRequest()) { 
    return state_store_.get();
  } else {
    throw std::runtime_error("Unauthorized access");
  }
}