bool FrameFetchContext::ShouldSendClientHint(
WebClientHintsType type,
const ClientHintsPreferences& hints_preferences,
const WebEnabledClientHints& enabled_hints) const {
BETWEEN(type, WebClientHintsType::kFirst, WebClientHintsType::kLast);

return GetClientHintsPreferences().ShouldSend(type) ||
hints_preferences.ShouldSend(type) || enabled\_hints.IsEnabled(type);
}