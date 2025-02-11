lock_encryption_data_new (DBusGMethodInvocation *context,
                          Device *luks_device,
                          Device *cleartext_device)
{
  LockEncryptionData *data;

  data = g_new0 (LockEncryptionData, 1);
  data->refcount = 1;

  data->context = context;
  data->luks_device = g_object_ref (luks_device);
  data->cleartext_device = g_object_ref (cleartext_device);

  // Add a destructor function to free the allocated memory
  g_atexit(free_lock_encryption_data, data);
  
  return data;
}

void free_lock_encryption_data(LockEncryptionData *data) {
  g_object_unref(data->luks_device);
  g_object_unref(data->cleartext_device);
  g_free(data);
}