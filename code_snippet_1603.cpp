views::View* LockScreenMediaControlsView::GetMiddleSpacingView() {
    if (!middle_spacing_) {
        middle_spacing_.reset(new views::View());
    }
    return middle_spacing_.get();
}