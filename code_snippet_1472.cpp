static int hash_accept(struct socket *sock, struct socket *newsock, int flags)
{
    //...
    err = af_alg_accept(ask->parent, newsock);
    if (!newsock) {
        return -EINVAL; // or any other suitable error code
    }
    if (err)
        return err;
    sk2 = newsock->sk;
    //...
}