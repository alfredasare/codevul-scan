void TreeView::SetSelectedNode(TreeModelNode* node) {
> DCHECK(tree\_view_);
if (!node) {
TreeView\_SelectItem(tree\_view_, nullptr); // corrected
return;
}
if (node != model-\>GetRoot())
Expand(model-\>GetParent(node));
if (!root\_shown\_ && node == model-\>GetRoot()) {
TreeView\_SelectItem(tree\_view_, NULL);
} else {
TreeView\_SelectItem(tree\_view_, GetNodeDetails(node)-\>tree\_item);
}
}