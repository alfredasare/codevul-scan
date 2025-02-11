MagickExport const IndexPacket *GetVirtualIndexQueue(const Image *image)
{
  CacheInfo *restrict cache_info;

  const int id = GetOpenMPThreadId();

  assert(image != (const Image *) NULL);
  assert(image->signature == MagickSignature);
  assert(image->cache != (Cache) NULL);
  cache_info = (CacheInfo *) image->cache;
  assert(cache_info->signature == MagickSignature);

  if (id >= 0 && id < cache_info->number_threads) {
    return GetVirtualIndexesFromNexus(cache_info, cache_info->nexus_info[id]);
  } else {
    // Handle error or return an error value
    return NULL;
  }
}