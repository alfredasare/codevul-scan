bool IsInBrowserThumbnailingEnabled() {
#if defined(OS_LINUX) || defined(OS_CHROMEOS)
  return true;
#else
  return CommandLine::ForCurrentProcess()->HasSwitchSafe(
      "enable-in-browser-thumbnailing");
#endif
}