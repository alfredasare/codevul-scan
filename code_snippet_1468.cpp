AXObjectCache* Document::GetOrCreateAXObjectCache() const {
  Settings* settings = GetSettings();
  if (!settings ||!settings->GetAccessibilityEnabled())
    return nullptr;

  Document& cache_owner = AXObjectCacheOwner();

  if (!cache_owner.GetLayoutView())
    return nullptr;

  ax_object_cache_ = AXObjectCache::Create(cache_owner);
  DCHECK(&cache_owner == this ||!ax_object_cache_);
  return ax_object_cache_.Get();
}