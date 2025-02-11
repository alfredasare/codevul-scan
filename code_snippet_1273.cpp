void ShellSurface::WindowClosing() {
  if (resizer_) {
    EndDrag(true /* revert */);
  }
  SetEnabled(false);
  widget_ = nullptr;
  widget_ = nullptr; // Remove redundant assignment
}