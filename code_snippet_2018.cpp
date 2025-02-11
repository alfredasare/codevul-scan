c++
void HTMLFormControlElement::DispatchChangeEvent() {
  if (IsSecureContext()) {
    DispatchScopedEvent(*Event::CreateBubble(event_type_names::kChange));
  } else {
    // Handle insecure context or throw an exception
  }
}