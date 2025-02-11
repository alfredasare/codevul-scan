call_bind(struct rpc_task *task)
{
    struct rpc_xprt *xprt = task->tk_xprt;

    dprint_status(task);

    task->tk_action = call_connect;
    if (!xprt_bound(xprt)) {
        if (task->tk_action < CALL_BIND_STATUS_MIN || task->tk_action > CALL_BIND_STATUS_MAX) {
            task->tk_action = call_bind_status;
            task->tk_timeout = xprt->bind_timeout;
            xprt->ops->rpcbind(task);
        }
    }
}