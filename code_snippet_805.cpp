c++
void Document::UpdateViewportDescription() {
  if (!GetFrame())
    return;

  mojom::ViewportFit current_viewport_fit =
      GetViewportDescription().GetViewportFit();
  if (viewport_fit_ != current_viewport_fit &&
      frame_->Client()->GetRemoteNavigationAssociatedInterfaces()) {
    if (!display_cutout_host_.is_bound()) {
      if (frame_->Client()->GetRemoteNavigationAssociatedInterfaces()->GetInterface(&display_cutout_host_)) {
        DCHECK(display_cutout_host_.is_bound());
        display_cutout_host_->ViewportFitChanged(current_viewport_fit);
      } else {
        LOG(ERROR) << "Failed to bind display_cutout_host_ object.";
        return;
      }
    } else {
      display_cutout_host_->ViewportFitChanged(current_viewport_fit);
    }
  }

  if (GetFrame()->IsMainFrame()) {
    GetPage()->GetChromeClient().DispatchViewportPropertiesDidChange(
        GetViewportDescription());
  }
}