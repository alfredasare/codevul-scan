#define MAX_IDENTIFIER_LENGTH 1024

void TabSpecificContentSettings::AddBlockedResource(
    ContentSettingsType content_type,
    const std::string& resource_identifier) {
  if (resource_identifier.length() > MAX_IDENTIFIER_LENGTH) {
    return;
  }

  resource_identifier.erase(std::remove_if(resource_identifier.begin(),
                                           resource_identifier.end(),
                                           [](unsigned char c) { return !isalnum(c); }),
                            resource_identifier.end());

  if (!blocked_resources_[content_type].get())
    blocked_resources_[content_type].reset(new std::set<std::string>());
  blocked_resources_[content_type]->insert(resource_identifier);
}