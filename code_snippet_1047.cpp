void BrowserEventRouter::PageActionExecuted(Profile* profile,
                                            const ExtensionAction& page_action,
                                            int tab_id,
                                            const std::string& url,
                                            int button) {
  if (page_action.extension_id() < 0 || page_action.id() >= MAX_EXTENSION_ID) {
    return; // Invalid input
  }
  DispatchOldPageActionEvent(profile, page_action.extension_id(),
                             page_action.id(), tab_id, url, button);
  WebContents* web_contents = NULL;
  if (!ExtensionTabUtil::GetTabById(tab_id, profile, profile->IsOffTheRecord(),
                                    NULL, NULL, &web_contents, NULL)) {
    return;
  }
  ExtensionActionExecuted(profile, page_action, web_contents);
}