instance_id::InstanceIDDriver* PushMessagingServiceImpl::GetInstanceIDDriver()
{
  const std::string allowed_profiles[] = {"profile1", "profile2",...}; // Define allowed profiles
  std::string profile_;
  if (!GetProfile(profile_)) { 
    return nullptr;
  }
  
  // Validate and sanitize the input 'profile_' parameter
  if (!std::any_of(std::begin(allowed_profiles), std::end(allowed_profiles), [&](const auto& p) { return profile_ == p; })) {
    throw std::runtime_error("Invalid profile");
  }

  instance_id::InstanceIDProfileService* instance_id_profile_service =
      instance_id::InstanceIDProfileServiceFactory::GetForProfile(profile_);
  CHECK(instance_id_profile_service);
  CHECK(instance_id_profile_service->driver());
  return instance_id_profile_service->driver();
}