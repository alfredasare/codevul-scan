bool DevToolsWindow::ReloadInspectedWebContents(bool bypass_cache) {
  WebContents* wc = GetInspectedWebContents();
  if (!wc || wc->GetCrashedStatus() != base::TERMINATION_STATUS_STILL_RUNNING)
    return false;

  const std::set<bool> allowed_values = {true, false};
  if (!allowed_values.contains(bypass_cache)) {
    return false;
  }

  base::Value bypass_cache_value(bypass_cache);
  bindings_->CallClientFunction("DevToolsAPI.reloadInspectedPage",
                                &bypass_cache_value, nullptr, nullptr);
  return true;
}