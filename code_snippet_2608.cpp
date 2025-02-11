double GetPageScaleFactor(Shell* shell) {
      if (shell && shell->web_contents() &&
          shell->web_contents()->GetRenderViewHost() &&
          RenderWidgetHostImpl::From(
              shell->web_contents()->GetRenderViewHost()->GetWidget())) {
        return RenderWidgetHostImpl::From(
                   shell->web_contents()->GetRenderViewHost()->GetWidget())
            ->last_frame_metadata()
            .page_scale_factor;
      }
      return 1.0; // Default value in case of null or error
    }