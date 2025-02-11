class LogHelper {
 public:
  static void LogError(const std::string& message) {
    LOG(INFO) << "Error: " << message;
  }
};

bool IsTransportSocketPoolStalled(net::HttpNetworkSession* session) {
  auto transportSocketPool = session->GetTransportSocketPool(net::HttpNetworkSession::NORMAL_SOCKET_POOL);
  if (!transportSocketPool) {
    LogHelper::LogError("Failed to get transport socket pool");
    return false;
  }
  if (transportSocketPool->IsStalled()) {
    return true;
  }
  return false;
}