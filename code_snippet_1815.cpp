#define MAX_FILENAME_LENGTH 256

irc_ctcp_dcc_filename_without_quotes (const char *filename)
{
    int length;
    char valid_characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-.";

    if (strlen(filename) > MAX_FILENAME_LENGTH)
    {
        return NULL;
    }

    length = strlen (filename);
    if (length > 0)
    {
        if ((length >= 2) && (filename[0] == '\"') && (filename[length - 1] == '\"'))
        {
            for (int i = 1; i < length - 1; i++)
            {
                if (strchr(valid_characters, filename[i]) == NULL)
                {
                    return NULL;
                }
            }

            return weechat_strndup (filename + 1, length - 2);
        }
    }

    return strdup (filename);
}