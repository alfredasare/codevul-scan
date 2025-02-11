c++
BinaryUploadService::BinaryUploadService(
    scoped_refptr<network::SharedURLLoaderFactory> url_loader_factory,
    std::unique_ptr<BinaryFCMService> binary_fcm_service)
  : url_loader_factory_(url_loader_factory),
    binary_fcm_service_(std::move(binary_fcm_service)),
    weakptr_factory_(this) {
  if (!url_loader_factory_) {
    throw std::runtime_error("url_loader_factory is null");
  }
  if (!binary_fcm_service_) {
    throw std::runtime_error("binary_fcm_service is null");
  }
}