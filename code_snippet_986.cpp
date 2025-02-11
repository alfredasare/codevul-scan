static struct task *h2_timeout_task(struct task *t)
{
    struct h2c *h2c = t->context;
    int expired = tick_is_expired(t->expire, now_ms);

    //...

    if (h2c->mbuf->o &&!validate_path(h2c->mbuf->o, "/path/to/allowed/directory") &&!is_subdir(h2c->mbuf->o, "/path/to/allowed/directory")) {
        // Handle invalid path or path traversal attempt
        h2c->flags |= H2_CF_GOAWAY_FAILED;
    }

    //...

    if (h2c->mbuf->o &&!(h2c->flags & H2_CF_GOAWAY_FAILED) && conn_xprt_ready(h2c->conn)) {
        // Use absolute path or chrooted path for file operations
        char *absolute_path = chroot_path(h2c->mbuf->o, "/path/to/allowed/directory");
        h2c->conn->xprt->snd_buf(h2c->conn, absolute_path, 0);
        free(absolute_path);
    }

    //...
}