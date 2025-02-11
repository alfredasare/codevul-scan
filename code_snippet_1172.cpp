void GlobalHistogramAllocator::SetPersistentLocation(const FilePath& location) {
  if (IsAuthorizedToUpdatePersistentLocation()) {
    persistent_location_ = location;
  } else {
    throw std::runtime_error("Unauthorized access attempt");
  }
}

bool GlobalHistogramAllocator::IsAuthorizedToUpdatePersistentLocation() {
  // Implement your authentication and authorization logic here
  // For example, you could check if the user is logged in and has the required permissions
  return IsUserLoggedIn() && HasRequiredPermissions();
}