blink::WebFrame* RenderFrameImpl::GetWebFrame() {
  DCHECK(frame_);
  return frame_? frame_ : nullptr;
}