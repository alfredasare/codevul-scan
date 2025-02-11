WebContents* TabsCaptureVisibleTabFunction::GetWebContentsForID(
    int window_id,
    std::string* error) {
  //... (rest of the function remains the same)

  // Validate window_id
  if (window_id < 0 || window_id >= chrome_details_.GetNumWindows()) {
    *error = "Invalid window ID";
    return nullptr;
  }

  Browser* browser = NULL;
  if (!GetBrowserFromWindowID(chrome_details_, window_id, &browser, error))
    return nullptr;

  //... (rest of the function remains the same)
}