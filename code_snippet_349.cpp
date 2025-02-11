void AutofillDialogViews::SectionContainer::OnMouseEntered(const ui::MouseEvent& event) {
  if (!IsValidEvent(event)) {
    return; // invalid input, do nothing
  }

  SetActive(true);
  proxy_button_->OnMouseEntered(ProxyEvent(event));
  SchedulePaint();
}

bool IsValidEvent(const ui::MouseEvent& event) {
  return event.type == ui::MouseEvent::Type::MOUSE_ENTER && event.x >= 0 && event.x <= GetWidth() && event.y >= 0 && event.y <= GetHeight();
}