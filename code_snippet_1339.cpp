bool IsTransportSocketPoolStalled(net::HttpNetworkSession* session) {
  std::unique_ptr<net::TransportSocketPool, net::TransportSocketPoolDeleter>
      normal_socket_pool(session->GetTransportSocketPool(net::HttpNetworkSession::NORMAL_SOCKET_POOL));
  return normal_socket_pool && normal_socket_pool->IsStalled();
}