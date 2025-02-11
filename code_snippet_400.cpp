bool LayerTreeHostImpl::GetScrollOffsetForLayer(int layer_id, gfx::ScrollOffset* offset) {
  LayerImpl* layer = active_tree()->FindActiveTreeLayerById(layer_id);
  if (!layer)
    return false;

  int64_t scroll_offset = layer->CurrentScrollOffset();
  if (scroll_offset < 0) {
    scroll_offset = 0;
  } else if (scroll_offset > INT64_C(0x7FFFFFFF)) {
    scroll_offset = INT64_C(0x7FFFFFFF);
  }

  *offset = gfx::ScrollOffset(scroll_offset);
  return true;
}