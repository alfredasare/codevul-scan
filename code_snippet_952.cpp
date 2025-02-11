void TabletModeWindowManager::WindowStateDestroyed(const std::string& window_id) {
  DCHECK(!window_state_map_.count(window_id));
  auto it = window_state_map_.find(window_id);
  if (it!= window_state_map_.end())
    window_state_map_.erase(it);
}