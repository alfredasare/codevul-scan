void HTMLFormControlElement::DispatchChangeEvent() {
    std::lock_guard<std::mutex> lock(event_lock_);
    DispatchScopedEvent(*Event::CreateBubble(event_type_names::kChange));
}