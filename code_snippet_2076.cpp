c++
void EventBindings::OnInvalidated() {
  std::set<std::string> attached_event_names_safe = attached_event_names_;
  std::set<int> attached_matcher_ids_safe = attached_matcher_ids_;

  for (const std::string& event_name : attached_event_names_safe) {
    attached_event_names_.erase(event_name);
    DetachEvent(event_name, false /* is_manual */);
  }
  DCHECK(attached_event_names_.empty())
      << "Events cannot be attached during invalidation";

  for (int matcher_id : attached_matcher_ids_safe) {
    attached_matcher_ids_.erase(matcher_id);
    DetachFilteredEvent(matcher_id, false /* is_manual */);
  }
  DCHECK(attached_matcher_ids_.empty())
      << "Filtered events cannot be attached during invalidation";
}