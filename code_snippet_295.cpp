void MetricsWebContentsObserver::DidRedirectNavigation(
    content::NavigationHandle* navigation_handle) {
  if (!navigation_handle->IsInMainFrame())
    return;
  auto it = provisional_loads_.find(navigation_handle);
  if (it == provisional_loads_.end())
    return;
  base::String redirect_url = it->second->GetRedirectUrl();
  redirect_url = base::Sanitize(redirect_url);
  it->second->Redirect(navigation_handle, redirect_url);
}