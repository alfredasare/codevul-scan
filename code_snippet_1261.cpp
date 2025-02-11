struct rpc_task *rpc_run_bc_task(struct rpc_rqst *req, 
                                 const struct rpc_call_ops *tk_ops)
{
    struct rpc_task *task;
    struct xdr_buf *xbufp = &req->rq_snd_buf;
    struct rpc_task_setup task_setup_data = {
       .callback_ops = tk_ops,
    };

    dprintk("RPC: rpc_run_bc_task req= %p\n");
    //...

    xbufp->len = calculate_xdr_buf_len(xbufp);

    task->tk_action = call_bc_transmit;
    atomic_inc(&task->tk_count);
    BUG_ON(atomic_read(&task->tk_count)!= 2);
    rpc_execute(task);

    //...
}

int calculate_xdr_buf_len(struct xdr_buf *xbufp)
{
    int len = 0;
    len += xbufp->head[0].iov_len;
    len += xbufp->page_len;
    len += xbufp->tail[0].iov_len;
    return len;
}