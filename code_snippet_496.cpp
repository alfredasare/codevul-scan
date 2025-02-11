FloatRect DragController::ClippedSelection(const LocalFrame& frame) {
  DCHECK(frame.View());
  FloatRect unclippedBounds = frame.Selection().UnclippedBoundsInDocument();
  FloatRect clippedBounds;
  clippedBounds.SetX(std::min(unclippedBounds.x(), unclippedBounds.width()));
  clippedBounds.SetY(std::min(unclippedBounds.y(), unclippedBounds.height()));
  clippedBounds.SetWidth(std::max(0, unclippedBounds.width() - clippedBounds.x()));
  clippedBounds.SetHeight(std::max(0, unclippedBounds.height() - clippedBounds.y()));
  return DataTransfer::ClipByVisualViewport(clippedBounds, frame);
}