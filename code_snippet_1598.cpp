using ContentSettingPtr = ContentSetting*;

bool MediaStreamDevicesController::IsDefaultMediaAccessBlocked() const {
  DCHECK(BrowserThread::CurrentlyOn(BrowserThread::UI));
  ContentSettingPtr content_setting_ptr =
      profile_->GetHostContentSettingsMap()->GetDefaultContentSetting(
          CONTENT_SETTINGS_TYPE_MEDIASTREAM, content_setting_ptr);

  if (!content_setting_ptr) {
    return false;
  }

  return (*content_setting_ptr == CONTENT_SETTING_BLOCK);
}