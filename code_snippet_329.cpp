void RenderFrameImpl::didReceiveTitle(blink::WebLocalFrame* frame,
                                   const blink::WebString& title,
                                   blink::WebTextDirection direction) {
  // Validate the frame pointer to ensure it's not tampered with
  if (!frame || frame != frame_ || !frame->parent()) {
    LOG(WARNING) << "Invalid frame pointer received";
    return;
  }

  render_view_->didReceiveTitle(frame, title, direction);
}