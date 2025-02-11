void PageHandler::Reload(Maybe<bool> bypassCache,
                         Maybe<std::string> script_to_evaluate_on_load,
                         std::unique_ptr<ReloadCallback> callback) {
  WebContentsImpl* web_contents = GetWebContents();
  if (!web_contents) {
    callback->sendFailure(Response::InternalError());
    return;
  }

  // Validate the bypassCache input
  if (bypassCache.has_value() && bypassCache.value()) {
    // Check if the user is authorized to bypass cache
    if (!IsAuthorizedToBypassCache()) {
      callback->sendFailure(Response::AccessDenied());
      return;
    }
  }

  callback->fallThrough();
  web_contents->GetController().Reload(bypassCache.fromMaybe(false)
                                           ? ReloadType::BYPASSING_CACHE
                                             : ReloadType::NORMAL,
                                       false);
}