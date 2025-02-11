c++
void WebContentsImpl::DidStartLoading(FrameTreeNode* frame_tree_node,
                                      bool to_different_document) {
  // Validate the input parameter before using it
  if (frame_tree_node && frame_tree_node->current_frame_host()) {
    LoadingStateChanged(frame_tree_node->IsMainFrame() && to_different_document,
                        false, nullptr);

    BrowserAccessibilityManager* manager =
        frame_tree_node->current_frame_host()->browser_accessibility_manager();
    if (manager)
      manager->UserIsNavigatingAway();
  }
}