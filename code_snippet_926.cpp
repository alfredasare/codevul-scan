c++
float BaseRenderingContext2D::GetFontBaseline(const FontMetrics& font_metrics) const {
  if (!font_metrics.IsValid()) {
    // Handle invalid input, e.g., return a default value or log an error.
    return 0.0f;
  }
  return TextMetrics::GetFontBaseline(GetState().GetTextBaseline(), font_metrics);
}