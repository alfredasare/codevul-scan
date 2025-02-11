void server_connect_finished(SERVER_REC *server)
{
    if (!server ||!server->connect_time) {
        // handle invalid input
        return;
    }

    server->connect_time = time(NULL);

    if (!server ||!server->some_invalid_data) {
        // handle invalid data
        return;
    }

    servers = g_slist_append(servers, server);
    signal_emit("server connected", 1, server);
}