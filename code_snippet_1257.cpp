dbus\_g\_proxy\_manager\_ref(DBusGProxyManager *manager, gpointer data)
{
 g\_assert(manager != NULL);
 g\_assert(manager->refcount > 0);

 g\_mutex\_lock(&(manager->mutex));

 manager->refcount += 1;

 g\_mutex\_unlock(&(manager->mutex));

 return manager;
}