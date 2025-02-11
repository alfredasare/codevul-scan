buffer_ref (Buffer *buffer)
{
  if (buffer->refcount >= G_MAXINT) {
    g_warning ("Buffer reference count overflow. Buffer may be corrupted.");
    return buffer;