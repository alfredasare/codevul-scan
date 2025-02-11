++
void WebstorePrivateApi::SetTestingProfileSyncService(ProfileSyncService* service) {
  if (service == nullptr) {
    throw std::invalid_argument("Invalid input: service cannot be null");
  }
  if (!service->isValid()) {
    throw std::invalid_argument("Invalid input: service is not a valid object");
  }
  test_sync_service = service;
}