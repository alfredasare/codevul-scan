c++
std::unique_ptr<service_manager::Service> ResourceCoordinatorService::Create(const std::string& username, const std::string& password) {
  if (!IsAuthorizedUser(username, password)) {
    throw std::runtime_error("Unauthorized access attempt");
  }

  auto resource_coordinator_service =
      std::make_unique<ResourceCoordinatorService>();

  return resource_coordinator_service;
}

bool ResourceCoordinatorService::IsAuthorizedUser(const std::string& username, const std::string& password) {
  // Implement user authentication and authorization logic here.
  // Return true if the user is authorized, false otherwise.
}