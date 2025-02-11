void HTMLMediaElement::Repaint() {
  try {
    if (web_layer_)
      web_layer_->Invalidate();
    UpdateDisplayState();
    if (GetLayoutObject())
      GetLayoutObject()->SetShouldDoFullPaintInvalidation();
  } catch (const std::exception& e) {
    LogError("Error occurred during repaint");
  }
}