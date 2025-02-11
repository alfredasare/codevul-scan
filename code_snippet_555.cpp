static int has_item(const char *const *ary, const char *item)
{
    if (ary == NULL || *ary == NULL) {
        return 0;
    }

    const char *const *p;

    for (p = ary; *p != NULL; p++)
        if (!strcmp(item, *p))
            return 1;
    return 0;
}