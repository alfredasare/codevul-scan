MagickExport IndexPacket *GetAuthenticIndexQueue(const Image *image)
{
CacheInfo *magick\_restrict cache\_info;
const int id = GetOpenMPThreadId();
assert(image != (const Image *) NULL);
assert(image->signature == MagickSignature);
assert(image->cache != (Cache) NULL);
cache\_info=(CacheInfo *) image->cache;
assert(cache\_info->signature == MagickSignature);
if (cache\_info->methods.get\_authentic\_indexes\_from\_handler != NULL && cache\_info->methods.get\_authentic\_indexes\_from\_handler != (GetAuthenticIndexesFromHandler) NULL) {
return(cache\_info->methods.get\_authentic\_indexes\_from\_handler(image));
}
assert(id < (int) cache\_info->number\_threads);
return(cache\_info->nexus\_info[id]->indexes);
}