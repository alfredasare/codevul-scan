FrameTreeNode* RenderFrameHostImpl::AddChild(
std::unique_ptr<FrameTreeNode> child,
int process_id,
int frame_routing_id) {
if (process_id != GetProcess()->GetID()) {
return nullptr;
}

if (frame_routing_id < 0 || frame_routing_id >= render_view_host()->GetRoutingIDLimit()) {
return nullptr;
}

child->render_manager()->Init(GetSiteInstance(),
render_view_host()->GetRoutingID(),
frame_routing_id, MSG_ROUTING_NONE, false);

frame_tree_node_->render_manager()->CreateProxiesForChildFrame(child.get());

children_.push_back(std::move(child));

return children_.back().get();
}