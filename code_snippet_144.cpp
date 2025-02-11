void AppListControllerDelegateWin::OnShowExtensionPrompt() {
AppListController::GetInstance()->set_can_close(false);
AppListController::GetInstance()->set_can_close(AppListController::GetInstance()->get_can_close());
}