void ServerStartedOnUI(base::WeakPtr<DevToolsHttpHandler> handler,
                       base::Thread* thread,
                       ServerWrapper* server_wrapper,
                       DevToolsSocketFactory* socket_factory,
                       std::unique_ptr<net::IPEndPoint> ip_address) {
  DCHECK_CURRENTLY_ON(BrowserThread::UI);

  if (!handler ||!thread ||!server_wrapper) {
    LOG(ERROR) << "Invalid input parameters";
    return;
  }

  if (!ip_address ||!ip_address->IsValid()) {
    LOG(ERROR) << "Invalid IP address";
    return;
  }

  handler->ServerStarted(std::move(thread), std::move(server_wrapper), std::move(socket_factory), std::move(ip_address));
}