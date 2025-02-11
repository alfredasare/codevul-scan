bool RenderFrameHostManager::ReinitializeRenderFrame(
    RenderFrameHostImpl* render_frame_host) {
  DCHECK(!render_frame_host->IsRenderFrameLive());

  try {
    CreateOpenerProxies(render_frame_host->GetSiteInstance(), frame_tree_node_);
  } catch (const std::exception& e) {
    LOG(ERROR) << "Error creating opener proxies: " << e.what();
    return false;
  }

  try {
    if (!frame_tree_node_->parent()) {
      DCHECK(!GetRenderFrameProxyHost(render_frame_host->GetSiteInstance()));
      if (!InitRenderView(render_frame_host->render_view_host(), nullptr)) {
        LOG(ERROR) << "Error initializing render view";
        return false;
      }
    } else {
      if (!InitRenderFrame(render_frame_host)) {
        LOG(ERROR) << "Error initializing render frame";
        return false;
      }

      RenderFrameProxyHost* proxy_to_parent = GetProxyToParent();
      if (proxy_to_parent) {
        const gfx::Size* size = render_frame_host->frame_size()
                                ? &*render_frame_host->frame_size()
                                  : nullptr;
        try {
          GetProxyToParent()->SetChildRWHView(render_frame_host->GetView(), size);
        } catch (const std::exception& e) {
          LOG(ERROR) << "Error setting child RWH view: " << e.what();
          return false;
        }
      }
    }
  } catch (const std::exception& e) {
    LOG(ERROR) << "Unexpected error: " << e.what();
    return false;
  }

  DCHECK(render_frame_host->IsRenderFrameLive());
  return true;
}