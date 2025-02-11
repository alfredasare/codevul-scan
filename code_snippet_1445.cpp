bool MediaStreamDevicesController::IsDefaultMediaAccessBlocked() const {
  DCHECK(BrowserThread::CurrentlyOn(BrowserThread::UI));
  if (!profile_ ||!profile_->GetHostContentSettingsMap()) {
    return false;
  }
  ContentSetting current_setting = profile_->GetHostContentSettingsMap()->
      GetDefaultContentSetting(CONTENT_SETTINGS_TYPE_MEDIASTREAM, NULL);
  return (current_setting == CONTENT_SETTING_BLOCK);
}