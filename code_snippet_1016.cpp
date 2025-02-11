static void nr_destroy_timer(unsigned long data)
{
    struct sock *sk = (struct sock *)data;
    bh_lock_sock(sk);

    if (sock_owned_by_user(sk)) {
        bh_unlock_sock(sk);
        return; // socket is in use, cannot destroy it
    }

    sock_hold(sk);
    nr_destroy_socket(sk);
    bh_unlock_sock(sk);
    sock_put(sk);
}