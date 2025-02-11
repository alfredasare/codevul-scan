static void free_groupnames(char **groupnames)
{
    int i;
    if (!groupnames)
        return;

    for (i = 0; groupnames && groupnames[i]; i++)
        free(groupnames[i]);

    if (groupnames)
        free(groupnames);
}