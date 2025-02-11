#define MAX_NAME_LENGTH 64 // Define an appropriate maximum name length

static int color_table_compare(const void *lhs, const void *rhs)
{
    const ColorEntry *entry1 = lhs;
    const ColorEntry *entry2 = rhs;

    return strncasecmp(entry1->name, entry2->name, MIN(MAX_NAME_LENGTH, strlen(entry1->name), strlen(entry2->name)));
}