void BasePrefsChange::Observe(int type,
const content::NotificationSource& source,
const content::NotificationDetails& details) {
if (type == chrome::NOTIFICATION_PREF_CHANGED) {
const std::string* pref\_name = content::Details<std::string>(details).ptr();
if (pref\_name && pref\_observer-\>IsObserved(\*pref\_name)) {
ProtectorServiceFactory::GetForProfile(profile())->DismissChange(this);
}
}
}