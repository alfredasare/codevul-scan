static const PixelPacket *GetVirtualPixelsCache(const Image *image)
{
  CacheInfo
    *restrict cache_info;

  const int
    id = GetOpenMPThreadId();

  assert(image != (const Image *) NULL);
  assert(image->signature == MagickSignature);
  assert(image->cache != (Cache) NULL);
  cache_info=(CacheInfo *) image->cache;
  assert(cache_info->signature == MagickSignature);
  assert(id < (int) cache_info->number_threads);
  return(GetVirtualPixelsNexus(image->cache,cache_info->nexus_info[id]));
}
