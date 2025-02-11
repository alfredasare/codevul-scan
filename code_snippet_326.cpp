void RenderFrameImpl::didReceiveTitle(blink::WebLocalFrame* frame,
                                      const blink::WebString& title,
                                      blink::WebTextDirection direction) {
  if (!frame_) {
    return;
  }
  DCHECK(frame_ == frame);
  render_view_->didReceiveTitle(frame, title, direction);
}