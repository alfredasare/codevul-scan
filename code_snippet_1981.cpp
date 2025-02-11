#include <string.h> // for strdup()

char* menu_cache_item_get_icon(MenuCacheItem* item)
{
    char *copy = strdup(item->icon); // Make a copy of the string
    if (!copy) { // Check if the allocation was successful
        return NULL;
    }
    // Perform any necessary validation or sanitization here
    // ...

    return copy; // Return the copied and validated string
}

void menu_cache_item_icon_free(char *icon)
{
    if (icon) {
        free(icon);
    }
}