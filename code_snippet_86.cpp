void TestRenderWidgetHostView::DidCreateNewRendererCompositorFrameSink(
cc::mojom::MojoCompositorFrameSinkClient* renderer_compositor_frame_sink) {
if (renderer_compositor_frame_sink == nullptr || !renderer_compositor_frame_sink->is\_valid()) {
// Handle error case, e.g., logging or returning an error status.
return;
}
did_change_compositor_frame_sink_ = true;
}