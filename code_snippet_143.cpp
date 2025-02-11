void AppListControllerDelegateWin::OnShowExtensionPrompt() {
  if (AppListController* controller = AppListController::GetInstance()) {
    if (!controller->get_can_close()) {
      controller->set_can_close(false);
    }
  }
}