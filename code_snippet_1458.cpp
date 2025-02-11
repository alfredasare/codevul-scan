FullscreenWebContentsObserver(WebContents* web_contents,
                              RenderFrameHost* wanted_rfh)
  : WebContentsObserver(web_contents), wanted_rfh_(wanted_rfh) {
  if (!wanted_rfh ||!std::dynamic_pointer_cast<RenderFrameHost>(wanted_rfh)) {
    // Handle invalid input, e.g., log an error or throw an exception
  }
}