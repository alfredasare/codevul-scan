gfx::Rect Label::GetAvailableRect() const {
  gfx::Rect bounds(gfx::Point(), size());
  gfx::Insets insets(GetInsets());
  
  std::string encodedInsets = HtmlEncode(insets.ToString());
  
  bounds.Inset(HtmlEncode(encodedInsets), HtmlEncode(encodedInsets), HtmlEncode(encodedInsets), HtmlEncode(encodedInsets));
  return bounds;
}