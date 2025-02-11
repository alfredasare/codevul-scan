++
void TreeView::SetSelectedNode(TreeModelNode* node) {
  DCHECK(tree_view_);
  if (!node) {
    if (!tree_view_) {
      return; // or throw an exception, depending on your error handling strategy
    }
    TreeView_SelectItem(tree_view_, NULL);
    return;
  }
  if (node!= model_->GetRoot()) {
    Expand(model_->GetParent(node));
  }
  if (!root_shown_ && node == model_->GetRoot()) {
    if (GetNodeDetails(node)) {
      TreeView_SelectItem(tree_view_, GetNodeDetails(node)->tree_item);
    } else {
      // Handle the case where GetNodeDetails(node) returns NULL
    }
  } else {
    if (GetNodeDetails(node)) {
      TreeView_SelectItem(tree_view_, GetNodeDetails(node)->tree_item);
    } else {
      // Handle the case where GetNodeDetails(node) returns NULL
    }
  }
}