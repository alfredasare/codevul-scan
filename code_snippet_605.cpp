void TabStripModel::AddSelectionFromAnchorTo(int index) {
 const int old\_active = active\_index();
 selection\_model\_.AddSelectionFromAnchorTo(index);
 if (old\_active >= 0 && old\_active < selection\_model\_.count()) {
 NotifySelectionChanged(old\_active);
 }
}