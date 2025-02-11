scoped_refptr<::ppapi::CallbackTracker> PluginModule::GetCallbackTracker() {
    if (!callback_tracker_.get()) {
        callback_tracker_.reset(new ::ppapi::CallbackTracker());
    }
    return callback_tracker_;
}