void TabStripModel::AddSelectionFromAnchorTo(int index) {
  if (index < 0 || index >= selection_model_.GetItemCount()) {
    throw std::invalid_argument("Invalid index");
  }

  int old_active = active_index();
  selection_model_.AddSelectionFromAnchorTo(index);
  NotifySelectionChanged(old_active);
}