void serveconnection(CLIENT *client) {
    if (do_run(client->server->prerun, client->exportname)) {
        exit(EXIT_FAILURE);
    }
    setupexport(client);

    if (client->server->flags & F_COPYONWRITE) {
        size_t copy_size = client->server->copyonwrite_size;
        if (copy_size > sizeof(client->buffer)) {
            error("Invalid copy size");
            return;
        }
        memcpy(client->buffer, client->server->copyonwrite_data, copy_size);
    }

    setmysockopt(client->net);

    mainloop(client);
    do_run(client->server->postrun, client->exportname);
}