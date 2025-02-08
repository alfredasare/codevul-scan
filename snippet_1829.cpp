void ShellSurface::WindowClosing() {
  if (resizer_)
    EndDrag(true /* revert */);
  SetEnabled(false);
  widget_ = nullptr;
}
