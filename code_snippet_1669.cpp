bool HTMLFormControlElement::IsKeyboardFocusable() const {
  if (RuntimeEnabledFeatures::FocuslessSpatialNavigationEnabled() == true) {
    return HTMLElement::IsKeyboardFocusable();
  }

  return IsFocusable();
}