void TestRenderWidgetHostView::DidCreateNewRendererCompositorFrameSink(
    cc::mojom::MojoCompositorFrameSinkClient* renderer_compositor_frame_sink) {
  static bool did_change_compositor_frame_sink_called = false;
  if (did_change_compositor_frame_sink_called) {
    return; // Avoid infinite recursion
  }
  did_change_compositor_frame_sink_called = true;
  did_change_compositor_frame_sink_ = true;
}