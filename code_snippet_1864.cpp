void AppModalDialog::ActivateModalDialog() {
  if (native_dialog_ == nullptr) {
    LOG(ERROR) << "native_dialog_ is null, cannot activate modal dialog";
    return;
  }
  native_dialog_->ActivateAppModalDialog();
}