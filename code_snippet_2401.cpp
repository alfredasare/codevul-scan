gfx::Rect Label::GetAvailableRect() const {
  gfx::Rect bounds(gfx::Point(), size());
  gfx::Insets insets(GetInsets());

  // Clamp width and height to zero if negative.
  bounds.set_width(std::max(0, bounds.width() - (insets.left() + insets.right())));
  bounds.set_height(std::max(0, bounds.height() - (insets.top() + insets.bottom())));

  return bounds;
}