MagickExport void *GetVirtualMemoryBlob(const MemoryInfo *memory_info)
{
  if (!memory_info || memory_info->signature != MagickCoreSignature) {
    return NULL;
  }
  return memory_info->blob;
}