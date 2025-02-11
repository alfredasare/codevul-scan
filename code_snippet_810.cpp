float BaseRenderingContext2D::GetFontBaseline(const FontMetrics& font_metrics) const {
  try {
    return TextMetrics::GetFontBaseline(GetState().GetTextBaseline(), font_metrics);
  } catch (const std::exception& e) {
    // Log the error and return a generic error message
    std::cerr << "Error occurred while getting font baseline: " << e.what() << std::endl;
    return std::numeric_limits<float>::quiet_NaN(); // Return NaN for invalid results
  }
}