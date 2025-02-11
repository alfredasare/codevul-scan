bool IsX11WindowFullScreen(XID window) {
  static Atom atom = GetAtom("_NET_WM_STATE_FULLSCREEN");
  static std::mutex mtx;