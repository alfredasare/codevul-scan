std::unique_ptr<ColorChooserDialog> color_chooser_dialog_;
std::unique_ptr<ColorChooser> current_color_chooser_;

void ColorChooserWin::OnColorChooserDialogClosed() {
  if (color_chooser_dialog_) {
    color_chooser_dialog_->ListenerDestroyed();
    color_chooser_dialog_.reset();
  }
  DCHECK(current_color_chooser_ == this);
  current_color_chooser_.reset();
  if (web_contents_) {
    web_contents_->DidEndColorChooser();
  }
}