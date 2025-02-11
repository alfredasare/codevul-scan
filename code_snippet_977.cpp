std::unique_ptr<ResourceCoordinatorService> ResourceCoordinatorService::Create() {
  auto resource_coordinator_service = std::make_unique<ResourceCoordinatorService>();

  resource_coordinator_service->SetShutdownCallback([this]() {
    resource_coordinator_service.reset();
  });

  return resource_coordinator_service;
}