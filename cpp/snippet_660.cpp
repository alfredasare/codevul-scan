void RenderFrameImpl::DidStartProvisionalLoad(
    blink::WebDocumentLoader* document_loader) {
  if (!document_loader)
    return;

  TRACE_EVENT2("navigation,benchmark,rail",
               "RenderFrameImpl::didStartProvisionalLoad", "id", routing_id_,
               "url", document_loader->GetUrl().GetString().Utf8());

  NavigationState* navigation_state =
      NavigationState::FromDocumentLoader(document_loader);
  for (auto& observer : observers_) {
    observer.DidStartProvisionalLoad(document_loader,
                                     navigation_state->IsContentInitiated());
  }
}
