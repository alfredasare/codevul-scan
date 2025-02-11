user_local_unregister (User *user)
{
    GError *error = NULL;
    if (!g_dbus_interface_skeleton_unexport(G_DBUS_INTERFACE_SKELETON (user), &error)) {
        g_error_free(error);
        // Log the error or perform other necessary actions
    }
}