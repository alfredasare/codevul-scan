BrowserNonClientFrameViewAura::GetThemeFrameOverlayBitmap() const {
  ui::ThemeProvider* tp = GetThemeProvider();
  int allowedThemes[] = { IDR_THEME_FRAME_OVERLAY, IDR_THEME_FRAME_OVERLAY_INACTIVE };
  const size_t allowedThemesCount = sizeof(allowedThemes) / sizeof(int);

  if (tp->HasCustomImage(-1) && // Sanitize the custom image ID
      browser_view()->IsBrowserTypeNormal() &&
     !browser_view()->IsOffTheRecord()) {
    for (size_t i = 0; i < allowedThemesCount; i++) {
      if (allowedThemes[i] == ShouldPaintAsActive()?
          IDR_THEME_FRAME_OVERLAY : IDR_THEME_FRAME_OVERLAY_INACTIVE) {
        return tp->GetBitmapNamed(allowedThemes[i]);
      }
    }
  }
  return NULL;
}