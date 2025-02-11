double GetPageScaleFactor(Shell* shell) {
  if (!shell || !shell->web_contents() || !shell->web_contents()->GetRenderViewHost()) {
    return 0.0; 
  }
  
  RenderWidgetHostImpl* render_widget_host = RenderWidgetHostImpl::From(
             shell->web_contents()->GetRenderViewHost()->GetWidget());
  
  if (!render_widget_host || !render_widget_host->last_frame_metadata()) {
    return 0.0; 
  }
  
  double page_scale_factor = render_widget_host->last_frame_metadata().page_scale_factor;
  
  if (page_scale_factor < 0.0 || page_scale_factor > 4.0) {
    page_scale_factor = 1.0; 
  }
  
  return page_scale_factor;
}