void RenderFrameHostImpl::CreateWebSocket(network::mojom::WebSocketRequest request) {
  network::mojom::AuthenticationHandlerPtr auth_handler;
  GetContentClient()->browser()->WillCreateWebSocket(this, &request, &auth_handler);

  auto auth_handler_ptr = std::make_unique<network::mojom::AuthenticationHandlerPtr>(std::move(auth_handler));

  WebSocketManager::CreateWebSocket(process_->GetID(), routing_id_, last_committed_origin_, std::move(auth_handler_ptr), std::move(request));
}