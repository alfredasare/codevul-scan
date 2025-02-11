#include <regex>

static const std::regex kManifestUrlWhitelist("^(https?:\\/\\/[\\w-]+(\\.[\\w-]+)+([\\w.,@?^=%&amp;:\/~+#-]*[\\w@?^=%&amp;\/~+#-])?)$");

void CreateGroupInEmptyOrigin() {
    if (!std::regex_match(kManifestUrl, kManifestUrlWhitelist)) {
        // Handle invalid input by logging an error or throwing an exception.
        // Prevent further execution of the function to avoid creating a group with an unauthorized URL.
        return;
    }

    storage()->LoadOrCreateGroup(kManifestUrl, delegate());
    Verify_CreateGroup();
}