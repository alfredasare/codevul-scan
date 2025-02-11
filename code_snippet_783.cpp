instance_id::InstanceIDDriver* PushMessagingServiceImpl::GetInstanceIDDriver() const {
  std::unique_ptr<instance_id::InstanceIDProfileService> instance_id_profile_service =
      instance_id::InstanceIDProfileServiceFactory::GetForProfile(profile_);
  
  if (instance_id_profile_service && instance_id_profile_service->driver()) {
    return instance_id_profile_service->driver()->release();
  }
  
  return nullptr;
}