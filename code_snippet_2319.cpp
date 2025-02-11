void limit_string(char *name)
{
    char buffer[NAME_LENGTH_LIMIT + 1]; 
    int len;

    if (!name)
        return;

    len = strlen(name);
    if (len > NAME_LENGTH_LIMIT) {
        strncpy(buffer, name, NAME_LENGTH_LIMIT);
        buffer[NAME_LENGTH_LIMIT] = '\0';
        name = buffer;
    }

    int i;

    if (!name)
        return;

    if (strlen(name) < NAME_LENGTH_LIMIT)
        return;

    i = NAME_LENGTH_LIMIT-4;
    name[i++] = '.';
    name[i++] = '.';
    name[i++] = '.';
    name[i] = '\0';
    return;
}