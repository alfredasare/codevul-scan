void serveconnection(CLIENT *client) {
    // Validate inputs
    if (!client || !client->server || !client->server->prerun || !client->exportname || !client->net || !client->server->postrun) {
        return;
    }

    if (do_run(client->server->prerun, client->exportname)) {
        exit(EXIT_FAILURE);