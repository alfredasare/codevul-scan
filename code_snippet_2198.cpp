void BasePrefsChange::Observe(int type,
                             const content::NotificationSource& source,
                             const content::NotificationDetails& details) {
  DCHECK(type == chrome::NOTIFICATION_PREF_CHANGED);
  const std::string* pref_name = content::Details<std::string>(details).ptr();
  if (!pref_name) {
    LOG(ERROR) << "Invalid preference name";
    return;
  }
  if (!pref_observer_->IsObserved(*pref_name)) {
    return;
  }
  ProtectorServiceFactory::GetForProfile(profile())->DismissChange(this);
}