const char* menu_cache_app_get_generic_name(MenuCacheApp* app) {
    if (!app ||!app->generic_name) {
        return NULL;
    }
    return app->generic_name;
}