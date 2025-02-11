irc_server_set_nick(struct t_irc_server *server, const char *nick)
{
    struct t_irc_channel *ptr_channel;
    
    if (server->nick)
        free(server->nick);
    server->nick = (nick) ? strdup(nick) : NULL;