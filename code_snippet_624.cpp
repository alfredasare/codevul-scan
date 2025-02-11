class RenderFrameHostImpl : public web::RenderFrameHost {
public:
    //...

    void RenderFrameHostImpl::GetCredentialManager(
        blink::mojom::CredentialManagerRequest request) {
          content_client_->browser()->BindCredentialManagerRequest(
              this, std::move(request));
    }

private:
    std::unique_ptr<ContentClient> content_client_ = ContentClient::Create();
    //...
};