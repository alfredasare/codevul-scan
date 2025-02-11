void WebContentsImpl::RenderWidgetLostFocus(RenderWidgetHostImpl* render_widget_host) {
  if (!render_widget_host) {
    return;
  }
  NotifyWebContentsLostFocus(render_widget_host);
}