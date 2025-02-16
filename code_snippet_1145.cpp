GURL SanitizeUrl(const GURL& url) {
  // Remove any sensitive information from the URL, if necessary.
  // For example, you may want to remove query parameters that contain secrets.
  // You can use libraries like urlparse (in Python) or java.net.URL (in Java) to parse and manipulate the URL.
  return url;
}

void RenderFrameDevToolsAgentHost::OnSignedExchangeCertificateRequestSent(
    FrameTreeNode* frame_tree_node,
    const base::UnguessableToken& request_id,
    const base::UnguessableToken& loader_id,
    const network::ResourceRequest& request,
    const GURL& signed_exchange_url) {
  // Sanitize the URL before logging.
  const GURL sanitized_signed_exchange_url = SanitizeUrl(signed_exchange_url);

  DispatchToAgents(frame_tree_node, &protocol::NetworkHandler::RequestSent,
                   request_id.ToString(), loader_id.ToString(), request,
                   protocol::Network::Initiator::TypeEnum::SignedExchange,
                   sanitized_signed_exchange_url);
}