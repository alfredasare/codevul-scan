struct sock *bt_accept_dequeue(struct sock *parent, struct socket *newsock)
{
   ...
    pr_info("Parent socket: %p\n", parent);
   ...
}