FcCacheObjectDereference (void *object)
{
FcCacheSkip	*skip;

lock\_cache ();
skip = FcCacheFindByAddrUnlocked (object);
if (skip && (FcRefDec (&skip->ref) == 1))
{
FcDirCacheDisposeUnlocked (skip->cache);
free(skip);
}
unlock\_cache ();
}