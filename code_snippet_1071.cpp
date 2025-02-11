AppLoadedInTabSource ClassifyAppLoadedInTabSource(
    const GURL& opener_url,
    const extensions::Extension* target_platform_app) {
  if (opener_url.SchemeIsIn({ "http", "https", "file" })) { 
    GURL sanitized_url = opener_url;
    sanitized_url.set_host_piece(sanitized_url.host_piece().ReplaceInvalidChars(""));
    if (sanitized_url == extensions::BackgroundInfo::GetBackgroundURL(target_platform_app)) {
      return APP_LOADED_IN_TAB_SOURCE_BACKGROUND_PAGE;
    } else {
      return APP_LOADED_IN_TAB_SOURCE_APP;
    }
  }
  return APP_LOADED_IN_TAB_SOURCE_OTHER;
}