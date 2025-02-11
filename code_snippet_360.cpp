MagickExport void *GetVirtualMemoryBlob(const MemoryInfo *memory_info)
{
  assert(memory_info!= (const MemoryInfo *) NULL);
  assert(memory_info->signature == MagickCoreSignature);

  size_t blob_size = memory_info->blob_size;
  if (memory_info->blob!= NULL && blob_size > 0 && memory_info->blob + blob_size >= memory_info->blob) {
    return memory_info->blob;
  } else {
    return NULL;
  }
}