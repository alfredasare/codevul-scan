views::View* LockScreenMediaControlsView::GetMiddleSpacingView() {
if (CheckAccessControl()) { // replace CheckAccessControl() with a proper access control check
return middle_spacing_.get();
}
return nullptr;
}