send_cancel(struct TCP_Server_Info *server, void *buf, struct mid_q_entry *mid)
{
    if (!server ||!server->ops ||!server->ops->send_cancel) {
        return 0; // or handle the error as appropriate
    }
    return server->ops->send_cancel(server, buf, mid);
}