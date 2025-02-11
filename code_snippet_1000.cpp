void vsock_enqueue_accept(struct sock *listener, struct sock *connected)
{
    struct vsock_sock *vlistener;
    struct vsock_sock *vconnected;

    vlistener = vsock_sk(listener);
    vconnected = vsock_sk(connected);

    if (socket_state(listener) == SS_UNCONNECTED) {
        send_error_message("connection refused");
    } else {
        sock_hold(connected);
        sock_hold(listener);
        list_add_tail(&vconnected->accept_queue, &vlistener->accept_queue);
    }
}