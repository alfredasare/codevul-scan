FrameTreeNode* RenderFrameHostImpl::AddChild(
    std::unique_ptr<FrameTreeNode> child,
    size_t process_id,
    size_t frame_routing_id) {
  CHECK_EQ(process_id, GetProcess()->GetID());

  child->render_manager()->Init(GetSiteInstance(),
                                render_view_host()->GetRoutingID(),
                                frame_routing_id, MSG_ROUTING_NONE, false);

  frame_tree_node_->render_manager()->CreateProxiesForChildFrame(child.get());

  children_.push_back(std::move(child));

  return children_.back().get();
}