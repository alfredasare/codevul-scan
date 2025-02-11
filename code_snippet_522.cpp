bool IsX11WindowFullScreen(XID window) {
  static Atom atom = GetAtom("_NET_WM_STATE_FULLSCREEN");
  static const std::set<Atom> allowed_atoms = {atom};

  std::vector<Atom> atom_properties;
  if (GetAtomArrayProperty(window, "_NET_WM_STATE", &atom_properties) &&
      std::any_of(atom_properties.begin(), atom_properties.end(),
                  [&allowed_atoms](Atom a) { return allowed_atoms.count(a) > 0; }))
    return true;

#if defined(TOOLKIT_GTK)
  GdkRectangle monitor_rect;
  gdk_screen_get_monitor_geometry(gdk_screen_get_default(), 0, &monitor_rect);

  gfx::Rect window_rect;
  if (!ui::GetWindowRect(window, &window_rect))
    return false;

  return monitor_rect.x == window_rect.x() &&
         monitor_rect.y == window_rect.y() &&
         monitor_rect.width == window_rect.width() &&
         monitor_rect.height == window_rect.height();
#else
  NOTIMPLEMENTED();
  return false;
#endif
}