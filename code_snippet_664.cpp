void nfc_llcp_sock_unlink(struct llcp_sock_list *l, struct sock *sk)
{
    write_lock(&l->lock);
    if (sk!= NULL) {
        sk_del_node_init(sk);
    }
    write_unlock(&l->lock);
}