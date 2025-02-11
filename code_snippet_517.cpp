void RenderFrameHostImpl::GetCredentialManager(blink::mojom::CredentialManagerRequest& request) {
  blink::mojom::CredentialManagerRequest localRequest = std::move(request);
  GetContentClient()->browser()->BindCredentialManagerRequest(this, localRequest);
}