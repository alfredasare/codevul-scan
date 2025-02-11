const char* menu_cache_app_get_generic_name(MenuCacheApp* app)
{
    if (app != NULL) {
        return app->generic_name;
    } else {
        // Return an error message or handle the error as appropriate
        return "Invalid menu cache app";
    }
}