user_local_unregister (User *user)
{
    GObject *object = G_OBJECT (user);
    if (g_dbus_interface_skeleton_has_reference (G_DBUS_INTERFACE_SKELETON (object))) {
        g_dbus_interface_skeleton_unexport (G_DBUS_INTERFACE_SKELETON (object));
    }
}