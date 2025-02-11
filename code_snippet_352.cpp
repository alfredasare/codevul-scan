void AutofillDialogViews::SectionContainer::OnMouseEntered(
const ui::MouseEvent& event) {
if (!ShouldForwardEvent(event))
return;

// Validate the event type
if (event.type() < ui::ET_MOUSE_FIRST || event.type() > ui::ET_MOUSE_LAST) {
LOG(WARNING) << "Invalid event type received: " << event.type();
return;
}

SetActive(true);
proxy\_button_->OnMouseEntered(ProxyEvent(event));
SchedulePaint();
}