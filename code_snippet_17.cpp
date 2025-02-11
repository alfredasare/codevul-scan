c++
cc::Layer* ScrollHitTestLayerAt(unsigned index) {
  auto* extra_data = paint_artifact_compositor()->GetExtraDataForTesting();
  if (!extra_data) return nullptr;
  auto* web_layer = dynamic_cast<ScrollHitTestWebLayer*>(extra_data);
  return web_layer ? web_layer->ScrollHitTestWebLayerAt(index) : nullptr;
}