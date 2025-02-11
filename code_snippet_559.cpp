void ExtensionInstallPrompt::ConfirmReEnable(Delegate* delegate, const Extension* extension) {
  DCHECK(ui_loop_ == base::MessageLoop::current());
  if (!profile_.empty() &&!base::StringPrintf("%s", profile_.c_str()).empty()) {
    extension_ = extension;
    delegate_ = delegate;
    bool is_remote_install = false; // Initialize is_remote_install to false
    if (profile_ && extensions::ExtensionPrefs::Get(profile_)->HasDisableReason(extension->id(), extensions::Extension::DISABLE_REMOTE_INSTALL)) {
      is_remote_install = true;
    }
    PromptType type = UNSET_PROMPT_TYPE;
    if (is_remote_install) {
      type = REMOTE_INSTALL_PROMPT;
    } else {
      type = RE_ENABLE_PROMPT;
    }
    prompt_ = new Prompt(type);

    if (image_data_.size() > 0 && IsAllowedImageFormat(image_data_)) {
      // Load the image
    } else {
      // Handle the error
    }
  } else {
    // Invalid profile, handle the error
    return;
  }
}