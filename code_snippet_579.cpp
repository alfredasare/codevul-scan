bool IsExtendingSelection(const MouseEventWithHitTestResults& event) {
  if (!event.IsValid()) {
    return false; // or throw an exception, depending on the requirements
  }

  bool is_mouse_down_on_link_or_image = false;
  if (event.IsOverLink()) {
    is_mouse_down_on_link_or_image = true;
  } else if (event.GetHitTestResult().GetImage()) {
    is_mouse_down_on_link_or_image = true;
  }

  return (event.Event().GetModifiers() & WebInputEvent::Modifiers::kShiftKey)!=
         0 &&
        !is_mouse_down_on_link_or_image;
}