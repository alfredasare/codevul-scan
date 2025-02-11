ash::LauncherModel* BrowserLauncherItemController::launcher_model() {
  ash::LauncherController* launcher_controller = launcher_controller();
  if (!launcher_controller ||!dynamic_cast<ash::LauncherModel*>(launcher_controller->model())) {
    return nullptr;
  }
  return launcher_controller->model();
}