void OomInterventionTabHelper::WebContentsDestroyed() {
  StopMonitoring();
}
