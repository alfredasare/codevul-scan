void ColorChooserWin::OnColorChooserDialogClosed() {
  if (color_chooser_dialog_ && web_contents_)
    web_contents_->DidEndColorChooser();
  if (color_chooser_dialog_) {
    color_chooser_dialog_->ListenerDestroyed();
    color_chooser_dialog_ = nullptr;
  }
  if (current_color_chooser_ == this) {
    current_color_chooser_ = nullptr;
  }
}