irc_server_set_nick (struct t_irc_server *server, const char *nick)
{
    struct t_irc_channel *ptr_channel;
    size_t nick_len;

    if (server->nick)
        free (server->nick);

    nick_len = strlen (nick);
    if (nick_len > IRC_NICK_MAX_LENGTH) {
        char *truncated_nick = malloc ((IRC_NICK_MAX_LENGTH + 1) * sizeof(char));
        strncpy_s(truncated_nick, IRC_NICK_MAX_LENGTH, nick, nick_len);
        truncated_nick[IRC_NICK_MAX_LENGTH] = '\0';
        server->nick = strdup (truncated_nick);
        free (truncated_nick);
    } else {
        server->nick = (nick)? strdup (nick) : NULL;
    }

    //... (rest of the code remains the same)