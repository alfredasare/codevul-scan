bool TabsCaptureVisibleTabFunction::IsValidWindowId(int window_id) {
  const int min_window_id = 0;
  const int max_window_id = 100; // Define a reasonable maximum value based on your application's logic
  return window_id >= min_window_id && window_id < max_window_id;
}

WebContents* TabsCaptureVisibleTabFunction::GetWebContentsForID(
    int window_id,
    std::string* error) {
  if (!IsValidWindowId(window_id)) {
    *error = "Invalid window ID";
    return nullptr;
  }

  Browser* browser = nullptr;
  if (!GetBrowserFromWindowID(chrome_details_, window_id, &browser, error))
    return nullptr;

  if (browser->GetTabCount() == 0) {
    *error = "No active web contents to capture";
    return nullptr;
  }

  const int active_tab_id = browser->tab_strip_model()->GetActiveWebContents()->GetMainFrame()->GetIdentifier();
  if (!extension()->permissions_data()->CanCaptureVisiblePage(active_tab_id, error)) {
    return nullptr;
  }

  return browser->tab_strip_model()->GetActiveWebContents();
}