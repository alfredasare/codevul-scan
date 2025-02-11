void Document::UpdateViewportDescription() {
  if (!GetFrame())
    return;

  mojom::ViewportFit current_viewport_fit =
      GetViewportDescription().GetViewportFit();
  if (viewport_fit_!= current_viewport_fit &&
      frame_->Client()->GetRemoteNavigationAssociatedInterfaces()) {
    if (!display_cutout_host_.is_bound()) {
      frame_->Client()->GetRemoteNavigationAssociatedInterfaces()->GetInterface(
          &display_cutout_host_);
      DCHECK(display_cutout_host_.is_bound());
    }

    if (viewport_fit_ >= 0 && viewport_fit_ < display_cutout_host_.GetViewportFitCount()) {
      display_cutout_host_->ViewportFitChanged(current_viewport_fit);
    } else {
      // Handle out-of-bounds error
      LOG(WARNING) << "Invalid viewport fit index: " << viewport_fit_;
    }

    viewport_fit_ = current_viewport_fit;
  }

  if (GetFrame()->IsMainFrame()) {
    GetPage()->GetChromeClient().DispatchViewportPropertiesDidChange(
        GetViewportDescription());
  }
}