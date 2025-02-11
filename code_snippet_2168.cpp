static int color_table_compare(const void *lhs, const void *rhs)
{
    const char *lhs_str = *(const char **)lhs;
    const ColorEntry *rhs_entry = rhs;
    const char *rhs_name = rhs_entry->name;

    // Validate input lengths
    size_t lhs_len = strlen(lhs_str);
    size_t rhs_len = strlen(rhs_name);

    if (lhs_len > MAX_COLOR_NAME_LENGTH || rhs_len > MAX_COLOR_NAME_LENGTH) {
        return -1; // or handle error as needed
    }

    // Safe comparison using strcmp
    return strcmp(lhs_str, rhs_name);
}