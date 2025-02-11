blink::WebFrame* RenderFrameImpl::GetWebFrame() {
> if (frame_) {
> return frame_;
> } else {
> return nullptr;
> }
}