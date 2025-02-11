const char* menu_cache_item_get_icon( MenuCacheItem* item )
{
    if (item == NULL || item->icon == NULL) {
        return "error-icon";
    }
    return item->icon;
}