logger_command_cb (const void *pointer, void *data,
                   struct t_gui_buffer *buffer,
                   int argc, char **argv, char **argv_eol)
{
    /* make C compiler happy */
    (void) pointer;
    (void) data;
    (void) argv_eol;

    const char *allowed_commands[] = {"list", "set", "flush", "disable"};
    const int num_allowed_commands = sizeof(allowed_commands) / sizeof(allowed_commands[0]);

    char **args = strtok(argv[1], " ");
    while (*args!= NULL) {
        int found = 0;
        for (int i = 0; i < num_allowed_commands; i++) {
            if (strcmp(*args, allowed_commands[i]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            return WEECHAT_RC_ERROR;
        }
        args = strtok(NULL, " ");
    }

    if ((argc == 1)
        || ((argc == 2) && (weechat_strcasecmp (argv[1], "list") == 0)))
    {
        logger_list ();
        return WEECHAT_RC_OK;
    }

    if (weechat_strcasecmp (argv[1], "set") == 0)
    {
        if (argc > 2)
            logger_set_buffer (buffer, argv[2]);
        return WEECHAT_RC_OK;
    }

    if (weechat_strcasecmp (argv[1], "flush") == 0)
    {
        logger_flush ();
        return WEECHAT_RC_OK;
    }

    if (weechat_strcasecmp (argv[1], "disable") == 0)
    {
        logger_set_buffer (buffer, "0");
        return WEECHAT_RC_OK;
    }

    WEECHAT_COMMAND_ERROR;
}