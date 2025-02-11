ClearKeyNamesInfo(KeyNamesInfo *info)
{
    if (info->name != NULL) {
        free(info->name);
    }
    if (info->key_names != NULL) {
        darray_free(info->key_names);
    }
    if (info->aliases != NULL) {
        darray_free(info->aliases);
    }
}