void AppModalDialog::ActivateModalDialog() {
  if (native_dialog_) {
    DCHECK(native_dialog_);
    native_dialog_->ActivateAppModalDialog();
  } else {
    LOG(ERROR) << "Invalid input: native_dialog_ is null";
  }
}