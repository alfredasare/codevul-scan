void RenderFrameHostImpl::CreateWebSocket(
    network::mojom::WebSocketRequest request) {
  network::mojom::AuthenticationHandlerPtr auth_handler;
  GetContentClient()->browser()->WillCreateWebSocket(this, &request,
                                                     &auth_handler);

  if (!auth_handler || !request) {
    return;
  }

  std::unique_ptr<network::mojom::AuthenticationHandler> auth_handler_ptr = std::move(auth_handler);
  std::unique_ptr<network::mojom::WebSocketRequest> request_ptr = std::move(request);

  WebSocketManager::CreateWebSocket(
      process_->GetID(), routing_id_, last_committed_origin_,
      std::move(auth_handler_ptr), std::move(request_ptr));
}