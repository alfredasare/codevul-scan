void RenderFrameDevToolsAgentHost::DidReceiveCompositorFrame() {
  std::string metadataStr = RenderWidgetHostImpl::From(
      web_contents()->GetRenderViewHost()->GetWidget())
          ->last_frame_metadata().SerializeToString();
  size_t metadataSize = metadataStr.size();
  if (metadataSize > kMaxMetadataBufferSize) {
    metadataStr.truncate(kMaxMetadataBufferSize);
  }
  for (auto* page : protocol::PageHandler::ForAgentHost(this))
    page->OnSwapCompositorFrame(metadataStr);
  //...
}