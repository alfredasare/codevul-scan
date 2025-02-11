static int has_item(char **ary, const char *item)
{
    size_t i;
    for (i = 0; ary[i]!= NULL; i++) {
        if (strcmp(item, ary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}