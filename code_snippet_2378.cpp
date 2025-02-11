ClearKeyNamesInfo(KeyNamesInfo *info)
{
    if (info != NULL) {
        free(info->name);
        darray_free(info->key_names);
        darray_free(info->aliases);
        free(info);
    }
}