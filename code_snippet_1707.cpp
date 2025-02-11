cifs_reclassify_socket4(struct socket *sock)
{
    struct sock *sk = sock->sk;
    BUG_ON(sock_owned_by_user(sk));

    // Validate input strings
    if (!cifs_slock_key[0] || strlen(cifs_slock_key[0]) > MAX_KEY_LENGTH) {
        printk(KERN_ERR "Invalid cifs_slock_key\n");
        return;
    }

    if (!cifs_key[0] || strlen(cifs_key[0]) > MAX_KEY_LENGTH) {
        printk(KERN_ERR "Invalid cifs_key\n");
        return;
    }

    sock_lock_init_class_and_name(sk, "slock-AF_INET-CIFS",
        cifs_slock_key[0], "sk_lock-AF_INET-CIFS", cifs_key[0]);
}