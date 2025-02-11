void MetricsWebContentsObserver::DidRedirectNavigation(
    content::NavigationHandle* navigation_handle) {
  if (!navigation_handle->IsInMainFrame())
    return;
  auto it = provisional_loads_.find(navigation_handle);
  if (it == provisional_loads_.end() || it->second == nullptr ||
      !it->second->is_valid())
    return;
  it->second->Redirect(navigation_handle);
}