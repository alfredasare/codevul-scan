bool ListenToGuestWebContents(
    AccessibilityNotificationWaiter* accessibility_waiter,
    WebContents* web_contents) {
  if (!web_contents ||!web_contents->IsMainWorld()) {
    return false;
  }
  accessibility_waiter->ListenToAdditionalFrame(
      static_cast<RenderFrameHostImpl*>(web_contents->GetMainFrame()));
  return true;
}