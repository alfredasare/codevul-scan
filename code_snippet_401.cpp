static void __sk_destruct(struct rcu_head *head)
{
    struct sock *sk = container_of(head, struct sock, sk_rcu);
    struct sk_filter *filter;

    if (sk->sk_destruct)
        sk->sk_destruct(sk);

    filter = rcu_access_pointer(sk->sk_filter);
    if (filter && atomic_read(&sk->sk_wmem_alloc) == 0) {
        sk_filter_uncharge(sk, filter);
        RCU_INIT_POINTER(sk->sk_filter, NULL);
    }

    if (filter) {
        sk->sk_filter = NULL; // Set the pointer to NULL after use
    }

    //... (rest of the code remains the same)