void DesktopWindowTreeHostX11::ShowImpl() {
  gfx::Rect rect = Show(ui::SHOW_STATE_NORMAL);
  // Validate the rect before accessing its elements
  if (rect.IsValid()) {
    // Access the rect's elements safely
    int width = rect.width();
    int height = rect.height();
    //...
  }
}