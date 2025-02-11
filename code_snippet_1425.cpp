void ShellSurface::WindowClosing() {
  if (resizer_)
    EndDrag(true /* revert */);
  widget_ = nullptr;
  SetEnabled(false);
}