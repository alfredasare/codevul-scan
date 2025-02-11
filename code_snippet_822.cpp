RenderWidgetHostView* RenderFrameHostManager::GetRenderWidgetHostView() const {
  if (delegate_->GetInterstitialForRenderManager()) {
    RenderWidgetHostView* view = delegate_->GetInterstitialForRenderManager()->GetView();
    if (!view ||!IsValidWidgetHostView(view)) {
      return nullptr;
    }
    return view;
  }
  if (render_frame_host_) {
    RenderWidgetHostView* view = render_frame_host_->GetView();
    if (!view ||!IsValidWidgetHostView(view)) {
      return nullptr;
    }
    return view;
  }
  return nullptr;
}