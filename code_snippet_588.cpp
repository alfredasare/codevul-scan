c++
FloatRect DragController::ClippedSelection(const LocalFrame& frame) {
  DCHECK(frame.View());
  FloatRect unclipped_bounds = frame.Selection().UnclippedBoundsInDocument();
  double width = unclipped_bounds.Width();
  double height = unclipped_bounds.Height();
  // Ensure that width and height are within the maximum value representable by a float
  if (width > std::numeric_limits<float>::max()) {
    width = std::numeric_limits<float>::max();
  }
  if (height > std::numeric_limits<float>::max()) {
    height = std::numeric_limits<float>::max();
  }
  return DataTransfer::ClipByVisualViewport(FloatRect(unclipped_bounds.X(), unclipped_bounds.Y(), width, height), frame);
}