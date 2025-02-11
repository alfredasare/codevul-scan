void CastConfigDelegateChromeos::GetReceiversAndActivities(
const ReceiversAndActivitesCallback& callback) {
std::string sanitized_javascript =
SpellCheckString("backgroundSetup.getMirrorCapableReceiversAndActivities();");

ExecuteJavaScriptWithCallback(
sanitized_javascript,
base::Bind(&GetReceiversAndActivitiesCallback, callback));
}