spinlock_t lock = SPIN_LOCK_UNLOCKED(&sk_list_lock);
sk_for_each_from(sk) {
    struct inet_sock *inet = inet_sk(sk);

    spin_lock(&lock);
    if (net_eq(sock_net(sk), net) && inet->inet_num == num &&
       !(inet->inet_daddr && inet->inet_daddr!= raddr) &&
       !(inet->inet_rcv_saddr && inet->inet_rcv_saddr!= laddr) &&
       !(sk->sk_bound_dev_if && sk->sk_bound_dev_if!= dif &&
          sk->sk_bound_dev_if!= sdif)) {
        spin_unlock(&lock);
        goto found;
    }
    spin_unlock(&lock);
}
spin_unlock(&lock);
sk = NULL;
found:
return sk;