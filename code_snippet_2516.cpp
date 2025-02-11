void limit_string(char *name)
{
    int i;

    if (!name)
        return;

    // Initialize 'name' to an empty string to prevent issues with uninitialized memory
    *name = '\0';

    i = strlen(name);
    if (i >= NAME_LENGTH_LIMIT)
        return;

    // Copy the string and ensure it does not exceed the buffer size
    strncpy(name, name, NAME_LENGTH_LIMIT - 1);
    name[NAME_LENGTH_LIMIT - 1] = '\0';

    // Add the trailing dots
    name[i++] = '.';
    name[i++] = '.';
    name[i] = '.';
    name[i + 1] = '\0';
}