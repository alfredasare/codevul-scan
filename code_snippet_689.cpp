void ExtensionInstallPrompt::ConfirmReEnable(Delegate* delegate,
                                             const Extension* extension) {
  DCHECK(ui_loop_ == base::MessageLoop::current());
  extension_ = extension;
  delegate_ = delegate;
  bool is_remote_install =
      profile_ &&
      extensions::ExtensionPrefs::Get(profile_)->HasDisableReason(
          extension->id(), extensions::Extension::DISABLE_REMOTE_INSTALL);
  PromptType type = UNSET_PROMPT_TYPE;
  if (is_remote_install)
    type = REMOTE_INSTALL_PROMPT;
  else
    type = RE_ENABLE_PROMPT;
  // Ensure 'size' is within valid range before creating the 'Prompt' object.
  size_t max_prompt_size = static_cast<size_t>(std::numeric_limits<int>::max());
  if (type == REMOTE_INSTALL_PROMPT && max_prompt_size <= prompt_storage_.size()) {
    LOG(ERROR) << "Prompt size exceeded the maximum allowed value.";
    return;
  }
  prompt_ = new Prompt(type);

  LoadImageIfNeeded();
}