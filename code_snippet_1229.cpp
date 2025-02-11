c++
void NavigationControllerImpl::Restore(
    int selected_navigation,
    RestoreType type,
    std::vector<std::unique_ptr<NavigationEntry>>* entries) {
  DCHECK(GetEntryCount() == 0 && !GetPendingEntry());

  if (selected_navigation >= 0 && selected_navigation < entries->size()) {
    needs_reload_ = true;
    entries_.assign(entries->begin(), entries->begin() + selected_navigation + 1);
    entries->erase(entries->begin(), entries->begin() + selected_navigation + 1);

    FinishRestore(selected_navigation, type);
  } else {
    // Handle the error condition appropriately, such as throwing an exception or logging an error message.
    throw std::out_of_range("Error: Selected navigation index is out of bounds.");
  }
}