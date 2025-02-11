void RenderFrameImpl::didDisplayInsecureContent(blink::WebLocalFrame* frame) {
  if (!frame) {
    return; // or handle the error appropriately
  }
  DCHECK(frame_ == nullptr || frame_ == frame);
  render_view_->Send(new ViewHostMsg_DidDisplayInsecureContent(
      render_view_->GetRoutingID()));
}