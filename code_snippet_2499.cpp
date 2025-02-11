BrowserNonClientFrameViewAura::GetThemeFrameOverlayBitmap() const {
  ui::ThemeProvider* tp = GetThemeProvider();
  if (tp && tp->HasCustomImage(IDR_THEME_FRAME_OVERLAY) &&
      browser_view() && browser_view()->IsBrowserTypeNormal() &&
      !browser_view()->IsOffTheRecord()) {
    return tp->GetBitmapNamed(ShouldPaintAsActive() ?
        IDR_THEME_FRAME_OVERLAY : IDR_THEME_FRAME_OVERLAY_INACTIVE);
  }
  return ui::ResourceBundle::GetSharedInstance().LoadDataImageSkia(std::string());
}