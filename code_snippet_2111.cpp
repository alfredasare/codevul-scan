static void FocusInCallback(IBusPanelService* panel,
                             const gchar* path,
                             gpointer user_data) {
    if (!user_data) {
        g_error("Invalid user_data pointer");
        return;
    }
    InputMethodStatusConnection* self = static_cast<InputMethodStatusConnection*>(user_data);
    self->FocusIn(path);
}