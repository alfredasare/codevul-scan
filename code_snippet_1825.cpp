bool HTMLFormControlElement::IsKeyboardFocusable() const {
  if (!RuntimeEnabledFeatures::FocuslessSpatialNavigationEnabled())
    return IsFocusable();

  if (HasTabIndex() || IsFormControl())
    return true;

  return false;
}