java
void CreateGroupInEmptyOrigin() {
    try {
        storage()->LoadOrCreateGroup(kManifestUrl, delegate());
        Verify_CreateGroup();
    } catch (Exception e) {
        Logger::log("Error creating group: " + e.getMessage());
    }
}