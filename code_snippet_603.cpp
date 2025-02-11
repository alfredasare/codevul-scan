buffer_ref (Buffer *buffer)
{
  atomic_int refcount = buffer->refcount;
  atomic_fetch_add(&refcount, 1);
  buffer->refcount = refcount;
  return buffer;
}

void buffer_unref (Buffer *buffer)
{
  atomic_int refcount = buffer->refcount;
  atomic_fetch_sub(&refcount, 1);
  if (atomic_load(&refcount) == 0) {
    // Deallocate the buffer
  }
}