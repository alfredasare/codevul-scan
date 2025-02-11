#include <string.h>

#define MAX_INPUT_LENGTH 64

/* ... (previous code) ... */

if ((argc == 1)
    || ((argc == 2) && (weechat_strcasecmp (argv[1], "list") == 0)))
{
    logger_list ();
    return WEECHAT_RC_OK;
}

if (argc > 1 && weechat_strcasecmp (argv[1], "set") == 0)
{
    if (argc > 2)
    {
        // Limit the length of the input string and check for invalid characters
        if (strlen(argv[2]) > MAX_INPUT_LENGTH || strchr(argv[2], '/') != NULL)
        {
            WEECHAT_COMMAND_ERROR;
            return WEECHAT_RC_ERROR;
        }
        logger_set_buffer (buffer, argv[2]);
    }
    return WEECHAT_RC_OK;
}

/* ... (remaining code) ... */