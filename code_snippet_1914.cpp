maximum_visible_length(char *str, int offset)
{
    // Validate the offset parameter
    if (offset < 0 || offset > strlen(str)) {
        // Handle invalid offset value
        // For example, return an error code or log an error message
        return -1;
    }

    visible_length_offset = offset;
    return visible_length(str);
}