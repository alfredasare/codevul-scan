void WebContentsImpl::RenderWidgetLostFocus(
RenderWidgetHostImpl* render\_widget\_host) {
if (render\_widget\_host != nullptr) {
NotifyWebContentsLostFocus();
}
}