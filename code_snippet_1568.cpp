mutex mtx;
bool ImeObserver::HasListener(const std::string& event_name) const {
  std::unique_lock<mutex> lock(mtx);
  return extensions::EventRouter::Get(profile_)->HasEventListener(event_name);
}