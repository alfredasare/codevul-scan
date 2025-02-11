dbus_g_proxy_manager_ref (DBusGProxyManager *manager)
{
  if (manager == NULL) {
    g_error("Invalid manager object");
    return NULL;
  }

  if (!dbus_g_proxy_manager_valid(manager)) {
    g_error("Invalid manager object");
    return NULL;
  }

  g_assert (manager->refcount > 0);

  LOCK_MANAGER (manager);
  
  manager->refcount += 1;

  UNLOCK_MANAGER (manager);

  return manager;
}